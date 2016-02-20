/*************************************************************************************************************
*                                                  MODULE                                                    *
*************************************************************************************************************/
#ifndef CMU_H
#define CMU_H

#ifdef __cplusplus
extern "C" {
#endif
    

/*************************************************************************************************************
*                                                 DEFINES                                                    *
*************************************************************************************************************/
#define CMU                                     ((CMURegTypeDef *)CMU_BASE)
    
/* Bit fields for CMU CTRL */
#define CMU_CTRL_RESETVALUE                     0x000C262CUL    /* Default value for CMU_CTRL               */
#define CMU_CTRL_MASK                           0x00FE3EEFUL    /* Mask for CMU_CTRL                        */
#define CMU_CTRL_HFXOMODE_SHIFT                 0               /* Shift value for CMU_CTRL_HFXOMODE        */
#define CMU_CTRL_HFXOMODE_MASK                  (0x3UL << 0)    /* Bit mask for CMU_CTRL_HFXOMODE           */
#define CMU_CTRL_HFXOMODE_DEFAULT               (0x3UL << 0)    /* DEFAULT for CMU_CTRL_HFXOMODE            */
#define CMU_CTRL_HFXOMODE_XTAL                  (0x0UL << 0)    /* XTAL for CMU_CTRL_HFXOMODE               */
#define CMU_CTRL_HFXOMODE_BUFEXTCLK             (0x1UL << 0)    /* BUFEXTCLK for CMU_CTRL_HFXOMODE          */
#define CMU_CTRL_HFXOMODE_DIGEXTCLK             (0x2UL << 0)    /* DIGEXTCLK for CMU_CTRL_HFXOMODE          */
#define CMU_CTRL_HFXOBOOST_SHIFT                2               /* Shift value for CMU_CTRL_HFXOBOOST       */
#define CMU_CTRL_HFXOBOOST_MASK                 (0x3UL << 2)    /* Bit mask for CMU_CTRL_HFXOBOOST          */
#define CMU_CTRL_HFXOBOOST_DEFAULT              (0x3UL << 2)    /* DEFAULT mask for CMU_CTRL_HFXOBOOST      */
#define CMU_CTRL_HFXOBOOST_50PCENT              (0x0UL << 2)    /* 50PCENT for CMU_CTRL_HFXOBOOST           */
#define CMU_CTRL_HFXOBOOST_70PCENT              (0x1UL << 2)    /* 70PCENT for CMU_CTRL_HFXOBOOST           */
#define CMU_CTRL_HFXOBOOST_80PCENT              (0x2UL << 2)    /* 80PCENT for CMU_CTRL_HFXOBOOST           */
#define CMU_CTRL_HFXOBOOST_100PCENT             (0x3UL << 2)    /* 100PCENT for CMU_CTRL_HFXOBOOST          */
#define CMU_CTRL_HFXOBUFCUR_SHIFT               5               /* Shift value for CMU_CTRL_HFXOBUFCUR      */
#define CMU_CTRL_HFXOBUFCUR_MASK                (0x3UL << 5)    /* Bit mask for CMU_CTRL_HFXOBUFCUR         */
#define CMU_CTRL_HFXOBUFCUR_DEFAULT             (0x1UL << 5)    /* DEFAULT for CMU_CTRL_HFXOBUFCUR          */
#define CMU_CTRL_HFXOGLITCHDETEN_SHIFT          7               /* Shift value for CMU_CTRL_HFXOGLITCHDETEN */
#define CMU_CTRL_HFXOGLITCHDETEN_MASK           (0x1UL << 7)    /* Bit mask for CMU_CTRL_HFXOGLITCHDETEN    */
#define CMU_CTRL_HFXOGLITCHDETEN_DEFAULT        (0x0UL << 7)    /* DEFAULT for CMU_CTRL_HFXOGLITCHDETEN     */
#define CMU_CTRL_HFXOGLITCHDETEN                (0x1UL << 7)    /* HFXO Glitch Detector Enable              */
#define CMU_CTRL_HFXOTIMEOUT_SHIFT              9               /* Shift value for CMU_CTRL_HFXOTIMEOUT     */
#define CMU_CTRL_HFXOTIMEOUT_MASK               (0x3UL << 9)    /* Bit mask for CMU_CTRL_HFXOTIMEOUT        */
#define CMU_CTRL_HFXOTIMEOUT_DEFAULT            (0x3UL << 9)    /* DEFAULT for CMU_CTRL_HFXOTIMEOUT         */
#define CMU_CTRL_HFXOTIMEOUT_8CYCLES            (0x0UL << 9)    /* 8CYCLES for CMU_CTRL_HFXOTIMEOUT         */
#define CMU_CTRL_HFXOTIMEOUT_256CYCLES          (0x1UL << 9)    /* 256CYCLES for CMU_CTRL_HFXOTIMEOUT       */
#define CMU_CTRL_HFXOTIMEOUT_1KCYCLES           (0x2UL << 9)    /* 1KCYCLES for CMU_CTRL_HFXOTIMEOUT        */
#define CMU_CTRL_HFXOTIMEOUT_16KCYCLES          (0x3UL << 9)    /* 16KCYCLES for CMU_CTRL_HFXOTIMEOUT       */
#define CMU_CTRL_LFXOMODE_SHIFT                 11              /* Shift value for CMU_CTRL_LFXOMODE        */
#define CMU_CTRL_LFXOMODE_MASK                  (0x3UL << 11)   /* Bit mask for CMU_CTRL_LFXOMODE           */
#define CMU_CTRL_LFXOMODE_DEFAULT               (0x0UL << 11)   /* DEFAULT for CMU_CTRL_LFXOMODE            */
#define CMU_CTRL_LFXOMODE_XTAL                  (0x0UL << 11)   /* XTAL for CMU_CTRL_LFXOMODE               */
#define CMU_CTRL_LFXOMODE_BUFEXTCLK             (0x0UL << 11)   /* BUFEXTCLK for CMU_CTRL_LFXOMODE          */
#define CMU_CTRL_LFXOMODE_DIGEXTCLK             (0x0UL << 11)   /* DIGEXTCLK for CMU_CTRL_LFXOMODE          */
#define CMU_CTRL_LFXOBOOST_SHIFT                13              /* Shift value for CMU_CTRL_LFXOBOOST       */
#define CMU_CTRL_LFXOBOOST_MASK                 (0x1UL << 13)   /* Bit mask for CMU_CTRL_LFXOBOOST          */
#define CMU_CTRL_LFXOBOOST_DEFAULT              (0x1UL << 13)   /* DEFAULT for CMU_CTRL_LFXOBOOST           */
#define CMU_CTRL_LFXOBOOST_70PCENT              (0x0UL << 13)   /* 70PCENT for CMU_CTRL_LFXOBOOST           */
#define CMU_CTRL_LFXOBOOST_100PCENT             (0x1UL << 13)   /* 100PCENT for CMU_CTRL_LFXOBOOST          */
#define CMU_CTRL_HFCLKDIV_SHIFT                 14              /* Shift vvalue for CMU_CTRL_HFCLKDIV       */
#define CMU_CTRL_HFCLKDIV_MASK                  (0x7UL << 13)   /* Bit mask for CMU_CTRL_HFCLKDIV           */
#define CMU_CTRL_HFCLKDIV_DEFAULT               (0x0UL << 13)   /* DEFAULT for CMU_CTRL_HFCLKDIV            */     
#define CMU_CTRL_LFXOBUFCUR_SHIFT               17              /* Shift value for CMU_CTRL_LFXOBUFCUR      */
#define CMU_CTRL_LFXOBUFCUR_MASK                (0x1UL << 17)   /* Bit mask for CMU_CTRL_LFXOBUFCUR         */
#define CMU_CTRL_LFXOBUFCUR_DEFAULT             (0x0UL << 17)   /* DEFAULT for CMU_CTRL_LFXOBUFCUR          */
#define CMU_CTRL_LFXOBUFCUR                     (0x1UL << 17)   /* LFXO Boost Buffer Current                */
#define CMU_CTRL_LFXOTIMEOUT_SHIFT              18              /* Shift value for CMU_CTRL_LFXOTIMEOUT     */
#define CMU_CTRL_LFXOTIMEOUT_MASK               (0x3UL << 18)   /* Bit mask for CMU_CTRL_LFXOTIMEOUT        */
#define CMU_CTRL_LFXOTIMEOUT_DEFAULT            (0x3UL << 18)   /* DEFAULT for CMU_CTRL_LFXOTIMEOUT         */
#define CMU_CTRL_LFXOTIMEOUT_8CYCLES            (0x0UL << 18)   /* 8CYCLES for CMU_CTRL_LFXOTIMEOUT         */
#define CMU_CTRL_LFXOTIMEOUT_1KCYCLES           (0x1UL << 18)   /* 1KCYCLES for CMU_CTRL_LFXOTIMEOUT        */
#define CMU_CTRL_LFXOTIMEOUT_16KCYCLES          (0x2UL << 18)   /* 16KCYCLES for CMU_CTRL_LFXOTIMEOUT       */
#define CMU_CTRL_LFXOTIMEOUT_32KCYCLES          (0x3UL << 18)   /* 32KCYCLES for CMU_CTRL_LFXOTIMEOUT       */
#define CMU_CTRL_CLKOUTSEL0_SHIFT               20              /* Shift value for CMU_CTRL_CLKOUTSEL0      */
#define CMU_CTRL_CLKOUTSEL0_MASK                (0x7UL << 20)   /* Bit mask for CMU_CTRL_CLKOUTSEL0         */
#define CMU_CTRL_CLKOUTSEL0_DEFAULT             (0x0UL << 20)   /* DEFAULT for CMU_CTRL_CLKOUTSEL0          */
#define CMU_CTRL_CLKOUTSEL0_HFRCO               (0x0UL << 20)   /* HFRCO for CMU_CTRL_CLKOUTSEL0            */
#define CMU_CTRL_CLKOUTSEL0_HFXO                (0x1UL << 20)   /* HFXO for CMU_CTRL_CLKOUTSEL0             */
#define CMU_CTRL_CLKOUTSEL0_HFCLK2              (0x2UL << 20)   /* HFCLK2 for CMU_CTRL_CLKOUTSEL0           */
#define CMU_CTRL_CLKOUTSEL0_HFCLK4              (0x3UL << 20)   /* HFCLK4 for CMU_CTRL_CLKOUTSEL0           */
#define CMU_CTRL_CLKOUTSEL0_HFCLK8              (0x4UL << 20)   /* HFCLK8 for CMU_CTRL_CLKOUTSEL0           */
#define CMU_CTRL_CLKOUTSEL0_HFCLK16             (0x5UL << 20)   /* HFCLK16 for CMU_CTRL_CLKOUTSEL0          */
#define CMU_CTRL_CLKOUTSEL0_ULFRCO              (0x6UL << 20)   /* ULFRCO for CMU_CTRL_CLKOUTSEL0           */
#define CMU_CTRL_CLKOUTSEL0_ULXHFRCO            (0x7UL << 20)   /* ULXHFRCO for CMU_CTRL_CLKOUTSEL0         */
#define CMU_CTRL_CLKOUTSEL1_SHIFT               23              /* Shift value for CMU_CTRL_CLKOUTSEL1      */
#define CMU_CTRL_CLKOUTSEL1_MASK                (0x7UL << 23)   /* Bit mask for CMU_CTRL_CLKOUTSEL1         */
#define CMU_CTRL_CLKOUTSEL1_DEFAULT             (0x0UL << 23)   /* DEFAULT for CMU_CTRL_CLKOUTSEL1          */
#define CMU_CTRL_CLKOUTSEL1_LFRCO               (0x0UL << 23)   /* LFRCO for CMU_CTRL_CLKOUTSEL1            */
#define CMU_CTRL_CLKOUTSEL1_LFXO                (0x1UL << 23)   /* LFXO for CMU_CTRL_CLKOUTSEL1             */
#define CMU_CTRL_CLKOUTSEL1_HFCLK               (0x2UL << 23)   /* HFCLK for CMU_CTRL_CLKOUTSEL1            */
#define CMU_CTRL_CLKOUTSEL1_LFXOQ               (0x3UL << 23)   /* LFXOQ for CMU_CTRL_CLKOUTSEL1            */
#define CMU_CTRL_CLKOUTSEL1_HFXOQ               (0x4UL << 23)   /* HFXOQ for CMU_CTRL_CLKOUTSEL1            */
#define CMU_CTRL_CLKOUTSEL1_LFRCOQ              (0x5UL << 23)   /* LFRCOQ for CMU_CTRL_CLKOUTSEL1           */
#define CMU_CTRL_CLKOUTSEL1_HFRCOQ              (0x6UL << 23)   /* HFRCOQ for CMU_CTRL_CLKOUTSEL1           */
#define CMU_CTRL_CLKOUTSEL1_AUXHFRCOQ           (0x7UL << 23)   /* AUXHFRCOQ for CMU_CTRL_CLKOUTSEL1        */
    
/* Bit fields for CMU HFCORECLKDIV */
#define CMU_HFCORECLKDIV_RESETVALUE             0x00000000UL    /* Default value for CMU_HFCORECLKDIV       */
#define CMU_HFCORECLKDIV_MASK                   0x0000000FUL    /* Mask for CMU_HFCORECLKDIV                */
#define CMU_HFCORECLKDIV_HFCORECLKDIV_SHIFT     0               /* Shift value for CMU_HFCORECLKDIV_HFCORECLKDIV */
#define CMU_HFCORECLKDIV_HFCORECLKDIV_MASK      (0xFUL << 0)    /* Mask for CMU_HFCORECLKDIV_HFCORECLKDIV   */
#define CMU_HFCORECLKDIV_HFCORECLKDIV_DEFAULT   (0x0UL << 0)    /* Default for CMU_HFCORECLKDIV_HFCORECLKDIV */
#define CMU_HFCORECLKDIV_HFCORECLKDIV_HFCLK     (0x0UL << 0)    /* HFCLK for HFCORECLK                      */
#define CMU_HFCORECLKDIV_HFCORECLKDIV_HFCLK2    (0x1UL << 0)    /* HFCLK / 2 for HFCORECLK                  */
#define CMU_HFCORECLKDIV_HFCORECLKDIV_HFCLK4    (0x2UL << 0)    /* HFCLK / 4 for HFCORECLK                  */
#define CMU_HFCORECLKDIV_HFCORECLKDIV_HFCLK8    (0x3UL << 0)    /* HFCLK / 8 for HFCORECLK                  */
#define CMU_HFCORECLKDIV_HFCORECLKDIV_HFCLK16   (0x4UL << 0)    /* HFCLK / 16 for HFCORECLK                 */
#define CMU_HFCORECLKDIV_HFCORECLKDIV_HFCLK32   (0x5UL << 0)    /* HFCLK / 32 for HFCORECLK                 */
#define CMU_HFCORECLKDIV_HFCORECLKDIV_HFCLK64   (0x6UL << 0)    /* HFCLK / 64 for HFCORECLK                 */
#define CMU_HFCORECLKDIV_HFCORECLKDIV_HFCLK128  (0x7UL << 0)    /* HFCLK / 128 for HFCORECLK                */
#define CMU_HFCORECLKDIV_HFCORECLKDIV_HFCLK256  (0x8UL << 0)    /* HFCLK / 256 for HFCORECLK                */
#define CMU_HFCORECLKDIV_HFCORECLKDIV_HFCLK512  (0x9UL << 0)    /* HFCLK / 512 for HFCORECLK                */
#define CMU_HFCORECLKDIV_HFCORECLKLEDIV_SHIFT   8               /* Shift value for CMU_HFCORECLKDIV_HFCORECLKEDIV*/
#define CMU_HFCORECLKDIV_HFCORECLKLEDIV_MASK    (0x1UL << 8)    /* Mask for CMU_HFCORECLKDIV_HFCORECLKEDIV  */ 
#define CMU_HFCORECLKDIV_HFCORECLKLEDIV_DEFAUT  (0x0UL << 8)    /* DEFAUT for CMU_HFCORECLKDIV_HFCORECLKEDIV*/
#define CMU_HFCORECLKDIV_HFCORECLKLEDIV_DIV2    (0x0UL << 8)    /* DIV2 for CMU_HFCORECLKEDIV_HFCORECLKEDIV */
#define CMU_HFCORECLKDIV_HFCORECLKLEDIV_DIV4    (0x1UL << 8)    /* DIV4 for CMU_HFCORECLKEDIV_HFCORECLKEDIV */

    
/* Bit fields for CMU HFPERCLKDIV */
#define CMU_HFPERCLKDIV_RESETVALUE              0x00000100UL    /* Default value for CMU_HFPERCLKDIV        */
#define CMU_HFPERCLKDIV_MASK                    0x0000010FUL    /* Mask for CMU_HFPERCLKDIV                 */
#define CMU_HFPERCLKDIV_HFPERCLKDIV_SHIFT       0               /* Shift value for CMU_HFPERCLKDIV_HFPERCLKDIV */
#define CMU_HFPERCLKDIV_HFPERCLKDIV_MASK        (0xFUL << 0)    /* Bit mask for CMU_HFPERCLKDIV_HFPERCLKDIV */
#define CMU_HFPERCLKDIV_HFPERCLKDIV_DEFAULT     (0xFUL << 0)    /* DEFAULT for CMU_HFPERCLKDIV_HFPERCLKDIV  */
#define CMU_HFPERCLKDIV_HFPERCLKDIV_HFCLK       (0x0UL << 0)    /* HFCLK for HFPERCLK                       */
#define CMU_HFPERCLKDIV_HFPERCLKDIV_HFCLK2      (0x1UL << 0)    /* HFCLK / 2 for HFPERCLK                   */
#define CMU_HFPERCLKDIV_HFPERCLKDIV_HFCLK4      (0x2UL << 0)    /* HFCLK / 4 for HFPERCLK                   */
#define CMU_HFPERCLKDIV_HFPERCLKDIV_HFCLK8      (0x3UL << 0)    /* HFCLK / 8 for HFPERCLK                   */
#define CMU_HFPERCLKDIV_HFPERCLKDIV_HFCLK16     (0x4UL << 0)    /* HFCLK / 16 for HFPERCLK                  */
#define CMU_HFPERCLKDIV_HFPERCLKDIV_HFCLK32     (0x5UL << 0)    /* HFCLK / 32 for HFPERCLK                  */
#define CMU_HFPERCLKDIV_HFPERCLKDIV_HFCLK64     (0x6UL << 0)    /* HFCLK / 64 for HFPERCLK                  */
#define CMU_HFPERCLKDIV_HFPERCLKDIV_HFCLK128    (0x7UL << 0)    /* HFCLK / 128 for HFPERCLK                 */
#define CMU_HFPERCLKDIV_HFPERCLKDIV_HFCLK256    (0x8UL << 0)    /* HFCLK / 256 for HFPERCLK                 */
#define CMU_HFPERCLKDIV_HFPERCLKDIV_HFCLK512    (0x9UL << 0)    /* HFCLK / 512 for HFPERCLK                 */
#define CMU_HFPERCLKDIV_HFPERCLKEN_SHIFT        8               /* Shift value for CMU_HFPERCLKDIV_HFPERCLKEN */
#define CMU_HFPERCLKDIV_HFPERCLKEN_MASK         (0x1UL << 8)    /* Bit mask for CMU_HFPERCLKDIV_HFPERCLKEN  */
#define CMU_HFPERCLKDIV_HFPERCLKEN_DEFAULT      (0x0UL << 8)    /* DEFAULT for CMU_HFPERCLKDIV_HFPERCLKEN   */
#define CMU_HFPERCLKDIV_HFPERCLKEN              (0x1UL << 8)    /* HFPERCLK Enable                          */
    
/* Bit fields for CMU HFRCOCTRL */
#define CMU_HFRCOCTRL_RESETVALUE                0x00000380UL    /* Default value for CMU_HFRCOCTRL          */
#define CMU_HFRCOCTRL_MASK                      0x0001F7FFUL    /* Mask for CMU_HFRCOCTRL                   */
#define CMU_HFRCOCTRL_TUNING_SHIFT              0               /* Shift value for CMU_HFRCOCTRL_TUNING     */
#define CMU_HFRCOCTRL_TUNING_MASK               (0xFFUL << 0)   /* Bit mask for CMU_HFRCOCTRL_TUNING        */
#define CMU_HFRCOCTRL_TUNING_DEFAULT            (0x80UL << 0)   /* DEFAULT for CMU_HFRCOCTRL_TUNING         */
#define CMU_HFRCOCTRL_BAND_SHIFT                8               /* Shift value for CMU_HFRCOCTRL_BAND       */
#define CMU_HFRCOCTRL_BAND_MASK                 (0x7UL  << 8)   /* Bit mask for CMU_HFRCOCTRL_BAND          */
#define CMU_HFRCOCTRL_BAND_DEFAULT              (0x3UL  << 8)   /* DEFAULT for CMU_HFRCOCTRL_BAND           */
#define CMU_HFRCOCTRL_BAND_1MHZ                 (0x0UL  << 8)   /* 1MHZ for HFRCO                           */
#define CMU_HFRCOCTRL_BAND_7MHZ                 (0x1UL  << 8)   /* 7MHZ for HFRCO                           */
#define CMU_HFRCOCTRL_BAND_11MHZ                (0x2UL  << 8)   /* 11MHZ for HFRCO                          */
#define CMU_HFRCOCTRL_BAND_14MHZ                (0x3UL  << 8)   /* 14MHZ for HFRCO                          */
#define CMU_HFRCOCTRL_BAND_21MHZ                (0x4UL  << 8)   /* 21MHZ for HFRCO                          */
#define CMU_HFRCOCTRL_BAND_28MHZ                (0x5UL  << 8)   /* 28MHZ for HFRCO                          */
#define CMU_HFRCOCTRL_SUDELAY_SHIFT             12              /* Shift value for CMU_HFRCOCTRL_SUDELAY    */
#define CMU_HFRCOCTRL_SUDELAY_MASK              (0x1FUL << 12)  /* Bit mask for CMU_HFRCOCTRL_SUDELAY       */
#define CMU_HFRCOCTRL_SUDELAY_DEFAULT           (0x0UL  << 12)  /* DEFAULT for CMU_HFRCOCTRL_HFRCOCTRL      */
    
/* Bit fields for CMU LFRCOCTRL */
#define CMU_LFRCOCTRL_RESETVALUE                0x00000040UL    /* Default value for CMU_LFRCOCTRL          */
#define CMU_LFRCOCTRL_MASK                      0x0000007FUL    /* Mask for CMU_LFRCOCTRL                   */
#define CMU_LFRCOCTRL_TUNING_SHIFT              0               /* Shift value for CMU_LFRCOCTRL_TUNING     */
#define CMU_LFRCOCTRL_TUNING_MASK               (0x7FUL << 0)   /* Bit mask for CMU_LFRCOCTRL_TUNING        */
#define CMU_LFRCOCTRL_TUNING_DEFAULT            (0x40UL << 0)   /* DEFAULT for CMU_LFRCOCTRL_TUNING         */
    
/* Bit fields for CMU AUXHFRCOCTRL */
#define CMU_AUXHFRCOCTRL_RESETVALUE             0x00000080UL    /* Default value for CMU_AUXHFRCOCTRL       */
#define CMU_AUXHFRCOCTRL_MASK                   0x000000FFUL    /* Mask for CMU_AUXHFRCOCTRL                */
#define CMU_AUXHFRCOCTRL_TUNING_SHIFT           0               /* Shift value for CMU_AUXHFRCOCTRL_TUNING  */
#define CMU_AUXHFRCOCTRL_TUNING_MASK            (0xFFUL << 0)   /* Bit mask for CMU_AUXHFRCOCTRL_TUNING     */
#define CMU_AUXHFRCOCTRL_TUNING_DEFAULT         (0x80UL << 0)   /* DEFAULT for CMU_AUXHFRCOCTRL_TUNING      */
#define CMU_AUXHFRCOCTRL_BAND_SHIFT             8               /* Shift value for CMU_AUXHFRCOCTRL_BAND    */
#define CMU_AUXHFRCOCTRL_BAND_MASK              (0x7UL << 8)    /* Bit mask for CMU_AUXHFRCOCTRL_BAND       */
#define CMU_AUXHFRCOCTRL_BAND_DEFAULT           (0x0UL << 8)    /* DEFAULT for CMU_AUXHFRCOCTRL_BAND        */   
#define CMU_AUXHFRCOCTRL_BAND_14M               (0x0UL << 8)    /* 14MHZ for CMU_AUXHFRCOCTRL_BAND          */
#define CMU_AUXHFRCOCTRL_BAND_11M               (0x1UL << 8)    /* 11MHZ for CMU_AUXHFRCOCTRL_BAND          */
#define CMU_AUXHFRCOCTRL_BAND_7M                (0x2UL << 8)    /* 7MHZ for CMU_AUXHFRCOCTRL_BAND           */
#define CMU_AUXHFRCOCTRL_BAND_1M                (0x3UL << 8)    /* 1MHZ for CMU_AUXHFRCOCTRL_BAND           */
#define CMU_AUXHFRCOCTRL_BAND_28M               (0x6UL << 8)    /* 28MHZ for CMU_AUXHFRCOCTRL_BAND          */
#define CMU_AUXHFRCOCTRL_BAND_21M               (0x7UL << 8)    /* 21MHZ for CMU_AUXHFRCOCTRL_BAND          */
    
/* Bit fields for CMU CALCTRL */
#define CMU_CALCTRL_RESETVALUE                  0x00000000UL    /* Default value for CMU_CALCTRL            */
#define CMU_CALCTRL_MASK                        0x00000007UL    /* Mask for CMU_CALCTRL                     */
#define CMU_CALCTRL_UPSEL_SHIFT                 0               /* Shift value for CMU_CALCTRL_UPSEL        */
#define CMU_CALCTRL_UPSEL_MASK                  (0x7UL << 0)    /* Bit mask for CMU_CALCTRL_UPSEL           */
#define CMU_CALCTRL_UPSEL_DEFAULT               (0x0UL << 0)    /* DEFAULT for CMU_CALCTRL_UPSEL            */
#define CMU_CALCTRL_UPSEL_HFXO                  (0x0UL << 0)    /* HFXO for CMU_CALCTRL_UPSEL               */
#define CMU_CALCTRL_UPSEL_LFXO                  (0x1UL << 0)    /* LFXO for CMU_CALCTRL_UPSEL               */
#define CMU_CALCTRL_UPSEL_HFRCO                 (0x2UL << 0)    /* HFRCO for CMU_CALCTRL_UPSEL              */
#define CMU_CALCTRL_UPSEL_LFRCO                 (0x3UL << 0)    /* LFRCO for CMU_CALCTRL_UPSEL              */
#define CMU_CALCTRL_UPSEL_AUXHFRCO              (0x4UL << 0)    /* AUXHFRCO for CMU_CALCTRL_UPSEL           */
#define CMU_CALCTRL_DOWNSEL_SHIFT               3               /* Shift value for CMU_CALCTRL_DOWNSEL      */
#define CMU_CALCTRL_DOWNSEL_MASK                (0x7UL << 3)    /* Bit mask for CMU_CALCTRL_DOWNSEL         */  
#define CMU_CALCTRL_DOWNSEL_DEFAULT             (0x0UL << 3)    /* DEFAULT for CMU_CALCTRL_DOWNSEL          */ 
#define CMU_CALCTRL_DOWNSEL_HFCLK               (0x0UL << 3)    /* HFCLK for CMU_CALCTRL_DOWNSEL            */
#define CMU_CALCTRL_DOWNSEL_HFXO                (0x1UL << 3)    /* HFXO for CMU_CALCTRL_DOWNSEL             */
#define CMU_CALCTRL_DOWNSEL_LFXO                (0x2UL << 3)    /* LFXO for CMU_CALCTRL_DOWNSEL             */
#define CMU_CALCTRL_DOWNSEL_HFRCO               (0x3UL << 3)    /* HFRCO for CMU_CALCTRL_DOWNSEL            */
#define CMU_CALCTRL_DOWNSEL_LFRCO               (0x4UL << 3)    /* LFRCO for CMU_CALCTRL_DOWNSEL            */
#define CMU_CALCTRL_DOWNSEL_AUXHFRCO            (0x5UL << 3)    /* AUXHFRCO for CMU_CALCTRL_DOWNSEL         */
#define CMU_CALCTRL_CONT_SHIFT                  6               /* Shift value for CMU_CALCTRL_CONT         */
#define CMU_CALCTRL_CONT_MASK                   (0x1UL << 6)    /* Bit mask for CMU_CALCTRL_CONT            */
#define CMU_CALCTRL_CONT_DEFAULT                (0x0UL << 6)    /* DEFAULT for CMU_CALCTRL_CONT             */
#define CMU_CALCTRL_CONT_ENABLE                 (0x1UL << 6)    /* Enalbe for CMU_CALCTRL_CONT              */
    
/* Bit fields for CMU CALCNT */
#define CMU_CALCNT_RESETVALUE                   0x00000000UL    /* Default value for CMU_CALCNT             */
#define CMU_CALCNT_MASK                         0x000FFFFFUL    /* Mask for CMU_CALCNT                      */
#define CMU_CALCNT_CALCNT_SHIFT                 0               /* Shift value for CMU_CALCNT_CALCNT        */
#define CMU_CALCNT_CALCNT_MASK                  (0xFFFFFUL << 0)/* Bit mask for CMU_CALCNT_CALCNT           */
#define CMU_CALCNT_CALCNT_DEFAULT               (0x0UL << 0)    /* DEFAULT for CMU_CALCNT_CALCNT            */
    
/* Bit fields for CMU OSCENCMD */
#define CMU_OSCENCMD_RESETVALUE                 0x00000000UL    /* Default value for CMU_OSCENCMD           */
#define CMU_OSCENCMD_MASK                       0x000003FFUL    /* Mask for CMU_OSCENCMD                    */
#define CMU_OSCENCMD_HFRCOEN_SHIFT              0               /* Shift value for CMU_OSCENCMD_HFRCOEN     */
#define CMU_OSCENCMD_HFRCOEN_MASK               (0x1UL << 0)    /* Bit mask for CMU_OSCENCMD_HFRCOEN        */
#define CMU_OSCENCMD_HFRCOEN_DEFAULT            (0x0UL << 0)    /* DEFAULT for CMU_OSCENCMD_HFRCOEN         */
#define CMU_OSCENCMD_HFRCOEN                    (0x1UL << 0)    /* HFRCO Enable                             */
#define CMU_OSCENCMD_HFRCODIS_SHIFT             1               /* Shift value for CMU_OSCENCMD_HFRCODIS    */
#define CMU_OSCENCMD_HFRCODIS_MASK              (0x1UL << 1)    /* Bit mask for CMU_OSCENCMD_HFRCODIS       */
#define CMU_OSCENCMD_HFRCODIS_DEFAULT           (0x0UL << 1)    /* DEFAULT for CMU_OSCENCMD_HFRCODIS        */
#define CMU_OSCENCMD_HFRCODIS                   (0x1UL << 1)    /* HFRCO Disable                            */
#define CMU_OSCENCMD_HFXOEN_SHIFT               2               /* Shift value for CMU_OSCENCMD_HFXOEN      */
#define CMU_OSCENCMD_HFXOEN_MASK                (0x1UL << 2)    /* Bit mask for CMU_OSCENCMD_HFXOEN         */
#define CMU_OSCENCMD_HFXOEN_DEFAULT             (0x0UL << 2)    /* DEFAULT for CMU_OSCENCMD_HFXOEN          */
#define CMU_OSCENCMD_HFXOEN                     (0x1UL << 2)    /* HFXO Enable                              */
#define CMU_OSCENCMD_HFXODIS_SHIFT              3               /* Shift value for CMU_OSCENCMD_HFXODIS     */
#define CMU_OSCENCMD_HFXODIS_MASK               (0x1UL << 3)    /* Bit mask for CMU_OSCENCMD_HFXODIS        */
#define CMU_OSCENCMD_HFXODIS_DEFAULT            (0x0UL << 3)    /* DEFAULT for CMU_OSCENCMD_HFXODIS         */
#define CMU_OSCENCMD_HFXODIS                    (0x1UL << 3)    /* HFXO Disable                             */
#define CMU_OSCENCMD_AUXHFRCOEN_SHIFT           4               /* Shift value for CMU_OSCENCMD_AUXHFRCOEN  */
#define CMU_OSCENCMD_AUXHFRCOEN_MASK            (0x1UL << 4)    /* Bit mask for CMU_OSCENCMD_AUXHFRCOEN     */
#define CMU_OSCENCMD_AUXHFRCOEN_DEFAULT         (0x0UL << 4)    /* DEFAULT for CMU_OSCENCMD_AUXHFRCOEN      */
#define CMU_OSCENCMD_AUXHFRCOEN                 (0x1UL << 4)    /* AUXHFRCO Enable                          */
#define CMU_OSCENCMD_AUXHFRCODIS_SHIFT          5               /* Shift value for CMU_OSCENCMD_AUXHFRCODIS */
#define CMU_OSCENCMD_AUXHFRCODIS_MASK           (0x1UL << 5)    /* Bit mask for CMU_OSCENCMD_AUXHFRCODIS    */
#define CMU_OSCENCMD_AUXHFRCODIS_DEFAULT        (0x0UL << 5)    /* DEFAULT for CMU_OSCENCMD_AUXHFRCODIS     */
#define CMU_OSCENCMD_AUXHFRCODIS                (0x1UL << 5)    /* AUXHFRCO Disable                         */
#define CMU_OSCENCMD_LFRCOEN_SHIFT              6               /* Shift value for CMU_OSCENCMD_LFRCOEN     */
#define CMU_OSCENCMD_LFRCOEN_MASK               (0x1UL << 6)    /* Bit mask for CMU_OSCENCMD_LFRCOEN        */
#define CMU_OSCENCMD_LFRCOEN_DEFAULT            (0x0UL << 6)    /* DEFAULT for CMU_OSCENCMD_LFRCOEN         */
#define CMU_OSCENCMD_LFRCOEN                    (0x1UL << 6)    /* LFRCO Enable                             */
#define CMU_OSCENCMD_LFRCODIS_SHIFT             7               /* Shift value for CMU_OSCENCMD_LFRCODIS    */
#define CMU_OSCENCMD_LFRCODIS_MASK              (0x1UL << 7)    /* Bit mask for CMU_OSCENCMD_LFRCODIS       */
#define CMU_OSCENCMD_LFRCODIS_DEFAULT           (0x0UL << 7)    /* DEFAULT for CMU_OSCENCMD_LFRCODIS        */
#define CMU_OSCENCMD_LFRCODIS                   (0x1UL << 7)    /* LFRCO Disable                            */
#define CMU_OSCENCMD_LFXOEN_SHIFT               8               /* Shift value for CMU_OSCENCMD_LFXOEN      */
#define CMU_OSCENCMD_LFXOEN_MASK                (0x1UL << 8)    /* Bit mask for CMU_OSCENCMD_LFXOEN         */
#define CMU_OSCENCMD_LFXOEN_DEFAULT             (0x0UL << 8)    /* DEFAULT for CMU_OSCENCMD_LFXOEN          */
#define CMU_OSCENCMD_LFXOEN                     (0x1UL << 8)    /* LFXO Enable                              */
#define CMU_OSCENCMD_LFXODIS_SHIFT              9               /* Shift value for CMU_OSCENCMD_LFXODIS     */
#define CMU_OSCENCMD_LFXODIS_MASK               (0x1UL << 9)    /* Bit mask for CMU_OSCENCMD_LFXODIS        */
#define CMU_OSCENCMD_LFXODIS_DEFAULT            (0x0UL << 9)    /* DEFAULT for CMU_OSCENCMD_LFXODIS         */
#define CMU_OSCENCMD_LFXODIS                    (0x1UL << 9)    /* LFXO Disable                             */
    
/* Bit fields for CMU CMD */
#define CMU_CMD_RESETVALUE                      0x00000000UL    /* Default value for CMU_CMD                */
#define CMU_CMD_MASK                            0x0000000FUL    /* Mask for CMU_CMD                         */
#define CMU_CMD_HFCLKSEL_SHIFT                  0               /* Shift value for CMU_CMD_HFCLKSEL         */
#define CMU_CMD_HFCLKSEL_MASK                   (0x7UL << 0)    /* Bit mask for CMU_CMD_HFCLKSEL            */
#define CMU_CMD_HFCLKSEL_DEFAULT                (0x0UL << 0)    /* DEFAULT for CMU_CMD_HFCLKSEL             */
#define CMU_CMD_HFCLKSEL_HFRCO                  (0x1UL << 0)    /* HFRCO for HFCLK                          */
#define CMU_CMD_HFCLKSEL_HFXO                   (0x2UL << 0)    /* HFXO for HFCLK                           */
#define CMU_CMD_HFCLKSEL_LFRCO                  (0x3UL << 0)    /* LFRCO for HFCLK                          */
#define CMU_CMD_HFCLKSEL_LFXO                   (0x4UL << 0)    /* LFXO for HFCLK                           */
#define CMU_CMD_CALSTART_SHIFT                  3               /* Shift value for CMU_CMD_CALSTART         */
#define CMU_CMD_CALSTART_MASK                   (0x1UL << 3)    /* Bit mask for CMU_CMD_CALSTART            */
#define CMU_CMD_CALSTART_DEFAULT                (0x0UL << 3)    /* DEFAULT for CMU_CMD_CALSTART             */
#define CMU_CMD_CALSTART                        (0x1UL << 3)    /* Calibration Start                        */
#define CMU_CMD_CALSTOP_SHIFT                   4               /* Shift value for CMU_CMD_CALSTOP          */
#define CMU_CMD_CALSTOP_MASK                    (0x1UL << 4)    /* Bit mask for CMU_CMD_CALSTOP             */
#define CMU_CMD_CALSTOP_DEFAULT                 (0x0UL << 4)    /* DEFAULT for CMU_CMD_CALSTOP              */
#define CMU_CMD_CALSTOP                         (0x1UL << 4)    /* Calibration Start                        */
#define CMU_CMD_USBCCLKSEL_SHIFT                5               /* Shift value for CMU_CMD_USBCCLKSEL       */
#define CMU_CMD_USBCCLKSEL_MASK                 (0x3UL << 5)    /* Bit mask for CMU_CMD_USBCCLKSEL          */
#define CMU_CMD_USBCCLKSEL_DEFAULT              (0x0UL << 5)    /* DEFAULT for CMU_CMD_USBCCLKSEL           */
#define CMU_CMD_USBCCLKSEL_HFCLKNODIV           (0x1UL << 5)    /* HFCLKNODIV for CMU_CMD_USBCCLKSEL        */
#define CMU_CMD_USBCCLKSEL_LFXO                 (0x2UL << 5)    /* LFXO for CMU_CMD_USBCCLKSEL              */
#define CMU_CMD_USBCCLKSEL_LFRCO                (0x3UL << 5)    /* LFRCO for CMU_CMD_USBCCLKSEL             */    
    
/* Bit fields for CMU LFCLKSEL */
#define CMU_LFCLKSEL_RESETVALUE                 0x00000005UL    /* Default value for CMU_LFCLKSEL           */
#define CMU_LFCLKSEL_MASK                       0x0000000FUL    /* Mask for CMU_LFCLKSEL                    */
#define CMU_LFCLKSEL_LFA_SHIFT                  0               /* Shift value for CMU_LFCLKSEL_LFA         */
#define CMU_LFCLKSEL_LFA_MASK                   (0x3UL << 0)    /* Bit mask for CMU_LFCLKSEL_LFA            */
#define CMU_LFCLKSEL_LFA_DEFAULT                (0x1UL << 0)    /* DEFAULT for CMU_LFCLKSEL_LFA             */
#define CMU_LFCLKSEL_LFA_DISABLED               (0x0UL << 0)    /* DISABLED for LFACLK                      */
#define CMU_LFCLKSEL_LFA_LFRCO                  (0x1UL << 0)    /* LFRCO for LFACLK                         */
#define CMU_LFCLKSEL_LFA_LFXO                   (0x2UL << 0)    /* LFXO for LFACLK                          */
#define CMU_LFCLKSEL_LFA_HFCORECLKLEDIV2        (0x3UL << 0)    /* HFCORECLKLE / 2 for LFACLK               */
#define CMU_LFCLKSEL_LFB_SHIFT                  2               /* Shift value for CMU_LFCLKSEL_LFB         */
#define CMU_LFCLKSEL_LFB_MASK                   (0x3UL << 2)    /* Bit mask for CMU_LFCLKSEL_LFB            */
#define CMU_LFCLKSEL_LFB_DEFAULT                (0x1UL << 2)    /* DEFAULT for CMU_LFCLKSEL_LFB             */
#define CMU_LFCLKSEL_LFB_DISABLED               (0x0UL << 2)    /* DISABLED for LFBCLK                      */
#define CMU_LFCLKSEL_LFB_LFRCO                  (0x1UL << 2)    /* LFRCO for LFBCLK                         */
#define CMU_LFCLKSEL_LFB_LFXO                   (0x2UL << 2)    /* LFXO for LFBCLK                          */
#define CMU_LFCLKSEL_LFB_HFCORECLKLEDIV2        (0x3UL << 2)    /* HFCORECLKLE / 2 for LFBCLK               */
#define CMU_LFCLKSEL_LFAE_SHIFT                 16               /* Shift value for CMU_LFCLKSEL_LFAE       */
#define CMU_LFCLKSEL_LFAE_MASK                  (0x1UL << 16)    /* Bit mask for CMU_LFCLKSEL_LFAE          */
#define CMU_LFCLKSEL_LFAE_DEFAULT               (0x0UL << 16)    /* DEFAULT for CMU_LFCLKSEL_LFAE           */
#define CMU_LFCLKSEL_LFAE_DISABLED              (0x0UL << 16)    /* DISABLED for CMU_LFCLKSEL_LFAE          */  
#define CMU_LFCLKSEL_LFAE_ULFRCO                (0x1UL << 16)    /* ULFRCO for CMU_LFCLKSEL_LFAE            */ 
#define CMU_LFCLKSEL_LFBE_SHIFT                 20               /* Shift value for CMU_LFCLKSEL_LFBE       */
#define CMU_LFCLKSEL_LFBE_MASK                  (0x1UL << 20)    /* Bit mask for CMU_LFCLKSEL_LFBE          */
#define CMU_LFCLKSEL_LFBE_DEFAULT               (0x0UL << 20)    /* DEFAULT for CMU_LFCLKSEL_LFBE           */
#define CMU_LFCLKSEL_LFBE_DISABLED              (0x0UL << 20)    /* DISABLED for CMU_LFCLKSEL_LFBE          */  
#define CMU_LFCLKSEL_LFBE_ULFRCO                (0x1UL << 20)    /* ULFRCO for CMU_LFCLKSEL_LFBE            */ 
   
/* Bit fields for CMU STATUS */
#define CMU_STATUS_RESETVALUE                   0x00000403UL    /* Default value for CMU_STATUS             */
#define CMU_STATUS_MASK                         0x00007FFFUL    /* Mask for CMU_STATUS                      */
#define CMU_STATUS_HFRCOENS_SHIFT               0               /* Shift value for CMU_STATUS_HFRCOENS      */
#define CMU_STATUS_HFRCOENS_MASK                (0x1UL << 0)    /* Bit mask for CMU_STATUS_HFRCOENS         */
#define CMU_STATUS_HFRCOENS_DEFAULT             (0x0UL << 0)    /* DEFAULT for CMU_STATUS_HFRCOENS          */
#define CMU_STATUS_HFRCOENS                     (0x1UL << 0)    /* HFRCO Enable Status                      */
#define CMU_STATUS_HFRCORDY_SHIFT               1               /* Shift value for CMU_STATUS_HFRCORDY      */
#define CMU_STATUS_HFRCORDY_MASK                (0x1UL << 1)    /* Bit mask for CMU_STATUS_HFRCORDY         */
#define CMU_STATUS_HFRCORDY_DEFAULT             (0x0UL << 1)    /* DEFAULT for CMU_STATUS_HFRCORDY          */
#define CMU_STATUS_HFRCORDY                     (0x1UL << 1)    /* HFRCO Ready                              */
#define CMU_STATUS_HFXOENS_SHIFT                2               /* Shift value for CMU_STATUS_HFXOENS       */
#define CMU_STATUS_HFXOENS_MASK                 (0x1UL << 2)    /* Bit mask for CMU_STATUS_HFXOENS          */
#define CMU_STATUS_HFXOENS_DEFAULT              (0x0UL << 2)    /* DEFAULT for CMU_STATUS_HFXOENS           */
#define CMU_STATUS_HFXOENS                      (0x1UL << 2)    /* HFXO Enable Status                       */
#define CMU_STATUS_HFXORDY_SHIFT                3               /* Shift value for CMU_STATUS_HFXORDY       */
#define CMU_STATUS_HFXORDY_MASK                 (0x1UL << 3)    /* Bit mask for CMU_STATUS_HFXORDY          */
#define CMU_STATUS_HFXORDY_DEFAULT              (0x0UL << 3)    /* DEFAULT for CMU_STATUS_HFXORDY           */
#define CMU_STATUS_HFXORDY                      (0x1UL << 3)    /* HFXO Ready                               */
#define CMU_STATUS_AUXHFRCOENS_SHIFT            4               /* Shift value for CMU_STATUS_AUXHFRCOENS   */
#define CMU_STATUS_AUXHFRCOENS_MASK             (0x1UL << 4)    /* Bit mask for CMU_STATUS_AUXHFRCOENS      */
#define CMU_STATUS_AUXHFRCOENS_DEFAULT          (0x0UL << 4)    /* DEFAULT for CMU_STATUS_AUXHFRCOENS       */
#define CMU_STATUS_AUXHFRCOENS                  (0x1UL << 4)    /* AUXHFRCO Enable Status                   */
#define CMU_STATUS_AUXHFRCORDY_SHIFT            5               /* Shift value for CMU_STATUS_AUXHFRCORDY   */
#define CMU_STATUS_AUXHFRCORDY_MASK             (0x1UL << 5)    /* Bit mask for CMU_STATUS_AUXHFRCORDY      */
#define CMU_STATUS_AUXHFRCORDY_DEFAULT          (0x0UL << 5)    /* DEFAULT for CMU_STATUS_AUXHFRCORDY       */
#define CMU_STATUS_AUXHFRCORDY                  (0x1UL << 5)    /* AUXHFRCO Ready                           */
#define CMU_STATUS_LFRCOENS_SHIFT               6               /* Shift value for CMU_STATUS_LFRCOENS      */
#define CMU_STATUS_LFRCOENS_MASK                (0x1UL << 6)    /* Bit mask for CMU_STATUS_LFRCOENS         */
#define CMU_STATUS_LFRCOENS_DEFAULT             (0x0UL << 6)    /* DEFAULT for CMU_STATUS_LFRCOENS          */
#define CMU_STATUS_LFRCOENS                     (0x1UL << 6)    /* LFRCO Enable Status                      */
#define CMU_STATUS_LFRCORDY_SHIFT               7               /* Shift value for CMU_STATUS_LFRCORDY      */
#define CMU_STATUS_LFRCORDY_MASK                (0x1UL << 7)    /* Bit mask for CMU_STATUS_LFRCORDY         */
#define CMU_STATUS_LFRCORDY_DEFAULT             (0x0UL << 7)    /* DEFAULT for CMU_STATUS_LFRCORDY          */
#define CMU_STATUS_LFRCORDY                     (0x1UL << 7)    /* LFRCO Ready                              */
#define CMU_STATUS_LFXOENS_SHIFT                8               /* Shift value for CMU_STATUS_LFXOENS       */
#define CMU_STATUS_LFXOENS_MASK                 (0x1UL << 8)    /* Bit mask for CMU_STATUS_LFXOENS          */
#define CMU_STATUS_LFXOENS_DEFAULT              (0x0UL << 8)    /* DEFAULT for CMU_STATUS_LFXOENS           */
#define CMU_STATUS_LFXOENS                      (0x1UL << 8)    /* LFXO Enable Status                       */
#define CMU_STATUS_LFXORDY_SHIFT                9               /* Shift value for CMU_STATUS_LFXORDY       */
#define CMU_STATUS_LFXORDY_MASK                 (0x1UL << 9)    /* Bit mask for CMU_STATUS_LFXORDY          */
#define CMU_STATUS_LFXORDY_DEFAULT              (0x1UL << 9)    /* DEFAULT for CMU_STATUS_LFXORDY           */
#define CMU_STATUS_LFXORDY                      (0x1UL << 9)    /* LFXO Ready                               */
#define CMU_STATUS_HFRCOSEL_SHIFT               10              /* Shift value for CMU_STATUS_HFRCOSEL      */
#define CMU_STATUS_HFRCOSEL_MASK                (0x1UL << 10)   /* Bit mask for CMU_STATUS_HFRCOSEL         */
#define CMU_STATUS_HFRCOSEL_DEFAULT             (0x0UL << 10)   /* DEFAULT for CMU_STATUS_HFRCOSEL          */
#define CMU_STATUS_HFRCOSEL                     (0x1UL << 10)   /* HFRCO Selected                           */
#define CMU_STATUS_HFXOSEL_SHIFT                11              /* Shift value for CMU_STATUS_HFXOSEL       */
#define CMU_STATUS_HFXOSEL_MASK                 (0x1UL << 11)   /* Bit mask for CMU_STATUS_HFXOSEL          */
#define CMU_STATUS_HFXOSEL_DEFAULT              (0x0UL << 11)   /* DEFAULT for CMU_STATUS_HFXOSEL           */
#define CMU_STATUS_HFXOSEL                      (0x1UL << 11)   /* HFXO Selected                            */
#define CMU_STATUS_LFRCOSEL_SHIFT               12              /* Shift value for CMU_STATUS_LFRCOSEL      */
#define CMU_STATUS_LFRCOSEL_MASK                (0x1UL << 12)   /* Bit mask for CMU_STATUS_LFRCOSEL         */
#define CMU_STATUS_LFRCOSEL_DEFAULT             (0x1UL << 12)   /* DEFAULT for CMU_STATUS_LFRCOSEL          */
#define CMU_STATUS_LFRCOSEL                     (0x1UL << 12)   /* LFRCO Selected                           */
#define CMU_STATUS_LFXOSEL_SHIFT                13              /* Shift value for CMU_STATUS_LFXOSEL       */
#define CMU_STATUS_LFXOSEL_MASK                 (0x1UL << 13)   /* Bit mask for CMU_STATUS_LFXOSEL          */
#define CMU_STATUS_LFXOSEL_DEFAULT              (0x0UL << 13)   /* DEFAULT for CMU_STATUS_LFXOSEL           */
#define CMU_STATUS_LFXOSEL                      (0x1UL << 13)   /* LFXO Selected                            */
#define CMU_STATUS_CALBSY_SHIFT                 14              /* Shift value for CMU_STATUS_CALBSY        */
#define CMU_STATUS_CALBSY_MASK                  (0x1UL << 14)   /* Bit mask for CMU_STATUS_CALBSY           */
#define CMU_STATUS_CALBSY_DEFAULT               (0x0UL << 14)   /* DEFAULT for CMU_STATUS_CALBSY            */
#define CMU_STATUS_CALBSY                       (0x1UL << 14)   /* Calibration Busy                         */
#define CMU_STATUS_USBCHFCLKSEL_SHIFT           15              /* Shift value for CMU_STATUS_USBCHFCLKSEL  */
#define CMU_STATUS_USBCHFCLKSEL_MASK            (0x1UL << 15)   /* Bit mask for CMU_STATUS_USBCHFCLKSEL     */
#define CMU_STATUS_USBCHFCLKSEL_DEFAULT         (0x0UL << 15)   /* DEFAULT for CMU_STATUS_USBCHFCLKSEL      */
#define CMU_STATUS_USBCHFCLKSEL                 (0x1UL << 15)   /* USBC HFCLK Selected                      */
#define CMU_STATUS_USBCLFXOSEL_SHIFT            16              /* Shift value for CMU_STATUS_USBCLFXOSEL   */
#define CMU_STATUS_USBCLFXOSEL_MASK             (0x1UL << 16)   /* Bit mask for CMU_STATUS_USBCLFXOSEL      */
#define CMU_STATUS_USBCLFXOSEL_DEFAULT          (0x0UL << 16)   /* DEFAULT for CMU_STATUS_USBCLFXOSEL       */
#define CMU_STATUS_USBCLFXOSEL                  (0x1UL << 16)   /* USBC LFXO Selected                       */ 
#define CMU_STATUS_USBCLFRCOSEL_SHIFT           17              /* Shift value for CMU_STATUS_USBCLFRCOSEL  */
#define CMU_STATUS_USBCLFRCOSEL_MASK            (0x1UL << 17)   /* Bit mask for CMU_STATUS_USBCLFRCOSEL     */
#define CMU_STATUS_USBCLFRCOSEL_DEFAULT         (0x0UL << 17)   /* DEFAULT for CMU_STATUS_USBCLFRCOSEL      */
#define CMU_STATUS_USBCLFRCOSEL                 (0x1UL << 17)   /* USBC LFRCO Selected                      */
    
/* Bit fields for CMU IF */
#define CMU_IF_RESETVALUE                       0x00000001UL    /* Default value for CMU_IF                 */
#define CMU_IF_MASK                             0x0000003FUL    /* Mask for CMU_IF                          */
#define CMU_IF_HFRCORDY_SHIFT                   0               /* Shift value for CMU_IF_HFRCORDY          */
#define CMU_IF_HFRCORDY_MASK                    (0x1UL << 0)    /* Bit mask for CMU_IF_HFRCORDY             */
#define CMU_IF_HFRCORDY_DEFAULT                 (0x0UL << 0)    /* DEFAULT for CMU_IF_HFRCORDY              */
#define CMU_IF_HFRCORDY                         (0x1UL << 0)    /* HFRCO Ready Interrupt Flag               */
#define CMU_IF_HFXORDY_SHIFT                    1               /* Shift value for CMU_IF_HFXORDY           */
#define CMU_IF_HFXORDY_MASK                     (0x1UL << 1)    /* Bit mask for CMU_IF_HFXORDY              */
#define CMU_IF_HFXORDY_DEFAULT                  (0x0UL << 1)    /* DEFAULT for CMU_IF_HFXORDY               */
#define CMU_IF_HFXORDY                          (0x1UL << 1)    /* HFXO Ready Interrupt Flag                */
#define CMU_IF_LFRCORDY_SHIFT                   2               /* Shift value for CMU_IF_LFRCORDY          */
#define CMU_IF_LFRCORDY_MASK                    (0x1UL << 2)    /* Bit mask for CMU_IF_LFRCORDY             */
#define CMU_IF_LFRCORDY_DEFAULT                 (0x0UL << 2)    /* DEFAULT for CMU_IF_LFRCORDY              */
#define CMU_IF_LFRCORDY                         (0x1UL << 2)    /* LFRCO Ready Interrupt Flag               */
#define CMU_IF_LFXORDY_SHIFT                    3               /* Shift value for CMU_IF_LFXORDY           */
#define CMU_IF_LFXORDY_MASK                     (0x1UL << 3)    /* Bit mask for CMU_IF_LFXORDY              */
#define CMU_IF_LFXORDY_DEFAULT                  (0x0UL << 3)    /* DEFAULT for CMU_IF_LFXORDY               */
#define CMU_IF_LFXORDY                          (0x1UL << 3)    /* LFXO Ready Interrupt Flag                */
#define CMU_IF_AUXHFRCORDY_SHIFT                4               /* Shift value for CMU_IF_AUXHFRCORDY       */
#define CMU_IF_AUXHFRCORDY_MASK                 (0x1UL << 4)    /* Bit mask for CMU_IF_AUXHFRCORDY          */
#define CMU_IF_AUXHFRCORDY_DEFAULT              (0x0UL << 4)    /* DEFAULT for CMU_IF_AUXHFRCORDY           */
#define CMU_IF_AUXHFRCORDY                      (0x1UL << 4)    /* AUXHFRCO Ready Interrupt Flag            */
#define CMU_IF_CALRDY_SHIFT                     5               /* Shift value for CMU_IF_CALRDY            */
#define CMU_IF_CALRDY_MASK                      (0x1UL << 5)    /* Bit mask for CMU_IF_CALRDY               */
#define CMU_IF_CALRDY_DEFAULT                   (0x0UL << 5)    /* DEFAULT for CMU_IF_CALRDY                */
#define CMU_IF_CALRDY                           (0x1UL << 5)    /* Calibration Ready Interrupt Flag         */
#define CMU_IF_CALOF_SHIFT                      6               /* Shift value for CMU_IF_CALOF             */
#define CMU_IF_CALOF_MASK                       (0x1UL << 6)    /* Bit mask for CMU_IF_CALOF                */
#define CMU_IF_CALOF_DEFAULT                    (0x0UL << 6)    /* DEFAULT for CMU_IF_CALOF                 */
#define CMU_IF_CALOF                            (0x1UL << 6)    /* Calibration Overflow Interrupt Flag      */
#define CMU_IF_USBCHFCLKSEL_SHIFT               7               /* Shift value for CMU_IF_USBCHFCLKSEL      */
#define CMU_IF_USBCHFCLKSEL_MASK                (0x1UL << 7)    /* Bit mask for CMU_IF_USBCHFCLKSEL         */
#define CMU_IF_USBCHFCLKSEL_DEFAULT             (0x0UL << 7)    /* DEFAULT for CMU_IF_USBCHFCLKSEL          */
#define CMU_IF_USBCHFCLKSEL                     (0x1UL << 7)    /* USBC HFCLK Selected Interrupt Flag       */
    
/* Bit fields for CMU IFS */
#define CMU_IFS_RESETVALUE                      0x00000001UL    /* Default value for CMU_IFS                */
#define CMU_IFS_MASK                            0x0000003FUL    /* Mask for CMU_IFS                         */
#define CMU_IFS_HFRCORDY_SHIFT                  0               /* Shift value for CMU_IFS_HFRCORDY         */
#define CMU_IFS_HFRCORDY_MASK                   (0x1UL << 0)    /* Bit mask for CMU_IFS_HFRCORDY            */
#define CMU_IFS_HFRCORDY_DEFAULT                (0x0UL << 0)    /* DEFAULT for CMU_IFS_HFRCORDY             */
#define CMU_IFS_HFRCORDY                        (0x1UL << 0)    /* HFRCO Ready Interrupt Flag Set           */
#define CMU_IFS_HFXORDY_SHIFT                   1               /* Shift value for CMU_IFS_HFXORDY          */
#define CMU_IFS_HFXORDY_MASK                    (0x1UL << 1)    /* Bit mask for CMU_IFS_HFXORDY             */
#define CMU_IFS_HFXORDY_DEFAULT                 (0x0UL << 1)    /* DEFAULT for CMU_IFS_HFXORDY              */
#define CMU_IFS_HFXORDY                         (0x1UL << 1)    /* HFXO Ready Interrupt Flag Set            */
#define CMU_IFS_LFRCORDY_SHIFT                  2               /* Shift value for CMU_IFS_LFRCORDY         */
#define CMU_IFS_LFRCORDY_MASK                   (0x1UL << 2)    /* Bit mask for CMU_IFS_LFRCORDY            */
#define CMU_IFS_LFRCORDY_DEFAULT                (0x0UL << 2)    /* DEFAULT for CMU_IFS_LFRCORDY             */
#define CMU_IFS_LFRCORDY                        (0x1UL << 2)    /* LFRCO Ready Interrupt Flag Set           */
#define CMU_IFS_LFXORDY_SHIFT                   3               /* Shift value for CMU_IFS_LFXORDY          */
#define CMU_IFS_LFXORDY_MASK                    (0x1UL << 3)    /* Bit mask for CMU_IFS_LFXORDY             */
#define CMU_IFS_LFXORDY_DEFAULT                 (0x0UL << 3)    /* DEFAULT for CMU_IFS_LFXORDY              */
#define CMU_IFS_LFXORDY                         (0x1UL << 3)    /* LFXO Ready Interrupt Flag Set            */
#define CMU_IFS_AUXHFRCORDY_SHIFT               4               /* Shift value for CMU_IFS_AUXHFRCORDY      */
#define CMU_IFS_AUXHFRCORDY_MASK                (0x1UL << 4)    /* Bit mask for CMU_IFS_AUXHFRCORDY         */
#define CMU_IFS_AUXHFRCORDY_DEFAULT             (0x0UL << 4)    /* DEFAULT for CMU_IFS_AUXHFRCORDY          */
#define CMU_IFS_AUXHFRCORDY                     (0x1UL << 4)    /* AUXHFRCO Ready Interrupt Flag Set        */
#define CMU_IFS_CALRDY_SHIFT                    5               /* Shift value for CMU_IFS_CALRDY           */
#define CMU_IFS_CALRDY_MASK                     (0x1UL << 5)    /* Bit mask for CMU_IFS_CALRDY              */
#define CMU_IFS_CALRDY_DEFAULT                  (0x0UL << 5)    /* DEFAULT for CMU_IFS_CALRDY               */
#define CMU_IFS_CALRDY                          (0x1UL << 5)    /* Calibration Ready Interrupt Flag Set     */
#define CMU_IFS_CALOF_SHIFT                     6               /* Shift value for CMU_IFS_CALOF            */
#define CMU_IFS_CALOF_MASK                      (0x1UL << 6)    /* Bit mask for CMU_IFS_CALOF               */
#define CMU_IFS_CALOF_DEFAULT                   (0x0UL << 6)    /* DEFAULT for CMU_IFS_CALOF                */
#define CMU_IFS_CALOF                           (0x1UL << 6)    /* Calibration Overflow Interrupt Flag Set  */
#define CMU_IFS_USBCHFCLKSEL_SHIFT              7               /* Shift value for CMU_IFS_USBCHFCLKSEL     */
#define CMU_IFS_USBCHFCLKSEL_MASK               (0x1UL << 7)    /* Bit mask for CMU_IFS_USBCHFCLKSEL        */
#define CMU_IFS_USBCHFCLKSEL_DEFAULT            (0x0UL << 7)    /* DEFAULT for CMU_IFS_USBCHFCLKSEL         */
#define CMU_IFS_USBCHFCLKSEL                    (0x1UL << 7)    /* USBC HFCLK Selected Interrupt Flag Set   */
    
/* Bit fields for CMU IFC */
#define CMU_IFC_RESETVALUE                      0x00000001UL    /* Default value for CMU_IFC                */
#define CMU_IFC_MASK                            0x0000003FUL    /* Mask for CMU_IFC                         */
#define CMU_IFC_HFRCORDY_SHIFT                  0               /* Shift value for CMU_IFC_HFRCORDY         */
#define CMU_IFC_HFRCORDY_MASK                   (0x1UL << 0)    /* Bit mask for CMU_IFC_HFRCORDY            */
#define CMU_IFC_HFRCORDY_DEFAULT                (0x0UL << 0)    /* DEFAULT for CMU_IFC_HFRCORDY             */
#define CMU_IFC_HFRCORDY                        (0x1UL << 0)    /* HFRCO Ready Interrupt Flag Clear         */
#define CMU_IFC_HFXORDY_SHIFT                   1               /* Shift value for CMU_IFC_HFXORDY          */
#define CMU_IFC_HFXORDY_MASK                    (0x1UL << 1)    /* Bit mask for CMU_IFC_HFXORDY             */
#define CMU_IFC_HFXORDY_DEFAULT                 (0x0UL << 1)    /* DEFAULT for CMU_IFC_HFXORDY              */
#define CMU_IFC_HFXORDY                         (0x1UL << 1)    /* HFXO Ready Interrupt Flag Clear          */
#define CMU_IFC_LFRCORDY_SHIFT                  2               /* Shift value for CMU_IFC_LFRCORDY         */
#define CMU_IFC_LFRCORDY_MASK                   (0x1UL << 2)    /* Bit mask for CMU_IFC_LFRCORDY            */
#define CMU_IFC_LFRCORDY_DEFAULT                (0x0UL << 2)    /* DEFAULT for CMU_IFC_LFRCORDY             */
#define CMU_IFC_LFRCORDY                        (0x1UL << 2)    /* LFRCO Ready Interrupt Flag Clear         */
#define CMU_IFC_LFXORDY_SHIFT                   3               /* Shift value for CMU_IFC_LFXORDY          */
#define CMU_IFC_LFXORDY_MASK                    (0x1UL << 3)    /* Bit mask for CMU_IFC_LFXORDY             */
#define CMU_IFC_LFXORDY_DEFAULT                 (0x0UL << 3)    /* DEFAULT for CMU_IFC_LFXORDY              */
#define CMU_IFC_LFXORDY                         (0x1UL << 3)    /* LFXO Ready Interrupt Flag Clear          */
#define CMU_IFC_AUXHFRCORDY_SHIFT               4               /* Shift value for CMU_IFC_AUXHFRCORDY      */
#define CMU_IFC_AUXHFRCORDY_MASK                (0x1UL << 4)    /* Bit mask for CMU_IFC_AUXHFRCORDY         */
#define CMU_IFC_AUXHFRCORDY_DEFAULT             (0x0UL << 4)    /* DEFAULT for CMU_IFC_AUXHFRCORDY          */
#define CMU_IFC_AUXHFRCORDY                     (0x1UL << 4)    /* AUXHFRCO Ready Interrupt Flag Clear      */
#define CMU_IFC_CALRDY_SHIFT                    5               /* Shift value for CMU_IFC_CALRDY           */
#define CMU_IFC_CALRDY_MASK                     (0x1UL << 5)    /* Bit mask for CMU_IFC_CALRDY              */
#define CMU_IFC_CALRDY_DEFAULT                  (0x0UL << 5)    /* DEFAULT for CMU_IFC_CALRDY               */
#define CMU_IFC_CALRDY                          (0x1UL << 5)    /* Calibration Ready Interrupt Flag Clear   */
#define CMU_IFC_CALOF_SHIFT                     6               /* Shift value for CMU_IFC_CALOF            */
#define CMU_IFC_CALOF_MASK                      (0x1UL << 6)    /* Bit mask for CMU_IFC_CALOF               */
#define CMU_IFC_CALOF_DEFAULT                   (0x0UL << 6)    /* DEFAULT for CMU_IFC_CALOF                */
#define CMU_IFC_CALOF                           (0x1UL << 6)    /* Calibration Overflow Interrupt Flag Clear*/
#define CMU_IFC_USBCHFCLKSEL_SHIFT              7               /* Shift value for CMU_IFC_USBCHFCLKSEL     */
#define CMU_IFC_USBCHFCLKSEL_MASK               (0x1UL << 7)    /* Bit mask for CMU_IFC_USBCHFCLKSEL        */
#define CMU_IFC_USBCHFCLKSEL_DEFAULT            (0x0UL << 7)    /* DEFAULT for CMU_IFC_USBCHFCLKSEL         */
#define CMU_IFC_USBCHFCLKSEL                    (0x1UL << 7)    /* USBC HFCLK Selected Interrupt Flag Clear */
    
/* Bit fields for CMU IEN */
#define CMU_IEN_RESETVALUE                      0x00000001UL    /* Default value for CMU_IEN                */
#define CMU_IEN_MASK                            0x0000003FUL    /* Mask for CMU_IFE                         */
#define CMU_IEN_HFRCORDY_SHIFT                  0               /* Shift value for CMU_IEN_HFRCORDY         */
#define CMU_IEN_HFRCORDY_MASK                   (0x1UL << 0)    /* Bit mask for CMU_IEN_HFRCORDY            */
#define CMU_IEN_HFRCORDY_DEFAULT                (0x0UL << 0)    /* DEFAULT for CMU_IEN_HFRCORDY             */
#define CMU_IEN_HFRCORDY                        (0x1UL << 0)    /* HFRCO Ready Interrupt Enable             */
#define CMU_IEN_HFXORDY_SHIFT                   1               /* Shift value for CMU_IEN_HFXORDY          */
#define CMU_IEN_HFXORDY_MASK                    (0x1UL << 1)    /* Bit mask for CMU_IEN_HFXORDY             */
#define CMU_IEN_HFXORDY_DEFAULT                 (0x0UL << 1)    /* DEFAULT for CMU_IEN_HFXORDY              */
#define CMU_IEN_HFXORDY                         (0x1UL << 1)    /* HFXO Ready Interrupt Enable              */
#define CMU_IEN_LFRCORDY_SHIFT                  2               /* Shift value for CMU_IEN_LFRCORDY         */
#define CMU_IEN_LFRCORDY_MASK                   (0x1UL << 2)    /* Bit mask for CMU_IEN_LFRCORDY            */
#define CMU_IEN_LFRCORDY_DEFAULT                (0x0UL << 2)    /* DEFAULT for CMU_IEN_LFRCORDY             */
#define CMU_IEN_LFRCORDY                        (0x1UL << 2)    /* LFRCO Ready Interrupt Enable             */
#define CMU_IEN_LFXORDY_SHIFT                   3               /* Shift value for CMU_IEN_LFXORDY          */
#define CMU_IEN_LFXORDY_MASK                    (0x1UL << 3)    /* Bit mask for CMU_IEN_LFXORDY             */
#define CMU_IEN_LFXORDY_DEFAULT                 (0x0UL << 3)    /* DEFAULT for CMU_IEN_LFXORDY              */
#define CMU_IEN_LFXORDY                         (0x1UL << 3)    /* LFXO Ready Interrupt Enable              */
#define CMU_IEN_AUXHFRCORDY_SHIFT               4               /* Shift value for CMU_IEN_AUXHFRCORDY      */
#define CMU_IEN_AUXHFRCORDY_MASK                (0x1UL << 4)    /* Bit mask for CMU_IEN_AUXHFRCORDY         */
#define CMU_IEN_AUXHFRCORDY_DEFAULT             (0x0UL << 4)    /* DEFAULT for CMU_IEN_AUXHFRCORDY          */
#define CMU_IEN_AUXHFRCORDY                     (0x1UL << 4)    /* AUXHFRCO Ready Interrupt Enable          */
#define CMU_IEN_CALRDY_SHIFT                    5               /* Shift value for CMU_IEN_CALRDY           */
#define CMU_IEN_CALRDY_MASK                     (0x1UL << 5)    /* Bit mask for CMU_IEN_CALRDY              */
#define CMU_IEN_CALRDY_DEFAULT                  (0x0UL << 5)    /* DEFAULT for CMU_IEN_CALRDY               */
#define CMU_IEN_CALRDY                          (0x1UL << 5)    /* Calibration Ready Interrupt Enable       */
#define CMU_IEN_CALOF_SHIFT                     6               /* Shift value for CMU_IEN_CALOF            */
#define CMU_IEN_CALOF_MASK                      (0x1UL << 6)    /* Bit mask for CMU_IEN_CALOF               */
#define CMU_IEN_CALOF_DEFAULT                   (0x0UL << 6)    /* DEFAULT for CMU_IEN_CALOF                */
#define CMU_IEN_CALOF                           (0x1UL << 6)    /* Calibration Overflow Interrupt Enable    */
#define CMU_IEN_USBCHFCLKSEL_SHIFT              7               /* Shift value for CMU_IEN_USBCHFCLKSEL     */
#define CMU_IEN_USBCHFCLKSEL_MASK               (0x1UL << 7)    /* Bit mask for CMU_IEN_USBCHFCLKSEL        */
#define CMU_IEN_USBCHFCLKSEL_DEFAULT            (0x0UL << 7)    /* DEFAULT for CMU_IEN_USBCHFCLKSEL         */
#define CMU_IEN_USBCHFCLKSEL                    (0x1UL << 7)    /* USBC HFCLK Selected Interrupt Enable     */
    
/* Bit fields for CMU HFCORECLKEN0 */
#define CMU_HFCORECLKEN0_RESETVALUE             0x00000000UL    /* Default value for CMU_HFCORECLKEN0       */
#define CMU_HFCORECLKEN0_MASK                   0x0000000FUL    /* Mask for CMU_HFCORECLKEN0                */
#define CMU_HFCORECLKEN0_DMA_SHIFT              0               /* Shift value for CMU_HFCORECLKEN0_DMA     */
#define CMU_HFCORECLKEN0_DMA_MASK               (0x1UL << 0)    /* Bit mask for CMU_HFCORECLKEN0_DMA        */
#define CMU_HFCORECLKEN0_DMA_DEFAULT            (0x0UL << 0)    /* DEFAULT for CMU_HFCORECLKEN0_DMA         */
#define CMU_HFCORECLKEN0_DMA                    (0x1UL << 0)    /* Direct Memory Access Controller Clock Enable */    
#define CMU_HFCORECLKEN0_AES_SHIFT              1               /* Shift value for CMU_HFCORECLKEN0_AES     */
#define CMU_HFCORECLKEN0_AES_MASK               (0x1UL << 1)    /* Bit mask for CMU_HFCORECLKEN0_AES        */
#define CMU_HFCORECLKEN0_AES_DEFAULT            (0x0UL << 1)    /* DEFAULT for CMU_HFCORECLKEN0_AES         */
#define CMU_HFCORECLKEN0_AES                    (0x1UL << 1)    /* Advanced Encryption Standard Accelerator Clock Enable */
#define CMU_HFCORECLKEN0_USBC_SHIFT             2               /* Shift value for CMU_HFCORECLKEN0_USBC    */
#define CMU_HFCORECLKEN0_USBC_MASK              (0x1UL << 2)    /* Bit mask for CMU_HFCORECLKEN0_USBC       */
#define CMU_HFCORECLKEN0_USBC_DEFAULT           (0x0UL << 2)    /* DEFAULT for CMU_HFCORECLKEN0_USBC        */
#define CMU_HFCORECLKEN0_USBC                   (0x1UL << 2)    /* Universal Serial Bus Interface Core Clock Enable */  
#define CMU_HFCORECLKEN0_USB_SHIFT              3               /* Shift value for CMU_HFCORECLKEN0_USB     */
#define CMU_HFCORECLKEN0_USB_MASK               (0x1UL << 3)    /* Bit mask for CMU_HFCORECLKEN0_USB        */
#define CMU_HFCORECLKEN0_USB_DEFAULT            (0x0UL << 3)    /* DEFAULT for CMU_HFCORECLKEN0_USB         */
#define CMU_HFCORECLKEN0_USB                    (0x1UL << 3)    /* Universal Serial Bus Interface Clock Enable */       
#define CMU_HFCORECLKEN0_LE_SHIFT               4               /* Shift value for CMU_HFCORECLKEN0_LE      */
#define CMU_HFCORECLKEN0_LE_MASK                (0x1UL << 4)    /* Bit mask for CMU_HFCORECLKEN0_LE         */
#define CMU_HFCORECLKEN0_LE_DEFAULT             (0x0UL << 4)    /* DEFAULT for CMU_HFCORECLKEN0_LE          */
#define CMU_HFCORECLKEN0_LE                     (0x1UL << 4)    /* Low Energy Peripheral Interface Clock Enable */
#define CMU_HFCORECLKEN0_EBI_SHIFT              5               /* Shift value for CMU_HFCORECLKEN0_EBI     */
#define CMU_HFCORECLKEN0_EBI_MASK               (0x1UL << 5)    /* Bit mask for CMU_HFCORECLKEN0_EBI        */
#define CMU_HFCORECLKEN0_EBI_DEFAULT            (0x0UL << 5)    /* DEFAULT for CMU_HFCORECLKEN0_EBI         */
#define CMU_HFCORECLKEN0_EBI                    (0x1UL << 5)    /* External Bus Interface Clock Enable      */
    
/* Bit fields for CMU HFPERCLKEN0 */
#define CMU_HFPERCLKEN0_RESETVALUE              0x00000000UL    /* Default value for CMU_HFPERCLKEN0        */
#define CMU_HFPERCLKEN0_MASK                    0x0000FFFFUL    /* Mask for CMU_HFPERCLKEN0                 */
#define CMU_HFPERCLKEN0_USART0_SHIFT            0               /* Shift value for CMU_HFPERCLKEN0_USART0   */
#define CMU_HFPERCLKEN0_USART0_MASK             (0x1UL << 0)    /* Bit mask for CMU_HFPERCLKEN0_USART0      */
#define CMU_HFPERCLKEN0_USART0_DEFAULT          (0x0UL << 0)    /* DEFAULT for CMU_HFPERCLKEN0_USART0       */
#define CMU_HFPERCLKEN0_USART0                  (0x1UL << 0)    /* Universal Synchronous/Asynchronous Receiver
                                                                   /Transmitter 0 Clock Enable              */
#define CMU_HFPERCLKEN0_USART1_SHIFT            1               /* Shift value for CMU_HFPERCLKEN0_USART1   */
#define CMU_HFPERCLKEN0_USART1_MASK             (0x1UL << 1)    /* Bit mask for CMU_HFPERCLKEN0_USART1      */
#define CMU_HFPERCLKEN0_USART1_DEFAULT          (0x0UL << 1)    /* DEFAULT for CMU_HFPERCLKEN0_USART1       */
#define CMU_HFPERCLKEN0_USART1                  (0x1UL << 1)    /* Universal Synchronous/Asynchronous Receiver
                                                                   /Transmitter 1 Clock Enable              */
#define CMU_HFPERCLKEN0_USART2_SHIFT            2               /* Shift value for CMU_HFPERCLKEN0_USART2   */
#define CMU_HFPERCLKEN0_USART2_MASK             (0x1UL << 2)    /* Bit mask for CMU_HFPERCLKEN0_USART2      */
#define CMU_HFPERCLKEN0_USART2_DEFAULT          (0x0UL << 2)    /* DEFAULT for CMU_HFPERCLKEN0_USART2       */
#define CMU_HFPERCLKEN0_USART2                  (0x1UL << 2)    /* Universal Synchronous/Asynchronous Receiver
                                                                   /Transmitter 2 Clock Enable              */
#define CMU_HFPERCLKEN0_UART0_SHIFT             3               /* Shift value for CMU_HFPERCLKEN0_UART0    */
#define CMU_HFPERCLKEN0_UART0_MASK              (0x1UL << 3)    /* Bit mask for CMU_HFPERCLKEN0_UART0       */
#define CMU_HFPERCLKEN0_UART0_DEFAULT           (0x0UL << 3)    /* DEFAULT for CMU_HFPERCLKEN0_UART0        */
#define CMU_HFPERCLKEN0_UART0                   (0x1UL << 3)    /* Universal Asynchronous Receiver
                                                                   /Transmitter 0 Clock Enable              */
#define CMU_HFPERCLKEN0_UART1_SHIFT             4               /* Shift value for CMU_HFPERCLKEN0_UART1    */
#define CMU_HFPERCLKEN0_UART1_MASK              (0x1UL << 4)    /* Bit mask for CMU_HFPERCLKEN0_UART1       */
#define CMU_HFPERCLKEN0_UART1_DEFAULT           (0x0UL << 4)    /* DEFAULT for CMU_HFPERCLKEN0_UART1        */
#define CMU_HFPERCLKEN0_UART1                   (0x1UL << 4)    /* Universal Asynchronous Receiver
                                                                   /Transmitter 0 Clock Enable              */
#define CMU_HFPERCLKEN0_TIMER0_SHIFT            5               /* Shift value for CMU_HFPERCLKEN0_TIMER0   */
#define CMU_HFPERCLKEN0_TIMER0_MASK             (0x1UL << 5)    /* Bit mask for CMU_HFPERCLKEN0_TIMER0      */
#define CMU_HFPERCLKEN0_TIMER0_DEFAULT          (0x0UL << 5)    /* DEFAULT for CMU_HFPERCLKEN0_TIMER0       */
#define CMU_HFPERCLKEN0_TIMER0                  (0x1UL << 5)    /* Timer 0 Clock Enable                     */
#define CMU_HFPERCLKEN0_TIMER1_SHIFT            6               /* Shift value for CMU_HFPERCLKEN0_TIMER1   */
#define CMU_HFPERCLKEN0_TIMER1_MASK             (0x1UL << 6)    /* Bit mask for CMU_HFPERCLKEN0_TIMER1      */
#define CMU_HFPERCLKEN0_TIMER1_DEFAULT          (0x0UL << 6)    /* DEFAULT for CMU_HFPERCLKEN0_TIMER1       */
#define CMU_HFPERCLKEN0_TIMER1                  (0x1UL << 6)    /* Timer 1 Clock Enable                     */
#define CMU_HFPERCLKEN0_TIMER2_SHIFT            7               /* Shift value for CMU_HFPERCLKEN0_TIMER2   */
#define CMU_HFPERCLKEN0_TIMER2_MASK             (0x1UL << 7)    /* Bit mask for CMU_HFPERCLKEN0_TIMER2      */
#define CMU_HFPERCLKEN0_TIMER2_DEFAULT          (0x0UL << 7)    /* DEFAULT for CMU_HFPERCLKEN0_TIMER2       */
#define CMU_HFPERCLKEN0_TIMER2                  (0x1UL << 7)    /* Timer 2 Clock Enable                     */
#define CMU_HFPERCLKEN0_TIMER3_SHIFT            8               /* Shift value for CMU_HFPERCLKEN0_TIMER3   */
#define CMU_HFPERCLKEN0_TIMER3_MASK             (0x1UL << 8)    /* Bit mask for CMU_HFPERCLKEN0_TIMER3      */
#define CMU_HFPERCLKEN0_TIMER3_DEFAULT          (0x0UL << 8)    /* DEFAULT for CMU_HFPERCLKEN0_TIMER3       */
#define CMU_HFPERCLKEN0_TIMER3                  (0x1UL << 8)    /* Timer 3 Clock Enable                     */    
#define CMU_HFPERCLKEN0_ACMP0_SHIFT             9               /* Shift value for CMU_HFPERCLKEN0_ACMP0    */
#define CMU_HFPERCLKEN0_ACMP0_MASK              (0x1UL << 9)    /* Bit mask for CMU_HFPERCLKEN0_ACMP0       */
#define CMU_HFPERCLKEN0_ACMP0_DEFAULT           (0x0UL << 9)    /* DEFAULT for CMU_HFPERCLKEN0_ACMP0        */
#define CMU_HFPERCLKEN0_ACMP0                   (0x1UL << 9)    /* Analog Comparator 0 Clock Enable         */  
#define CMU_HFPERCLKEN0_ACMP1_SHIFT             10              /* Shift value for CMU_HFPERCLKEN0_ACMP1    */
#define CMU_HFPERCLKEN0_ACMP1_MASK              (0x1UL << 10)   /* Bit mask for CMU_HFPERCLKEN0_ACMP1       */
#define CMU_HFPERCLKEN0_ACMP1_DEFAULT           (0x0UL << 10)   /* DEFAULT for CMU_HFPERCLKEN0_ACMP1        */
#define CMU_HFPERCLKEN0_ACMP1                   (0x1UL << 10)   /* Analog Comparator 1 Clock Enable         */
#define CMU_HFPERCLKEN0_I2C0_SHIFT              11              /* Shift value for CMU_HFPERCLKEN0_I2C0     */
#define CMU_HFPERCLKEN0_I2C0_MASK               (0x1UL << 11)   /* Bit mask for CMU_HFPERCLKEN0_I2C0        */
#define CMU_HFPERCLKEN0_I2C0_DEFAULT            (0x1UL << 11)   /* DEFAULT for CMU_HFPERCLKEN0_I2C0         */
#define CMU_HFPERCLKEN0_I2C0                    (0x1UL << 11)   /* I2C 0 Clock Enable                       */
#define CMU_HFPERCLKEN0_I2C1_SHIFT              12              /* Shift value for CMU_HFPERCLKEN0_I2C1     */
#define CMU_HFPERCLKEN0_I2C1_MASK               (0x1UL << 12)   /* Bit mask for CMU_HFPERCLKEN0_I2C1        */
#define CMU_HFPERCLKEN0_I2C1_DEFAULT            (0x1UL << 12)   /* DEFAULT for CMU_HFPERCLKEN0_I2C1         */
#define CMU_HFPERCLKEN0_I2C1                    (0x1UL << 12)   /* I2C 1 Clock Enable                       */
#define CMU_HFPERCLKEN0_GPIO_SHIFT              13              /* Shift value for CMU_HFPERCLKEN0_GPIO     */
#define CMU_HFPERCLKEN0_GPIO_MASK               (0x1UL << 13)   /* Bit mask for CMU_HFPERCLKEN0_GPIO        */
#define CMU_HFPERCLKEN0_GPIO_DEFAULT            (0x0UL << 13)   /* DEFAULT for CMU_HFPERCLKEN0_GPIO         */
#define CMU_HFPERCLKEN0_GPIO                    (0x1UL << 13)   /* General purpose Input/Output Clock Enable */
#define CMU_HFPERCLKEN0_VCMP_SHIFT              14              /* Shift value for CMU_HFPERCLKEN0_VCMP     */
#define CMU_HFPERCLKEN0_VCMP_MASK               (0x1UL << 14)   /* Bit mask for CMU_HFPERCLKEN0_VCMP        */
#define CMU_HFPERCLKEN0_VCMP_DEFAULT            (0x1UL << 14)   /* DEFAULT for CMU_HFPERCLKEN0_VCMP         */
#define CMU_HFPERCLKEN0_VCMP                    (0x1UL << 14)   /* Voltage Comparator Clock Enable          */  
#define CMU_HFPERCLKEN0_PRS_SHIFT               15              /* Shift value for CMU_HFPERCLKEN0_PRS      */
#define CMU_HFPERCLKEN0_PRS_MASK                (0x1UL << 15)   /* Bit mask for CMU_HFPERCLKEN0_PRS         */
#define CMU_HFPERCLKEN0_PRS_DEFAULT             (0x0UL << 15)   /* DEFAULT for CMU_HFPERCLKEN0_PRS          */
#define CMU_HFPERCLKEN0_PRS                     (0x1UL << 15)   /* Peripheral Reflex System Clock Enable    */
#define CMU_HFPERCLKEN0_ADC0_SHIFT              16              /* Shift value for CMU_HFPERCLKEN0_ADC0     */
#define CMU_HFPERCLKEN0_ADC0_MASK               (0x1UL << 16)   /* Bit mask for CMU_HFPERCLKEN0_ADC0        */
#define CMU_HFPERCLKEN0_ADC0_DEFAULT            (0x0UL << 16)   /* DEFAULT for CMU_HFPERCLKEN0_ADC0         */
#define CMU_HFPERCLKEN0_ADC0                    (0x1UL << 16)   /* Analog to Digital Converter 0 Clock Enable */ 
#define CMU_HFPERCLKEN0_DAC0_SHIFT              17              /* Shift value for CMU_HFPERCLKEN0_DAC0     */
#define CMU_HFPERCLKEN0_DAC0_MASK               (0x1UL << 17)   /* Bit mask for CMU_HFPERCLKEN0_DAC0        */
#define CMU_HFPERCLKEN0_DAC0_DEFAULT            (0x0UL << 17)   /* DEFAULT for CMU_HFPERCLKEN0_DAC0         */
#define CMU_HFPERCLKEN0_DAC0                    (0x1UL << 17)   /* Digital to Analog Converter 0 Clock Enable */
    
/* Bit fields for CMU SYNCBUSY */
#define CMU_SYNCBUSY_RESETVALUE                 0x00000000UL    /* Default value for CMU_SYNCBUSY           */
#define CMU_SYNCBUSY_MASK                       0x00000055UL    /* Mask for CMU_SYNCBUSY                    */
#define CMU_SYNCBUSY_LFACLKEN0_SHIFT            0               /* Shift value for CMU_SYNCBUSY_LFACLKEN0   */
#define CMU_SYNCBUSY_LFACLKEN0_MASK             (0x1UL << 0)    /* Bit mask for CMU_SYNCBUSY_LFACLKEN0      */
#define CMU_SYNCBUSY_LFACLKEN0_DEFAULT          (0x0UL << 0)    /* DEFAULT for CMU_SYNCBUSY_LFACLKEN0       */
#define CMU_SYNCBUSY_LFACLKEN0                  (0x1UL << 0)    /* Low Frequency A Clock Enable 0 Busy      */
#define CMU_SYNCBUSY_LFAPRESC0_SHIFT            2               /* Shift value for CMU_SYNCBUSY_LFAPRESC0   */
#define CMU_SYNCBUSY_LFAPRESC0_MASK             (0x1UL << 2)    /* Bit mask for CMU_SYNCBUSY_LFAPRESC0      */
#define CMU_SYNCBUSY_LFAPRESC0_DEFAULT          (0x0UL << 2)    /* DEFAULT for CMU_SYNCBUSY_LFAPRESC0       */
#define CMU_SYNCBUSY_LFAPRESC0                  (0x1UL << 2)    /* Low Frequency A Prescaler 0 Busy         */
#define CMU_SYNCBUSY_LFBCLKEN0_SHIFT            4               /* Shift value for CMU_SYNCBUSY_LFBCLKEN0   */
#define CMU_SYNCBUSY_LFBCLKEN0_MASK             (0x1UL << 4)    /* Bit mask for CMU_SYNCBUSY_LFBCLKEN0      */
#define CMU_SYNCBUSY_LFBCLKEN0_DEFAULT          (0x0UL << 4)    /* DEFAULT for CMU_SYNCBUSY_LFBCLKEN0       */
#define CMU_SYNCBUSY_LFBCLKEN0                  (0x1UL << 4)    /* Low Frequency B Clock Enable 0 Busy      */
#define CMU_SYNCBUSY_LFBPRESC0_SHIFT            6               /* Shift value for CMU_SYNCBUSY_LFBPRESC0   */
#define CMU_SYNCBUSY_LFBPRESC0_MASK             (0x1UL << 6)    /* Bit mask for CMU_SYNCBUSY_LFBPRESC0      */
#define CMU_SYNCBUSY_LFBPRESC0_DEFAULT          (0x0UL << 6)    /* DEFAULT for CMU_SYNCBUSY_LFBPRESC0       */
#define CMU_SYNCBUSY_LFBPRESC0                  (0x1UL << 6)    /* Low Frequency B Prescaler 0 Busy         */

/* Bit fields for CMU FREEZE */
#define CMU_FREEZE_RESETVALUE                   0x00000000UL    /* Default value for CMU_FREEZE             */
#define CMU_FREEZE_MASK                         0x00000001UL    /* Mask for CMU_FREEZE_FREEZE               */
#define CMU_FREEZE_REGFREEZE_SHIFT              0               /* Shift value for CMU_FREEZE_FREEZE        */
#define CMU_FREEZE_REGFREEZE_MASK               (0x1UL << 0)    /* Bit mask for CMU_FREEZE_FREEZE           */
#define CMU_FREEZE_REGFREEZE_DEFAULT            (0x0UL << 0)    /* DEFAULT for CMU_FREEZE_FREEZE            */
#define CMU_FREEZE_REGFREEZE_UPDATE             (0x0UL << 0)    /* UPDATE for CMU_FREEZE_FREEZE             */
#define CMU_FREEZE_REGFREEZE_FREEZE             (0x1UL << 0)    /* FREEZE for CMU_FREEZE_FREEZE             */

/* Bit fields for CMU LFACLKEN0 */
#define CMU_LFACLKEN0_RESETVALUE                0x00000000UL    /* Default value for CMU_LFACLKEN0          */
#define CMU_LFACLKEN0_MASK                      0x00000007UL    /* Mask for CMU_LFACLKEN0                   */
#define CMU_LFACLKEN0_LESENSE_SHIFT             0               /* Shift value for CMU_LFACLKEN0_LESENSE    */
#define CMU_LFACLKEN0_LESENSE_MASK              (0x1UL << 0)    /* Bit mask for CMU_LFACLKEN0_LESENSE       */
#define CMU_LFACLKEN0_LESENSE_DEFAULT           (0x0UL << 0)    /* DEFAULT for CMU_LFACLKEN0_LESENSE        */
#define CMU_LFACLKEN0_LESENSE                   (0x1UL << 0)    /* Low Energy Sensor Interface Clock Enable */   
#define CMU_LFACLKEN0_RTC_SHIFT                 1               /* Shift value for CMU_LFACLKEN0_RTC        */
#define CMU_LFACLKEN0_RTC_MASK                  (0x1UL << 1)    /* Bit mask for CMU_LFACLKEN0_RTC           */
#define CMU_LFACLKEN0_RTC_DEFAULT               (0x0UL << 1)    /* DEFAULT for CMU_LFACLKEN0_RTC            */
#define CMU_LFACLKEN0_RTC                       (0x1UL << 1)    /* Real-Time Counter Clock Enable           */
#define CMU_LFACLKEN0_LETIMER0_SHIFT            2               /* Shift value for CMU_LFACLKEN0_LETIMER0   */
#define CMU_LFACLKEN0_LETIMER0_MASK             (0x1UL << 2)    /* Bit mask for CMU_LFACLKEN0_LETIMER0      */
#define CMU_LFACLKEN0_LETIMER0_DEFAULT          (0x0UL << 2)    /* DEFAULT for CMU_LFACLKEN0_LETIMER0       */
#define CMU_LFACLKEN0_LETIMER0                  (0x1UL << 2)    /* Low Energy Timer 0 Clock Enable          */
#define CMU_LFACLKEN0_LCD_SHIFT                 3               /* Shift value for CMU_LFACLKEN0_LCD        */
#define CMU_LFACLKEN0_LCD_MASK                  (0x1UL << 3)    /* Bit mask for CMU_LFACLKEN0_LCD           */
#define CMU_LFACLKEN0_LCD_DEFAULT               (0x0UL << 3)    /* DEFAULT for CMU_LFACLKEN0_LCD            */
#define CMU_LFACLKEN0_LCD                       (0x1UL << 3)    /* Liquid Crystal Display Controller Clock Enable */

/* Bit fields for CMU LFBCLKEN0 */
#define CMU_LFBCLKEN0_RESETVALUE                0x00000000UL    /* Default value for CMU_LFBCLKEN0          */
#define CMU_LFBCLKEN0_MASK                      0x00000003UL    /* Mask for CMU_LFBCLKEN0                   */
#define CMU_LFBCLKEN0_LEUART0_SHIFT             0               /* Shift value for CMU_LFBCLKEN0_LEUART0    */
#define CMU_LFBCLKEN0_LEUART0_MASK              (0x1UL << 0)    /* Bit mask for CMU_LFBCLKEN0_LEUART0       */
#define CMU_LFBCLKEN0_LEUART0_DEFAULT           (0x0UL << 0)    /* DEFAULT for CMU_LFBCLKEN0_LEUART0        */
#define CMU_LFBCLKEN0_LEUART0                   (0x1UL << 0)    /* Low Energy UART 0 Clock Enable           */
#define CMU_LFBCLKEN0_LEUART1_SHIFT             1               /* Shift value for CMU_LFBCLKEN0_LEUART1    */
#define CMU_LFBCLKEN0_LEUART1_MASK              (0x1UL << 1)    /* Bit mask for CMU_LFBCLKEN0_LEUART1       */
#define CMU_LFBCLKEN0_LEUART1_DEFAULT           (0x0UL << 1)    /* DEFAULT for CMU_LFBCLKEN0_LEUART1        */
#define CMU_LFBCLKEN0_LEUART1                   (0x1UL << 1)    /* Low Energy UART 1 Clock Enable           */
    
/* Bit fields for CMU LFAPRESC0 */
#define CMU_LFAPRESC0_RESETVALUE                0x00000000UL    /* Default value for CMU_LFAPRESC0          */
#define CMU_LFAPRESC0_MASK                      0x000003FFUL    /* Mask for CMU_LFAPRESC0                   */
#define CMU_LFAPRESC0_LESENSE_SHIFT             0               /* Shift value for CMU_LFAPRESC0_LESENSE    */
#define CMU_LFAPRESC0_LESENSE_MASK              (0x3UL << 0)    /* Bit mask for CMU_LFAPRESC0_LESENSE       */
#define CMU_LFAPRESC0_LESENSE_DEFAULT           (0x0UL << 0)    /* DEFAULT for CMU_LFAPRESC0_LESENSE        */
#define CMU_LFAPRESC0_LESENSE_DIV1              (0x0UL << 0)    /* LFACLK for LESENSE Clock                 */
#define CMU_LFAPRESC0_LESENSE_DIV2              (0x1UL << 0)    /* LFACLK / 2 for LESENSE Clock             */  
#define CMU_LFAPRESC0_LESENSE_DIV3              (0x2UL << 0)    /* LFACLK / 4 for LESENSE Clock             */
#define CMU_LFAPRESC0_LESENSE_DIV4              (0x3UL << 0)    /* LFACLK / 8 for LESENSE Clock             */
#define CMU_LFAPRESC0_RTC_SHIFT                 4               /* Shift value for CMU_LFAPRESC0_RTC        */
#define CMU_LFAPRESC0_RTC_MASK                  (0xFUL << 4)    /* Bit mask for CMU_LFAPRESC0_RTC           */
#define CMU_LFAPRESC0_RTC_DEFAULT               (0x0UL << 4)    /* DEFAULT for CMU_LFAPRESC0_RTC            */
#define CMU_LFAPRESC0_RTC_DIV1                  (0x0UL << 4)    /* LFACLK for RTC Clock                     */
#define CMU_LFAPRESC0_RTC_DIV2                  (0x1UL << 4)    /* LFACLK / 2 for RTC Clock                 */
#define CMU_LFAPRESC0_RTC_DIV4                  (0x2UL << 4)    /* LFACLK / 4 for RTC Clock                 */
#define CMU_LFAPRESC0_RTC_DIV8                  (0x3UL << 4)    /* LFACLK / 8 for RTC Clock                 */
#define CMU_LFAPRESC0_RTC_DIV16                 (0x4UL << 4)    /* LFACLK / 16 for RTC Clock                */
#define CMU_LFAPRESC0_RTC_DIV32                 (0x5UL << 4)    /* LFACLK / 32 for RTC Clock                */
#define CMU_LFAPRESC0_RTC_DIV64                 (0x6UL << 4)    /* LFACLK / 64 for RTC Clock                */
#define CMU_LFAPRESC0_RTC_DIV128                (0x7UL << 4)    /* LFACLK / 128 for RTC Clock               */
#define CMU_LFAPRESC0_RTC_DIV256                (0x8UL << 4)    /* LFACLK / 256 for RTC Clock               */
#define CMU_LFAPRESC0_RTC_DIV512                (0x9UL << 4)    /* LFACLK / 512 for RTC Clock               */
#define CMU_LFAPRESC0_RTC_DIV1024               (0xAUL << 4)    /* LFACLK / 1024 for RTC Clock              */
#define CMU_LFAPRESC0_RTC_DIV2048               (0xBUL << 4)    /* LFACLK / 2048 for RTC Clock              */
#define CMU_LFAPRESC0_RTC_DIV4096               (0xCUL << 4)    /* LFACLK / 4096 for RTC Clock              */
#define CMU_LFAPRESC0_RTC_DIV8192               (0xDUL << 4)    /* LFACLK / 8192 for RTC Clock              */
#define CMU_LFAPRESC0_RTC_DIV16384              (0xEUL << 4)    /* LFACLK / 16348 for RTC Clock             */
#define CMU_LFAPRESC0_RTC_DIV32768              (0xFUL << 4)    /* LFACLK / 32768 for RTC Clock             */
#define CMU_LFAPRESC0_LETIMER0_SHIFT            8               /* Shift value for CMU_LFAPRESC0_LETIMER0   */
#define CMU_LFAPRESC0_LETIMER0_MASK             (0xFUL << 8)    /* Bit mask for CMU_LFAPRESC0_LETIMER0      */
#define CMU_LFAPRESC0_LETIMER0_DEFAULT          (0x0UL << 8)    /* DEFAULT for CMU_LFAPRESC0_LETIMER0       */
#define CMU_LFAPRESC0_LETIMER0_DIV1             (0x0UL << 8)    /* LFACLK for LETIMER0 Clock                */
#define CMU_LFAPRESC0_LETIMER0_DIV2             (0x1UL << 8)    /* LFACLK / 2 for LETIMER0 Clock            */
#define CMU_LFAPRESC0_LETIMER0_DIV4             (0x2UL << 8)    /* LFACLK / 4 for LETIMER0 Clock            */
#define CMU_LFAPRESC0_LETIMER0_DIV8             (0x3UL << 8)    /* LFACLK / 8 for LETIMER0 Clock            */
#define CMU_LFAPRESC0_LETIMER0_DIV16            (0x4UL << 8)    /* LFACLK / 16 for LETIMER0 Clock           */
#define CMU_LFAPRESC0_LETIMER0_DIV32            (0x5UL << 8)    /* LFACLK / 32 for LETIMER0 Clock           */
#define CMU_LFAPRESC0_LETIMER0_DIV64            (0x6UL << 8)    /* LFACLK / 64 for LETIMER0 Clock           */
#define CMU_LFAPRESC0_LETIMER0_DIV128           (0x7UL << 8)    /* LFACLK / 128 for LETIMER0 Clock          */
#define CMU_LFAPRESC0_LETIMER0_DIV256           (0x8UL << 8)    /* LFACLK / 256 for LETIMER0 Clock          */
#define CMU_LFAPRESC0_LETIMER0_DIV512           (0x9UL << 4)    /* LFACLK / 512 for LETIMER0 Clock          */
#define CMU_LFAPRESC0_LETIMER0_DIV1024          (0xAUL << 8)    /* LFACLK / 1024 for LETIMER0 Clock         */
#define CMU_LFAPRESC0_LETIMER0_DIV2048          (0xBUL << 8)    /* LFACLK / 2048 for LETIMER0 Clock         */
#define CMU_LFAPRESC0_LETIMER0_DIV4096          (0xCUL << 8)    /* LFACLK / 4096 for LETIMER0 Clock         */
#define CMU_LFAPRESC0_LETIMER0_DIV8192          (0xDUL << 8)    /* LFACLK / 8192 for LETIMER0 Clock         */
#define CMU_LFAPRESC0_LETIMER0_DIV16384         (0xEUL << 8)    /* LFACLK / 16384 for LETIMER0 Clock        */
#define CMU_LFAPRESC0_LETIMER0_DIV32768         (0xFUL << 8)    /* LFACLK / 32768 for LETIMER0 Clock        */
#define CMU_LFAPRESC0_LCD_SHIFT                 12              /* Shift value for CMU_LFAPRESC0_LCD        */
#define CMU_LFAPRESC0_LCD_MASK                  (0x3UL << 12)   /* Bit mask for CMU_LFAPRESC0_LCD           */
#define CMU_LFAPRESC0_LCD_DEFAULT               (0x0UL << 12)   /* DEFAULT for CMU_LFAPRESC0_LCD            */
#define CMU_LFAPRESC0_LCD_DIV16                 (0x0UL << 12)   /* LFACLK / 16 for LCD Clock                */
#define CMU_LFAPRESC0_LCD_DIV32                 (0x1UL << 12)   /* LFACLK / 32 for LCD Clock                */
#define CMU_LFAPRESC0_LCD_DIV64                 (0x2UL << 12)   /* LFACLK / 64 for LCD Clock                */
#define CMU_LFAPRESC0_LCD_DIV128                (0x3UL << 8)    /* LFACLK / 128 for LCD Clock               */

/* Bit fields for CMU LFBPRESC0 */
#define CMU_LFBPRESC0_RESETVALUE                0x00000000UL    /* Default value for CMU_LFBPRESC0          */
#define CMU_LFBPRESC0_MASK                      0x00000033UL    /* Mask for CMU_LFBPRESC0                   */
#define CMU_LFBPRESC0_LEUART0_SHIFT             0               /* Shift value for CMU_LFBPRESC0_LEUART0    */
#define CMU_LFBPRESC0_LEUART0_MASK              (0x3UL << 0)    /* Bit mask for CMU_LFBPRESC0_LEUART0       */
#define CMU_LFBPRESC0_LEUART0_DEFAULT           (0x0UL << 0)    /* DEFAULT for CMU_LFBPRESC0_LEUART0        */
#define CMU_LFBPRESC0_LEUART0_DIV1              (0x0UL << 0)    /* LFBCLK for LEUART0 Clock                 */
#define CMU_LFBPRESC0_LEUART0_DIV2              (0x1UL << 0)    /* LFBCLK / 2 for LEUART0 Clock             */
#define CMU_LFBPRESC0_LEUART0_DIV4              (0x2UL << 0)    /* LFBCLK / 4 for LEUART0 Clock             */
#define CMU_LFBPRESC0_LEUART0_DIV8              (0x3UL << 0)    /* LFBCLK / 8 for LEUART0 Clock             */
#define CMU_LFBPRESC0_LEUART1_SHIFT             4               /* Shift value for CMU_LFBPRESC0_LEUART1    */
#define CMU_LFBPRESC0_LEUART1_MASK              (0x3UL << 4)    /* Bit mask for CMU_LFBPRESC0_LEUART1       */
#define CMU_LFBPRESC0_LEUART1_DEFAULT           (0x0UL << 4)    /* DEFAULT for CMU_LFBPRESC0_LEUART1        */
#define CMU_LFBPRESC0_LEUART1_DIV1              (0x0UL << 4)    /* LFBCLK for LEUART1 Clock                 */
#define CMU_LFBPRESC0_LEUART1_DIV2              (0x1UL << 4)    /* LFBCLK / 2 for LEUART1 Clock             */
#define CMU_LFBPRESC0_LEUART1_DIV4              (0x2UL << 4)    /* LFBCLK / 4 for LEUART1 Clock             */
#define CMU_LFBPRESC0_LEUART1_DIV8              (0x3UL << 4)    /* LFBCLK / 8 for LEUART1 Clock             */

/* Bit fields for CMU PCNTCTRL */
#define CMU_PCNTCTRL_RESETVALUE                 0x00000000UL    /* Default value for CMU_PCNTCTRL           */
#define CMU_PCNTCTRL_MASK                       0x0000003FUL    /* Mask for CMU_PCNTCTRL                    */
#define CMU_PCNTCTRL_PCNT0CLKEN_SHIFT           0               /* Shift value for CMU_PCNTCTRL_PCNT0CLKEN  */
#define CMU_PCNTCTRL_PCNT0CLKEN_MASK            (0x1UL << 0)    /* Bit mask for CMU_PCNTCTRL_PCNT0CLKEN     */
#define CMU_PCNTCTRL_PCNT0CLKEN_DEFAULT         (0x0UL << 0)    /* DEFAULT for CMU_PCNTCTRL_PCNT0CLKEN      */
#define CMU_PCNTCTRL_PCNT0CLKEN                 (0x1UL << 0)    /* PCNT0 Clock Enable                       */
#define CMU_PCNTCTRL_PCNT0CLKSEL_SHIFT          1               /* Shift value for CMU_PCNTCTRL_PCNT0CLKSEL */
#define CMU_PCNTCTRL_PCNT0CLKSEL_MASK           (0x1UL << 1)    /* Bit mask for CMU_PCNTCTRL_PCNT0CLKSEL    */
#define CMU_PCNTCTRL_PCNT0CLKSEL_DEFAULT        (0x0UL << 1)    /* DEFAULT for CMU_PCNTCTRL_PCNT0CLKSEL     */
#define CMU_PCNTCTRL_PCNT0CLKSEL_LFACLK         (0x0UL << 1)    /* LFACLK for PCNT0 Clock                   */
#define CMU_PCNTCTRL_PCNT0CLKSEL_PCNT0S0        (0x1UL << 1)    /* PCNT0S0 for PCNT0 Clock                  */
#define CMU_PCNTCTRL_PCNT1CLKEN_SHIFT           2               /* Shift value for CMU_PCNTCTRL_PCNT1CLKEN  */
#define CMU_PCNTCTRL_PCNT1CLKEN_MASK            (0x1UL << 2)    /* Bit mask for CMU_PCNTCTRL_PCNT1CLKEN     */
#define CMU_PCNTCTRL_PCNT1CLKEN_DEFAULT         (0x0UL << 2)    /* DEFAULT for CMU_PCNTCTRL_PCNT1CLKEN      */
#define CMU_PCNTCTRL_PCNT1CLKEN                 (0x1UL << 2)    /* PCNT1 Clock Enable                       */
#define CMU_PCNTCTRL_PCNT1CLKSEL_SHIFT          3               /* Shift value for CMU_PCNTCTRL_PCNT1CLKSEL */
#define CMU_PCNTCTRL_PCNT1CLKSEL_MASK           (0x1UL << 3)    /* Bit mask for CMU_PCNTCTRL_PCNT1CLKSEL    */
#define CMU_PCNTCTRL_PCNT1CLKSEL_DEFAULT        (0x0UL << 3)    /* DEFAULT for CMU_PCNTCTRL_PCNT1CLKSEL     */
#define CMU_PCNTCTRL_PCNT1CLKSEL_LFACLK         (0x0UL << 3)    /* LFACLK for PCNT1 Clock                   */
#define CMU_PCNTCTRL_PCNT1CLKSEL_PCNT1S0        (0x1UL << 3)    /* PCNT1S0 for PCNT1 Clock                  */
#define CMU_PCNTCTRL_PCNT2CLKEN_SHIFT           4               /* Shift value for CMU_PCNTCTRL_PCNT2CLKEN  */
#define CMU_PCNTCTRL_PCNT2CLKEN_MASK            (0x1UL << 4)    /* Bit mask for CMU_PCNTCTRL_PCNT2CLKEN     */
#define CMU_PCNTCTRL_PCNT2CLKEN_DEFAULT         (0x0UL << 4)    /* DEFAULT for CMU_PCNTCTRL_PCNT2CLKEN      */
#define CMU_PCNTCTRL_PCNT2CLKEN                 (0x1UL << 4)    /* PCNT2 Clock Enable                       */
#define CMU_PCNTCTRL_PCNT2CLKSEL_SHIFT          5               /* Shift value for CMU_PCNTCTRL_PCNT2CLKSEL */
#define CMU_PCNTCTRL_PCNT2CLKSEL_MASK           (0x1UL << 5)    /* Bit mask for CMU_PCNTCTRL_PCNT2CLKSEL    */
#define CMU_PCNTCTRL_PCNT2CLKSEL_DEFAULT        (0x0UL << 5)    /* DEFAULT for CMU_PCNTCTRL_PCNT2CLKSEL     */
#define CMU_PCNTCTRL_PCNT2CLKSEL_LFACLK         (0x0UL << 5)    /* LFACLK for PCNT2 Clock                   */
#define CMU_PCNTCTRL_PCNT2CLKSEL_PCNT2S0        (0x1UL << 5)    /* PCNT2S0 for PCNT2 Clock                  */

/* Bit fields for CMU LCDCTRL */
#define CMU_LCDCTRL_RESETVALUE                  0x00000020UL    /* Default value for CMU_LCDCTRL */
#define CMU_LCDCTRL_MASK                        0x0000007FUL    /* Mask for CMU_LCDCTRL */
#define CMU_LCDCTRL_FDIV_SHIFT                  0               /* Shift value for CMU_LCDCTRL_FDIV */
#define CMU_LCDCTRL_FDIV_MASK                   (0x7UL << 0)    /* Bit mask for CMU_LCDCTRL_FDIV */
#define CMU_LCDCTRL_FDIV_DEFAULT                (0x0UL << 0     /* DEFAULT for CMU_LCDCTRL_FDIV */
#define CMU_LCDCTRL_VBOOSTEN_SHIFT              3               /* Shift value for CMU_LCDCTRL_VBOOSTEN */
#define CMU_LCDCTRL_VBOOSTEN_MASK               (0x1UL << 3)    /* Bit mask for CMU_LCDCTRL_VBOOSTEN */
#define CMU_LCDCTRL_VBOOSTEN_DEFAULT            (0x0UL << 3)    /* DEFAULT for CMU_LCDCTRL_VBOOSTEN */
#define CMU_LCDCTRL_VBOOSTEN                    (0x1UL << 3)    /* Voltage Boost Enable */
#define CMU_LCDCTRL_VBFDIV_SHIFT                4               /* Shift value for CMU_LCDCTRL_VBFDIV */
#define CMU_LCDCTRL_VBFDIV_MASK                 (0x7UL << 4)    /* Bit mask for CMU_LCDCTRL_VBFDIV */
#define CMU_LCDCTRL_VBFDIV_DEFAULT              (0x2UL << 4)    /* DEFAULT for CMU_LCDCTRL_VBFDIV */
#define CMU_LCDCTRL_VBFDIV_DIV1                 (0x0UL << 4)    /* FLACLK for Voltage Boost updata Frequency */
#define CMU_LCDCTRL_VBFDIV_DIV2                 (0x1UL << 4)    /* FLACLK / 2 for Voltage Boost updata Frequency */
#define CMU_LCDCTRL_VBFDIV_DIV4                 (0x2UL << 4)    /* FLACLK / 4 for Voltage Boost updata Frequency */
#define CMU_LCDCTRL_VBFDIV_DIV8                 (0x3UL << 4)    /* FLACLK / 8 for Voltage Boost updata Frequency */
#define CMU_LCDCTRL_VBFDIV_DIV16                (0x4UL << 4)    /* FLACLK / 16 for Voltage Boost updata Frequency */
#define CMU_LCDCTRL_VBFDIV_DIV32                (0x5UL << 4)    /* FLACLK / 32 for Voltage Boost updata Frequency */
#define CMU_LCDCTRL_VBFDIV_DIV64                (0x6UL << 4)    /* FLACLK / 64 for Voltage Boost updata Frequency */
#define CMU_LCDCTRL_VBFDIV_DIV128               (0x7UL << 4)    /* FLACLK / 128 for Voltage Boost updata Frequency */
    
/* Bit fields for CMU ROUTE */
#define CMU_ROUTE_RESETVALUE                    0x00000000UL    /* Default value for CMU_ROUTE              */
#define CMU_ROUTE_MASK                          0x00000007UL    /* Mask for CMU_ROUTE                       */
#define CMU_ROUTE_CLKOUT0PEN_SHIFT              0               /* Shift value for CMU_ROUTE_CLKOUT0PEN     */
#define CMU_ROUTE_CLKOUT0PEN_MASK               (0x1UL << 0)    /* Bit mask for CMU_ROUTE_CLKOUT0PEN        */
#define CMU_ROUTE_CLKOUT0PEN_DEFAULT            (0x0UL << 0)    /* DEFAULT for CMU_ROUTE_CLKOUT0PEN         */
#define CMU_ROUTE_CLKOUT0PEN                    (0x1UL << 0)    /* CLKOUT0 Pin Enable                       */
#define CMU_ROUTE_CLKOUT1PEN_SHIFT              1               /* Shift value for CMU_ROUTE_CLKOUT1PEN     */
#define CMU_ROUTE_CLKOUT1PEN_MASK               (0x1UL << 1)    /* Bit mask for CMU_ROUTE_CLKOUT1PEN        */
#define CMU_ROUTE_CLKOUT1PEN_DEFAULT            (0x0UL << 1)    /* DEFAULT for CMU_ROUTE_CLKOUT1PEN         */
#define CMU_ROUTE_CLKOUT1PEN                    (0x1UL << 1)    /* CLKOUT1 Pin Enable                       */
#define CMU_ROUTE_LOCATION_SHIFT                2               /* Shift value for CMU_ROUTE_LOCATION       */
#define CMU_ROUTE_LOCATION_MASK                 (0x7UL << 2)    /* Bit mask for CMU_ROUTE_LOCATION          */
#define CMU_ROUTE_LOCATION_DEFAULT              (0x0UL << 2)    /* DEFAULT for CMU_ROUTE_LOCATION           */
#define CMU_ROUTE_LOCATION_LOC0                 (0x0UL << 2)    /* LOC0 for CMU_ROUTE_LOCATION              */
#define CMU_ROUTE_LOCATION_LOC1                 (0x1UL << 2)    /* LOC1 for CMU_ROUTE_LOCATION              */
#define CMU_ROUTE_LOCATION_LOC2                 (0x1UL << 2)    /* LOC2 for CMU_ROUTE_LOCATION              */
    
/* Bit fields for CMU LOCK */
#define CMU_LOCK_RESETVALUE                     0x00000000UL    /* Default value for CMU_LOCK               */
#define CMU_LOCK_MASK                           0x0000FFFFUL    /* Mask for CMU_LOCK                        */
#define CMU_LOCK_LOCKKEY_SHIFT                  0               /* Shift value for CMU_LOCK_LOCKKEY         */
#define CMU_LOCK_LOCKKEY_MASK                   (0xFFFFUL << 0) /* Bit mask for CMU_LOCK_LOCKKEY            */
#define CMU_LOCK_LOCKKEY_DEFAULT                (0x0UL    << 0) /* DEFAULT for CMU_LOCK_LOCKKEY             */
#define CMU_LOCK_LOCKKEY_LOCK                   (0x0UL    << 0) /* Lock CMU registers                       */
#define CMU_LOCK_LOCKKEY_UNLOCK                 (0x580EUL << 0) /* Unlock CMU registers                     */
#define CMU_LOCK_LOCKKEY_UNLOCKED               (0x0UL    << 0) /* CMU registers are unlocked               */
#define CMU_LOCK_LOCKKEY_LOCKED                 (0x1UL    << 0) /* CMU registers are locked                 */
  
#define LFRCO_FREQ                              32768UL         /* This value will be change with temperature
                                                                   of CPU                                   */
#define HFRCO_FREQ_1MHZ                         1000000UL
#define HFRCO_FREQ_7MHZ                         7000000UL
#define HFRCO_FREQ_11MHZ                        11000000UL
#define HFRCO_FREQ_14MHZ                        14000000UL
#define HFRCO_FREQ_21MHZ                        21000000UL
#define HFRCO_FREQ_28MHZ                        28000000UL
#define LFXO_FREQ                               CHIP_LSE_FREQ
#define HFXO_FREQ                               CHIP_HSE_FREQ
#define ULFRCO_FREQ                             1000UL
    
#define LFCLK_SOURCE_NUM                        3

    
/*************************************************************************************************************
*                                                  DATA TYPES                                                *
*************************************************************************************************************/
typedef enum
{
    HFXO_MODE_XTAL      = CMU_CTRL_HFXOMODE_XTAL,
    HFXO_MODE_BUFEXTCLK = CMU_CTRL_HFXOMODE_BUFEXTCLK,
    HFXO_MODE_DIGEXTCLK = CMU_CTRL_HFXOMODE_DIGEXTCLK,
} CMUHFXOModeSelTypeDef;

typedef enum
{
    HFXO_BOOST_50PCENT  = CMU_CTRL_HFXOBOOST_50PCENT,
    HFXO_BOOST_70PCENT  = CMU_CTRL_HFXOBOOST_70PCENT,
    HFXO_BOOST_80PCENT  = CMU_CTRL_HFXOBOOST_80PCENT,
    HFXO_BOOST_100PCENT = CMU_CTRL_HFXOBOOST_100PCENT,
} CMUHFXOBoostTypeDef;

typedef enum
{
    HFXO_TIMEOUT_8CYCLES   = CMU_CTRL_HFXOTIMEOUT_8CYCLES,
    HFXO_TIMEOUT_256CYCLES = CMU_CTRL_HFXOTIMEOUT_256CYCLES,
    HFXO_TIMEOUT_1KCYCLES  = CMU_CTRL_HFXOTIMEOUT_1KCYCLES,
    HFXO_TIMEOUT_16KCYCLES = CMU_CTRL_HFXOTIMEOUT_16KCYCLES,
} CMUHFXOTimeoutTypeDef;

typedef enum
{
    LFXO_MODE_XTAL      = CMU_CTRL_LFXOMODE_XTAL,
    LFXO_MODE_BUFEXTCLK = CMU_CTRL_LFXOMODE_BUFEXTCLK,
    LFXO_MODE_DIGEXTCLK = CMU_CTRL_LFXOMODE_DIGEXTCLK,
} CMULFXOModeSelTypeDef;

typedef enum
{
    LFXO_BOOST_70PCENT  = CMU_CTRL_LFXOBOOST_70PCENT,
    LFXO_BOOST_100PCENT = CMU_CTRL_LFXOBOOST_100PCENT,
} CMULFXOBoostTypeDef;

typedef enum
{
    LFXO_TIMEOUT_8CYCLES   = CMU_CTRL_LFXOTIMEOUT_8CYCLES,
    LFXO_TIMEOUT_1KCYCLES  = CMU_CTRL_LFXOTIMEOUT_1KCYCLES,
    LFXO_TIMEOUT_16KCYCLES = CMU_CTRL_LFXOTIMEOUT_16KCYCLES,
    LFXO_TIMEOUT_32KCYCLES = CMU_CTRL_LFXOTIMEOUT_32KCYCLES,
} CMULFXOTimeoutTypeDef;

typedef enum
{
    OscHFRCO    = CMU_OSCENCMD_HFRCOEN_SHIFT,       /* High frequency RC oscillator.                        */
    OscHFXO     = CMU_OSCENCMD_HFXOEN_SHIFT,        /* High frequency crystal oscillator.                   */
    OscAUXHFRCO = CMU_OSCENCMD_AUXHFRCOEN_SHIFT,    /* Auxiliary high frequency RC oscillator.              */
    OscLFRCO    = CMU_OSCENCMD_LFRCOEN_SHIFT,       /* Low frequency RC oscillator.                         */
    OscLFXO     = CMU_OSCENCMD_LFXOEN_SHIFT,        /* Low frequency crystal oscillator.                    */  
} CMUOscTypeDef;

typedef enum
{
    HFClkHFRCOSource = CMU_CMD_HFCLKSEL_HFRCO,  /* High frequency RC oscillator.                            */
    HFClkHFXOSource  = CMU_CMD_HFCLKSEL_HFXO,   /* High frequency crystal oscillator.                       */
    HFClkLFRCOSource = CMU_CMD_HFCLKSEL_LFRCO,  /* Low frequency RC oscillator.                             */
    HFClkLFXOSource  = CMU_CMD_HFCLKSEL_LFXO,   /* Low frequency crystal oscillator.                        */
} CMUHFCLKSourceTypeDef;

typedef enum
{
    HFRCO_BAND_1MHZ  = CMU_HFRCOCTRL_BAND_1MHZ, 
    HFRCO_BAND_7MHZ  = CMU_HFRCOCTRL_BAND_7MHZ,
    HFRCO_BAND_11MHZ = CMU_HFRCOCTRL_BAND_14MHZ,
    HFRCO_BAND_14MHZ = CMU_HFRCOCTRL_BAND_11MHZ,
    HFRCO_BAND_21MHZ = CMU_HFRCOCTRL_BAND_21MHZ,
    HFRCO_BAND_28MHZ = CMU_HFRCOCTRL_BAND_28MHZ,
} CMUHFRCOBandTypeDef;

typedef enum
{
    HFCORECLK_HFCLK         = CMU_HFCORECLKDIV_HFCORECLKDIV_HFCLK,
    HFCORECLK_HFCLK_DIV_2   = CMU_HFCORECLKDIV_HFCORECLKDIV_HFCLK2,
    HFCORECLK_HFCLK_DIV_4   = CMU_HFCORECLKDIV_HFCORECLKDIV_HFCLK4,
    HFCORECLK_HFCLK_DIV_8   = CMU_HFCORECLKDIV_HFCORECLKDIV_HFCLK8,
    HFCORECLK_HFCLK_DIV_16  = CMU_HFCORECLKDIV_HFCORECLKDIV_HFCLK16,
    HFCORECLK_HFCLK_DIV_32  = CMU_HFCORECLKDIV_HFCORECLKDIV_HFCLK32,
    HFCORECLK_HFCLK_DIV_64  = CMU_HFCORECLKDIV_HFCORECLKDIV_HFCLK64,
    HFCORECLK_HFCLK_DIV_128 = CMU_HFCORECLKDIV_HFCORECLKDIV_HFCLK128,
    HFCORECLK_HFCLK_DIV_256 = CMU_HFCORECLKDIV_HFCORECLKDIV_HFCLK256,
    HFCORECLK_HFCLK_DIV_512 = CMU_HFCORECLKDIV_HFCORECLKDIV_HFCLK512,
} CMUHFCOREClockDivTypeDef;

typedef enum
{
    HFPERCLK_HFCLK         = CMU_HFPERCLKDIV_HFPERCLKDIV_HFCLK,
    HFPERCLK_HFCLK_DIV_2   = CMU_HFPERCLKDIV_HFPERCLKDIV_HFCLK2,
    HFPERCLK_HFCLK_DIV_4   = CMU_HFPERCLKDIV_HFPERCLKDIV_HFCLK4,
    HFPERCLK_HFCLK_DIV_8   = CMU_HFPERCLKDIV_HFPERCLKDIV_HFCLK8,
    HFPERCLK_HFCLK_DIV_16  = CMU_HFPERCLKDIV_HFPERCLKDIV_HFCLK16,
    HFPERCLK_HFCLK_DIV_32  = CMU_HFPERCLKDIV_HFPERCLKDIV_HFCLK32,
    HFPERCLK_HFCLK_DIV_64  = CMU_HFPERCLKDIV_HFPERCLKDIV_HFCLK64,
    HFPERCLK_HFCLK_DIV_128 = CMU_HFPERCLKDIV_HFPERCLKDIV_HFCLK128,
    HFPERCLK_HFCLK_DIV_256 = CMU_HFPERCLKDIV_HFPERCLKDIV_HFCLK256,
    HFPERCLK_HFCLK_DIV_512 = CMU_HFPERCLKDIV_HFPERCLKDIV_HFCLK512,
} CMUHFPERClockDivTypeDef;

typedef enum
{
    LFAClock = CMU_LFCLKSEL_LFA_SHIFT,  /* Low frequency A clock                                            */ 
    LFBClock = CMU_LFCLKSEL_LFB_SHIFT,  /* Low frequency B clock                                            */     
} CMULFClockTypeDef;

typedef enum
{
    LFClkLFRCOSource          = CMU_LFCLKSEL_LFA_LFRCO,             /* Low frequency RC oscillator.         */
    LFClkLFXOSource           = CMU_LFCLKSEL_LFA_LFXO,              /* Low frequency crystal oscillator.    */
    LFClkHFCoreClkLEDivSource = CMU_LFCLKSEL_LFA_HFCORECLKLEDIV2    /* High frequency crystal oscillator.   */  
} CMULFCLKSourceTypeDef;

typedef enum
{
    LFA_RTC_LFACLK_DIV1   = CMU_LFAPRESC0_RTC_DIV1,
    LFA_RTC_LFACLK_DIV2   = CMU_LFAPRESC0_RTC_DIV2,
    LFA_RTC_LFACLK_DIV4   = CMU_LFAPRESC0_RTC_DIV4,
    LFA_RTC_LFACLK_DIV8   = CMU_LFAPRESC0_RTC_DIV8,
    LFA_RTC_LFACLK_DIV16  = CMU_LFAPRESC0_RTC_DIV16,
    LFA_RTC_LFACLK_DIV32  = CMU_LFAPRESC0_RTC_DIV32,
    LFA_RTC_LFACLK_DIV64  = CMU_LFAPRESC0_RTC_DIV64,
    LFA_RTC_LFACLK_DIV128 = CMU_LFAPRESC0_RTC_DIV128,
    LFA_RTC_LFACLK_DIV256 = CMU_LFAPRESC0_RTC_DIV256,
    LFA_RTC_LFACLK_DIV512 = CMU_LFAPRESC0_RTC_DIV512,
} CMULFARTCClockDivTypeDef;

typedef enum
{
    LFA_LETIMER0_LFACLK_DIV1     = CMU_LFAPRESC0_LETIMER0_DIV1,
    LFA_LETIMER0_LFACLK_DIV2     = CMU_LFAPRESC0_LETIMER0_DIV2,
    LFA_LETIMER0_LFACLK_DIV4     = CMU_LFAPRESC0_LETIMER0_DIV4,
    LFA_LETIMER0_LFACLK_DIV8     = CMU_LFAPRESC0_LETIMER0_DIV8,
    LFA_LETIMER0_LFACLK_DIV16    = CMU_LFAPRESC0_LETIMER0_DIV16,
    LFA_LETIMER0_LFACLK_DIV32    = CMU_LFAPRESC0_LETIMER0_DIV32,
    LFA_LETIMER0_LFACLK_DIV64    = CMU_LFAPRESC0_LETIMER0_DIV64,
    LFA_LETIMER0_LFACLK_DIV128   = CMU_LFAPRESC0_LETIMER0_DIV128,
    LFA_LETIMER0_LFACLK_DIV256   = CMU_LFAPRESC0_LETIMER0_DIV256,
    LFA_LETIMER0_LFACLK_DIV512   = CMU_LFAPRESC0_LETIMER0_DIV512,
    LFA_LETIMER0_LFACLK_DIV1024  = CMU_LFAPRESC0_LETIMER0_DIV1024,
    LFA_LETIMER0_LFACLK_DIV2048  = CMU_LFAPRESC0_LETIMER0_DIV2048,
    LFA_LETIMER0_LFACLK_DIV4096  = CMU_LFAPRESC0_LETIMER0_DIV4096,
    LFA_LETIMER0_LFACLK_DIV8192  = CMU_LFAPRESC0_LETIMER0_DIV8192,
    LFA_LETIMER0_LFACLK_DIV16384 = CMU_LFAPRESC0_LETIMER0_DIV16384,
    LFA_LETIMER0_LFACLK_DIV32768 = CMU_LFAPRESC0_LETIMER0_DIV32768,
} CMULFALETIMER0ClockDivTypeDef;

typedef enum
{
    LFA_LCD_LFACLK_DIV16  = CMU_LFAPRESC0_RTC_DIV16,
    LFA_LCD_LFACLK_DIV32  = CMU_LFAPRESC0_RTC_DIV32,
    LFA_LCD_LFACLK_DIV64  = CMU_LFAPRESC0_RTC_DIV64,
    LFA_LCD_LFACLK_DIV128 = CMU_LFAPRESC0_RTC_DIV128,
} CMULFALCDClockDivTypeDef;

typedef enum
{
    LFB_LEUART0_LFBCLK_DIV1 = CMU_LFBPRESC0_LEUART0_DIV1,
    LFB_LEUART0_LFBCLK_DIV2 = CMU_LFBPRESC0_LEUART0_DIV2,
    LFB_LEUART0_LFBCLK_DIV4 = CMU_LFBPRESC0_LEUART0_DIV4,
    LFB_LEUART0_LFBCLK_DIV8 = CMU_LFBPRESC0_LEUART0_DIV8,
} CMULFBLEUART0ClockDivTypeDef;

typedef enum
{
    LFB_LEUART1_LFBCLK_DIV1 = CMU_LFBPRESC0_LEUART1_DIV1,
    LFB_LEUART1_LFBCLK_DIV2 = CMU_LFBPRESC0_LEUART1_DIV2,
    LFB_LEUART1_LFBCLK_DIV4 = CMU_LFBPRESC0_LEUART1_DIV4,
    LFB_LEUART1_LFBCLK_DIV8 = CMU_LFBPRESC0_LEUART1_DIV8,
} CMULFBLEUART1ClockDivTypeDef;

typedef enum
{
    USART0Clock = CMU_HFPERCLKEN0_USART0,
    USART1Clock = CMU_HFPERCLKEN0_USART1,
    USART2Clock = CMU_HFPERCLKEN0_USART2,
    UART0Clock  = CMU_HFPERCLKEN0_UART0,
    UART1Clock  = CMU_HFPERCLKEN0_UART1,
    TIMER0Clock = CMU_HFPERCLKEN0_TIMER0,
    TIMER1Clock = CMU_HFPERCLKEN0_TIMER1,
    TIMER2Clock = CMU_HFPERCLKEN0_TIMER2,
    TIMER3Clock = CMU_HFPERCLKEN0_TIMER3,
    ACMP0Clock  = CMU_HFPERCLKEN0_ACMP0,       
    ACMP1Clock  = CMU_HFPERCLKEN0_ACMP1,
    I2C0Clock   = CMU_HFPERCLKEN0_I2C0,
    I2C1Clock   = CMU_HFPERCLKEN0_I2C1,
    GPIOClock   = CMU_HFPERCLKEN0_GPIO,
    VCMPClock   = CMU_HFPERCLKEN0_VCMP,
    PRSClock    = CMU_HFPERCLKEN0_PRS,
    ADC0Clock   = CMU_HFPERCLKEN0_ADC0,
    DAC0Clock   = CMU_HFPERCLKEN0_DAC0,
} CMUHFPERClockTypeDef;

typedef enum
{
    DMA1Clock = CMU_HFCORECLKEN0_DMA,
    AESClock  = CMU_HFCORECLKEN0_AES,
    USBCClock = CMU_HFCORECLKEN0_USBC,
    USBClock  = CMU_HFCORECLKEN0_USB,
    LEClock   = CMU_HFCORECLKEN0_LE,       
    EBIClock  = CMU_HFCORECLKEN0_EBI,  
} CMUHFCOREClockTypeDef;

typedef enum
{     
    RTCClock      = CMU_LFACLKEN0_RTC,
    LETIMER0Clock = CMU_LFACLKEN0_LETIMER0,
    LCDClock      = CMU_LFACLKEN0_LCD,
} CMULEAClockTypeDef;

typedef enum
{
    LEUART0Clock  = CMU_LFBCLKEN0_LEUART0, 
    LEUART1Clock  = CMU_LFBCLKEN0_LEUART1,
} CMULEBClockTypeDef;

typedef enum
{
    PCNT0Clock  = CMU_PCNTCTRL_PCNT0CLKSEL_SHIFT, 
    PCNT1Clock  = CMU_PCNTCTRL_PCNT1CLKSEL_SHIFT,
    PCNT2Clock  = CMU_PCNTCTRL_PCNT2CLKSEL_SHIFT, 
} CMUPCNTClockTypeDef;

typedef enum
{
    PCNTCLK_LFACLK = CMU_PCNTCTRL_PCNT0CLKSEL_LFACLK, 
    PCNTCLK_PCNTS  = CMU_PCNTCTRL_PCNT0CLKSEL_PCNT0S0,
} CMUPCNTClockSelTypeDef;

typedef enum
{
    CLKOUT0_PIN = CMU_ROUTE_CLKOUT0PEN, 
    CLKOUT1_PIN = CMU_ROUTE_CLKOUT1PEN, 
} CMUCLKOUTPinTypeDef;

typedef enum
{
    CLKOUT0_LOC0 = CMU_ROUTE_LOCATION_LOC0, /* PA2 For CLK0,PA1 For CLK1                                    */
    CLKOUT1_LOC1 = CMU_ROUTE_LOCATION_LOC1, /* PC11 For CLK0,PD8 For CLK1                                   */
    CLKOUT1_LOC2 = CMU_ROUTE_LOCATION_LOC2,
} CMUCLKOUTLocationTypeDef;

typedef enum
{
    CLKOUT0_SEL_HFRCO    = CMU_CTRL_CLKOUTSEL0_HFRCO, 
    CLKOUT0_SEL_HFXO     = CMU_CTRL_CLKOUTSEL0_HFXO, 
    CLKOUT0_SEL_HFCLK2   = CMU_CTRL_CLKOUTSEL0_HFCLK2, 
    CLKOUT0_SEL_HFCLK4   = CMU_CTRL_CLKOUTSEL0_HFCLK4,
    CLKOUT0_SEL_HFCLK8   = CMU_CTRL_CLKOUTSEL0_HFCLK8,
    CLKOUT0_SEL_HFCLK16  = CMU_CTRL_CLKOUTSEL0_HFCLK16,
    CLKOUT0_SEL_ULFRCO   = CMU_CTRL_CLKOUTSEL0_ULFRCO,
    CLKOUT0_SEL_ULXHFRCO = CMU_CTRL_CLKOUTSEL0_ULXHFRCO,
} CMUCLKOUT0SelTypeDef;

typedef enum
{
    CLKOUT1_SEL_LFRCO     = CMU_CTRL_CLKOUTSEL1_LFRCO, 
    CLKOUT1_SEL_LFXO      = CMU_CTRL_CLKOUTSEL1_LFXO, 
    CLKOUT1_SEL_HFCLK     = CMU_CTRL_CLKOUTSEL1_HFCLK,
    CLKOUT1_SEL_LFXOQ     = CMU_CTRL_CLKOUTSEL1_LFXOQ,
    CLKOUT1_SEL_HFXOQ     = CMU_CTRL_CLKOUTSEL1_HFXOQ,
    CLKOUT1_SEL_LFRCOQ    = CMU_CTRL_CLKOUTSEL1_LFRCOQ,
    CLKOUT1_SEL_HFRCOQ    = CMU_CTRL_CLKOUTSEL1_HFRCOQ,
    CLKOUT1_SEL_AUXHFRCOQ = CMU_CTRL_CLKOUTSEL1_AUXHFRCOQ,
} CMUCLKOUT1SelTypeDef;

typedef enum 
{
    CMU_HFCORECLKDIV_DIV_DIV2 = CMU_HFCORECLKDIV_HFCORECLKLEDIV_DIV2,
    CMU_HFCORECLKDIV_DIV_DIV4 = CMU_HFCORECLKDIV_HFCORECLKLEDIV_DIV4,
} CMUHFCOREClkEDivTypeDef;

typedef enum 
{
    AUXHFRCOCTRL_BAND_14M = CMU_AUXHFRCOCTRL_BAND_14M,
    AUXHFRCOCTRL_BAND_11M = CMU_AUXHFRCOCTRL_BAND_11M,
    AUXHFRCOCTRL_BAND_7M  = CMU_AUXHFRCOCTRL_BAND_7M,
    AUXHFRCOCTRL_BAND_1M  = CMU_AUXHFRCOCTRL_BAND_1M,
    AUXHFRCOCTRL_BAND_28M = CMU_AUXHFRCOCTRL_BAND_28M,
    AUXHFRCOCTRL_BAND_21M = CMU_AUXHFRCOCTRL_BAND_21M,
} CMUAUXHFRCOBandSelTypeDef;

typedef enum
{             
    CALCTRL_UPSEL_HFXO     = CMU_CALCTRL_UPSEL_HFXO,               
    CALCTRL_UPSEL_LFXO     = CMU_CALCTRL_UPSEL_LFXO,              
    CALCTRL_UPSEL_HFRCO    = CMU_CALCTRL_UPSEL_HFRCO,             
    CALCTRL_UPSEL_LFRCO    = CMU_CALCTRL_UPSEL_LFRCO,               
    CALCTRL_UPSEL_AUXHFRCO = CMU_CALCTRL_UPSEL_AUXHFRCO, 
} CMUCALUpcounterSelTypeDef;

typedef enum
{
    CALCTRL_DOWNSEL_HFCLK    = CMU_CALCTRL_DOWNSEL_HFCLK,               
    CALCTRL_DOWNSEL_HFXO     = CMU_CALCTRL_DOWNSEL_HFXO,               
    CALCTRL_DOWNSEL_LFXO     = CMU_CALCTRL_DOWNSEL_LFXO,              
    CALCTRL_DOWNSEL_HFRCO    = CMU_CALCTRL_DOWNSEL_HFRCO,             
    CALCTRL_DOWNSEL_LFRCO    = CMU_CALCTRL_DOWNSEL_LFRCO,               
    CALCTRL_DOWNSEL_AUXHFRCO = CMU_CALCTRL_DOWNSEL_AUXHFRCO, 
} CMUCALDowncounterSelTypeDef;

typedef enum 
{
    CMD_USBCCLKSEL_HFCLKNODIV = CMU_CMD_USBCCLKSEL_HFCLKNODIV,           
    CMD_USBCCLKSEL_LFXO       = CMU_CMD_USBCCLKSEL_LFXO,                
    CMD_USBCCLKSEL_LFRCO      = CMU_CMD_USBCCLKSEL_LFRCO,                 
} CMUUSBCoreClockSelTypeDef;

typedef enum
{
    CMU_IRQ_HFRCORDY    = CMU_IF_HFRCORDY, 
    CMU_IRQ_HFXORDY     = CMU_IF_HFXORDY, 
    CMU_IRQ_LFRCORDY    = CMU_IF_LFRCORDY,
    CMU_IRQ_LFXORDY     = CMU_IF_LFXORDY,
    CMU_IRQ_AUXHFRCORDY = CMU_IF_AUXHFRCORDY,
    CMU_IRQ_CALRDY      = CMU_IF_CALRDY,
} CMUIrqTypeDef;


/*************************************************************************************************************
*                                            FUNCTION PROTOTYPES                                             *
*************************************************************************************************************/
static inline void CMUOscillatorEnable (CMUOscTypeDef osc)
{
    CMU->OSCENCMD = (0x1UL << osc);
        
    while (!(CMU->STATUS & (0x1UL << (osc + 1))));
}

static inline void CMUOscillatorDisable (CMUOscTypeDef osc)
{
    CMU->OSCENCMD = (0x1UL << (osc + 1));
}

static inline CPU_BOOL CMUOscillatorStatus (CMUOscTypeDef osc)
{
    if (CMU->STATUS & (0x1UL << osc ))
    {
        return DEF_ON;
    }
    
    return DEF_OFF;
}

static inline void CMULECLKSync (CPU_INT32U mask)
{
    if (CMU->FREEZE & CMU_FREEZE_REGFREEZE_FREEZE)
    {
        return;
    }
    
    while (CMU->SYNCBUSY & mask);
}

static inline void CMUHFPERCLKEnable (void)
{
    CMU->HFPERCLKDIV |= CMU_HFPERCLKDIV_HFPERCLKEN;
}

static inline void CMUHFPERCLKDisable (void)
{
    CMU->HFPERCLKDIV &= ~CMU_HFPERCLKDIV_HFPERCLKEN;
}

static inline void CMULFCLKEnable (CMULFClockTypeDef clock, CMULFCLKSourceTypeDef source)
{
    CMU->LFCLKSEL = (CMU->LFCLKSEL & ((~CMU_LFCLKSEL_LFA_MASK) << clock)) | (source << clock);
}

static inline void CMULFCLKDisable (CMULFClockTypeDef clock)
{
    CMU->LFCLKSEL = (CMU->LFCLKSEL & ((~CMU_LFCLKSEL_LFA_MASK) << clock)) | (CMU_LFCLKSEL_LFA_DISABLED << clock);
}

static inline void CMUHFPeripheralClockEnable (CMUHFPERClockTypeDef clock)
{
    CMU->HFPERCLKEN0 |= clock;
}

static inline void CMUHFPeripheralClockDisable (CMUHFPERClockTypeDef clock)
{
    CMU->HFPERCLKEN0 &= ~clock;;
}

static inline void CMUHFCOREClockEnable (CMUHFCOREClockTypeDef clock)
{
    CMU->HFCORECLKEN0 |= clock;;
}

static inline void CMUHFCOREClockDisable (CMUHFCOREClockTypeDef clock)
{
    CMU->HFCORECLKEN0 &= ~clock;
}

static inline void CMULEAPeripheralClockEnable (CMULEAClockTypeDef clock)
{
    CMULECLKSync(CMU_SYNCBUSY_LFACLKEN0);
    CMU->LFACLKEN0 |= clock;
}

static inline void CMULEAPeripheralClockDisable (CMULEAClockTypeDef clock)
{
    CMULECLKSync(CMU_SYNCBUSY_LFACLKEN0);
    CMU->LFACLKEN0 &= ~clock;
}

static inline void CMULEBPeripheralClockEnable (CMULEBClockTypeDef clock)
{
    CMULECLKSync(CMU_SYNCBUSY_LFBCLKEN0);
    CMU->LFBCLKEN0 |= clock;
}

static inline void CMULEBPeripheralClockDisable (CMULEBClockTypeDef clock)
{
    CMULECLKSync(CMU_SYNCBUSY_LFBCLKEN0);
    CMU->LFBCLKEN0 &= ~clock;
}

static inline void CMUContinuousCalibrationEnable (void)
{
    CMU->CALCTRL = (CMU->CALCTRL & ~CMU_CALCTRL_CONT_MASK) | CMU_CALCTRL_CONT_ENABLE;
}

static inline void CMUCalibrationStartEnable (void)  
{
    CMU->CMD = (CMU->CMD & ~CMU_CMD_CALSTART_MASK) | CMU_CMD_CALSTART;
}

static inline void CMUCalibrationStopEnable (void)  
{
    CMU->CMD = (CMU->CMD & ~CMU_CMD_CALSTOP_MASK) | CMU_CMD_CALSTOP;
}

static inline void CMUClockSelectforLFAExtendedEnable (void)
{
    CMU->LFCLKSEL = (CMU->LFCLKSEL & ~CMU_LFCLKSEL_LFAE_MASK) | CMU_LFCLKSEL_LFAE_ULFRCO;
}

static inline void CMUClockSelectforLFAExtendedDisable (void)
{
    CMU->LFCLKSEL = (CMU->LFCLKSEL & ~CMU_LFCLKSEL_LFAE_MASK) | CMU_LFCLKSEL_LFAE_DISABLED;
}

static inline void CMUClockSelectforLFBExtendedEnable (void)
{
    CMU->LFCLKSEL = (CMU->LFCLKSEL & ~CMU_LFCLKSEL_LFBE_MASK) | CMU_LFCLKSEL_LFBE_ULFRCO;
}

static inline void CMUClockSelectforLFBExtendedDisable (void)
{
    CMU->LFCLKSEL = (CMU->LFCLKSEL & ~CMU_LFCLKSEL_LFBE_MASK) | CMU_LFCLKSEL_LFBE_DISABLED;
}

static inline void CMUFreezeEnable (void)
{
    while (CMU->SYNCBUSY);

    CMU->FREEZE = CMU_FREEZE_REGFREEZE_FREEZE;
}

static inline void CMUFreezeDisable (void)
{
    CMU->FREEZE = 0;
}

static inline void CMUPCNTClockEnable (CMUPCNTClockTypeDef clock)
{
    CMU->PCNTCTRL |= (0x1UL << (clock - 1));
}

static inline void CMUPCNTClockDisable (CMUPCNTClockTypeDef clock)
{
    CMU->PCNTCTRL &= ~(0x1UL << (clock - 1));
}

static inline void CMUCLKOUTPinEnable (CMUCLKOUTPinTypeDef pin)
{
    CMU->ROUTE |= pin;
}

static inline void CMUCLKOUTPinDisable (CMUCLKOUTPinTypeDef pin)
{
    CMU->ROUTE &= ~pin;
}

static inline void CMULock(void)
{
    CMU->LOCK = CMU_LOCK_LOCKKEY_LOCK;
}

static inline void CMUUnlock(void)
{
    CMU->LOCK = CMU_LOCK_LOCKKEY_UNLOCK;
}

static inline void CMUCalibrateStart(void)
{
    CMU->CMD = CMU_CMD_CALSTART;
}

static inline CPU_INT32U CMUCalibrateCountGet (void)
{
    while (CMU->STATUS & CMU_STATUS_CALBSY);

    return CMU->CALCNT;
}

static inline void CMUIntEnable (CPU_INT32U flag)
{
    CMU->IEN |= flag;
}

static inline void CMUIntDisable (CPU_INT32U flag)
{
    CMU->IEN &= ~flag;
}

static inline CPU_INT32U CMUIntGet (void)
{
    return CMU->IF;
}

static inline CPU_BOOL CMUIntFlagGet (CMUIrqTypeDef irq)
{
    if (CMU->IF & irq)
    {
        return DEF_ON;
    }
    else
    {
        return DEF_OFF;
    }
}

static inline void CMUIntSet (CPU_INT32U flag)
{
    CMU->IFS = flag;
}

static inline void CMUIntClear (CPU_INT32U flag)
{
    CMU->IFC = flag;
}

static inline CPU_INT32U CMUIntStatusGet (void)
{
    return CMU->IEN;
}

static inline CPU_INT32U CMUIntEnabledGet (void)
{
    CPU_INT32U en;

    en = 0;
    en = CMU->IEN;

    /* Bitwise AND of pending and enabled interrupts */
    return CMU->IF & en;
}


/*************************************************************************************************************
*                                            FUNCTION STATEMENT                                              *
*************************************************************************************************************/
void CMUHFXOModeSel (CMUHFXOModeSelTypeDef sel);
void CMUHFXOBoostSet (CMUHFXOBoostTypeDef pcent);
void CMUHFXOTimeoutSet (CMUHFXOTimeoutTypeDef time);
void CMULFXOModeSel (CMULFXOModeSelTypeDef sel);
void CMULFXOBoostSet (CMULFXOBoostTypeDef pcent);
void CMULFXOTimeoutSet (CMULFXOTimeoutTypeDef time);
CPU_INT32U CMUCalibrate (CPU_INT32U count, CMUOscTypeDef osc);
void CMUHFCLKSelectSet (CMUHFCLKSourceTypeDef source);
void CMUHFCoreClockSet (CMUHFCOREClockDivTypeDef div);
void CMUHFPeripheralClockSet (CMUHFPERClockDivTypeDef div);
void CMULFARTCClockSet (CMULFARTCClockDivTypeDef div);
void CMULFALETIMER0ClockSet (CMULFALETIMER0ClockDivTypeDef div);
void CMULFALCDClockSet (CMULFALCDClockDivTypeDef div);
void CMULFBLEUART0ClockSet (CMULFBLEUART0ClockDivTypeDef div);
void CMULFBLEUART1ClockSet (CMULFBLEUART1ClockDivTypeDef div);
CPU_INT32U CMUHFRCOFreqGet (void);
CPU_INT32U CMUHFClockGet (void);
CPU_INT32U CMUHFCoreClockGet (void);
CPU_INT32U CMUHFPeripheralClockGet (void);
CPU_INT32U CMULFClockGet (CMULFClockTypeDef clock);
CPU_INT32U CMULFAPeripheralClockGet (CMULEAClockTypeDef lea);
CPU_INT32U CMULFBPeripheralClockGet (CMULEBClockTypeDef leb);
void CMUHFRCOFrqSet (CMUHFRCOBandTypeDef band);
void CMUHFRCOStartupDelaySet (CPU_INT32U value);
CPU_INT32U CMUHFRCOStartupDelayGet (void);
void CMULCDClkFDIVSet (CPU_INT32U div);
CPU_INT32U CMULCDClkFDIVGet (void);
void CMUOscillatorTuningSet (CMUOscTypeDef osc, CPU_INT32U val);
CPU_INT32U CMUOscillatorTuningGet (CMUOscTypeDef osc);
void CMUPCNTClockSel (CMUPCNTClockTypeDef clock, CMUPCNTClockSelTypeDef sel);      
void CMUCLKOUTLocationSet (CMUCLKOUTLocationTypeDef locatoin);
void CMUCLKOUT0Sel (CMUCLKOUT0SelTypeDef sel);
void CMUCLKOUT1Sel (CMUCLKOUT1SelTypeDef sel);
void CMUHFCOREClkEDivFactorSet (CMUHFCOREClkEDivTypeDef factor);
void AUXHFRCOBandSelectSet (CMUAUXHFRCOBandSelTypeDef sel);
void CalibrationUpcounterSelectSet (CMUCALUpcounterSelTypeDef sel);
void CalibrationDowncounterSelectSet (CMUCALDowncounterSelTypeDef sel);
void USBCoreClockSelectSet (CMUUSBCoreClockSelTypeDef sel);
void CMUStatusUpdata (void);
void CMUStatusRestore (void);
void CMUSOscLFDisable (void);


/*************************************************************************************************************
*                                               MODULE END                                                   *
*************************************************************************************************************/   
#ifdef __cplusplus
}
#endif

#endif 