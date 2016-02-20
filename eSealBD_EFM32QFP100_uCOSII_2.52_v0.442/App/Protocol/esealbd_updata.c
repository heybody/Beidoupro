/*************************************************************************************************************
*                                              INCLUDE FILES                                                 *
*************************************************************************************************************/
#include <app.h>
#include <ucos_ii.h>

/*************************************************************************************************************
*                                            FUNCTION PROTOTYPES                                             *
*************************************************************************************************************/
void EsealBDUpdataProcess (CPU_INT8U *pdata, CPU_INT32U len, FNCT_COMM comm)
{
    sCiphertextTypeDef *ciphertext;
    sHeadTypeDef *head;
    CPU_INT32U id;
    CPU_INT32U rn;
    CPU_INT32U key;
    CPU_INT8U *p;

    ciphertext = (sCiphertextTypeDef *)pdata;

    id = EsealBDGetID();
    rn = NToHL(ciphertext->rn);
    key = EsealBDGetKey();

    if (id == NToHL(ciphertext->id))
    {
        Decrypt(id, rn, key, (CPU_INT8U *)&ciphertext->data, NToHS(ciphertext->len));

        p = (CPU_INT8U *)&ciphertext->data;
        head = (sHeadTypeDef *)p;

        if (NToHS(head->crc) != GetCRC16(&p[HEAD_CRC_POS], NToHS(head->len) + HEAD_HEAD_SIZE - HEAD_CRC_LEN))
        {
            EsealBDUpdataError(HEAD_ERROR_TYPE_CRC, comm);

            return;
        }

        switch (NToHS(head->type))
        {
            case ESEALBD_UPDATA_TYPE_QUERY:         EsealBDUpdataQuery(&head->data, NToHS(head->len), comm);
                                                    break;
            case ESEALBD_UPDATA_TYPE_CONFIG:        EsealBDUpdataConfig(&head->data, NToHS(head->len), comm);
                                                    break;
            case ESEALBD_UPDATA_TYPE_INFO:          EsealBDUpdataInfo(&head->data, NToHS(head->len), comm);
                                                    break;
            case ESEALBD_UPDATA_TYPE_EXTRA_INFO:    EsealBDUpdataExtraInfo(&head->data, NToHS(head->len), comm);
                                                    break;
            default:                                break;
        }
    }
}

void EsealBDUpdataError (CPU_INT8U error, FNCT_COMM comm)
{
    CPU_INT8U  data[SOCKET_HEAD_SIZE + CHIPHERTEXT_HEAD_SIZE + HEAD_HEAD_SIZE + ESEALBD_UPDATA_REPLAY_SIZE_ERROR];
    CPU_INT16U len;
    CPU_INT32U id;
    CPU_INT32U rn;
    CPU_INT32U key;
    sCiphertextTypeDef *ciphertext;
    CPU_INT8U *p;
    sHeadTypeDef *head;
    sEsealBDUpdataErrornReplayTypeDef *replay;

    id  = EsealBDGetID();
    rn  = EsealBDGetRN();
    key = EsealBDGetKey();

    ciphertext = (sCiphertextTypeDef *)&data[SOCKET_HEAD_SIZE];
    ciphertext->id  = NToHL(id);
    ciphertext->rn  = NToHL(rn);

    ciphertext->len = NToHS(HEAD_HEAD_SIZE + ESEALBD_UPDATA_REPLAY_SIZE_ERROR);

    p = (CPU_INT8U *)&ciphertext->data;

    head = (sHeadTypeDef *)p;

    replay = (sEsealBDUpdataErrornReplayTypeDef *)&head->data;

    replay->id = NToHL(id);
    replay->error = error;

    len  = ESEALBD_UPDATA_REPLAY_SIZE_ERROR;
    head->len = NToHS(len);
    head->type = NToHS(ESEALBD_UPDATA_TYPE_REPLAY_ERROR);
    head->crc = NToHS(GetCRC16(&data[SOCKET_HEAD_SIZE + CHIPHERTEXT_HEAD_SIZE + HEAD_CRC_POS],
                               HEAD_HEAD_SIZE - HEAD_CRC_LEN + len));

   // Encrypt(id, rn, key, (CPU_INT8U *)&ciphertext->data, NToHS(ciphertext->len));

    SocketPackageSend(ESEALBD_UPDATA_PORT, data, CHIPHERTEXT_HEAD_SIZE + HEAD_HEAD_SIZE + len);
    //comm(data, SOCKET_HEAD_SIZE + CHIPHERTEXT_HEAD_SIZE + HEAD_HEAD_SIZE + len);
    EsealBuffDataIn(data, SOCKET_HEAD_SIZE + CHIPHERTEXT_HEAD_SIZE + HEAD_HEAD_SIZE + len);
}

void EsealBDUpdataQuery (CPU_INT8U *pdata, CPU_INT32U len, FNCT_COMM comm)
{
    sEsealBDUpdataQueryTypeDef *cmd;
    CPU_INT32U id;
    sEsealBDWorkTypeDef work;
    CPU_INT8U ch;
    sEsealBDStateTypeDef state;
    sEsealBDSensorTypeDef sensor;
    CPU_INT8U i;
    CPU_INT32U cmd_id;

    id = EsealBDGetID();

    cmd = (sEsealBDUpdataQueryTypeDef *)pdata;

    if (cmd->count != ((len - 1) / 4))
    {
        return;
    }

    for (i = 0; i < cmd->count; i++)
    {
        cmd_id = NToHL(* (CPU_INT32U *)(pdata + 1 + 4 * i));

        if (cmd_id == id)
        {
            EsealBDGetWork(&work);
            EsealBDGetSensor(&sensor);

            EsealBDGetState(&state);
            ch = EsealBDGetCH(comm);

            EsealBDUpdataQueryReplay(work, ch, sensor, comm);
        }
    }

}

void EsealBDUpdataConfig (CPU_INT8U *pdata, CPU_INT32U len, FNCT_COMM comm)
{
    sEsealBDUpdataConfigTypeDef *cmd;
    CPU_INT32U id;
    sEsealBDWorkTypeDef work;
    CPU_INT8U ch;
    sEsealBDSensorTypeDef sensor;

    id = EsealBDGetID();

    cmd = (sEsealBDUpdataConfigTypeDef *)pdata;

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
        ch = EsealBDGetCH(comm);

        /////////

        EsealBDUpdataResetFlagSet(DEF_ON);
        EsealUpdataExtraCOllectedInfo((FNCT_COMM)EsealBuffDataIn);
        OSTimeDly (1500);
        EsealBDUpdataResetFlagSet(DEF_OFF);

        //////////

        EsealBDUpdataQueryReplay(work, ch, sensor, comm);
    }
}

void EsealBDUpdataInfo (CPU_INT8U *pdata, CPU_INT32U len, FNCT_COMM comm)
{
    sEsealBDUpdataInfoTypeDef *cmd;
    CPU_INT32U id;
    CPU_INT8U i;
    CPU_INT32U cmd_id;

    id = EsealBDGetID();

    cmd = (sEsealBDUpdataInfoTypeDef *)pdata;

    if (cmd->count != ((len - 1) / 4))
    {
        return;
    }

    for (i = 0; i < cmd->count; i++)
    {
        cmd_id = NToHL(* (CPU_INT32U *)(pdata + 1 + 4 * i));

        if (cmd_id == id)
        {
          EsealBDUpdata(ESEALBD_UPDATA_QUERY, comm);

        }
    }
}

void EsealBDUpdataExtraInfo (CPU_INT8U *pdata, CPU_INT32U len, FNCT_COMM comm)
{
    sEsealBDUpdataExtraInfoTypeDef *cmd;
    CPU_INT32U id;
    //CPU_INT8U i;
    CPU_INT32U cmd_id;

    id = EsealBDGetID();

    cmd = (sEsealBDUpdataExtraInfoTypeDef *)pdata;


    cmd_id = NToHL(cmd->id);

    if (cmd_id == id)
    {
        EsealBDUpdataExtra(ESEALBD_UPDATA_QUERY, 0, 1, (FNCT_COMM)EsealBuffDataIn);
    }

}

void EsealBDUpdataQueryReplay (sEsealBDWorkTypeDef work, CPU_INT8U ch,
                               sEsealBDSensorTypeDef sensor, FNCT_COMM comm)
{
    CPU_INT8U  data[SOCKET_HEAD_SIZE + CHIPHERTEXT_HEAD_SIZE + HEAD_HEAD_SIZE + ESEALBD_UPDATA_REPLAY_SIZE_QUERY];
    CPU_INT16U len;
    CPU_INT32U id;
    CPU_INT32U rn;
    CPU_INT32U key;
    sCiphertextTypeDef *ciphertext;
    CPU_INT8U *p;
    sHeadTypeDef *head;
    sEsealBDUpdataQueryReplayTypeDef *replay;

    id  = EsealBDGetID();
    rn  = EsealBDGetRN();
    key = EsealBDGetKey();

    ciphertext = (sCiphertextTypeDef *)&data[SOCKET_HEAD_SIZE];
    ciphertext->id  = NToHL(id);
    ciphertext->rn  = NToHL(rn);

    ciphertext->len = NToHS(HEAD_HEAD_SIZE + ESEALBD_UPDATA_REPLAY_SIZE_QUERY);

    p = (CPU_INT8U *)&ciphertext->data;

    head = (sHeadTypeDef *)p;

    replay = (sEsealBDUpdataQueryReplayTypeDef *)&head->data;

    replay->id           = NToHL(id);
    replay->work.period  = NToHS(work.period);
    replay->work.window  = work.window;
    replay->work.channel = work.channel;
    replay->ch           = ch;
    replay->sensor       = sensor;

    len  = ESEALBD_UPDATA_REPLAY_SIZE_QUERY;
    head->len = NToHS(len);
    head->type = NToHS(ESEALBD_UPDATA_TYPE_REPLAY_QUERY);
    head->crc = NToHS(GetCRC16(&data[SOCKET_HEAD_SIZE + CHIPHERTEXT_HEAD_SIZE + HEAD_CRC_POS],
                               HEAD_HEAD_SIZE - HEAD_CRC_LEN + len));

  Encrypt(id, rn, key, (CPU_INT8U *)&ciphertext->data, NToHS(ciphertext->len));

    SocketPackageSend(ESEALBD_UPDATA_PORT, data, CHIPHERTEXT_HEAD_SIZE + HEAD_HEAD_SIZE + len);
    //comm(data, SOCKET_HEAD_SIZE + CHIPHERTEXT_HEAD_SIZE + HEAD_HEAD_SIZE + len);
    EsealBuffDataIn(data, SOCKET_HEAD_SIZE + CHIPHERTEXT_HEAD_SIZE + HEAD_HEAD_SIZE + len);
}

void EsealBDUpdataInfoReplay (CPU_INT8U updata, sUtcTypeDef utc, sEsealBDFixTypeDef fix,
                              sEsealBDStateTypeDef state, sEsealBDSensorTypeDef sensor, FNCT_COMM comm)
{
    CPU_INT8U  data[SOCKET_HEAD_SIZE + CHIPHERTEXT_HEAD_SIZE + HEAD_HEAD_SIZE + ESEALBD_UPDATA_REPLAY_SIZE_INFO];
    CPU_INT16U len;
    CPU_INT32U id;
    CPU_INT32U rn;
    CPU_INT32U key;
    sCiphertextTypeDef *ciphertext;
    CPU_INT8U *p;
    sHeadTypeDef *head;
    sEsealBDUpdataInfoReplayTypeDef *replay;

    id  = EsealBDGetID();
    rn  = EsealBDGetRN();
    key = EsealBDGetKey();

    ciphertext = (sCiphertextTypeDef *)&data[SOCKET_HEAD_SIZE];
    ciphertext->id  = NToHL(id);
    ciphertext->rn  = NToHL(rn);

    ciphertext->len = NToHS(HEAD_HEAD_SIZE + ESEALBD_UPDATA_REPLAY_SIZE_INFO);

    p = (CPU_INT8U *)&ciphertext->data;

    head = (sHeadTypeDef *)p;

    replay = (sEsealBDUpdataInfoReplayTypeDef *)&head->data;

    replay->id     = NToHL(id);
    replay->updata = updata;
    replay->year   = (CPU_INT8U)(utc.year - 2000);
    replay->month  = utc.month;
    replay->date   = utc.date;
    replay->hour   = utc.hour;
    replay->minute = utc.minute;
    replay->second = utc.second;
    replay->fix    = fix;
    replay->fix.info.latitude_direction  = fix.info.longitude_direction;
    replay->fix.info.latitude_h  = NToHS(fix.info.longitude_h);
    replay->fix.info.latitude_l  = NToHL(fix.info.longitude_l);
    replay->fix.info.longitude_direction  = fix.info.latitude_direction;
    replay->fix.info.longitude_h = NToHS(fix.info.latitude_h);
    replay->fix.info.longitude_l = NToHL(fix.info.latitude_l);
    replay->safe   = state.safe;
    replay->sw     = state.sw;
    replay->sensor = sensor;
    replay->sensor.temperature = NToHS(sensor.temperature);
    replay->sensor.humidity    = NToHS(sensor.humidity);
    replay->sensor.shake       = NToHS(sensor.shake);

    len  = ESEALBD_UPDATA_REPLAY_SIZE_INFO;
    head->len = NToHS(len);
    head->type = NToHS(ESEALBD_UPDATA_TYPE_REPLAY_INFO);
    head->crc = NToHS(GetCRC16(&data[SOCKET_HEAD_SIZE + CHIPHERTEXT_HEAD_SIZE + HEAD_CRC_POS],
                               HEAD_HEAD_SIZE - HEAD_CRC_LEN + len));

    Encrypt(id, rn, key, (CPU_INT8U *)&ciphertext->data, NToHS(ciphertext->len));

    SocketPackageSend(ESEALBD_UPDATA_PORT, data, CHIPHERTEXT_HEAD_SIZE + HEAD_HEAD_SIZE + len);
    //comm(data, SOCKET_HEAD_SIZE + CHIPHERTEXT_HEAD_SIZE + HEAD_HEAD_SIZE + len);
    EsealBuffDataIn(data, SOCKET_HEAD_SIZE + CHIPHERTEXT_HEAD_SIZE + HEAD_HEAD_SIZE + len);
}
/**
 * [EsealBDUpdataExtraInfoReplay  description]
 * @param updata [type:ESEALBD_UPDATA_IRQ_TEMPERATURE]
 * @param utc    [utc时间]
 * @param delay  [0]
 * @param sensor [sensor_info：传感器是否使能的标志位]
 * @param pdata  [group 传感器数据]
 * @param count  [description]
 * @param comm   [EsealBuffDataIn]
 */
void EsealBDUpdataExtraInfoReplay (CPU_INT8U updata, sUtcTypeDef utc, CPU_INT16U delay, sEsealBDUpdataExtraSensorTypeDef sensor,
                                   SensorDataTypeDef *pdata, CPU_INT8U count, FNCT_COMM comm)
{
    CPU_INT8U  data[SOCKET_HEAD_SIZE + CHIPHERTEXT_HEAD_SIZE + HEAD_HEAD_SIZE + ESEALBD_UPDATA_REPLAY_SIZE_EXTRA_INFO + 16];
    CPU_INT8U i;
    CPU_INT16U replay_len;
    CPU_INT32U id;
    CPU_INT32U rn;
    CPU_INT32U key;
    sCiphertextTypeDef *ciphertext;
    CPU_INT8U *p;
    sHeadTypeDef *head;
    CPU_INT8U sensor_len;
    SensorTHG *psensor;
    sEsealBDUpdataExtraReplayHeadTypeDef *replay;
    CPU_INT16U temp;
    CPU_INT8U *p_extra;

    id  = EsealBDGetID();
    rn  = EsealBDGetRN();
    key = EsealBDGetKey();

    ciphertext = (sCiphertextTypeDef *)&data[SOCKET_HEAD_SIZE];
    ciphertext->id  = NToHL(id);
    ciphertext->rn  = NToHL(rn);

    switch (sensor)
    {
        case sensor_type_t_h_g: sensor_len = sizeof (SensorTHG);
                                break;
        case sensor_type_t_h:   sensor_len = sizeof (SensorTH);
                                break;
        case sensor_type_h_g:   sensor_len = sizeof (SensorHG);
                                break;
        case sensor_type_t_g:   sensor_len = sizeof (SensorTG);
                                break;
        case sensor_type_t:     sensor_len = sizeof (SensorT);
                                break;
        case sensor_type_h:     sensor_len = sizeof (SensorH);
                                break;
        case sensor_type_g:     sensor_len = sizeof (SensorG);
                                break;
        case sensor_type_none:  sensor_len = sizeof (SensorNone);
                                break;
        default:                break;
    }

    replay_len = sizeof (sEsealBDUpdataExtraReplayHeadTypeDef) -1  +  sensor_len * count;

    ciphertext->len = NToHS(HEAD_HEAD_SIZE + replay_len);

    p = (CPU_INT8U *)&ciphertext->data;

    head = (sHeadTypeDef *)p;

    replay = (sEsealBDUpdataExtraReplayHeadTypeDef *)&head->data;

    replay->id     = NToHL(id);
    replay->updata = updata;
    replay->year   = (CPU_INT8U)(utc.year - 2000);
    replay->month  = utc.month;
    replay->date   = utc.date;
    replay->hour   = utc.hour;
    replay->minute = utc.minute;
    replay->second = utc.second;
    replay->delay    = NToHS(delay);
    replay->count = count;
    replay->sensor_info = sensor;

    for (i = 0; i < count; i++)
    {
        psensor = (SensorTHG *)((CPU_INT32U)&(replay->data) + (sensor_len * i));

        psensor->safety = pdata[i].thg.safety;
        psensor->location_flag = pdata[i].thg.location_flag;
        psensor->longitude = NToHL(pdata[i].thg.longitude);
        psensor->latitude = NToHL(pdata[i].thg.latitude);

        p_extra = (CPU_INT8U *)&psensor->temperature;

        if (sensor & ESEALBD_UPDATA_EXTRA_INFO_T_SENSOR_MASK)
        {
            temp = NToHS(pdata[i].thg.temperature);
             memcpy(p_extra, (CPU_INT8U *)&temp, 2);
             p_extra = (CPU_INT8U *)((CPU_INT32U)p_extra + 2);
        }

        if (sensor & ESEALBD_UPDATA_EXTRA_INFO_H_SENSOR_MASK)
        {
             memcpy(p_extra, &pdata[i].thg.humidity, 1);
             p_extra = (CPU_INT8U *)((CPU_INT32U)p_extra + 1);
        }

        if (sensor & ESEALBD_UPDATA_EXTRA_INFO_G_SENSOR_MASK)
        {
             memcpy(p_extra, &pdata[i].thg.gs_x, 3);
             p_extra = (CPU_INT8U *)((CPU_INT32U)p_extra + 3);
        }
    }

    head->len = NToHS(replay_len);
    head->type = NToHS(ESEALBD_UPDATA_TYPE_REPLAY_EXTRA_INFO);
    head->crc = NToHS(GetCRC16(&data[SOCKET_HEAD_SIZE + CHIPHERTEXT_HEAD_SIZE + HEAD_CRC_POS],
                               HEAD_HEAD_SIZE - HEAD_CRC_LEN + replay_len));

    //Encrypt(id, rn, key, (CPU_INT8U *)&ciphertext->data, NToHS(ciphertext->len));

    SocketPackageSend(ESEALBD_UPDATA_PORT, data, CHIPHERTEXT_HEAD_SIZE + HEAD_HEAD_SIZE + replay_len);
    //comm(data, SOCKET_HEAD_SIZE + CHIPHERTEXT_HEAD_SIZE + HEAD_HEAD_SIZE + replay_len);
     comm(data, SOCKET_HEAD_SIZE + CHIPHERTEXT_HEAD_SIZE + HEAD_HEAD_SIZE + replay_len);
     //EsealBuffDataIn(data, SOCKET_HEAD_SIZE + CHIPHERTEXT_HEAD_SIZE + HEAD_HEAD_SIZE + replay_len);
}


/*************************************************************************************************************
*                                               MODULE END                                                   *
*************************************************************************************************************/
