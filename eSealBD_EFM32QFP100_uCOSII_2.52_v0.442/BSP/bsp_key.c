/*************************************************************************************************************
*                                              INCLUDE FILES                                                 *
*************************************************************************************************************/
#include <bsp.h>


/*************************************************************************************************************
*                                                CONSTANTS                                                   *
*************************************************************************************************************/
const BspKeyTableTypeDef BspKeyTable[BSP_KEY_NUM] = 
{
    {
        .out_pin  = BSP_KEY_OUT_PIN,\
        .out_port = BSP_KEY_OUT_PORT,\
        .in_pin   = BSP_KEY_IN_PIN,\
        .in_port  = BSP_KEY_IN_PORT,\
    }
};


/*************************************************************************************************************
*                                            FUNCTION PROTOTYPES                                             *
*************************************************************************************************************/
void BspKeyInit (BspKeyTypeDef key)
{
    DevGPIOPinConfig(BspKeyTable[key].out_port, BspKeyTable[key].out_pin, DEV_GPIO_PIN_MODE_OUT_PP, 
                     DEV_GPIO_PIN_DRIVE_STANDARD, DEV_GPIO_PIN_FRQ_NORMAL);
    DevGPIOPinConfig(BspKeyTable[key].in_port, BspKeyTable[key].in_pin, DEV_GPIO_PIN_MODE_IN, 
                     DEV_GPIO_PIN_DRIVE_STANDARD, DEV_GPIO_PIN_FRQ_NORMAL);
    
    DevGPIOPinOutSet(BspKeyTable[key].out_port, BspKeyTable[key].out_pin);
}

CPU_BOOL BspKeyGet (BspKeyTypeDef key)
{
    CPU_BOOL flag;
    
    flag = DevGPIOPinInGet(BspKeyTable[key].in_port, BspKeyTable[key].in_pin);
    
    return flag;
}


/*************************************************************************************************************
*                                               MODULE END                                                   *
*************************************************************************************************************/
