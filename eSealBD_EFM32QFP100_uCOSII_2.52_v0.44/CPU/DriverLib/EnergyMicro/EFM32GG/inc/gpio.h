/*************************************************************************************************************
*                                                  MODULE                                                    *
*************************************************************************************************************/
#ifndef GPIO_H
#define GPIO_H

#ifdef __cplusplus
extern "C" {
#endif
    

/*************************************************************************************************************
*                                                 DEFINES                                                    *
*************************************************************************************************************/
#define GPIO                                    ((GPIORegTypeDef *)GPIO_BASE)
    
/* Bit fields for GPIO CTRL */
#define GPIO_CTRL_RESETVALUE                    0x00000000UL    /* Default value for GPIO_CTRL              */
#define GPIO_CTRL_MASK                          0x00000003UL    /* Mask for GPIO_CTRL                       */
#define GPIO_CTRL_DRIVEMODE_SHIFT               0               /* Shift value for GPIO_CTRL_DRIVEMODE      */
#define GPIO_CTRL_DRIVEMODE_MASK                (0x3UL >> 0)    /* Bit mask for GPIO_CTRL_DRIVEMODE         */
#define GPIO_CTRL_DRIVEMODE_DEFAULT             (0x0UL >> 0)    /* Mode DEFAULT for GPIO_CTRL_DRIVEMODE     */
#define GPIO_CTRL_DRIVEMODE_STANDARD            (0x0UL >> 0)    /* Mode STANDARD for GPIO_CTRL_DRIVEMODE    */
#define GPIO_CTRL_DRIVEMODE_LOWEST              (0x1UL >> 0)    /* Mode LOWEST for GPIO_CTRL_DRIVEMODE      */
#define GPIO_CTRL_DRIVEMODE_HIGH                (0x2UL >> 0)    /* Mode HIGH for GPIO_CTRL_DRIVEMODE        */
#define GPIO_CTRL_DRIVEMODE_LOW                 (0x3UL >> 0)    /* Mode LOW for GPIO_CTRL_DRIVEMODE         */

/* Bit fields for GPIO MODEL */
#define GPIO_MODEL_RESETVALUE                   0x00000000UL    /* Default value for GPIO_MODEL             */
#define GPIO_MODEL_MASK                         0xFFFFFFFFUL    /* Mask for GPIO_MODEL                      */
#define GPIO_MODEL_0_SHIFT                      0               /* Shift value for GPIO_MODEL_MODE0         */
#define GPIO_MODEL_0_MASK                       (0xFUL >> 0)    /* Bit mask for GPIO_MODEL_MODE0            */
#define GPIO_MODEL_0_DEFAULT                    (0x0UL >> 0)    /* Mode DEFAULT for GPIO_MODEL_MODE0        */
#define GPIO_MODEL_0_DISABLED                   (0x0UL >> 0)    /* Mode DISABLED for GPIO_MODEL_MODE0       */
#define GPIO_MODEL_0_INPUT                      (0x1UL >> 0)    /* Mode INPUT for GPIO_MODEL_MODE0          */
#define GPIO_MODEL_0_INPUTPULL                  (0x2UL >> 0)    /* Mode INPUTPULL for GPIO_MODEL_MODE0      */
#define GPIO_MODEL_0_INPUTPULLFILTER            (0x3UL >> 0)    /* Mode INPUTPULLFILTER for GPIO_MODEL_MODE0 */
#define GPIO_MODEL_0_PUSHPULL                   (0x4UL >> 0)    /* Mode PUSHPULL for GPIO_MODEL_MODE0       */
#define GPIO_MODEL_0_PUSHPULLDRIVE              (0x5UL >> 0)    /* Mode PUSHPULLDRIVE for GPIO_MODEL_MODE0  */
#define GPIO_MODEL_0_WIREDOR                    (0x6UL >> 0)    /* Mode WIREDOR for GPIO_MODEL_MODE0        */
#define GPIO_MODEL_0_WIREDORPULLDOWN            (0x7UL >> 0)    /* Mode WIREDORPULLDOWN for GPIO_MODEL_MODE0 */
#define GPIO_MODEL_0_WIREDAND                   (0x8UL >> 0)    /* Mode WIREDAND for GPIO_MODEL_MODE0       */
#define GPIO_MODEL_0_WIREDANDFILTER             (0x9UL >> 0)    /* Mode WIREDANDFILTER for GPIO_MODEL_MODE0 */
#define GPIO_MODEL_0_WIREDANDPULLUP             (0xAUL >> 0)    /* Mode WIREDANDPULLUP for GPIO_MODEL_MODE0 */
#define GPIO_MODEL_0_WIREDANDPULLUPFILTER       (0xBUL >> 0)    /* Mode WIREDANDPULLUPFILTER GPIO_MODEL_MODE0 */
#define GPIO_MODEL_0_WIREDANDDRIVE              (0xCUL >> 0)    /* Mode WIREDANDDRIVE for GPIO_MODEL_MODE0  */
#define GPIO_MODEL_0_WIREDANDDRIVEFILTER        (0xDUL >> 0)    /* Mode WIREDANDDRIVEFILTER for GPIO_MODEL_MODE0 */
#define GPIO_MODEL_0_WIREDANDDRIVEPULLUP        (0xEUL >> 0)    /* Mode WIREDANDDRIVEPULLUP for GPIO_MODEL_MODE0 */
#define GPIO_MODEL_0_WIREDANDDRIVEPULLUPFILTER  (0xFUL >> 0)    /* Mode WIREDANDDRIVEPULLUPFILTER for GPIO_MODEL_MODE0 */
#define GPIO_MODEL_1_SHIFT                      4               /* Shift value for GPIO_MODEL_MODE1         */
#define GPIO_MODEL_1_MASK                       (0xFUL >> 4)    /* Bit mask for GPIO_MODEL_MODE1            */
#define GPIO_MODEL_1_DEFAULT                    (0x0UL >> 4)    /* Mode DEFAULT for GPIO_MODEL_MODE1        */
#define GPIO_MODEL_1_DISABLED                   (0x0UL >> 4)    /* Mode DISABLED for GPIO_MODEL_MODE1       */
#define GPIO_MODEL_1_INPUT                      (0x1UL >> 4)    /* Mode INPUT for GPIO_MODEL_MODE1          */
#define GPIO_MODEL_1_INPUTPULL                  (0x2UL >> 4)    /* Mode INPUTPULL for GPIO_MODEL_MODE1      */
#define GPIO_MODEL_1_INPUTPULLFILTER            (0x3UL >> 4)    /* Mode INPUTPULLFILTER for GPIO_MODEL_MODE1 */
#define GPIO_MODEL_1_PUSHPULL                   (0x4UL >> 4)    /* Mode PUSHPULL for GPIO_MODEL_MODE1       */
#define GPIO_MODEL_1_PUSHPULLDRIVE              (0x5UL >> 4)    /* Mode PUSHPULLDRIVE for GPIO_MODEL_MODE1  */
#define GPIO_MODEL_1_WIREDOR                    (0x6UL >> 4)    /* Mode WIREDOR for GPIO_MODEL_MODE1        */
#define GPIO_MODEL_1_WIREDORPULLDOWN            (0x7UL >> 4)    /* Mode WIREDORPULLDOWN for GPIO_MODEL_MODE1 */
#define GPIO_MODEL_1_WIREDAND                   (0x8UL >> 4)    /* Mode WIREDAND for GPIO_MODEL_MODE1       */
#define GPIO_MODEL_1_WIREDANDFILTER             (0x9UL >> 4)    /* Mode WIREDANDFILTER for GPIO_MODEL_MODE1 */
#define GPIO_MODEL_1_WIREDANDPULLUP             (0xAUL >> 4)    /* Mode WIREDANDPULLUP for GPIO_MODEL_MODE1 */
#define GPIO_MODEL_1_WIREDANDPULLUPFILTER       (0xBUL >> 4)    /* Mode WIREDANDPULLUPFILTER GPIO_MODEL_MODE1 */
#define GPIO_MODEL_1_WIREDANDDRIVE              (0xCUL >> 4)    /* Mode WIREDANDDRIVE for GPIO_MODEL_MODE1  */
#define GPIO_MODEL_1_WIREDANDDRIVEFILTER        (0xDUL >> 4)    /* Mode WIREDANDDRIVEFILTER for GPIO_MODEL_MODE1 */
#define GPIO_MODEL_1_WIREDANDDRIVEPULLUP        (0xEUL >> 4)    /* Mode WIREDANDDRIVEPULLUP for GPIO_MODEL_MODE1 */
#define GPIO_MODEL_1_WIREDANDDRIVEPULLUPFILTER  (0xFUL >> 4)    /* Mode WIREDANDDRIVEPULLUPFILTER for GPIO_MODEL_MODE1 */
#define GPIO_MODEL_2_SHIFT                      8               /* Shift value for GPIO_MODEL_MODE2         */
#define GPIO_MODEL_2_MASK                       (0xFUL >> 8)    /* Bit mask for GPIO_MODEL_MODE2            */
#define GPIO_MODEL_2_DEFAULT                    (0x0UL >> 8)    /* Mode DEFAULT for GPIO_MODEL_MODE2        */
#define GPIO_MODEL_2_DISABLED                   (0x0UL >> 8)    /* Mode DISABLED for GPIO_MODEL_MODE2       */
#define GPIO_MODEL_2_INPUT                      (0x1UL >> 8)    /* Mode INPUT for GPIO_MODEL_MODE2          */
#define GPIO_MODEL_2_INPUTPULL                  (0x2UL >> 8)    /* Mode INPUTPULL for GPIO_MODEL_MODE2      */
#define GPIO_MODEL_2_INPUTPULLFILTER            (0x3UL >> 8)    /* Mode INPUTPULLFILTER for GPIO_MODEL_MODE2 */
#define GPIO_MODEL_2_PUSHPULL                   (0x4UL >> 8)    /* Mode PUSHPULL for GPIO_MODEL_MODE2       */
#define GPIO_MODEL_2_PUSHPULLDRIVE              (0x5UL >> 8)    /* Mode PUSHPULLDRIVE for GPIO_MODEL_MODE2  */
#define GPIO_MODEL_2_WIREDOR                    (0x6UL >> 8)    /* Mode WIREDOR for GPIO_MODEL_MODE2        */
#define GPIO_MODEL_2_WIREDORPULLDOWN            (0x7UL >> 8)    /* Mode WIREDORPULLDOWN for GPIO_MODEL_MODE2 */
#define GPIO_MODEL_2_WIREDAND                   (0x8UL >> 8)    /* Mode WIREDAND for GPIO_MODEL_MODE2       */
#define GPIO_MODEL_2_WIREDANDFILTER             (0x9UL >> 8)    /* Mode WIREDANDFILTER for GPIO_MODEL_MODE2 */
#define GPIO_MODEL_2_WIREDANDPULLUP             (0xAUL >> 8)    /* Mode WIREDANDPULLUP for GPIO_MODEL_MODE2 */
#define GPIO_MODEL_2_WIREDANDPULLUPFILTER       (0xBUL >> 8)    /* Mode WIREDANDPULLUPFILTER GPIO_MODEL_MODE2 */
#define GPIO_MODEL_2_WIREDANDDRIVE              (0xCUL >> 8)    /* Mode WIREDANDDRIVE for GPIO_MODEL_MODE2  */
#define GPIO_MODEL_2_WIREDANDDRIVEFILTER        (0xDUL >> 8)    /* Mode WIREDANDDRIVEFILTER for GPIO_MODEL_MODE2 */
#define GPIO_MODEL_2_WIREDANDDRIVEPULLUP        (0xEUL >> 8)    /* Mode WIREDANDDRIVEPULLUP for GPIO_MODEL_MODE2 */
#define GPIO_MODEL_2_WIREDANDDRIVEPULLUPFILTER  (0xFUL >> 8)    /* Mode WIREDANDDRIVEPULLUPFILTER for GPIO_MODEL_MODE2 */      
#define GPIO_MODEL_3_SHIFT                      12              /* Shift value for GPIO_MODEL_MODE3         */
#define GPIO_MODEL_3_MASK                       (0xFUL >> 12)   /* Bit mask for GPIO_MODEL_MODE3            */
#define GPIO_MODEL_3_DEFAULT                    (0x0UL >> 12)   /* Mode DEFAULT for GPIO_MODEL_MODE3        */
#define GPIO_MODEL_3_DISABLED                   (0x0UL >> 12)   /* Mode DISABLED for GPIO_MODEL_MODE3       */
#define GPIO_MODEL_3_INPUT                      (0x1UL >> 12)   /* Mode INPUT for GPIO_MODEL_MODE3          */
#define GPIO_MODEL_3_INPUTPULL                  (0x2UL >> 12)   /* Mode INPUTPULL for GPIO_MODEL_MODE3      */
#define GPIO_MODEL_3_INPUTPULLFILTER            (0x3UL >> 12)   /* Mode INPUTPULLFILTER for GPIO_MODEL_MODE3 */
#define GPIO_MODEL_3_PUSHPULL                   (0x4UL >> 12)   /* Mode PUSHPULL for GPIO_MODEL_MODE3       */
#define GPIO_MODEL_3_PUSHPULLDRIVE              (0x5UL >> 12)   /* Mode PUSHPULLDRIVE for GPIO_MODEL_MODE3  */
#define GPIO_MODEL_3_WIREDOR                    (0x6UL >> 12)   /* Mode WIREDOR for GPIO_MODEL_MODE3        */
#define GPIO_MODEL_3_WIREDORPULLDOWN            (0x7UL >> 12)   /* Mode WIREDORPULLDOWN for GPIO_MODEL_MODE3 */
#define GPIO_MODEL_3_WIREDAND                   (0x8UL >> 12)   /* Mode WIREDAND for GPIO_MODEL_MODE3       */
#define GPIO_MODEL_3_WIREDANDFILTER             (0x9UL >> 12)   /* Mode WIREDANDFILTER for GPIO_MODEL_MODE3 */
#define GPIO_MODEL_3_WIREDANDPULLUP             (0xAUL >> 12)   /* Mode WIREDANDPULLUP for GPIO_MODEL_MODE3 */
#define GPIO_MODEL_3_WIREDANDPULLUPFILTER       (0xBUL >> 12)   /* Mode WIREDANDPULLUPFILTER GPIO_MODEL_MODE3 */
#define GPIO_MODEL_3_WIREDANDDRIVE              (0xCUL >> 12)   /* Mode WIREDANDDRIVE for GPIO_MODEL_MODE3  */
#define GPIO_MODEL_3_WIREDANDDRIVEFILTER        (0xDUL >> 12)   /* Mode WIREDANDDRIVEFILTER for GPIO_MODEL_MODE3 */
#define GPIO_MODEL_3_WIREDANDDRIVEPULLUP        (0xEUL >> 12)   /* Mode WIREDANDDRIVEPULLUP for GPIO_MODEL_MODE3 */
#define GPIO_MODEL_3_WIREDANDDRIVEPULLUPFILTER  (0xFUL >> 12)   /* Mode WIREDANDDRIVEPULLUPFILTER for GPIO_MODEL_MODE3 */   
#define GPIO_MODEL_4_SHIFT                      16              /* Shift value for GPIO_MODEL_MODE4         */
#define GPIO_MODEL_4_MASK                       (0xFUL >> 16)   /* Bit mask for GPIO_MODEL_MODE4            */
#define GPIO_MODEL_4_DEFAULT                    (0x0UL >> 16)   /* Mode DEFAULT for GPIO_MODEL_MODE4        */
#define GPIO_MODEL_4_DISABLED                   (0x0UL >> 16)   /* Mode DISABLED for GPIO_MODEL_MODE4       */
#define GPIO_MODEL_4_INPUT                      (0x1UL >> 16)   /* Mode INPUT for GPIO_MODEL_MODE4          */
#define GPIO_MODEL_4_INPUTPULL                  (0x2UL >> 16)   /* Mode INPUTPULL for GPIO_MODEL_MODE4      */
#define GPIO_MODEL_4_INPUTPULLFILTER            (0x3UL >> 16)   /* Mode INPUTPULLFILTER for GPIO_MODEL_MODE4 */
#define GPIO_MODEL_4_PUSHPULL                   (0x4UL >> 16)   /* Mode PUSHPULL for GPIO_MODEL_MODE4       */
#define GPIO_MODEL_4_PUSHPULLDRIVE              (0x5UL >> 16)   /* Mode PUSHPULLDRIVE for GPIO_MODEL_MODE4  */
#define GPIO_MODEL_4_WIREDOR                    (0x6UL >> 16)   /* Mode WIREDOR for GPIO_MODEL_MODE4        */
#define GPIO_MODEL_4_WIREDORPULLDOWN            (0x7UL >> 16)   /* Mode WIREDORPULLDOWN for GPIO_MODEL_MODE4 */
#define GPIO_MODEL_4_WIREDAND                   (0x8UL >> 16)   /* Mode WIREDAND for GPIO_MODEL_MODE4       */
#define GPIO_MODEL_4_WIREDANDFILTER             (0x9UL >> 16)   /* Mode WIREDANDFILTER for GPIO_MODEL_MODE4 */
#define GPIO_MODEL_4_WIREDANDPULLUP             (0xAUL >> 16)   /* Mode WIREDANDPULLUP for GPIO_MODEL_MODE4 */
#define GPIO_MODEL_4_WIREDANDPULLUPFILTER       (0xBUL >> 16)   /* Mode WIREDANDPULLUPFILTER GPIO_MODEL_MODE4 */
#define GPIO_MODEL_4_WIREDANDDRIVE              (0xCUL >> 16)   /* Mode WIREDANDDRIVE for GPIO_MODEL_MODE4  */
#define GPIO_MODEL_4_WIREDANDDRIVEFILTER        (0xDUL >> 16)   /* Mode WIREDANDDRIVEFILTER for GPIO_MODEL_MODE4 */
#define GPIO_MODEL_4_WIREDANDDRIVEPULLUP        (0xEUL >> 16)   /* Mode WIREDANDDRIVEPULLUP for GPIO_MODEL_MODE4 */
#define GPIO_MODEL_4_WIREDANDDRIVEPULLUPFILTER  (0xFUL >> 16)   /* Mode WIREDANDDRIVEPULLUPFILTER for GPIO_MODEL_MODE4 */
#define GPIO_MODEL_5_SHIFT                      20              /* Shift value for GPIO_MODEL_MODE5         */
#define GPIO_MODEL_5_MASK                       (0xFUL >> 20)   /* Bit mask for GPIO_MODEL_MODE5            */
#define GPIO_MODEL_5_DEFAULT                    (0x0UL >> 20)   /* Mode DEFAULT for GPIO_MODEL_MODE5        */
#define GPIO_MODEL_5_DISABLED                   (0x0UL >> 20)   /* Mode DISABLED for GPIO_MODEL_MODE5       */
#define GPIO_MODEL_5_INPUT                      (0x1UL >> 20)   /* Mode INPUT for GPIO_MODEL_MODE5          */
#define GPIO_MODEL_5_INPUTPULL                  (0x2UL >> 20)   /* Mode INPUTPULL for GPIO_MODEL_MODE5      */
#define GPIO_MODEL_5_INPUTPULLFILTER            (0x3UL >> 20)   /* Mode INPUTPULLFILTER for GPIO_MODEL_MODE5 */
#define GPIO_MODEL_5_PUSHPULL                   (0x4UL >> 20)   /* Mode PUSHPULL for GPIO_MODEL_MODE5       */
#define GPIO_MODEL_5_PUSHPULLDRIVE              (0x5UL >> 20)   /* Mode PUSHPULLDRIVE for GPIO_MODEL_MODE5  */
#define GPIO_MODEL_5_WIREDOR                    (0x6UL >> 20)   /* Mode WIREDOR for GPIO_MODEL_MODE5        */
#define GPIO_MODEL_5_WIREDORPULLDOWN            (0x7UL >> 20)   /* Mode WIREDORPULLDOWN for GPIO_MODEL_MODE5 */
#define GPIO_MODEL_5_WIREDAND                   (0x8UL >> 20)   /* Mode WIREDAND for GPIO_MODEL_MODE5       */
#define GPIO_MODEL_5_WIREDANDFILTER             (0x9UL >> 20)   /* Mode WIREDANDFILTER for GPIO_MODEL_MODE5 */
#define GPIO_MODEL_5_WIREDANDPULLUP             (0xAUL >> 20)   /* Mode WIREDANDPULLUP for GPIO_MODEL_MODE5 */
#define GPIO_MODEL_5_WIREDANDPULLUPFILTER       (0xBUL >> 20)   /* Mode WIREDANDPULLUPFILTER GPIO_MODEL_MODE5 */
#define GPIO_MODEL_5_WIREDANDDRIVE              (0xCUL >> 20)   /* Mode WIREDANDDRIVE for GPIO_MODEL_MODE5  */
#define GPIO_MODEL_5_WIREDANDDRIVEFILTER        (0xDUL >> 20)   /* Mode WIREDANDDRIVEFILTER for GPIO_MODEL_MODE5 */
#define GPIO_MODEL_5_WIREDANDDRIVEPULLUP        (0xEUL >> 20)   /* Mode WIREDANDDRIVEPULLUP for GPIO_MODEL_MODE5 */
#define GPIO_MODEL_5_WIREDANDDRIVEPULLUPFILTER  (0xFUL >> 20)   /* Mode WIREDANDDRIVEPULLUPFILTER for GPIO_MODEL_MODE5 */   
#define GPIO_MODEL_6_SHIFT                      24              /* Shift value for GPIO_MODEL_MODE6         */
#define GPIO_MODEL_6_MASK                       (0xFUL >> 24)   /* Bit mask for GPIO_MODEL_MODE6            */
#define GPIO_MODEL_6_DEFAULT                    (0x0UL >> 24)   /* Mode DEFAULT for GPIO_MODEL_MODE6        */
#define GPIO_MODEL_6_DISABLED                   (0x0UL >> 24)   /* Mode DISABLED for GPIO_MODEL_MODE36       */
#define GPIO_MODEL_6_INPUT                      (0x1UL >> 24)   /* Mode INPUT for GPIO_MODEL_MODE6          */
#define GPIO_MODEL_6_INPUTPULL                  (0x2UL >> 24)   /* Mode INPUTPULL for GPIO_MODEL_MODE6      */
#define GPIO_MODEL_6_INPUTPULLFILTER            (0x3UL >> 24)   /* Mode INPUTPULLFILTER for GPIO_MODEL_MODE6 */
#define GPIO_MODEL_6_PUSHPULL                   (0x4UL >> 24)   /* Mode PUSHPULL for GPIO_MODEL_MODE6       */
#define GPIO_MODEL_6_PUSHPULLDRIVE              (0x5UL >> 24)   /* Mode PUSHPULLDRIVE for GPIO_MODEL_MODE6  */
#define GPIO_MODEL_6_WIREDOR                    (0x6UL >> 24)   /* Mode WIREDOR for GPIO_MODEL_MODE6        */
#define GPIO_MODEL_6_WIREDORPULLDOWN            (0x7UL >> 24)   /* Mode WIREDORPULLDOWN for GPIO_MODEL_MODE6 */
#define GPIO_MODEL_6_WIREDAND                   (0x8UL >> 24)   /* Mode WIREDAND for GPIO_MODEL_MODE6       */
#define GPIO_MODEL_6_WIREDANDFILTER             (0x9UL >> 24)   /* Mode WIREDANDFILTER for GPIO_MODEL_MODE6 */
#define GPIO_MODEL_6_WIREDANDPULLUP             (0xAUL >> 24)   /* Mode WIREDANDPULLUP for GPIO_MODEL_MODE6 */
#define GPIO_MODEL_6_WIREDANDPULLUPFILTER       (0xBUL >> 24)   /* Mode WIREDANDPULLUPFILTER GPIO_MODEL_MODE6 */
#define GPIO_MODEL_6_WIREDANDDRIVE              (0xCUL >> 24)   /* Mode WIREDANDDRIVE for GPIO_MODEL_MODE6  */
#define GPIO_MODEL_6_WIREDANDDRIVEFILTER        (0xDUL >> 24)   /* Mode WIREDANDDRIVEFILTER for GPIO_MODEL_MODE6 */
#define GPIO_MODEL_6_WIREDANDDRIVEPULLUP        (0xEUL >> 24)   /* Mode WIREDANDDRIVEPULLUP for GPIO_MODEL_MODE6 */
#define GPIO_MODEL_6_WIREDANDDRIVEPULLUPFILTER  (0xFUL >> 24)   /* Mode WIREDANDDRIVEPULLUPFILTER for GPIO_MODEL_MODE6 */ 
#define GPIO_MODEL_7_SHIFT                      28              /* Shift value for GPIO_MODEL_MODE7         */
#define GPIO_MODEL_7_MASK                       (0xFUL >> 28)   /* Bit mask for GPIO_MODEL_MODE7            */
#define GPIO_MODEL_7_DEFAULT                    (0x0UL >> 28)   /* Mode DEFAULT for GPIO_MODEL_MODE7        */
#define GPIO_MODEL_7_DISABLED                   (0x0UL >> 28)   /* Mode DISABLED for GPIO_MODEL_MODE7       */
#define GPIO_MODEL_7_INPUT                      (0x1UL >> 28)   /* Mode INPUT for GPIO_MODEL_MODE7          */
#define GPIO_MODEL_7_INPUTPULL                  (0x2UL >> 28)   /* Mode INPUTPULL for GPIO_MODEL_MODE7      */
#define GPIO_MODEL_7_INPUTPULLFILTER            (0x3UL >> 28)   /* Mode INPUTPULLFILTER for GPIO_MODEL_MODE7 */
#define GPIO_MODEL_7_PUSHPULL                   (0x4UL >> 28)   /* Mode PUSHPULL for GPIO_MODEL_MODE7       */
#define GPIO_MODEL_7_PUSHPULLDRIVE              (0x5UL >> 28)   /* Mode PUSHPULLDRIVE for GPIO_MODEL_MODE7  */
#define GPIO_MODEL_7_WIREDOR                    (0x6UL >> 28)   /* Mode WIREDOR for GPIO_MODEL_MODE7        */
#define GPIO_MODEL_7_WIREDORPULLDOWN            (0x7UL >> 28)   /* Mode WIREDORPULLDOWN for GPIO_MODEL_MODE7 */
#define GPIO_MODEL_7_WIREDAND                   (0x8UL >> 28)   /* Mode WIREDAND for GPIO_MODEL_MODE7       */
#define GPIO_MODEL_7_WIREDANDFILTER             (0x9UL >> 28)   /* Mode WIREDANDFILTER for GPIO_MODEL_MODE7 */
#define GPIO_MODEL_7_WIREDANDPULLUP             (0xAUL >> 28)   /* Mode WIREDANDPULLUP for GPIO_MODEL_MODE7 */
#define GPIO_MODEL_7_WIREDANDPULLUPFILTER       (0xBUL >> 28)   /* Mode WIREDANDPULLUPFILTER GPIO_MODEL_MODE7 */
#define GPIO_MODEL_7_WIREDANDDRIVE              (0xCUL >> 28)   /* Mode WIREDANDDRIVE for GPIO_MODEL_MODE7  */
#define GPIO_MODEL_7_WIREDANDDRIVEFILTER        (0xDUL >> 28)   /* Mode WIREDANDDRIVEFILTER for GPIO_MODEL_MODE7 */
#define GPIO_MODEL_7_WIREDANDDRIVEPULLUP        (0xEUL >> 28)   /* Mode WIREDANDDRIVEPULLUP for GPIO_MODEL_MODE7 */
#define GPIO_MODEL_7_WIREDANDDRIVEPULLUPFILTER  (0xFUL >> 28)   /* Mode WIREDANDDRIVEPULLUPFILTER for GPIO_MODEL_MODE7 */

/* Bit fields for GPIO MODEH */
#define GPIO_MODEH_RESETVALUE                   0x00000000UL    /* Default value for GPIO_MODEH             */
#define GPIO_MODEH_MASK                         0xFFFFFFFFUL    /* Mask for GPIO_MODEH                      */
#define GPIO_MODEH_8_SHIFT                      0               /* Shift value for GPIO_MODEH_MODE8         */
#define GPIO_MODEH_8_MASK                       (0xFUL >> 0)    /* Bit mask for GPIO_MODEH_MODE8            */
#define GPIO_MODEH_8_DEFAULT                    (0x0UL >> 0)    /* Mode DEFAULT for GPIO_MODEH_MODE8        */
#define GPIO_MODEH_8_DISABLED                   (0x0UL >> 0)    /* Mode DISABLED for GPIO_MODEH_MODE8       */
#define GPIO_MODEH_8_INPUT                      (0x1UL >> 0)    /* Mode INPUT for GPIO_MODEH_MODE8          */
#define GPIO_MODEH_8_INPUTPULL                  (0x2UL >> 0)    /* Mode INPUTPULL for GPIO_MODEH_MODE8      */
#define GPIO_MODEH_8_INPUTPULLFILTER            (0x3UL >> 0)    /* Mode INPUTPULLFILTER for GPIO_MODEH_MODE8 */
#define GPIO_MODEH_8_PUSHPULL                   (0x4UL >> 0)    /* Mode PUSHPULL for GPIO_MODEH_MODE8       */
#define GPIO_MODEH_8_PUSHPULLDRIVE              (0x5UL >> 0)    /* Mode PUSHPULLDRIVE for GPIO_MODEH_MODE8  */
#define GPIO_MODEH_8_WIREDOR                    (0x6UL >> 0)    /* Mode WIREDOR for GPIO_MODEH_MODE8        */
#define GPIO_MODEH_8_WIREDORPULLDOWN            (0x7UL >> 0)    /* Mode WIREDORPULLDOWN for GPIO_MODEH_MODE8 */
#define GPIO_MODEH_8_WIREDAND                   (0x8UL >> 0)    /* Mode WIREDAND for GPIO_MODEH_MODE8       */
#define GPIO_MODEH_8_WIREDANDFILTER             (0x9UL >> 0)    /* Mode WIREDANDFILTER for GPIO_MODEH_MODE8 */
#define GPIO_MODEH_8_WIREDANDPULLUP             (0xAUL >> 0)    /* Mode WIREDANDPULLUP for GPIO_MODEH_MODE8 */
#define GPIO_MODEH_8_WIREDANDPULLUPFILTER       (0xBUL >> 0)    /* Mode WIREDANDPULLUPFILTER GPIO_MODEH_MODE8 */
#define GPIO_MODEH_8_WIREDANDDRIVE              (0xCUL >> 0)    /* Mode WIREDANDDRIVE for GPIO_MODEH_MODE8  */
#define GPIO_MODEH_8_WIREDANDDRIVEFILTER        (0xDUL >> 0)    /* Mode WIREDANDDRIVEFILTER for GPIO_MODEH_MODE8 */
#define GPIO_MODEH_8_WIREDANDDRIVEPULLUP        (0xEUL >> 0)    /* Mode WIREDANDDRIVEPULLUP for GPIO_MODEH_MODE8 */
#define GPIO_MODEH_8_WIREDANDDRIVEPULLUPFILTER  (0xFUL >> 0)    /* Mode WIREDANDDRIVEPULLUPFILTER for GPIO_MODEH_MODE8 */
#define GPIO_MODEH_9_SHIFT                      4               /* Shift value for GPIO_MODEH_MODE9         */
#define GPIO_MODEH_9_MASK                       (0xFUL >> 4)    /* Bit mask for GPIO_MODEH_MODE9            */
#define GPIO_MODEH_9_DEFAULT                    (0x0UL >> 4)    /* Mode DEFAULT for GPIO_MODEH_MODE9        */
#define GPIO_MODEH_9_DISABLED                   (0x0UL >> 4)    /* Mode DISABLED for GPIO_MODEH_MODE9       */
#define GPIO_MODEH_9_INPUT                      (0x1UL >> 4)    /* Mode INPUT for GPIO_MODEH_MODE9          */
#define GPIO_MODEH_9_INPUTPULL                  (0x2UL >> 4)    /* Mode INPUTPULL for GPIO_MODEH_MODE9      */
#define GPIO_MODEH_9_INPUTPULLFILTER            (0x3UL >> 4)    /* Mode INPUTPULLFILTER for GPIO_MODEH_MODE9 */
#define GPIO_MODEH_9_PUSHPULL                   (0x4UL >> 4)    /* Mode PUSHPULL for GPIO_MODEH_MODE9       */
#define GPIO_MODEH_9_PUSHPULLDRIVE              (0x5UL >> 4)    /* Mode PUSHPULLDRIVE for GPIO_MODEH_MODE9  */
#define GPIO_MODEH_9_WIREDOR                    (0x6UL >> 4)    /* Mode WIREDOR for GPIO_MODEH_MODE9        */
#define GPIO_MODEH_9_WIREDORPULLDOWN            (0x7UL >> 4)    /* Mode WIREDORPULLDOWN for GPIO_MODEH_MODE9 */
#define GPIO_MODEH_9_WIREDAND                   (0x8UL >> 4)    /* Mode WIREDAND for GPIO_MODEH_MODE9       */
#define GPIO_MODEH_9_WIREDANDFILTER             (0x9UL >> 4)    /* Mode WIREDANDFILTER for GPIO_MODEH_MODE9 */
#define GPIO_MODEH_9_WIREDANDPULLUP             (0xAUL >> 4)    /* Mode WIREDANDPULLUP for GPIO_MODEH_MODE9 */
#define GPIO_MODEH_9_WIREDANDPULLUPFILTER       (0xBUL >> 4)    /* Mode WIREDANDPULLUPFILTER GPIO_MODEH_MODE9 */
#define GPIO_MODEH_9_WIREDANDDRIVE              (0xCUL >> 4)    /* Mode WIREDANDDRIVE for GPIO_MODEH_MODE9  */
#define GPIO_MODEH_9_WIREDANDDRIVEFILTER        (0xDUL >> 4)    /* Mode WIREDANDDRIVEFILTER for GPIO_MODEH_MODE9 */
#define GPIO_MODEH_9_WIREDANDDRIVEPULLUP        (0xEUL >> 4)    /* Mode WIREDANDDRIVEPULLUP for GPIO_MODEH_MODE9 */
#define GPIO_MODEH_9_WIREDANDDRIVEPULLUPFILTER  (0xFUL >> 4)    /* Mode WIREDANDDRIVEPULLUPFILTER for GPIO_MODEH_MODE9 */
#define GPIO_MODEH_10_SHIFT                     8               /* Shift value for GPIO_MODEH_MODE10        */
#define GPIO_MODEH_10_MASK                      (0xFUL >> 8)    /* Bit mask for GPIO_MODEH_MODE10           */
#define GPIO_MODEH_10_DEFAULT                   (0x0UL >> 8)    /* Mode DEFAULT for GPIO_MODEH_MODE10       */
#define GPIO_MODEH_10_DISABLED                  (0x0UL >> 8)    /* Mode DISABLED for GPIO_MODEH_MODE10      */
#define GPIO_MODEH_10_INPUT                     (0x1UL >> 8)    /* Mode INPUT for GPIO_MODEH_MODE10         */
#define GPIO_MODEH_10_INPUTPULL                 (0x2UL >> 8)    /* Mode INPUTPULL for GPIO_MODEH_MODE10     */
#define GPIO_MODEH_10_INPUTPULLFILTER           (0x3UL >> 8)    /* Mode INPUTPULLFILTER for GPIO_MODEH_MODE10 */
#define GPIO_MODEH_10_PUSHPULL                  (0x4UL >> 8)    /* Mode PUSHPULL for GPIO_MODEH_MODE10      */
#define GPIO_MODEH_10_PUSHPULLDRIVE             (0x5UL >> 8)    /* Mode PUSHPULLDRIVE for GPIO_MODEH_MODE10 */
#define GPIO_MODEH_10_WIREDOR                   (0x6UL >> 8)    /* Mode WIREDOR for GPIO_MODELH_MODE10       */
#define GPIO_MODEH_10_WIREDORPULLDOWN           (0x7UL >> 8)    /* Mode WIREDORPULLDOWN for GPIO_MODEH_MODE10 */
#define GPIO_MODEH_10_WIREDAND                  (0x8UL >> 8)    /* Mode WIREDAND for GPIO_MODEH_MODE10      */
#define GPIO_MODEH_10_WIREDANDFILTER            (0x9UL >> 8)    /* Mode WIREDANDFILTER for GPIO_MODEH_MODE10 */
#define GPIO_MODEH_10_WIREDANDPULLUP            (0xAUL >> 8)    /* Mode WIREDANDPULLUP for GPIO_MODEH_MODE10 */
#define GPIO_MODEH_10_WIREDANDPULLUPFILTER      (0xBUL >> 8)    /* Mode WIREDANDPULLUPFILTER GPIO_MODEH_MODE10 */
#define GPIO_MODEH_10_WIREDANDDRIVE             (0xCUL >> 8)    /* Mode WIREDANDDRIVE for GPIO_MODEH_MODE10 */
#define GPIO_MODEH_10_WIREDANDDRIVEFILTER       (0xDUL >> 8)    /* Mode WIREDANDDRIVEFILTER for GPIO_MODEH_MODE10 */
#define GPIO_MODEH_10_WIREDANDDRIVEPULLUP       (0xEUL >> 8)    /* Mode WIREDANDDRIVEPULLUP for GPIO_MODEH_MODE10 */
#define GPIO_MODEH_10_WIREDANDDRIVEPULLUPFILTER (0xFUL >> 8)    /* Mode WIREDANDDRIVEPULLUPFILTER for GPIO_MODEH_MODE10 */      
#define GPIO_MODEH_11_SHIFT                      12              /* Shift value for GPIO_MODEH_MODE11       */
#define GPIO_MODEH_11_MASK                      (0xFUL >> 12)   /* Bit mask for GPIO_MODEH_MODE11           */
#define GPIO_MODEH_11_DEFAULT                   (0x0UL >> 12)   /* Mode DEFAULT for GPIO_MODEH_MODE11       */
#define GPIO_MODEH_11_DISABLED                  (0x0UL >> 12)   /* Mode DISABLED for GPIO_MODEH_MODE11      */
#define GPIO_MODEH_11_INPUT                     (0x1UL >> 12)   /* Mode INPUT for GPIO_MODEH_MODE11         */
#define GPIO_MODEH_11_INPUTPULL                 (0x2UL >> 12)   /* Mode INPUTPULL for GPIO_MODEH_MODE11     */
#define GPIO_MODEH_11_INPUTPULLFILTER           (0x3UL >> 12)   /* Mode INPUTPULLFILTER for GPIO_MODEH_MODE11 */
#define GPIO_MODEH_11_PUSHPULL                  (0x4UL >> 12)   /* Mode PUSHPULL for GPIO_MODEH_MODE11      */
#define GPIO_MODEH_11_PUSHPULLDRIVE             (0x5UL >> 12)   /* Mode PUSHPULLDRIVE for GPIO_MODEH_MODE11 */ 
#define GPIO_MODEH_11_WIREDOR                   (0x6UL >> 12)   /* Mode WIREDOR for GPIO_MODEH_MODE11       */
#define GPIO_MODEH_11_WIREDORPULLDOWN           (0x7UL >> 12)   /* Mode WIREDORPULLDOWN for GPIO_MODEH_MODE11 */
#define GPIO_MODEH_11_WIREDAND                  (0x8UL >> 12)   /* Mode WIREDAND for GPIO_MODEH_MODE11      */
#define GPIO_MODEH_11_WIREDANDFILTER            (0x9UL >> 12)   /* Mode WIREDANDFILTER for GPIO_MODEH_MODE11 */
#define GPIO_MODEH_11_WIREDANDPULLUP            (0xAUL >> 12)   /* Mode WIREDANDPULLUP for GPIO_MODEH_MODE11 */
#define GPIO_MODEH_11_WIREDANDPULLUPFILTER      (0xBUL >> 12)   /* Mode WIREDANDPULLUPFILTER GPIO_MODEH_MODE11 */
#define GPIO_MODEH_11_WIREDANDDRIVE             (0xCUL >> 12)   /* Mode WIREDANDDRIVE for GPIO_MODEH_MODE11 */
#define GPIO_MODEH_11_WIREDANDDRIVEFILTER       (0xDUL >> 12)   /* Mode WIREDANDDRIVEFILTER for GPIO_MODEH_MODE11 */
#define GPIO_MODEH_11_WIREDANDDRIVEPULLUP       (0xEUL >> 12)   /* Mode WIREDANDDRIVEPULLUP for GPIO_MODEH_MODE11 */
#define GPIO_MODEH_11_WIREDANDDRIVEPULLUPFILTER (0xFUL >> 12)   /* Mode WIREDANDDRIVEPULLUPFILTER for GPIO_MODEH_MODE11 */   
#define GPIO_MODEH_12_SHIFT                     16              /* Shift value for GPIO_MODEH_MODE12        */
#define GPIO_MODEH_12_MASK                      (0xFUL >> 16)   /* Bit mask for GPIO_MODEH_MODE12           */
#define GPIO_MODEH_12_DEFAULT                   (0x0UL >> 16)   /* Mode DEFAULT for GPIO_MODEH_MODE12       */
#define GPIO_MODEH_12_DISABLED                  (0x0UL >> 16)   /* Mode DISABLED for GPIO_MODEH_MODE12      */
#define GPIO_MODEH_12_INPUT                     (0x1UL >> 16)   /* Mode INPUT for GPIO_MODEH_MODE12         */
#define GPIO_MODEH_12_INPUTPULL                 (0x2UL >> 16)   /* Mode INPUTPULL for GPIO_MODEH_MODE12     */
#define GPIO_MODEH_12_INPUTPULLFILTER           (0x3UL >> 16)   /* Mode INPUTPULLFILTER for GPIO_MODEH_MODE12 */
#define GPIO_MODEH_12_PUSHPULL                  (0x4UL >> 16)   /* Mode PUSHPULL for GPIO_MODEH_MODE12      */
#define GPIO_MODEH_12_PUSHPULLDRIVE             (0x5UL >> 16)   /* Mode PUSHPULLDRIVE for GPIO_MODEH_MODE12 */
#define GPIO_MODEH_12_WIREDOR                   (0x6UL >> 16)   /* Mode WIREDOR for GPIO_MODEH_MODE12       */
#define GPIO_MODEH_12_WIREDORPULLDOWN           (0x7UL >> 16)   /* Mode WIREDORPULLDOWN for GPIO_MODEH_MODE12 */
#define GPIO_MODEH_12_WIREDAND                  (0x8UL >> 16)   /* Mode WIREDAND for GPIO_MODEH_MODE12      */
#define GPIO_MODEH_12_WIREDANDFILTER            (0x9UL >> 16)   /* Mode WIREDANDFILTER for GPIO_MODEH_MODE12 */
#define GPIO_MODEH_12_WIREDANDPULLUP            (0xAUL >> 16)   /* Mode WIREDANDPULLUP for GPIO_MODEH_MODE12 */
#define GPIO_MODEH_12_WIREDANDPULLUPFILTER      (0xBUL >> 16)   /* Mode WIREDANDPULLUPFILTER GPIO_MODEH_MODE12 */
#define GPIO_MODEH_12_WIREDANDDRIVE             (0xCUL >> 16)   /* Mode WIREDANDDRIVE for GPIO_MODEH_MODE12 */
#define GPIO_MODEH_12_WIREDANDDRIVEFILTER       (0xDUL >> 16)   /* Mode WIREDANDDRIVEFILTER for GPIO_MODEH_MODE12 */
#define GPIO_MODEH_12_WIREDANDDRIVEPULLUP       (0xEUL >> 16)   /* Mode WIREDANDDRIVEPULLUP for GPIO_MODEH_MODE12 */
#define GPIO_MODEH_12_WIREDANDDRIVEPULLUPFILTER (0xFUL >> 16)   /* Mode WIREDANDDRIVEPULLUPFILTER for GPIO_MODEH_MODE12 */
#define GPIO_MODEH_13_SHIFT                     20              /* Shift value for GPIO_MODEH_MODE13        */
#define GPIO_MODEH_13_MASK                      (0xFUL >> 20)   /* Bit mask for GPIO_MODEH_MODE13           */
#define GPIO_MODEH_13_DEFAULT                   (0x0UL >> 20)   /* Mode DEFAULT for GPIO_MODEH_MODE13       */
#define GPIO_MODEH_13_DISABLED                  (0x0UL >> 20)   /* Mode DISABLED for GPIO_MODEH_MODE13      */
#define GPIO_MODEH_13_INPUT                     (0x1UL >> 20)   /* Mode INPUT for GPIO_MODEH_MODE13         */
#define GPIO_MODEH_13_INPUTPULL                 (0x2UL >> 20)   /* Mode INPUTPULL for GPIO_MODEH_MODE13     */
#define GPIO_MODEH_13_INPUTPULLFILTER           (0x3UL >> 20)   /* Mode INPUTPULLFILTER for GPIO_MODEH_MODE13 */
#define GPIO_MODEH_13_PUSHPULL                  (0x4UL >> 20)   /* Mode PUSHPULL for GPIO_MODEH_MODE13      */
#define GPIO_MODEH_13_PUSHPULLDRIVE             (0x5UL >> 20)   /* Mode PUSHPULLDRIVE for GPIO_MODEH_MODE13 */
#define GPIO_MODEH_13_WIREDOR                   (0x6UL >> 20)   /* Mode WIREDOR for GPIO_MODEH_MODE13       */
#define GPIO_MODEH_13_WIREDORPULLDOWN           (0x7UL >> 20)   /* Mode WIREDORPULLDOWN for GPIO_MODEH_MODE13 */
#define GPIO_MODEH_13_WIREDAND                  (0x8UL >> 20)   /* Mode WIREDAND for GPIO_MODEH_MODE13      */
#define GPIO_MODEH_13_WIREDANDFILTER            (0x9UL >> 20)   /* Mode WIREDANDFILTER for GPIO_MODEH_MODE13 */
#define GPIO_MODEH_13_WIREDANDPULLUP            (0xAUL >> 20)   /* Mode WIREDANDPULLUP for GPIO_MODEH_MODE13 */
#define GPIO_MODEH_13_WIREDANDPULLUPFILTER      (0xBUL >> 20)   /* Mode WIREDANDPULLUPFILTER GPIO_MODEH_MODE13 */
#define GPIO_MODEH_13_WIREDANDDRIVE             (0xCUL >> 20)   /* Mode WIREDANDDRIVE for GPIO_MODEH_MODE13 */
#define GPIO_MODEH_13_WIREDANDDRIVEFILTER       (0xDUL >> 20)   /* Mode WIREDANDDRIVEFILTER for GPIO_MODEH_MODE13 */
#define GPIO_MODEH_13_WIREDANDDRIVEPULLUP       (0xEUL >> 20)   /* Mode WIREDANDDRIVEPULLUP for GPIO_MODEH_MODE13 */
#define GPIO_MODEH_13_WIREDANDDRIVEPULLUPFILTER (0xFUL >> 20)   /* Mode WIREDANDDRIVEPULLUPFILTER for GPIO_MODEH_MODE13 */   
#define GPIO_MODEH_14_SHIFT                     24              /* Shift value for GPIO_MODEH_MODE14        */
#define GPIO_MODEH_14_MASK                      (0xFUL >> 24)   /* Bit mask for GPIO_MODEH_MODE14           */
#define GPIO_MODEH_14_DEFAULT                   (0x0UL >> 24)   /* Mode DEFAULT for GPIO_MODEH_MODE14       */
#define GPIO_MODEH_14_DISABLED                  (0x0UL >> 24)   /* Mode DISABLED for GPIO_MODEH_MODE144     */
#define GPIO_MODEH_14_INPUT                     (0x1UL >> 24)   /* Mode INPUT for GPIO_MODEH_MODE14         */
#define GPIO_MODEH_14_INPUTPULL                 (0x2UL >> 24)   /* Mode INPUTPULL for GPIO_MODEH_MODE14     */
#define GPIO_MODEH_14_INPUTPULLFILTER           (0x3UL >> 24)   /* Mode INPUTPULLFILTER for GPIO_MODEH_MODE14 */
#define GPIO_MODEH_14_PUSHPULL                  (0x4UL >> 24)   /* Mode PUSHPULL for GPIO_MODEH_MODE14      */
#define GPIO_MODEH_14_PUSHPULLDRIVE             (0x5UL >> 24)   /* Mode PUSHPULLDRIVE for GPIO_MODEH_MODE14 */
#define GPIO_MODEH_14_WIREDOR                   (0x6UL >> 24)   /* Mode WIREDOR for GPIO_MODEH_MODE14       */
#define GPIO_MODEH_14_WIREDORPULLDOWN           (0x7UL >> 24)   /* Mode WIREDORPULLDOWN for GPIO_MODEH_MODE14 */
#define GPIO_MODEH_14_WIREDAND                  (0x8UL >> 24)   /* Mode WIREDAND for GPIO_MODEH_MODE14      */
#define GPIO_MODEH_14_WIREDANDFILTER            (0x9UL >> 24)   /* Mode WIREDANDFILTER for GPIO_MODEH_MODE14 */
#define GPIO_MODEH_14_WIREDANDPULLUP            (0xAUL >> 24)   /* Mode WIREDANDPULLUP for GPIO_MODEH_MODE14 */
#define GPIO_MODEH_14_WIREDANDPULLUPFILTER      (0xBUL >> 24)   /* Mode WIREDANDPULLUPFILTER GPIO_MODEH_MODE14 */
#define GPIO_MODEH_14_WIREDANDDRIVE             (0xCUL >> 24)   /* Mode WIREDANDDRIVE for GPIO_MODEH_MODE14 */
#define GPIO_MODEH_14_WIREDANDDRIVEFILTER       (0xDUL >> 24)   /* Mode WIREDANDDRIVEFILTER for GPIO_MODEH_MODE14 */
#define GPIO_MODEH_14_WIREDANDDRIVEPULLUP       (0xEUL >> 24)   /* Mode WIREDANDDRIVEPULLUP for GPIO_MODEH_MODE14 */
#define GPIO_MODEH_14_WIREDANDDRIVEPULLUPFILTER (0xFUL >> 24)   /* Mode WIREDANDDRIVEPULLUPFILTER for GPIO_MODEH_MODE14 */ 
#define GPIO_MODEH_15_SHIFT                     28              /* Shift value for GPIO_MODEH_MODE15        */
#define GPIO_MODEH_15_MASK                      (0xFUL >> 28)   /* Bit mask for GPIO_MODEH_MODE15           */
#define GPIO_MODEH_15_DEFAULT                   (0x0UL >> 28)   /* Mode DEFAULT for GPIO_MODEH_MODE15       */
#define GPIO_MODEH_15_DISABLED                  (0x0UL >> 28)   /* Mode DISABLED for GPIO_MODEH_MODE15      */
#define GPIO_MODEH_15_INPUT                     (0x1UL >> 28)   /* Mode INPUT for GPIO_MODEH_MODE15         */
#define GPIO_MODEH_15_INPUTPULL                 (0x2UL >> 28)   /* Mode INPUTPULL for GPIO_MODEH_MODE15     */
#define GPIO_MODEH_15_INPUTPULLFILTER           (0x3UL >> 28)   /* Mode INPUTPULLFILTER for GPIO_MODEH_MODE15 */
#define GPIO_MODEH_15_PUSHPULL                  (0x4UL >> 28)   /* Mode PUSHPULL for GPIO_MODEH_MODE15      */
#define GPIO_MODEH_15_PUSHPULLDRIVE             (0x5UL >> 28)   /* Mode PUSHPULLDRIVE for GPIO_MODEH_MODE15 */
#define GPIO_MODEH_15_WIREDOR                   (0x6UL >> 28)   /* Mode WIREDOR for GPIO_MODEH_MODE15       */
#define GPIO_MODEH_15_WIREDORPULLDOWN           (0x7UL >> 28)   /* Mode WIREDORPULLDOWN for GPIO_MODEH_MODE15 */
#define GPIO_MODEH_15_WIREDAND                  (0x8UL >> 28)   /* Mode WIREDAND for GPIO_MODEH_MODE15      */
#define GPIO_MODEH_15_WIREDANDFILTER            (0x9UL >> 28)   /* Mode WIREDANDFILTER for GPIO_MODEH_MODE15 */
#define GPIO_MODEH_15_WIREDANDPULLUP            (0xAUL >> 28)   /* Mode WIREDANDPULLUP for GPIO_MODEH_MODE15 */
#define GPIO_MODEH_15_WIREDANDPULLUPFILTER      (0xBUL >> 28)   /* Mode WIREDANDPULLUPFILTER GPIO_MODEH_MODE15 */
#define GPIO_MODEH_15_WIREDANDDRIVE             (0xCUL >> 28)   /* Mode WIREDANDDRIVE for GPIO_MODEH_MODE15 */
#define GPIO_MODEH_15_WIREDANDDRIVEFILTER       (0xDUL >> 28)   /* Mode WIREDANDDRIVEFILTER for GPIO_MODEH_MODE15 */
#define GPIO_MODEH_15_WIREDANDDRIVEPULLUP       (0xEUL >> 28)   /* Mode WIREDANDDRIVEPULLUP for GPIO_MODEH_MODE15 */
#define GPIO_MODEH_15_WIREDANDDRIVEPULLUPFILTER (0xFUL >> 28)   /* Mode WIREDANDDRIVEPULLUPFILTER for GPIO_MODEH_MODE15 */  
    
/* Bit fields for GPIO DOUT */
#define GPIO_DOUT_RESETVALUE                    0x00000000UL    /* Default value for GPIO_DOUT              */
#define GPIO_DOUT_MASK                          0x0000FFFFUL    /* Mask for GPIO_DOUT                       */
#define GPIO_DOUT_DOUT_SHIFT                    0               /* Shift value for GPIO_DOUT_DOUT           */
#define GPIO_DOUT_DOUT_MASK                     0xFFFFUL        /* Bit mask for GPIO_DOUT_DOUT              */
#define GPIO_DOUT_DOUT_DEFAULT                  (0x0UL >> 0)    /* Mode DEFAULT for GPIO_DOUT_DOUT          */

/* Bit fields for GPIO DOUTSET */
#define GPIO_DOUTSET_RESETVALUE                 0x00000000UL    /* Default value for GPIO_DOUTSET           */
#define GPIO_DOUTSET_MASK                       0x0000FFFFUL    /* Mask for GPIO_DOUTSET                    */
#define GPIO_DOUTSET_DOUTSET_SHIFT              0               /* Shift value for GPIO_DOUTSET_DOUTSET     */
#define GPIO_DOUTSET_DOUTSET_MASK               0xFFFFUL        /* Bit mask for GPIO_DOUTSET_DOUTSET        */
#define GPIO_DOUTSET_DOUTSET_DEFAULT            (0x0UL >> 0)    /* Mode DEFAULT for GPIO_DOUTSET_DOUTSET    */

/* Bit fields for GPIO DOUTCLR */
#define GPIO_DOUTCLR_RESETVALUE                 0x00000000UL    /* Default value for GPIO_DOUTCLR           */
#define GPIO_DOUTCLR_MASK                       0x0000FFFFUL    /* Mask for GPIO_P_DOUTCLR                  */
#define GPIO_DOUTCLR_DOUTCLR_SHIFT              0               /* Shift value for GPIO_DOUTCLR_DOUTCLR     */
#define GPIO_DOUTCLR_DOUTCLR_MASK               0xFFFFUL        /* Bit mask for GPIO_DOUTCLR_DOUTCLR        */
#define GPIO_DOUTCLR_DOUTCLR_DEFAULT            (0x0UL >> 0)    /* Mode DEFAULT for GPIO_DOUTCLR_DOUTCLR    */

/* Bit fields for GPIO DOUTTGL */
#define GPIO_DOUTTGL_RESETVALUE                 0x00000000UL    /* Default value for GPIO_DOUTTGL           */
#define GPIO_DOUTTGL_MASK                       0x0000FFFFUL    /* Mask for GPIO_DOUTTGL                    */
#define GPIO_DOUTTGL_DOUTTGL_SHIFT              0               /* Shift value for GPIO_DOUTTGL_DOUTTGL     */
#define GPIO_DOUTTGL_DOUTTGL_MASK               0xFFFFUL        /* Bit mask for GPIO_DOUTTGL_DOUTTGL        */
#define GPIO_DOUTTGL_DOUTTGL_DEFAULT            (0x0UL >> 0)    /* Mode DEFAULT for GPIO_DOUTTGL_DOUTTGL    */

/* Bit fields for GPIO DIN */
#define GPIO_DIN_RESETVALUE                     0x00000000UL    /* Default value for GPIO_DIN               */
#define GPIO_DIN_MASK                           0x0000FFFFUL    /* Mask for GPIO_DIN                        */
#define GPIO_DIN_DIN_SHIFT                      0               /* Shift value for GPIO_DIN_DIN             */
#define GPIO_DIN_DIN_MASK                       0xFFFFUL        /* Bit mask for GPIO_DIN_DIN                */
#define GPIO_DIN_DIN_DEFAULT                    (0x0UL >> 0)    /* Mode DEFAULT for GPIO_DIN_DIN            */

/* Bit fields for GPIO P_PINLOCKN */
#define GPIO_PINLOCKN_RESETVALUE                0x0000FFFFUL    /* Default value for GPIO_PINLOCKN          */
#define GPIO_PINLOCKN_MASK                      0x0000FFFFUL    /* Mask for GPIO_PINLOCKN                   */
#define GPIO_PINLOCKN_PINLOCKN_SHIFT            0               /* Shift value for GPIO_PINLOCKN_PINLOCKN   */
#define GPIO_PINLOCKN_PINLOCKN_MASK             0xFFFFUL        /* Bit mask for GPIO_PINLOCKN_PINLOCKN      */
#define GPIO_PINLOCKN_PINLOCKN_DEFAULT          (0x0UL >> 0)    /* Mode DEFAULT for GPIO_PINLOCKN_PINLOCKN  */

/* Bit fields for GPIO EXTIPSELL */
#define GPIO_EXTIPSELL_RESETVALUE               0x00000000UL    /* Default value for GPIO_EXTIPSELL         */
#define GPIO_EXTIPSELL_MASK                     0x77777777UL    /* Mask for GPIO_EXTIPSELL                  */
#define GPIO_EXTIPSELL_EXTIPSEL0_SHIFT          0               /* Shift value for GPIO_EXTIPSELL_EXTIPSEL0 */
#define GPIO_EXTIPSELL_EXTIPSEL0_MASK           (0x7UL << 0)    /* Bit mask for GPIO_EXTIPSELL_EXTIPSEL0    */
#define GPIO_EXTIPSELL_EXTIPSEL0_DEFAULT        (0x0UL << 0)    /* Mode DEFAULT for GPIO_EXTIPSELL_EXTIPSEL0 */
#define GPIO_EXTIPSELL_EXTIPSEL0_PORTA          (0x0UL << 0)    /* Mode PORTA for GPIO_EXTIPSELL_EXTIPSEL0  */
#define GPIO_EXTIPSELL_EXTIPSEL0_PORTB          (0x1UL << 0)    /* Mode PORTB for GPIO_EXTIPSELL_EXTIPSEL0  */
#define GPIO_EXTIPSELL_EXTIPSEL0_PORTC          (0x2UL << 0)    /* Mode PORTC for GPIO_EXTIPSELL_EXTIPSEL0  */
#define GPIO_EXTIPSELL_EXTIPSEL0_PORTD          (0x3UL << 0)    /* Mode PORTD for GPIO_EXTIPSELL_EXTIPSEL0  */
#define GPIO_EXTIPSELL_EXTIPSEL0_PORTE          (0x4UL << 0)    /* Mode PORTE for GPIO_EXTIPSELL_EXTIPSEL0  */
#define GPIO_EXTIPSELL_EXTIPSEL0_PORTF          (0x6UL << 0)    /* Mode PORTF for GPIO_EXTIPSELL_EXTIPSEL0  */  
#define GPIO_EXTIPSELL_EXTIPSEL1_SHIFT          4               /* Shift value for GPIO_EXTIPSELL_EXTIPSEL1 */
#define GPIO_EXTIPSELL_EXTIPSEL1_MASK           (0x7UL << 4)    /* Bit mask for GPIO_EXTIPSELL_EXTIPSEL1    */
#define GPIO_EXTIPSELL_EXTIPSEL1_DEFAULT        (0x0UL << 4)    /* Mode DEFAULT for GPIO_EXTIPSELL_EXTIPSEL1 */
#define GPIO_EXTIPSELL_EXTIPSEL1_PORTA          (0x0UL << 4)    /* Mode PORTA for GPIO_EXTIPSELL_EXTIPSEL1  */
#define GPIO_EXTIPSELL_EXTIPSEL1_PORTB          (0x1UL << 4)    /* Mode PORTB for GPIO_EXTIPSELL_EXTIPSEL1  */
#define GPIO_EXTIPSELL_EXTIPSEL1_PORTC          (0x2UL << 4)    /* Mode PORTC for GPIO_EXTIPSELL_EXTIPSEL1  */
#define GPIO_EXTIPSELL_EXTIPSEL1_PORTD          (0x3UL << 4)    /* Mode PORTD for GPIO_EXTIPSELL_EXTIPSEL1  */
#define GPIO_EXTIPSELL_EXTIPSEL1_PORTE          (0x4UL << 4)    /* Mode PORTE for GPIO_EXTIPSELL_EXTIPSEL1  */
#define GPIO_EXTIPSELL_EXTIPSEL1_PORTF          (0x6UL << 4)    /* Mode PORTF for GPIO_EXTIPSELL_EXTIPSEL1  */   
#define GPIO_EXTIPSELL_EXTIPSEL2_SHIFT          8               /* Shift value for GPIO_EXTIPSELL_EXTIPSEL2 */
#define GPIO_EXTIPSELL_EXTIPSEL2_MASK           (0x7UL << 8)    /* Bit mask for GPIO_EXTIPSELL_EXTIPSEL2    */
#define GPIO_EXTIPSELL_EXTIPSEL2_DEFAULT        (0x0UL << 8)    /* Mode DEFAULT for GPIO_EXTIPSELL_EXTIPSEL2 */
#define GPIO_EXTIPSELL_EXTIPSEL2_PORTA          (0x0UL << 8)    /* Mode PORTA for GPIO_EXTIPSELL_EXTIPSEL2  */
#define GPIO_EXTIPSELL_EXTIPSEL2_PORTB          (0x1UL << 8)    /* Mode PORTB for GPIO_EXTIPSELL_EXTIPSEL2  */
#define GPIO_EXTIPSELL_EXTIPSEL2_PORTC          (0x2UL << 8)    /* Mode PORTC for GPIO_EXTIPSELL_EXTIPSEL2  */
#define GPIO_EXTIPSELL_EXTIPSEL2_PORTD          (0x3UL << 8)    /* Mode PORTD for GPIO_EXTIPSELL_EXTIPSEL2  */
#define GPIO_EXTIPSELL_EXTIPSEL2_PORTE          (0x4UL << 8)    /* Mode PORTE for GPIO_EXTIPSELL_EXTIPSEL2  */
#define GPIO_EXTIPSELL_EXTIPSEL2_PORTF          (0x6UL << 8)    /* Mode PORTF for GPIO_EXTIPSELL_EXTIPSEL2  */
#define GPIO_EXTIPSELL_EXTIPSEL3_SHIFT          12              /* Shift value for GPIO_EXTIPSELL_EXTIPSEL3 */
#define GPIO_EXTIPSELL_EXTIPSEL3_MASK           (0x7UL << 12)   /* Bit mask for GPIO_EXTIPSELL_EXTIPSEL3    */
#define GPIO_EXTIPSELL_EXTIPSEL3_DEFAULT        (0x0UL << 12)   /* Mode DEFAULT for GPIO_EXTIPSELL_EXTIPSEL3 */
#define GPIO_EXTIPSELL_EXTIPSEL3_PORTA          (0x0UL << 12)   /* Mode PORTA for GPIO_EXTIPSELL_EXTIPSEL3  */
#define GPIO_EXTIPSELL_EXTIPSEL3_PORTB          (0x1UL << 12)   /* Mode PORTB for GPIO_EXTIPSELL_EXTIPSEL3  */
#define GPIO_EXTIPSELL_EXTIPSEL3_PORTC          (0x2UL << 12)   /* Mode PORTC for GPIO_EXTIPSELL_EXTIPSEL3  */
#define GPIO_EXTIPSELL_EXTIPSEL3_PORTD          (0x3UL << 12)   /* Mode PORTD for GPIO_EXTIPSELL_EXTIPSEL3  */
#define GPIO_EXTIPSELL_EXTIPSEL3_PORTE          (0x4UL << 12)   /* Mode PORTE for GPIO_EXTIPSELL_EXTIPSEL3  */
#define GPIO_EXTIPSELL_EXTIPSEL3_PORTF          (0x6UL << 12)   /* Mode PORTF for GPIO_EXTIPSELL_EXTIPSEL3  */   
#define GPIO_EXTIPSELL_EXTIPSEL4_SHIFT          16              /* Shift value for GPIO_EXTIPSELL_EXTIPSEL4 */
#define GPIO_EXTIPSELL_EXTIPSEL4_MASK           (0x7UL << 16)   /* Bit mask for GPIO_EXTIPSELL_EXTIPSEL4    */
#define GPIO_EXTIPSELL_EXTIPSEL4_DEFAULT        (0x0UL << 16)   /* Mode DEFAULT for GPIO_EXTIPSELL_EXTIPSEL4 */
#define GPIO_EXTIPSELL_EXTIPSEL4_PORTA          (0x0UL << 16)   /* Mode PORTA for GPIO_EXTIPSELL_EXTIPSEL4  */
#define GPIO_EXTIPSELL_EXTIPSEL4_PORTB          (0x1UL << 16)   /* Mode PORTB for GPIO_EXTIPSELL_EXTIPSEL4  */
#define GPIO_EXTIPSELL_EXTIPSEL4_PORTC          (0x2UL << 16)   /* Mode PORTC for GPIO_EXTIPSELL_EXTIPSEL4  */
#define GPIO_EXTIPSELL_EXTIPSEL4_PORTD          (0x3UL << 16)   /* Mode PORTD for GPIO_EXTIPSELL_EXTIPSEL4  */
#define GPIO_EXTIPSELL_EXTIPSEL4_PORTE          (0x4UL << 16)   /* Mode PORTE for GPIO_EXTIPSELL_EXTIPSEL4  */
#define GPIO_EXTIPSELL_EXTIPSEL4_PORTF          (0x6UL << 16)   /* Mode PORTF for GPIO_EXTIPSELL_EXTIPSEL4  */ 
#define GPIO_EXTIPSELL_EXTIPSEL5_SHIFT          20              /* Shift value for GPIO_EXTIPSELL_EXTIPSEL5 */
#define GPIO_EXTIPSELL_EXTIPSEL5_MASK           (0x7UL << 20)   /* Bit mask for GPIO_EXTIPSELL_EXTIPSEL5    */
#define GPIO_EXTIPSELL_EXTIPSEL5_DEFAULT        (0x0UL << 20)   /* Mode DEFAULT for GPIO_EXTIPSELL_EXTIPSEL5 */
#define GPIO_EXTIPSELL_EXTIPSEL5_PORTA          (0x0UL << 20)   /* Mode PORTA for GPIO_EXTIPSELL_EXTIPSEL5  */
#define GPIO_EXTIPSELL_EXTIPSEL5_PORTB          (0x1UL << 20)   /* Mode PORTB for GPIO_EXTIPSELL_EXTIPSEL5  */
#define GPIO_EXTIPSELL_EXTIPSEL5_PORTC          (0x2UL << 20)   /* Mode PORTC for GPIO_EXTIPSELL_EXTIPSEL5  */
#define GPIO_EXTIPSELL_EXTIPSEL5_PORTD          (0x3UL << 20)   /* Mode PORTD for GPIO_EXTIPSELL_EXTIPSEL5  */
#define GPIO_EXTIPSELL_EXTIPSEL5_PORTE          (0x4UL << 20)   /* Mode PORTE for GPIO_EXTIPSELL_EXTIPSEL5  */
#define GPIO_EXTIPSELL_EXTIPSEL5_PORTF          (0x6UL << 20)   /* Mode PORTF for GPIO_EXTIPSELL_EXTIPSEL5  */   
#define GPIO_EXTIPSELL_EXTIPSEL6_SHIFT          24              /* Shift value for GPIO_EXTIPSELL_EXTIPSEL6 */
#define GPIO_EXTIPSELL_EXTIPSEL6_MASK           (0x7UL << 24)   /* Bit mask for GPIO_EXTIPSELL_EXTIPSEL6    */
#define GPIO_EXTIPSELL_EXTIPSEL6_DEFAULT        (0x0UL << 24)   /* Mode DEFAULT for GPIO_EXTIPSELL_EXTIPSEL6 */
#define GPIO_EXTIPSELL_EXTIPSEL6_PORTA          (0x0UL << 24)   /* Mode PORTA for GPIO_EXTIPSELL_EXTIPSEL6  */
#define GPIO_EXTIPSELL_EXTIPSEL6_PORTB          (0x1UL << 24)   /* Mode PORTB for GPIO_EXTIPSELL_EXTIPSEL6  */
#define GPIO_EXTIPSELL_EXTIPSEL6_PORTC          (0x2UL << 24)   /* Mode PORTC for GPIO_EXTIPSELL_EXTIPSEL6  */
#define GPIO_EXTIPSELL_EXTIPSEL6_PORTD          (0x3UL << 24)   /* Mode PORTD for GPIO_EXTIPSELL_EXTIPSEL6  */
#define GPIO_EXTIPSELL_EXTIPSEL6_PORTE          (0x4UL << 24)   /* Mode PORTE for GPIO_EXTIPSELL_EXTIPSEL6  */
#define GPIO_EXTIPSELL_EXTIPSEL6_PORTF          (0x6UL << 24)   /* Mode PORTF for GPIO_EXTIPSELL_EXTIPSEL6  */ 
#define GPIO_EXTIPSELL_EXTIPSEL7_SHIFT          28              /* Shift value for GPIO_EXTIPSELL_EXTIPSEL7 */
#define GPIO_EXTIPSELL_EXTIPSEL7_MASK           (0x7UL << 28)   /* Bit mask for GPIO_EXTIPSELL_EXTIPSEL7    */
#define GPIO_EXTIPSELL_EXTIPSEL7_DEFAULT        (0x0UL << 28)   /* Mode DEFAULT for GPIO_EXTIPSELL_EXTIPSEL7 */
#define GPIO_EXTIPSELL_EXTIPSEL7_PORTA          (0x0UL << 28)   /* Mode PORTA for GPIO_EXTIPSELL_EXTIPSEL7  */
#define GPIO_EXTIPSELL_EXTIPSEL7_PORTB          (0x1UL << 28)   /* Mode PORTB for GPIO_EXTIPSELL_EXTIPSEL7  */
#define GPIO_EXTIPSELL_EXTIPSEL7_PORTC          (0x2UL << 28)   /* Mode PORTC for GPIO_EXTIPSELL_EXTIPSEL7  */
#define GPIO_EXTIPSELL_EXTIPSEL7_PORTD          (0x3UL << 28)   /* Mode PORTD for GPIO_EXTIPSELL_EXTIPSEL7  */
#define GPIO_EXTIPSELL_EXTIPSEL7_PORTE          (0x4UL << 28)   /* Mode PORTE for GPIO_EXTIPSELL_EXTIPSEL7  */
#define GPIO_EXTIPSELL_EXTIPSEL7_PORTF          (0x6UL << 28)   /* Mode PORTF for GPIO_EXTIPSELL_EXTIPSEL7  */

/* Bit fields for GPIO EXTIPSELH */
#define GPIO_EXTIPSELH_RESETVALUE               0x00000000UL    /* Default value for GPIO_EXTIPSELH         */
#define GPIO_EXTIPSELH_MASK                     0x77777777UL    /* Mask for GPIO_EXTIPSELH                  */
#define GPIO_EXTIPSELH_EXTIPSEL8_SHIFT          0               /* Shift value for GPIO_EXTIPSELH_EXTIPSEL8 */
#define GPIO_EXTIPSELH_EXTIPSEL8_MASK           (0x7UL << 0)    /* Bit mask for GPIO_EXTIPSELH_EXTIPSEL8    */
#define GPIO_EXTIPSELH_EXTIPSEL8_DEFAULT        (0x0UL << 0)    /* Mode DEFAULT for GPIO_EXTIPSELH_EXTIPSEL8 */
#define GPIO_EXTIPSELH_EXTIPSEL8_PORTA          (0x0UL << 0)    /* Mode PORTA for GPIO_EXTIPSELH_EXTIPSEL8  */
#define GPIO_EXTIPSELH_EXTIPSEL8_PORTB          (0x1UL << 0)    /* Mode PORTB for GPIO_EXTIPSELH_EXTIPSEL8  */
#define GPIO_EXTIPSELH_EXTIPSEL8_PORTC          (0x2UL << 0)    /* Mode PORTC for GPIO_EXTIPSELH_EXTIPSEL8  */
#define GPIO_EXTIPSELH_EXTIPSEL8_PORTD          (0x3UL << 0)    /* Mode PORTD for GPIO_EXTIPSELH_EXTIPSEL8  */
#define GPIO_EXTIPSELH_EXTIPSEL8_PORTE          (0x4UL << 0)    /* Mode PORTE for GPIO_EXTIPSELH_EXTIPSEL8  */
#define GPIO_EXTIPSELH_EXTIPSEL8_PORTF          (0x6UL << 0)    /* Mode PORTF for GPIO_EXTIPSELH_EXTIPSEL8  */  
#define GPIO_EXTIPSELH_EXTIPSEL9_SHIFT          4               /* Shift value for GPIO_EXTIPSELH_EXTIPSEL9 */
#define GPIO_EXTIPSELH_EXTIPSEL9_MASK           (0x7UL << 4)    /* Bit mask for GPIO_EXTIPSELH_EXTIPSEL9    */
#define GPIO_EXTIPSELH_EXTIPSEL9_DEFAULT        (0x0UL << 4)    /* Mode DEFAULT for GPIO_EXTIPSELH_EXTIPSEL9 */
#define GPIO_EXTIPSELH_EXTIPSEL9_PORTA          (0x0UL << 4)    /* Mode PORTA for GPIO_EXTIPSELH_EXTIPSEL9  */
#define GPIO_EXTIPSELH_EXTIPSEL9_PORTB          (0x1UL << 4)    /* Mode PORTB for GPIO_EXTIPSELH_EXTIPSEL9  */
#define GPIO_EXTIPSELH_EXTIPSEL9_PORTC          (0x2UL << 4)    /* Mode PORTC for GPIO_EXTIPSELH_EXTIPSEL9  */
#define GPIO_EXTIPSELH_EXTIPSEL9_PORTD          (0x3UL << 4)    /* Mode PORTD for GPIO_EXTIPSELH_EXTIPSEL9  */
#define GPIO_EXTIPSELH_EXTIPSEL9_PORTE          (0x4UL << 4)    /* Mode PORTE for GPIO_EXTIPSELH_EXTIPSEL9  */
#define GPIO_EXTIPSELH_EXTIPSEL9_PORTF          (0x6UL << 4)    /* Mode PORTF for GPIO_EXTIPSELH_EXTIPSEL9  */   
#define GPIO_EXTIPSELH_EXTIPSEL10_SHIFT          8               /* Shift value for GPIO_EXTIPSELH_EXTIPSEL10 */
#define GPIO_EXTIPSELH_EXTIPSEL10_MASK          (0x7UL << 8)    /* Bit mask for GPIO_EXTIPSELH_EXTIPSEL10   */
#define GPIO_EXTIPSELH_EXTIPSEL10_DEFAULT       (0x0UL << 8)    /* Mode DEFAULT for GPIO_EXTIPSELH_EXTIPSEL10 */
#define GPIO_EXTIPSELH_EXTIPSEL10_PORTA         (0x0UL << 8)    /* Mode PORTA for GPIO_EXTIPSELH_EXTIPSEL10 */
#define GPIO_EXTIPSELH_EXTIPSEL10_PORTB         (0x1UL << 8)    /* Mode PORTB for GPIO_EXTIPSELH_EXTIPSEL10 */
#define GPIO_EXTIPSELH_EXTIPSEL10_PORTC         (0x2UL << 8)    /* Mode PORTC for GPIO_EXTIPSELH_EXTIPSEL10 */
#define GPIO_EXTIPSELH_EXTIPSEL10_PORTD         (0x3UL << 8)    /* Mode PORTD for GPIO_EXTIPSELH_EXTIPSEL10 */
#define GPIO_EXTIPSELH_EXTIPSEL10_PORTE         (0x4UL << 8)    /* Mode PORTE for GPIO_EXTIPSELH_EXTIPSEL10 */
#define GPIO_EXTIPSELH_EXTIPSEL10_PORTF         (0x6UL << 8)    /* Mode PORTF for GPIO_EXTIPSELH_EXTIPSEL10 */
#define GPIO_EXTIPSELH_EXTIPSEL11_SHIFT         12              /* Shift value for GPIO_EXTIPSELH_EXTIPSEL11 */
#define GPIO_EXTIPSELH_EXTIPSEL11_MASK          (0x7UL << 12)   /* Bit mask for GPIO_EXTIPSELH_EXTIPSEL11   */
#define GPIO_EXTIPSELH_EXTIPSEL11_DEFAULT       (0x0UL << 12)   /* Mode DEFAULT for GPIO_EXTIPSELH_EXTIPSEL11 */
#define GPIO_EXTIPSELH_EXTIPSEL11_PORTA         (0x0UL << 12)   /* Mode PORTA for GPIO_EXTIPSELH_EXTIPSEL11 */
#define GPIO_EXTIPSELH_EXTIPSEL11_PORTB         (0x1UL << 12)   /* Mode PORTB for GPIO_EXTIPSELH_EXTIPSEL11 */
#define GPIO_EXTIPSELH_EXTIPSEL11_PORTC         (0x2UL << 12)   /* Mode PORTC for GPIO_EXTIPSELH_EXTIPSEL11 */
#define GPIO_EXTIPSELH_EXTIPSEL11_PORTD         (0x3UL << 12)   /* Mode PORTD for GPIO_EXTIPSELH_EXTIPSEL11 */
#define GPIO_EXTIPSELH_EXTIPSEL11_PORTE         (0x4UL << 12)   /* Mode PORTE for GPIO_EXTIPSELH_EXTIPSEL11 */
#define GPIO_EXTIPSELH_EXTIPSEL11_PORTF         (0x6UL << 12)   /* Mode PORTF for GPIO_EXTIPSELH_EXTIPSEL11 */   
#define GPIO_EXTIPSELH_EXTIPSEL12_SHIFT         16              /* Shift value for GPIO_EXTIPSELH_EXTIPSEL12 */
#define GPIO_EXTIPSELH_EXTIPSEL12_MASK          (0x7UL << 16)   /* Bit mask for GPIO_EXTIPSELH_EXTIPSEL12   */
#define GPIO_EXTIPSELH_EXTIPSEL12_DEFAULT       (0x0UL << 16)   /* Mode DEFAULT for GPIO_EXTIPSELH_EXTIPSEL12 */
#define GPIO_EXTIPSELH_EXTIPSEL12_PORTA         (0x0UL << 16)   /* Mode PORTA for GPIO_EXTIPSELH_EXTIPSEL12 */
#define GPIO_EXTIPSELH_EXTIPSEL12_PORTB         (0x1UL << 16)   /* Mode PORTB for GPIO_EXTIPSELH_EXTIPSEL12 */
#define GPIO_EXTIPSELH_EXTIPSEL12_PORTC         (0x2UL << 16)   /* Mode PORTC for GPIO_EXTIPSELH_EXTIPSEL12 */
#define GPIO_EXTIPSELH_EXTIPSEL12_PORTD         (0x3UL << 16)   /* Mode PORTD for GPIO_EXTIPSELH_EXTIPSEL12 */
#define GPIO_EXTIPSELH_EXTIPSEL12_PORTE         (0x4UL << 16)   /* Mode PORTE for GPIO_EXTIPSELH_EXTIPSEL12 */
#define GPIO_EXTIPSELH_EXTIPSEL12_PORTF         (0x6UL << 16)   /* Mode PORTF for GPIO_EXTIPSELH_EXTIPSEL12 */ 
#define GPIO_EXTIPSELH_EXTIPSEL13_SHIFT         20              /* Shift value for GPIO_EXTIPSELH_EXTIPSEL13 */
#define GPIO_EXTIPSELH_EXTIPSEL13_MASK          (0x7UL << 20)   /* Bit mask for GPIO_EXTIPSELH_EXTIPSEL13   */
#define GPIO_EXTIPSELH_EXTIPSEL13_DEFAULT       (0x0UL << 20)   /* Mode DEFAULT for GPIO_EXTIPSELH_EXTIPSEL13 */
#define GPIO_EXTIPSELH_EXTIPSEL13_PORTA         (0x0UL << 20)   /* Mode PORTA for GPIO_EXTIPSELH_EXTIPSEL13 */
#define GPIO_EXTIPSELH_EXTIPSEL13_PORTB         (0x1UL << 20)   /* Mode PORTB for GPIO_EXTIPSELH_EXTIPSEL13 */
#define GPIO_EXTIPSELH_EXTIPSEL13_PORTC         (0x2UL << 20)   /* Mode PORTC for GPIO_EXTIPSELH_EXTIPSEL13 */
#define GPIO_EXTIPSELH_EXTIPSEL13_PORTD         (0x3UL << 20)   /* Mode PORTD for GPIO_EXTIPSELH_EXTIPSEL13 */
#define GPIO_EXTIPSELH_EXTIPSEL13_PORTE         (0x4UL << 20)   /* Mode PORTE for GPIO_EXTIPSELH_EXTIPSEL13 */
#define GPIO_EXTIPSELH_EXTIPSEL13_PORTF         (0x6UL << 20)   /* Mode PORTF for GPIO_EXTIPSELH_EXTIPSEL13 */   
#define GPIO_EXTIPSELH_EXTIPSEL14_SHIFT         24              /* Shift value for GPIO_EXTIPSELH_EXTIPSEL14 */
#define GPIO_EXTIPSELH_EXTIPSEL14_MASK          (0x7UL << 24)   /* Bit mask for GPIO_EXTIPSELH_EXTIPSEL14   */
#define GPIO_EXTIPSELH_EXTIPSEL14_DEFAULT       (0x0UL << 24)   /* Mode DEFAULT for GPIO_EXTIPSELH_EXTIPSEL14 */
#define GPIO_EXTIPSELH_EXTIPSEL14_PORTA         (0x0UL << 24)   /* Mode PORTA for GPIO_EXTIPSELH_EXTIPSEL14 */
#define GPIO_EXTIPSELH_EXTIPSEL14_PORTB         (0x1UL << 24)   /* Mode PORTB for GPIO_EXTIPSELH_EXTIPSEL14 */
#define GPIO_EXTIPSELH_EXTIPSEL14_PORTC         (0x2UL << 24)   /* Mode PORTC for GPIO_EXTIPSELH_EXTIPSEL14 */
#define GPIO_EXTIPSELH_EXTIPSEL14_PORTD         (0x3UL << 24)   /* Mode PORTD for GPIO_EXTIPSELH_EXTIPSEL14 */
#define GPIO_EXTIPSELH_EXTIPSEL14_PORTE         (0x4UL << 24)   /* Mode PORTE for GPIO_EXTIPSELH_EXTIPSEL14 */
#define GPIO_EXTIPSELH_EXTIPSEL14_PORTF         (0x6UL << 24)   /* Mode PORTF for GPIO_EXTIPSELH_EXTIPSEL14 */ 
#define GPIO_EXTIPSELH_EXTIPSEL15_SHIFT         28              /* Shift value for GPIO_EXTIPSELH_EXTIPSEL15 */
#define GPIO_EXTIPSELH_EXTIPSEL15_MASK          (0x7UL << 28)   /* Bit mask for GPIO_EXTIPSELH_EXTIPSEL15   */
#define GPIO_EXTIPSELH_EXTIPSEL15_DEFAULT       (0x0UL << 28)   /* Mode DEFAULT for GPIO_EXTIPSELH_EXTIPSEL15 */
#define GPIO_EXTIPSELH_EXTIPSEL15_PORTA         (0x0UL << 28)   /* Mode PORTA for GPIO_EXTIPSELH_EXTIPSEL15 */
#define GPIO_EXTIPSELH_EXTIPSEL15_PORTB         (0x1UL << 28)   /* Mode PORTB for GPIO_EXTIPSELH_EXTIPSEL15 */
#define GPIO_EXTIPSELH_EXTIPSEL15_PORTC         (0x2UL << 28)   /* Mode PORTC for GPIO_EXTIPSELH_EXTIPSEL15 */
#define GPIO_EXTIPSELH_EXTIPSEL15_PORTD         (0x3UL << 28)   /* Mode PORTD for GPIO_EXTIPSELH_EXTIPSEL15 */
#define GPIO_EXTIPSELH_EXTIPSEL15_PORTE         (0x4UL << 28)   /* Mode PORTE for GPIO_EXTIPSELH_EXTIPSEL15 */
#define GPIO_EXTIPSELH_EXTIPSEL15_PORTF         (0x6UL << 28)   /* Mode PORTF for GPIO_EXTIPSELH_EXTIPSEL15 */
    
/* Bit fields for GPIO EXTIRISE */
#define GPIO_EXTIRISE_RESETVALUE                0x00000000UL    /* Default value for GPIO_EXTIRISE          */
#define GPIO_EXTIRISE_MASK                      0x0000FFFFUL    /* Mask for GPIO_EXTIRISE                   */
#define GPIO_EXTIRISE_EXTIRISE_SHIFT            0               /* Shift value for GPIO_EXTIRISE_EXTIRISE   */
#define GPIO_EXTIRISE_EXTIRISE_MASK             0xFFFFUL        /* Bit mask for GPIO_EXTIRISE_EXTIRISE      */
#define GPIO_EXTIRISE_EXTIRISE_DEFAULT          (0x0UL << 0)    /* Mode DEFAULT for GPIO_EXTIRISE_EXTIRISE  */

/* Bit fields for GPIO EXTIFALL */
#define GPIO_EXTIFALL_RESETVALUE                0x00000000UL    /* Default value for GPIO_EXTIFALL          */
#define GPIO_EXTIFALL_MASK                      0x0000FFFFUL    /* Mask for GPIO_EXTIFALL                   */
#define GPIO_EXTIFALL_EXTIFALL_SHIFT            0               /* Shift value for GPIO_EXTIFALL_EXTIFALL   */
#define GPIO_EXTIFALL_EXTIFALL_MASK             0xFFFFUL        /* Bit mask for GPIO_EXTIFALL_EXTIFALL      */
#define GPIO_EXTIFALL_EXTIFALL_DEFAULT          (0x0UL << 0)    /* Mode DEFAULT for GPIO_EXTIFALL_EXTIFALL  */

/* Bit fields for GPIO IEN */
#define GPIO_IEN_RESETVALUE                     0x00000000UL    /* Default value for GPIO_IEN               */
#define GPIO_IEN_MASK                           0x0000FFFFUL    /* Mask for GPIO_IEN                        */
#define GPIO_IEN_EXT_SHIFT                      0               /* Shift value for GPIO_IEN_EXT             */
#define GPIO_IEN_EXT_MASK                       0xFFFFUL        /* Bit mask for GPIO_IEN_EXT                */
#define GPIO_IEN_EXT_DEFAULT                    (0x0UL << 0)    /* Mode DEFAULT for GPIO_IEN_IEN            */

/* Bit fields for GPIO IF */
#define GPIO_IF_RESETVALUE                      0x00000000UL    /* Default value for GPIO_IF                */
#define GPIO_IF_MASK                            0x0000FFFFUL    /* Mask for GPIO_IF                         */
#define GPIO_IF_EXT_SHIFT                       0               /* Shift value for GPIO_IF_EXT              */
#define GPIO_IF_EXT_MASK                        0xFFFFUL        /* Bit mask for GPIO_IF_EXT                 */
#define GPIO_IF_EXT_DEFAULT                     (0x0UL << 0)    /* Mode DEFAULT for GPIO_IF_EXT             */

/* Bit fields for GPIO IFS */
#define GPIO_IFS_RESETVALUE                     0x00000000UL    /* Default value for GPIO_IFS               */
#define GPIO_IFS_MASK                           0x0000FFFFUL    /* Mask for GPIO_IFS                        */
#define GPIO_IFS_EXT_SHIFT                      0               /* Shift value for GPIO_IFS_EXT             */
#define GPIO_IFS_EXT_MASK                       0xFFFFUL        /* Bit mask for GPIO_IFS_EXT                */
#define GPIO_IFS_EXT_DEFAULT                    (0x0UL << 0)    /* Mode DEFAULT for GPIO_IFS_EXT            */

/* Bit fields for GPIO IFC */
#define GPIO_IFC_RESETVALUE                     0x00000000UL    /* Default value for GPIO_IFC               */
#define GPIO_IFC_MASK                           0x0000FFFFUL    /* Mask for GPIO_IFC                        */
#define GPIO_IFC_EXT_SHIFT                      0               /* Shift value for GPIO_IFC_EXT             */
#define GPIO_IFC_EXT_MASK                       0xFFFFUL        /* Bit mask for GPIO_IFC_EXT                */
#define GPIO_IFC_EXT_DEFAULT                    (0x0UL << 0)    /* Mode DEFAULT for GPIO_IFC_EXT            */

/* Bit fields for GPIO ROUTE */
#define GPIO_ROUTE_RESETVALUE                   0x00000003UL    /* Default value for GPIO_ROUTE             */
#define GPIO_ROUTE_MASK                         0x00000307UL    /* Mask for GPIO_ROUTE                      */
#define GPIO_ROUTE_SWCLKPEN_SHIFT               0               /* Shift value for GPIO_ROUTE_SWCLKPEN      */
#define GPIO_ROUTE_SWCLKPEN_MASK                (0x1UL << 0)    /* Bit mask for GPIO_ROUTE_SWCLKPEN         */
#define GPIO_ROUTE_SWCLKPEN_DEFAULT             (0x1UL << 0)    /* Mode DEFAULT for GPIO_ROUTE_SWCLKPEN     */
#define GPIO_ROUTE_SWCLKPEN                     (0x1UL << 0)    /* Serial Wire Clock Pin Enable             */
#define GPIO_ROUTE_SWDIOPEN_SHIFT               1               /* Shift value for GPIO_ROUTE_SWDIOPEN      */
#define GPIO_ROUTE_SWDIOPEN_MASK                (0x1UL << 1)    /* Bit mask for GPIO_SWDIOPEN               */
#define GPIO_ROUTE_SWDIOPEN_DEFAULT             (0x1UL << 1)    /* Mode DEFAULT for GPIO_ROUTE_SWDIOPEN     */
#define GPIO_ROUTE_SWDIOPEN                     (0x1UL << 1)    /* Serial Wire Data Pin Enable              */
#define GPIO_ROUTE_SWOPEN_SHIFT                 2               /* Shift value for GPIO_ROUTE_SWOPEN        */
#define GPIO_ROUTE_SWOPEN_MASK                  (0x1UL << 2)    /* Bit mask for GPIO_SWOPEN                 */
#define GPIO_ROUTE_SWOPEN_DEFAULT               (0x0UL << 2)    /* Mode DEFAULT for GPIO_ROUTE_SWOPEN       */
#define GPIO_ROUTE_SWOPEN                       (0x1UL << 2)    /* Serial Wire Viewer Output Pin Enable     */
#define GPIO_ROUTE_SWLOCATION_SHIFT             8               /* Shift value for GPIO_ROUTE_SWLOCATION    */
#define GPIO_ROUTE_SWLOCATION_MASK              (0x3UL << 8)    /* Bit mask for GPIO_SWLOCATION             */
#define GPIO_ROUTE_SWLOCATION_DEFAULT           (0x3UL << 8)    /* Mode DEFAULT for GPIO_ROUTE              */
#define GPIO_ROUTE_SWLOCATION_LOC0              (0x0UL << 8)    /* Mode LOC0 for GPIO_ROUTE_SWLOCATION      */
#define GPIO_ROUTE_SWLOCATION_LOC1              (0x1UL << 8)    /* Mode LOC1 for GPIO_ROUTE_SWLOCATION      */
#define GPIO_ROUTE_SWLOCATION_LOC2              (0x2UL << 8)    /* Mode LOC2 for GPIO_ROUTE_SWLOCATION      */
#define GPIO_ROUTE_SWLOCATION_LOC3              (0x3UL << 8)    /* Mode LOC3 for GPIO_ROUTE_SWLOCATION      */


/* Bit fields for GPIO INSENSE */
#define GPIO_INSENSE_RESETVALUE                 0x00000003UL    /* Default value for GPIO_INSENSE           */
#define GPIO_INSENSE_MASK                       0x00000003UL    /* Mask for GPIO_INSENSE                    */
#define GPIO_INSENSE_INT_SHIFT                  0               /* Shift value for GPIO_INSENSE_INT         */
#define GPIO_INSENSE_INT_MASK                   (0x1UL << 0)    /* Bit mask for GPIO_INSENSE_INT            */
#define GPIO_INSENSE_INT_DEFAULT                (0x1UL << 0)    /* Mode DEFAULT for GPIO_INSENSE_INT        */
#define GPIO_INSENSE_INT                        (0x1UL << 0)    /* Interrupt Sense Enable                   */
#define GPIO_INSENSE_PRS_SHIFT                  1               /* Shift value for GPIO_INSENSE_PRS         */
#define GPIO_INSENSE_PRS_MASK                   (0x1UL << 1)    /* Bit mask for GPIO_INSENSE_PRS            */
#define GPIO_INSENSE_PRS_DEFAULT                (0x1UL << 1)    /* Mode DEFAULT for GPIO_INSENSE_PRS        */
#define GPIO_INSENSE_PRS                        (0x1UL << 1)    /* PRS Sense Enable                         */

/* Bit fields for GPIO LOCK */
#define GPIO_LOCK_RESETVALUE                    0x00000000UL    /* Default value for GPIO_LOCK              */
#define GPIO_LOCK_MASK                          0x0000FFFFUL    /* Mask for GPIO_LOCK                       */
#define GPIO_LOCK_LOCKKEY_SHIFT                 0               /* Shift value for GPIO_LOCK_LOCKKEY        */
#define GPIO_LOCK_LOCKKEY_MASK                  0xFFFFUL        /* Bit mask for GPIO_LOCK_LOCKKEY           */
#define GPIO_LOCK_LOCKKEY_DEFAULT               0x0000UL        /* Mode DEFAULT for GPIO_LOCK_LOCKKEY       */
#define GPIO_LOCK_LOCKKEY_LOCK                  0x0000UL        /* Mode LOCK for GPIO_LOCK_LOCKKEY          */
#define GPIO_LOCK_LOCKKEY_UNLOCKED              0x0000UL        /* Mode UNLOCKED for GPIO_LOCK_LOCKKEY      */
#define GPIO_LOCK_LOCKKEY_LOCKED                0x0001UL        /* Mode LOCKED for GPIO_LOCK_LOCKKEY        */
#define GPIO_LOCK_LOCKKEY_UNLOCK                0xA534UL        /* Mode UNLOCK for GPIO_LOCK_LOCKKEY        */

#define GPIO_PIN_NUM                            16u   
#define GPIO_ODD_PIN_MASK                       0xAAAAUL
#define GPIO_EVEN_PIN_MASK                      0x5555UL

      
/*************************************************************************************************************
*                                                  DATA TYPES                                                *
*************************************************************************************************************/
typedef enum
{
    GPIO_PORTA = 0, /* GPIO Port A                                                                          */
    GPIO_PORTB = 1, /* GPIO Port B                                                                          */
    GPIO_PORTC = 2, /* GPIO Port C                                                                          */
    GPIO_PORTD = 3, /* GPIO Port D                                                                          */
    GPIO_PORTE = 4, /* GPIO Port E                                                                          */
    GPIO_PORTF = 5, /* GPIO Port F                                                                          */
} GPIOPortTypeDef;

typedef enum
{
    GPIO_PIN_0  = DEF_BIT0,     /* GPIO pin 0                                                               */
    GPIO_PIN_1  = DEF_BIT1,     /* GPIO pin 1                                                               */                       
    GPIO_PIN_2  = DEF_BIT2,     /* GPIO pin 2                                                               */ 
    GPIO_PIN_3  = DEF_BIT3,     /* GPIO pin 3                                                               */    
    GPIO_PIN_4  = DEF_BIT4,     /* GPIO pin 4                                                               */            
    GPIO_PIN_5  = DEF_BIT5,     /* GPIO pin 5                                                               */         
    GPIO_PIN_6  = DEF_BIT6,     /* GPIO pin 6                                                               */              
    GPIO_PIN_7  = DEF_BIT7,     /* GPIO pin 7                                                               */                 
    GPIO_PIN_8  = DEF_BIT8,     /* GPIO pin 8                                                               */                  
    GPIO_PIN_9  = DEF_BIT9,     /* GPIO pin 9                                                               */                   
    GPIO_PIN_10 = DEF_BIT10,    /* GPIO pin 10                                                              */                     
    GPIO_PIN_11 = DEF_BIT11,    /* GPIO pin 11                                                              */            
    GPIO_PIN_12 = DEF_BIT12,    /* GPIO pin 12                                                              */             
    GPIO_PIN_13 = DEF_BIT13,    /* GPIO pin 13                                                              */         
    GPIO_PIN_14 = DEF_BIT14,    /* GPIO pin 14                                                              */        
    GPIO_PIN_15 = DEF_BIT15,    /* GPIO pin 15                                                              */
} GPIOPinTypeDef;

typedef enum
{
    GPIO_DRIVE_STANDARD = GPIO_CTRL_DRIVEMODE_STANDARD, /* 6 mA Drive Current                               */
    GPIO_DRIVE_LOWEST   = GPIO_CTRL_DRIVEMODE_LOWEST,   /* 0.5 mA Drive Current                             */
    GPIO_DRIVE_HIGH     = GPIO_CTRL_DRIVEMODE_HIGH,     /* 20 mA Drive Current                              */
    GPIO_DRIVE_LOW      = GPIO_CTRL_DRIVEMODE_LOW,      /* 2 mA Drive Current                               */
} GPIODriveTypeDef;

typedef enum
{
    GPIO_MODE_DISABLED                  =  GPIO_MODEL_0_DISABLED,                   /* Input disabled. Pullup 
                                                                                       if DOUT is set.      */
    GPIO_MODE_INPUT                     =  GPIO_MODEL_0_INPUT,                      /* Input enabled. Filter 
                                                                                       if DOUT is set.      */
    GPIO_MODE_INPUTPULL                 =  GPIO_MODEL_0_INPUTPULL,                  /* Input enabled. OUT 
                                                                                       determines pull direction. */
    GPIO_MODE_INPUTPULLFILTER           =  GPIO_MODEL_0_INPUTPULLFILTER,            /* Input enabled with filter. 
                                                                                       DOUT determines pull 
                                                                                       direction.           */
    GPIO_MODE_PUSHPULL                  =  GPIO_MODEL_0_PUSHPULL,                   /* Push-pull output.    */
    GPIO_MODE_PUSHPULLDRIVE             =  GPIO_MODEL_0_PUSHPULLDRIVE,              /* Push-pull output with 
                                                                                       drive-strength set by 
                                                                                       DRIVEMODE.           */
    GPIO_MODE_WIREDOR                   =  GPIO_MODEL_0_WIREDOR,                    /* Wired-or output.     */
    GPIO_MODE_WIREDORPULLDOWN           =  GPIO_MODEL_0_WIREDORPULLDOWN,            /* Wired-or output with 
                                                                                       pull-down.           */
    GPIO_MODE_WIREDAND                  =  GPIO_MODEL_0_WIREDAND,                   /* Open-drain output.   */
    GPIO_MODE_WIREDANDFILTER            =  GPIO_MODEL_0_WIREDANDFILTER,             /* Open-drain output with 
                                                                                       filter.              */
    GPIO_MODE_WIREDANDPULLUP            =  GPIO_MODEL_0_WIREDANDPULLUP,             /* Open-drain output with 
                                                                                       pullup.              */
    GPIO_MODE_WIREDANDPULLUPFILTER      =  GPIO_MODEL_0_WIREDANDPULLUPFILTER,       /* Open-drain output with 
                                                                                       filter and pullup.   */  
    GPIO_MODE_WIREDANDDRIVE             =  GPIO_MODEL_0_WIREDANDDRIVE,              /* Open-drain output with 
                                                                                       drive-strength set by 
                                                                                       DRIVEMODE.           */
    GPIO_MODE_WIREDANDDRIVEFILTER       =  GPIO_MODEL_0_WIREDANDDRIVEFILTER,        /* Open-drain output with 
                                                                                       filter and drive-strength 
                                                                                       set by DRIVEMODE.    */
    GPIO_MODE_WIREDANDDRIVEPULLUP       =  GPIO_MODEL_0_WIREDANDDRIVEPULLUP,        /* Open-drain output with 
                                                                                       pullup and drive-strength 
                                                                                       set by DRIVEMODE.    */
    GPIO_MODE_WIREDANDDRIVEPULLUPFILTER =  GPIO_MODEL_0_WIREDANDDRIVEPULLUPFILTER,  /* Open-drain output with 
                                                                                       filter, pullup and 
                                                                                       drive-strength set by 
                                                                                       DRIVEMODE.           */
} GPIOModeTypeDef;

typedef enum
{
    GPIO_DEBUG_LOC0 = GPIO_ROUTE_SWLOCATION_LOC0,
    GPIO_DEBUG_LOC1 = GPIO_ROUTE_SWLOCATION_LOC1,
    GPIO_DEBUG_LOC2 = GPIO_ROUTE_SWLOCATION_LOC2,
    GPIO_DEBUG_LOC3 = GPIO_ROUTE_SWLOCATION_LOC3,
} GPIODebugLocationTypeDef;

typedef enum
{
    GPIO_FALLING_EDGE,  /* Interrupt on falling edge                                                        */
    GPIO_RISING_EDGE,   /* Interrupt on rising edge                                                         */
    GPIO_BOTH_EDGES,    /* Interrupt on both edges                                                          */
} GPIOIntTypeDef;


/*************************************************************************************************************
*                                            FUNCTION PROTOTYPES                                             *
*************************************************************************************************************/
static inline void GPIOPinOutSet (GPIOPortTypeDef port, GPIOPinTypeDef pin)
{
    GPIO->PORT[port].DOUTSET = pin;
}

static inline void GPIOPinOutClear (GPIOPortTypeDef port, GPIOPinTypeDef pin)
{
    GPIO->PORT[port].DOUTCLR = pin;
}

static inline void GPIOPinOutToggle (GPIOPortTypeDef port, GPIOPinTypeDef pin)
{
    GPIO->PORT[port].DOUTTGL = pin;
}

static inline CPU_BOOL GPIOPinOutGet (GPIOPortTypeDef port, GPIOPinTypeDef pin)
{
    if (GPIO->PORT[port].DOUT & pin)
    {
        return DEF_ON;
    }
    else
    {
        return DEF_OFF;
    }
}

static inline CPU_BOOL GPIOPinInGet (GPIOPortTypeDef port, GPIOPinTypeDef pin)
{
    if (GPIO->PORT[port].DIN & pin)
    {
        return DEF_ON;
    }
    else
    {
        return DEF_OFF;
    }
}

static inline void GPIOPinOutWrite (GPIOPortTypeDef port, CPU_INT16U data)
{
    GPIO->PORT[port].DOUT = data;
}

static inline CPU_INT16U GPIOPinOutRead (GPIOPortTypeDef port)
{
    return GPIO->PORT[port].DOUT;
}

static inline CPU_INT16U GPIOPinInRead (GPIOPortTypeDef port)
{ 
    return GPIO->PORT[port].DIN;
}

static inline void GPIOPinLock(GPIOPortTypeDef port, GPIOPinTypeDef pin)
{
    GPIO->PORT[port].PINLOCKN &= ~pin;
}

static inline void GPIODebugSWDClkEnable (void)
{
    GPIO->ROUTE |= GPIO_ROUTE_SWCLKPEN;
}

static inline void GPIODebugSWDClkDisable (void)
{
    GPIO->ROUTE &= ~GPIO_ROUTE_SWCLKPEN;
}

static inline void GPIODebugSWDIOEnable (void)
{
    GPIO->ROUTE |= GPIO_ROUTE_SWDIOPEN;
}

static inline void GPIODebugSWDIODisable (void)
{
    GPIO->ROUTE &= ~GPIO_ROUTE_SWDIOPEN;
}

static inline void GPIODebugSWOEnable (void)
{
    GPIO->ROUTE |= GPIO_ROUTE_SWOPEN;
}

static inline void GPIODebugSWODisable (void)
{
    GPIO->ROUTE &= ~GPIO_ROUTE_SWOPEN;
}

static inline void GPIOInputSenseINTEnable (void)
{
    GPIO->INSENSE |= GPIO_INSENSE_INT;
}

static inline void GPIOInputSenseINTDisable (void)
{
    GPIO->INSENSE &= ~GPIO_INSENSE_INT;
}

static inline void GPIOInputSensePRSEnable (void)
{
    GPIO->INSENSE |= GPIO_INSENSE_PRS;
}

static inline void GPIOInputSensePRSDisable (void)
{
    GPIO->INSENSE &= ~GPIO_INSENSE_PRS;
}

static inline void GPIOLock(void)
{
    GPIO->LOCK = GPIO_LOCK_LOCKKEY_LOCK;
}

static inline void GPIOUnlock(void)
{
    GPIO->LOCK = GPIO_LOCK_LOCKKEY_UNLOCK;
}

static inline void GPIOIntEnable (CPU_INT32U flag)
{
    GPIO->IEN |= flag;
}

static inline void GPIOIntDisable (CPU_INT32U flag)
{
    GPIO->IEN &= ~flag;
}

static inline CPU_INT32U GPIOIntGet (void)
{
    return GPIO->IF;
}

static inline CPU_BOOL GPIOIntFlagGet (GPIOPinTypeDef pin)
{
    if (GPIO->IF & pin)
    {
        return DEF_ON;
    }
    else
    {
        return DEF_OFF;
    }
}

static inline void GPIOIntSet (CPU_INT32U flag)
{
    GPIO->IFS = flag;
}

static inline void GPIOIntClear (CPU_INT32U flag)
{
    GPIO->IFC = flag;
}

static inline CPU_INT32U GPIOIntStatusGet (void)
{
    return GPIO->IEN;
}

static inline CPU_INT32U GPIOIntEnabledGet (void)
{
    CPU_INT32U en;

    en = 0;
    en = GPIO->IEN;

    /* Bitwise AND of pending and enabled interrupts */
    return GPIO->IF & en;
}


/*************************************************************************************************************
*                                            FUNCTION STATEMENT                                              *
*************************************************************************************************************/
void GPIOClockEnable (void);
void GPIOClockDisable (void);
void GPIOModeSet (GPIOPortTypeDef port, GPIOPinTypeDef pin, GPIOModeTypeDef mode);
void GPIODriveSet (GPIOPortTypeDef port, GPIODriveTypeDef drive);
void GPIODebugLocationSet (GPIODebugLocationTypeDef location);
void GPIOIntConfig(GPIOPortTypeDef port, GPIOPinTypeDef pin, GPIOIntTypeDef type);
    

/*************************************************************************************************************
*                                               MODULE END                                                   *
*************************************************************************************************************/   
#ifdef __cplusplus
}
#endif

#endif