/*************************************************************************************************************
*                                              INCLUDE FILES                                                 *
*************************************************************************************************************/
#include <bsp.h>


/*************************************************************************************************************
*                                            FUNCTION PROTOTYPES                                             *
*************************************************************************************************************/
void BspMG2639IOInit(void)
{
    DevGPIOPinConfig(BSP_MG2639_PWRKEY_N_PORT, BSP_MG2639_PWRKEY_N_PIN, DEV_GPIO_PIN_MODE_OUT_PP, 
                     DEV_GPIO_PIN_DRIVE_STANDARD, DEV_GPIO_PIN_FRQ_NORMAL);
    DevGPIOPinConfig(BSP_MG2639_SYSRST_PORT, BSP_MG2639_SYSRST_PIN, DEV_GPIO_PIN_MODE_OUT_PP, 
                     DEV_GPIO_PIN_DRIVE_STANDARD, DEV_GPIO_PIN_FRQ_NORMAL);
    DevGPIOPinConfig(BSP_MG2639_WAKEUP_PORT, BSP_MG2639_WAKEUP_PIN, DEV_GPIO_PIN_MODE_OUT_PP, 
                     DEV_GPIO_PIN_DRIVE_STANDARD, DEV_GPIO_PIN_FRQ_NORMAL);
    DevGPIOPinConfig(BSP_MG2639_EN_PORT, BSP_MG2639_EN_PIN, DEV_GPIO_PIN_MODE_OUT_PP, 
                     DEV_GPIO_PIN_DRIVE_STANDARD, DEV_GPIO_PIN_FRQ_NORMAL);

    
}

void BspMG2639Enable (void)
{
    DevGPIOPinOutSet(BSP_MG2639_EN_PORT, BSP_MG2639_EN_PIN);
}

void BspMG2639Disable(void)
{
    DevGPIOPinOutClear(BSP_MG2639_EN_PORT, BSP_MG2639_EN_PIN);
}

void BspMG2639PowerkeyPinH (void)
{
    DevGPIOPinOutSet(BSP_MG2639_PWRKEY_N_PORT, BSP_MG2639_PWRKEY_N_PIN);
}

void BspMG2639PowerkeyPinL (void)
{
    DevGPIOPinOutClear(BSP_MG2639_PWRKEY_N_PORT, BSP_MG2639_PWRKEY_N_PIN);
}

void BspMG2639SystemResetPinH (void)
{
    DevGPIOPinOutSet(BSP_MG2639_SYSRST_PORT, BSP_MG2639_SYSRST_PIN);
}

void BspMG2639SystemResetPinL (void)
{
    DevGPIOPinOutClear(BSP_MG2639_SYSRST_PORT, BSP_MG2639_SYSRST_PIN);
}

void BspMG2639WakeupPinH (void)
{
    DevGPIOPinOutSet(BSP_MG2639_WAKEUP_PORT, BSP_MG2639_WAKEUP_PIN);
}

void BspMG2639WakeupPinL (void)
{
    DevGPIOPinOutClear(BSP_MG2639_WAKEUP_PORT, BSP_MG2639_WAKEUP_PIN);
}




/*************************************************************************************************************
*                                               MODULE END                                                   *
*************************************************************************************************************/
