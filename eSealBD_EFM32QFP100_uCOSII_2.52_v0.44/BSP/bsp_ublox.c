/*************************************************************************************************************
*                                              INCLUDE FILES                                                 *
*************************************************************************************************************/
#include <bsp.h>


/*************************************************************************************************************
*                                            FUNCTION PROTOTYPES                                             *
*************************************************************************************************************/
void BspUbloxIOConfig (void)
{
   
    DevGPIOPinConfig(BSP_UBLOX_PWR_PORT, BSP_UBLOX_PWR_PIN, DEV_GPIO_PIN_MODE_OUT_PP, 
                     DEV_GPIO_PIN_DRIVE_STANDARD, DEV_GPIO_PIN_FRQ_NORMAL);
    
    DevGPIOPinConfig(BSP_UBLOX_RESET_PORT, BSP_UBLOX_RESET_PIN, DEV_GPIO_PIN_MODE_OUT_PP, 
                     DEV_GPIO_PIN_DRIVE_STANDARD, DEV_GPIO_PIN_FRQ_NORMAL);
    //BspUbloxRestartPinH();
    BspUbloxRstPinL();
    BspUbloxPwrPinL();


}
void BspUbloxRstPinH(void)
{
    DevGPIOPinOutSet(BSP_UBLOX_RESET_PORT, BSP_UBLOX_RESET_PIN);
}
void BspUbloxRstPinL(void)
{
    DevGPIOPinOutClear(BSP_UBLOX_RESET_PORT, BSP_UBLOX_RESET_PIN);
}

void BspUbloxPwrPinH(void)
{
    DevGPIOPinOutSet(BSP_UBLOX_PWR_PORT, BSP_UBLOX_PWR_PIN);


}

void BspUbloxPwrPinL(void)
{
    DevGPIOPinOutClear(BSP_UBLOX_PWR_PORT, BSP_UBLOX_PWR_PIN);

}

void BspUbloxPowewrOn(void)
{
  BspUbloxPwrPinL();

}
void BspUbloxPowewrOff(void)
{

     BspUbloxPwrPinH();
}


/*************************************************************************************************************
*                                               MODULE END                                                   *
*************************************************************************************************************/
