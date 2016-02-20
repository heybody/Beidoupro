/*************************************************************************************************************
*                                              INCLUDE FILES                                                 *
*************************************************************************************************************/
#include <ucos_ii.h>

#include <bsp.h>


/*************************************************************************************************************
*                                            FUNCTION PROTOTYPES                                             *
*************************************************************************************************************/
void BspHM1103CInit (void)
{
    COM0Init(115200);
    BspHM1103CIOInit();
    BspHM1103CResetOn();
    OSTimeDly(500);
    BspHM1103CResetOff();
    //BspHM1103CGPSColdOpen((FNCT_COMM)COM0TxFIFOIn);  
    //BspHM1103CBDColdOpen((FNCT_COMM)COM0TxFIFOIn);  
    //BspHM1103CGNSSColdOpen((FNCT_COMM)COM0TxFIFOIn);  
    BspHM1103CGNSS_BDWarmOpen((FNCT_COMM)COM0TxFIFOIn);

}

void BspHM1103CIOInit (void)
{
    DevGPIOPinConfig(BSP_HM1103C_RST_PORT, BSP_HM1103C_RST_PIN, DEV_GPIO_PIN_MODE_OUT_PP, 
                     DEV_GPIO_PIN_DRIVE_STANDARD, DEV_GPIO_PIN_FRQ_NORMAL);
}

void BspHM1103CResetOn (void)
{
    DevGPIOPinOutClear(BSP_HM1103C_RST_PORT, BSP_HM1103C_RST_PIN);
}

void BspHM1103CResetOff (void)
{
    DevGPIOPinOutSet(BSP_HM1103C_RST_PORT, BSP_HM1103C_RST_PIN);
}

void BspHM1103CBDColdOpen (FNCT_COMM comm)
{
    //CPU_INT8U data[] = {"$CCSIR,1,1*48\r\n"};
    CPU_INT8U data[] = {"$CCSIR,1,2*45\r\n"};   //20131009
    comm(data, sizeof (data) - 1);
}

void BspHM1103CGPSColdOpen (FNCT_COMM comm)
{
    CPU_INT8U data[] = {"$CCSIR,2,2*46\r\n"};
    
    comm(data, sizeof (data) - 1);
}

void BspHM1103CGNSSColdOpen (FNCT_COMM comm)
{
    //CPU_INT8U data[] = {"$CCSIR,3,1*4A\r\n"};
    CPU_INT8U data[] = {"$CCSIR,3,2*47\r\n"};
    comm(data, sizeof (data) - 1);
}

void BspHM1103CBDWarmOpen (FNCT_COMM comm)
{
    CPU_INT8U data[] = {"$CCSIR,1,0*49\r\n"};
    
    comm(data, sizeof (data) - 1);
}

void BspHM1103CGPSWarmOpen (FNCT_COMM comm)
{
    CPU_INT8U data[] = {"$CCSIR,2,0*4A\r\n"};
    
    comm(data, sizeof (data) - 1);
}

void BspHM1103CGNSSWarmOpen (FNCT_COMM comm)
{
    CPU_INT8U data[] = {"$CCSIR,3,0*4B\r\n"};
    
    comm(data, sizeof (data) - 1);
}

void BspHM1103CGNSS_BDWarmOpen (FNCT_COMM comm)
{
    CPU_INT8U data[] = {"$cfgsys,h11\r\n"};
    
    comm(data, sizeof (data) - 1);
}



/*************************************************************************************************************
*                                               MODULE END                                                   *
*************************************************************************************************************/
