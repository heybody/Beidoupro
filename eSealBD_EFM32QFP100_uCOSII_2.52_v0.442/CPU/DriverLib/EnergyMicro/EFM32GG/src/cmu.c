/*************************************************************************************************************
*                                              INCLUDE FILES                                                 *
*************************************************************************************************************/
#include <efm32.h>


/*************************************************************************************************************
*                                              LOCAL TABLES                                                  *
*************************************************************************************************************/
static CPU_INT32U CMUStatus;


/*************************************************************************************************************
*                                            FUNCTION PROTOTYPES                                             *
*************************************************************************************************************/
void CMUHFXOModeSel (CMUHFXOModeSelTypeDef sel)
{
    CMU->CTRL = (CMU->CTRL & ~CMU_CTRL_HFXOMODE_MASK) | sel;
}

void CMUHFXOBoostSet (CMUHFXOBoostTypeDef pcent)
{
    CMU->CTRL = (CMU->CTRL & ~CMU_CTRL_HFXOBOOST_MASK) | pcent;
}

void CMUHFXOTimeoutSet (CMUHFXOTimeoutTypeDef time)
{
    CMU->CTRL = (CMU->CTRL & ~CMU_CTRL_HFXOTIMEOUT_MASK) | time;
}

void CMULFXOModeSel (CMULFXOModeSelTypeDef sel)
{
    CMU->CTRL = (CMU->CTRL & ~CMU_CTRL_LFXOMODE_MASK) | sel;
}

void CMULFXOBoostSet (CMULFXOBoostTypeDef pcent)
{
    CMU->CTRL = (CMU->CTRL & ~CMU_CTRL_LFXOBOOST_MASK) | pcent;
}

void CMUHFCLKDivSet (CPU_INT32U value)
{
    CMU->CTRL = (CMU->CTRL & ~CMU_CTRL_HFCLKDIV_MASK);
    
    CMU->CTRL  = value;
}

void CMULFXOTimeoutSet (CMULFXOTimeoutTypeDef time)
{
    CMU->CTRL = (CMU->CTRL & ~CMU_CTRL_LFXOTIMEOUT_MASK) | time;
}

CPU_INT32U CMUCalibrate (CPU_INT32U count, CMUOscTypeDef osc)
{
    /* Set reference clock source */
    switch (osc)
    {
        case OscHFXO:       CMU->CALCTRL = CMU_CALCTRL_UPSEL_LFXO;
                            break;
        case OscLFXO:       CMU->CALCTRL = CMU_CALCTRL_UPSEL_LFRCO;
                            break;
        case OscHFRCO:      CMU->CALCTRL = CMU_CALCTRL_UPSEL_HFXO;
                            break;
        case OscLFRCO:      CMU->CALCTRL = CMU_CALCTRL_UPSEL_HFRCO;
                            break;
        case OscAUXHFRCO:   CMU->CALCTRL = CMU_CALCTRL_UPSEL_AUXHFRCO;
                            break;
        default:            return 0;
    }

    CMU->CALCNT = count;    /* Set top value */
   
    CMU->CMD = CMU_CMD_CALSTART;    /* Start calibration */

    while (CMU->STATUS & CMU_STATUS_CALBSY);    /* Wait until calibration completes */  

    return CMU->CALCNT;
}

void CMUHFCLKSelectSet (CMUHFCLKSourceTypeDef source)
{
    CPU_INT32U freq;
    
    MSCFlashWaitStateControl(MSC_MAX_FREQ_0WS + 1);

    CMU->CMD = source;

    CMUStatusUpdata();
    
    freq = CMUHFCoreClockGet();

    MSCFlashWaitStateControl(freq);
}

void CMUHFCoreClockSet (CMUHFCOREClockDivTypeDef div)
{
    CMU->HFCORECLKDIV = (CMU->HFCORECLKDIV & ~CMU_HFCORECLKDIV_HFCORECLKDIV_MASK) | div;
}

void CMUHFPeripheralClockSet (CMUHFPERClockDivTypeDef div)
{
    
    CMU->HFPERCLKDIV = (CMU->HFPERCLKDIV & ~CMU_HFPERCLKDIV_HFPERCLKDIV_MASK) | div;
}

void CMULFARTCClockSet (CMULFARTCClockDivTypeDef div)
{
    CMU->LFAPRESC0 = (CMU->LFAPRESC0 & ~CMU_LFAPRESC0_RTC_MASK) | div;
}

void CMULFALETIMER0ClockSet (CMULFALETIMER0ClockDivTypeDef div)
{
    CMU->LFAPRESC0 = (CMU->LFAPRESC0 & ~CMU_LFAPRESC0_LETIMER0_MASK) | div;
}

void CMULFALCDClockSet (CMULFALCDClockDivTypeDef div)
{
    CMU->LFAPRESC0 = (CMU->LFAPRESC0 & ~CMU_LFAPRESC0_LCD_MASK) | div;
}

void CMULFBLEUART0ClockSet (CMULFBLEUART0ClockDivTypeDef div)
{
    CMU->LFBPRESC0 = (CMU->LFBPRESC0 & ~CMU_LFBPRESC0_LEUART0_MASK) | div;
}

void CMULFBLEUART1ClockSet (CMULFBLEUART1ClockDivTypeDef div)
{
    CMU->LFBPRESC0 = (CMU->LFBPRESC0 & ~CMU_LFBPRESC0_LEUART1_MASK) | div;
}

CPU_INT32U CMUHFRCOFreqGet (void)
{
    CPU_INT32U ret;
    
    switch (CMU->HFRCOCTRL & CMU_HFRCOCTRL_BAND_MASK)
    {
        case CMU_HFRCOCTRL_BAND_28MHZ:  ret = HFRCO_FREQ_28MHZ;
                                        break;
        case CMU_HFRCOCTRL_BAND_21MHZ:  ret = HFRCO_FREQ_21MHZ;
                                        break;
        case CMU_HFRCOCTRL_BAND_14MHZ:  ret = HFRCO_FREQ_14MHZ;
                                        break;
        case CMU_HFRCOCTRL_BAND_11MHZ:  ret = HFRCO_FREQ_11MHZ;
                                        break;
        case CMU_HFRCOCTRL_BAND_7MHZ:   ret = HFRCO_FREQ_7MHZ;
                                        break;
        case CMU_HFRCOCTRL_BAND_1MHZ:   ret = HFRCO_FREQ_1MHZ;
                                        break;
        default:                        ret = 0;
                                        break;
    }
    
    return ret;
}

CPU_INT32U CMUHFClockGet (void)
{
    CPU_INT32U ret;
  
    switch (CMU->STATUS & (CMU_STATUS_HFRCOSEL | CMU_STATUS_HFXOSEL | CMU_STATUS_LFRCOSEL | CMU_STATUS_LFXOSEL))
    {
        case CMU_STATUS_LFXOSEL:    ret = LFXO_FREQ;
                                    break;
        case CMU_STATUS_LFRCOSEL:   ret = LFRCO_FREQ;
                                    break;
        case CMU_STATUS_HFXOSEL:    ret = HFXO_FREQ;;
                                    break;
        case CMU_STATUS_HFRCOSEL:   ret = CMUHFRCOFreqGet();
                                    break;
        default:                    ret = 0;
                                    break;
    }

    return ret;
}

CPU_INT32U CMUHFCoreClockGet (void)
{
    CPU_INT32U ret;
  
    ret = CMUHFClockGet();
  
    ret >>= CMU->HFCORECLKDIV & CMU_HFCORECLKDIV_MASK;
  
    return ret;
}

CPU_INT32U CMUHFPeripheralClockGet (void)
{
    CPU_INT32U ret;
  
    ret = CMUHFClockGet();
  
    ret >>= CMU->HFPERCLKDIV & CMU_HFPERCLKDIV_HFPERCLKDIV_MASK;
  
    return ret;
}

CPU_INT32U CMULFClockGet (CMULFClockTypeDef clock)
{
    CPU_INT32U ret;
    
    switch ((CMU->LFCLKSEL >> clock) & 0x3UL)
    {
        case CMU_LFCLKSEL_LFA_DISABLED:         ret = 0;
                                                break;
        case CMU_LFCLKSEL_LFA_LFRCO:            ret = LFRCO_FREQ;
                                                break;
        case CMU_LFCLKSEL_LFA_LFXO:             ret = LFXO_FREQ;
                                                break;
        case CMU_LFCLKSEL_LFA_HFCORECLKLEDIV2:  ret = CMUHFCoreClockGet() / 2;
                                                break;
        default:                                ret = 0;
                                                break;
    }
    
    return ret;
}

CPU_INT32U CMULFAPeripheralClockGet (CMULEAClockTypeDef lea)
{
    CPU_INT32U ret;
    
    ret = CMULFClockGet(LFAClock);
    
    switch (lea)
    {
        case RTCClock:      ret >>= ((CMU->LFAPRESC0 & CMU_LFAPRESC0_RTC_MASK) >> CMU_LFAPRESC0_RTC_SHIFT);
                            break;
        case LETIMER0Clock: ret >>= ((CMU->LFAPRESC0 & CMU_LFAPRESC0_LETIMER0_MASK) >> CMU_LFAPRESC0_LETIMER0_SHIFT);
                            break;
        case LCDClock:      ret >>= ((CMU->LFAPRESC0 & CMU_LFAPRESC0_LCD_MASK) >> CMU_LFAPRESC0_LCD_SHIFT);
                            ret >>= 4;
                            break;
        default:            ret = 0;
                            break;
    }
    
    return ret;
}

CPU_INT32U CMULFBPeripheralClockGet (CMULEBClockTypeDef leb)
{
    CPU_INT32U ret;
    
    ret = CMULFClockGet(LFBClock);
    
    switch (leb)
    {
        case LEUART0Clock:  ret >>= ((CMU->LFBPRESC0 & CMU_LFBPRESC0_LEUART0_MASK) >> CMU_LFBPRESC0_LEUART0_SHIFT);
                            break;
        case LEUART1Clock:  ret >>= ((CMU->LFBPRESC0 & CMU_LFBPRESC0_LEUART1_MASK) >> CMU_LFBPRESC0_LEUART1_SHIFT);
                            break;  
        default:            ret = 0;
                            break;
    }
    
    return ret;
}

void CMUHFRCOFrqSet (CMUHFRCOBandTypeDef band)
{
    CPU_INT32U cal;
    CPU_INT32U freq;

    cal = DEVINFOHFRCOBandCalGet(band); /* Read value from calibration table */
    
    if (cal == 0xFFFFFFFF)
    {
        return;
    }
  
    /* If HFRCO is used for core clock, we have to consider flash access WS. */
    if (CMU->STATUS & CMU_STATUS_HFRCOSEL )
    {
        /* Configure worst case wait states for flash access before setting divider */
        MSCFlashWaitStateControl(MSC_MAX_FREQ_0WS + 1);
    }
    
    CMU->HFRCOCTRL = (CMU->HFRCOCTRL & ~(CMU_HFRCOCTRL_BAND_MASK | CMU_HFRCOCTRL_TUNING_MASK)) 
                   | (band  | (cal << CMU_HFRCOCTRL_TUNING_SHIFT)); /* Set band/tuning */

    /* If HFRCO is used for core clock, optimize flash WS */
    if (CMU->STATUS & CMU_STATUS_HFRCOSEL )
    {
        freq = CMUHFCoreClockGet();

        MSCFlashWaitStateControl(freq);
    }
}

void CMUHFRCOStartupDelaySet (CPU_INT32U val)
{
    CMU->HFRCOCTRL = (CMU->HFRCOCTRL & ~CMU_HFRCOCTRL_SUDELAY_MASK) 
                   | ((val & (CMU_HFRCOCTRL_SUDELAY_MASK >> CMU_HFRCOCTRL_SUDELAY_SHIFT)) << CMU_HFRCOCTRL_SUDELAY_SHIFT);
}

CPU_INT32U CMUHFRCOStartupDelayGet (void)
{
    return ((CMU->HFRCOCTRL & CMU_HFRCOCTRL_SUDELAY_MASK) >> CMU_HFRCOCTRL_SUDELAY_SHIFT);
}

void CMULCDClkFDIVSet (CPU_INT32U div)
{
    /* Do not allow modification if LCD clock enabled */
    if (CMU->LFACLKEN0 & CMU_LFACLKEN0_LCD)
    {
        return;
    }

    CMU->LCDCTRL = (CMU->LCDCTRL & ~CMU_LCDCTRL_FDIV_MASK) | ((div << CMU_LCDCTRL_FDIV_SHIFT) & CMU_LCDCTRL_FDIV_MASK);
}

CPU_INT32U CMULCDClkFDIVGet (void)
{

    return ((CMU->LCDCTRL & CMU_LCDCTRL_FDIV_MASK) >> CMU_LCDCTRL_FDIV_SHIFT);
}

void CMUOscillatorTuningSet (CMUOscTypeDef osc, CPU_INT32U val)
{
    switch (osc)
    {
        case OscLFRCO:      val &= (CMU_LFRCOCTRL_TUNING_MASK >> CMU_LFRCOCTRL_TUNING_SHIFT); 
                            CMU->LFRCOCTRL = (CMU->LFRCOCTRL & ~CMU_LFRCOCTRL_TUNING_MASK) 
                                           | (val << CMU_LFRCOCTRL_TUNING_SHIFT);
                            break;
        case OscHFRCO:      val &= (CMU_HFRCOCTRL_TUNING_MASK >> CMU_HFRCOCTRL_TUNING_SHIFT);
                            CMU->HFRCOCTRL = (CMU->HFRCOCTRL & ~CMU_HFRCOCTRL_TUNING_MASK) 
                                           | (val << CMU_HFRCOCTRL_TUNING_SHIFT);
                            break;
        case OscAUXHFRCO:   val &= (CMU_AUXHFRCOCTRL_TUNING_MASK >> CMU_AUXHFRCOCTRL_TUNING_SHIFT);
                            CMU->AUXHFRCOCTRL = (CMU->AUXHFRCOCTRL & ~CMU_AUXHFRCOCTRL_TUNING_MASK)
                                              | (val << CMU_AUXHFRCOCTRL_TUNING_SHIFT);
                            break;

        default:            break;
    }
}

CPU_INT32U CMUOscillatorTuningGet (CMUOscTypeDef osc)
{
    CPU_INT32U ret;

    switch (osc)
    {
        case OscLFRCO:      ret = (CMU->LFRCOCTRL & CMU_LFRCOCTRL_TUNING_MASK) >> CMU_LFRCOCTRL_TUNING_SHIFT;
                            break;

        case OscHFRCO:      ret = (CMU->HFRCOCTRL & CMU_HFRCOCTRL_TUNING_MASK) >> CMU_HFRCOCTRL_TUNING_SHIFT;
                            break;
        case OscAUXHFRCO:   ret = (CMU->AUXHFRCOCTRL & CMU_AUXHFRCOCTRL_TUNING_MASK) >> CMU_AUXHFRCOCTRL_TUNING_SHIFT;
                            break;
        default:            ret = 0;
                            break;
    }

    return ret;
}

void CMUPCNTClockSel (CMUPCNTClockTypeDef clock, CMUPCNTClockSelTypeDef sel)
{
    CMU->PCNTCTRL = (CMU->PCNTCTRL & ~(CMU_PCNTCTRL_PCNT0CLKEN_MASK << clock)) | (sel << clock);
}

void CMUCLKOUTLocationSet (CMUCLKOUTLocationTypeDef locatoin)
{
    CMU->ROUTE = (CMU->ROUTE & ~CMU_ROUTE_LOCATION_MASK) | locatoin;
}

void CMUCLKOUT0Sel (CMUCLKOUT0SelTypeDef sel)
{
    CMU->CTRL = (CMU->CTRL & ~CMU_CTRL_CLKOUTSEL0_MASK) | sel;
}

void CMUCLKOUT1Sel (CMUCLKOUT1SelTypeDef sel)
{
    CMU->CTRL = (CMU->CTRL & ~CMU_CTRL_CLKOUTSEL1_MASK) | sel;
}

void CMUHFCOREClkEDivFactorSet (CMUHFCOREClkEDivTypeDef factor)
{
    CMU->CTRL = (CMU->CTRL & ~CMU_HFCORECLKDIV_HFCORECLKLEDIV_MASK) | factor;
}

void AUXHFRCOBandSelectSet (CMUAUXHFRCOBandSelTypeDef sel)
{
    CMU->AUXHFRCOCTRL = (CMU->AUXHFRCOCTRL & ~CMU_AUXHFRCOCTRL_BAND_MASK) | sel;
}

void CalibrationUpcounterSelectSet (CMUCALUpcounterSelTypeDef sel)
{
    CMU->CMD = (CMU->CMD & ~CMU_CALCTRL_UPSEL_MASK) | sel;
}

void CalibrationDowncounterSelectSet (CMUCALDowncounterSelTypeDef sel)
{
    CMU->CMD = (CMU->CMD & ~CMU_CALCTRL_DOWNSEL_MASK) | sel;
}

void USBCoreClockSelectSet (CMUUSBCoreClockSelTypeDef sel)
{
    CMU->CMD = (CMU->CMD & ~CMU_CMD_USBCCLKSEL_MASK) | sel;
}

void CMUStatusUpdata (void)
{
    CMUStatus = (CPU_INT32U)(CMU->STATUS);  /* Fetch current configuration */
}

void CMUStatusRestore (void)
{
    CPU_INT32U lock_status;

    /* CMU registers may be locked */
    lock_status = CMU->LOCK & CMU_LOCK_LOCKKEY_LOCKED;
    if (lock_status)
    {
        CMUUnlock();
    }

    /* AUXHFRCO was automatically disabled (except if using debugger). */
    /* HFXO was automatically disabled. */
    /* LFRCO/LFXO were possibly disabled by SW in EM3. */
    /* Restore according to status prior to entering EM. */
    CMU->OSCENCMD = CMUStatus & (CMU_STATUS_AUXHFRCOENS | CMU_STATUS_HFXOENS 
                              | CMU_STATUS_LFRCOENS | CMU_STATUS_LFXOENS);

    /* Restore oscillator used for clocking core */
    switch (CMUStatus & (CMU_STATUS_HFXOSEL | CMU_STATUS_HFRCOSEL 
                      | CMU_STATUS_LFXOSEL | CMU_STATUS_LFRCOSEL))
    {
        case CMU_STATUS_LFRCOSEL:   while (!(CMU->STATUS & CMU_STATUS_LFRCORDY));    /* Wait for LFRCO to stabilize */
                                    CMU->CMD = CMU_CMD_HFCLKSEL_LFRCO;
                                    break;
        case CMU_STATUS_LFXOSEL:    while (!(CMU->STATUS & CMU_STATUS_LFXORDY));    /* Wait for LFXO to stabilize */
                                    CMU->CMD = CMU_CMD_HFCLKSEL_LFXO;
                                    break;
        case CMU_STATUS_HFXOSEL:    while (!(CMU->STATUS & CMU_STATUS_HFXORDY));    /* Wait for HFXO to stabilize */
                                    CMU->CMD = CMU_CMD_HFCLKSEL_HFXO;
                                    break;
        default:                    break;  /* CMU_STATUS_HFRCOSEL */
                                            /* If core clock was HFRCO core clock, it is automatically restored 
                                               to state prior to entering energy mode. No need for further action. */
    }

    /* Restore CMU register locking */
    if (lock_status)
    {
        CMULock();
    }
}

void CMUSOscLFDisable (void)
{
    CPU_INT32U lock_status;

    /* CMU registers may be locked */
    lock_status = CMU->LOCK & CMU_LOCK_LOCKKEY_LOCKED;
    if (lock_status)
    {
        CMUUnlock();
    }
    
    CMUOscillatorDisable(OscLFRCO);
    CMUOscillatorDisable(OscLFXO);
    
    /* Restore CMU register locking */
    if (lock_status)
    {
        CMULock();
    }
}

                       
/*************************************************************************************************************
*                                                  END FILE                                                  *
*************************************************************************************************************/