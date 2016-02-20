/*************************************************************************************************************
*                                                  MODULE                                                    *
*************************************************************************************************************/
#ifndef DEV_I2C_H
#define DEV_I2C_H

#ifdef __cplusplus
extern "C" {
#endif

/*************************************************************************************************************
*                                                 DEFINES                                                    *
*************************************************************************************************************/
#define DEV_I2C_NUM                                 2
#define DEV_I2C_INT_NUM                             17
#define DEV_I2C_PIN_LOC_NUM                         6
    

#define DEV_I2C0_LOC0_SDA_PORT                      DEV_GPIO_PORTA
#define DEV_I2C0_LOC0_SDA_PIN                       DEV_GPIO_PIN_0
#define DEV_I2C0_LOC0_SCL_PORT                      DEV_GPIO_PORTA
#define DEV_I2C0_LOC0_SCL_PIN                       DEV_GPIO_PIN_1
#define DEV_I2C0_LOC1_SDA_PORT                      DEV_GPIO_PORTD
#define DEV_I2C0_LOC1_SDA_PIN                       DEV_GPIO_PIN_6
#define DEV_I2C0_LOC1_SCL_PORT                      DEV_GPIO_PORTD
#define DEV_I2C0_LOC1_SCL_PIN                       DEV_GPIO_PIN_7    
#define DEV_I2C0_LOC2_SDA_PORT                      DEV_GPIO_PORTC
#define DEV_I2C0_LOC2_SDA_PIN                       DEV_GPIO_PIN_6
#define DEV_I2C0_LOC2_SCL_PORT                      DEV_GPIO_PORTC
#define DEV_I2C0_LOC2_SCL_PIN                       DEV_GPIO_PIN_7  
#define DEV_I2C0_LOC3_SDA_PORT                      DEV_GPIO_PORTC
#define DEV_I2C0_LOC3_SDA_PIN                       DEV_GPIO_PIN_0
#define DEV_I2C0_LOC3_SCL_PORT                      DEV_GPIO_PORTC
#define DEV_I2C0_LOC3_SCL_PIN                       DEV_GPIO_PIN_1  
#define DEV_I2C0_LOC4_SDA_PORT                      DEV_GPIO_PORTF
#define DEV_I2C0_LOC4_SDA_PIN                       DEV_GPIO_PIN_0
#define DEV_I2C0_LOC4_SCL_PORT                      DEV_GPIO_PORTF
#define DEV_I2C0_LOC4_SCL_PIN                       DEV_GPIO_PIN_1 
#define DEV_I2C0_LOC5_SDA_PORT                      DEV_GPIO_PORTE
#define DEV_I2C0_LOC5_SDA_PIN                       DEV_GPIO_PIN_12
#define DEV_I2C0_LOC5_SCL_PORT                      DEV_GPIO_PORTE
#define DEV_I2C0_LOC5_SCL_PIN                       DEV_GPIO_PIN_13
                                                    
#define DEV_I2C1_LOC0_SDA_PORT                      DEV_GPIO_PORTC
#define DEV_I2C1_LOC0_SDA_PIN                       DEV_GPIO_PIN_4
#define DEV_I2C1_LOC0_SCL_PORT                      DEV_GPIO_PORTC
#define DEV_I2C1_LOC0_SCL_PIN                       DEV_GPIO_PIN_5
#define DEV_I2C1_LOC1_SDA_PORT                      DEV_GPIO_PORTB
#define DEV_I2C1_LOC1_SDA_PIN                       DEV_GPIO_PIN_11
#define DEV_I2C1_LOC1_SCL_PORT                      DEV_GPIO_PORTB
#define DEV_I2C1_LOC1_SCL_PIN                       DEV_GPIO_PIN_12    
#define DEV_I2C1_LOC2_SDA_PORT                      DEV_GPIO_PORTE
#define DEV_I2C1_LOC2_SDA_PIN                       DEV_GPIO_PIN_0
#define DEV_I2C1_LOC2_SCL_PORT                      DEV_GPIO_PORTE
#define DEV_I2C1_LOC2_SCL_PIN                       DEV_GPIO_PIN_1
        
#define DEV_I2C0_LOC0                               I2C_LOC0                           
#define DEV_I2C0_LOC1                               I2C_LOC1                           
#define DEV_I2C0_LOC2                               I2C_LOC2                           
#define DEV_I2C0_LOC3                               I2C_LOC4                           
#define DEV_I2C0_LOC4                               I2C_LOC5                           
#define DEV_I2C0_LOC5                               I2C_LOC6                           
#define DEV_I2C1_LOC0                               I2C_LOC0                           
#define DEV_I2C1_LOC1                               I2C_LOC1                           
#define DEV_I2C1_LOC2                               I2C_LOC2                           
    
    
/***********************************************************************************************************
*                                            TYPE DEFINES                                                   *
*************************************************************************************************************/    
typedef enum
{
    DEV_I2C0 = 0,
    DEV_I2C1 = 1,
} DevI2CTypeDef;

typedef struct
{
    I2CModeTypedef mode;
    CPU_INT16U div;
    CPU_INT8U slave_addr;
} DevI2cInitTypeDef;

typedef enum
{
     DEV_I2C_PIN_LOC0 = 0,
     DEV_I2C_PIN_LOC1 = 1,
     DEV_I2C_PIN_LOC2 = 2,
     DEV_I2C_PIN_LOC3 = 3,
     DEV_I2C_PIN_LOC4 = 4,
     DEV_I2C_PIN_LOC5 = 5,
} DevI2cPinLoctionTypeDef;

typedef struct
{
    DevGPIOPortTypeDef sda_port;
    DevGPIOPortTypeDef scl_port;
    DevGPIOPinTypeDef  sda_pin;
    DevGPIOPinTypeDef  scl_pin;
    CPU_INT32U         loc;
} DevI2cPinTypeDef;

typedef struct
{
    I2CTypedef port;
    DevI2cPinTypeDef  pin[DEV_I2C_PIN_LOC_NUM];
} DevI2CTableTypeDef;

typedef enum
{
    WRITE = 0,
    READ = 1,
}DevI2cRWModeType; 

typedef enum
{
    DEV_I2C_INT_START = IF_START,
    DEV_I2C_INT_RSTART = IF_RSTART,
    DEV_I2C_INT_ADDR = IF_ADDR,
    DEV_I2C_INT_TXC = IF_TXC,
    DEV_I2C_INT_TXBL = IF_TXBL,
    DEV_I2C_INT_RXDATAV = IF_RXDATAV,
    DEV_I2C_INT_ACK = IF_ACK,
    DEV_I2C_INT_NACK = IF_NACK,
    DEV_I2C_INT_MSTOP = IF_MSTOP,
    DEV_I2C_INT_ARBLOST = IF_ARBLOST,
    DEV_I2C_INT_BUSERR = IF_BUSERR,
    DEV_I2C_INT_BUSHOLD = IF_BUSHOLD,
    DEV_I2C_INT_TXOF = IF_TXOF,
    DEV_I2C_INT_RXUF = IF_RXUF,
    DEV_I2C_INT_BITO = IF_BITO,
    DEV_I2C_INTF_CLTO = IF_CLTO,
    DEV_I2C_INT_SSTOP = IF_SSTOP,
   // DEV_I2C_INT_ALL  = IF_MASK,
} DevI2cIntTypedef;

typedef enum
{
    START = I2C_CMD_START,
    STOP = I2C_CMD_STOP,
    ACK = I2C_CMD_ACK,
    NACK = I2C_CMD_NACK,
    CONT = I2C_CMD_CONT,
    ABORT = I2C_CMD_ABORT,
    CLEARTX = I2C_CMD_CLEARTX,
    CLEARPC = I2C_CMD_CLEARPC,
} DevI2cCmdTypedef;


/*************************************************************************************************************
*                                            FUNCTION STATEMENT                                              *
*************************************************************************************************************/
void  DevI2CClockEnable (DevI2CTypeDef x);
void  DevI2CClockDisable (DevI2CTypeDef x);
void DevI2CInit (DevI2CTypeDef x, DevI2cInitTypeDef init);
void DevI2CIOConfig (DevI2CTypeDef x, DevI2cPinLoctionTypeDef loc);
void DevI2CTxStartAddr (DevI2CTypeDef x, CPU_INT8U addr, DevI2cRWModeType mode);
void DevI2CTxData (DevI2CTypeDef x, CPU_INT8U *pdata, CPU_INT16U len);
CPU_INT8U DevI2CRxData (DevI2CTypeDef x);
CPU_BOOL DevI2CSlaverAckFlagGet (DevI2CTypeDef x);

void DevI2CIntInit (DevI2CTypeDef x);
void DevI2CIntEnable (DevI2CTypeDef x, DevI2cIntTypedef irq);
void DevI2CIntDisable (DevI2CTypeDef x, DevI2cIntTypedef irq);
void DevI2cIntRegister (DevI2CTypeDef x, DevI2cIntTypedef irq, FNCT_VOID isr);
void DevI2cIntUnregister (DevI2CTypeDef x, DevI2cIntTypedef irq, FNCT_VOID isr);
void DevI2c0IntHandler(void);
void DevI2c1IntHandler(void);
void DevI2cSendCmd (DevI2CTypeDef x, DevI2cCmdTypedef cmd);


/*************************************************************************************************************
*                                               MODULE END                                                   *
*************************************************************************************************************/     
#ifdef __cplusplus
}
#endif

#endif 