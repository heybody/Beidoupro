/*************************************************************************************************************
*                                              INCLUDE FILES                                                 *
*************************************************************************************************************/
#include <efm32.h>


/*************************************************************************************************************
*                                            FUNCTION PROTOTYPES                                             *
*************************************************************************************************************/
void USARTClockEnable (USARTTypeDef x)
{
    switch (x)
    {
        case USART_0:   CMUHFPeripheralClockEnable(USART0Clock);
                        break;
        case USART_1:   CMUHFPeripheralClockEnable(USART1Clock);
                        break;
        case USART_2:   CMUHFPeripheralClockEnable(USART2Clock);
                        break;               
        default:        break;     
    }
}

void USARTClockDisable (USARTTypeDef x)
{
    switch (x)
    {
        case USART_0:   CMUHFPeripheralClockDisable(USART0Clock);
                        break;
        case USART_1:   CMUHFPeripheralClockDisable(USART1Clock);
                        break;
        case USART_2:   CMUHFPeripheralClockDisable(USART2Clock);
                        break;
        default:        break;     
    }
}

void USARTBaudAsyncSet (USARTTypeDef x, CPU_INT32U baud, USARTOversamplingTypeDef oversample)
{
    CPU_INT32U clock;
    CPU_INT32U ovs;
    CPU_INT32U div;

    clock = CMUHFPeripheralClockGet();  /* HFPERCLK used to clock all USART/UART peripheral modules */

    /* Map oversampling */
    switch (oversample)
    {
        case USART_OVERSAMPLING_X16:    ovs = 16;
                                        break;
        case USART_OVERSAMPLING_X8:     ovs = 8;
                                        break;
        case USART_OVERSAMPLING_X6:     ovs = 6;
                                        break;
        case USART_OVERSAMPLING_X4:     ovs = 4;
                                        break;
        default:                        return;
    }
    
    div  = 4 * clock + (ovs * baud) / 2;
    div /= (ovs * baud);
    div -= 4;
    
    USARTOversamplingSet(x, oversample);
    USARTClockDivSet(x, div);
}

CPU_INT32U USARTBaudAsyncGet (USARTTypeDef x)
{
    CPU_INT32U clock;
    CPU_INT32U ovs;
    CPU_INT32U baud;

    clock = CMUHFPeripheralClockGet();  /* HFPERCLK used to clock all USART/UART peripheral modules */

    baud = 0;
    ovs = 16;
    /* Map oversampling */
    switch (USARTOversamplingGet(x))
    {
        case USART_OVERSAMPLING_X16:    ovs = 16;
                                        break;
        case USART_OVERSAMPLING_X8:     ovs = 8;
                                        break;
        case USART_OVERSAMPLING_X6:     ovs = 6;
                                        break;
        case USART_OVERSAMPLING_X4:     ovs = 4;
                                        break;
        default:                        break;
    }
    
    baud = 4 * clock / (ovs * (USARTClockDivGet(x) + 4));
  
    return baud;
}

void USARTBaudSyncSet (USARTTypeDef x, CPU_INT32U baud)
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
    
    USARTClockDivSet(x, div);
}

CPU_INT32U USARTBaudSyncGet (USARTTypeDef x)
{
    CPU_INT32U clock;
    CPU_INT32U baud;

    clock = CMUHFPeripheralClockGet();  /* HFPERCLK used to clock all USART/UART peripheral modules */
    
    baud = 0;
    baud = 2 * clock / (4 + (USARTClockDivGet(x)));
    
    return baud;
}

void USARTAsyncConfig (USARTTypeDef x, USARTDataBitTypeDef bits, 
                       USARTParityModeTypeDef parity, USARTStopModeTypeDef stop)
{
    USARTModeSet(x, USART_MODE_ASYNC);
    USARTDataBitSet(x, bits);
    USARTParityModeSet(x, parity);
    USARTStopModeSet(x, stop);
 }

void USARTSyncConfig (USARTTypeDef x, USARTDataBitTypeDef bits, 
                      USARTClockModeTypeDef clock, USARTMSBFTypeDef msb, USARTSyncModeTypeDef mode)
{
    USARTModeSet(x, USART_MODE_SYNC);
    USARTClockPolaritySet(x,(USARTClockPolarityTypeDef)(clock & USART_CTRL_CLKPOL_MASK));
    USARTSampleClockEdgeSet(x, (USARTSampleClockEdgeTypeDef)(clock & USART_CTRL_CLKPHA_MASK));
    USARTMSBFSet(x, msb);
    USARTDataBitSet(x, bits);
    USARTParityModeSet(x, USART_PARITY_NONE);
    USARTStopModeSet(x, USART_STOP_BIT_ONE);
    
    if (mode == USART_SYNC_MODE_MASTER)
    {
        USARTCmdMasterEnable(x);
    }
    else
    {
        USARTCmdMasterDisable(x);
    }
}

void USARTEnable (USARTTypeDef x,USARTCmdRTxTypeDef rtx)
{
    USARTCmd(x, rtx);
    
    if (rtx & USART_CMD_RXEN)
    {
        USARTRxPinEnable(x);
    }
    
    if (rtx & USART_CMD_TXEN)
    {
        USARTTxPinEnable(x);
    }
}

void USARTDisable (USARTTypeDef x,USARTCmdRTxTypeDef rtx)
{
    USARTCmd(x, rtx << 1);
    
    if (rtx & USART_CMD_RXEN)
    {
        USARTRxPinDisable(x);
    }
    
    if (rtx & USART_CMD_TXEN)
    {
        USARTTxPinDisable(x);
    }
}

CPU_INT8U USARTRxByte (USARTTypeDef x)
{
    while (!USARTStatusFlagGet(x, USART_STATUS_FLAG_RXDATAV));

    return USARTRxDataGet(x);
}

CPU_INT16U USARTRxHalfWord (USARTTypeDef x)
{
    while (!USARTStatusFlagGet(x, USART_STATUS_FLAG_RXFULL));

    return USARTRxDoubleDataGet(x);
}

void USARTTxByte (USARTTypeDef x, CPU_INT8U byte)
{
    while (!USARTStatusFlagGet(x, USART_STATUS_FLAG_TXBL));  /* Check that transmit buffer is empty */
    
    USARTTxDataSet(x, byte);
    
    while (!USARTStatusFlagGet(x, USART_STATUS_FLAG_TXC));
}

void USARTTxHalfWord (USARTTypeDef x, CPU_INT16U data)
{
    while (!USARTStatusFlagGet(x, USART_STATUS_FLAG_TXBL));  /* Check that transmit buffer is empty */

    USARTTxDoubleData1Set(x, data);
}


/*************************************************************************************************************
*                                                  END FILE                                                  *
*************************************************************************************************************/
