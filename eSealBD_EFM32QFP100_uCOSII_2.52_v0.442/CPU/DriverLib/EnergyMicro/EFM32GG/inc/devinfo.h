/*************************************************************************************************************
*                                                  MODULE                                                    *
*************************************************************************************************************/
#ifndef DEVINFO_H
#define DEVINFO_H

#ifdef __cplusplus
extern "C" {
#endif
  
    
/*************************************************************************************************************
*                                              INCLUDE FILES                                                 *
*************************************************************************************************************/
#include <cmu.h>
    
    
/*************************************************************************************************************
*                                                 DEFINES                                                    *
*************************************************************************************************************/
#define DEVINFO                                 ((DEVINFORegTypeDef *)DEVINFO_BASE)  
    
/* Bit fields for DEVINFO CAL */
#define DEVINFO_CAL_CRC_SHIFT                   0               /* Integrity CRC checksum shift             */    
#define DEVINFO_CAL_CRC_MASK                    (0xFFFFUL << 0) /* Integrity CRC checksum mask              */
#define DEVINFO_CAL_TEMP_SHIFT                  16              /* Calibration temperature shift            */
#define DEVINFO_CAL_TEMP_MASK                   (0xFFUL   << 16)/* Calibration temperature, DegC, mask      */
    
/* Bit fields for DEVINFO ADC0CAL0 */
#define DEVINFO_ADC0CAL0_1V25_OFFSET_SHIFT      0               /* Offset for 1V25 reference, shift         */
#define DEVINFO_ADC0CAL0_1V25_OFFSET_MASK       (0x7FUL << 0)   /* Offset for 1V25 reference, mask          */
#define DEVINFO_ADC0CAL0_1V25_GAIN_SHIFT        8               /* Gain for 1V25 reference, shift           */ 
#define DEVINFO_ADC0CAL0_1V25_GAIN_MASK         (0x7FUL << 8)   /* Gain for 1V25 reference, mask            */
#define DEVINFO_ADC0CAL0_2V5_OFFSET_SHIFT       16              /* Offset for 2V5 reference, shift          */
#define DEVINFO_ADC0CAL0_2V5_OFFSET_MASK        (0x7FUL << 16)  /* Offset for 2V5 reference, mask           */
#define DEVINFO_ADC0CAL0_2V5_GAIN_SHIFT         24              /* Gain for 2V5 reference, shift            */
#define DEVINFO_ADC0CAL0_2V5_GAIN_MASK          (0x7FUL << 24)  /* Gain for 2V5 reference, mask             */

/* Bit fields for DEVINFO ADC0CAL1 */
#define DEVINFO_ADC0CAL1_VDD_OFFSET_SHIFT       0               /* Offset for VDD reference, shift          */    
#define DEVINFO_ADC0CAL1_VDD_OFFSET_MASK        (0x7FUL << 0)   /* Offset for VDD reference, mask           */
#define DEVINFO_ADC0CAL1_VDD_GAIN_SHIFT         8               /* Gain for VDD reference, shift            */    
#define DEVINFO_ADC0CAL1_VDD_GAIN_MASK          (0x7FUL << 8)   /* Gain for VDD reference, mask             */
#define DEVINFO_ADC0CAL1_5VDIFF_OFFSET_SHIFT    16              /* Offset for 5VDIFF reference, shift       */
#define DEVINFO_ADC0CAL1_5VDIFF_OFFSET_MASK     (0x7FUL << 16)  /* Offset for 5VDIFF reference, mask        */
#define DEVINFO_ADC0CAL1_5VDIFF_GAIN_SHIFT      24              /* Gain for 5VDIFF reference, mask          */    
#define DEVINFO_ADC0CAL1_5VDIFF_GAIN_MASK       (0x7FUL << 24)  /* Gain 5VDIFF for 5VDIFF reference, mask   */

/* Bit fields for DEVINFO ADC0CAL2 */
#define DEVINFO_ADC0CAL2_2XVDDVSS_OFFSET_SHIFT  0               /* Offset for 2XVDDVSS reference, shift     */
#define DEVINFO_ADC0CAL2_2XVDDVSS_OFFSET_MASK   (0x7FUL  << 0)  /* Offset for 2XVDDVSS reference, mask      */
#define DEVINFO_ADC0CAL2_TEMP1V25_SHIFT         20              /* Temperature reading at 1V25 reference, DegC */
#define DEVINFO_ADC0CAL2_TEMP1V25_MASK          (0xFFFUL << 20) /* Temperature reading at 1V25 reference, mask */

/* Bit fields for DEVINFO DAC0CAL0 */
#define DEVINFO_DAC0CAL0_1V25_CH0_OFFSET_SHIFT  0               /* Channel 0 offset for 1V25 reference, shift */
#define DEVINFO_DAC0CAL0_1V25_CH0_OFFSET_MASK   (0x3FUL << 0)   /* Channel 0 offset for 1V25 reference, mask */
#define DEVINFO_DAC0CAL0_1V25_CH1_OFFSET_SHIFT  8               /* Channel 1 offset for 1V25 reference, shift */
#define DEVINFO_DAC0CAL0_1V25_CH1_OFFSET_MASK   (0x3FUL << 8)   /* Channel 1 offset for 1V25 reference, mask */
#define DEVINFO_DAC0CAL0_1V25_GAIN_SHIFT        16              /* Gain for 1V25 reference, shift           */
#define DEVINFO_DAC0CAL0_1V25_GAIN_MASK         (0x7FUL << 16)  /* Gain for 1V25 reference, mask            */

/* Bit fields for DEVINFO DAC0CAL1 */
#define DEVINFO_DAC0CAL1_2V5_CH0_OFFSET_SHIFT   0               /* Channel 0 offset for 2V5 reference, shift */
#define DEVINFO_DAC0CAL1_2V5_CH0_OFFSET_MASK    (0x3FUL << 0)   /* Channel 0 offset for 2V5 reference, mask */
#define DEVINFO_DAC0CAL1_2V5_CH1_OFFSET_SHIFT   8               /* Channel 1 offset for 2V5 reference, shift */
#define DEVINFO_DAC0CAL1_2V5_CH1_OFFSET_MASK    (0x3FUL << 8)   /* Channel 1 offset for 2V5 reference, mask */
#define DEVINFO_DAC0CAL1_2V5_GAIN_SHIFT         16              /* Gain for 2V5 reference, shift            */    
#define DEVINFO_DAC0CAL1_2V5_GAIN_MASK          (0x7FUL << 16)  /* Gain for 2V5 reference, mask             */

/* Bit fields for DEVINFO DAC0CAL2 */
#define DEVINFO_DAC0CAL2_VDD_CH0_OFFSET_SHIFT   0               /* Channel 0 offset for VDD reference, shift*/
#define DEVINFO_DAC0CAL2_VDD_CH0_OFFSET_MASK    (0x3FUL << 0)   /* Channel 0 offset for VDD reference, mask */
#define DEVINFO_DAC0CAL2_VDD_CH1_OFFSET_SHIFT   8               /* Channel 1 offset for VDD reference, shift */
#define DEVINFO_DAC0CAL2_VDD_CH1_OFFSET_MASK    (0x3FUL << 8)   /* Channel 1 offset for VDD reference, mask */
#define DEVINFO_DAC0CAL2_VDD_GAIN_SHIFT         16              /* Gain for VDD reference, shift            */    
#define DEVINFO_DAC0CAL2_VDD_GAIN_MASK          (0x7FUL << 16)  /* Gain for VDD reference, mask             */

/* Bit fields for DEVINFO HFRCOCAL0 */
#define DEVINFO_HFRCOCAL0_BAND1_SHIFT           0               /* 1MHz tuning value for HFRCO, shift       */
#define DEVINFO_HFRCOCAL0_BAND1_MASK            (0xFFUL << 0)   /* 1MHz tuning value for HFRCO, mask        */
#define DEVINFO_HFRCOCAL0_BAND7_SHIFT           8               /* 7MHz tuning value for HFRCO, shift       */
#define DEVINFO_HFRCOCAL0_BAND7_MASK            (0xFFUL << 8)   /* 7MHz tuning value for HFRCO, mask        */
#define DEVINFO_HFRCOCAL0_BAND11_SHIFT          16              /* 11MHz tuning value for HFRCO, shift      */
#define DEVINFO_HFRCOCAL0_BAND11_MASK           (0xFFUL << 16)  /* 11MHz tuning value for HFRCO, mask       */
#define DEVINFO_HFRCOCAL0_BAND14_SHIFT          24              /* 14MHz tuning value for HFRCO, shift      */
#define DEVINFO_HFRCOCAL0_BAND14_MASK           (0xFFUL << 24)  /* 14MHz tuning value for HFRCO, mask       */

/* Bit fields for DEVINFO HFRCOCAL1 */
#define DEVINFO_HFRCOCAL1_BAND21_SHIFT          0               /* 21MHz tuning value for HFRCO, shift      */    
#define DEVINFO_HFRCOCAL1_BAND21_MASK           (0xFFUL << 0)   /* 21MHz tuning value for HFRCO, mask       */
#define DEVINFO_HFRCOCAL1_BAND28_SHIFT          8               /* 28MHz tuning value for HFRCO, mask       */
#define DEVINFO_HFRCOCAL1_BAND28_MASK           (0xFFUL << 8)   /* 28MHz tuning value for HFRCO, shift      */

/* Bit fields for DEVINFO UNIQUEL */   
#define DEVINFO_UNIQUEL_SHIFT                   0               /**< Unique Low 32-bit shift                */   
#define DEVINFO_UNIQUEL_MASK                    0xFFFFFFFFUL    /**< Lower part of  64-bit device unique number */

/* Bit fields for DEVINFO UNIQUEH */
#define DEVINFO_UNIQUEH_SHIFT                   0               /**< Unique High 32-bit shift               */
#define DEVINFO_UNIQUEH_MASK                    0xFFFFFFFFUL    /**< High part of  64-bit device unique number */

/* Bit fields for DEVINFO MSIZE */ 
#define DEVINFO_MSIZE_FLASH_SHIFT               0               /* Bit position for SRAM size               */
#define DEVINFO_MSIZE_FLASH_MASK                (0xFFFFUL >> 0) /* SRAM size in kilobytes                   */
#define DEVINFO_MSIZE_SRAM_SHIFT                16              /* Bit position for flash size              */
#define DEVINFO_MSIZE_SRAM_MASK                 (0xFFFFUL >> 16)/* Flash size in kilobytes                  */
   
/* Bit fields for DEVINFO PART */ 
#define _DEVINFO_PART_DEVICE_NUMBER_SHIFT       0               /* Bit position for device number           */
#define _DEVINFO_PART_DEVICE_NUMBER_MASK        (0xFFFFUL >> 0) /* Device number                            */
#define _DEVINFO_PART_DEVICE_FAMILY_SHIFT       16              /* Bit position for device family           */
#define _DEVINFO_PART_DEVICE_FAMILY_MASK        (0xFFUL   >> 16)/* Device Family, 0x47 for Gecko            */
#define _DEVINFO_PART_PROD_REV_SHIFT            24              /* Bit position for production revision     */
#define _DEVINFO_PART_PROD_REV_MASK             (0xFFUL   >> 24)/* Production revision                      */    

    
/*************************************************************************************************************
*                                                  DATA TYPES                                                *
*************************************************************************************************************/


/*************************************************************************************************************
*                                            FUNCTION STATEMENT                                              *
*************************************************************************************************************/
CPU_INT32U DEVINFOHFRCOBandCalGet (CMUHFRCOBandTypeDef band);


/*************************************************************************************************************
*                                               MODULE END                                                   *
*************************************************************************************************************/   
#ifdef __cplusplus
}
#endif

#endif 

