/*************************************************************************************************************
*                                                  MODULE                                                    *
*************************************************************************************************************/
#ifndef BSP_A7153_H
#define BSP_A7153_H

#ifdef __cplusplus
extern "C" {
#endif


/*************************************************************************************************************
*                                                 DEFINES                                                    *
*************************************************************************************************************/
#define BSP_A7153_NUM                           1
  
#define BSP_A7153_0_SCS_PORT                    DEV_GPIO_PORTE
#define BSP_A7153_0_GIO2_PORT                   DEV_GPIO_PORTE
    
#define BSP_A7153_0_SCS_PIN                     DEV_GPIO_PIN_14
#define BSP_A7153_0_GIO2_PIN                    DEV_GPIO_PIN_9
    
#define BSP_A7153_POWER_LEVEL                   17
#define BSP_A7153_POWER_MIN                     12
    
#define BSP_A7153_POWER_0dB                     12

    
/*************************************************************************************************************
*                                                  DATA TYPES                                                *
*************************************************************************************************************/
typedef struct 
{
    DevGPIOPinTypeDef scs_pin;
    DevGPIOPortTypeDef scs_port;
    DevGPIOPinTypeDef gio2_pin;
    DevGPIOPortTypeDef gio2_port;
    DevSPITypeDef spi;
} BspA7153DeveiceTypeDef;

typedef enum 
{
    BSP_A7153_0 = 0,
} BspA7153TypeDef;


/*************************************************************************************************************
*                                            FUNCTION STATEMENT                                              *
*************************************************************************************************************/
CPU_BOOL BspA7153Init (BspA7153TypeDef n, CPU_INT8U sfd, CPU_INT8U ch);
void BspA7153IOCfg (BspA7153TypeDef n);
void BspA7153SCSH (BspA7153TypeDef n);
void BspA7153SCSL (BspA7153TypeDef n);
void BspA7153Reset (BspA7153TypeDef n);
void BspA7153SetSFD (BspA7153TypeDef n, CPU_INT8U sfd);
void BspA7153SetCH (BspA7153TypeDef n, CPU_INT8U ch);
CPU_INT8U BspA7153GetCH (BspA7153TypeDef n);
CPU_BOOL BspA7153PowerSet (BspA7153TypeDef n, CPU_INT8U power);
CPU_INT8U BspA7153PowerGet (BspA7153TypeDef n);
void BspA7153SetPayloadLen (BspA7153TypeDef n, CPU_INT8U payload_len);
void BspA7153WriteReset (BspA7153TypeDef n);
void BspA7153ReadReset (BspA7153TypeDef n);
void BspA7153FIFOClear (BspA7153TypeDef n);
CPU_INT8U BspA7153GetRN (BspA7153TypeDef n);
void BspA7153RegCfg (BspA7153TypeDef n);
void BspA7153StrobeCMD (BspA7153TypeDef n, CPU_INT8U cmd);
void BspA7153WrReg8Bit (BspA7153TypeDef n, CPU_INT8U reg, CPU_INT8U value);
CPU_INT8U BspA7153RdReg8Bit (BspA7153TypeDef n, CPU_INT8U reg);
void BspA7153WrReg16Bit (BspA7153TypeDef n, CPU_INT8U reg, CPU_INT16U value);
CPU_INT16U BspA7153RdReg16Bit (BspA7153TypeDef n, CPU_INT8U reg);
void BspA7153WrFIFO (BspA7153TypeDef n, CPU_INT8U *pdata, CPU_INT32U len);
void BspA7153RdFIFO (BspA7153TypeDef n, CPU_INT8U *pdata, CPU_INT32U len);
void BspA7125Cal (BspA7153TypeDef n);
void BspA7153CHGroupCal (BspA7153TypeDef n, CPU_INT8U ch);


/*************************************************************************************************************
*                                               MODULE END                                                   *
*************************************************************************************************************/
#ifdef __cplusplus
}
#endif

#endif
