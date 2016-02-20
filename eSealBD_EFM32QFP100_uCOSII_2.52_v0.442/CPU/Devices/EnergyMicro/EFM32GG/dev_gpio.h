/*************************************************************************************************************
*                                                  MODULE                                                    *
*************************************************************************************************************/
#ifndef DEV_GPIO_H
#define DEV_GPIO_H

#ifdef __cplusplus
extern "C" {
#endif

/*************************************************************************************************************
*                                                 DEFINES                                                    *
*************************************************************************************************************/
#define DEV_GPIO_PIN_IRQ_NUM                    GPIO_PIN_NUM
#define DEV_GPIO_PIN_IRQ_MASK                   (GPIO_ODD_PIN_MASK | GPIO_EVEN_PIN_MASK)
    
    
/*************************************************************************************************************
*                                                  DATA TYPES                                                *
*************************************************************************************************************/
typedef enum
{
    DEV_GPIO_PORTA = GPIO_PORTA, 
    DEV_GPIO_PORTB = GPIO_PORTB, 
    DEV_GPIO_PORTC = GPIO_PORTC, 
    DEV_GPIO_PORTD = GPIO_PORTD, 
    DEV_GPIO_PORTE = GPIO_PORTE, 
    DEV_GPIO_PORTF = GPIO_PORTF, 
} DevGPIOPortTypeDef;

typedef enum
{
    DEV_GPIO_PIN_0  = GPIO_PIN_0, 
    DEV_GPIO_PIN_1  = GPIO_PIN_1,                      
    DEV_GPIO_PIN_2  = GPIO_PIN_2, 
    DEV_GPIO_PIN_3  = GPIO_PIN_3,   
    DEV_GPIO_PIN_4  = GPIO_PIN_4,            
    DEV_GPIO_PIN_5  = GPIO_PIN_5,        
    DEV_GPIO_PIN_6  = GPIO_PIN_6,            
    DEV_GPIO_PIN_7  = GPIO_PIN_7,                
    DEV_GPIO_PIN_8  = GPIO_PIN_8,                
    DEV_GPIO_PIN_9  = GPIO_PIN_9,                   
    DEV_GPIO_PIN_10 = GPIO_PIN_10,                      
    DEV_GPIO_PIN_11 = GPIO_PIN_11,           
    DEV_GPIO_PIN_12 = GPIO_PIN_12,            
    DEV_GPIO_PIN_13 = GPIO_PIN_13,        
    DEV_GPIO_PIN_14 = GPIO_PIN_14,        
    DEV_GPIO_PIN_15 = GPIO_PIN_15,
} DevGPIOPinTypeDef;

typedef enum
{
    DEV_GPIO_PIN_MODE_DISABLE    = GPIO_MODE_DISABLED, 
    DEV_GPIO_PIN_MODE_IN         = GPIO_MODE_INPUT, 
    DEV_GPIO_PIN_MODE_IN_P       = GPIO_MODE_INPUTPULL, 
    DEV_GPIO_PIN_MODE_IN_PF      = GPIO_MODE_INPUTPULLFILTER, 
    DEV_GPIO_PIN_MODE_OUT_PP     = GPIO_MODE_PUSHPULL, 
    DEV_GPIO_PIN_MODE_OUT_PPD    = GPIO_MODE_PUSHPULLDRIVE, 
    DEV_GPIO_PIN_MODE_W_O        = GPIO_MODE_WIREDOR, 
    DEV_GPIO_PIN_MODE_W_OPD      = GPIO_MODE_WIREDORPULLDOWN,
    DEV_GPIO_PIN_MODE_OUT_OD     = GPIO_MODE_WIREDAND,
    DEV_GPIO_PIN_MODE_OUT_ODF    = GPIO_MODE_WIREDANDFILTER,
    DEV_GPIO_PIN_MODE_OUT_ODPU   = GPIO_MODE_WIREDANDPULLUP,
    DEV_GPIO_PIN_MODE_OUT_ODFPU  = GPIO_MODE_WIREDANDPULLUPFILTER,
    DEV_GPIO_PIN_MODE_OUT_ODD    = GPIO_MODE_WIREDANDDRIVE,
    DEV_GPIO_PIN_MODE_OUT_ODFD   = GPIO_MODE_WIREDANDDRIVEFILTER,
    DEV_GPIO_PIN_MODE_OUT_ODPUD  = GPIO_MODE_WIREDANDDRIVEFILTER,
    DEV_GPIO_PIN_MODE_OUT_ODFPUD = GPIO_MODE_WIREDANDDRIVEFILTER,
} DevGPIOPinModeTypeDef;

typedef enum
{
    DEV_GPIO_PIN_DRIVE_STANDARD = GPIO_DRIVE_STANDARD, 
    DEV_GPIO_PIN_DRIVE_LOWEST   = GPIO_DRIVE_LOWEST, 
    DEV_GPIO_PIN_DRIVE_HIGH     = GPIO_DRIVE_HIGH,
    DEV_GPIO_PIN_DRIVE_LOW      = GPIO_DRIVE_LOW,
} DevGPIOPinDriveTypeDef;

typedef enum
{
    DEV_GPIO_PIN_FRQ_NORMAL, 
} DevGPIOPinDFrqTypeDef;

typedef enum
{
    DEV_GPIO_FALLING_EDGE = GPIO_FALLING_EDGE, 
    DEV_GPIO_RISING_EDGE  = GPIO_RISING_EDGE, 
    DEV_GPIO_BOTH_EDGES   = GPIO_BOTH_EDGES,
} DevGPIOIntTypeDef;


/*************************************************************************************************************
*                                            FUNCTION PROTOTYPES                                             *
*************************************************************************************************************/
static inline void DevGPIOPinOutSet (DevGPIOPortTypeDef port, DevGPIOPinTypeDef pin)
{
    GPIOPinOutSet((GPIOPortTypeDef)port, (GPIOPinTypeDef)pin);
}

static inline void DevGPIOPinOutClear (DevGPIOPortTypeDef port, DevGPIOPinTypeDef pin)
{
    GPIOPinOutClear((GPIOPortTypeDef)port, (GPIOPinTypeDef)pin);
}

static inline void DevGPIOPinOutToggle (DevGPIOPortTypeDef port, DevGPIOPinTypeDef pin)
{
    GPIOPinOutToggle((GPIOPortTypeDef)port, (GPIOPinTypeDef)pin);
}

static inline CPU_BOOL DevGPIOPinOutGet (DevGPIOPortTypeDef port, DevGPIOPinTypeDef pin)
{
    return GPIOPinOutGet((GPIOPortTypeDef)port, (GPIOPinTypeDef)pin);
}

static inline CPU_BOOL DevGPIOPinInGet (DevGPIOPortTypeDef port, DevGPIOPinTypeDef pin)
{
    return GPIOPinInGet((GPIOPortTypeDef)port, (GPIOPinTypeDef)pin);
}

static inline void DevGPIOPinOutWrite (DevGPIOPortTypeDef port, CPU_INT16U data)
{
    GPIOPinOutWrite((GPIOPortTypeDef)port, data);
}

static inline CPU_INT16U DevGPIOPinOutRead (DevGPIOPortTypeDef port)
{
    return GPIOPinOutRead((GPIOPortTypeDef)port);
}

static inline CPU_INT16U DevGPIOPinInRead (DevGPIOPortTypeDef port)
{ 
    return GPIOPinInRead((GPIOPortTypeDef)port);
}


/*************************************************************************************************************
*                                            FUNCTION STATEMENT                                              *
*************************************************************************************************************/    
void DevGPIOInit (void);
void DevGPIOPinConfig (DevGPIOPortTypeDef port, DevGPIOPinTypeDef pin, DevGPIOPinModeTypeDef mode, 
                       DevGPIOPinDriveTypeDef drive, DevGPIOPinDFrqTypeDef frq);
void DevGPIOIntConfig (DevGPIOPortTypeDef port, DevGPIOPinTypeDef pin, DevGPIOIntTypeDef type);
void DevGPIOIntRegister (DevGPIOPortTypeDef port, DevGPIOPinTypeDef pin, FNCT_VOID isr);
void GPIOIntUnregister (DevGPIOPortTypeDef port, DevGPIOPinTypeDef pin);
CPU_INT8U DevGPIOIntEnable (DevGPIOPortTypeDef port, DevGPIOPinTypeDef pin);
CPU_INT8U DevGPIOIntDisable (DevGPIOPortTypeDef port, DevGPIOPinTypeDef pin);
CPU_INT8U DevGPIOIntClear (DevGPIOPortTypeDef port, DevGPIOPinTypeDef pin);
void DevGPIOIntInit (void);
void GPIOOddPinIntHandler (void);
void GPIOEvenPinIntHandler (void);

/*************************************************************************************************************
*                                               MODULE END                                                   *
*************************************************************************************************************/ 
#ifdef __cplusplus
}
#endif

#endif
