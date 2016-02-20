/*************************************************************************************************************
*                                                  MODULE                                                    *
*************************************************************************************************************/
#ifndef BSP_LED_H
#define BSP_LED_H

#ifdef __cplusplus
extern "C" {
#endif

    
/*************************************************************************************************************
*                                                 DEFINES                                                    *
*************************************************************************************************************/
#define BSP_LED_NUM                             10u
    
#define BSP_LED1_PIN                            DEV_GPIO_PIN_10
#define BSP_LED2_PIN                            DEV_GPIO_PIN_11
#define BSP_LED4_PIN                            DEV_GPIO_PIN_11
#define BSP_LED5_PIN                            DEV_GPIO_PIN_10
#define BSP_LED6_PIN                            DEV_GPIO_PIN_13
#define BSP_LED7_PIN                            DEV_GPIO_PIN_12
#define BSP_LED10_PIN                           DEV_GPIO_PIN_11
#define BSP_LED11_PIN                           DEV_GPIO_PIN_10
#define BSP_LED12_PIN                           DEV_GPIO_PIN_9
#define BSP_LED13_PIN                           DEV_GPIO_PIN_8     
    
#define BSP_LED1_PORT                           DEV_GPIO_PORTF
#define BSP_LED2_PORT                           DEV_GPIO_PORTF
#define BSP_LED4_PORT                           DEV_GPIO_PORTF
#define BSP_LED5_PORT                           DEV_GPIO_PORTF
#define BSP_LED6_PORT                           DEV_GPIO_PORTC
#define BSP_LED7_PORT                           DEV_GPIO_PORTC
#define BSP_LED10_PORT                          DEV_GPIO_PORTC
#define BSP_LED11_PORT                          DEV_GPIO_PORTC
#define BSP_LED12_PORT                          DEV_GPIO_PORTC
#define BSP_LED13_PORT                          DEV_GPIO_PORTC    


/*************************************************************************************************************
*                                                  DATA TYPES                                                *
*************************************************************************************************************/
typedef enum 
{
    BSP_LED4  = 0,
    BSP_LED5  = 1,
    BSP_LED6  = 2,
    BSP_LED7  = 3,
    BSP_LED10 = 4,
    BSP_LED11 = 5,
    BSP_LED12 = 6,
    BSP_LED13 = 7,
    BSP_LED1  = 8,
    BSP_LED2  = 9,
} BspLedTypeDef;

typedef struct
{
    DevGPIOPortTypeDef port;
    DevGPIOPinTypeDef  pin;
} BspLedTableTypeDef;


/*************************************************************************************************************
*                                            FUNCTION STATEMENT                                              *
*************************************************************************************************************/
void BspLedInit (BspLedTypeDef led);
void BspLedOff (BspLedTypeDef led);
void BspLedOn (BspLedTypeDef led);
void BspLedToggle (BspLedTypeDef led);


/*************************************************************************************************************
*                                               MODULE END                                                   *
*************************************************************************************************************/ 
#ifdef __cplusplus
}
#endif

#endif
