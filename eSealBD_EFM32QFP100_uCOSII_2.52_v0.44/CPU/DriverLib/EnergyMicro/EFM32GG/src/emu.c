/*************************************************************************************************************
*                                              INCLUDE FILES                                                 *
*************************************************************************************************************/
#include <efm32.h>


/*************************************************************************************************************
*                                            FUNCTION PROTOTYPES                                             *
*************************************************************************************************************/
void EMUUpdataConfig (void)
{
    CMUStatusUpdata();
}

void EMURestore (void)
{
    CMUStatusRestore();
}

void EMUEnterEM1 (void)
{
    CM3CoreSleep(); /* Just enter Cortex-M3 sleep mode */
}

void EMUEnterEM2 (void)
{
    EMUUpdataConfig();

    CM3CoreDeepSleep(); /* Enter Cortex-M3 deep sleep mode */
    
    EMURestore();
}

void EMUEnterEM3 (void)
{
    EMUUpdataConfig();

    /* Disable LF oscillators */
    CMUSOscLFDisable();

    CM3CoreDeepSleep(); /* Enter Cortex-M3 deep sleep mode */
    
    EMURestore();
}

void EMUEnterEM4 (void)
{
    CPU_INT32U i;

    /* Make sure register write lock is disabled */
    EMU->LOCK = EMU_LOCK_LOCKKEY_UNLOCK;

    for (i = 0; i < 4; i++)
    {
        EMU->CTRL = (2 << EMU_CTRL_EM4CTRL_SHIFT);
        EMU->CTRL = (3 << EMU_CTRL_EM4CTRL_SHIFT);
    }
    EMU->CTRL = (2 << EMU_CTRL_EM4CTRL_SHIFT);
}

void EMUMemPwrDown (EMUPowerDownRAMTypeDef blocks)
{
    EMU->MEMCTRL = blocks;
}

void EMUResetCauseClear (void)
{
    CPU_INT32U lock_status;

    /* EMU registers may be locked */
    lock_status = EMU->LOCK & EMU_LOCK_LOCKKEY_LOCKED;
    if (lock_status)
    {
        EMUUnlock();
    }

    EMU->CTRL |= EMU_AUXCTRL_HRCCLR;
    EMU->CTRL &= ~EMU_AUXCTRL_HRCCLR;

    if (lock_status)
    {
        EMULock();
    }
}


/*************************************************************************************************************
*                                                  END FILE                                                  *
*************************************************************************************************************/
