/*************************************************************************************************************
*                                                  MODULE                                                    *
*************************************************************************************************************/
#ifndef DEV_UART_H
#define DEV_UART_H

#ifdef __cplusplus
extern "C" {
#endif

/*************************************************************************************************************
*                                                 DEFINES                                                    *
*************************************************************************************************************/
#define DEV_UART_NUM                            7u  
#define DEV_UART_INT_NUM                        4u
#define DEV_UART_LOCTION_NUM                    6u
#define DEV_UART_IRQ_MASK                       (USART_INT_TXC | USART_INT_TXBL | USART_INT_RXDATAV | USART_INT_RXFULL)

#define DEV_UART0_LOC0_TX_PORT                  DEV_GPIO_PORTE
#define DEV_UART0_LOC0_RX_PORT                  DEV_GPIO_PORTE
#define DEV_UART0_LOC1_TX_PORT                  DEV_GPIO_PORTE
#define DEV_UART0_LOC1_RX_PORT                  DEV_GPIO_PORTE
#define DEV_UART0_LOC2_TX_PORT                  DEV_GPIO_PORTC
#define DEV_UART0_LOC2_RX_PORT                  DEV_GPIO_PORTC 
#define DEV_UART0_LOC3_TX_PORT                  DEV_GPIO_PORTE
#define DEV_UART0_LOC3_RX_PORT                  DEV_GPIO_PORTE
#define DEV_UART0_LOC4_TX_PORT                  DEV_GPIO_PORTB
#define DEV_UART0_LOC4_RX_PORT                  DEV_GPIO_PORTB
#define DEV_UART0_LOC5_TX_PORT                  DEV_GPIO_PORTC
#define DEV_UART0_LOC5_RX_PORT                  DEV_GPIO_PORTC
    
#define DEV_UART1_LOC0_TX_PORT                  DEV_GPIO_PORTC
#define DEV_UART1_LOC0_RX_PORT                  DEV_GPIO_PORTC
#define DEV_UART1_LOC1_TX_PORT                  DEV_GPIO_PORTD
#define DEV_UART1_LOC1_RX_PORT                  DEV_GPIO_PORTD
#define DEV_UART1_LOC2_TX_PORT                  DEV_GPIO_PORTD
#define DEV_UART1_LOC2_RX_PORT                  DEV_GPIO_PORTD

#define DEV_UART2_LOC0_TX_PORT                  DEV_GPIO_PORTC
#define DEV_UART2_LOC0_RX_PORT                  DEV_GPIO_PORTC
#define DEV_UART2_LOC1_TX_PORT                  DEV_GPIO_PORTB
#define DEV_UART2_LOC1_RX_PORT                  DEV_GPIO_PORTB
    
#define DEV_UART3_LOC0_TX_PORT                  DEV_GPIO_PORTF
#define DEV_UART3_LOC0_RX_PORT                  DEV_GPIO_PORTF 
#define DEV_UART3_LOC1_TX_PORT                  DEV_GPIO_PORTE
#define DEV_UART3_LOC1_RX_PORT                  DEV_GPIO_PORTE
#define DEV_UART3_LOC2_TX_PORT                  DEV_GPIO_PORTA
#define DEV_UART3_LOC2_RX_PORT                  DEV_GPIO_PORTA

#define DEV_UART4_LOC1_TX_PORT                  DEV_GPIO_PORTF
#define DEV_UART4_LOC1_RX_PORT                  DEV_GPIO_PORTF 
#define DEV_UART4_LOC2_TX_PORT                  DEV_GPIO_PORTB
#define DEV_UART4_LOC2_RX_PORT                  DEV_GPIO_PORTB
#define DEV_UART4_LOC3_TX_PORT                  DEV_GPIO_PORTE
#define DEV_UART4_LOC3_RX_PORT                  DEV_GPIO_PORTE
 
#define DEV_UART5_LOC0_TX_PORT                  DEV_GPIO_PORTD
#define DEV_UART5_LOC0_RX_PORT                  DEV_GPIO_PORTD     
#define DEV_UART5_LOC1_TX_PORT                  DEV_GPIO_PORTB
#define DEV_UART5_LOC1_RX_PORT                  DEV_GPIO_PORTB 
#define DEV_UART5_LOC2_TX_PORT                  DEV_GPIO_PORTE
#define DEV_UART5_LOC2_RX_PORT                  DEV_GPIO_PORTE
#define DEV_UART5_LOC3_TX_PORT                  DEV_GPIO_PORTF
#define DEV_UART5_LOC3_RX_PORT                  DEV_GPIO_PORTF
#define DEV_UART5_LOC4_TX_PORT                  DEV_GPIO_PORTF
#define DEV_UART5_LOC4_RX_PORT                  DEV_GPIO_PORTA 
    
#define DEV_UART6_LOC0_TX_PORT                  DEV_GPIO_PORTC
#define DEV_UART6_LOC0_RX_PORT                  DEV_GPIO_PORTC 
#define DEV_UART6_LOC1_TX_PORT                  DEV_GPIO_PORTA
#define DEV_UART6_LOC1_RX_PORT                  DEV_GPIO_PORTA
    
#define DEV_UART0_LOC0_TX_PIN                   DEV_GPIO_PIN_10
#define DEV_UART0_LOC0_RX_PIN                   DEV_GPIO_PIN_11
#define DEV_UART0_LOC1_TX_PIN                   DEV_GPIO_PIN_7
#define DEV_UART0_LOC1_RX_PIN                   DEV_GPIO_PIN_6
#define DEV_UART0_LOC2_TX_PIN                   DEV_GPIO_PIN_11
#define DEV_UART0_LOC2_RX_PIN                   DEV_GPIO_PIN_10 
#define DEV_UART0_LOC3_TX_PIN                   DEV_GPIO_PIN_13
#define DEV_UART0_LOC3_RX_PIN                   DEV_GPIO_PIN_12
#define DEV_UART0_LOC4_TX_PIN                   DEV_GPIO_PIN_7
#define DEV_UART0_LOC4_RX_PIN                   DEV_GPIO_PIN_8
#define DEV_UART0_LOC5_TX_PIN                   DEV_GPIO_PIN_0
#define DEV_UART0_LOC5_RX_PIN                   DEV_GPIO_PIN_1
     
#define DEV_UART1_LOC0_TX_PIN                   DEV_GPIO_PIN_0
#define DEV_UART1_LOC0_RX_PIN                   DEV_GPIO_PIN_1
#define DEV_UART1_LOC1_TX_PIN                   DEV_GPIO_PIN_0
#define DEV_UART1_LOC1_RX_PIN                   DEV_GPIO_PIN_1
#define DEV_UART1_LOC2_TX_PIN                   DEV_GPIO_PIN_7
#define DEV_UART1_LOC2_RX_PIN                   DEV_GPIO_PIN_6

#define DEV_UART2_LOC0_TX_PIN                   DEV_GPIO_PIN_2
#define DEV_UART2_LOC0_RX_PIN                   DEV_GPIO_PIN_3
#define DEV_UART2_LOC1_TX_PIN                   DEV_GPIO_PIN_3
#define DEV_UART2_LOC1_RX_PIN                   DEV_GPIO_PIN_4
    
#define DEV_UART3_LOC0_TX_PIN                   DEV_GPIO_PIN_6
#define DEV_UART3_LOC0_RX_PIN                   DEV_GPIO_PIN_7 
#define DEV_UART3_LOC1_TX_PIN                   DEV_GPIO_PIN_0
#define DEV_UART3_LOC1_RX_PIN                   DEV_GPIO_PIN_1
#define DEV_UART3_LOC2_TX_PIN                   DEV_GPIO_PIN_3
#define DEV_UART3_LOC2_RX_PIN                   DEV_GPIO_PIN_4

#define DEV_UART4_LOC1_TX_PIN                   DEV_GPIO_PIN_10
#define DEV_UART4_LOC1_RX_PIN                   DEV_GPIO_PIN_11 
#define DEV_UART4_LOC2_TX_PIN                   DEV_GPIO_PIN_9
#define DEV_UART4_LOC2_RX_PIN                   DEV_GPIO_PIN_10
#define DEV_UART4_LOC3_TX_PIN                   DEV_GPIO_PIN_2
#define DEV_UART4_LOC3_RX_PIN                   DEV_GPIO_PIN_3
 
#define DEV_UART5_LOC0_TX_PIN                   DEV_GPIO_PIN_4
#define DEV_UART5_LOC0_RX_PIN                   DEV_GPIO_PIN_5     
#define DEV_UART5_LOC1_TX_PIN                   DEV_GPIO_PIN_13
#define DEV_UART5_LOC1_RX_PIN                   DEV_GPIO_PIN_14 
#define DEV_UART5_LOC2_TX_PIN                   DEV_GPIO_PIN_14
#define DEV_UART5_LOC2_RX_PIN                   DEV_GPIO_PIN_15
#define DEV_UART5_LOC3_TX_PIN                   DEV_GPIO_PIN_0
#define DEV_UART5_LOC3_RX_PIN                   DEV_GPIO_PIN_1
#define DEV_UART5_LOC4_TX_PIN                   DEV_GPIO_PIN_2
#define DEV_UART5_LOC4_RX_PIN                   DEV_GPIO_PIN_0 
    
#define DEV_UART6_LOC0_TX_PIN                   DEV_GPIO_PIN_6
#define DEV_UART6_LOC0_RX_PIN                   DEV_GPIO_PIN_7 
#define DEV_UART6_LOC1_TX_PIN                   DEV_GPIO_PIN_5
#define DEV_UART6_LOC1_RX_PIN                   DEV_GPIO_PIN_6
    
#define DEV_UART0_LOC0                          USART_LOC0
#define DEV_UART0_LOC1                          USART_LOC1
#define DEV_UART0_LOC2                          USART_LOC2
#define DEV_UART0_LOC3                          USART_LOC3
#define DEV_UART0_LOC4                          USART_LOC4
#define DEV_UART0_LOC5                          USART_LOC5
    
#define DEV_UART1_LOC0                          USART_LOC0
#define DEV_UART1_LOC1                          USART_LOC1
#define DEV_UART1_LOC2                          USART_LOC2
    
#define DEV_UART2_LOC0                          USART_LOC0
#define DEV_UART2_LOC1                          USART_LOC1
    
#define DEV_UART3_LOC0                          USART_LOC0
#define DEV_UART3_LOC1                          USART_LOC1
#define DEV_UART3_LOC2                          USART_LOC2
    
#define DEV_UART4_LOC1                          USART_LOC1
#define DEV_UART4_LOC2                          USART_LOC2
#define DEV_UART4_LOC3                          USART_LOC3
    
#define DEV_UART5_LOC0                          USART_LOC0
#define DEV_UART5_LOC1                          USART_LOC1
#define DEV_UART5_LOC2                          USART_LOC2
#define DEV_UART5_LOC3                          USART_LOC3
#define DEV_UART5_LOC4                          USART_LOC4
    
#define DEV_UART6_LOC0                          USART_LOC0
#define DEV_UART6_LOC1                          USART_LOC1
    

    
    
    
/*************************************************************************************************************
*                                                  DATA TYPES                                                *
*************************************************************************************************************/
typedef enum
{
    DEV_UART0 = 0, 
    DEV_UART1 = 1,
    DEV_UART2 = 2,
    DEV_UART3 = 3, 
    DEV_UART4 = 4,
    DEV_UART5 = 5,
    DEV_UART6 = 6,
} DevUARTTypeDef;

typedef enum
{
    DEV_USART, 
    DEV_UART,
    DEV_LEUART,
} DevUARTTypeTypeDef;

typedef struct
{
    DevGPIOPortTypeDef tx_port;
    DevGPIOPortTypeDef rx_port;
    DevGPIOPinTypeDef  tx_pin;
    DevGPIOPinTypeDef  rx_pin;
    CPU_INT32U         loc;
} DevUARTPinTypeDef;

typedef struct
{
    CPU_INT32U         x;
    DevUARTTypeTypeDef type;
    DevUARTPinTypeDef  pin[DEV_UART_LOCTION_NUM];
} DevUARTTableTypeDef;

typedef enum
{
    DEV_UART_PIN_LOC0 = 0,
    DEV_UART_PIN_LOC1 = 1,
    DEV_UART_PIN_LOC2 = 2,
    DEV_UART_PIN_LOC3 = 3,
    DEV_UART_PIN_LOC4 = 4,
    DEV_UART_PIN_LOC5 = 5,
} DevUARTPinLoctionTypeDef;

typedef enum
{
    DEV_UART_TX  = USART_RX, 
    DEV_UART_RX  = USART_TX, 
    DEV_UART_RTX = USART_RTX,
} DevUARTRTxTypeDef;

typedef enum
{
    DEV_UART_BIT_8 = USART_DATABIT_EIGHT,
    DEV_UART_BIT_9 = USART_DATABIT_NINE,
} DevUARTDataBitTypeDef;

typedef enum
{
    DEV_UART_PARITY_NONE = USART_PARITY_NONE, 
    DEV_UART_PARITY_EVEN = USART_PARITY_EVEN, 
    DEV_UART_PARITY_ODD  = USART_PARITY_ODD, 
} DevUARTParityModeTypeDef;

typedef enum
{
    DEV_UART_STOP_BIT_0_5 = USART_STOP_BIT_HALF, 
    DEV_UART_STOP_BIT_1   = USART_STOP_BIT_ONE, 
    DEV_UART_STOP_BIT_1_5 = USART_STOP_BIT_ONEANDAHALF, 
    DEV_UART_STOP_BIT_2   = USART_STOP_BIT_TWO,
} DevUARTStopModeTypeDef;

typedef enum
{
    DEV_UART_CONTROL_NONE, 
    DEV_UART_CONTROL_RTS, 
    DEV_UART_CONTROL_CTS,
    DEV_UART_CONTROL_BOTH,
} DevUARTControlTypeDef;

typedef enum
{
    DEV_UART_INT_TXC     = USART_INT_TXC, 
    DEV_UART_INT_TXBL    = USART_INT_TXBL, 
    DEV_UART_INT_RXDATAV = USART_INT_RXDATAV,
    DEV_UART_INT_RXFULL  = USART_INT_RXFULL,
} DevUARTIntTypeDef;


/*************************************************************************************************************
*                                            FUNCTION STATEMENT                                              *
*************************************************************************************************************/ 
void DevUARTClockEnable (DevUARTTypeDef x);
void DevUARTClockDisable (DevUARTTypeDef x);
void DevUARTIOConfig (DevUARTTypeDef x, DevUARTPinLoctionTypeDef loction, DevUARTRTxTypeDef rtx);
void DevUARTInit (DevUARTTypeDef x, DevUARTStopModeTypeDef stop, DevUARTDataBitTypeDef bits, 
                  DevUARTParityModeTypeDef parity,DevUARTControlTypeDef control, 
                  CPU_INT32U baud, DevUARTRTxTypeDef rtx);
void DevUARTTxData (DevUARTTypeDef x, CPU_INT8U *pdata, CPU_INT32U len);
void DevUARTRxData (DevUARTTypeDef x, CPU_INT8U *pdata, CPU_INT32U len);
CPU_INT8U DevUARTIntRegister (DevUARTTypeDef x, DevUARTIntTypeDef irq, FNCT_VOID isr);
CPU_INT8U DevUARTIntRegisterUARTIntUnregister (DevUARTTypeDef x, DevUARTIntTypeDef irq);
void DevUARTIntInit (DevUARTTypeDef x);
CPU_INT8U DevUARTIntEnable (DevUARTTypeDef x, DevUARTIntTypeDef irq);
CPU_INT8U DevUARTIntDisable (DevUARTTypeDef x, DevUARTIntTypeDef irq);
void DevUART0RxIntHandler (void);
void DevUART0TxIntHandler (void);
void DevUART1RxIntHandler (void);
void DevUART1TxIntHandler (void);
void DevUART2RxIntHandler (void);
void DevUART2TxIntHandler (void);
void DevUART3RxIntHandler (void);
void DevUART3TxIntHandler (void);
void DevUART4RxIntHandler (void);
void DevUART4TxIntHandler (void);
void DevUART5IntHandler (void);
void DevUART6IntHandler (void);


/*************************************************************************************************************
*                                               MODULE END                                                   *
*************************************************************************************************************/ 
#ifdef __cplusplus
}
#endif

#endif
