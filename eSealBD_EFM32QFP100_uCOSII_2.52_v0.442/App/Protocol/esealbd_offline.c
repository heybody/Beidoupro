/*************************************************************************************************************
*                                              INCLUDE FILES                                                 *
*************************************************************************************************************/
#include <ucos_ii.h>

#include <app.h>


/*************************************************************************************************************
*                                            FUNCTION PROTOTYPES                                             *
*************************************************************************************************************/
void EsealBDOfflineProcess (CPU_INT8U *pdata, CPU_INT32U len, FNCT_COMM comm)
{
    sHeadTypeDef *head;

    head = (sHeadTypeDef *)pdata;
    
  //  OSTimeDly(10);
    
    if (NToHS(head->crc) != GetCRC16(&pdata[HEAD_CRC_POS], NToHS(head->len) + HEAD_HEAD_SIZE - HEAD_CRC_LEN))
    {
        EsealBDOfflineError(HEAD_ERROR_TYPE_CRC, comm);
        
        return;
    }
    
    switch (NToHS(head->type))
    {
        case ESEALBD_OFFLINE_TYPE_QUERY:    EsealBDOfflineQuery(&head->data, NToHS(head->len), comm);
                                            break;
        case ESEALBD_OFFLINE_TYPE_SCAN:     EsealBDOfflineScan(&head->data, NToHS(head->len), comm);
                                            break;
        case ESEALBD_OFFLINE_TYPE_GET_RN:   EsealBDOfflineGetRN(&head->data, NToHS(head->len), comm);
                                            break;
        default:                            break;
    }
}

void EsealBDOfflineError (CPU_INT8U error, FNCT_COMM comm)
{
    CPU_INT8U  data[SOCKET_HEAD_SIZE + HEAD_HEAD_SIZE + ESEALBD_OFFLINE_REPLAY_SIZE_ERROR];
    CPU_INT16U len;
    CPU_INT32U id;
    sHeadTypeDef *head;
    sEsealBDOfflineErrorReplayTypeDef *replay;
    
    id = EsealBDGetID();
    
    head = (sHeadTypeDef *)&data[SOCKET_HEAD_SIZE];
    
    replay = (sEsealBDOfflineErrorReplayTypeDef *)&head->data;
    
    replay->id = NToHL(id);
    replay->error = error;
    
    len = ESEALBD_OFFLINE_REPLAY_SIZE_ERROR;
    
    HeadReplayData(ESEALBD_OFFLINE_PORT, ESEALBD_OFFLINE_TYPE_REPLAY_ERROR, data, len, comm); 
}

void EsealBDOfflineQuery (CPU_INT8U *pdata, CPU_INT32U len, FNCT_COMM comm)
{
    sEsealBDOfflineQueryTypeDef *cmd;
    CPU_INT32U id;
    
    id = EsealBDGetID();
    
    cmd = (sEsealBDOfflineQueryTypeDef *)pdata;
    
    if (id == NToHL(cmd->id))
    {
        if (EsealBDCheckForm((CPU_INT8U *)&cmd->form) == DEF_TRUE)
        {
            EsealBDOfflineQueryReplay(comm);
        }
    }
}

void EsealBDOfflineScan (CPU_INT8U *pdata, CPU_INT32U len, FNCT_COMM comm)
{
    EsealBDOfflineScanReplay(comm);
}

void EsealBDOfflineGetRN (CPU_INT8U *pdata, CPU_INT32U len, FNCT_COMM comm)
{
    EsealBDSetRN();
    EsealBDOfflineGetRNReplay(EsealBDGetRN(), comm);
}

void EsealBDOfflineQueryReplay (FNCT_COMM comm)
{
    CPU_INT8U  data[SOCKET_HEAD_SIZE + HEAD_HEAD_SIZE + ESEALBD_OFFLINE_REPLAY_SIZE_QUERY];
    CPU_INT16U len;
    CPU_INT16U data_len;
    CPU_INT32U id;
    sHeadTypeDef *head;
    sEsealBDOfflineQueryReplayTypeDef *replay;
    
    id = EsealBDGetID();
    data_len = EsealBDGetDataSize();
    
    if (data_len > 10)
    {
        data_len -= 10; 
    }
    
    head = (sHeadTypeDef *)&data[SOCKET_HEAD_SIZE];
    
    replay = (sEsealBDOfflineQueryReplayTypeDef *)&head->data;
    
    replay->id = NToHL(id);
    EsealBDGetForm((CPU_INT8U *)&replay->form);
    replay->len = NToHS(data_len);
    EsealBDGetData(&replay->data, data_len);
    
    len = 4 + 10 + 2 + data_len;
        
    HeadReplayData(ESEALBD_OFFLINE_PORT, ESEALBD_OFFLINE_TYPE_REPLAY_QUERY, data, len, comm); 
}

void EsealBDOfflineScanReplay (FNCT_COMM comm)
{
    CPU_INT8U  data[SOCKET_HEAD_SIZE + HEAD_HEAD_SIZE + ESEALBD_OFFLINE_REPLAY_SIZE_SCAN];
    CPU_INT16U len;
    CPU_INT32U id;
    sHeadTypeDef *head;
    sEsealBDOfflineScanReplayTypeDef *replay;
    
    id = EsealBDGetID();
        
    head = (sHeadTypeDef *)&data[SOCKET_HEAD_SIZE];
    
    replay = (sEsealBDOfflineScanReplayTypeDef *)&head->data;
    
    replay->id = NToHL(id);
    
    len = ESEALBD_OFFLINE_REPLAY_SIZE_SCAN;
    
    HeadReplayData(ESEALBD_OFFLINE_PORT, ESEALBD_OFFLINE_TYPE_REPLAY_SCAN, data, len, comm); 
}

void EsealBDOfflineGetRNReplay (CPU_INT32U rn, FNCT_COMM comm)
{
    CPU_INT8U  data[SOCKET_HEAD_SIZE + HEAD_HEAD_SIZE + ESEALBD_OFFLINE_REPLAY_SIZE_GET_RN];
    CPU_INT16U len;
    CPU_INT32U id;
    sHeadTypeDef *head;
    sEsealBDOfflineGetRNReplayTypeDef *replay;
    
    id = EsealBDGetID();
    
    head = (sHeadTypeDef *)&data[SOCKET_HEAD_SIZE];
    
    replay = (sEsealBDOfflineGetRNReplayTypeDef *)&head->data;
    
    replay->id = NToHL(id);
    replay->rn = NToHL(rn);
    
    len = ESEALBD_OFFLINE_REPLAY_SIZE_GET_RN;
    
    HeadReplayData(ESEALBD_OFFLINE_PORT, ESEALBD_OFFLINE_TYPE_REPLAY_GET_RN, data, len, comm); 
}


/*************************************************************************************************************
*                                               MODULE END                                                   *
*************************************************************************************************************/
