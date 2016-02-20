/*************************************************************************************************************
*                                              INCLUDE FILES                                                 *
*************************************************************************************************************/
#include <dev.h>


/*************************************************************************************************************
*                                                CONSTANTS                                                   *
*************************************************************************************************************/
const DevUARTTableTypeDef  DevUARTTable[DEV_UART_NUM] = 
{
    {
        .x    = USART_0,\
        .type = DEV_USART,\
        .pin[DEV_UART_PIN_LOC0].tx_port = DEV_UART0_LOC0_TX_PORT,\
        .pin[DEV_UART_PIN_LOC0].rx_port = DEV_UART0_LOC0_RX_PORT,\
        .pin[DEV_UART_PIN_LOC0].tx_pin  = DEV_UART0_LOC0_TX_PIN,\
        .pin[DEV_UART_PIN_LOC0].rx_pin  = DEV_UART0_LOC0_RX_PIN,\
        .pin[DEV_UART_PIN_LOC0].loc     = DEV_UART0_LOC0,\
        .pin[DEV_UART_PIN_LOC1].tx_port = DEV_UART0_LOC1_TX_PORT,\
        .pin[DEV_UART_PIN_LOC1].rx_port = DEV_UART0_LOC1_RX_PORT,\
        .pin[DEV_UART_PIN_LOC1].tx_pin  = DEV_UART0_LOC1_TX_PIN,\
        .pin[DEV_UART_PIN_LOC1].rx_pin  = DEV_UART0_LOC1_RX_PIN,\
        .pin[DEV_UART_PIN_LOC1].loc     = DEV_UART0_LOC1,\
        .pin[DEV_UART_PIN_LOC2].tx_port = DEV_UART0_LOC2_TX_PORT,\
        .pin[DEV_UART_PIN_LOC2].rx_port = DEV_UART0_LOC2_RX_PORT,\
        .pin[DEV_UART_PIN_LOC2].tx_pin  = DEV_UART0_LOC2_TX_PIN,\
        .pin[DEV_UART_PIN_LOC2].rx_pin  = DEV_UART0_LOC2_RX_PIN,\
        .pin[DEV_UART_PIN_LOC2].loc     = DEV_UART0_LOC2,\
        .pin[DEV_UART_PIN_LOC3].tx_port = DEV_UART0_LOC3_TX_PORT,\
        .pin[DEV_UART_PIN_LOC3].rx_port = DEV_UART0_LOC3_RX_PORT,\
        .pin[DEV_UART_PIN_LOC3].tx_pin  = DEV_UART0_LOC3_TX_PIN,\
        .pin[DEV_UART_PIN_LOC3].rx_pin  = DEV_UART0_LOC3_RX_PIN,\
        .pin[DEV_UART_PIN_LOC3].loc     = DEV_UART0_LOC3,\
        .pin[DEV_UART_PIN_LOC4].tx_port = DEV_UART0_LOC4_TX_PORT,\
        .pin[DEV_UART_PIN_LOC4].rx_port = DEV_UART0_LOC4_RX_PORT,\
        .pin[DEV_UART_PIN_LOC4].tx_pin  = DEV_UART0_LOC4_TX_PIN,\
        .pin[DEV_UART_PIN_LOC4].rx_pin  = DEV_UART0_LOC4_RX_PIN,\
        .pin[DEV_UART_PIN_LOC4].loc     = DEV_UART0_LOC4,\
        .pin[DEV_UART_PIN_LOC5].tx_port = DEV_UART0_LOC5_TX_PORT,\
        .pin[DEV_UART_PIN_LOC5].rx_port = DEV_UART0_LOC5_RX_PORT,\
        .pin[DEV_UART_PIN_LOC5].tx_pin  = DEV_UART0_LOC5_TX_PIN,\
        .pin[DEV_UART_PIN_LOC5].rx_pin  = DEV_UART0_LOC5_RX_PIN,\
        .pin[DEV_UART_PIN_LOC5].loc     = DEV_UART0_LOC5,\
    },\
    {
        .x    = USART_1,\
        .type = DEV_USART,\
        .pin[DEV_UART_PIN_LOC0].tx_port = DEV_UART1_LOC0_TX_PORT,\
        .pin[DEV_UART_PIN_LOC0].rx_port = DEV_UART1_LOC0_RX_PORT,\
        .pin[DEV_UART_PIN_LOC0].tx_pin  = DEV_UART1_LOC0_TX_PIN,\
        .pin[DEV_UART_PIN_LOC0].rx_pin  = DEV_UART1_LOC0_RX_PIN,\
        .pin[DEV_UART_PIN_LOC0].loc     = DEV_UART1_LOC0,\
        .pin[DEV_UART_PIN_LOC1].tx_port = DEV_UART1_LOC1_TX_PORT,\
        .pin[DEV_UART_PIN_LOC1].rx_port = DEV_UART1_LOC1_RX_PORT,\
        .pin[DEV_UART_PIN_LOC1].tx_pin  = DEV_UART1_LOC1_TX_PIN,\
        .pin[DEV_UART_PIN_LOC1].rx_pin  = DEV_UART1_LOC1_RX_PIN,\
        .pin[DEV_UART_PIN_LOC1].loc     = DEV_UART1_LOC1,\
        .pin[DEV_UART_PIN_LOC2].tx_port = DEV_UART1_LOC2_TX_PORT,\
        .pin[DEV_UART_PIN_LOC2].rx_port = DEV_UART1_LOC2_RX_PORT,\
        .pin[DEV_UART_PIN_LOC2].tx_pin  = DEV_UART1_LOC2_TX_PIN,\
        .pin[DEV_UART_PIN_LOC2].rx_pin  = DEV_UART1_LOC2_RX_PIN,\
        .pin[DEV_UART_PIN_LOC2].loc     = DEV_UART1_LOC2,\
    },\
    {
        .x    = USART_2,\
        .type = DEV_USART,\
        .pin[DEV_UART_PIN_LOC0].tx_port = DEV_UART2_LOC0_TX_PORT,\
        .pin[DEV_UART_PIN_LOC0].rx_port = DEV_UART2_LOC0_RX_PORT,\
        .pin[DEV_UART_PIN_LOC0].tx_pin  = DEV_UART2_LOC0_TX_PIN,\
        .pin[DEV_UART_PIN_LOC0].rx_pin  = DEV_UART2_LOC0_RX_PIN,\
        .pin[DEV_UART_PIN_LOC0].loc     = DEV_UART2_LOC0,\
        .pin[DEV_UART_PIN_LOC1].tx_port = DEV_UART2_LOC1_TX_PORT,\
        .pin[DEV_UART_PIN_LOC1].rx_port = DEV_UART2_LOC1_RX_PORT,\
        .pin[DEV_UART_PIN_LOC1].tx_pin  = DEV_UART2_LOC1_TX_PIN,\
        .pin[DEV_UART_PIN_LOC1].rx_pin  = DEV_UART2_LOC1_RX_PIN,\
        .pin[DEV_UART_PIN_LOC1].loc     = DEV_UART2_LOC1,\
    },\
    {
        .x    = UART_0,\
        .type = DEV_UART,\
        .pin[DEV_UART_PIN_LOC0].tx_port = DEV_UART3_LOC0_TX_PORT,\
        .pin[DEV_UART_PIN_LOC0].rx_port = DEV_UART3_LOC0_RX_PORT,\
        .pin[DEV_UART_PIN_LOC0].tx_pin  = DEV_UART3_LOC0_TX_PIN,\
        .pin[DEV_UART_PIN_LOC0].rx_pin  = DEV_UART3_LOC0_RX_PIN,\
        .pin[DEV_UART_PIN_LOC0].loc     = DEV_UART3_LOC0,\
        .pin[DEV_UART_PIN_LOC1].tx_port = DEV_UART3_LOC1_TX_PORT,\
        .pin[DEV_UART_PIN_LOC1].rx_port = DEV_UART3_LOC1_RX_PORT,\
        .pin[DEV_UART_PIN_LOC1].tx_pin  = DEV_UART3_LOC1_TX_PIN,\
        .pin[DEV_UART_PIN_LOC1].rx_pin  = DEV_UART3_LOC1_RX_PIN,\
        .pin[DEV_UART_PIN_LOC1].loc     = DEV_UART3_LOC1,\
        .pin[DEV_UART_PIN_LOC2].tx_port = DEV_UART3_LOC2_TX_PORT,\
        .pin[DEV_UART_PIN_LOC2].rx_port = DEV_UART3_LOC2_RX_PORT,\
        .pin[DEV_UART_PIN_LOC2].tx_pin  = DEV_UART3_LOC2_TX_PIN,\
        .pin[DEV_UART_PIN_LOC2].rx_pin  = DEV_UART3_LOC2_RX_PIN,\
        .pin[DEV_UART_PIN_LOC2].loc     = DEV_UART3_LOC2,\
    },\
   {
        .x    = UART_1,\
        .type = DEV_UART,\
        .pin[DEV_UART_PIN_LOC1].tx_port = DEV_UART4_LOC1_TX_PORT,\
        .pin[DEV_UART_PIN_LOC1].rx_port = DEV_UART4_LOC1_RX_PORT,\
        .pin[DEV_UART_PIN_LOC1].tx_pin  = DEV_UART4_LOC1_TX_PIN,\
        .pin[DEV_UART_PIN_LOC1].rx_pin  = DEV_UART4_LOC1_RX_PIN,\
        .pin[DEV_UART_PIN_LOC1].loc     = DEV_UART4_LOC1,\
        .pin[DEV_UART_PIN_LOC2].tx_port = DEV_UART4_LOC2_TX_PORT,\
        .pin[DEV_UART_PIN_LOC2].rx_port = DEV_UART4_LOC2_RX_PORT,\
        .pin[DEV_UART_PIN_LOC2].tx_pin  = DEV_UART4_LOC2_TX_PIN,\
        .pin[DEV_UART_PIN_LOC2].rx_pin  = DEV_UART4_LOC2_RX_PIN,\
        .pin[DEV_UART_PIN_LOC2].loc     = DEV_UART4_LOC2,\
        .pin[DEV_UART_PIN_LOC3].tx_port = DEV_UART4_LOC3_TX_PORT,\
        .pin[DEV_UART_PIN_LOC3].rx_port = DEV_UART4_LOC3_RX_PORT,\
        .pin[DEV_UART_PIN_LOC3].tx_pin  = DEV_UART4_LOC3_TX_PIN,\
        .pin[DEV_UART_PIN_LOC3].rx_pin  = DEV_UART4_LOC3_RX_PIN,\
        .pin[DEV_UART_PIN_LOC3].loc     = DEV_UART4_LOC3,\
    },\
    {
        .x    = LEUART_0,\
        .type = DEV_LEUART,\
        .pin[DEV_UART_PIN_LOC0].tx_port = DEV_UART5_LOC0_TX_PORT,\
        .pin[DEV_UART_PIN_LOC0].rx_port = DEV_UART5_LOC0_RX_PORT,\
        .pin[DEV_UART_PIN_LOC0].tx_pin  = DEV_UART5_LOC0_TX_PIN,\
        .pin[DEV_UART_PIN_LOC0].rx_pin  = DEV_UART5_LOC0_RX_PIN,\
        .pin[DEV_UART_PIN_LOC0].loc     = DEV_UART5_LOC0,\
        .pin[DEV_UART_PIN_LOC1].tx_port = DEV_UART5_LOC1_TX_PORT,\
        .pin[DEV_UART_PIN_LOC1].rx_port = DEV_UART5_LOC1_RX_PORT,\
        .pin[DEV_UART_PIN_LOC1].tx_pin  = DEV_UART5_LOC1_TX_PIN,\
        .pin[DEV_UART_PIN_LOC1].rx_pin  = DEV_UART5_LOC1_RX_PIN,\
        .pin[DEV_UART_PIN_LOC1].loc     = DEV_UART5_LOC1,\
        .pin[DEV_UART_PIN_LOC2].tx_port = DEV_UART5_LOC2_TX_PORT,\
        .pin[DEV_UART_PIN_LOC2].rx_port = DEV_UART5_LOC2_RX_PORT,\
        .pin[DEV_UART_PIN_LOC2].tx_pin  = DEV_UART5_LOC2_TX_PIN,\
        .pin[DEV_UART_PIN_LOC2].rx_pin  = DEV_UART5_LOC2_RX_PIN,\
        .pin[DEV_UART_PIN_LOC2].loc     = DEV_UART5_LOC2,\
        .pin[DEV_UART_PIN_LOC3].tx_port = DEV_UART5_LOC3_TX_PORT,\
        .pin[DEV_UART_PIN_LOC3].rx_port = DEV_UART5_LOC3_RX_PORT,\
        .pin[DEV_UART_PIN_LOC3].tx_pin  = DEV_UART5_LOC3_TX_PIN,\
        .pin[DEV_UART_PIN_LOC3].rx_pin  = DEV_UART5_LOC3_RX_PIN,\
        .pin[DEV_UART_PIN_LOC3].loc     = DEV_UART5_LOC3,\
        .pin[DEV_UART_PIN_LOC4].tx_port = DEV_UART5_LOC4_TX_PORT,\
        .pin[DEV_UART_PIN_LOC4].rx_port = DEV_UART5_LOC4_RX_PORT,\
        .pin[DEV_UART_PIN_LOC4].tx_pin  = DEV_UART5_LOC4_TX_PIN,\
        .pin[DEV_UART_PIN_LOC4].rx_pin  = DEV_UART5_LOC4_RX_PIN,\
        .pin[DEV_UART_PIN_LOC4].loc     = DEV_UART5_LOC4,\
    },\
    {
        .x    = LEUART_1,\
        .type = DEV_LEUART,\
        .pin[DEV_UART_PIN_LOC0].tx_port = DEV_UART6_LOC0_TX_PORT,\
        .pin[DEV_UART_PIN_LOC0].rx_port = DEV_UART6_LOC0_RX_PORT,\
        .pin[DEV_UART_PIN_LOC0].tx_pin  = DEV_UART6_LOC0_TX_PIN,\
        .pin[DEV_UART_PIN_LOC0].rx_pin  = DEV_UART6_LOC0_RX_PIN,\
        .pin[DEV_UART_PIN_LOC0].loc     = DEV_UART6_LOC0,\
        .pin[DEV_UART_PIN_LOC1].tx_port = DEV_UART6_LOC1_TX_PORT,\
        .pin[DEV_UART_PIN_LOC1].rx_port = DEV_UART6_LOC1_RX_PORT,\
        .pin[DEV_UART_PIN_LOC1].tx_pin  = DEV_UART6_LOC1_TX_PIN,\
        .pin[DEV_UART_PIN_LOC1].rx_pin  = DEV_UART6_LOC1_RX_PIN,\
        .pin[DEV_UART_PIN_LOC1].loc     = DEV_UART6_LOC1,\
    },  
};


/*************************************************************************************************************
*                                            GLOBAL VARIABLES                                                *
*************************************************************************************************************/ 
extern CPU_INT8U const MapTbl[256];


/*************************************************************************************************************
*                                              LOCAL TABLES                                                  *
*************************************************************************************************************/
static FNCT_VOID DevUARTIntVectTbl[DEV_UART_NUM][DEV_UART_INT_NUM];
static volatile CPU_INT16U DevUARTIrqRegisterFlag[DEV_UART_NUM];


/*************************************************************************************************************
*                                            FUNCTION PROTOTYPES                                             *
*************************************************************************************************************/
void DevUARTClockEnable (DevUARTTypeDef x)
{
    switch (DevUARTTable[x].type)
    {
        case DEV_USART:     USARTClockEnable((USARTTypeDef)DevUARTTable[x].x);
                            break;
        case DEV_UART:      UARTClockEnable((UARTTypeDef)DevUARTTable[x].x);
                            break;
        case DEV_LEUART:    LEUARTClockEnable((LEUARTTypeDef)DevUARTTable[x].x);
                            break;
        default:            break;
    }
}

void DevUARTClockDisable (DevUARTTypeDef x)
{
    switch (DevUARTTable[x].type)
    {
        case DEV_USART:     USARTClockDisable((USARTTypeDef)DevUARTTable[x].x);
                            break;
        case DEV_UART:      UARTClockDisable((UARTTypeDef)DevUARTTable[x].x);
                            break;
        case DEV_LEUART:    LEUARTClockDisable((LEUARTTypeDef)DevUARTTable[x].x);
                            break;
        default:            break;
    }
}

void DevUARTIOConfig (DevUARTTypeDef x, DevUARTPinLoctionTypeDef loction, DevUARTRTxTypeDef rtx)
{
    switch (DevUARTTable[x].type)
    {
        case DEV_USART:     USARTLocationSet((USARTTypeDef)DevUARTTable[x].x, (USARTLocationTypeDef)DevUARTTable[x].pin[loction].loc);
                            break;
        case DEV_UART:      UARTLocationSet((UARTTypeDef)DevUARTTable[x].x, (UARTLocationTypeDef)DevUARTTable[x].pin[loction].loc);
                            break;
        case DEV_LEUART:    LEUARTLocationSet((LEUARTTypeDef)DevUARTTable[x].x, (LEUARTLocationTypeDef)DevUARTTable[x].pin[loction].loc);
                            break;
        default:            break;
    }
    
    switch (rtx)
    {
        case DEV_UART_TX:   DevGPIOPinConfig(DevUARTTable[x].pin[loction].tx_port, 
                                             DevUARTTable[x].pin[loction].tx_pin, 
                                             DEV_GPIO_PIN_MODE_OUT_PP, DEV_GPIO_PIN_DRIVE_STANDARD, 
                                             DEV_GPIO_PIN_FRQ_NORMAL);
                            switch (DevUARTTable[x].type)
                            {
                                case DEV_USART:     USARTCmdTxClear((USARTTypeDef)DevUARTTable[x].x);
                                                    break;
                                case DEV_UART:      UARTCmdTxClear((UARTTypeDef)DevUARTTable[x].x);
                                                    break; 
                                case DEV_LEUART:    LEUARTCmdTxClear((LEUARTTypeDef)DevUARTTable[x].x);
                                                    break;
                                default:            break;
                            }
                            break;
        case DEV_UART_RX:   DevGPIOPinConfig(DevUARTTable[x].pin[loction].rx_port, 
                                             DevUARTTable[x].pin[loction].rx_pin,
                                             DEV_GPIO_PIN_MODE_IN, DEV_GPIO_PIN_DRIVE_STANDARD, 
                                             DEV_GPIO_PIN_FRQ_NORMAL);
                            switch (DevUARTTable[x].type)
                            {
                                case DEV_USART:     USARTCmdRxClear((USARTTypeDef)DevUARTTable[x].x);
                                                    break;
                                case DEV_UART:      UARTCmdRxClear((UARTTypeDef)DevUARTTable[x].x);
                                                    break; 
                                case DEV_LEUART:    LEUARTCmdRxClear((LEUARTTypeDef)DevUARTTable[x].x);
                                                    break;
                                default:            break;
                            }
                            break;
        case DEV_UART_RTX:  DevGPIOPinConfig(DevUARTTable[x].pin[loction].tx_port, 
                                             DevUARTTable[x].pin[loction].tx_pin, 
                                             DEV_GPIO_PIN_MODE_OUT_PP, DEV_GPIO_PIN_DRIVE_STANDARD, 
                                             DEV_GPIO_PIN_FRQ_NORMAL);
                            DevGPIOPinConfig(DevUARTTable[x].pin[loction].rx_port, 
                                             DevUARTTable[x].pin[loction].rx_pin,
                                             DEV_GPIO_PIN_MODE_IN, DEV_GPIO_PIN_DRIVE_STANDARD, 
                                             DEV_GPIO_PIN_FRQ_NORMAL);
                            switch (DevUARTTable[x].type)
                            {
                                case DEV_USART:     USARTCmdTxClear((USARTTypeDef)DevUARTTable[x].x);
                                                    break;
                                case DEV_UART:      UARTCmdTxClear((UARTTypeDef)DevUARTTable[x].x);
                                                    break; 
                                case DEV_LEUART:    LEUARTCmdTxClear((LEUARTTypeDef)DevUARTTable[x].x);
                                                    break;
                                default:            break;
                            }
                            switch (DevUARTTable[x].type)
                            {
                                case DEV_USART:     USARTCmdRxClear((USARTTypeDef)DevUARTTable[x].x);
                                                    break;
                                case DEV_UART:      UARTCmdRxClear((UARTTypeDef)DevUARTTable[x].x);
                                                    break; 
                                case DEV_LEUART:    LEUARTCmdRxClear((LEUARTTypeDef)DevUARTTable[x].x);
                                                    break;
                                default:            break;
                            }
                            break;
        default:            break;
    }
}

void DevUARTInit (DevUARTTypeDef x, DevUARTStopModeTypeDef stop, DevUARTDataBitTypeDef bits, 
                  DevUARTParityModeTypeDef parity,DevUARTControlTypeDef control, 
                  CPU_INT32U baud, DevUARTRTxTypeDef rtx)
{
    switch (DevUARTTable[x].type)
    {
        case DEV_USART:     USARTAsyncConfig((USARTTypeDef)DevUARTTable[x].x, (USARTDataBitTypeDef)bits, 
                                             (USARTParityModeTypeDef)parity, (USARTStopModeTypeDef)stop);
                            USARTBaudAsyncSet((USARTTypeDef)DevUARTTable[x].x, baud, USART_OVERSAMPLING_X16);
                            USARTEnable((USARTTypeDef)DevUARTTable[x].x, (USARTCmdRTxTypeDef)rtx);
                            USARTBaudAsyncGet((USARTTypeDef)DevUARTTable[x].x);
                            break;
        case DEV_UART:      UARTAsyncConfig((UARTTypeDef)DevUARTTable[x].x, (UARTDataBitTypeDef)bits, 
                                             (UARTParityModeTypeDef)parity, (UARTStopModeTypeDef)stop);
                            UARTBaudAsyncSet((UARTTypeDef)DevUARTTable[x].x, baud, UART_OVERSAMPLING_X16);
                            UARTEnable((UARTTypeDef)DevUARTTable[x].x, (UARTCmdRTxTypeDef)rtx);
                            UARTBaudAsyncGet((UARTTypeDef)DevUARTTable[x].x);
                            break;
        case DEV_LEUART:    LEUARTConfig((LEUARTTypeDef)DevUARTTable[x].x, (LEUARTDataBitTypeDef)bits, 
                                          (LEUARTParityModeTypeDef)parity, (LEUARTStopModeTypeDef)stop);
                            LEUARTBaudSet((LEUARTTypeDef)DevUARTTable[x].x, baud);
                            LEUARTEnable((LEUARTTypeDef)DevUARTTable[x].x, (LEUARTCmdRTxTypeDef)rtx);
                            LEUARTBaudGet((LEUARTTypeDef)DevUARTTable[x].x);
                            break;
        default:            break;
    }
}

void DevUARTTxData (DevUARTTypeDef x, CPU_INT8U *pdata, CPU_INT32U len)
{
    CPU_INT32U i;
    
    switch (DevUARTTable[x].type)
    {
        case DEV_USART:     for (i = 0; i < len; i++)
                            {  
                                USARTTxByte((USARTTypeDef)DevUARTTable[x].x, pdata[i]);
                            }
                            break;
        case DEV_UART:      for (i = 0; i < len; i++)
                            {  
                                UARTTxByte((UARTTypeDef)DevUARTTable[x].x, pdata[i]);
                            }
                            break;
        case DEV_LEUART:    for (i = 0; i < len; i++)
                            {
                                LEUARTTxByte((LEUARTTypeDef)DevUARTTable[x].x, pdata[i]);
                            }
                            break;
        default:            break;
    }
}

void DevUARTRxData (DevUARTTypeDef x, CPU_INT8U *pdata, CPU_INT32U len)
{
    CPU_INT32U i;
    
    switch (DevUARTTable[x].type)
    {
        case DEV_USART:     for (i = 0; i < len; i++)
                            {  
                                 pdata[i] = USARTRxByte((USARTTypeDef)DevUARTTable[x].x);
                            }
                            break;
        case DEV_UART:      for (i = 0; i < len; i++)
                            {  
                                 pdata[i] = UARTRxByte((UARTTypeDef)DevUARTTable[x].x);
                            }
                            break;
        case DEV_LEUART:    for (i = 0; i < len; i++)
                            {
                                pdata[i] = LEUARTRxByte((LEUARTTypeDef)DevUARTTable[x].x);
                            }
                            break;
        default:            break;
    }
}

CPU_INT8U DevUARTIntRegister (DevUARTTypeDef x, DevUARTIntTypeDef irq, FNCT_VOID isr)
{ 
    CPU_INT8U n;
    
    if (!(irq & DEV_UART_IRQ_MASK))
    {
        return DEV_INT_IRQ_ERROR;
    }
    
    n = MapTbl[(CPU_INT8U)irq];
    
    if (DevUARTIrqRegisterFlag[x] & irq)
    {
        return DEV_INT_IRQ_REGISTERED;
    }
                       
    DevUARTIntVectTbl[x][n] = isr;
    DevUARTIrqRegisterFlag[x] |= irq; 
    
    return DEV_INT_IRQ_OK;
}

CPU_INT8U DevUARTIntRegisterUARTIntUnregister (DevUARTTypeDef x, DevUARTIntTypeDef irq)
{ 
    CPU_INT8U n;
    
    if (!(irq & DEV_UART_IRQ_MASK))
    {
        return DEV_INT_IRQ_ERROR;
    }
    
    n = MapTbl[(CPU_INT8U)irq];
                             
    DevUARTIntVectTbl[x][n] = IntHandlerDefault;
    DevUARTIrqRegisterFlag[x] &= ~irq;
    
    return DEV_INT_IRQ_OK;
}

void DevUARTIntInit (DevUARTTypeDef x)
{
    CPU_INT8U irq;

    for (irq = 0; irq < DEV_UART_INT_NUM; irq++)
    {
        DevUARTIntRegister(x, (DevUARTIntTypeDef)(1 << irq), IntHandlerDefault);
    }

    switch (x)
    {
        case DEV_UART0: IntVectRegister(INT_USART0_RX, DevUART0RxIntHandler);
                        IntVectRegister(INT_USART0_TX, DevUART0TxIntHandler);
                        break;
        case DEV_UART1: IntVectRegister(INT_USART1_RX, DevUART1RxIntHandler);
                        IntVectRegister(INT_USART1_TX, DevUART1TxIntHandler);
                        break;
        case DEV_UART2: IntVectRegister(INT_USART2_RX, DevUART2RxIntHandler);
                        IntVectRegister(INT_USART2_TX, DevUART2TxIntHandler);
                        break;
        case DEV_UART3: IntVectRegister(INT_UART0_RX, DevUART3RxIntHandler);
                        IntVectRegister(INT_UART0_TX, DevUART3TxIntHandler);
                        break;
        case DEV_UART4: IntVectRegister(INT_UART1_RX, DevUART4RxIntHandler);
                        IntVectRegister(INT_UART1_TX, DevUART4TxIntHandler);
                        break;
        case DEV_UART5: IntVectRegister(INT_LEUART0, DevUART5IntHandler);
                        break;
        case DEV_UART6: IntVectRegister(INT_LEUART1, DevUART6IntHandler);
                        break;
        default:        break;
    }
    
    DevUARTIrqRegisterFlag[x] = DEF_ZERO;
}

CPU_INT8U DevUARTIntEnable (DevUARTTypeDef x, DevUARTIntTypeDef irq)
{
    if (!(irq & DEV_UART_IRQ_MASK))
    {
        return DEV_INT_IRQ_ERROR;
    }
    
    switch (DevUARTTable[x].type)
    {
        case DEV_USART:     USARTIntClear((USARTTypeDef)DevUARTTable[x].x, (CPU_INT32U)irq);
                            USARTIntEnable((USARTTypeDef)DevUARTTable[x].x, (CPU_INT32U)irq);
                            break;
        case DEV_UART:      UARTIntClear((UARTTypeDef)DevUARTTable[x].x, (CPU_INT32U)irq);
                            UARTIntEnable((UARTTypeDef)DevUARTTable[x].x, (CPU_INT32U)irq);
                            break;
        case DEV_LEUART:    LEUARTIntClear((LEUARTTypeDef)DevUARTTable[x].x, (CPU_INT32U)irq);
                            LEUARTIntEnable((LEUARTTypeDef)DevUARTTable[x].x, (CPU_INT32U)irq);
                            break;
        default:            break;
    }
    
    switch (x)
    {
        case DEV_UART0: if (irq & USART_TX_IRQ_MASK)
                        {               
                            IntEnable(INT_USART0_TX);
                        }
                        if (irq & USART_RX_IRQ_MASK)
                        {               
                            IntEnable(INT_USART0_RX);
                        }
                        break;
        case DEV_UART1: if (irq & USART_TX_IRQ_MASK)
                        {               
                            IntEnable(INT_USART1_TX);
                        }
                        if (irq & USART_RX_IRQ_MASK)
                        {               
                            IntEnable(INT_USART1_RX);
                        }
                        break;
        case DEV_UART2: if (irq & USART_TX_IRQ_MASK)
                        {               
                            IntEnable(INT_USART2_TX);
                        }
                        if (irq & USART_RX_IRQ_MASK)
                        {               
                            IntEnable(INT_USART2_RX);
                        }
                        break;
        case DEV_UART3: if (irq & UART_TX_IRQ_MASK)
                        {               
                            IntEnable(INT_UART0_TX);
                        }
                        if (irq & UART_RX_IRQ_MASK)
                        {               
                            IntEnable(INT_UART0_RX);
                        }
                        break;  
        case DEV_UART4: if (irq & UART_TX_IRQ_MASK)
                        {               
                            IntEnable(INT_UART1_TX);
                        }
                        if (irq & UART_RX_IRQ_MASK)
                        {               
                            IntEnable(INT_UART1_RX);
                        }
                        break; 
        case DEV_UART5: if (irq & (LEUART_TX_IRQ_MASK | LEUART_RX_IRQ_MASK))
                        {
                            IntEnable(INT_LEUART0);
                        }
                        break;
        case DEV_UART6: if (irq & (LEUART_TX_IRQ_MASK | LEUART_RX_IRQ_MASK))
                        {
                            IntEnable(INT_LEUART1);
                        }
                        break;
        default:        break;
    }

    return DEV_INT_IRQ_OK;
}

CPU_INT8U DevUARTIntDisable (DevUARTTypeDef x, DevUARTIntTypeDef irq)
{
    if (!(irq & DEV_UART_IRQ_MASK))
    {
        return DEV_INT_IRQ_ERROR;
    }
    
    switch (DevUARTTable[x].type)
    {
        case DEV_USART:     USARTIntClear((USARTTypeDef)DevUARTTable[x].x, (CPU_INT32U)irq);
                            USARTIntDisable((USARTTypeDef)DevUARTTable[x].x, (CPU_INT32U)irq);
                            break;
        case DEV_UART:      UARTIntClear((UARTTypeDef)DevUARTTable[x].x, (CPU_INT32U)irq);
                            UARTIntDisable((UARTTypeDef)DevUARTTable[x].x, (CPU_INT32U)irq);
                            break;
        case DEV_LEUART:    LEUARTIntClear((LEUARTTypeDef)DevUARTTable[x].x, (CPU_INT32U)irq);
                            LEUARTIntDisable((LEUARTTypeDef)DevUARTTable[x].x, (CPU_INT32U)irq);
                            break;
        default:            break;
    }
    
    switch (x)
    {
        case DEV_UART0: if ((irq & USART_TX_IRQ_MASK) && (!(DevUARTIrqRegisterFlag[x] & USART_TX_IRQ_MASK)))
                        {     
                            IntDisable(INT_USART0_TX);
                        }
                        if ((irq & USART_RX_IRQ_MASK) && (!(DevUARTIrqRegisterFlag[x] & USART_RX_IRQ_MASK)))
                        {               
                            IntDisable(INT_USART0_RX);
                        }
                        break;
        case DEV_UART1: if ((irq & USART_TX_IRQ_MASK) && (!(DevUARTIrqRegisterFlag[x] & USART_TX_IRQ_MASK)))
                        {     
                            IntDisable(INT_USART1_TX);
                        }
                        if ((irq & USART_RX_IRQ_MASK) && (!(DevUARTIrqRegisterFlag[x] & USART_RX_IRQ_MASK)))
                        {               
                            IntDisable(INT_USART1_RX);
                        }
                        break;
        case DEV_UART2: if ((irq & USART_TX_IRQ_MASK) && (!(DevUARTIrqRegisterFlag[x] & USART_TX_IRQ_MASK)))
                        {     
                            IntDisable(INT_USART2_TX);
                        }
                        if ((irq & USART_RX_IRQ_MASK) && (!(DevUARTIrqRegisterFlag[x] & USART_RX_IRQ_MASK)))
                        {               
                            IntDisable(INT_USART2_RX);
                        }
                        break;
        case DEV_UART3: if ((irq & UART_TX_IRQ_MASK) && (!(DevUARTIrqRegisterFlag[x] & UART_TX_IRQ_MASK)))
                        {     
                            IntDisable(INT_UART0_TX);
                        }
                        if ((irq & UART_RX_IRQ_MASK) && (!(DevUARTIrqRegisterFlag[x] & UART_RX_IRQ_MASK)))
                        {               
                            IntDisable(INT_UART0_RX);
                        }
                        break;
        case DEV_UART4: if ((irq & UART_TX_IRQ_MASK) && (!(DevUARTIrqRegisterFlag[x] & UART_TX_IRQ_MASK)))
                        {     
                            IntDisable(INT_UART1_TX);
                        }
                        if ((irq & UART_RX_IRQ_MASK) && (!(DevUARTIrqRegisterFlag[x] & UART_RX_IRQ_MASK)))
                        {               
                            IntDisable(INT_UART1_RX);
                        }
                        break;
        case DEV_UART5: if ((irq & (LEUART_TX_IRQ_MASK | LEUART_RX_IRQ_MASK)) && (!(DevUARTIrqRegisterFlag[x] 
                            & (LEUART_TX_IRQ_MASK | LEUART_RX_IRQ_MASK))))
                        {     
                            IntDisable(INT_LEUART0);
                        }
                        break;
        case DEV_UART6: if ((irq & (LEUART_TX_IRQ_MASK | LEUART_RX_IRQ_MASK)) && (!(DevUARTIrqRegisterFlag[x] 
                            & (LEUART_TX_IRQ_MASK | LEUART_RX_IRQ_MASK))))
                        {     
                            IntDisable(INT_LEUART1);
                        }
                        break;                
        default:        break;
    }

    return DEV_INT_IRQ_OK;
}

void DevUART0RxIntHandler (void)
{
    FNCT_VOID isr;
    CPU_INT16U flag;
    CPU_INT8U n;
    
    flag = USARTIntGet((USARTTypeDef)DevUARTTable[DEV_UART0].x) & USART_RX_IRQ_MASK;
    
    flag = flag & DevUARTIrqRegisterFlag[DEV_UART0];
    
    while ((CPU_INT8U)flag != DEF_ZERO)
    {
        n = MapTbl[(CPU_INT8U)flag];
        
        isr = DevUARTIntVectTbl[DEV_UART0][n];
        isr();
                
        flag &= ~(1 << n);
    }
}

void DevUART0TxIntHandler (void)
{
    FNCT_VOID isr;
    CPU_INT16U flag;
    CPU_INT8U n;
    
    flag = USARTIntGet((USARTTypeDef)DevUARTTable[DEV_UART0].x) & USART_TX_IRQ_MASK;
    
    flag = flag & DevUARTIrqRegisterFlag[DEV_UART0];
    
    while ((CPU_INT8U)flag != DEF_ZERO)
    {
        n = MapTbl[(CPU_INT8U)flag];
        
        isr = DevUARTIntVectTbl[DEV_UART0][n];
        isr();
                
        flag &= ~(1 << n);
    }
}

void DevUART1RxIntHandler (void)
{
    FNCT_VOID isr;
    CPU_INT16U flag;
    CPU_INT8U n;
    
    flag = USARTIntGet((USARTTypeDef)DevUARTTable[DEV_UART1].x) & USART_RX_IRQ_MASK;
    
    flag = flag & DevUARTIrqRegisterFlag[DEV_UART1];
    
    while ((CPU_INT8U)flag != DEF_ZERO)
    {
        n = MapTbl[(CPU_INT8U)flag];
        
        isr = DevUARTIntVectTbl[DEV_UART1][n];
        isr();
                
        flag &= ~(1 << n);
    }
}

void DevUART1TxIntHandler (void)
{
    FNCT_VOID isr;
    CPU_INT16U flag;
    CPU_INT8U n;
    
    flag = USARTIntGet((USARTTypeDef)DevUARTTable[DEV_UART1].x) & USART_TX_IRQ_MASK;
    
    flag = flag & DevUARTIrqRegisterFlag[DEV_UART1];
    
    while ((CPU_INT8U)flag != DEF_ZERO)
    {
        n = MapTbl[(CPU_INT8U)flag];
        
        isr = DevUARTIntVectTbl[DEV_UART1][n];
        isr();
                
        flag &= ~(1 << n);
    }
}

void DevUART2RxIntHandler (void)
{
    FNCT_VOID isr;
    CPU_INT16U flag;
    CPU_INT8U n;
    
    flag = USARTIntGet((USARTTypeDef)DevUARTTable[DEV_UART2].x) & USART_RX_IRQ_MASK;
    
    flag = flag & DevUARTIrqRegisterFlag[DEV_UART2];
    
    while ((CPU_INT8U)flag != DEF_ZERO)
    {
        n = MapTbl[(CPU_INT8U)flag];
        
        isr = DevUARTIntVectTbl[DEV_UART2][n];
        isr();
                
        flag &= ~(1 << n);
    }
}

void DevUART2TxIntHandler (void)
{
    FNCT_VOID isr;
    CPU_INT16U flag;
    CPU_INT8U n;
    
    flag = USARTIntGet((USARTTypeDef)DevUARTTable[DEV_UART2].x) & USART_TX_IRQ_MASK;
    
    flag = flag & DevUARTIrqRegisterFlag[DEV_UART2];
    
    while ((CPU_INT8U)flag != DEF_ZERO)
    {
        n = MapTbl[(CPU_INT8U)flag];
        
        isr = DevUARTIntVectTbl[DEV_UART2][n];
        isr();
                
        flag &= ~(1 << n);
    }
}

void DevUART3RxIntHandler (void)
{
    FNCT_VOID isr;
    CPU_INT16U flag;
    CPU_INT8U n;
    
    flag = UARTIntGet((UARTTypeDef)DevUARTTable[DEV_UART3].x) & UART_RX_IRQ_MASK;
    
    flag = flag & DevUARTIrqRegisterFlag[DEV_UART3];
    
    while ((CPU_INT8U)flag != DEF_ZERO)
    {
        n = MapTbl[(CPU_INT8U)flag];
        
        isr = DevUARTIntVectTbl[DEV_UART3][n];
        isr();
                
        flag &= ~(1 << n);
    }
}

void DevUART3TxIntHandler (void)
{
    FNCT_VOID isr;
    CPU_INT16U flag;
    CPU_INT8U n;
    
    flag = UARTIntGet((UARTTypeDef)DevUARTTable[DEV_UART3].x) & UART_TX_IRQ_MASK;
    
    flag = flag & DevUARTIrqRegisterFlag[DEV_UART3];
    
    while ((CPU_INT8U)flag != DEF_ZERO)
    {
        n = MapTbl[(CPU_INT8U)flag];
        
        isr = DevUARTIntVectTbl[DEV_UART3][n];
        isr();
                
        flag &= ~(1 << n);
    }
}

void DevUART4RxIntHandler (void)
{
    FNCT_VOID isr;
    CPU_INT16U flag;
    CPU_INT8U n;
    
    flag = UARTIntGet((UARTTypeDef)DevUARTTable[DEV_UART4].x) & UART_RX_IRQ_MASK;
    
    flag = flag & DevUARTIrqRegisterFlag[DEV_UART4];
    
    while ((CPU_INT8U)flag != DEF_ZERO)
    {
        n = MapTbl[(CPU_INT8U)flag];
        
        isr = DevUARTIntVectTbl[DEV_UART4][n];
        isr();
                
        flag &= ~(1 << n);
    }
}

void DevUART4TxIntHandler (void)
{
    FNCT_VOID isr;
    CPU_INT16U flag;
    CPU_INT8U n;
    
    flag = UARTIntGet((UARTTypeDef)DevUARTTable[DEV_UART4].x) & UART_TX_IRQ_MASK;
    
    flag = flag & DevUARTIrqRegisterFlag[DEV_UART4];
    
    while ((CPU_INT8U)flag != DEF_ZERO)
    {
        n = MapTbl[(CPU_INT8U)flag];
        
        isr = DevUARTIntVectTbl[DEV_UART4][n];
        isr();
                
        flag &= ~(1 << n);
    }
}

void DevUART5IntHandler (void)
{
    FNCT_VOID isr;
    CPU_INT16U flag;
    CPU_INT8U n;
    
    flag = LEUARTIntGet((LEUARTTypeDef)DevUARTTable[DEV_UART5].x) & LEUART_RX_IRQ_MASK;
    
    flag = flag & DevUARTIrqRegisterFlag[DEV_UART5];
    
    while ((CPU_INT8U)flag != DEF_ZERO)
    {
        n = MapTbl[(CPU_INT8U)flag];
        
        isr = DevUARTIntVectTbl[DEV_UART5][n];
        isr();
                
        flag &= ~(1 << n);
    }
}

void DevUART6IntHandler (void)
{
    FNCT_VOID isr;
    CPU_INT16U flag;
    CPU_INT8U n;
    
    flag = LEUARTIntGet((LEUARTTypeDef)DevUARTTable[DEV_UART6].x) & LEUART_RX_IRQ_MASK;
    
    flag = flag & DevUARTIrqRegisterFlag[DEV_UART6];
    
    while ((CPU_INT8U)flag != DEF_ZERO)
    {
        n = MapTbl[(CPU_INT8U)flag];
        
        isr = DevUARTIntVectTbl[DEV_UART6][n];
        isr();
                
        flag &= ~(1 << n);
    }
}


/*************************************************************************************************************
*                                                  END FILE                                                  *
*************************************************************************************************************/