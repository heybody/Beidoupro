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
static FNCT_VOID DevClockIntVectTbl[DEV_CLOCK_IRQ_NUM];
static volatile CPU_INT32U DevClockIrqRegisterFlag;


/*************************************************************************************************************
*                                            FUNCTION PROTOTYPES                                             *
*************************************************************************************************************/
void DevClockInit (void)
{
    CMUHFRCOFrqSet(HFRCO_BAND_14MHZ);
    CMUHFCoreClockSet(HFCORECLK_HFCLK);
    CMUHFCLKSelectSet(HFClkHFRCOSource);                     
    
    CMULFCLKEnable(LFAClock, LFClkHFCoreClkLEDivSource);
    CMULFCLKEnable(LFBClock, LFClkHFCoreClkLEDivSource);
    
    CMULFBLEUART0ClockSet(LFB_LEUART0_LFBCLK_DIV8);
    CMULFBLEUART1ClockSet(LFB_LEUART1_LFBCLK_DIV8);
    
    CMUHFPERCLKEnable();
    CMUHFCOREClockEnable(LEClock);
    
    CMUOscillatorEnable(OscLFRCO);
}

CPU_INT32U DevClockHSIGet (void)
{
    return CMUHFRCOFreqGet();
}

CPU_INT32U DevClockHSEGet (void)
{
    return HFXO_FREQ;
}

CPU_INT32U DevClockLSIGet (void)
{
    return LFRCO_FREQ;
}

CPU_INT32U DevClockLSEGet (void)
{
    return LFXO_FREQ;
}

CPU_INT32U DevClockCoreGet (void)
{
    return CMUHFCoreClockGet();
}

CPU_INT8U DevClockIntRegister (DevClockIrqTypeDef irq, FNCT_VOID isr)
{ 
    CPU_INT8U n;
    
    if (!(irq & DEV_CLOCK_IRQ_MASK))
    {
        return DEV_INT_IRQ_ERROR;
    }
    
    if (irq & DevClockIrqRegisterFlag)
    {
        return DEV_INT_IRQ_REGISTERED;
    }
    
    DevClockIrqRegisterFlag |= irq;
    
    n = MapTbl[(CPU_INT8U)irq];
    
    DevClockIntVectTbl[n] = isr;
    
    return DEV_INT_IRQ_OK;
}

CPU_INT8U DevClockIntUnregister (DevClockIrqTypeDef irq)
{ 
    CPU_INT8U n;
    
    if (!(irq & DEV_CLOCK_IRQ_MASK))
    {
        return DEV_INT_IRQ_ERROR;
    }
    
    DevClockIrqRegisterFlag &= ~irq;
    
    n = MapTbl[(CPU_INT8U)irq];
    
    DevClockIntVectTbl[n] = IntHandlerDefault;
    
    return DEV_INT_IRQ_OK;
}

CPU_INT8U DevClockIntEnable (DevClockIrqTypeDef irq)
{
    if (!(irq & DEV_CLOCK_IRQ_MASK))
    {
        return DEV_INT_IRQ_ERROR;
    }
    
    CMUIntEnable(irq);

    IntEnable(INT_CMU);
    
    return DEV_INT_IRQ_OK;
}

CPU_INT8U DevClockIntDisable (DevClockIrqTypeDef irq)
{
    if (!(irq & DEV_CLOCK_IRQ_MASK))
    {
        return DEV_INT_IRQ_ERROR;
    }
    
    CMUIntDisable(irq);
    
    if (!(DevClockIrqRegisterFlag & DEV_CLOCK_IRQ_MASK))
    {
        IntDisable(INT_CMU);
    }
    
    return DEV_INT_IRQ_OK;
}

void DevClockIntInit (void)
{
    CPU_INT32U irq;

    for (irq = 0; irq < DEV_CLOCK_IRQ_NUM; irq++) 
    {
        DevClockIntRegister((DevClockIrqTypeDef)irq, IntHandlerDefault);
    }
    
    IntVectRegister(INT_CMU, DevClockIntHandler);
    
    DevClockIrqRegisterFlag = DEF_ZERO;
}

void DevClockIntHandler (void)
{
    FNCT_VOID isr;
    CPU_INT32U flag;
    CPU_INT8U n;
    
    flag = CMUIntGet();
    CMUIntClear(flag);
    flag = flag & DevClockIrqRegisterFlag;
    
    while ((CPU_INT8U)flag != DEF_ZERO)
    {
        n = MapTbl[(CPU_INT8U)flag];
        
        isr = DevClockIntVectTbl[n];
        isr();
        
        flag &= ~(1 << n);
    }
}


/*************************************************************************************************************
*                                                  END FILE                                                  *
*************************************************************************************************************/