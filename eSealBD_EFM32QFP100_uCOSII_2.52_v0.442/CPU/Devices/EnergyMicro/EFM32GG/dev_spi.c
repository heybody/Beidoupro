/*************************************************************************************************************
*                                              INCLUDE FILES                                                 *
*************************************************************************************************************/
#include <dev.h>


/*************************************************************************************************************
*                                                CONSTANTS                                                   *
*************************************************************************************************************/
const DevSPITableTypeDef  DevSPITable[DEV_SPI_NUM] = 
{
    {
        .x    = USART_0,\
        .pin[DEV_SPI_PIN_LOC0].mosi_port = DEV_SPI0_LOC0_MOSI_PORT,\
        .pin[DEV_SPI_PIN_LOC0].miso_port = DEV_SPI0_LOC0_MISO_PORT,\
        .pin[DEV_SPI_PIN_LOC0].clk_port  = DEV_SPI0_LOC0_CLK_PORT,\
        .pin[DEV_SPI_PIN_LOC0].cs_port   = DEV_SPI0_LOC0_CS_PORT,\
        .pin[DEV_SPI_PIN_LOC0].mosi_pin  = DEV_SPI0_LOC0_MOSI_PIN,\
        .pin[DEV_SPI_PIN_LOC0].miso_pin  = DEV_SPI0_LOC0_MISO_PIN,\
        .pin[DEV_SPI_PIN_LOC0].clk_pin   = DEV_SPI0_LOC0_CLK_PIN,\
        .pin[DEV_SPI_PIN_LOC0].cs_pin    = DEV_SPI0_LOC0_CS_PIN,\
        .pin[DEV_SPI_PIN_LOC0].loc       = DEV_SPI0_LOC0,\
        .pin[DEV_SPI_PIN_LOC1].mosi_port = DEV_SPI0_LOC1_MOSI_PORT,\
        .pin[DEV_SPI_PIN_LOC1].miso_port = DEV_SPI0_LOC1_MISO_PORT,\
        .pin[DEV_SPI_PIN_LOC1].clk_port  = DEV_SPI0_LOC1_CLK_PORT,\
        .pin[DEV_SPI_PIN_LOC1].cs_port   = DEV_SPI0_LOC1_CS_PORT,\
        .pin[DEV_SPI_PIN_LOC1].mosi_pin  = DEV_SPI0_LOC1_MOSI_PIN,\
        .pin[DEV_SPI_PIN_LOC1].miso_pin  = DEV_SPI0_LOC1_MISO_PIN,\
        .pin[DEV_SPI_PIN_LOC1].clk_pin   = DEV_SPI0_LOC1_CLK_PIN,\
        .pin[DEV_SPI_PIN_LOC1].cs_pin    = DEV_SPI0_LOC1_CS_PIN,\
        .pin[DEV_SPI_PIN_LOC1].loc       = DEV_SPI0_LOC1,\
        .pin[DEV_SPI_PIN_LOC2].mosi_port = DEV_SPI0_LOC2_MOSI_PORT,\
        .pin[DEV_SPI_PIN_LOC2].miso_port = DEV_SPI0_LOC2_MISO_PORT,\
        .pin[DEV_SPI_PIN_LOC2].clk_port  = DEV_SPI0_LOC2_CLK_PORT,\
        .pin[DEV_SPI_PIN_LOC2].cs_port   = DEV_SPI0_LOC2_CS_PORT,\
        .pin[DEV_SPI_PIN_LOC2].mosi_pin  = DEV_SPI0_LOC2_MOSI_PIN,\
        .pin[DEV_SPI_PIN_LOC2].miso_pin  = DEV_SPI0_LOC2_MISO_PIN,\
        .pin[DEV_SPI_PIN_LOC2].clk_pin   = DEV_SPI0_LOC2_CLK_PIN,\
        .pin[DEV_SPI_PIN_LOC2].cs_pin    = DEV_SPI0_LOC2_CS_PIN,\
        .pin[DEV_SPI_PIN_LOC2].loc       = DEV_SPI0_LOC2,\
        .pin[DEV_SPI_PIN_LOC4].mosi_port = DEV_SPI0_LOC4_MOSI_PORT,\
        .pin[DEV_SPI_PIN_LOC4].miso_port = DEV_SPI0_LOC4_MISO_PORT,\
        .pin[DEV_SPI_PIN_LOC4].clk_port  = DEV_SPI0_LOC4_CLK_PORT,\
        .pin[DEV_SPI_PIN_LOC4].cs_port   = DEV_SPI0_LOC4_CS_PORT,\
        .pin[DEV_SPI_PIN_LOC4].mosi_pin  = DEV_SPI0_LOC4_MOSI_PIN,\
        .pin[DEV_SPI_PIN_LOC4].miso_pin  = DEV_SPI0_LOC4_MISO_PIN,\
        .pin[DEV_SPI_PIN_LOC4].clk_pin   = DEV_SPI0_LOC4_CLK_PIN,\
        .pin[DEV_SPI_PIN_LOC4].cs_pin    = DEV_SPI0_LOC4_CS_PIN,\
        .pin[DEV_SPI_PIN_LOC4].loc       = DEV_SPI0_LOC4,\
        .pin[DEV_SPI_PIN_LOC5].mosi_port = DEV_SPI0_LOC5_MOSI_PORT,\
        .pin[DEV_SPI_PIN_LOC5].miso_port = DEV_SPI0_LOC5_MISO_PORT,\
        .pin[DEV_SPI_PIN_LOC5].clk_port  = DEV_SPI0_LOC5_CLK_PORT,\
        .pin[DEV_SPI_PIN_LOC5].cs_port   = DEV_SPI0_LOC5_CS_PORT,\
        .pin[DEV_SPI_PIN_LOC5].mosi_pin  = DEV_SPI0_LOC5_MOSI_PIN,\
        .pin[DEV_SPI_PIN_LOC5].miso_pin  = DEV_SPI0_LOC5_MISO_PIN,\
        .pin[DEV_SPI_PIN_LOC5].clk_pin   = DEV_SPI0_LOC5_CLK_PIN,\
        .pin[DEV_SPI_PIN_LOC5].cs_pin    = DEV_SPI0_LOC5_CS_PIN,\
        .pin[DEV_SPI_PIN_LOC5].loc       = DEV_SPI0_LOC5,\
    },\
    {
        .x    = USART_1,\
        .pin[DEV_SPI_PIN_LOC0].mosi_port = DEV_SPI1_LOC0_MOSI_PORT,\
        .pin[DEV_SPI_PIN_LOC0].miso_port = DEV_SPI1_LOC0_MISO_PORT,\
        .pin[DEV_SPI_PIN_LOC0].clk_port  = DEV_SPI1_LOC0_CLK_PORT,\
        .pin[DEV_SPI_PIN_LOC0].cs_port   = DEV_SPI1_LOC0_CS_PORT,\
        .pin[DEV_SPI_PIN_LOC0].mosi_pin  = DEV_SPI1_LOC0_MOSI_PIN,\
        .pin[DEV_SPI_PIN_LOC0].miso_pin  = DEV_SPI1_LOC0_MISO_PIN,\
        .pin[DEV_SPI_PIN_LOC0].clk_pin   = DEV_SPI1_LOC0_CLK_PIN,\
        .pin[DEV_SPI_PIN_LOC0].cs_pin    = DEV_SPI1_LOC0_CS_PIN,\
        .pin[DEV_SPI_PIN_LOC0].loc       = DEV_SPI1_LOC0,\
        .pin[DEV_SPI_PIN_LOC1].mosi_port = DEV_SPI1_LOC1_MOSI_PORT,\
        .pin[DEV_SPI_PIN_LOC1].miso_port = DEV_SPI1_LOC1_MISO_PORT,\
        .pin[DEV_SPI_PIN_LOC1].clk_port  = DEV_SPI1_LOC1_CLK_PORT,\
        .pin[DEV_SPI_PIN_LOC1].cs_port   = DEV_SPI1_LOC1_CS_PORT,\
        .pin[DEV_SPI_PIN_LOC1].mosi_pin  = DEV_SPI1_LOC1_MOSI_PIN,\
        .pin[DEV_SPI_PIN_LOC1].miso_pin  = DEV_SPI1_LOC1_MISO_PIN,\
        .pin[DEV_SPI_PIN_LOC1].clk_pin   = DEV_SPI1_LOC1_CLK_PIN,\
        .pin[DEV_SPI_PIN_LOC1].cs_pin    = DEV_SPI1_LOC1_CS_PIN,\
        .pin[DEV_SPI_PIN_LOC1].loc       = DEV_SPI1_LOC1,\
        .pin[DEV_SPI_PIN_LOC2].mosi_port = DEV_SPI1_LOC2_MOSI_PORT,\
        .pin[DEV_SPI_PIN_LOC2].miso_port = DEV_SPI1_LOC2_MISO_PORT,\
        .pin[DEV_SPI_PIN_LOC2].clk_port  = DEV_SPI1_LOC2_CLK_PORT,\
        .pin[DEV_SPI_PIN_LOC2].cs_port   = DEV_SPI1_LOC2_CS_PORT,\
        .pin[DEV_SPI_PIN_LOC2].mosi_pin  = DEV_SPI1_LOC2_MOSI_PIN,\
        .pin[DEV_SPI_PIN_LOC2].miso_pin  = DEV_SPI1_LOC2_MISO_PIN,\
        .pin[DEV_SPI_PIN_LOC2].clk_pin   = DEV_SPI1_LOC2_CLK_PIN,\
        .pin[DEV_SPI_PIN_LOC2].cs_pin    = DEV_SPI1_LOC2_CS_PIN,\
        .pin[DEV_SPI_PIN_LOC2].loc       = DEV_SPI1_LOC2,\
    },\
    {
        .x    = USART_2,\
        .pin[DEV_SPI_PIN_LOC0].mosi_port = DEV_SPI2_LOC0_MOSI_PORT,\
        .pin[DEV_SPI_PIN_LOC0].miso_port = DEV_SPI2_LOC0_MISO_PORT,\
        .pin[DEV_SPI_PIN_LOC0].clk_port  = DEV_SPI2_LOC0_CLK_PORT,\
        .pin[DEV_SPI_PIN_LOC0].cs_port   = DEV_SPI2_LOC0_CS_PORT,\
        .pin[DEV_SPI_PIN_LOC0].mosi_pin  = DEV_SPI2_LOC0_MOSI_PIN,\
        .pin[DEV_SPI_PIN_LOC0].miso_pin  = DEV_SPI2_LOC0_MISO_PIN,\
        .pin[DEV_SPI_PIN_LOC0].clk_pin   = DEV_SPI2_LOC0_CLK_PIN,\
        .pin[DEV_SPI_PIN_LOC0].cs_pin    = DEV_SPI2_LOC0_CS_PIN,\
        .pin[DEV_SPI_PIN_LOC0].loc       = DEV_SPI2_LOC0,\
        .pin[DEV_SPI_PIN_LOC1].mosi_port = DEV_SPI2_LOC1_MOSI_PORT,\
        .pin[DEV_SPI_PIN_LOC1].miso_port = DEV_SPI2_LOC1_MISO_PORT,\
        .pin[DEV_SPI_PIN_LOC1].clk_port  = DEV_SPI2_LOC1_CLK_PORT,\
        .pin[DEV_SPI_PIN_LOC1].cs_port   = DEV_SPI2_LOC1_CS_PORT,\
        .pin[DEV_SPI_PIN_LOC1].mosi_pin  = DEV_SPI2_LOC1_MOSI_PIN,\
        .pin[DEV_SPI_PIN_LOC1].miso_pin  = DEV_SPI2_LOC1_MISO_PIN,\
        .pin[DEV_SPI_PIN_LOC1].clk_pin   = DEV_SPI2_LOC1_CLK_PIN,\
        .pin[DEV_SPI_PIN_LOC1].cs_pin    = DEV_SPI2_LOC1_CS_PIN,\
        .pin[DEV_SPI_PIN_LOC1].loc       = DEV_SPI2_LOC1,\
    },\
};


/*************************************************************************************************************
*                                            FUNCTION PROTOTYPES                                             *
*************************************************************************************************************/
void DevSPIClockEnable (DevSPITypeDef x)
{
    USARTClockEnable((USARTTypeDef)DevSPITable[x].x);
}

void DevSPIClockDisable (DevSPITypeDef x)
{
    USARTClockDisable((USARTTypeDef)DevSPITable[x].x);
}

void DevSPIIOConfig (DevSPITypeDef x, DevSPIPinLoctionTypeDef loction, CPU_BOOL cs)
{
    USARTLocationSet((USARTTypeDef)DevSPITable[x].x, (USARTLocationTypeDef)DevSPITable[x].pin[loction].loc);

    DevGPIOPinConfig(DevSPITable[x].pin[loction].mosi_port, DevSPITable[x].pin[loction].mosi_pin, 
                     DEV_GPIO_PIN_MODE_OUT_PP, DEV_GPIO_PIN_DRIVE_STANDARD, DEV_GPIO_PIN_FRQ_NORMAL);
    DevGPIOPinConfig(DevSPITable[x].pin[loction].miso_port, DevSPITable[x].pin[loction].miso_pin,
                     DEV_GPIO_PIN_MODE_IN, DEV_GPIO_PIN_DRIVE_STANDARD, DEV_GPIO_PIN_FRQ_NORMAL);
    DevGPIOPinConfig(DevSPITable[x].pin[loction].clk_port, DevSPITable[x].pin[loction].clk_pin, 
                     DEV_GPIO_PIN_MODE_OUT_PP, DEV_GPIO_PIN_DRIVE_STANDARD, DEV_GPIO_PIN_FRQ_NORMAL);
    if (cs == DEF_ON)
    {
        DevGPIOPinConfig(DevSPITable[x].pin[loction].cs_port, DevSPITable[x].pin[loction].cs_pin, 
                         DEV_GPIO_PIN_MODE_OUT_PP, DEV_GPIO_PIN_DRIVE_STANDARD, DEV_GPIO_PIN_FRQ_NORMAL);
    }
    
    USARTCmdTxClear((USARTTypeDef)DevSPITable[x].x);
    USARTCmdRxClear((USARTTypeDef)DevSPITable[x].x);
}

void DevSPIInit (DevSPITypeDef x, DevSPIDataBitTypeDef bits, DevSPIClockModeTypeDef clock, 
                 DevSPIMSBFTypeDef msb,DevSPIModeTypeDef mode, CPU_INT32U baud, CPU_BOOL cs)
{
    
    USARTSyncConfig((USARTTypeDef)DevSPITable[x].x, (USARTDataBitTypeDef)bits, 
                    (USARTClockModeTypeDef)clock, (USARTMSBFTypeDef)msb, (USARTSyncModeTypeDef)mode);
    USARTBaudSyncSet((USARTTypeDef)DevSPITable[x].x, baud);
    USARTBaudSyncGet((USARTTypeDef)DevSPITable[x].x);
    USARTEnable((USARTTypeDef)DevSPITable[x].x, USART_RTX);
    USARTClkPinEnable((USARTTypeDef)DevSPITable[x].x);
    
    if (cs == DEF_ON)
    {
        USARTCsPinEnable((USARTTypeDef)DevSPITable[x].x);
    }
    else
    {
        USARTCsPinDisable((USARTTypeDef)DevSPITable[x].x);
    }
}

void DevSPITxData (DevSPITypeDef x, CPU_INT8U *pdata, CPU_INT32U len)
{
    CPU_INT32U i;
    
    for (i = 0; i < len; i++)
    {  
        USARTTxByte((USARTTypeDef)DevSPITable[x].x, pdata[i]);
        USARTRxByte((USARTTypeDef)DevSPITable[x].x);
    }
}

void DevSPIRxData (DevSPITypeDef x, CPU_INT8U *pdata, CPU_INT32U len)
{
    CPU_INT32U i;
    
    for (i = 0; i < len; i++)
    {  
        USARTTxByte((USARTTypeDef)DevSPITable[x].x, 0x00);
        pdata[i] = USARTRxByte((USARTTypeDef)DevSPITable[x].x);
    }
}


/*************************************************************************************************************
*                                                  END FILE                                                  *
*************************************************************************************************************/
