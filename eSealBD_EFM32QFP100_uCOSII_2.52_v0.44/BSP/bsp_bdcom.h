/*************************************************************************************************************
*                                                  MODULE                                                    *
*************************************************************************************************************/
#ifndef BSP_BDCOM_H
#define BSP_BDCOM_H

#ifdef __cplusplus
extern "C" {
#endif


/*************************************************************************************************************
*                                                 DEFINES                                                    *
*************************************************************************************************************/
#define BD_COM_DATA_MAX_SIZE                    256u
#define BD_COM_PACK_DATA_SIZE                   18u
#define BD_COM_TX_FIFO_SIZE                     256u
#define BD_COM_RX_FIFO_SIZE                     256u    
#define BD_DATA_QUEUE_SIZE                      1u
#define BD_COMMANDER_ID                         522885u

#define BSP_BD_COM_EN_PIN                       DEV_GPIO_PIN_7
#define BSP_BD_COM_EN_PORT                      DEV_GPIO_PORTE
    

/*************************************************************************************************************
*                                                  DATA TYPES                                                *
*************************************************************************************************************/
typedef enum 
{
    BDCOM_TX_OK,
    BDCOM_ERROR_TX_FIFO_FULL,
} BDCOMTXTypeDef;

typedef enum 
{
    BDCOM_RX_OK,
    BDCOM_ERROR_RX_FIFO_FULL,
} BDCOMRXTypeDef;

//typedef struct 
//{
//    CPU_INT8U ch1_power;
//    CPU_INT8U ch2_power;
//    CPU_INT8U ch1_lock_wave;
//    CPU_INT8U ch2_lock_wave;
//    CPU_INT8U responce_wave;
//    CPU_BOOL single_status;
//    CPU_BOOL power_status;
//    CPU_INT32U id;
//    CPU_INT8U broadcast_addr;
//    CPU_INT16U service_period;
//    CPU_INT8U buad;
//    CPU_BOOL secret_module;
//    CPU_BOOL height_module;
//} BDCOMStatusTypeDef;

typedef struct
{
    CPU_INT8U CustomerAddr[3];
    CPU_INT8U WideAddr[3];
    CPU_INT16U SerFrequency;
    CPU_BOOL flag;
}BDCOMStatusTypeDef;

typedef struct 
{
    CPU_BOOL crc_flag;
    CPU_INT8U trans_type;
    CPU_INT8U send_type;
    CPU_INT8U send_addr;
    CPU_INT8U acknowledg;
    CPU_INT8U sequence;
    CPU_INT8U data_len;
    CPU_INT8U *pdata;
} BDCOMCoutTypeDef;

typedef struct
{
    CPU_INT8U len;
    CPU_INT8U data[BD_COM_DATA_MAX_SIZE];
} sBDDataItemTypeDef;

typedef struct 
{
    CPU_INT32U front;
    CPU_INT32U rear; 
    CPU_INT32U count;
    sBDDataItemTypeDef item[BD_DATA_QUEUE_SIZE];       
} sBDDataQueueTypeDef;

typedef struct 
{
    volatile CPU_BOOL data_queue_flag;
    sBDDataQueueTypeDef data_queue;
       
} sBDDataTypeDef;

typedef enum 
{
    BDCOM_TX_QUEUE_OK,
    BDCOM_ERROR_TX_SIZE_OUT_OF_RANGE,
} BDCOMTXQueueTypeDef;

#pragma pack(1)

typedef struct
{
    CPU_BOOL   flag;
    CPU_INT16U count;
    CPU_INT8U  data[BD_COM_DATA_MAX_SIZE];
} sBDPackageTypeDef;

#pragma pack()


/*************************************************************************************************************
*                                            FUNCTION STATEMENT                                              *
*************************************************************************************************************/
void BDComInit (void);
void BspBdCOMEnable (void);
void BspBdCOMDisable(void);
CPU_INT8U GetReceiveDataLen (CPU_INT8U *pdata, CPU_INT16U len, CPU_INT8U *data_site);
BDCOMRXTypeDef BDComRxFIFOIn (CPU_INT8U *pdata, CPU_INT16U len);
void BDComReceive (sBDPackageTypeDef *package, CPU_INT8U *pdata, CPU_INT16U len);
//void BDComDATAPack (CPU_INT8U *buff, CPU_INT8U *pdata, CPU_INT16U len);
void BDComDATAPack (CPU_INT8U *buff, CPU_INT8U *pdata, CPU_INT16U len, CPU_INT8U *customeraddr);
void BDComSendData (CPU_INT8U *pdata, CPU_INT16U len);
BDCOMTXTypeDef BDComTxFIFOIn (CPU_INT8U *pdata, CPU_INT16U len);
void BDComTxFIFOOut (void);
CPU_BOOL BDComRxFIFOIsEmpty (void);
CPU_INT8U BDComRxData (void);
void BDComRxFIFOClear (void);
CPU_INT32U BDGetCoutSendID(CPU_INT8U *pdata, CPU_INT8U len);
CPU_BOOL BDModuleInfoGet(BDCOMStatusTypeDef *status);
CPU_BOOL BDModuleStateGet(void);
CPU_INT32U BDASSICToHex (CPU_INT8U *p, CPU_INT8U len);


void BDBuffInit (void);
void BDBuffDataOut (CPU_INT8U *pdata, CPU_INT16U len, CPU_INT8U *err);
BDCOMTXQueueTypeDef BDBuffDataIn (CPU_INT8U *pdata, CPU_INT16U len);
void sBDPackageInit (sBDPackageTypeDef *package);


/*************************************************************************************************************
*                                               MODULE END                                                   *
*************************************************************************************************************/
#ifdef __cplusplus
}
#endif

#endif
