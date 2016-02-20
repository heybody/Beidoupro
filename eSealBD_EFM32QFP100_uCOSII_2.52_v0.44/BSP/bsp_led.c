/*************************************************************************************************************
*                                              INCLUDE FILES                                                 *
*************************************************************************************************************/
#include <bsp.h>


/*************************************************************************************************************
*                                                CONSTANTS                                                   *
*************************************************************************************************************/
const BspLedTableTypeDef BspLedTable[BSP_LED_NUM] = 
{
    {
        .port = BSP_LED4_PORT,\
        .pin  = BSP_LED4_PIN,\
    },\
    {
        .port = BSP_LED5_PORT,\
        .pin  = BSP_LED5_PIN,\
    },\
    {
        .port = BSP_LED6_PORT,\
        .pin  = BSP_LED6_PIN,\
    },\
    {
        .port = BSP_LED7_PORT,\
        .pin  = BSP_LED7_PIN,\
    },\
    {
        .port = BSP_LED10_PORT,\
        .pin  = BSP_LED10_PIN,\
    },\
    {
        .port = BSP_LED11_PORT,\
        .pin  = BSP_LED11_PIN,\
    },\
    {
        .port = BSP_LED12_PORT,\
        .pin  = BSP_LED12_PIN,\
    },\
    {
        .port = BSP_LED13_PORT,\
        .pin  = BSP_LED13_PIN,\
    },\
    {
        .port = BSP_LED1_PORT,\
        .pin  = BSP_LED1_PIN,\
    },\
    {
        .port = BSP_LED2_PORT,\
        .pin  = BSP_LED2_PIN,\
    },\
};


/*************************************************************************************************************
*                                            FUNCTION PROTOTYPES                                             *
*************************************************************************************************************/
void BspLedInit (BspLedTypeDef led)
{
    DevGPIOPinConfig(BspLedTable[led].port, BspLedTable[led].pin, DEV_GPIO_PIN_MODE_OUT_PP,//DEV_GPIO_PIN_MODE_OUT_PP, 
                     DEV_GPIO_PIN_DRIVE_STANDARD, DEV_GPIO_PIN_FRQ_NORMAL);
}

void BspLedOn (BspLedTypeDef led)
{
    DevGPIOPinOutSet(BspLedTable[led].port, BspLedTable[led].pin);
}

void BspLedOff (BspLedTypeDef led)
{
    DevGPIOPinOutClear(BspLedTable[led].port, BspLedTable[led].pin);
}

void BspLedToggle (BspLedTypeDef led)
{
    DevGPIOPinOutToggle(BspLedTable[led].port, BspLedTable[led].pin);
}


/*************************************************************************************************************
*                                               MODULE END                                                   *
*************************************************************************************************************/
