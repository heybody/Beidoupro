/*************************************************************************************************************
*                                                  MODULE                                                    *
*************************************************************************************************************/
#ifndef EMU_H
#define EMU_H

#ifdef __cplusplus
extern "C" {
#endif
    

/*************************************************************************************************************
*                                                 DEFINES                                                    *
*************************************************************************************************************/
#define EMU                                     ((EMURegTypeDef *)EMU_BASE)
    
/* Bit fields for EMU CTRL */
#define EMU_CTRL_RESETVALUE                     0x00000000UL    /* Default value for EMU_CTRL               */
#define EMU_CTRL_MASK                           0x0000000FUL    /* Mask for EMU_CTRL                        */
#define EMU_CTRL_EMVREG_SHIFT                   0               /* Shift value for EMU_CTRL_EMVREG          */
#define EMU_CTRL_EMVREG_MASK                    (0x1UL << 0)    /* Bit mask for EMU_CTRL_EMVREG             */
#define EMU_CTRL_EMVREG_DEFAULT                 (0x0UL << 0)    /* Mode DEFAULT for EMU_CTRL_EMVREG         */
#define EMU_CTRL_EMVREG_REDUCED                 (0x0UL << 0)    /* Mode REDUCED for EMU_CTRL_EMVREG         */
#define EMU_CTRL_EMVREG_FULL                    (0x1UL << 0)    /* Mode FULL for EMU_CTRL_EMVREG            */
#define EMU_CTRL_EM2BLOCK_SHIFT                 1               /* Shift value for EMU_CTRL_EM2BLOCK        */
#define EMU_CTRL_EM2BLOCK_MASK                  (0x1UL << 1)    /* Bit mask for EMU_CTRL_EM2BLOCK           */
#define EMU_CTRL_EM2BLOCK_DEFAULT               (0x0UL << 1)    /* Mode DEFAULT for EMU_CTRL_EM2BLOCK       */
#define EMU_CTRL_EM2BLOCK                       (0x1UL << 1)    /* Energy Mode 2 Block                      */
#define EMU_CTRL_EM4CTRL_SHIFT                  2               /* Shift value for EMU_CTRL_EM4CTRL         */
#define EMU_CTRL_EM4CTRL_MASK                   (0x3UL << 2)    /* Bit mask for EMU_CTRL_EM4CTRL            */
#define EMU_CTRL_EM4CTRL_DEFAULT                (0x0UL << 2)    /* Mode DEFAULT for EMU_CTRL_EM4CTRL        */

/* Bit fields for EMU MEMCTRL */
#define EMU_MEMCTRL_RESETVALUE                  0x00000000UL    /* Default value for EMU_MEMCTRL            */
#define EMU_MEMCTRL_MASK                        0x00000007UL    /* Mask for EMU_MEMCTRL                     */
#define EMU_MEMCTRL_POWERDOWN_BLOCK1_SHIFT      0               /* Shift value for EMU_MEMCTRL_POWERDOWN_BLOCK1 */
#define EMU_MEMCTRL_POWERDOWN_BLOCK1_MASK       (0x1UL >> 0)    /* Bit mask for EMU_MEMCTRL_POWERDOWN_BLOCK1 */
#define EMU_MEMCTRL_POWERDOWN_BLOCK1_DEFAULT    (0x0UL >> 0)    /* Mode DEFAULT for EMU_MEMCTRL_POWERDOWN_BLOCK1 */
#define EMU_MEMCTRL_POWERDOWN_BLOCK1            (0x1UL >> 0)    /* Mode DEFAULT for EMU_MEMCTRL_POWERDOWN_BLOCK1 */
#define EMU_MEMCTRL_POWERDOWN_BLOCK2_SHIFT      1               /* Shift value for EMU_MEMCTRL_POWERDOWN_BLOCK2 */
#define EMU_MEMCTRL_POWERDOWN_BLOCK2_MASK       (0x1UL >> 1)    /* Bit mask for EMU_MEMCTRL_POWERDOWN_BLOCK2 */
#define EMU_MEMCTRL_POWERDOWN_BLOCK2_DEFAULT    (0x0UL >> 1)    /* Mode DEFAULT for EMU_MEMCTRL_POWERDOWN_BLOCK2 */
#define EMU_MEMCTRL_POWERDOWN_BLOCK2            (0x1UL >> 1)    /* Mode DEFAULT for EMU_MEMCTRL_POWERDOWN_BLOCK2 */    
#define EMU_MEMCTRL_POWERDOWN_BLOCK3_SHIFT      2               /* Shift value for EMU_MEMCTRL_POWERDOWN_BLOCK3 */
#define EMU_MEMCTRL_POWERDOWN_BLOCK3_MASK       (0x1UL >> 2)    /* Bit mask for EMU_MEMCTRL_POWERDOWN_BLOCK3 */
#define EMU_MEMCTRL_POWERDOWN_BLOCK3_DEFAULT    (0x0UL >> 2)    /* Mode DEFAULT for EMU_MEMCTRL_POWERDOWN_BLOCK3 */
#define EMU_MEMCTRL_POWERDOWN_BLOCK3            (0x1UL >> 2)    /* Mode DEFAULT for EMU_MEMCTRL_POWERDOWN_BLOCK3 */
    
/* Bit fields for EMU LOCK */
#define EMU_LOCK_RESETVALUE                     0x00000000UL    /* Default value for EMU_LOCK               */
#define EMU_LOCK_MASK                           0x0000FFFFUL    /* Mask for EMU_LOCK                        */
#define EMU_LOCK_LOCKKEY_SHIFT                  0               /* Shift value for EMU_LOCK_LOCKKEY         */
#define EMU_LOCK_LOCKKEY_MASK                   0xFFFFUL        /* Bit mask for EMU_LOCK_LOCKKEY            */
#define EMU_LOCK_LOCKKEY_DEFAULT                0x0000UL        /* Mode DEFAULT for EMU_LOCK_LOCKKEY        */
#define EMU_LOCK_LOCKKEY_LOCK                   0x0000UL        /* Mode LOCK for EMU_LOCK_LOCKKEY           */
#define EMU_LOCK_LOCKKEY_UNLOCKED               0x0000UL        /* Mode UNLOCKED for EMU_LOCK_LOCKKEY       */
#define EMU_LOCK_LOCKKEY_LOCKED                 0x0001UL        /* Mode LOCKED for EMU_LOCK_LOCKKEY         */
#define EMU_LOCK_LOCKKEY_UNLOCK                 0xADE8UL        /* Mode UNLOCK for EMU_LOCK_LOCKKEY         */

/* Bit fields for EMU AUXCTRL */
#define EMU_AUXCTRL_RESETVALUE                  0x00000000UL    /* Default value for EMU_AUXCTRL            */
#define EMU_AUXCTRL_MASK                        0x00000001UL    /* Mask for EMU_AUXCTRL                     */
#define EMU_AUXCTRL_HRCCLR_SHIFT                0               /* Shift value for EMU_AUXCTRL_HRCCLR       */
#define EMU_AUXCTRL_HRCCLR_MASK                 0x1UL           /* Bit mask for EMU_AUXCTRL_HRCCLR          */
#define EMU_AUXCTRL_HRCCLR_DEFAULT              0x00000000UL    /* Mode DEFAULT for EMU_AUXCTRL_HRCCLR      */
#define EMU_AUXCTRL_HRCCLR                      (0x1UL << 0)    /* Hard Reset Cause Clear                   */
    
    
/*************************************************************************************************************
*                                                  DATA TYPES                                                *
*************************************************************************************************************/
typedef enum
{
    EMU_POWER_DOWN_RAM_BLOCK_1   = EMU_MEMCTRL_POWERDOWN_BLOCK1, 
    EMU_POWER_DOWN_RAM_BLOCK_2   = EMU_MEMCTRL_POWERDOWN_BLOCK2, 
    EMU_POWER_DOWN_RAM_BLOCK_3   = EMU_MEMCTRL_POWERDOWN_BLOCK3, 
    EMU_POWER_DOWN_RAM_BLOCK_1_2 = EMU_MEMCTRL_POWERDOWN_BLOCK1 | EMU_MEMCTRL_POWERDOWN_BLOCK2, 
    EMU_POWER_DOWN_RAM_BLOCK_1_3 = EMU_MEMCTRL_POWERDOWN_BLOCK1 | EMU_MEMCTRL_POWERDOWN_BLOCK3, 
    EMU_POWER_DOWN_RAM_BLOCK_2_3 = EMU_MEMCTRL_POWERDOWN_BLOCK2 | EMU_MEMCTRL_POWERDOWN_BLOCK3,
    EMU_POWER_DOWN_RAM_BLOCK_1_2_3 = EMU_MEMCTRL_POWERDOWN_BLOCK1 | EMU_MEMCTRL_POWERDOWN_BLOCK2 | EMU_MEMCTRL_POWERDOWN_BLOCK3,
} EMUPowerDownRAMTypeDef;


/*************************************************************************************************************
*                                            FUNCTION PROTOTYPES                                             *
*************************************************************************************************************/
static inline void EMULock(void)
{
    EMU->LOCK = EMU_LOCK_LOCKKEY_LOCK;
}

static inline void EMUUnlock(void)
{
    EMU->LOCK = EMU_LOCK_LOCKKEY_UNLOCK;
}


/*************************************************************************************************************
*                                            FUNCTION STATEMENT                                              *
*************************************************************************************************************/
void EMUUpdataConfig (void);
void EMURestore (void);
void EMUEnterEM1 (void);
void EMUEnterEM2 (void);
void EMUEnterEM3 (void);
void EMUEnterEM4 (void);
void EMUMemPwrDown (EMUPowerDownRAMTypeDef blocks);
void EMUResetCauseClear (void);


/*************************************************************************************************************
*                                               MODULE END                                                   *
*************************************************************************************************************/     
#ifdef __cplusplus
}
#endif

#endif 

