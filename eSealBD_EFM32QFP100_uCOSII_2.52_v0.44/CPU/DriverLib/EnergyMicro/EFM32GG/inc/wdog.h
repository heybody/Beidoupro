/*************************************************************************************************************
*                                                  MODULE                                                    *
*************************************************************************************************************/
#ifndef WDOG_H
#define WDOG_H

#ifdef __cplusplus
extern "C" {
#endif
    

/*************************************************************************************************************
*                                                 DEFINES                                                    *
*************************************************************************************************************/
#define WDOG                                    ((WDOGRegTypeDef *)WDOG_BASE)

/* Bit fields for WDOG CTRL */
#define WDOG_CTRL_RESETVALUE                    0x00000F00UL    /* Default value for WDOG_CTRL              */
#define WDOG_CTRL_MASK                          0x00003F7FUL    /* Mask for WDOG_CTRL                       */
#define WDOG_CTRL_EN_SHIFT                      0               /* Shift value for WDOG_CTRL_EN             */
#define WDOG_CTRL_EN_MASK                       (0x1UL << 0)    /* Bit mask for WDOG_CTRL_EN                */
#define WDOG_CTRL_EN_DEFAULT                    (0x0UL << 0)    /* Mode DEFAULT for WDOG_CTRL_EN            */
#define WDOG_CTRL_EN                            (0x1UL << 0)    /* Watchdog Timer Enable                    */
#define WDOG_CTRL_DEBUGRUN_SHIFT                1               /* Shift value for WDOG_CTRL_DEBUGRUN       */
#define WDOG_CTRL_DEBUGRUN_MASK                 (0x1UL << 1)    /* Bit mask for WDOG_CTRL_DEBUGRUN          */
#define WDOG_CTRL_DEBUGRUN_DEFAULT              (0x0UL << 1)    /* Mode DEFAULT for WDOG_CTRL_DEBUGRUN      */
#define WDOG_CTRL_DEBUGRUN                      (0x1UL << 1)    /* Debug Mode Run Enable                    */
#define WDOG_CTRL_EM2RUN_SHIFT                  2               /* Shift value for WDOG_CTRL_EM2RUN         */
#define WDOG_CTRL_EM2RUN_MASK                   (0x1UL << 2)    /* Bit mask for WDOG_CTRL_EM2RUN            */
#define WDOG_CTRL_EM2RUN_DEFAULT                (0x0UL << 2)    /* Mode DEFAULT for WDOG_CTRL_EM2RUN        */
#define WDOG_CTRL_EM2RUN                        (0x1UL << 2)    /* Energy Mode 2 Run Enable                 */
#define WDOG_CTRL_EM3RUN_SHIFT                  3               /* Shift value for WDOG_CTRL_EM3RUN         */
#define WDOG_CTRL_EM3RUN_MASK                   (0x1UL << 3)    /* Bit mask for WDOG_CTRL_EM3RUN            */
#define WDOG_CTRL_EM3RUN_DEFAULT                (0x0UL << 3)    /* Mode DEFAULT for WDOG_CTRL_EM3RUN        */
#define WDOG_CTRL_EM3RUN                        (0x1UL << 3)    /* Energy Mode 3 Run Enable                 */
#define WDOG_CTRL_LOCK_SHIFT                    4               /* Shift value for WDOG_CTRL_LOCK           */
#define WDOG_CTRL_LOCK_MASK                     (0x1UL << 4)    /* Bit mask for WDOG_CTRL_LOCK              */
#define WDOG_CTRL_LOCK_DEFAULT                  (0x0UL << 4)    /* Mode DEFAULT for WDOG_CTRL_LOCK          */
#define WDOG_CTRL_LOCK                          (0x1UL << 4)    /* Configuration lock                       */
#define WDOG_CTRL_EM4BLOCK_SHIFT                5               /* Shift value for WDOG_CTRL_EM4BLOCK       */
#define WDOG_CTRL_EM4BLOCK_MASK                 (0x1UL << 5)    /* Bit mask for WDOG_CTRL_EM4BLOCK          */
#define WDOG_CTRL_EM4BLOCK_DEFAULT              (0x0UL << 5)    /* Mode DEFAULT for WDOG_CTRL_EM4BLOCK      */
#define WDOG_CTRL_EM4BLOCK                      (0x1UL << 5)    /* Energy Mode 4 Block                      */
#define WDOG_CTRL_SWOSCBLOCK_SHIFT              6               /* Shift value for WDOG_CTRL_SWOSCBLOCK     */
#define WDOG_CTRL_SWOSCBLOCK_MASK               (0x1UL << 6)    /* Bit mask for WDOG_CTRL_SWOSCBLOCK        */
#define WDOG_CTRL_SWOSCBLOCK_DEFAULT            (0x0UL << 6)    /* Mode DEFAULT for WDOG_CTRL_SWOSCBLOCK    */
#define WDOG_CTRL_SWOSCBLOCK                    (0x1UL << 6)    /* Software Oscillator Disable Block        */
#define WDOG_CTRL_PERSEL_SHIFT                  8               /* Shift value for WDOG_CTRL_PERSEL         */
#define WDOG_CTRL_PERSEL_MASK                   (0xFUL << 8)    /* Bit mask for WDOG_CTRL_PERSEL            */
#define WDOG_CTRL_PERSEL_DEFAULT                (0xFUL << 8)    /* Mode DEFAULT for WDOG_CTRL_PERSEL        */
#define WDOG_CTRL_CLKSEL_SHIFT                  12              /* Shift value for WDOG_CTRL_CLKSEL         */
#define WDOG_CTRL_CLKSEL_MASK                   (0x3UL << 12)   /* Bit mask for WDOG_CTRL_CLKSEL            */
#define WDOG_CTRL_CLKSEL_DEFAULT                (0x0UL << 12)   /* Mode DEFAULT for WDOG_CTRL_CLKSEL        */
#define WDOG_CTRL_CLKSEL_ULFRCO                 (0x0UL << 12)   /* Mode ULFRCO for WDOG_CTRL_CLKSEL         */
#define WDOG_CTRL_CLKSEL_LFRCO                  (0x1UL << 12)   /* Mode LFRCO for WDOG_CTRL_CLKSEL          */
#define WDOG_CTRL_CLKSEL_LFXO                   (0x2UL << 12)   /* Mode LFXO for WDOG_CTRL_CLKSEL           */

/* Bit fields for WDOG CMD */
#define WDOG_CMD_RESETVALUE                     0x00000000UL    /* Default value for WDOG_CMD               */
#define WDOG_CMD_MASK                           0x00000001UL    /* Mask for WDOG_CMD                        */
#define WDOG_CMD_CLEAR_SHIFT                    0               /* Shift value for WDOG_CMD_CLEAR           */
#define WDOG_CMD_CLEAR_MASK                     (0x1UL << 0)    /* Bit mask for WDOG_CMD_CLEAR              */
#define WDOG_CMD_CLEAR_DEFAULT                  (0x0UL << 0)    /* Mode DEFAULT for WDOG_CMD_CLEAR          */
#define WDOG_CMD_CLEAR_UNCHANGED                (0x0UL << 0)    /* Mode UNCHANGED for WDOG_CMD_CLEAR        */
#define WDOG_CMD_CLEAR_CLEARED                  (0x1UL << 0)    /* Mode CLEARED for WDOG_CMD_CLEAR          */
#define WDOG_CMD_CLEAR                          (0x1UL << 0)    /* Watchdog Timer Clear                     */

/* Bit fields for WDOG SYNCBUSY */
#define WDOG_SYNCBUSY_RESETVALUE                0x00000000UL    /* Default value for WDOG_SYNCBUSY          */
#define WDOG_SYNCBUSY_MASK                      0x00000003UL    /* Mask for WDOG_SYNCBUSY                   */
#define WDOG_SYNCBUSY_CTRL_SHIFT                0               /* Shift value for WDOG_SYNCBUSY_CTRL       */
#define WDOG_SYNCBUSY_CTRL_MASK                 (0x1UL << 0)    /* Bit mask for WDOG_SYNCBUSY_CTRL          */
#define WDOG_SYNCBUSY_CTRL_DEFAULT              (0x0UL << 0)    /* Mode DEFAULT for WDOG_SYNCBUSY_CTRL      */
#define WDOG_SYNCBUSY_CTRL                      (0x1UL << 0)    /* WDOG_CTRL Register Busy                  */
#define WDOG_SYNCBUSY_CMD_SHIFT                 1               /* Shift value for WDOG_SYNCBUSY_CMD        */
#define WDOG_SYNCBUSY_CMD_MASK                  (0x1UL << 1)    /* Bit mask for WDOG_SYNCBUSY_CMD           */
#define WDOG_SYNCBUSY_CMD_DEFAULT               (0x0UL << 1)    /* Mode DEFAULT for WDOG_SYNCBUSY_CMD       */
#define WDOG_SYNCBUSY_CMD                       (0x1UL << 1)    /* WDOG_CMD Register Busy                   */
    
    
/*************************************************************************************************************
*                                                 DATA TYPES                                                *
*************************************************************************************************************/
/* Data Types for WDOG CTRL */ 
typedef enum 
{
    WDOG_0 = WDOG_BASE,
} WDOGTypeDef;

typedef enum 
{
    WDOG_CTRL_CLK_ULFRCO = WDOG_CTRL_CLKSEL_ULFRCO,
    WDOG_CTRL_CLK_LFRCO  = WDOG_CTRL_CLKSEL_LFRCO,
    WDOG_CTRL_CLK_LFXO   = WDOG_CTRL_CLKSEL_LFXO,
} WDOGClockSlectTypeDef;

typedef enum
{
    WDOG_CTRL_PERSEL_9      = 0x0,
    WDOG_CTRL_PERSEL_17     = 0x1,
    WDOG_CTRL_PERSEL_33     = 0x2,
    WDOG_CTRL_PERSEL_65     = 0x3,
    WDOG_CTRL_PERSEL_129    = 0x4,
    WDOG_CTRL_PERSEL_257    = 0x5,
    WDOG_CTRL_PERSEL_513    = 0x6,
    WDOG_CTRL_PERSEL_1025   = 0x7,
    WDOG_CTRL_PERSEL_2049   = 0x8,
    WDOG_CTRL_PERSEL_4099   = 0x9,
    WDOG_CTRL_PERSEL_8193   = 0xA,
    WDOG_CTRL_PERSEL_16385  = 0xB,
    WDOG_CTRL_PERSEL_32769  = 0xC,
    WDOG_CTRL_PERSEL_65537  = 0xD,
    WDOG_CTRL_PERSEL_131073 = 0xE,
    WDOG_CTRL_PERSEL_262145 = 0xF
} WDOGPeriodselTypeDef;

/* Data Types for WDOG CMD */
typedef enum 
{
    WDOG_CMD_UNCHANGED = WDOG_CMD_CLEAR_UNCHANGED,
    WDOG_CMD_CLEARED   = WDOG_CMD_CLEAR_CLEARED,
} WDOGTimerClearModeTypeDef;

/* Data Types for WDOG SYNCBUSY */
typedef enum 
{
    WDOG_SYNCBUSY_SYNCHRONIZE_CTRL = WDOG_SYNCBUSY_CTRL,
    WDOG_SYNCBUSY_SYNCHRONIZE_CMD  = WDOG_SYNCBUSY_CMD,
} WDOGSyncBusyStatusTypeDef;

    
    
/*************************************************************************************************************
*                                            FUNCTION PROTOTYPES                                             *
*************************************************************************************************************/   
/* Function for WDOG CTRL */
static inline void WDOGTimerEnable (WDOGTypeDef n)
{
    WDOGRegTypeDef *wdog;
    
    wdog = (WDOGRegTypeDef *)n;
    
    wdog->CTRL |= WDOG_CTRL_EN;
}

static inline void WDOGTimerDisable (WDOGTypeDef n)
{
    WDOGRegTypeDef *wdog;
    
    wdog = (WDOGRegTypeDef *)n;
    
    wdog->CTRL &= ~WDOG_CTRL_EN;
}

static inline CPU_BOOL WDOGTimerFlagGet (WDOGTypeDef n)
{
    WDOGRegTypeDef *wdog;
    
    wdog = (WDOGRegTypeDef *)n;
    
    if (wdog->CTRL & WDOG_CTRL_EN_MASK)
    {
        return DEF_ON;
    }
    else
    {
        return DEF_OFF;
    }
}

static inline void WDOGDebugModeRunEnable (WDOGTypeDef n)
{
    WDOGRegTypeDef *wdog;
    
    wdog = (WDOGRegTypeDef *)n;
    
    wdog->CTRL |= WDOG_CTRL_DEBUGRUN;
}

static inline void WDOGDebugModeRunDisable (WDOGTypeDef n)
{
    WDOGRegTypeDef *wdog;
    
    wdog = (WDOGRegTypeDef *)n;
    
    wdog->CTRL &= ~WDOG_CTRL_DEBUGRUN;
}

static inline CPU_BOOL WDOGDebugModeRunFlagGet (WDOGTypeDef n)
{
    WDOGRegTypeDef *wdog;
    
    wdog = (WDOGRegTypeDef *)n;
    
    if (wdog->CTRL & WDOG_CTRL_DEBUGRUN_MASK)
    {
        return DEF_ON;
    }
    else
    {
        return DEF_OFF;
    }
}

static inline void WDOGEnergyMode2Enable (WDOGTypeDef n)
{
    WDOGRegTypeDef *wdog;
    
    wdog = (WDOGRegTypeDef *)n;
   
    wdog->CTRL |= WDOG_CTRL_EM2RUN;   
}

static inline void WDOGEnergyMode2Disable (WDOGTypeDef n)
{
    WDOGRegTypeDef *wdog;
    
    wdog = (WDOGRegTypeDef *)n;
   
    wdog->CTRL &= ~WDOG_CTRL_EM2RUN;   
}

static inline CPU_BOOL WDOGEnergyMode2FlagGet (WDOGTypeDef n)
{
    WDOGRegTypeDef *wdog;
    
    wdog = (WDOGRegTypeDef *)n;
    
    if (wdog->CTRL & WDOG_CTRL_EM2RUN_MASK)
    {
        return DEF_ON;
    }
    else
    {
        return DEF_OFF;
    }
}

static inline void WDOGEnergyMode3Enable (WDOGTypeDef n)
{
    WDOGRegTypeDef *wdog;
    
    wdog = (WDOGRegTypeDef *)n;
   
    wdog->CTRL |= WDOG_CTRL_EM3RUN;   
}

static inline void WDOGEnergyMode3Disable (WDOGTypeDef n)
{
    WDOGRegTypeDef *wdog;
    
    wdog = (WDOGRegTypeDef *)n;
   
    wdog->CTRL &= ~WDOG_CTRL_EM3RUN;   
}

static inline CPU_BOOL WDOGEnergyMode3FlagGet (WDOGTypeDef n)
{
    WDOGRegTypeDef *wdog;
    
    wdog = (WDOGRegTypeDef *)n;
    
    if (wdog->CTRL & WDOG_CTRL_EM3RUN_MASK)
    {
        return DEF_ON;
    }
    else
    {
        return DEF_OFF;
    }
}

static inline void WDOGConfigurationLockEnable (WDOGTypeDef n)
{
    WDOGRegTypeDef *wdog;
    
    wdog = (WDOGRegTypeDef *)n;
   
    wdog->CTRL |= WDOG_CTRL_LOCK;
}

static inline void WDOGConfigurationLockDisable (WDOGTypeDef n)
{
    WDOGRegTypeDef *wdog;
    
    wdog = (WDOGRegTypeDef *)n;
   
    wdog->CTRL &= ~WDOG_CTRL_LOCK;
}

static inline CPU_BOOL WDOGConfigurationLockFlagGet (WDOGTypeDef n)
{
    WDOGRegTypeDef *wdog;
    
    wdog = (WDOGRegTypeDef *)n;
    
    if (wdog->CTRL & WDOG_CTRL_LOCK_MASK)
    {
        return DEF_ON;
    }
    else
    {
        return DEF_OFF;
    }
}

static inline void WODGEnergyMode4BlockEnable (WDOGTypeDef n)
{
    WDOGRegTypeDef *wdog;
    
    wdog = (WDOGRegTypeDef *)n;
   
    wdog->CTRL |= WDOG_CTRL_EM4BLOCK;
}

static inline void WODGEnergyMode4BlockDisable (WDOGTypeDef n)
{
    WDOGRegTypeDef *wdog;
    
    wdog = (WDOGRegTypeDef *)n;
   
    wdog->CTRL &= ~WDOG_CTRL_EM4BLOCK;
}

static inline CPU_BOOL WODGEnergyMode4BlockFlagGet (WDOGTypeDef n)
{
    WDOGRegTypeDef *wdog;
    
    wdog = (WDOGRegTypeDef *)n;
    
    if (wdog->CTRL & WDOG_CTRL_EM4BLOCK_MASK)
    {
        return DEF_ON;
    }
    else
    {
        return DEF_OFF;
    }
}

static inline void WODGSoftwareOscillatorDisableBlockEnable (WDOGTypeDef n)
{
    WDOGRegTypeDef *wdog;
    
    wdog = (WDOGRegTypeDef *)n;
   
    wdog->CTRL |= WDOG_CTRL_SWOSCBLOCK;
}

static inline void WODGSoftwareOscillatorDisableBlockDisable (WDOGTypeDef n)
{
    WDOGRegTypeDef *wdog;
    
    wdog = (WDOGRegTypeDef *)n;
   
    wdog->CTRL &= ~WDOG_CTRL_SWOSCBLOCK;
}

static inline CPU_BOOL WODGSoftwareOscillatorDisableBlockFlagGet (WDOGTypeDef n)
{
    WDOGRegTypeDef *wdog;
    
    wdog = (WDOGRegTypeDef *)n;
    
    if (wdog->CTRL & WDOG_CTRL_SWOSCBLOCK_MASK)
    {
        return DEF_ON;
    }
    else
    {
        return DEF_OFF;
    }
}

static inline void WDOGTimeoutPeriodSelectSet (WDOGTypeDef n, CPU_INT32U value)
{
    WDOGRegTypeDef *wdog;
    
    wdog = (WDOGRegTypeDef *)n;
    
    wdog->CTRL &= ~WDOG_CTRL_PERSEL_MASK;
    wdog->CTRL |= ((value << WDOG_CTRL_PERSEL_SHIFT) & WDOG_CTRL_PERSEL_MASK);
}

static inline CPU_INT32U WDOGTimeoutPeriodSelectGet (WDOGTypeDef n)
{
    WDOGRegTypeDef *wdog;
    
    wdog = (WDOGRegTypeDef *)n;
    
    return (CPU_INT32U)((wdog->CTRL & WDOG_CTRL_PERSEL_MASK) >> WDOG_CTRL_PERSEL_SHIFT);
}

static inline void WDOGClockSelectModeSet (WDOGTypeDef n, WDOGClockSlectTypeDef clock)
{
    WDOGRegTypeDef *wdog;
    
    wdog = (WDOGRegTypeDef *)n;
   
    wdog->CTRL |= clock;
}

static inline WDOGClockSlectTypeDef WDOGClockSelectModeGet (WDOGTypeDef n)
{
    WDOGRegTypeDef *wdog;
    
    wdog = (WDOGRegTypeDef *)n;
    
    return (WDOGClockSlectTypeDef)(wdog->CTRL & WDOG_CTRL_CLKSEL_MASK);
}

static inline CPU_BOOL WDOGClockSelectModeFlagGet (WDOGTypeDef n, WDOGClockSlectTypeDef clock)
{
    WDOGRegTypeDef *wdog;
    
    wdog = (WDOGRegTypeDef *)n;
    
    if (wdog->CTRL & clock)
    {
        return DEF_ON;
    }
    else
    {
        return DEF_OFF;
    }
}

/* Function for WDOG CMD */
static inline void WDOGTimerClearModeSet (WDOGTypeDef n, WDOGTimerClearModeTypeDef clear)
{
    WDOGRegTypeDef *wdog;
    
    wdog = (WDOGRegTypeDef *)n;
   
    wdog->CMD &= ~WDOG_CMD_CLEAR_MASK;
    wdog->CMD |= clear;
}

static inline WDOGTimerClearModeTypeDef WDOGTimerClearModeGet (WDOGTypeDef n)
{
    WDOGRegTypeDef *wdog;
    
    wdog = (WDOGRegTypeDef *)n;
    
    return (WDOGTimerClearModeTypeDef)(wdog->CMD & WDOG_CMD_CLEAR_MASK);
}

static inline CPU_BOOL WDOGTimerClearModeFlagGet (WDOGTypeDef n, WDOGTimerClearModeTypeDef clear)
{
    WDOGRegTypeDef *wdog;
    
    wdog = (WDOGRegTypeDef *)n;
    
    if (wdog->CMD & clear)
    {
        return DEF_ON;
    }
    else
    {
        return DEF_OFF;
    }
}

/* Function for WDOG SYNCBUSY */
static inline WDOGSyncBusyStatusTypeDef WDOGSyncBusyStatusGet (WDOGTypeDef n)
{
    WDOGRegTypeDef *wdog;
    
    wdog = (WDOGRegTypeDef *)n;
    
    return (WDOGSyncBusyStatusTypeDef)(wdog->SYNCBUSY & WDOG_SYNCBUSY_CMD_MASK);
}

static inline CPU_BOOL WDOGSyncBusyStatusFlagGet (WDOGTypeDef n, WDOGSyncBusyStatusTypeDef status)
{
    WDOGRegTypeDef *wdog;
    
    wdog = (WDOGRegTypeDef *)n;
   
    if (wdog->SYNCBUSY & status)
    {
        return DEF_ON;
    }
    else
    {
        return DEF_OFF;
    }
}




/*************************************************************************************************************
*                                            FUNCTION STATEMENT                                              *
*************************************************************************************************************/
void WDOGClockEnable (WDOGTypeDef n);
void WDOGClockDisable (WDOGTypeDef n);
    
       
/*************************************************************************************************************
*                                               MODULE END                                                   *
*************************************************************************************************************/     
#ifdef __cplusplus
}
#endif

#endif 