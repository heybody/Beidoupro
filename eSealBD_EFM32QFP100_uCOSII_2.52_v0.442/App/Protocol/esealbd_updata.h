/*************************************************************************************************************
*                                                  MODULE                                                    *
*************************************************************************************************************/
#ifndef ESEALBD_UPDATA_H
#define ESEALBD_UPDATA_H

#ifdef __cplusplus
extern "C" {
#endif


/*************************************************************************************************************
*                                                 DEFINES                                                    *
*************************************************************************************************************/
#define ESEALBD_UPDATA_CMD_MAX_SIZE                                 256 
#define ESEALBD_UPDATA_TYPE_EXTRA_INFO_GROUP_MAX_SIZE               5
    
#define ESEALBD_UPDATA_PORT                                         0xA001u
    
#define ESEALBD_UPDATA_TYPE_QUERY                                   0x0F00u
#define ESEALBD_UPDATA_TYPE_CONFIG                                  0x0F01u
#define ESEALBD_UPDATA_TYPE_INFO                                    0x0FD2u
#define ESEALBD_UPDATA_TYPE_EXTRA_INFO                              0x0FD3u

#define ESEALBD_UPDATA_REPLAY_SIZE_ERROR                            5u  
#define ESEALBD_UPDATA_REPLAY_SIZE_QUERY                            18u
#define ESEALBD_UPDATA_REPLAY_SIZE_INFO                             37u
#define ESEALBD_UPDATA_REPLAY_SIZE_EXTRA_INFO                       (sizeof (sEsealBDUpdataExtraReplayHeadTypeDef) - 1 + sizeof (SensorDataTypeDef) * ESEALBD_UPDATA_TYPE_EXTRA_INFO_GROUP_MAX_SIZE)

#define ESEALBD_UPDATA_TYPE_REPLAY_ERROR                            0x1F0Fu 
#define ESEALBD_UPDATA_TYPE_REPLAY_QUERY                            0x1F00u
#define ESEALBD_UPDATA_TYPE_REPLAY_INFO                             0x1FD0u
#define ESEALBD_UPDATA_TYPE_REPLAY_EXTRA_INFO                       0x1FD4u
    
#define ESEALBD_UPDATA_EXTRA_INFO_G_SENSOR_MASK                     0x04
#define ESEALBD_UPDATA_EXTRA_INFO_H_SENSOR_MASK                     0x02
#define ESEALBD_UPDATA_EXTRA_INFO_T_SENSOR_MASK                     0x01


/*************************************************************************************************************
*                                                  DATA TYPES                                                *
*************************************************************************************************************/
#pragma pack(1)
    
typedef struct
{
    CPU_INT8U count;
    CPU_INT8U data;
} sEsealBDUpdataQueryTypeDef;

typedef struct
{
    CPU_INT32U id;
    sEsealBDWorkTypeDef work;
    sEsealBDSensorTypeDef sensor;
} sEsealBDUpdataConfigTypeDef;  

typedef struct
{
    CPU_INT8U count;
    CPU_INT8U data;
} sEsealBDUpdataInfoTypeDef;

typedef struct
{
    CPU_INT32U id;
} sEsealBDUpdataExtraInfoTypeDef;

typedef struct
{
    CPU_INT32U id;
    CPU_INT8U  error;
} sEsealBDUpdataErrornReplayTypeDef;  

typedef struct
{
    CPU_INT32U id;
    sEsealBDWorkTypeDef work;
    CPU_INT8U  ch;
    sEsealBDSensorTypeDef sensor;
} sEsealBDUpdataQueryReplayTypeDef; 

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
} sEsealBDUpdataInfoReplayTypeDef;  

typedef enum
{
    sensor_type_t_h_g = 7,
    sensor_type_t_h = 3,
    sensor_type_t_g = 5,
    sensor_type_h_g = 6,
    sensor_type_t = 1,
    sensor_type_h = 2,
    sensor_type_g = 4,
    sensor_type_none = 0,
} sEsealBDUpdataExtraSensorTypeDef;

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
    CPU_INT16U delay;
    CPU_INT8U  count;
    sEsealBDUpdataExtraSensorTypeDef  sensor_info;
    CPU_INT8U data;
} sEsealBDUpdataExtraReplayHeadTypeDef;  

typedef struct
{
    CPU_INT8U safety;
    CPU_INT8U location_flag;
    CPU_INT32U longitude;
    CPU_INT32U latitude;    
    CPU_INT16U temperature;
    CPU_INT8U  humidity;       
    CPU_INT8U gs_x;
    CPU_INT8U gs_y;
    CPU_INT8U gs_z;
}SensorTHG;

typedef struct
{
    CPU_INT8U safety;
    CPU_INT8U location_flag;
    CPU_INT32U longitude;
    CPU_INT32U latitude;
    CPU_INT16U temperature;
    CPU_INT8U  humidity;       
}SensorTH;

typedef struct
{
    CPU_INT8U safety;
    CPU_INT8U location_flag;
    CPU_INT32U longitude;
    CPU_INT32U latitude;
    CPU_INT16U temperature;    
    CPU_INT8U gs_x;
    CPU_INT8U gs_y;
    CPU_INT8U gs_z;
}SensorTG;

typedef struct
{
    CPU_INT8U safety;
    CPU_INT8U location_flag;
    CPU_INT32U longitude;
    CPU_INT32U latitude;
    CPU_INT8U  humidity;       
    CPU_INT8U gs_x;
    CPU_INT8U gs_y;
    CPU_INT8U gs_z;
}SensorHG;

typedef struct
{
    CPU_INT8U safety;
    CPU_INT8U location_flag;
    CPU_INT32U longitude;
    CPU_INT32U latitude;
    CPU_INT16U temperature;
}SensorT;

typedef struct
{
    CPU_INT8U safety;
    CPU_INT8U location_flag;
    CPU_INT32U longitude;
    CPU_INT32U latitude;
    CPU_INT8U  humidity;       
}SensorH;

typedef struct
{   
    CPU_INT8U safety;
    CPU_INT8U location_flag;
    CPU_INT32U longitude;
    CPU_INT32U latitude;
    CPU_INT8U gs_x;
    CPU_INT8U gs_y;
    CPU_INT8U gs_z;
}SensorG;

typedef struct
{   
    CPU_INT8U safety;
    CPU_INT8U location_flag;
    CPU_INT32U longitude;
    CPU_INT32U latitude;
}SensorNone;
typedef union
{
  SensorTHG thg;
  SensorTH th;
  SensorTG tg;
  SensorHG hg;
  SensorT t;
  SensorH h;
  SensorG g;
  SensorNone none;
}SensorDataTypeDef;
    
typedef struct
{
    CPU_INT8U safety;
    CPU_INT8U location_flag;
    CPU_INT32U longitude;
    CPU_INT32U latitude;
    CPU_INT8U data;
} FixDataTypeDef;  

typedef struct
{
    FixDataTypeDef      fix;
    SensorDataTypeDef   sensor;
} sEsealBDUpdataExtraDataTypeDef;  
#pragma pack() 

/*************************************************************************************************************
*                                            FUNCTION STATEMENT                                              *
*************************************************************************************************************/
void EsealBDUpdataProcess (CPU_INT8U *pdata, CPU_INT32U len, FNCT_COMM comm);
void EsealBDUpdataError (CPU_INT8U error, FNCT_COMM comm);
void EsealBDUpdataQuery (CPU_INT8U *pdata, CPU_INT32U len, FNCT_COMM comm);
void EsealBDUpdataConfig (CPU_INT8U *pdata, CPU_INT32U len, FNCT_COMM comm);
void EsealBDUpdataInfo (CPU_INT8U *pdata, CPU_INT32U len, FNCT_COMM comm);
void EsealBDUpdataExtraInfo (CPU_INT8U *pdata, CPU_INT32U len, FNCT_COMM comm);

void EsealBDUpdataQueryReplay (sEsealBDWorkTypeDef work, CPU_INT8U ch, 
                               sEsealBDSensorTypeDef sensor, FNCT_COMM comm);
void EsealBDUpdataInfoReplay (CPU_INT8U udata, sUtcTypeDef utc, sEsealBDFixTypeDef fix, 
                              sEsealBDStateTypeDef state, sEsealBDSensorTypeDef sensor, FNCT_COMM comm);
//void EsealBDUpdataExtraInfoReplay (CPU_INT8U updata, sUtcTypeDef utc, CPU_INT16U delay, sEsealBDUpdataExtraInfoTypeDef sensor_info,
//                                   sEsealBDUpdataExtraInfoGroupTypeDef *group, CPU_INT8U group_count, FNCT_COMM comm);
void EsealBDUpdataExtraInfoReplay (CPU_INT8U updata, sUtcTypeDef utc, CPU_INT16U delay, sEsealBDUpdataExtraSensorTypeDef sensor, 
                                   SensorDataTypeDef *group, CPU_INT8U group_count, FNCT_COMM comm);
/*************************************************************************************************************
*                                               MODULE END                                                   *
*************************************************************************************************************/
#ifdef __cplusplus
}
#endif

#endif
