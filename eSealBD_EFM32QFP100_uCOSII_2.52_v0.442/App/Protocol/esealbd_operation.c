/*************************************************************************************************************
*                                              INCLUDE FILES                                                 *
*************************************************************************************************************/
#include <app.h>
#include <includes.h>


/*************************************************************************************************************
*                                            FUNCTION PROTOTYPES                                             *
*************************************************************************************************************/
void EsealBDOperationProcess (CPU_INT8U *pdata, CPU_INT32U len, FNCT_COMM comm)
{
    sCiphertextTypeDef *ciphertext;
    sHeadTypeDef *head;
    CPU_INT32U id;
    CPU_INT32U rn;
    CPU_INT32U key;
    CPU_INT8U *p;
    
    id = EsealBDGetID();
    rn = EsealBDGetRN();
    key = EsealBDGetKey();

    ciphertext = (sCiphertextTypeDef *)pdata;
    
    if (id == NToHL(ciphertext->id))
    {
        Decrypt(id, rn, key, (CPU_INT8U *)&ciphertext->data, NToHS(ciphertext->len));
        
        p = (CPU_INT8U *)&ciphertext->data;
        head = (sHeadTypeDef *)p;
        
        if (NToHS(head->crc) != GetCRC16(&p[HEAD_CRC_POS], NToHS(head->len) + HEAD_HEAD_SIZE - HEAD_CRC_LEN))
        {
            //EsealBDOperationError(HEAD_ERROR_TYPE_CRC, comm);
            
            //return;
        }
        
        switch (NToHS(head->type))
        {
            case ESEALBD_OPERATION_TYPE_QUERY:      EsealBDOperationQuery(&head->data, NToHS(head->len), comm);
                                                    break;
            case ESEALBD_OPERATION_TYPE_CONFIG:     EsealBDOperationConfig(&head->data, NToHS(head->len), comm);
                                                    break;
            case ESEALBD_OPERATION_TYPE_OPERATION:  EsealBDOperationOperation(&head->data, NToHS(head->len), comm);
                                                    break;
            case ESEALBD_OPERATION_TYPE_WRITE_DATA: EsealBDOperationWriteData(&head->data, NToHS(head->len), comm);
                                                    break;
            case ESEALBD_OPERATION_TYPE_READ_DATA:  EsealBDOperationReadData(&head->data, NToHS(head->len), comm);
                                                    break;
            case ESEALBD_OPERATION_TYPE_CLEAR:      EsealBDOperationClear(&head->data, NToHS(head->len), comm);
                                                    break;
            case ESEALBD_OPERATION_TYPE_INFO:       EsealBDOperationInfo(&head->data, NToHS(head->len), comm);
                                                    break;
            default:                                break;
        }
    }
}

void EsealBDOperationError (CPU_INT8U error, FNCT_COMM comm)
{
    CPU_INT8U  data[SOCKET_HEAD_SIZE + CHIPHERTEXT_HEAD_SIZE + HEAD_HEAD_SIZE + ESEALBD_OPERATION_REPLAY_SIZE_ERROR];
    CPU_INT16U len;
    CPU_INT32U id;
    CPU_INT32U rn;
    CPU_INT32U key;
    sCiphertextTypeDef *ciphertext;
    CPU_INT8U *p;
    sHeadTypeDef *head;
    sEsealBDOperatioErrornReplayTypeDef *replay;
    
    id  = EsealBDGetID();
    rn  = EsealBDGetRN();
    key = EsealBDGetKey();
    
    ciphertext = (sCiphertextTypeDef *)&data[SOCKET_HEAD_SIZE];
    ciphertext->id  = NToHL(id);
    ciphertext->rn  = NToHL(rn);
    
    ciphertext->len = NToHS(HEAD_HEAD_SIZE + ESEALBD_OPERATION_REPLAY_SIZE_ERROR);
    
    p = (CPU_INT8U *)&ciphertext->data;
    
    head = (sHeadTypeDef *)p;
    
    replay = (sEsealBDOperatioErrornReplayTypeDef *)&head->data;
    
    replay->id = NToHL(id);
    replay->error = error;
    
    len  = ESEALBD_OPERATION_REPLAY_SIZE_ERROR;
    head->len = NToHS(len);
    head->type = NToHS(ESEALBD_OPERATION_TYPE_REPLAY_ERROR);
    head->crc = NToHS(GetCRC16(&data[SOCKET_HEAD_SIZE + CHIPHERTEXT_HEAD_SIZE + HEAD_CRC_POS],
                               HEAD_HEAD_SIZE - HEAD_CRC_LEN + len)); 
    
    Encrypt(id, rn, key, (CPU_INT8U *)&ciphertext->data, NToHS(ciphertext->len));
    
    SocketPackageSend(ESEALBD_OPERATION_PORT, data, CHIPHERTEXT_HEAD_SIZE + HEAD_HEAD_SIZE + len); 
    comm(data, SOCKET_HEAD_SIZE + CHIPHERTEXT_HEAD_SIZE + HEAD_HEAD_SIZE + len);
}

void EsealBDOperationQuery (CPU_INT8U *pdata, CPU_INT32U len, FNCT_COMM comm)
{
    sEsealBDOperationQueryTypeDef *cmd;
    CPU_INT32U id;
    sEsealBDWorkTypeDef work;
    CPU_INT8U ch;
    sEsealBDStateTypeDef state;
    sEsealBDSensorTypeDef sensor;
    
    id = EsealBDGetID();
    
    cmd = (sEsealBDOperationQueryTypeDef *)pdata;
    
    if (id == NToHL(cmd->id))
    {
        EsealBDGetWork(&work);
        EsealBDGetSensor(&sensor);

        EsealBDGetState(&state);
        ch = EsealBDGetCH(comm);
        
        EsealBDOperationQueryReplay(work, ch, state, sensor, comm);
    }
}

void EsealBDOperationConfig (CPU_INT8U *pdata, CPU_INT32U len, FNCT_COMM comm)
{
    sEsealBDOperatioConfigTypeDef *cmd;
    CPU_INT32U id;
    sEsealBDWorkTypeDef work;
    CPU_INT8U ch;
    sEsealBDStateTypeDef state;
    sEsealBDSensorTypeDef sensor;
    
    id = EsealBDGetID();
    
    cmd = (sEsealBDOperatioConfigTypeDef *)pdata;
    
    if (id == NToHL(cmd->id))
    {
        work.period  = NToHS(cmd->work.period);
        
        work.window  = cmd->work.window;
        work.channel = cmd->work.channel;
        EsealBDSetWork(work);
        
        sensor.temperature_en = cmd->sensor.temperature_en;
        sensor.temperature    = NToHS(cmd->sensor.temperature);
        sensor.humidity_en    = cmd->sensor.humidity_en;
        sensor.humidity       = NToHS(cmd->sensor.humidity);
        sensor.shake_en       = cmd->sensor.shake_en;
        sensor.shake          = NToHS(cmd->sensor.shake);   
        EsealBDSetSensor(sensor);
        
        EsealBDGetWork(&work);
        EsealBDGetSensor(&sensor);

        EsealBDGetState(&state);
        ch = EsealBDGetCH(comm);
        /////////
        
        EsealBDUpdataResetFlagSet(DEF_ON);
        EsealUpdataExtraCOllectedInfo((FNCT_COMM)EsealBuffDataIn);
        OSTimeDly (1500);
        EsealBDUpdataResetFlagSet(DEF_OFF);
        
        //////////
        EsealBDOperationQueryReplay(work, ch, state, sensor, comm);   
    }
}

void EsealBDOperationOperation (CPU_INT8U *pdata, CPU_INT32U len, FNCT_COMM comm)
{
    sEsealBDOperatioOperatioTypeDef *cmd;
    CPU_INT32U id;
    sEsealBDWorkTypeDef work;
    CPU_INT8U ch;
    sEsealBDStateTypeDef state;
    sEsealBDSensorTypeDef sensor;
    
    id = EsealBDGetID();
    
    cmd = (sEsealBDOperatioOperatioTypeDef *)pdata;
    
    if (id == NToHL(cmd->id))
    {
        if (cmd->power == DEF_ON)
        {
            EsealBDPowerOn();
        }
        else
        {
            EsealBDPowerOff();
        }
        
        EsealBDUpdataSafe(cmd->safe);
        
        EsealBDGetWork(&work);
        EsealBDGetSensor(&sensor);
        //sensor.temperature = 0;
        //sensor.humidity    = 0;
        //sensor.shake       = 0;
        EsealBDGetState(&state);
        ch = EsealBDGetCH(comm);
        
        EsealBDOperationQueryReplay(work, ch, state, sensor, comm);   
        
        if (state.safe == 0x00)
        {
            //EsealUpdataExtraCOllectedInfo((FNCT_COMM)EsealBuffDataIn);
            
            /////////
            
            EsealBDUpdataResetFlagSet(DEF_ON);
            EsealUpdataExtraCOllectedInfo((FNCT_COMM)EsealBuffDataIn);
            OSTimeDly (1500);
            EsealBDUpdataResetFlagSet(DEF_OFF);
            
            //////////
        }
        else if (state.safe == 0x01)
        {
            /////////
            
            EsealBDUpdataResetFlagSet(DEF_ON);
            //EsealUpdataExtraCOllectedInfo((FNCT_COMM)EsealBuffDataIn);
            OSTimeDly (1500);
            EsealBDUpdataResetFlagSet(DEF_OFF);
            
            //////////
            EsealUpdataExtraCOllectedInfoInit();
            EsealBuffInit();
        }
        
        EsealBDUpdataExtra(ESEALBD_UPDATA_OTHER, 0, 1, (FNCT_COMM)EsealBuffDataIn);
        
    }
    



}

void EsealBDOperationWriteData (CPU_INT8U *pdata, CPU_INT32U len, FNCT_COMM comm)
{
    sEsealBDOperatioWriteDataTypeDef *cmd;
    CPU_INT32U id;
    
    id = EsealBDGetID();
    
    cmd = (sEsealBDOperatioWriteDataTypeDef *)pdata;
    
    if (id == NToHL(cmd->id))
    {
        EsealBDSetData((CPU_INT8U *)&cmd->data, NToHS(cmd->len));
    }
}

void EsealBDOperationReadData (CPU_INT8U *pdata, CPU_INT32U len, FNCT_COMM comm)
{
    sEsealBDOperatioReadDataTypeDef *cmd;
    CPU_INT32U id;
    
    id = EsealBDGetID();
    
    cmd = (sEsealBDOperatioReadDataTypeDef *)pdata;
    
    if (id == NToHL(cmd->id))
    {
        EsealBDOperationReadDataReplay(NToHS(cmd->len), comm);
    }
}

void EsealBDOperationClear (CPU_INT8U *pdata, CPU_INT32U len, FNCT_COMM comm)
{
    sEsealBDOperatioClearTypeDef *cmd;
    CPU_INT32U id;
    
    id = EsealBDGetID();
    
    cmd = (sEsealBDOperatioClearTypeDef *)pdata;
    
    if (id == NToHL(cmd->id))
    {
        EsealBDClearData(NToHS(cmd->len));
    }
}

void EsealBDOperationInfo (CPU_INT8U *pdata, CPU_INT32U len, FNCT_COMM comm)
{
    sEsealBDOperatioInfoTypeDef *cmd;
    CPU_INT32U id;
    
    id = EsealBDGetID();
    
    cmd = (sEsealBDOperatioInfoTypeDef *)pdata;
    
    if (id == NToHL(cmd->id))
    {
      EsealBDUpdata(ESEALBD_UPDATA_QUERY, comm);
      
      //EsealBDUpdataExtra(ESEALBD_UPDATA_QUERY, 0, 1, comm);
    }
}

void EsealBDOperationQueryReplay (sEsealBDWorkTypeDef work, CPU_INT8U ch, sEsealBDStateTypeDef state, 
                                  sEsealBDSensorTypeDef sensor, FNCT_COMM comm)
{
    CPU_INT8U  data[SOCKET_HEAD_SIZE + CHIPHERTEXT_HEAD_SIZE + HEAD_HEAD_SIZE + ESEALBD_OPERATION_REPLAY_SIZE_QUERY];
    CPU_INT16U len;
    CPU_INT32U id;
    CPU_INT32U rn;
    CPU_INT32U key;
    sCiphertextTypeDef *ciphertext;
    CPU_INT8U *p;
    sHeadTypeDef *head;
    sEsealBDOperatioQueryReplayTypeDef *replay;
    
    id  = EsealBDGetID();
    rn  = EsealBDGetRN();
    key = EsealBDGetKey();
    
    ciphertext = (sCiphertextTypeDef *)&data[SOCKET_HEAD_SIZE];
    ciphertext->id  = NToHL(id);
    ciphertext->rn  = NToHL(rn);
    
    ciphertext->len = NToHS(HEAD_HEAD_SIZE + ESEALBD_OPERATION_REPLAY_SIZE_QUERY);
    
    p = (CPU_INT8U *)&ciphertext->data;
    
    head = (sHeadTypeDef *)p;
    
    replay = (sEsealBDOperatioQueryReplayTypeDef *)&head->data;    
    
    replay->id           = NToHL(id);
    replay->work.period  = NToHS(work.period);
    replay->work.window  = work.window;
    replay->work.channel = work.channel;
    replay->ch           = ch;
    replay->state        = state;
    replay->sensor       = sensor;
    
    len  = ESEALBD_OPERATION_REPLAY_SIZE_QUERY;
    head->len = NToHS(len);
    head->type = NToHS(ESEALBD_OPERATION_TYPE_REPLAY_QUERY);
    head->crc = NToHS(GetCRC16(&data[SOCKET_HEAD_SIZE + CHIPHERTEXT_HEAD_SIZE + HEAD_CRC_POS],
                               HEAD_HEAD_SIZE - HEAD_CRC_LEN + len)); 
    
    Encrypt(id, rn, key, (CPU_INT8U *)&ciphertext->data, NToHS(ciphertext->len));
    
    SocketPackageSend(ESEALBD_OPERATION_PORT, data, CHIPHERTEXT_HEAD_SIZE + HEAD_HEAD_SIZE + len); 
    comm(data, SOCKET_HEAD_SIZE + CHIPHERTEXT_HEAD_SIZE + HEAD_HEAD_SIZE + len);
}

void EsealBDOperationReadDataReplay (CPU_INT16U data_len, FNCT_COMM comm)
{
    CPU_INT8U  data[SOCKET_HEAD_SIZE + CHIPHERTEXT_HEAD_SIZE + HEAD_HEAD_SIZE + ESEALBD_OPERATION_REPLAY_SIZE_READ_DATA];
    CPU_INT16U len;
    CPU_INT16U data_size;
    CPU_INT32U id;
    CPU_INT32U rn;
    CPU_INT32U key;
    sCiphertextTypeDef *ciphertext;
    CPU_INT8U *p;
    sHeadTypeDef *head;
    sEsealBDOperatioReadDataReplayTypeDef *replay;
    
    id  = EsealBDGetID();
    rn  = EsealBDGetRN();
    key = EsealBDGetKey();
    
    ciphertext = (sCiphertextTypeDef *)&data[SOCKET_HEAD_SIZE];
    ciphertext->id  = NToHL(id);
    ciphertext->rn  = NToHL(rn);
    
    data_size = EsealBDGetDataSize();
    
    if (data_size > data_len)
    {
        data_size = data_len;
    }
    
    ciphertext->len = NToHS(HEAD_HEAD_SIZE + 4 + 2 + data_size);
    
    p = (CPU_INT8U *)&ciphertext->data;
    
    head = (sHeadTypeDef *)p;
    
    replay = (sEsealBDOperatioReadDataReplayTypeDef *)&head->data;
    
    replay->id = NToHL(id);
    replay->len = NToHS(data_size);
    
    EsealBDGetFormData((CPU_INT8U *)&replay->data, data_size);
    len  = 4 + 2 + data_size;
   
    
    head->len = NToHS(len);
    head->type = NToHS(ESEALBD_OPERATION_TYPE_REPLAY_READ_DATA);
    head->crc = NToHS(GetCRC16(&data[SOCKET_HEAD_SIZE + CHIPHERTEXT_HEAD_SIZE + HEAD_CRC_POS],
                               HEAD_HEAD_SIZE - HEAD_CRC_LEN + len)); 
    
    Encrypt(id, rn, key, (CPU_INT8U *)&ciphertext->data, NToHS(ciphertext->len));
    
    SocketPackageSend(ESEALBD_OPERATION_PORT, data, CHIPHERTEXT_HEAD_SIZE + HEAD_HEAD_SIZE + len); 
    comm(data, SOCKET_HEAD_SIZE + CHIPHERTEXT_HEAD_SIZE + HEAD_HEAD_SIZE + len);
}

void EsealBDOperationInfoReplay (CPU_INT8U udata, sUtcTypeDef utc, sEsealBDFixTypeDef fix, 
                                 sEsealBDStateTypeDef state, sEsealBDSensorTypeDef sensor, FNCT_COMM comm)
{
    CPU_INT8U  data[SOCKET_HEAD_SIZE + CHIPHERTEXT_HEAD_SIZE + HEAD_HEAD_SIZE + ESEALBD_OPERATION_REPLAY_SIZE_INFO];
    CPU_INT16U len;
    CPU_INT32U id;
    CPU_INT32U rn;
    CPU_INT32U key;
    sCiphertextTypeDef *ciphertext;
    CPU_INT8U *p;
    sHeadTypeDef *head;
    sEsealBDOperatioInfoReplayTypeDef *replay;
    
    id  = EsealBDGetID();
    rn  = EsealBDGetRN();
    key = EsealBDGetKey();
    
    ciphertext = (sCiphertextTypeDef *)&data[SOCKET_HEAD_SIZE];
    ciphertext->id  = NToHL(id);
    ciphertext->rn  = NToHL(rn);
    
    ciphertext->len = NToHS(HEAD_HEAD_SIZE + ESEALBD_OPERATION_REPLAY_SIZE_INFO);
    
    p = (CPU_INT8U *)&ciphertext->data;
    
    head = (sHeadTypeDef *)p;
    
    replay = (sEsealBDOperatioInfoReplayTypeDef *)&head->data;    
    
    replay->id     = NToHL(id);
    replay->updata = udata;
    replay->year   = (CPU_INT8U)(utc.year - 2000);
    replay->month  = utc.month;
    replay->date   = utc.date;
    replay->hour   = utc.hour;
    replay->minute = utc.minute;
    replay->second = utc.second;
    replay->fix    = fix;
    replay->safe   = state.safe;
    replay->sw     = state.sw;
    replay->sensor = sensor;
    
    len  = ESEALBD_OPERATION_REPLAY_SIZE_INFO;
    head->len = NToHS(len);
    head->type = NToHS(ESEALBD_OPERATION_TYPE_REPLAY_INFO);
    head->crc = NToHS(GetCRC16(&data[SOCKET_HEAD_SIZE + CHIPHERTEXT_HEAD_SIZE + HEAD_CRC_POS],
                               HEAD_HEAD_SIZE - HEAD_CRC_LEN + len)); 
    
    Encrypt(id, rn, key, (CPU_INT8U *)&ciphertext->data, NToHS(ciphertext->len));
    
    SocketPackageSend(ESEALBD_OPERATION_PORT, data, CHIPHERTEXT_HEAD_SIZE + HEAD_HEAD_SIZE + len); 
    comm(data, SOCKET_HEAD_SIZE + CHIPHERTEXT_HEAD_SIZE + HEAD_HEAD_SIZE + len);
}



/*************************************************************************************************************
*                                               MODULE END                                                   *
*************************************************************************************************************/
