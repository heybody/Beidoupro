/*************************************************************************************************************
*                                              INCLUDE FILES                                                 *
*************************************************************************************************************/
#include <efm32.h>


/*************************************************************************************************************
*                                            GLOBAL VARIABLES                                                *
*************************************************************************************************************/ 
extern CPU_INT8U const MapTbl[256];


/*************************************************************************************************************
*                                            FUNCTION PROTOTYPES                                             *
*************************************************************************************************************/
void GPIOClockEnable (void)
{
    CMUHFPeripheralClockEnable((CMUHFPERClockTypeDef)DEF_BIT13);
}

void GPIOClockDisable (void)
{
    CMUHFPeripheralClockDisable(GPIOClock);
}

void GPIOModeSet (GPIOPortTypeDef port, GPIOPinTypeDef pin, GPIOModeTypeDef mode)
{
    CPU_INT8U n;
    
    if (pin < GPIO_PIN_8)
    {
        n = MapTbl[(CPU_INT8U)pin];
        GPIO->PORT[port].MODEL = (GPIO->PORT[port].MODEL & ~(0xF << (n * 4))) | (mode << (n * 4));
    }
    else
    {
        n = MapTbl[(CPU_INT8U)(pin >> 8)];
        GPIO->PORT[port].MODEH = (GPIO->PORT[port].MODEH & ~(0xF << (n * 4))) | (mode << (n * 4));
    }
}

void GPIODriveSet (GPIOPortTypeDef port, GPIODriveTypeDef drive)
{
    GPIO->PORT[port].CTRL = (GPIO->PORT[port].CTRL & ~(GPIO_CTRL_DRIVEMODE_MASK)) | drive;
}

void GPIODebugLocationSet (GPIODebugLocationTypeDef location)
{
    GPIO->ROUTE = (GPIO->ROUTE & ~GPIO_ROUTE_SWLOCATION_MASK) | location;
}

void GPIOIntConfig (GPIOPortTypeDef port, GPIOPinTypeDef pin, GPIOIntTypeDef type)
{
    CPU_INT8U n;
    
    if (pin < GPIO_PIN_8)
    {
        n = MapTbl[(CPU_INT8U)pin];
        GPIO->EXTIPSELL = (GPIO->EXTIPSELL & ~(0xF << (n * 4))) | (port << (n * 4));
    }
    else
    {
        n = MapTbl[(CPU_INT8U)(pin >> 8)];
        GPIO->EXTIPSELH = (GPIO->EXTIPSELH & ~(0xF << (n * 4))) | (port << (n * 4));
    }
    
    switch (type)
    {
        case GPIO_FALLING_EDGE:     GPIO->EXTIFALL |= pin;
                                    break;
        case GPIO_RISING_EDGE:      GPIO->EXTIRISE |= pin;
                                    break;
        case GPIO_BOTH_EDGES:       GPIO->EXTIFALL |= pin;
                                    GPIO->EXTIRISE |= pin;
                                    break;
        default:                    break;
    }
}


/*************************************************************************************************************
*                                                  END FILE                                                  *
*************************************************************************************************************/