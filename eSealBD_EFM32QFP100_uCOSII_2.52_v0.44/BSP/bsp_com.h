/*************************************************************************************************************
*                                                  MODULE                                                    *
*************************************************************************************************************/
#ifndef BSP_COM_H
#define BSP_COM_H

#ifdef __cplusplus
extern "C" {
#endif


/*************************************************************************************************************
*                                                 DEFINES                                                    *
*************************************************************************************************************/
#define	COM0                                    DEV_UART1
#define	COM1                                    DEV_UART2
#define	COM2                                    DEV_UART3
#define	COM3                                    DEV_UART4
#define	COM4                                    DEV_UART5
#define	COM5                                    DEV_UART6

#define	COM0_PIN_LOCTION                        DEV_UART_PIN_LOC0
#define	COM1_PIN_LOCTION                        DEV_UART_PIN_LOC0
#define	COM2_PIN_LOCTION                        DEV_UART_PIN_LOC2
#define	COM3_PIN_LOCTION                        DEV_UART_PIN_LOC3
#define	COM4_PIN_LOCTION                        DEV_UART_PIN_LOC0
#define	COM5_PIN_LOCTION                        DEV_UART_PIN_LOC0

#define	COM_RTX                                 DEV_UART_RTX
#define	COM_CONFIG_STOP                         DEV_UART_STOP_BIT_1
#define	COM_CONFIG_BIT                          DEV_UART_BIT_8
#define	COM_CONFIG_PARITY                       DEV_UART_PARITY_NONE
#define	COM_CONFIG_CONTROL                      DEV_UART_CONTROL_NONE

#define	COM0_TX_FIFO_SIZE                       512
#define	COM0_RX_FIFO_SIZE                       512
#define	COM1_TX_FIFO_SIZE                       512
#define	COM1_RX_FIFO_SIZE                       512
#define	COM2_TX_FIFO_SIZE                       512
#define	COM2_RX_FIFO_SIZE                       512
#define	COM3_TX_FIFO_SIZE                       512
#define	COM3_RX_FIFO_SIZE                       512
#define	COM4_TX_FIFO_SIZE                       512
#define	COM4_RX_FIFO_SIZE                       512
#define	COM5_TX_FIFO_SIZE                       512
#define	COM5_RX_FIFO_SIZE                       512

#define	COM_OK                                  0
#define	COM_ERROR_TX_FIFO_FULL                  1


/*************************************************************************************************************
*                                            FUNCTION STATEMENT                                              *
*************************************************************************************************************/
void COM0Init (CPU_INT32U baud);
void COM0SendData (CPU_INT8U *pdata, CPU_INT32U len);
CPU_INT8U COM0TxFIFOIn (CPU_INT8U *pdata, CPU_INT16U len);
void COM0TxFIFOOut (void);
CPU_BOOL COM0RxFIFOIsEmpty (void);
CPU_INT8U COM0RxFIFOOut (void);
void COM0RxIrqHandle (void);
void COM1Init (CPU_INT32U baud);
void COM1SendData (CPU_INT8U *pdata, CPU_INT32U len);
CPU_INT8U COM1TxFIFOIn (CPU_INT8U *pdata, CPU_INT16U len);
void COM1TxFIFOOut (void);
CPU_BOOL COM1RxFIFOIsEmpty (void);
CPU_INT8U COM1RxFIFOOut (void);
void COM1RxIrqHandle (void);
void COM1RxFIFOClear (void);
void COM2Init (CPU_INT32U baud);
void COM2SendData (CPU_INT8U *pdata, CPU_INT32U len);
CPU_INT8U COM2TxFIFOIn (CPU_INT8U *pdata, CPU_INT16U len);
void COM2TxFIFOOut (void);
CPU_BOOL COM2RxFIFOIsEmpty (void);
CPU_INT8U COM2RxFIFOOut (void);
void COM2RxIrqHandle (void);
void COM2RxFIFOClear (void);
void COM3Init (CPU_INT32U baud);
void COM3SendData (CPU_INT8U *pdata, CPU_INT32U len);
CPU_INT8U COM3TxFIFOIn (CPU_INT8U *pdata, CPU_INT16U len);
void COM3TxFIFOOut (void);
CPU_BOOL COM3RxFIFOIsEmpty (void);
CPU_INT8U COM3RxFIFOOut (void);
void COM3RxIrqHandle (void);
void COM3RxFIFOClear (void);
void COM4Init (CPU_INT32U baud);
void COM4SendData (CPU_INT8U *pdata, CPU_INT32U len);
CPU_INT8U COM4TxFIFOIn (CPU_INT8U *pdata, CPU_INT16U len);
void COM4TxFIFOOut (void);
CPU_BOOL COM4RxFIFOIsEmpty (void);
CPU_INT8U COM4RxFIFOOut (void);
void COM4RxIrqHandle (void);
void COM5Init (CPU_INT32U baud);
void COM5SendData (CPU_INT8U *pdata, CPU_INT32U len);
CPU_INT8U COM5TxFIFOIn (CPU_INT8U *pdata, CPU_INT16U len);
void COM5TxFIFOOut (void);
CPU_BOOL COM5RxFIFOIsEmpty (void);
CPU_INT8U COM5RxFIFOOut (void);
void COM5RxIrqHandle (void);

/*************************************************************************************************************
*                                               MODULE END                                                   *
*************************************************************************************************************/
#ifdef __cplusplus
}
#endif

#endif
