/*************************************************************************************************************
*                                                  MODULE                                                    *
*************************************************************************************************************/
#ifndef ESEALBD_OPERATION_H
#define ESEALBD_OPERATION_H

#ifdef __cplusplus
extern "C" {
#endif


/*************************************************************************************************************
*                                                 DEFINES                                                    *
*************************************************************************************************************/
#define ESEALBD_OPERATION_CMD_MAX_SIZE          256
 
#define ESEALBD_OPERATION_PORT                  0xA002
    
#define ESEALBD_OPERATION_TYPE_QUERY            0x2F00
#define ESEALBD_OPERATION_TYPE_CONFIG           0x2F01
#define ESEALBD_OPERATION_TYPE_OPERATION        0x2F0C
#define ESEALBD_OPERATION_TYPE_WRITE_DATA       0x2FD0
#define ESEALBD_OPERATION_TYPE_READ_DATA        0x2FD1
#define ESEALBD_OPERATION_TYPE_CLEAR            0x2FD3
#define ESEALBD_OPERATION_TYPE_INFO             0x2FD2
    
#define ESEALBD_OPERATION_REPLAY_SIZE_ERROR     5u
#define ESEALBD_OPERATION_REPLAY_SIZE_QUERY     21u
#define ESEALBD_OPERATION_REPLAY_SIZE_READ_DATA (4u + 2u + 256)
#define ESEALBD_OPERATION_REPLAY_SIZE_INFO      33u

#define ESEALBD_OPERATION_TYPE_REPLAY_ERROR     0x1F0Fu     
#define ESEALBD_OPERATION_TYPE_REPLAY_QUERY     0x1F00u       
#define ESEALBD_OPERATION_TYPE_REPLAY_READ_DATA 0x1FD1u     
#define ESEALBD_OPERATION_TYPE_REPLAY_INFO      0x1FD0u
    
    
/*************************************************************************************************************
*                                                  DATA TYPES                                                *
*************************************************************************************************************/
#pragma pack(1)
    
typedef struct 
{
    CPU_INT16U period;
    CPU_INT8U  window;
    CPU_INT8U  channel;       
} sEsealBDWorkTypeDef;

typedef struct 
{
    CPU_BOOL   power;
    CPU_INT8U  safe;
    CPU_BOOL   sw;       
} sEsealBDStateTypeDef;

typedef struct 
{
    CPU_BOOL   temperature_en;
    CPU_INT16S temperature;
    CPU_BOOL   humidity_en;
    CPU_INT16U humidity;
    CPU_BOOL   shake_en;
    CPU_INT16U shake;       
} sEsealBDSensorTypeDef;

typedef struct 
{
    CPU_BOOL   flag;
    sLonLatInfoTypeDef info;      
} sEsealBDFixTypeDef;
    
typedef struct
{
    CPU_INT32U id;
} sEsealBDOperationQueryTypeDef;

typedef struct
{
    CPU_INT32U id;
    sEsealBDWorkTypeDef work;
    sEsealBDSensorTypeDef sensor;
} sEsealBDOperatioConfigTypeDef;  

typedef struct
{
    CPU_INT32U id;
    CPU_BOOL   power;
    CPU_INT8U  safe;
} sEsealBDOperatioOperatioTypeDef;  

typedef struct
{
    CPU_INT32U id;
    CPU_INT16U len;
    CPU_INT8U  data;
} sEsealBDOperatioWriteDataTypeDef;  

typedef struct
{
    CPU_INT32U id;
    CPU_INT16U len;
} sEsealBDOperatioReadDataTypeDef;

typedef struct
{
    CPU_INT32U id;
    CPU_INT16U len;
} sEsealBDOperatioClearTypeDef;

typedef struct
{
    CPU_INT32U id;
} sEsealBDOperatioInfoTypeDef;

typedef struct
{
    CPU_INT32U id;
    CPU_INT8U  error;
} sEsealBDOperatioErrornReplayTypeDef;  

typedef struct
{
    CPU_INT32U id;
    sEsealBDWorkTypeDef work;
    CPU_INT8U  ch;
    sEsealBDStateTypeDef state;
    sEsealBDSensorTypeDef sensor;
} sEsealBDOperatioQueryReplayTypeDef;  

typedef struct
{
    CPU_INT32U id;
    CPU_INT16U len;
    CPU_INT8U  data;
} sEsealBDOperatioReadDataReplayTypeDef;  

typedef struct
{
    CPU_INT32U id;
    CPU_INT8U  updata;
    CPU_INT8U  year;
    CPU_INT8U  month;
    CPU_INT8U  date;
    CPU_INT8U  hour;
    CPU_INT8U  minute;
    CPU_INT8U  second;
    sEsealBDFixTypeDef  fix;
    CPU_INT8U  safe;
    CPU_INT8U  sw;
    sEsealBDSensorTypeDef sensor;
} sEsealBDOperatioInfoReplayTypeDef;  


#pragma pack() 

/*************************************************************************************************************
*                                            FUNCTION STATEMENT                                              *
*************************************************************************************************************/
void EsealBDOperationProcess (CPU_INT8U *pdata, CPU_INT32U len, FNCT_COMM comm);
void EsealBDOperationError (CPU_INT8U error, FNCT_COMM comm);
void EsealBDOperationQuery (CPU_INT8U *pdata, CPU_INT32U len, FNCT_COMM comm);
void EsealBDOperationConfig (CPU_INT8U *pdata, CPU_INT32U len, FNCT_COMM comm);
void EsealBDOperationOperation (CPU_INT8U *pdata, CPU_INT32U len, FNCT_COMM comm);
void EsealBDOperationWriteData (CPU_INT8U *pdata, CPU_INT32U len, FNCT_COMM comm);
void EsealBDOperationReadData (CPU_INT8U *pdata, CPU_INT32U len, FNCT_COMM comm);
void EsealBDOperationClear (CPU_INT8U *pdata, CPU_INT32U len, FNCT_COMM comm);
void EsealBDOperationInfo (CPU_INT8U *pdata, CPU_INT32U len, FNCT_COMM comm);
void EsealBDOperationQueryReplay (sEsealBDWorkTypeDef work, CPU_INT8U ch, sEsealBDStateTypeDef state, 
                                  sEsealBDSensorTypeDef sensor, FNCT_COMM comm);
void EsealBDOperationReadDataReplay (CPU_INT16U data_len, FNCT_COMM comm);
void EsealBDOperationInfoReplay (CPU_INT8U udata, sUtcTypeDef utc, sEsealBDFixTypeDef fix, 
                                 sEsealBDStateTypeDef state, sEsealBDSensorTypeDef sensor, FNCT_COMM comm);

/*************************************************************************************************************
*                                               MODULE END                                                   *
*************************************************************************************************************/
#ifdef __cplusplus
}
#endif

#endif
