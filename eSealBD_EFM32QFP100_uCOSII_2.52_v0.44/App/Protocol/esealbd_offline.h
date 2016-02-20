/*************************************************************************************************************
*                                                  MODULE                                                    *
*************************************************************************************************************/
#ifndef ESEALBD_OFFLINE_H
#define ESEALBD_OFFLINE_H

#ifdef __cplusplus
extern "C" {
#endif


/*************************************************************************************************************
*                                                 DEFINES                                                    *
*************************************************************************************************************/
#define ESEALBD_OFFLINE_PORT                    0xA003
    
#define ESEALBD_OFFLINE_TYPE_QUERY              0x2FD3
#define ESEALBD_OFFLINE_TYPE_SCAN               0x2F02
#define ESEALBD_OFFLINE_TYPE_GET_RN             0x2F0D
    
#define ESEALBD_OFFLINE_REPLAY_SIZE_ERROR       5u 
#define ESEALBD_OFFLINE_REPLAY_SIZE_QUERY       (4u + 10u + 2u + 256u)
#define ESEALBD_OFFLINE_REPLAY_SIZE_SCAN        4u 
#define ESEALBD_OFFLINE_REPLAY_SIZE_GET_RN      8u 
    
#define ESEALBD_OFFLINE_TYPE_REPLAY_ERROR       0x1F0Fu 
#define ESEALBD_OFFLINE_TYPE_REPLAY_QUERY       0x1FD0u 
#define ESEALBD_OFFLINE_TYPE_REPLAY_SCAN        0x1F02u
#define ESEALBD_OFFLINE_TYPE_REPLAY_GET_RN      0x1F0Du   
    
    
/*************************************************************************************************************
*                                                  DATA TYPES                                                *
*************************************************************************************************************/
#pragma pack(1)
    
typedef struct
{
    CPU_INT8U  year;
    CPU_INT8U  mon;
    CPU_INT8U  day;
    CPU_INT8U  hour;
    CPU_INT8U  min;
    CPU_INT8U  sec;
    CPU_INT32U id;
} sEsealBDFormTypeDef;
    
typedef struct
{
    CPU_INT32U id;
    sEsealBDFormTypeDef form;
} sEsealBDOfflineQueryTypeDef;
    
typedef struct
{
    CPU_INT32U id;
    CPU_INT8U  error;
} sEsealBDOfflineErrorReplayTypeDef;

typedef struct
{
    CPU_INT32U id;
    sEsealBDFormTypeDef form;
    CPU_INT16U len;
    CPU_INT8U  data;
} sEsealBDOfflineQueryReplayTypeDef;

typedef struct
{
    CPU_INT32U id;
} sEsealBDOfflineScanReplayTypeDef;

typedef struct
{
    CPU_INT32U id;
    CPU_INT32U rn;
} sEsealBDOfflineGetRNReplayTypeDef;

#pragma pack() 

/*************************************************************************************************************
*                                            FUNCTION STATEMENT                                              *
*************************************************************************************************************/
void EsealBDOfflineProcess (CPU_INT8U *pdata, CPU_INT32U len, FNCT_COMM comm);
void EsealBDOfflineError (CPU_INT8U error, FNCT_COMM comm);
void EsealBDOfflineQuery (CPU_INT8U *pdata, CPU_INT32U len, FNCT_COMM comm);
void EsealBDOfflineScan (CPU_INT8U *pdata, CPU_INT32U len, FNCT_COMM comm);
void EsealBDOfflineGetRN (CPU_INT8U *pdata, CPU_INT32U len, FNCT_COMM comm);
void EsealBDOfflineQueryReplay (FNCT_COMM comm);
void EsealBDOfflineScanReplay (FNCT_COMM comm);
void EsealBDOfflineGetRNReplay (CPU_INT32U rn, FNCT_COMM comm);

/*************************************************************************************************************
*                                               MODULE END                                                   *
*************************************************************************************************************/
#ifdef __cplusplus
}
#endif

#endif
