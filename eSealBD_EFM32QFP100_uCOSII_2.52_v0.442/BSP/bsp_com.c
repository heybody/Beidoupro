/*************************************************************************************************************
*                                              INCLUDE FILES                                                 *
*************************************************************************************************************/
#include <bsp.h>
#include <fifo.h>


/*************************************************************************************************************
*                                              LOCAL TABLES                                                  *
*************************************************************************************************************/
static CPU_INT8U COM0TxFIFO[COM0_TX_FIFO_SIZE + FIFO_INFO_SIZE];
static CPU_INT8U COM0RxFIFO[COM0_RX_FIFO_SIZE + FIFO_INFO_SIZE];

static CPU_INT8U COM1TxFIFO[COM1_TX_FIFO_SIZE + FIFO_INFO_SIZE];
static CPU_INT8U COM1RxFIFO[COM1_RX_FIFO_SIZE + FIFO_INFO_SIZE];

static CPU_INT8U COM2TxFIFO[COM2_TX_FIFO_SIZE + FIFO_INFO_SIZE];
static CPU_INT8U COM2RxFIFO[COM2_RX_FIFO_SIZE + FIFO_INFO_SIZE];

static CPU_INT8U COM3TxFIFO[COM3_TX_FIFO_SIZE + FIFO_INFO_SIZE];
static CPU_INT8U COM3RxFIFO[COM3_RX_FIFO_SIZE + FIFO_INFO_SIZE];

static CPU_INT8U COM4TxFIFO[COM4_TX_FIFO_SIZE + FIFO_INFO_SIZE];
static CPU_INT8U COM4RxFIFO[COM4_RX_FIFO_SIZE + FIFO_INFO_SIZE];

static CPU_INT8U COM5TxFIFO[COM5_TX_FIFO_SIZE + FIFO_INFO_SIZE];
static CPU_INT8U COM5RxFIFO[COM5_RX_FIFO_SIZE + FIFO_INFO_SIZE];


/*************************************************************************************************************
*                                            FUNCTION PROTOTYPES                                             *
*************************************************************************************************************/
void COM0Init (CPU_INT32U baud)
{
    FIFOInit((FIFODataTypeDef *)COM0TxFIFO);
    FIFOInit((FIFODataTypeDef *)COM0RxFIFO);

    DevUARTClockEnable(COM0);
    DevUARTIOConfig(COM0, COM0_PIN_LOCTION, COM_RTX);
    DevUARTInit(COM0, COM_CONFIG_STOP, COM_CONFIG_BIT, COM_CONFIG_PARITY,
                COM_CONFIG_CONTROL, baud, COM_RTX);

    DevUARTIntInit(COM0);
    DevUARTIntRegister(COM0, DEV_UART_INT_RXDATAV, COM0RxIrqHandle);
    DevUARTIntEnable(COM0, DEV_UART_INT_RXDATAV);
}

void COM0SendData (CPU_INT8U *pdata, CPU_INT32U len)
{
    DevUARTTxData(COM0, pdata, len);
}

CPU_INT8U COM0TxFIFOIn (CPU_INT8U *pdata, CPU_INT16U len)
{
    CPU_INT16U i;

    if ((COM0_TX_FIFO_SIZE - GetFIFOCount((FIFODataTypeDef *)COM0TxFIFO, COM0_TX_FIFO_SIZE)) < len)
    {
       return COM_ERROR_TX_FIFO_FULL;
    }

    for (i = 0; i < len; i++)
    {
        FIFOIn((FIFODataTypeDef *)COM0TxFIFO, &pdata[i], COM0_TX_FIFO_SIZE);
    }

    return COM_OK;
}

void COM0TxFIFOOut (void)
{
    CPU_INT8U byte;

    while (!FIFOIsEmpty((FIFODataTypeDef *)COM0TxFIFO))
    {
        FIFOOut((FIFODataTypeDef *)COM0TxFIFO, &byte, COM0_TX_FIFO_SIZE);
        DevUARTTxData(COM0, &byte, 1);
    }
}

CPU_BOOL COM0RxFIFOIsEmpty (void)
{
    return FIFOIsEmpty((FIFODataTypeDef *)COM0RxFIFO);
}

CPU_INT8U COM0RxFIFOOut (void)
{
    CPU_INT8U byte;

    FIFOOut((FIFODataTypeDef *)COM0RxFIFO, &byte, COM0_RX_FIFO_SIZE);

    return byte;
}

void COM0RxIrqHandle (void)
{
    CPU_INT8U byte;

    DevUARTRxData(COM0, &byte, 1);

    FIFOIn((FIFODataTypeDef *)COM0RxFIFO, &byte, COM0_RX_FIFO_SIZE);
}

void COM1Init (CPU_INT32U baud)
{
    FIFOInit((FIFODataTypeDef *)COM1TxFIFO);
    FIFOInit((FIFODataTypeDef *)COM1RxFIFO);

    DevUARTClockEnable(COM1);
    DevUARTIOConfig(COM1, COM1_PIN_LOCTION, COM_RTX);
    DevUARTInit(COM1, COM_CONFIG_STOP, COM_CONFIG_BIT, COM_CONFIG_PARITY,
                COM_CONFIG_CONTROL, baud, COM_RTX);

    DevUARTIntInit(COM1);
    DevUARTIntRegister(COM1, DEV_UART_INT_RXDATAV, COM1RxIrqHandle);
    DevUARTIntEnable(COM1, DEV_UART_INT_RXDATAV);
}

void COM1SendData (CPU_INT8U *pdata, CPU_INT32U len)
{
    DevUARTTxData(COM1, pdata, len);
}

CPU_INT8U COM1TxFIFOIn (CPU_INT8U *pdata, CPU_INT16U len)
{
    CPU_INT16U i;

    if ((COM1_TX_FIFO_SIZE - GetFIFOCount((FIFODataTypeDef *)COM1TxFIFO, COM1_TX_FIFO_SIZE)) < len)
    {
       return COM_ERROR_TX_FIFO_FULL;
    }

    for (i = 0; i < len; i++)
    {
        FIFOIn((FIFODataTypeDef *)COM1TxFIFO, &pdata[i], COM1_TX_FIFO_SIZE);
    }

    return COM_OK;
}

void COM1TxFIFOOut (void)
{
    CPU_INT8U byte;

    while (!FIFOIsEmpty((FIFODataTypeDef *)COM1TxFIFO))
    {
        FIFOOut((FIFODataTypeDef *)COM1TxFIFO, &byte, COM1_TX_FIFO_SIZE);
        DevUARTTxData(COM1, &byte, 1);
    }
}

CPU_BOOL COM1RxFIFOIsEmpty (void)
{
    return FIFOIsEmpty((FIFODataTypeDef *)COM1RxFIFO);
}

CPU_INT8U COM1RxFIFOOut (void)
{
    CPU_INT8U byte;

    FIFOOut((FIFODataTypeDef *)COM1RxFIFO, &byte, COM1_RX_FIFO_SIZE);

    return byte;
}

void COM1RxIrqHandle (void)
{
    CPU_INT8U byte;

    DevUARTRxData(COM1, &byte, 1);

    FIFOIn((FIFODataTypeDef *)COM1RxFIFO, &byte, COM1_RX_FIFO_SIZE);
}

void COM1RxFIFOClear (void)
{
    CPU_INT8U byte;

    while (!COM1RxFIFOIsEmpty())
    {
        byte = COM1RxFIFOOut();
    }

    byte = byte;
}

void COM2Init (CPU_INT32U baud)
{
    FIFOInit((FIFODataTypeDef *)COM2TxFIFO);
    FIFOInit((FIFODataTypeDef *)COM2RxFIFO);

    DevUARTClockEnable(COM2);
    DevUARTIOConfig(COM2, COM2_PIN_LOCTION, COM_RTX);
    DevUARTInit(COM2, COM_CONFIG_STOP, COM_CONFIG_BIT, COM_CONFIG_PARITY,
                COM_CONFIG_CONTROL, baud, COM_RTX);

    DevUARTIntInit(COM2);
    DevUARTIntRegister(COM2, DEV_UART_INT_RXDATAV, COM2RxIrqHandle);
    DevUARTIntEnable(COM2, DEV_UART_INT_RXDATAV);
}

void COM2SendData (CPU_INT8U *pdata, CPU_INT32U len)
{
    DevUARTTxData(COM2, pdata, len);
}

CPU_INT8U COM2TxFIFOIn (CPU_INT8U *pdata, CPU_INT16U len)
{
    CPU_INT16U i;

    if ((COM2_TX_FIFO_SIZE - GetFIFOCount((FIFODataTypeDef *)COM2TxFIFO, COM2_TX_FIFO_SIZE)) < len)
    {
       return COM_ERROR_TX_FIFO_FULL;
    }

    for (i = 0; i < len; i++)
    {
        FIFOIn((FIFODataTypeDef *)COM2TxFIFO, &pdata[i], COM2_TX_FIFO_SIZE);
    }

    return COM_OK;
}

void COM2TxFIFOOut (void)
{
    CPU_INT8U byte;

    while (!FIFOIsEmpty((FIFODataTypeDef *)COM2TxFIFO))
    {
        FIFOOut((FIFODataTypeDef *)COM2TxFIFO, &byte, COM2_TX_FIFO_SIZE);
        DevUARTTxData(COM2, &byte, 1);
    }
}

CPU_BOOL COM2RxFIFOIsEmpty (void)
{
    return FIFOIsEmpty((FIFODataTypeDef *)COM2RxFIFO);
}

CPU_INT8U COM2RxFIFOOut (void)
{
    CPU_INT8U byte;

    FIFOOut((FIFODataTypeDef *)COM2RxFIFO, &byte, COM2_RX_FIFO_SIZE);

    return byte;
}

void COM2RxFIFOClear (void)
{
    CPU_INT8U byte;

    while (!COM2RxFIFOIsEmpty())
    {
        byte = COM2RxFIFOOut();
    }

    byte = byte;
}

void COM2RxIrqHandle (void)
{
    CPU_INT8U byte;

    DevUARTRxData(COM2, &byte, 1);

    FIFOIn((FIFODataTypeDef *)COM2RxFIFO, &byte, COM2_RX_FIFO_SIZE);
}

void COM3Init (CPU_INT32U baud)
{
    FIFOInit((FIFODataTypeDef *)COM3TxFIFO);
    FIFOInit((FIFODataTypeDef *)COM3RxFIFO);

    DevUARTClockEnable(COM3);
    DevUARTIOConfig(COM3, COM3_PIN_LOCTION, COM_RTX);
    DevUARTInit(COM3, COM_CONFIG_STOP, COM_CONFIG_BIT, COM_CONFIG_PARITY,
                COM_CONFIG_CONTROL, baud, COM_RTX);

    DevUARTIntInit(COM3);
    DevUARTIntRegister(COM3, DEV_UART_INT_RXDATAV, COM3RxIrqHandle);
    DevUARTIntEnable(COM3, DEV_UART_INT_RXDATAV);
}

void COM3SendData (CPU_INT8U *pdata, CPU_INT32U len)
{
    DevUARTTxData(COM3, pdata, len);
}

CPU_INT8U COM3TxFIFOIn (CPU_INT8U *pdata, CPU_INT16U len)
{
    CPU_INT16U i;

    if ((COM3_TX_FIFO_SIZE - GetFIFOCount((FIFODataTypeDef *)COM3TxFIFO, COM3_TX_FIFO_SIZE)) < len)
    {
       return COM_ERROR_TX_FIFO_FULL;
    }

    for (i = 0; i < len; i++)
    {
        FIFOIn((FIFODataTypeDef *)COM3TxFIFO, &pdata[i], COM3_TX_FIFO_SIZE);
    }

    return COM_OK;
}

void COM3TxFIFOOut (void)
{
    CPU_INT8U byte;

    while (!FIFOIsEmpty((FIFODataTypeDef *)COM3TxFIFO))
    {
        FIFOOut((FIFODataTypeDef *)COM3TxFIFO, &byte, COM3_TX_FIFO_SIZE);
        DevUARTTxData(COM3, &byte, 1);
    }
}

CPU_BOOL COM3RxFIFOIsEmpty (void)
{
    return FIFOIsEmpty((FIFODataTypeDef *)COM3RxFIFO);
}

CPU_INT8U COM3RxFIFOOut (void)
{
    CPU_INT8U byte;

    FIFOOut((FIFODataTypeDef *)COM3RxFIFO, &byte, COM3_RX_FIFO_SIZE);

    return byte;
}

void COM3RxIrqHandle (void)
{
    CPU_INT8U byte;

    DevUARTRxData(COM3, &byte, 1);

    FIFOIn((FIFODataTypeDef *)COM3RxFIFO, &byte, COM3_RX_FIFO_SIZE);
}

void COM3RxFIFOClear (void)
{
    CPU_INT8U byte;

    while (!COM3RxFIFOIsEmpty())
    {
        byte = COM3RxFIFOOut();
    }

    byte = byte;
}

void COM4Init (CPU_INT32U baud)
{
    FIFOInit((FIFODataTypeDef *)COM4TxFIFO);
    FIFOInit((FIFODataTypeDef *)COM4RxFIFO);

    DevUARTClockEnable(COM4);
    DevUARTIOConfig(COM4, COM4_PIN_LOCTION, COM_RTX);
    DevUARTInit(COM4, COM_CONFIG_STOP, COM_CONFIG_BIT, COM_CONFIG_PARITY,
                COM_CONFIG_CONTROL, baud, COM_RTX);

    DevUARTIntInit(COM4);
    DevUARTIntRegister(COM4, DEV_UART_INT_RXDATAV, COM4RxIrqHandle);
    DevUARTIntEnable(COM4, DEV_UART_INT_RXDATAV);
}

void COM4SendData (CPU_INT8U *pdata, CPU_INT32U len)
{
    DevUARTTxData(COM4, pdata, len);
}

CPU_INT8U COM4TxFIFOIn (CPU_INT8U *pdata, CPU_INT16U len)
{
    CPU_INT16U i;

    if ((COM4_TX_FIFO_SIZE - GetFIFOCount((FIFODataTypeDef *)COM4TxFIFO, COM4_TX_FIFO_SIZE)) < len)
    {
       return COM_ERROR_TX_FIFO_FULL;
    }

    for (i = 0; i < len; i++)
    {
        FIFOIn((FIFODataTypeDef *)COM4TxFIFO, &pdata[i], COM4_TX_FIFO_SIZE);
    }

    return COM_OK;
}

void COM4TxFIFOOut (void)
{
    CPU_INT8U byte;

    while (!FIFOIsEmpty((FIFODataTypeDef *)COM4TxFIFO))
    {
        FIFOOut((FIFODataTypeDef *)COM4TxFIFO, &byte, COM4_TX_FIFO_SIZE);
        DevUARTTxData(COM4, &byte, 1);
    }
}

CPU_BOOL COM4RxFIFOIsEmpty (void)
{
    return FIFOIsEmpty((FIFODataTypeDef *)COM4RxFIFO);
}

CPU_INT8U COM4RxFIFOOut (void)
{
    CPU_INT8U byte;

    FIFOOut((FIFODataTypeDef *)COM4RxFIFO, &byte, COM4_RX_FIFO_SIZE);

    return byte;
}

void COM4RxIrqHandle (void)
{
    CPU_INT8U byte;

    DevUARTRxData(COM4, &byte, 1);

    FIFOIn((FIFODataTypeDef *)COM4RxFIFO, &byte, COM4_RX_FIFO_SIZE);
}

void COM5Init (CPU_INT32U baud)
{
    FIFOInit((FIFODataTypeDef *)COM5TxFIFO);
    FIFOInit((FIFODataTypeDef *)COM5RxFIFO);

    DevUARTClockEnable(COM5);
    DevUARTIOConfig(COM5, COM5_PIN_LOCTION, COM_RTX);
    DevUARTInit(COM5, COM_CONFIG_STOP, COM_CONFIG_BIT, COM_CONFIG_PARITY,
                COM_CONFIG_CONTROL, baud, COM_RTX);

    DevUARTIntInit(COM5);
    DevUARTIntRegister(COM5, DEV_UART_INT_RXDATAV, COM5RxIrqHandle);
    DevUARTIntEnable(COM5, DEV_UART_INT_RXDATAV);
}


/**
 * [COM5SendData  数据发送]
 * @param pdata [要发送的数据首地址]
 * @param len   [长度]
 */
void COM5SendData (CPU_INT8U *pdata, CPU_INT32U len)
{
    DevUARTTxData(COM5, pdata, len);
}


/**
 * [COM5TxFIFOIn  将pdata中len个数据放入TxFIFO中]
 * @param  pdata [数据]
 * @param  len   [长度]
 * @return       [是否成功]
 */
CPU_INT8U COM5TxFIFOIn (CPU_INT8U *pdata, CPU_INT16U len)
{
    CPU_INT16U i;

    if ((COM5_TX_FIFO_SIZE - GetFIFOCount((FIFODataTypeDef *)COM5TxFIFO, COM5_TX_FIFO_SIZE)) < len)
    {
       return COM_ERROR_TX_FIFO_FULL;
    }

    for (i = 0; i < len; i++)
    {
        FIFOIn((FIFODataTypeDef *)COM5TxFIFO, &pdata[i], COM5_TX_FIFO_SIZE);
    }

    return COM_OK;
}

/**
 * [COM5TxFIFOOut 从TxFIFO中取出一个数据并通过UART发送  ]
 */
void COM5TxFIFOOut (void)
{
    CPU_INT8U byte;

    while (!FIFOIsEmpty((FIFODataTypeDef *)COM5TxFIFO))
    {
        FIFOOut((FIFODataTypeDef *)COM5TxFIFO, &byte, COM5_TX_FIFO_SIZE);
        DevUARTTxData(COM5, &byte, 1);
    }
}

/**
 * [COM5RxFIFOIsEmpty  description]
 * @return  [判断RXfifo是否为空]
 */
CPU_BOOL COM5RxFIFOIsEmpty (void)
{
    return FIFOIsEmpty((FIFODataTypeDef *)COM5RxFIFO);
}

/**
 * [COM5RxFIFOOut  description]
 * @return  [从邋RXfifo中取出数据，并返回]
 */
CPU_INT8U COM5RxFIFOOut (void)
{
    CPU_INT8U byte;

    FIFOOut((FIFODataTypeDef *)COM5RxFIFO, &byte, COM5_RX_FIFO_SIZE);

    return byte;
}

/*************************************
 * [COM5RxIrqHandle  中断中接受数据字节，放入RxFIFO中]
 *
 ***************************************/
void COM5RxIrqHandle (void)
{
    CPU_INT8U byte;

    DevUARTRxData(COM5, &byte, 1);

    FIFOIn((FIFODataTypeDef *)COM5RxFIFO, &byte, COM5_RX_FIFO_SIZE);
}

/*************************************************************************************************************
*                                               MODULE END                                                   *
*************************************************************************************************************/
