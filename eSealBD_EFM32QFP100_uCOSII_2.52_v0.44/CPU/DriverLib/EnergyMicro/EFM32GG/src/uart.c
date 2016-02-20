/*************************************************************************************************************
*                                              INCLUDE FILES                                                 *
*************************************************************************************************************/
#include <efm32.h>


/*************************************************************************************************************
*                                            FUNCTION PROTOTYPES                                             *
*************************************************************************************************************/
void UARTClockEnable (UARTTypeDef x)
{
    switch (x)
    {
        case UART_0:   CMUHFPeripheralClockEnable(UART0Clock);
                        break;
        case UART_1:   CMUHFPeripheralClockEnable(UART1Clock);
                        break;         
        default:        break;     
    }
}

void UARTClockDisable (UARTTypeDef x)
{
    switch (x)
    {
        case UART_0:   CMUHFPeripheralClockDisable(UART0Clock);
                        break;
        case UART_1:   CMUHFPeripheralClockDisable(UART1Clock);
                        break;
        default:        break;     
    }
}

void UARTBaudAsyncSet (UARTTypeDef x, CPU_INT32U baud, UARTOversamplingTypeDef oversample)
{
    CPU_INT32U clock;
    CPU_INT32U ovs;
    CPU_INT32U div;

    clock = CMUHFPeripheralClockGet();  /* HFPERCLK used to clock all USART/UART peripheral modules */

    /* Map oversampling */
    switch (oversample)
    {
        case UART_OVERSAMPLING_X16:    ovs = 16;
                                        break;
        case UART_OVERSAMPLING_X8:     ovs = 8;
                                        break;
        case UART_OVERSAMPLING_X6:     ovs = 6;
                                        break;
        case UART_OVERSAMPLING_X4:     ovs = 4;
                                        break;
        default:                        return;
    }
    
    div  = 4 * clock + (ovs * baud) / 2;
    div /= (ovs * baud);
    div -= 4;
    
    UARTOversamplingSet(x, oversample);
    UARTClockDivSet(x, div);
}

CPU_INT32U UARTBaudAsyncGet (UARTTypeDef x)
{
    CPU_INT32U clock;
    CPU_INT32U ovs;
    CPU_INT32U baud;

    clock = CMUHFPeripheralClockGet();  /* HFPERCLK used to clock all USART/UART peripheral modules */

    baud = 0;
    ovs = 16;
    /* Map oversampling */
    switch (UARTOversamplingGet(x))
    {
        case UART_OVERSAMPLING_X16:    ovs = 16;
                                        break;
        case UART_OVERSAMPLING_X8:     ovs = 8;
                                        break;
        case UART_OVERSAMPLING_X6:     ovs = 6;
                                        break;
        case UART_OVERSAMPLING_X4:     ovs = 4;
                                        break;
        default:                        break;
    }
    
    baud = 4 * clock / (ovs * (UARTClockDivGet(x) + 4));
  
    return baud;
}

void UARTBaudSyncSet (UARTTypeDef x, CPU_INT32U baud)
{
    CPU_INT32U clock;
    CPU_INT32U div;

    clock = CMUHFPeripheralClockGet();  /* HFPERCLK used to clock all USART/UART peripheral modules */
    
    div  = 2 * clock;
    div += baud - 1;
    div /= baud;
    div -= 4;
    div *= 64;
      
    /* Make sure we don't use fractional bits by rounding CLKDIV up 
    (and thus reducing baudrate, not increasing baudrate above specified value). */
    div += 0xc0;
    div &= 0xffffff00;
    
    div = (div >> 6);
    
    UARTClockDivSet(x, div);
}

CPU_INT32U UARTBaudSyncGet (UARTTypeDef x)
{
    CPU_INT32U clock;
    CPU_INT32U baud;

    clock = CMUHFPeripheralClockGet();  /* HFPERCLK used to clock all USART/UART peripheral modules */
    
    baud = 0;
    baud = 2 * clock / (4 + (UARTClockDivGet(x)));
    
    return baud;
}

void UARTAsyncConfig (UARTTypeDef x, UARTDataBitTypeDef bits, 
                       UARTParityModeTypeDef parity, UARTStopModeTypeDef stop)
{
    UARTModeSet(x, UART_MODE_ASYNC);
    UARTDataBitSet(x, bits);
    UARTParityModeSet(x, parity);
    UARTStopModeSet(x, stop);
 }

void UARTSyncConfig (UARTTypeDef x, UARTDataBitTypeDef bits, 
                      UARTClockModeTypeDef clock, UARTMSBFTypeDef msb, UARTSyncModeTypeDef mode)
{
    UARTModeSet(x, UART_MODE_SYNC);
    UARTClockPolaritySet(x,(UARTClockPolarityTypeDef)(clock & USART_CTRL_CLKPOL_MASK));
    UARTSampleClockEdgeSet(x, (UARTSampleClockEdgeTypeDef)(clock & USART_CTRL_CLKPHA_MASK));
    UARTMSBFSet(x, msb);
    UARTDataBitSet(x, bits);
    UARTParityModeSet(x, UART_PARITY_NONE);
    UARTStopModeSet(x, UART_STOP_BIT_ONE);
    
    if (mode == UART_SYNC_MODE_MASTER)
    {
        UARTCmdMasterEnable(x);
    }
    else
    {
        UARTCmdMasterDisable(x);
    }
}

void UARTEnable (UARTTypeDef x,UARTCmdRTxTypeDef rtx)
{
    UARTCmd(x, rtx);
    
    if (rtx & UART_RX)
    {
        UARTRxPinEnable(x);
    }
    
    if (rtx & UART_TX)
    {
        UARTTxPinEnable(x);
    }
}

void UARTDisable (UARTTypeDef x,UARTCmdRTxTypeDef rtx)
{
    UARTCmd(x, rtx << 1);
    
    if (rtx & UART_RX)
    {
        UARTRxPinDisable(x);
    }
    
    if (rtx & UART_TX)
    {
        UARTTxPinDisable(x);
    }
}

CPU_INT8U UARTRxByte (UARTTypeDef x)
{
    while (!UARTStatusFlagGet(x, UART_STATUS_FLAG_RXDATAV));

    return UARTRxDataGet(x);
}

CPU_INT16U UARTRxHalfWord (UARTTypeDef x)
{
    while (!UARTStatusFlagGet(x, UART_STATUS_FLAG_RXFULL));

    return UARTRxDoubleDataGet(x);
}

void UARTTxByte (UARTTypeDef x, CPU_INT8U byte)
{
    while (!UARTStatusFlagGet(x, UART_STATUS_FLAG_TXBL));  /* Check that transmit buffer is empty */
    
    UARTTxDataSet(x, byte);
    
    while (!UARTStatusFlagGet(x, UART_STATUS_FLAG_TXC));
}

void UARTTxHalfWord (UARTTypeDef x, CPU_INT16U data)
{
    while (!UARTStatusFlagGet(x, UART_STATUS_FLAG_TXBL));  /* Check that transmit buffer is empty */

    UARTTxDoubleData1Set(x, data);
}


/*************************************************************************************************************
*                                                  END FILE                                                  *
*************************************************************************************************************/
