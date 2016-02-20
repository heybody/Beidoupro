/*************************************************************************************************************
*                                                  MODULE                                                    *
*************************************************************************************************************/
#ifndef BSP_BLE_H
#define BSP_BLE_H

#ifdef __cplusplus
extern "C" {
#endif

    
/*************************************************************************************************************
*                                                 DEFINES                                                    *
*************************************************************************************************************/
//P07
#define BSP_BLE_RST_PIN                         DEV_GPIO_PIN_8
#define BSP_BLE_RST_PORT                        DEV_GPIO_PORTC
//P16
#define BSP_BLE_WU_PIN                          DEV_GPIO_PIN_9
#define BSP_BLE_WU_PORT                         DEV_GPIO_PORTC 
//P17
#define BSP_BLE_FORCE_PIN                       DEV_GPIO_PIN_10
#define BSP_BLE_FORCE_PORT                      DEV_GPIO_PORTC 
//P26
#define BSP_BLE_STATUS_PIN                      DEV_GPIO_PIN_11
#define BSP_BLE_STATUS_PORT                     DEV_GPIO_PORTC
    
#define BSP_BLE_CMD_SET_NAME                    0x0014
    
    
/*************************************************************************************************************
*                                             DATA TYPES                                                    *
*************************************************************************************************************/
#pragma pack(1)
typedef struct
{
    CPU_INT8U head;
    CPU_INT16U cmd;
    CPU_INT8U data_len;
    CPU_INT8U data;
} BleCmdTypeDef;

#pragma pack()
    
    
/*************************************************************************************************************
*                                            FUNCTION STATEMENT                                              *
*************************************************************************************************************/
void BspBleInit (void);
void BspBleIOInit (void);
void BspBleResetOn (void);
void BspBleResetOff (void);
void BspBleWUPinL (void);
void BspBleWUPinH (void);
void BspBleForcePinL (void);
void BspBleForcePinH (void);
CPU_BOOL BspBleStatusGet (void);
void BspBleSetMode (void);
void BspBleSetHost (FNCT_COMM comm);
void BspBleSetDevice (FNCT_COMM comm);
//void BspBleSetName (FNCT_COMM comm);
void BspBleRecovery(void);
void BspBleSetName (CPU_INT32U id, FNCT_COMM comm);


/*************************************************************************************************************
*                                               MODULE END                                                   *
*************************************************************************************************************/ 
#ifdef __cplusplus
}
#endif

#endif
