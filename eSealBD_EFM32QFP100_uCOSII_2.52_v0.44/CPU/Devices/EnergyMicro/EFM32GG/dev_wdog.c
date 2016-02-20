/*************************************************************************************************************
*                                              INCLUDE FILES                                                 *
*************************************************************************************************************/
#include <dev.h>

/*************************************************************************************************************
*                                                CONSTANTS                                                   *
*************************************************************************************************************/
const DevWatchDogTableTypeDef  DevWatchDogTable[DEV_WDOG_NUM] = 
{
    {
        .x    = WDOG_0,\
    },\
};

/*************************************************************************************************************
*                                            FUNCTION PROTOTYPES                                             *
*************************************************************************************************************/
void DevWatchDogClockEnable (DevWatchDogTypeDef n)
{
    WDOGClockEnable((WDOGTypeDef)DevWatchDogTable[n].x);
}

void DevWatchDogClockDisable (DevWatchDogTypeDef n)
{
    WDOGClockDisable((WDOGTypeDef)DevWatchDogTable[n].x);
}

void DevWatchDogEnable (DevWatchDogTypeDef n)
{
    if (WDOGTimerFlagGet((WDOGTypeDef)DevWatchDogTable[n].x) == DEF_OFF)
    {
        while (WDOGSyncBusyStatusFlagGet((WDOGTypeDef)DevWatchDogTable[n].x, WDOG_SYNCBUSY_SYNCHRONIZE_CTRL));
    }
    WDOGTimerEnable((WDOGTypeDef)DevWatchDogTable[n].x);
}

void DevWatchDogDisable (DevWatchDogTypeDef n)
{
    if (WDOGTimerFlagGet((WDOGTypeDef)DevWatchDogTable[n].x) == DEF_ON)
    {
        while (WDOGSyncBusyStatusFlagGet((WDOGTypeDef)DevWatchDogTable[n].x, WDOG_SYNCBUSY_SYNCHRONIZE_CTRL));
    }
    WDOGTimerDisable((WDOGTypeDef)DevWatchDogTable[n].x);
}

void DevWatchDogInit (DevWatchDogTypeDef n, WatchDogTimeOutTypeDef value)
{
    WDOGClockEnable((WDOGTypeDef)DevWatchDogTable[n].x);
    while (WDOGSyncBusyStatusFlagGet((WDOGTypeDef)DevWatchDogTable[n].x, WDOG_SYNCBUSY_SYNCHRONIZE_CTRL));
    WDOGConfigurationLockDisable((WDOGTypeDef)DevWatchDogTable[n].x);
    WDOGTimerEnable((WDOGTypeDef)DevWatchDogTable[n].x);
    WDOGClockSelectModeSet((WDOGTypeDef)DevWatchDogTable[n].x, WDOG_CTRL_CLK_LFRCO);
    WDOGTimeoutPeriodSelectSet((WDOGTypeDef)DevWatchDogTable[n].x, value); 
    
    WDOGEnergyMode2Enable((WDOGTypeDef)DevWatchDogTable[n].x);
    WDOGEnergyMode3Enable((WDOGTypeDef)DevWatchDogTable[n].x);
    WDOGDebugModeRunDisable((WDOGTypeDef)DevWatchDogTable[n].x);
//    WDOGDebugModeRunEnable((WDOGTypeDef)DevWatchDogTable[n].x);
}

void DevWatchDogFeed (DevWatchDogTypeDef n)
{
   if (WDOGTimerClearModeGet((WDOGTypeDef)DevWatchDogTable[n].x) == WDOG_CMD_CLEARED)
       return;
   WDOGTimerClearModeSet((WDOGTypeDef)DevWatchDogTable[n].x, WDOG_CMD_CLEARED); 
}

void DevWatchDogLock (DevWatchDogTypeDef n)
{
    while (WDOGSyncBusyStatusFlagGet((WDOGTypeDef)DevWatchDogTable[n].x, WDOG_SYNCBUSY_SYNCHRONIZE_CTRL));
    WDOGConfigurationLockEnable((WDOGTypeDef)DevWatchDogTable[n].x);
}


/*************************************************************************************************************
*                                                  END FILE                                                  *
*************************************************************************************************************/