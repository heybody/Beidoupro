/*************************************************************************************************************
*                                                  MODULE                                                    *
*************************************************************************************************************/
#ifndef BSP_MMA8491_H
#define BSP_MMA8491_H

#ifdef __cplusplus
extern "C" {
#endif
    
    
/*************************************************************************************************************
*                                              INCLUDE FILES                                                 *
*************************************************************************************************************/
#define BSP_MMA8491_I2C_PORT                                                        i2c0
#define BSP_MMA8491_I2C_EN_PORT                                                     DEV_GPIO_PORTD
#define BSP_MMA8491_I2C_EN_PIN                                                      DEV_GPIO_PIN_8

#define BSP_MMA8491_RX_DATA_TIMEOUT                                                 2000
#define BSP_MMA8491_RX_ACK_TIMEOUT                                                  500
 
#define BSP_MMA8491_ADDR                                                            0x55
    
#define BSP_MMA8491_REG_NUM                                                         7 
#define BSP_MMA8491_REG_STATUS                                                      0
#define BSP_MMA8491_REG_OUT_X_MSB                                                   1
#define BSP_MMA8491_REG_OUT_X_LSB                                                   2
#define BSP_MMA8491_REG_OUT_Y_MSB                                                   3
#define BSP_MMA8491_REG_OUT_Y_LSB                                                   4
#define BSP_MMA8491_REG_OUT_Z_MSB                                                   5
#define BSP_MMA8491_REG_OUT_Z_LSB                                                   6

    
/*************************************************************************************************************
*                                            TYPEDEF                                                         *
*************************************************************************************************************/  
#pragma pack (1)
typedef struct
{
    CPU_INT8U header;
    CPU_INT16U crc;
    CPU_INT16S  x;
    CPU_INT16S  y;
    CPU_INT16S  z;
    CPU_INT16U  rear;
} Mma8491UpdataTypeDef;

typedef struct
{
    CPU_INT8S  x;
    CPU_INT8S  y;
    CPU_INT8S  z;
} Mma8491DataTypeDef;

#pragma pack()


/*************************************************************************************************************
*                                            FUNCTION STATEMENT                                              *
*************************************************************************************************************/  
void BspMma8491Init (void);
CPU_BOOL BspMma8491Read (CPU_INT8U reg, CPU_INT8U count, CPU_INT8U *pdata);
void BspMma8491RxISR (void);
void BspMma8491EnPinH (void);
void BspMma8491EnPinL (void);
void BspMma8491EnPinPulse (void);
CPU_INT16S BspMma8491RegOutTo14BS (CPU_INT8U reg_msb, CPU_INT8U reg_lsb);
CPU_INT8S BspMma8491RegOutTo8BS (CPU_INT8U reg_msb, CPU_INT8U reg_lsb);
CPU_BOOL BspMma8491DataGet (Mma8491DataTypeDef *sensor);


/*************************************************************************************************************
*                                               MODULE END                                                   *
*************************************************************************************************************/ 
#ifdef __cplusplus
}
#endif

#endif