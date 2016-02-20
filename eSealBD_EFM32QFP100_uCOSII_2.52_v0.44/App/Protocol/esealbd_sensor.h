/*************************************************************************************************************
*                                                  MODULE                                                    *
*************************************************************************************************************/
#ifndef ESEALBD_SENSOR_H
#define ESEALBD_SENSOR_H

#ifdef __cplusplus
extern "C" {
#endif


/*************************************************************************************************************
*                                                 DEFINES                                                    *
*************************************************************************************************************/
#define ESEALBD_SENSOR_PORT                     0xA004
    
#define ESEALBD_SENSOR_TYPE_TEMPERATURE         0x3FDA
#define ESEALBD_SENSOR_TYPE_HUNIDITY            0x3FDB
#define ESEALBD_SENSOR_TYPE_ACCELERATION        0x3FDC
    
#define ESEALBD_SENSOR_SIGN_POSITIVE            0x00
#define ESEALBD_SENSOR_SIGN_NAGATIVE            0x01    
    
/*************************************************************************************************************
*                                                  DATA TYPES                                                *
*************************************************************************************************************/
#pragma pack(1)

typedef struct
{
    CPU_INT32U id;
    CPU_INT8U  sign;
    CPU_INT16U value;
} sEsealBDTemperatureTypeDef;

typedef struct
{
    CPU_INT32U id;
    CPU_INT8U  sign;
    CPU_INT16U value;
} sEsealBDHunmidityTypeDef;

typedef struct
{
    CPU_INT32U id;
    CPU_INT8U  sign_x;
    CPU_INT16U value_x;
    CPU_INT8U  sign_y;
    CPU_INT16U value_y;
    CPU_INT8U  sign_z;
    CPU_INT16U value_z;
} sEsealBDAccelerationTypeDef;

#pragma pack() 
    

/*************************************************************************************************************
*                                            FUNCTION STATEMENT                                              *
*************************************************************************************************************/
void EsealBDSebsorProcess (CPU_INT8U *pdata, CPU_INT32U len, FNCT_COMM comm);
void EsealBDSensorTemperature (CPU_INT8U *pdata, CPU_INT32U len, FNCT_COMM comm);    
void EsealBDSensorHumidity (CPU_INT8U *pdata, CPU_INT32U len, FNCT_COMM comm);
void EsealBDSensorAcceleration (CPU_INT8U *pdata, CPU_INT32U len, FNCT_COMM comm);


/*************************************************************************************************************
*                                               MODULE END                                                   *
*************************************************************************************************************/
#ifdef __cplusplus
}
#endif

#endif
