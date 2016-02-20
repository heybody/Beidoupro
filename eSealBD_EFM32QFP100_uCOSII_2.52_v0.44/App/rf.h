/*************************************************************************************************************
*                                                  MODULE                                                    *
*************************************************************************************************************/
#ifndef  RF_H
#define  RF_H

#ifdef __cplusplus
extern "C" {
#endif

    
/*************************************************************************************************************
*                                                 DEFINES                                                    *
*************************************************************************************************************/
#define RF_NUM                                  1
  
#define RF_SFD                                  0xA7u
#define RF_CH                                   0u

#define RF_STATUS_STANDBY                       0u
#define RF_STATUS_TX                            1u
#define RF_STATUS_RX                            2u
#define RF_STATUS_SLEEP                         3u
  
#define RF_DEVICE_ERROR                         0u
#define RF_RX_OK                                1u    
#define RF_RX_TIMEOUT                           2u
#define RF_RX_CD                                3u
#define RF_RX_CONTINUE                          4u
    
#define RF_RXD_OK                               1u
#define RF_RXD_CRC_ERROR                        2u

#define RF_DATA_SIZE                            128
#define RF_DATA_QUEUE_SIZE                      5
#define RF_DATA_STACK_SIZE                      5
    
#define RF_TX_MAX_DELAY                         50
  
#define RF_CH_NUM                               16
    
#define RF_CH_0                                 0
#define RF_CH_1                                 1
#define RF_CH_2                                 2
#define RF_CH_3                                 3
#define RF_CH_4                                 4
#define RF_CH_5                                 5
#define RF_CH_6                                 6
#define RF_CH_7                                 7
#define RF_CH_8                                 8
#define RF_CH_9                                 9
#define RF_CH_10                                10
#define RF_CH_11                                11
#define RF_CH_12                                12
#define RF_CH_13                                13
#define RF_CH_14                                14
#define RF_CH_15                                15
    
#define RF_CH_STD                               RF_CH_0
#define RF_CH_BOT_TEST                          RF_CH_4
#define RF_CH_BOT_TEST1                         RF_CH_7
#define RF_CH_BOT_RD                            RF_CH_6
 
#define RF_CH_DEFAULT                           RF_CH_STD
    
#define RF_POWER_LEVEL                          BSP_A7153_POWER_LEVEL
#define RF_POWER_MIN                            BSP_A7153_POWER_MIN
    
#define RF_0_IRQ_PORT                           BSP_A7153_0_GIO2_PORT  
#define RF_0_IRQ_PIN                            BSP_A7153_0_GIO2_PIN
    

/*************************************************************************************************************
*                                                  DATA TYPES                                                *
*************************************************************************************************************/
typedef struct
{
    CPU_BOOL crc_flag;
    CPU_INT8U len;
    CPU_INT8U data[RF_DATA_SIZE];
} sRFDataType;

typedef struct 
{
    CPU_INT32U front;
    CPU_INT32U rear; 
    CPU_INT32U count;
    sRFDataType item[RF_DATA_QUEUE_SIZE];       
} sRFDataQueue;

typedef struct
{
    CPU_INT32U sp;
    sRFDataType item[RF_DATA_STACK_SIZE];     
} sRFDataStack;
  

typedef struct 
{
    sRFDataQueue data_queue;
    sRFDataStack data_stack;
    volatile CPU_BOOL data_queue_flag;
    volatile CPU_INT8U tx_rx_flag;
    volatile CPU_INT32U tx_count;
    volatile CPU_INT32U rx_timeout;
} RFDataTypeDef;

typedef enum 
{
    RF_A7153_0 = 0,
} RFTypeDef;

typedef struct 
{
    DevGPIOPinTypeDef irq_pin;
    DevGPIOPortTypeDef irq_port;
    BspA7153TypeDef a7153;
} RFDeveiceTypeDef;

    
/*************************************************************************************************************
*                                            FUNCTION STATEMENT                                              *
*************************************************************************************************************/
CPU_BOOL RFInit (RFTypeDef n, CPU_INT8U ch);
void RFBuffInit (RFTypeDef n);
CPU_BOOL RFBuffDataOut (RFTypeDef n, CPU_INT8U *pdata, CPU_INT32U *plen);
void RFTRxIntRegister (RFTypeDef n, FNCT_VOID isr);
void RFTRxIntEnable (RFTypeDef n);
void RFTRxIntDisable (RFTypeDef n);
void RFTRxIntClear (RFTypeDef n);
void RFSetStandby (RFTypeDef n);
void RFTxInit (RFTypeDef n, CPU_INT8U ch, CPU_INT8U *pdata, CPU_INT32U len);
void RFTx (RFTypeDef n, CPU_INT32U cnt);
CPU_INT8U RFSetRx (RFTypeDef n, CPU_INT8U ch, CPU_INT32U timeout);
CPU_INT8U RFRxData (RFTypeDef n, CPU_INT8U *pdata, CPU_INT32U *len);
CPU_INT8U RFGetTxCH (RFTypeDef n);
CPU_INT8U RFGetRxCH (RFTypeDef n);
CPU_BOOL RFPowerSet (RFTypeDef n, CPU_INT8S power);
CPU_INT8S RFPowerGet (RFTypeDef n);
CPU_BOOL RFChipCheck (RFTypeDef n);
CPU_INT8U RFStatusGet (RFTypeDef n);
void RFSleep (RFTypeDef n);
void RF0TRxComplete (void);


/*************************************************************************************************************
*                                               MODULE END                                                   *
*************************************************************************************************************/
#ifdef __cplusplus
}
#endif

#endif



