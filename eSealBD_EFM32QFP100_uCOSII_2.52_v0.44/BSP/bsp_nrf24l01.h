/***************************************************************************************************
*                                              MODULE                                              *
***************************************************************************************************/
#ifndef BSP_NRF24L01_H
#define BSP_NRF24L01_H

#ifdef __cplusplus
extern "C" {
#endif
 
    
/***************************************************************************************************
*                                             DEFINES                                              *
***************************************************************************************************/
#define NRF24L01_CSN_PIN                    DEV_GPIO_PIN_14 
#define NRF24L01_CE_PIN                     DEV_GPIO_PIN_15
#define NRF24L01_IRQ_PIN                    DEV_GPIO_PIN_9 
#define NRF24L01_CSN_PORT                   DEV_GPIO_PORTE 
#define NRF24L01_CE_PORT                    DEV_GPIO_PORTE
#define NRF24L01_IRQ_PORT                   DEV_GPIO_PORTE 

#define AW                                  3
#define PW                                  9
#define CH                                  8
    
#define RF_DATA_SIZE                        9
#define RF_DATA_QUEUE_SIZE                  10
#define RF_DATA_STACK_SIZE                  10
 
    
/***************************************************************************************************
*                                              DATA TYPES                                          *
***************************************************************************************************/
typedef struct
{
    CPU_INT8U data[RF_DATA_SIZE];
}sRFDataType;

typedef struct 
{
    CPU_INT16U front;
    CPU_INT16U rear; 
    CPU_INT16U count;
    sRFDataType item[RF_DATA_QUEUE_SIZE];       
}sRFDataQueue;

typedef struct
{
    CPU_INT16U sp;
    sRFDataType item[RF_DATA_STACK_SIZE];     
}sRFDataStack;

typedef struct 
{
    sRFDataQueue queue;
    sRFDataStack stack;
    CPU_BOOL flag;
}sRFDataTypeDef;


/***************************************************************************************************
*                                        FUNCTION STATEMENT                                        *
***************************************************************************************************/
void nRF24L01IOInit (void);
void nRF24L01RxIntEnable (FNCT_VOID isr);
void nRF24L01CSNH (void);
void nRF24L01CSNL (void);
void nRF24L01CEH (void);
void nRF24L01CEL (void);
void nRF24L01Init (void);
void nRF24L01WrReg (CPU_INT8U addr, CPU_INT8U data);
void nRF24L01RdReg (CPU_INT8U addr, CPU_INT8U *data);
void nRF24L01WrTxFIFO (CPU_INT8U *pdata, CPU_INT16U len);
void nRF24L01RdRxFIFO (CPU_INT8U *pdata, CPU_INT16U len);
void nRF24L01WrIDCode (CPU_INT8U pipe, CPU_INT8U *paddr, CPU_INT16U len);
void nRF24L01RdIDCode (CPU_INT8U pipe, CPU_INT8U *paddr, CPU_INT16U len);
void nRF24L01ClrRxFIFO (void);
void nRF24L01SetSleep (void);
void nRF24L01SetRx (void);
void nRF24L01DataRx (CPU_INT8U *pdata, CPU_INT16U *len);
void nRF24L01RxIrqHandler (void);


/***************************************************************************************************
*                                           MODULE END                                             *
***************************************************************************************************/
#ifdef __cplusplus
}
#endif

#endif

























