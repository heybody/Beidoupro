/*************************************************************************************************************
*                                              INCLUDE FILES                                                 *
*************************************************************************************************************/
#include <ucos_ii.h>

#include <util.h>

#include <bsp.h>

//#include <esealbd.h>
extern const CPU_INT32U EsealBDID;

/*************************************************************************************************************
*                                            FUNCTION PROTOTYPES                                             *
*************************************************************************************************************/
void BspBleInit (void)
{
    COM2Init(115200);
    
    BspBleIOInit();
    
    BspBleResetOn();
    BspBleForcePinH();
    BspBleWUPinH();
    OSTimeDly(500);
    
    BspBleSetName(EsealBDID, (FNCT_COMM)COM2TxFIFOIn);
    
    
   BspBleSetDevice((FNCT_COMM)COM2TxFIFOIn); 
   
   // BspBleSetHost((FNCT_COMM)COM2TxFIFOIn); 
    OSTimeDly(100);
   // BspBleForcePinH();
    BspBleResetOff();
    BspBleWUPinL();
}
void BspBleRecovery(void)
{
    BspBleForcePinH();
    BspBleWUPinH();
    OSTimeDly(500);
    
    BspBleForcePinL();
    OSTimeDly(10);
    BspBleForcePinH();
    
    OSTimeDly(500);
    
    BspBleWUPinL();
    OSTimeDly(10);
    BspBleWUPinH();
    
    OSTimeDly(100);
    BspBleWUPinL();
}

void BspBleIOInit (void)
{
    DevGPIOPinConfig(BSP_BLE_RST_PORT, BSP_BLE_RST_PIN, DEV_GPIO_PIN_MODE_OUT_PP, 
                     DEV_GPIO_PIN_DRIVE_STANDARD, DEV_GPIO_PIN_FRQ_NORMAL);
    DevGPIOPinConfig(BSP_BLE_WU_PORT, BSP_BLE_WU_PIN, DEV_GPIO_PIN_MODE_OUT_PP, 
                     DEV_GPIO_PIN_DRIVE_STANDARD, DEV_GPIO_PIN_FRQ_NORMAL);
    DevGPIOPinConfig(BSP_BLE_FORCE_PORT, BSP_BLE_FORCE_PIN, DEV_GPIO_PIN_MODE_OUT_PP, 
                     DEV_GPIO_PIN_DRIVE_STANDARD, DEV_GPIO_PIN_FRQ_NORMAL);
    
    DevGPIOPinConfig(BSP_BLE_STATUS_PORT, BSP_BLE_STATUS_PIN, DEV_GPIO_PIN_MODE_IN, 
                     DEV_GPIO_PIN_DRIVE_STANDARD, DEV_GPIO_PIN_FRQ_NORMAL);    
}

void BspBleResetOn (void)
{
    DevGPIOPinOutClear(BSP_BLE_RST_PORT, BSP_BLE_RST_PIN);
}

void BspBleResetOff (void)
{
    DevGPIOPinOutSet(BSP_BLE_RST_PORT, BSP_BLE_RST_PIN);
}

void BspBleWUPinL (void)
{
    DevGPIOPinOutClear(BSP_BLE_WU_PORT, BSP_BLE_WU_PIN);
}

void BspBleWUPinH (void)
{
    DevGPIOPinOutSet(BSP_BLE_WU_PORT, BSP_BLE_WU_PIN);
}
void BspBleForcePinL (void)
{
    DevGPIOPinOutClear(BSP_BLE_FORCE_PORT, BSP_BLE_FORCE_PIN);
}

void BspBleForcePinH (void)
{
    DevGPIOPinOutSet(BSP_BLE_FORCE_PORT, BSP_BLE_FORCE_PIN);
}

CPU_BOOL BspBleStatusGet (void)
{
    CPU_BOOL flag;
    
    flag =  DevGPIOPinInGet(BSP_BLE_STATUS_PORT, BSP_BLE_STATUS_PIN);
    
    return flag;
}

void BspBleSetMode (void)
{        
    BspBleWUPinL();
    BspBleResetOff();
    OSTimeDly(500);

    BspBleWUPinH();
    OSTimeDly(500);
    BspBleResetOn();
    OSTimeDly(500);
}

void BspBleSetHost (FNCT_COMM comm)
{
//    CPU_INT8U data[] = {0xFA, 0x00, 0x64, 0x00, 0x64};
//    BspBleSetMode();
//    comm(data, sizeof (data));
    CPU_INT8U data[] = {0xFA, 0x00, 0x64, 0x00, 0x64};
    CPU_INT8U byte;
    BspBleSetMode();
    COM2RxFIFOClear();
    comm(data, sizeof (data));
    OSTimeDly(300);
    while (COM2RxFIFOIsEmpty() == DEF_FALSE)
    {
        byte = COM2RxFIFOOut();  
        OSTimeDly(1);
    }
    byte = byte;
    COM2RxFIFOClear();    
}

void BspBleSetDevice (FNCT_COMM comm)
{
    CPU_INT8U data[] = {0xFA, 0x00, 0x65, 0x00, 0x65};
    CPU_INT8U byte;
    BspBleSetMode();
    COM2RxFIFOClear();
    comm(data, sizeof (data));
    OSTimeDly(300);
    while (COM2RxFIFOIsEmpty() == DEF_FALSE)
    {
        byte = COM2RxFIFOOut();  
        OSTimeDly(1);
    }
    byte = byte;
    COM2RxFIFOClear();
}

void BspBleSetName (CPU_INT32U id, FNCT_COMM comm)
{
    CPU_INT8U data[128];
    //CPU_INT8U replay[128];
    CPU_INT8U count;
    CPU_INT8U i;
    CPU_INT8U j;
    CPU_INT8U id_array[36];
    CPU_INT8U fcs;
    CPU_INT8U *p;
    CPU_INT8U len;
    CPU_INT8U byte;
    
    BleCmdTypeDef *cmd;
    cmd = (BleCmdTypeDef *)data;
    

    cmd->head = 0xFA;
    cmd->cmd = HToNS(BSP_BLE_CMD_SET_NAME);
    
    i = sprintf((char *)id_array, "%d", id);
    cmd->data_len = i;
    len = sizeof(BleCmdTypeDef) + i;
    
    memcpy(&(cmd->data), id_array, cmd->data_len);
    
    //p = (CPU_INT8U *)&cmd->cmd;
    p = (CPU_INT8U *)((CPU_INT32U)cmd + 1);
    fcs = 0;
    
    for (j = 0;j < (len - 1 - 1);j++)
    {
        fcs ^= p[j];
    }
    
    data[len - 1] = fcs;
    
    count = 0;
    BspBleSetMode();
    COM2RxFIFOClear();
    comm(data, len);
    OSTimeDly(1000);
    while (COM2RxFIFOIsEmpty() == DEF_FALSE)
    {
        byte = COM2RxFIFOOut();  
        //replay[count] = byte;
        count++;
    }

    COM2RxFIFOClear();
    
    byte = byte;
}


/*************************************************************************************************************
*                                               MODULE END                                                   *
*************************************************************************************************************/
