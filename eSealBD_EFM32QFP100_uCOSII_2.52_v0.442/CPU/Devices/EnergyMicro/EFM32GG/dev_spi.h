/*************************************************************************************************************
*                                                  MODULE                                                    *
*************************************************************************************************************/
#ifndef DEV_SPI_H
#define DEV_SPI_H

#ifdef __cplusplus
extern "C" {
#endif


/*************************************************************************************************************
*                                                 DEFINES                                                    *
*************************************************************************************************************/
#define DEV_SPI_NUM                             3u
#define DEV_SPI_LOCTION_NUM                     6u
    
#define DEV_SPI0_LOC0_MOSI_PORT                 DEV_GPIO_PORTE
#define DEV_SPI0_LOC0_MISO_PORT                 DEV_GPIO_PORTE
#define DEV_SPI0_LOC0_CLK_PORT                  DEV_GPIO_PORTE
#define DEV_SPI0_LOC0_CS_PORT                   DEV_GPIO_PORTE
#define DEV_SPI0_LOC1_MOSI_PORT                 DEV_GPIO_PORTE
#define DEV_SPI0_LOC1_MISO_PORT                 DEV_GPIO_PORTE
#define DEV_SPI0_LOC1_CLK_PORT                  DEV_GPIO_PORTE
#define DEV_SPI0_LOC1_CS_PORT                   DEV_GPIO_PORTE
#define DEV_SPI0_LOC2_MOSI_PORT                 DEV_GPIO_PORTC
#define DEV_SPI0_LOC2_MISO_PORT                 DEV_GPIO_PORTC
#define DEV_SPI0_LOC2_CLK_PORT                  DEV_GPIO_PORTC
#define DEV_SPI0_LOC2_CS_PORT                   DEV_GPIO_PORTC
#define DEV_SPI0_LOC4_MOSI_PORT                 DEV_GPIO_PORTB
#define DEV_SPI0_LOC4_MISO_PORT                 DEV_GPIO_PORTB
#define DEV_SPI0_LOC4_CLK_PORT                  DEV_GPIO_PORTB
#define DEV_SPI0_LOC4_CS_PORT                   DEV_GPIO_PORTB
#define DEV_SPI0_LOC5_MOSI_PORT                 DEV_GPIO_PORTC
#define DEV_SPI0_LOC5_MISO_PORT                 DEV_GPIO_PORTC
#define DEV_SPI0_LOC5_CLK_PORT                  DEV_GPIO_PORTB
#define DEV_SPI0_LOC5_CS_PORT                   DEV_GPIO_PORTB
    
#define DEV_SPI1_LOC0_MOSI_PORT                 DEV_GPIO_PORTC
#define DEV_SPI1_LOC0_MISO_PORT                 DEV_GPIO_PORTC
#define DEV_SPI1_LOC0_CLK_PORT                  DEV_GPIO_PORTB
#define DEV_SPI1_LOC0_CS_PORT                   DEV_GPIO_PORTB
#define DEV_SPI1_LOC1_MOSI_PORT                 DEV_GPIO_PORTD
#define DEV_SPI1_LOC1_MISO_PORT                 DEV_GPIO_PORTD
#define DEV_SPI1_LOC1_CLK_PORT                  DEV_GPIO_PORTD
#define DEV_SPI1_LOC1_CS_PORT                   DEV_GPIO_PORTD
#define DEV_SPI1_LOC2_MOSI_PORT                 DEV_GPIO_PORTD
#define DEV_SPI1_LOC2_MISO_PORT                 DEV_GPIO_PORTD
#define DEV_SPI1_LOC2_CLK_PORT                  DEV_GPIO_PORTF
#define DEV_SPI1_LOC2_CS_PORT                   DEV_GPIO_PORTF

#define DEV_SPI2_LOC0_MOSI_PORT                 DEV_GPIO_PORTC
#define DEV_SPI2_LOC0_MISO_PORT                 DEV_GPIO_PORTC
#define DEV_SPI2_LOC0_CLK_PORT                  DEV_GPIO_PORTC
#define DEV_SPI2_LOC0_CS_PORT                   DEV_GPIO_PORTC
#define DEV_SPI2_LOC1_MOSI_PORT                 DEV_GPIO_PORTB
#define DEV_SPI2_LOC1_MISO_PORT                 DEV_GPIO_PORTB
#define DEV_SPI2_LOC1_CLK_PORT                  DEV_GPIO_PORTB
#define DEV_SPI2_LOC1_CS_PORT                   DEV_GPIO_PORTB

#define DEV_SPI0_LOC0_MOSI_PIN                  DEV_GPIO_PIN_10
#define DEV_SPI0_LOC0_MISO_PIN                  DEV_GPIO_PIN_11
#define DEV_SPI0_LOC0_CLK_PIN                   DEV_GPIO_PIN_12
#define DEV_SPI0_LOC0_CS_PIN                    DEV_GPIO_PIN_13
#define DEV_SPI0_LOC1_MOSI_PIN                  DEV_GPIO_PIN_7
#define DEV_SPI0_LOC1_MISO_PIN                  DEV_GPIO_PIN_6
#define DEV_SPI0_LOC1_CLK_PIN                   DEV_GPIO_PIN_5
#define DEV_SPI0_LOC1_CS_PIN                    DEV_GPIO_PIN_4
#define DEV_SPI0_LOC2_MOSI_PIN                  DEV_GPIO_PIN_11
#define DEV_SPI0_LOC2_MISO_PIN                  DEV_GPIO_PIN_10
#define DEV_SPI0_LOC2_CLK_PIN                   DEV_GPIO_PIN_9
#define DEV_SPI0_LOC2_CS_PIN                    DEV_GPIO_PIN_8
#define DEV_SPI0_LOC4_MOSI_PIN                  DEV_GPIO_PIN_7
#define DEV_SPI0_LOC4_MISO_PIN                  DEV_GPIO_PIN_8
#define DEV_SPI0_LOC4_CLK_PIN                   DEV_GPIO_PIN_13
#define DEV_SPI0_LOC4_CS_PIN                    DEV_GPIO_PIN_14
#define DEV_SPI0_LOC5_MOSI_PIN                  DEV_GPIO_PIN_0
#define DEV_SPI0_LOC5_MISO_PIN                  DEV_GPIO_PIN_1
#define DEV_SPI0_LOC5_CLK_PIN                   DEV_GPIO_PIN_13
#define DEV_SPI0_LOC5_CS_PIN                    DEV_GPIO_PIN_14
    
#define DEV_SPI1_LOC0_MOSI_PIN                  DEV_GPIO_PIN_0
#define DEV_SPI1_LOC0_MISO_PIN                  DEV_GPIO_PIN_1
#define DEV_SPI1_LOC0_CLK_PIN                   DEV_GPIO_PIN_7
#define DEV_SPI1_LOC0_CS_PIN                    DEV_GPIO_PIN_8
#define DEV_SPI1_LOC1_MOSI_PIN                  DEV_GPIO_PIN_0
#define DEV_SPI1_LOC1_MISO_PIN                  DEV_GPIO_PIN_1
#define DEV_SPI1_LOC1_CLK_PIN                   DEV_GPIO_PIN_2
#define DEV_SPI1_LOC1_CS_PIN                    DEV_GPIO_PIN_3
#define DEV_SPI1_LOC2_MOSI_PIN                  DEV_GPIO_PIN_7
#define DEV_SPI1_LOC2_MISO_PIN                  DEV_GPIO_PIN_6
#define DEV_SPI1_LOC2_CLK_PIN                   DEV_GPIO_PIN_0
#define DEV_SPI1_LOC2_CS_PIN                    DEV_GPIO_PIN_1
    
#define DEV_SPI2_LOC0_MOSI_PIN                  DEV_GPIO_PIN_2
#define DEV_SPI2_LOC0_MISO_PIN                  DEV_GPIO_PIN_3
#define DEV_SPI2_LOC0_CLK_PIN                   DEV_GPIO_PIN_4
#define DEV_SPI2_LOC0_CS_PIN                    DEV_GPIO_PIN_5
#define DEV_SPI2_LOC1_MOSI_PIN                  DEV_GPIO_PIN_3
#define DEV_SPI2_LOC1_MISO_PIN                  DEV_GPIO_PIN_4
#define DEV_SPI2_LOC1_CLK_PIN                   DEV_GPIO_PIN_5
#define DEV_SPI2_LOC1_CS_PIN                    DEV_GPIO_PIN_6
    
#define DEV_SPI0_LOC0                           USART_LOC0
#define DEV_SPI0_LOC1                           USART_LOC1
#define DEV_SPI0_LOC2                           USART_LOC2
#define DEV_SPI0_LOC4                           USART_LOC4
#define DEV_SPI0_LOC5                           USART_LOC5
    
#define DEV_SPI1_LOC0                           USART_LOC0
#define DEV_SPI1_LOC1                           USART_LOC1
#define DEV_SPI1_LOC2                           USART_LOC2
    
#define DEV_SPI2_LOC0                           USART_LOC0
#define DEV_SPI2_LOC1                           USART_LOC1
    
    
/*************************************************************************************************************
*                                                  DATA TYPES                                                *
*************************************************************************************************************/
typedef enum 
{
    DEV_SPI0 = 0,
    DEV_SPI1 = 1,
    DEV_SPI2 = 2,
}DevSPITypeDef;

typedef struct
{
    DevGPIOPortTypeDef mosi_port;
    DevGPIOPortTypeDef miso_port;
    DevGPIOPortTypeDef clk_port;
    DevGPIOPortTypeDef cs_port;
    DevGPIOPinTypeDef  mosi_pin;
    DevGPIOPinTypeDef  miso_pin;
    DevGPIOPinTypeDef  clk_pin;
    DevGPIOPinTypeDef  cs_pin;
    CPU_INT32U         loc;
} DevSPIPinTypeDef;

typedef struct
{
    CPU_INT32U       x;
    DevSPIPinTypeDef pin[DEV_SPI_LOCTION_NUM];
} DevSPITableTypeDef;

typedef enum
{
    DEV_SPI_PIN_LOC0 = 0,
    DEV_SPI_PIN_LOC1 = 1,
    DEV_SPI_PIN_LOC2 = 2,
    DEV_SPI_PIN_LOC4 = 4,
    DEV_SPI_PIN_LOC5 = 5,
} DevSPIPinLoctionTypeDef;

typedef enum
{
    DEV_SPI_BIT_8  = USART_DATABIT_EIGHT,
    DEV_SPI_BIT_16 = USART_DATABIT_SIXTEEN,
} DevSPIDataBitTypeDef;

typedef enum
{
    DEV_SPI_CLOCK_MODE0 = USART_CLOCK_MODE0,
    DEV_SPI_CLOCK_MODE1 = USART_CLOCK_MODE1,
    DEV_SPI_CLOCK_MODE2 = USART_CLOCK_MODE2, 
    DEV_SPI_CLOCK_MODE3 = USART_CLOCK_MODE3,
} DevSPIClockModeTypeDef;
                                           
typedef enum
{
    DEV_SPI_MSBF_LSB = USART_MSBF_LSB, 
    DEV_SPI_MSBF_MSB = USART_MSBF_MSB, 
} DevSPIMSBFTypeDef;

typedef enum
{
    DEV_SPI_MASTER = USART_SYNC_MODE_MASTER, 
    DEV_SPI_SLAVE  = USART_SYNC_MODE_SLAVE, 
} DevSPIModeTypeDef;


/*************************************************************************************************************
*                                            FUNCTION STATEMENT                                              *
*************************************************************************************************************/ 
void DevSPIClockEnable (DevSPITypeDef x);
void DevSPIClockDisable (DevSPITypeDef x);
void DevSPIIOConfig (DevSPITypeDef x, DevSPIPinLoctionTypeDef loction, CPU_BOOL cs);
void DevSPIInit (DevSPITypeDef x, DevSPIDataBitTypeDef bits, DevSPIClockModeTypeDef clock, 
                 DevSPIMSBFTypeDef msb,DevSPIModeTypeDef mode, CPU_INT32U baud, CPU_BOOL cs);
void DevSPITxData (DevSPITypeDef x, CPU_INT8U *pdata, CPU_INT32U len);
void DevSPIRxData (DevSPITypeDef x, CPU_INT8U *pdata, CPU_INT32U len);


/*************************************************************************************************************
*                                               MODULE END                                                   *
*************************************************************************************************************/ 
#endif

