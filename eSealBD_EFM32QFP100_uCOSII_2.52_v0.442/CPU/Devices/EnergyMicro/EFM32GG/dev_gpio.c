/*************************************************************************************************************
*                                              INCLUDE FILES                                                 *
*************************************************************************************************************/
#include <dev.h>


/*************************************************************************************************************
*                                            GLOBAL VARIABLES                                                *
*************************************************************************************************************/ 
extern CPU_INT8U const MapTbl[256];


/*************************************************************************************************************
*                                              LOCAL TABLES                                                  *
*************************************************************************************************************/
static FNCT_VOID DevGPIOIntVectTbl[GPIO_PIN_NUM];
static volatile CPU_INT32U DevGPIOIrqRegisterFlag;


/*************************************************************************************************************
*                                            FUNCTION PROTOTYPES                                             *
*************************************************************************************************************/
void DevGPIOInit (void)
{
    GPIOClockEnable();
    DevGPIOIntInit();
}

void DevGPIOPinConfig (DevGPIOPortTypeDef port, DevGPIOPinTypeDef pin, DevGPIOPinModeTypeDef mode, 
                       DevGPIOPinDriveTypeDef drive, DevGPIOPinDFrqTypeDef frq)
{
    GPIOModeSet((GPIOPortTypeDef)port, (GPIOPinTypeDef)pin, (GPIOModeTypeDef)mode);
    GPIODriveSet((GPIOPortTypeDef)port, (GPIODriveTypeDef)drive);
}

void DevGPIOIntConfig (DevGPIOPortTypeDef port, DevGPIOPinTypeDef pin, DevGPIOIntTypeDef type)
{
    GPIOIntConfig((GPIOPortTypeDef)port, (GPIOPinTypeDef)pin, (GPIOIntTypeDef)type);
}

void DevGPIOIntRegister (DevGPIOPortTypeDef port, DevGPIOPinTypeDef pin, FNCT_VOID isr)
{ 
    CPU_INT8U n;
    
    if (pin < DEV_GPIO_PIN_8)
    {
        n = MapTbl[(CPU_INT8U)pin];
    }
    else
    {
        n = MapTbl[(CPU_INT8U)(pin >> 8)] + 8;
    }
    
    if (n < GPIO_PIN_NUM) 
    {
        DevGPIOIntVectTbl[n] = isr;
    }
}

void GPIOIntUnregister (DevGPIOPortTypeDef port, DevGPIOPinTypeDef pin)
{ 
    CPU_INT8U n;
    
    if (pin < DEV_GPIO_PIN_8)
    {
        n = MapTbl[(CPU_INT8U)pin];
    }
    else
    {
        n = MapTbl[(CPU_INT8U)(pin >> 8)] + 8;
    }
    
    if (n < GPIO_PIN_NUM) 
    {
        DevGPIOIntVectTbl[n] = IntHandlerDefault;
    }
}

CPU_INT8U DevGPIOIntEnable (DevGPIOPortTypeDef port, DevGPIOPinTypeDef pin)
{
    if (!(pin & DEV_GPIO_PIN_IRQ_MASK))
    {
        return DEV_INT_IRQ_ERROR;
    }
    
    if (pin & DevGPIOIrqRegisterFlag)
    {
        return DEV_INT_IRQ_REGISTERED;
    }
    
    GPIOIntClear((GPIOPinTypeDef)pin);
    
    GPIOIntEnable((GPIOPinTypeDef)pin);

    DevGPIOIrqRegisterFlag |= pin;
    
    if (pin & GPIO_ODD_PIN_MASK)
    {
        IntEnable(INT_GPIO_ODD);
    }   
    else
    {
        IntEnable(INT_GPIO_EVEN);
    }
    
    return DEV_INT_IRQ_OK;
}

CPU_INT8U DevGPIOIntClear (DevGPIOPortTypeDef port, DevGPIOPinTypeDef pin)
{
    
    GPIOIntClear((GPIOPinTypeDef)pin);
    
    return DEV_INT_IRQ_OK;
}

CPU_INT8U DevGPIOIntDisable (DevGPIOPortTypeDef port, DevGPIOPinTypeDef pin)
{
    if (!(pin & DEV_GPIO_PIN_IRQ_MASK))
    {
        return DEV_INT_IRQ_ERROR;
    }
    
    GPIOIntClear((GPIOPinTypeDef)pin);

    GPIOIntDisable((GPIOPinTypeDef)pin);
    
    DevGPIOIrqRegisterFlag &= ~pin;
    
    if (pin & GPIO_ODD_PIN_MASK)
    {
        if (DevGPIOIrqRegisterFlag & GPIO_ODD_PIN_MASK)
        {
            IntDisable(INT_GPIO_ODD);
        }
    }   
    else
    {
        if (DevGPIOIrqRegisterFlag & GPIO_EVEN_PIN_MASK)
        {
            IntDisable(INT_GPIO_EVEN);
        }
    }
    
    return DEV_INT_IRQ_OK;
}

void DevGPIOIntInit (void)
{
    CPU_INT32U pin;

    for (pin = 0; pin < DEV_GPIO_PIN_IRQ_NUM; pin++) 
    {
        DevGPIOIntRegister(DEV_GPIO_PORTA, (DevGPIOPinTypeDef)(1 << pin), IntHandlerDefault);
    }
    
    IntVectRegister(INT_GPIO_ODD, GPIOOddPinIntHandler);
    IntVectRegister(INT_GPIO_EVEN, GPIOEvenPinIntHandler);
    
    DevGPIOIrqRegisterFlag = DEF_ZERO;
}

void GPIOOddPinIntHandler (void)
{
    FNCT_VOID isr;
    CPU_INT32U flag;
    CPU_INT32U pin;
    
    flag = GPIOIntGet();
    GPIOIntClear(flag);
    flag = flag & GPIO_ODD_PIN_MASK;
    flag = flag & DevGPIOIrqRegisterFlag;
    
    while ((CPU_INT8U)flag != DEF_ZERO)
    {
        pin = MapTbl[(CPU_INT8U)flag];
        
        isr = DevGPIOIntVectTbl[pin];
        isr();
        
        flag &= ~(1 << pin);
    }
    
    while ((CPU_INT8U)(flag >> 8) != DEF_ZERO)
    {
        pin = MapTbl[(CPU_INT8U)(flag >> 8)] + 8;
        
        isr = DevGPIOIntVectTbl[pin];
        isr();
        
        flag &= ~(1 << pin);
    }
}

void GPIOEvenPinIntHandler (void)
{
    FNCT_VOID isr;
    CPU_INT32U flag;
    CPU_INT32U pin;
    
    flag = GPIOIntGet();
    GPIOIntClear(flag);
    flag = flag & GPIO_EVEN_PIN_MASK;
    flag = flag & DevGPIOIrqRegisterFlag;
    
    while ((CPU_INT8U)flag != DEF_ZERO)
    {
        pin = MapTbl[(CPU_INT8U)flag];
        
        isr = DevGPIOIntVectTbl[pin];
        isr();
        
        flag &= ~(1 << pin);
    }
    
    while ((CPU_INT8U)(flag >> 8) != DEF_ZERO)
    {
        pin = MapTbl[(CPU_INT8U)(flag >> 8)] + 8;
        
        isr = DevGPIOIntVectTbl[pin];
        isr();
        
        flag &= ~(1 << pin);
    }
}


/*************************************************************************************************************
*                                                  END FILE                                                  *
*************************************************************************************************************/