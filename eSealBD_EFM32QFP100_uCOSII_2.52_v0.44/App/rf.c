/*************************************************************************************************************
*                                              INCLUDE FILES                                                 *
*************************************************************************************************************/
#include <ucos_ii.h>

#include <app.h>


/*************************************************************************************************************
*                                                CONSTANTS                                                   *
*************************************************************************************************************/
CPU_INT8U const RFChTbl[RF_CH_NUM] = {5, 10, 15, 20, 25, 30, 35, 40, 45, 50, 55, 60, 65, 70, 75, 80};

const RFDeveiceTypeDef RFDeveice[RF_NUM] = 
{
    {
        .irq_port = RF_0_IRQ_PORT,\
        .irq_pin  = RF_0_IRQ_PIN,\
        .a7153    = BSP_A7153_0
    }
};


/*************************************************************************************************************
*                                            GLOBAL VARIABLES                                                *
*************************************************************************************************************/
OS_EXT OS_EVENT *MsgRF0TxComplete;
OS_EXT OS_EVENT *MsgRF0RxComplete;


/*************************************************************************************************************
*                                              LOCAL TABLES                                                  *
*************************************************************************************************************/
static RFDataTypeDef RFData[RF_NUM];


/*************************************************************************************************************
*                                            FUNCTION PROTOTYPES                                             *
*************************************************************************************************************/
CPU_BOOL RFInit (RFTypeDef n, CPU_INT8U ch)
{
    RFBuffInit(n);
    
    return BspA7153Init(RFDeveice[n].a7153, RF_SFD, RFChTbl[ch]);
}

void RFBuffInit (RFTypeDef n)
{
    QueueInit(&RFData[n].data_queue);
    RFData[n].data_stack.sp = DEF_ZERO;
    RFData[n].data_queue_flag = DEF_OFF;
    RFData[n].tx_rx_flag = RF_STATUS_STANDBY;
    RFData[n].tx_count = DEF_ZERO;
    RFData[n].rx_timeout = DEF_ZERO;
}

CPU_BOOL RFBuffDataOut (RFTypeDef n, CPU_INT8U *pdata, CPU_INT32U *plen)
{
    sRFDataType *item;
    void *temp;
    CPU_BOOL ret;
    
    ret = DEF_FALSE;

    RFData[n].data_queue_flag = DEF_ON;
    
    if (QueueIsEmpty(&RFData[n].data_queue) == DEF_FALSE) 
    {
        QueueOut (&RFData[n].data_queue, &temp, sizeof(sRFDataType), RF_DATA_QUEUE_SIZE);
        item = (sRFDataType *)temp;
        *plen = item->len;       
        memcpy(pdata, item->data, item->len);
        
        ret = DEF_TRUE;
    }
    RFData[n].data_queue_flag = DEF_OFF;
    
    if (ret == DEF_TRUE)
    {
        return ret;
    }
                                         
    if (RFData[n].data_stack.sp > 0)
    {
        RFData[n].data_stack.sp--;
        *plen = RFData[n].data_stack.item[RFData[n].data_stack.sp].len;          
        memcpy(pdata, RFData[n].data_stack.item[RFData[n].data_stack.sp].data, *plen);
        
        ret = DEF_TRUE;
    }
    
    return ret;
}

void RFTRxIntRegister (RFTypeDef n, FNCT_VOID isr)
{  
    DevGPIOIntRegister(RFDeveice[n].irq_port, RFDeveice[n].irq_pin, isr);
    DevGPIOIntConfig(RFDeveice[n].irq_port, RFDeveice[n].irq_pin, DEV_GPIO_FALLING_EDGE);
}

void RFTRxIntEnable (RFTypeDef n)
{  
    DevGPIOIntEnable(RFDeveice[n].irq_port, RFDeveice[n].irq_pin);
}

void RFTRxIntDisable (RFTypeDef n)
{  
    DevGPIOIntDisable(RFDeveice[n].irq_port, RFDeveice[n].irq_pin);
}

void RFTRxIntClear (RFTypeDef n)
{  
    DevGPIOIntClear(RFDeveice[n].irq_port, RFDeveice[n].irq_pin);
}

void RFSetStandby (RFTypeDef n)
{
    RFTRxIntDisable(n);
    BspA7153StrobeCMD(RFDeveice[n].a7153, A7153_CMD_STBY);
    RFTRxIntClear(n);
    RFTRxIntEnable(n);
}

void RFTxInit (RFTypeDef n, CPU_INT8U ch, CPU_INT8U *pdata, CPU_INT32U len)
{
    RFTRxIntDisable(n);
    BspA7153StrobeCMD(RFDeveice[n].a7153, A7153_CMD_STBY); 
    BspA7153SetCH(RFDeveice[n].a7153, RFChTbl[ch]);  

    BspA7153SetPayloadLen(RFDeveice[n].a7153, len);
    BspA7153WrFIFO(RFDeveice[n].a7153, pdata, len);
    BspA7153StrobeCMD(RFDeveice[n].a7153, A7153_CMD_PLL);
    
    RFTRxIntClear(n);
    RFTRxIntEnable(n);
}

void RFTx (RFTypeDef n, CPU_INT32U cnt)
{
    CPU_INT8U err;
    
    if (cnt > 0)
    {
        RFData[n].tx_rx_flag = RF_STATUS_TX;
        RFData[n].tx_count = cnt;
        
        RFTRxIntDisable(n);
        BspA7153StrobeCMD(RFDeveice[n].a7153, A7153_CMD_TX);
        RFTRxIntClear(n);
        RFTRxIntEnable(n);
                            
        switch (n)
        {
            case RF_A7153_0:    OSMboxPend(MsgRF0TxComplete, RF_TX_MAX_DELAY * cnt, &err);
                                break;
            default:            break;
        } 
    }
}

CPU_INT8U RFSetRx (RFTypeDef n, CPU_INT8U ch, CPU_INT32U timeout)
{ 
    CPU_INT8U err;
    CPU_INT8U flag;
    CPU_INT8U status;
    
    RFData[n].tx_rx_flag = RF_STATUS_RX;
    RFData[n].rx_timeout = timeout;
    switch (n)
    {
        case RF_A7153_0:    BspA7153SetCH(RFDeveice[n].a7153, RFChTbl[ch]);
                            BspA7153StrobeCMD(RFDeveice[n].a7153, A7153_CMD_RX);
                            if (RFData[n].rx_timeout > 0)
                            {
                                
                                //OSTimeDly(1);
                                status = BspA7153RdReg8Bit(RFDeveice[n].a7153, A7153_REG_ADDR_MODECTRL);
                                OSMboxPend(MsgRF0RxComplete, RFData[n].rx_timeout, &err);
                            
                                if(err == OS_NO_ERR )
                                {
                                    flag = RF_RX_OK;
                                }
                                else
                                {
                                    flag = RF_RX_TIMEOUT;
                                }
                            }
                            else
                            {
                                flag = RF_RX_CONTINUE;
                            }
                            break;
        default:            flag = RF_RX_TIMEOUT;
                            break;
    }
    
    status = status;
    
    return flag;
}

CPU_INT8U RFRxData (RFTypeDef n, CPU_INT8U *pdata, CPU_INT32U *len)
{
    CPU_INT8U status;
    CPU_INT8U flag;
    
    switch (n)
    {
        case RF_A7153_0:    status = BspA7153RdReg8Bit(RFDeveice[n].a7153, A7153_REG_ADDR_MODE);
                            if (!(status & DEF_BIT5))
                            {
                                *len = BspA7153RdReg8Bit(RFDeveice[n].a7153, A7153_REG_ADDR_PHR) & 0x7F;
                            
                                BspA7153RdFIFO(RFDeveice[n].a7153, pdata, *len);
                                        
                                flag = RF_RXD_OK;
                            }
                            else
                            {
                                *len = BspA7153RdReg8Bit(RFDeveice[n].a7153, A7153_REG_ADDR_PHR) & 0x7F;
                            
                                BspA7153RdFIFO(RFDeveice[n].a7153, pdata, *len);
                                        
                                flag = RF_RXD_CRC_ERROR;
                            };
                            RFTRxIntDisable(n);
                            BspA7153StrobeCMD(RFDeveice[n].a7153, A7153_CMD_STBY);
                            RFTRxIntClear(n);
                            RFTRxIntEnable(n);
                            break;
        default:            flag = RF_DEVICE_ERROR;
                            RFTRxIntDisable(n);
                            BspA7153StrobeCMD(RFDeveice[n].a7153, A7153_CMD_STBY);
                            RFTRxIntClear(n);
                            RFTRxIntEnable(n);
                            break;
    }
    
    return flag;
}


CPU_BOOL RFPowerSet (RFTypeDef n, CPU_INT8S power)
{     
    if ((power + RF_POWER_MIN) > RF_POWER_LEVEL)
    {
        return DEF_FALSE;
    }
    
    return BspA7153PowerSet((BspA7153TypeDef)n, (CPU_INT8U)(power + RF_POWER_MIN));
}

CPU_INT8S RFPowerGet (RFTypeDef n)
{
    CPU_INT8S power;
    
    power = BspA7153PowerGet((BspA7153TypeDef)n);
    
    return (CPU_INT8S)(power - RF_POWER_MIN);
}

CPU_BOOL RFChipCheck (RFTypeDef n)
{
    CPU_INT8U ch;
    CPU_INT8U temp;
    CPU_BOOL  flag;
    
    ch = BspA7153GetCH(RFDeveice[n].a7153);
    
    temp = 50;
    
    BspA7153SetCH(RFDeveice[n].a7153, temp);
    
    if (temp == BspA7153GetCH(RFDeveice[n].a7153))
    {
        flag = DEF_TRUE;
    }
    else
    {
        flag = DEF_FALSE;
    }
    
    BspA7153SetCH(RFDeveice[n].a7153, ch);
    
    return flag;
}

CPU_INT8U RFStatusGet (RFTypeDef n)
{
    CPU_INT8U status;
    
    status = RFData[n].tx_rx_flag;
    
    return status;
}

void RFSleep (RFTypeDef n)
{
    RFTRxIntDisable(n);
    BspA7153StrobeCMD(RFDeveice[n].a7153, A7153_CMD_SLEEP);
    RFTRxIntClear(n);
    RFTRxIntEnable(n);
    QueueInit(&RFData[n].data_queue);
    RFData[n].data_stack.sp = DEF_ZERO;
    RFData[n].data_queue_flag = DEF_OFF;
    RFData[n].tx_rx_flag = RF_STATUS_SLEEP;
    RFData[n].tx_count = DEF_ZERO;
    RFData[n].rx_timeout = DEF_ZERO;
}

void RF0TRxComplete (void)
{
    sRFDataType *item;
    void *temp;
    CPU_INT8U len;
    CPU_INT8U status;
    CPU_BOOL crc_flag;
    
    if (RFData[RF_A7153_0].tx_rx_flag == RF_STATUS_TX)
    {
        RFData[RF_A7153_0].tx_count--;
        if (RFData[RF_A7153_0].tx_count > 0)
        {
            BspA7153StrobeCMD(RFDeveice[RF_A7153_0].a7153, A7153_CMD_TX);
        }
        else
        {
            OSMboxPost(MsgRF0TxComplete, (void *)&RFData[RF_A7153_0].tx_rx_flag);
        }
    }
    else if (RFData[RF_A7153_0].tx_rx_flag == RF_STATUS_RX)
    {
        if (RFData[RF_A7153_0].rx_timeout > 0)
        {
            OSMboxPost(MsgRF0RxComplete, (void *)&RFData[RF_A7153_0].tx_rx_flag);
        }
        else
        {
            status = BspA7153RdReg8Bit(RFDeveice[RF_A7153_0].a7153, A7153_REG_ADDR_MODE); 
            
            if (!(status & DEF_BIT5))
            {
                crc_flag = DEF_ON;
            }
            else
            {
                crc_flag = DEF_OFF;
            }
            
            len = BspA7153RdReg8Bit(RFDeveice[RF_A7153_0].a7153, A7153_REG_ADDR_PHR) &0x7F;
            
            if (RFData[RF_A7153_0].data_queue_flag == DEF_OFF)
            {
                QueueIn(&RFData[RF_A7153_0].data_queue, &temp, sizeof(sRFDataType), RF_DATA_QUEUE_SIZE);
                item = (sRFDataType *)temp;
                
                item->len = len;
             
                item->crc_flag = crc_flag;
                    
                BspA7153RdFIFO(RFDeveice[RF_A7153_0].a7153, item->data, len);
            }
            else
            {
                RFData[RF_A7153_0].data_stack.item[RFData[RF_A7153_0].data_stack.sp].len = len;
                RFData[RF_A7153_0].data_stack.item[RFData[RF_A7153_0].data_stack.sp].crc_flag = crc_flag;
                BspA7153RdFIFO(RFDeveice[RF_A7153_0].a7153, 
                               RFData[RF_A7153_0].data_stack.item[RFData[RF_A7153_0].data_stack.sp].data, len);
                
                if (RFData[RF_A7153_0].data_stack.sp < (RF_DATA_STACK_SIZE - 1))
                {
                    RFData[RF_A7153_0].data_stack.sp++;
                }
            } 
        
            BspA7153StrobeCMD(RFDeveice[RF_A7153_0].a7153, A7153_CMD_RX);
        }
    }
    
#if APP_OS_EN > 0
    
#if OS_CRITICAL_METHOD == 3u
    OS_CPU_SR  cpu_sr;
#endif

    OS_ENTER_CRITICAL();                         /* Tell uC/OS-II that we are starting an ISR               */
    OSIntNesting++;
    OS_EXIT_CRITICAL();

    OSIntExit();                                 /* Tell uC/OS-II that we are leaving the ISR               */
#else
    
#endif  
}


/*************************************************************************************************************
*                                               MODULE END                                                   *
*************************************************************************************************************/