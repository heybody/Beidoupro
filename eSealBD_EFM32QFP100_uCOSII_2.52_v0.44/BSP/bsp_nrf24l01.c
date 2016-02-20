/***************************************************************************************************
*                                          INCLUDE FILES                                           *
***************************************************************************************************/
#include <bsp.h>
#include <queue.h>
#include <string.h>


/***************************************************************************************************
*                                          LOCAL TABLES                                            *
***************************************************************************************************/
static CPU_INT8U IDCode[AW] = {0xE1, 0x30, 0x22};
static sRFDataTypeDef RFData;


/***************************************************************************************************
*                                        FUNCTION PROTOTYPES                                       *
***************************************************************************************************/
void nRF24L01IOInit (void)
{
   // GPIOModeSet(NRF24L01_CSN_PORT, NRF24L01_CSN_PIN, GPIOModeOutput);
  //  GPIOModeSet(NRF24L01_CE_PORT, NRF24L01_CE_PIN, GPIOModeOutput);
    
    DevGPIOPinConfig(NRF24L01_CSN_PORT, NRF24L01_CSN_PIN, DEV_GPIO_PIN_MODE_OUT_PP, 
                     DEV_GPIO_PIN_DRIVE_STANDARD, DEV_GPIO_PIN_FRQ_NORMAL);
    DevGPIOPinConfig(NRF24L01_CE_PORT, NRF24L01_CE_PIN, DEV_GPIO_PIN_MODE_OUT_PP, 
                     DEV_GPIO_PIN_DRIVE_STANDARD, DEV_GPIO_PIN_FRQ_NORMAL);
    
    DevGPIOPinConfig(NRF24L01_IRQ_PORT, NRF24L01_IRQ_PIN, DEV_GPIO_PIN_MODE_IN_P, 
                     DEV_GPIO_PIN_DRIVE_STANDARD, DEV_GPIO_PIN_FRQ_NORMAL);
}

void nRF24L01RxIntEnable (FNCT_VOID isr)
{
    //GPIOIntConfig(NRF24L01_IRQ_PORT, NRF24L01_IRQ_PIN, GPIO_FALLING_EDGE);
    DevGPIOIntConfig(NRF24L01_IRQ_PORT, NRF24L01_IRQ_PIN, DEV_GPIO_FALLING_EDGE);
    
    //GPIORenEnable(NRF24L01_IRQ_PORT, NRF24L01_IRQ_PIN);
    
    
    //GPIOIntClear(NRF24L01_IRQ_PORT, NRF24L01_IRQ_PIN);
    DevGPIOIntClear(NRF24L01_IRQ_PORT, NRF24L01_IRQ_PIN);
    
    //GPIOIntRegister(NRF24L01_IRQ_PORT, NRF24L01_IRQ_PIN, isr);
    DevGPIOIntRegister(NRF24L01_IRQ_PORT, NRF24L01_IRQ_PIN, isr);
    
    //GPIOIntEnable(NRF24L01_IRQ_PORT, NRF24L01_IRQ_PIN);
    DevGPIOIntEnable(NRF24L01_IRQ_PORT, NRF24L01_IRQ_PIN);
}

void nRF24L01CSNH (void)
{
    DevGPIOPinOutSet(NRF24L01_CSN_PORT, NRF24L01_CSN_PIN);
}

void nRF24L01CSNL (void)
{
    DevGPIOPinOutClear(NRF24L01_CSN_PORT, NRF24L01_CSN_PIN);
}

void nRF24L01CEH (void)
{
    DevGPIOPinOutSet(NRF24L01_CE_PORT, NRF24L01_CE_PIN);
}

void nRF24L01CEL (void)
{
    DevGPIOPinOutClear(NRF24L01_CE_PORT, NRF24L01_CE_PIN);
}

void nRF24L01Init (void)
{
    CPU_INT8U data[AW] = {0x00, 0x00, 0x00};
    //SPIInit();
        
    DevSPIClockEnable(DEV_SPI0);
    DevSPIInit(DEV_SPI0, DEV_SPI_BIT_8, DEV_SPI_CLOCK_MODE0, 
               DEV_SPI_MSBF_MSB, DEV_SPI_MASTER, 6000000, DEF_OFF);
    DevSPIIOConfig(DEV_SPI0, DEV_SPI_PIN_LOC0, DEF_OFF);
    
    nRF24L01IOInit();
    
    nRF24L01RxIntEnable(nRF24L01RxIrqHandler);
    
    nRF24L01CSNL();
    
    data[0] = CH;
        
    nRF24L01WrReg(EN_AA, DISAA);
    nRF24L01WrReg(SETUP_RETR, ARD_250US);
    nRF24L01WrReg(RF_SETUP, RF_DR_2Mbps | RF_PWR_0dBm);
    nRF24L01WrReg(EN_RXADDR, ERX_P0);
    nRF24L01WrReg(SETUP_AW, AW_3_BYTE);
    nRF24L01WrReg(RF_CH, data[0]);
        
    nRF24L01WrIDCode(RX_ADDR_P0, IDCode, AW);
    nRF24L01RdIDCode(RX_ADDR_P0, data, AW);
        
    nRF24L01WrReg(RX_PW_P0, PW);
        
    nRF24L01CEH();
    
    nRF24L01SetSleep();
}

void nRF24L01WrReg (CPU_INT8U addr, CPU_INT8U data)
{   
    CPU_INT8U cmd;
    
    cmd = W_REGISTER + addr;
    
    nRF24L01CSNH();
    nRF24L01CSNL();     
    
    //SPISendData(&cmd, 1);
    DevSPITxData(DEV_SPI0, &cmd, 1);
    //SPISendData(&data, 1);
    DevSPITxData(DEV_SPI0, &data, 1);
    
    nRF24L01CSNH();
}

void nRF24L01RdReg (CPU_INT8U addr, CPU_INT8U *data)
{
    CPU_INT8U cmd;
    
    cmd = R_REGISTER + addr;
    
    nRF24L01CSNH();
    nRF24L01CSNL();     
    
    //SPISendData(&cmd, 1);
    DevSPITxData(DEV_SPI0, &cmd, 1);
    //SPIReceiveData(data, 1);  
    DevSPIRxData(DEV_SPI0, data, 1); 
    
    nRF24L01CSNH();
}

void nRF24L01WrTxFIFO (CPU_INT8U *pdata, CPU_INT16U len)
{
    CPU_INT8U cmd;
    
    cmd = W_TX_PAYLOAD;
    
    nRF24L01CSNH();
    nRF24L01CSNL();     
    
    //SPISendData(&cmd, 1);
    DevSPITxData(DEV_SPI0, &cmd, 1);
    //SPISendData(pdata, len);      
     DevSPITxData(DEV_SPI0, pdata, len);
     
    nRF24L01CSNH();
}

void nRF24L01RdRxFIFO (CPU_INT8U *pdata, CPU_INT16U len)
{
    CPU_INT8U cmd;
    
    cmd = R_RX_PAYLOAD;
    
    nRF24L01CSNH();
    nRF24L01CSNL();   
    
    //SPISendData(&cmd, 1);
    DevSPITxData(DEV_SPI0, &cmd, 1);
    //SPIReceiveData(pdata,len);  
    DevSPIRxData(DEV_SPI0, pdata,len);  
    
    nRF24L01CSNH();
}

void nRF24L01WrIDCode (CPU_INT8U pipe, CPU_INT8U *paddr, CPU_INT16U len)
{
    CPU_INT8U cmd;
    
    cmd = W_REGISTER + pipe;
    
    nRF24L01CSNH();
    nRF24L01CSNL();    
    
    //SPISendData(&cmd, 1);
    DevSPITxData(DEV_SPI0, &cmd, 1);
    //SPISendData(paddr, len);   
    DevSPITxData(DEV_SPI0, paddr, len);
    
    nRF24L01CSNH(); 
}

void nRF24L01RdIDCode (CPU_INT8U pipe, CPU_INT8U *paddr, CPU_INT16U len)
{
    CPU_INT8U cmd;
    
    cmd = R_REGISTER + pipe;
    
    nRF24L01CSNH();
    nRF24L01CSNL();   
    
    //SPISendData(&cmd, 1);
    DevSPITxData(DEV_SPI0, &cmd, 1);
    //SPIReceiveData(paddr, len);    
    DevSPIRxData(DEV_SPI0, paddr, len); 
    
    nRF24L01CSNH();  
}

void nRF24L01ClrRxFIFO (void)
{
    CPU_INT8U cmd;
    
    cmd = FLUSH_RX;
    
    nRF24L01CSNH();
    nRF24L01CSNL(); 
    
    //SPISendData(&cmd, 1);  
    DevSPITxData(DEV_SPI0, &cmd, 1);
 
    nRF24L01CSNH();
}

void nRF24L01SetSleep (void)
{
    nRF24L01CEL();
    nRF24L01WrReg(CONFIG, MASK_TX_DS | EN_CRC | CRCO | PRIM_RX);
    nRF24L01CEH(); 
}

void nRF24L01SetRx (void)
{
    QueueInit(&RFData.queue);
    RFData.stack.sp = DEF_ZERO;
    RFData.flag = DEF_OFF;
    
    nRF24L01CEL();
    nRF24L01ClrRxFIFO();
    nRF24L01WrReg(CONFIG, MASK_TX_DS | EN_CRC | CRCO | PWR_UP | PRIM_RX);
    nRF24L01WrReg(STATUS, 0x40);
    nRF24L01CEH(); 
}

void nRF24L01DataRx (CPU_INT8U *pdata, CPU_INT16U *len)
{
    sRFDataType *item;
    void *temp;
    
    RFData.flag = DEF_ON;
    
    if (QueueIsEmpty(&RFData.queue) == 0)
    {   
        QueueOut(&RFData.queue, &temp, sizeof(sRFDataType), RF_DATA_QUEUE_SIZE);
        item = (sRFDataType *)temp;
        
        memcpy(pdata, item->data, PW);
        *len = PW;
        
        RFData.flag = DEF_OFF;
        
        return;
    }
    
    RFData.flag = DEF_OFF;
    
    if (RFData.stack.sp > 0)
    {
        RFData.stack.sp--;
        
        memcpy(pdata, RFData.stack.item[RFData.stack.sp].data, PW);
        *len = PW;
        
        return;
    }
    
    *len = 0; 
}

void nRF24L01RxIrqHandler (void)
{
    sRFDataType *rf_temp;
    void *temp;
    CPU_INT8U status;
    
    do
    {
        if (RFData.flag == DEF_OFF)
        {
            QueueIn(&RFData.queue, &temp, sizeof(sRFDataType), RF_DATA_QUEUE_SIZE);
            rf_temp = (sRFDataType *)temp;
        
            nRF24L01RdRxFIFO(rf_temp->data, PW);
        }
        else
        {
            nRF24L01RdRxFIFO(RFData.stack.item[RFData.stack.sp].data, PW);
                
            if (RFData.stack.sp < (RF_DATA_STACK_SIZE - 1))
            {
                RFData.stack.sp++;
            }
        }
        
        nRF24L01RdReg(FIFO_STATUS, &status);
        
    }while ((status & 0x01) == 0x00);
        
    nRF24L01ClrRxFIFO();
    nRF24L01WrReg(STATUS, 0x40);   
}






















