/*************************************************************************************************************
*                                              INCLUDE FILES                                                 *
*************************************************************************************************************/
#include <efm32.h>


/*************************************************************************************************************
*                                            FUNCTION PROTOTYPES                                             *
*************************************************************************************************************/
void LEUARTClockEnable (LEUARTTypeDef x)
{
    switch (x)
    {                  
        case LEUART_0:   CMULEBPeripheralClockEnable(LEUART0Clock);
                        break;
        case LEUART_1:   CMULEBPeripheralClockEnable(LEUART1Clock);
                        break;
        default:        break;     
    }
}

void LEUARTClockDisable (LEUARTTypeDef x)
{
    switch (x)
    {
        case LEUART_0:   CMULEBPeripheralClockDisable(LEUART0Clock);
                        break;
        case LEUART_1:   CMULEBPeripheralClockDisable(LEUART1Clock);
                        break;
        default:        break;     
    }
}


void LEUARTBaudSet (LEUARTTypeDef x, CPU_INT32U baud)
{
    CPU_INT32U clock;
    CPU_INT32U div;

    switch (x)
    {
        case LEUART_0:    clock = CMULFBPeripheralClockGet(LEUART0Clock); 
                          break;
        case LEUART_1:    clock = CMULFBPeripheralClockGet(LEUART1Clock);
                          break;
        default:          break;
    }
    
    div  = 32 * clock;
    div /= baud;
    div -= 32;
    
    LEUARTClockDivSet(x, div);
}

CPU_INT32U LEUARTBaudGet (LEUARTTypeDef x)
{
    CPU_INT32U clock;
    CPU_INT32U baud;

    switch (x)
    {
        case LEUART_0:    clock = CMULFBPeripheralClockGet(LEUART0Clock); 
                          break;
        case LEUART_1:    clock = CMULFBPeripheralClockGet(LEUART1Clock);
                          break;
        default:          break;
    }

    baud = 0;
    baud = 32 * clock / (LEUARTClockDivGet(x) + 32);
    
    return baud;
}

void LEUARTConfig (LEUARTTypeDef x, LEUARTDataBitTypeDef bits, 
                   LEUARTParityModeTypeDef parity, LEUARTStopModeTypeDef stop)
{
    LEUARTDataBitSet(x, bits);
    LEUARTParityModeSet(x, parity);
    LEUARTStopModeSet(x, stop);
 }

void LEUARTEnable (LEUARTTypeDef x, LEUARTCmdRTxTypeDef rtx)
{
    LEUARTCmd(x, rtx);
    
    if (rtx & LEUART_CMD_RXEN)
    {
        LEUARTRxPinEnable(x);
    }
    
    if (rtx & LEUART_CMD_TXEN)
    {
        LEUARTTxPinEnable(x);
    }
}

void LEUARTDisable (LEUARTTypeDef x, LEUARTCmdRTxTypeDef rtx)
{
    LEUARTCmd(x, rtx << 1);
    
    if (rtx & LEUART_CMD_RXEN)
    {
        LEUARTRxPinDisable(x);
    }
    
    if (rtx & LEUART_CMD_TXEN)
    {
        LEUARTTxPinDisable(x);
    }
}

CPU_INT8U LEUARTRxByte (LEUARTTypeDef x)
{
    while (!LEUARTStatusFlagGet(x, LEUART_STATUS_FLAG_RXDATAV));
    
    return LEUARTRxDataGet(x);
}

void LEUARTTxByte (LEUARTTypeDef x, CPU_INT8U byte)
{
    while (!LEUARTStatusFlagGet(x, LEUART_STATUS_FLAG_TXBL)); 
    
    LEUARTTxDataSet(x, byte);
    
    while (!LEUARTStatusFlagGet(x, LEUART_STATUS_FLAG_TXC));
}


/*************************************************************************************************************
*                                                  END FILE                                                  *
*************************************************************************************************************/
