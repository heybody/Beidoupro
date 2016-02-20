/*************************************************************************************************************
*                                                  MODULE                                                    *
*************************************************************************************************************/
#ifndef ESEALBD_H
#define ESEALBD_H

#ifdef __cplusplus
extern "C" {
#endif


/*************************************************************************************************************
*                                                 DEFINES                                                    *
*************************************************************************************************************/
#define	ESEALBD_ID_ADDR                         0x00010000UL
#define	ESEALBD_KEY_ADDR                        0x00011000UL
#define	ESEALBD_DATA_ADDR                       0x00012000UL
#define	ESEALBD_WORK_ADDR                       0x00013000UL
#define	ESEALBD_SENSOR_ADDR                     0x00014000UL
#define	ESEALBD_STATE_ADDR                      0x00015000UL

#define ESEALBD_DATA_MAX_SIZE                   256
#define ESEALBD_DATA_QUEUE_SIZE                 200
#define ESEALBD_UPDATA_PACKAGE_COUNT            2

#define ESEALBD_GPRS_RESEND_COUNT               3

#define ESEALBD_DATA_SEND_SUCCESS               0x00
#define ESEALBD_DATA_SEND_FAIL                  0x01


/*************************************************************************************************************
*                                                  DATA TYPES                                                *
*************************************************************************************************************/
typedef enum
{
    ESEALBD_WORK_CH_AUT0    = 0x00,
    ESEALBD_WORK_CH_GPRS    = 0x01,
    ESEALBD_WORK_CH_BD      = 0x02,
    ESEALBD_WORK_CH_GPRS_BD = 0x03,
    ESEALBD_WORK_CH_D       = 0x04,
    ESEALBD_WORK_CH_GPRS_D  = 0x05,
} eEsealBDWorkCHTypeDef;

typedef enum
{
    ESEALBD_STATE_SAFE_NO_LOCKED = 0x00,
    ESEALBD_STATE_SAFE_LOCKED    = 0x01,
    ESEALBD_STATE_SAFE_UNLOCKED  = 0x02,
} eEsealBDStateSafeTypeDef;

typedef enum
{
    ESEALBD_UPDATA_PERIOD           = 0x00,
    ESEALBD_UPDATA_QUERY            = 0x01,
    ESEALBD_UPDATA_IRQ              = 0x02,
    ESEALBD_UPDATA_OTHER            = 0x03,
    ESEALBD_UPDATA_IRQ_TEMPERATURE  = 0x04,
    ESEALBD_UPDATA_IRQ_HUMIDITY     = 0x05,
    ESEALBD_UPDATA_IRQ_ACCELERATION = 0x06,
} eEsealBDUpdataTypeDef;

#pragma pack(1)

typedef struct
{
    CPU_INT16U len;
    sEsealBDFormTypeDef form;
    CPU_INT8U  data;
} sEsealBDDataTypeDef;

typedef struct
{
    CPU_INT8U len;
    CPU_INT8U data[ESEALBD_DATA_MAX_SIZE];
} sEsealUpdataItemTypeDef;


typedef struct
{
    CPU_INT32U front;
    CPU_INT32U rear;
    CPU_INT32U count;
    sEsealUpdataItemTypeDef item[ESEALBD_DATA_QUEUE_SIZE];
} sEsealUpdataQueueTypeDef;

typedef struct
{
    volatile CPU_BOOL flag;
    sEsealUpdataQueueTypeDef queue;
} sEsealUpdataTypeDef;

typedef enum
{
    ESEAL_TX_QUEUE_OK,
    ESEAL_TX_QUEUE_ERROR_ITEM_SIZE,
    ESEAL_TX_QUEUE_ERROR_QUEUE_SIZE,
    ESEAL_TX_QUEUE_EMPTY,
} eEsealUpdataTXQueueTypeDef;

typedef struct
{
    SensorDataTypeDef group[5];
    CPU_INT8U count;
    eEsealBDUpdataTypeDef type;
    CPU_INT16U delay;
    sEsealBDUpdataExtraSensorTypeDef sensor_info;
    sUtcTypeDef utc;
}sEsealUpdataExtraTypeDef;


typedef struct
{
    CPU_INT32U deviceid; //设备id
    CPU_INT32U latitude;//经度
    CPU_INT32U longitude;//纬度
    char latitudedirection;
    char longitudedirection;
    char openflag;  //开关量
    short temperature;  //温度值
    short humidity; //湿度值
    short shake; //震动量
    short temperatureset; //温度阈值
    short humidityset;//湿度阈值
    short shakeset;//震动阈值
    char reveiceflag;//信息接收标志位
    sUtcTypeDef utc;
}EsealQiuupdatePackage;


#pragma pack()




/*************************************************************************************************************
*                                            FUNCTION STATEMENT                                              *
*************************************************************************************************************/
void EsealBDInit (void);
CPU_INT32U EsealBDGetID (void);
void EsealBDRNInit (void);
void EsealBDSetRN (void);
CPU_INT32U EsealBDGetRN (void);
void EsealBDGetForm (CPU_INT8U *form);
CPU_BOOL EsealBDCheckForm (CPU_INT8U *form);
CPU_INT16U EsealBDGetDataSize (void);
void EsealBDSetData (CPU_INT8U *pdata, CPU_INT16U len);
void EsealBDGetData (CPU_INT8U *pdata, CPU_INT16U len);
void EsealBDGetFormData (CPU_INT8U *pdata, CPU_INT16U len);
void EsealBDClearData (CPU_INT16U len);
CPU_INT32U EsealBDGetKey (void);
void EsealBDSetWork (sEsealBDWorkTypeDef work);
void EsealBDGetWork (sEsealBDWorkTypeDef *work);
void EsealBDSetSensor (sEsealBDSensorTypeDef sensor);
void EsealBDGetSensor (sEsealBDSensorTypeDef *sensor);
void EsealBDUpdataSensorTemperature (CPU_INT16S temperature);
void EsealBDUpdataSensorHumidity (CPU_INT16U humidity);
void EsealBDUpdataSensorShake (CPU_INT16U shake);
void EsealBDSetState (sEsealBDStateTypeDef state);
void EsealBDGetState (sEsealBDStateTypeDef *state);
CPU_INT8U EsealBDGetCH (FNCT_COMM comm);
void EsealBDPowerOn (void);
void EsealBDPowerOff (void);
void EsealBDUpdataSafe (CPU_INT8U safe);
void EsealBDGetFix (sEsealBDFixTypeDef *fix);
void EsealSafeCheck (void);
void EsealBDUpdataUtc (void);
void EsealBDProcess (CPU_INT32U cnt);
void EsealGprsProcess (CPU_INT32U cnt);
void EsealBDProcessUpdata (CPU_INT32U cnt);
void EsealBDUpdata (eEsealBDUpdataTypeDef type, FNCT_COMM com);
void EsealBDUpdataExtra (eEsealBDUpdataTypeDef type, CPU_INT16U delay , CPU_INT8U count, FNCT_COMM com);

void EsealBuffInit (void);
eEsealUpdataTXQueueTypeDef EsealBuffDataOut (sEsealUpdataItemTypeDef *pitem);
eEsealUpdataTXQueueTypeDef EsealBuffDataIn (CPU_INT8U *pdata, CPU_INT16U len);

void EsealUpdataExtraCOllectedInfoInit (void);
void EsealUpdataExtraCOllectedInfo(FNCT_COMM com);
void EsealBDUpdataResetFlagSet (CPU_BOOL flag);
CPU_BOOL EsealBDUpdataResetFlagGet (void);

void EsealBDQiuUpdate(void);

/*************************************************************************************************************
*                                               MODULE END                                                   *
*************************************************************************************************************/
#ifdef __cplusplus
}
#endif

#endif
