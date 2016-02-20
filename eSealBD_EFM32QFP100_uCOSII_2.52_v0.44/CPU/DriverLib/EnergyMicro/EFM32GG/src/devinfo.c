/*************************************************************************************************************
*                                              INCLUDE FILES                                                 *
*************************************************************************************************************/
#include <efm32.h>


/*************************************************************************************************************
*                                            FUNCTION PROTOTYPES                                             *
*************************************************************************************************************/
CPU_INT32U DEVINFOHFRCOBandCalGet (CMUHFRCOBandTypeDef band)
{
    CPU_INT32U ret;
    
    switch (band)
    {
        case HFRCO_BAND_1MHZ:   ret = (DEVINFO->HFRCOCAL0 & DEVINFO_HFRCOCAL0_BAND1_MASK) 
                                    >> DEVINFO_HFRCOCAL0_BAND1_SHIFT;
                                break;
        case HFRCO_BAND_7MHZ:   ret = (DEVINFO->HFRCOCAL0 & DEVINFO_HFRCOCAL0_BAND7_MASK) 
                                    >> DEVINFO_HFRCOCAL0_BAND7_SHIFT;
                                break;
        case HFRCO_BAND_11MHZ:  ret = (DEVINFO->HFRCOCAL0 & DEVINFO_HFRCOCAL0_BAND11_MASK) 
                                    >> DEVINFO_HFRCOCAL0_BAND11_SHIFT;
                                break;
        case HFRCO_BAND_14MHZ:  ret = (DEVINFO->HFRCOCAL0 & DEVINFO_HFRCOCAL0_BAND14_MASK) 
                                    >> DEVINFO_HFRCOCAL0_BAND14_SHIFT;
                                break;

        case HFRCO_BAND_21MHZ:  ret = (DEVINFO->HFRCOCAL1 & DEVINFO_HFRCOCAL1_BAND21_MASK) 
                                    >> DEVINFO_HFRCOCAL1_BAND21_SHIFT;
                                break;

        case HFRCO_BAND_28MHZ:  ret = (DEVINFO->HFRCOCAL1 & DEVINFO_HFRCOCAL1_BAND28_MASK) 
                                    >> DEVINFO_HFRCOCAL1_BAND28_SHIFT;
                                break;

        default:                ret = 0xFFFFFFFF;
                                break;
    }
    
    return ret;
}


/*************************************************************************************************************
*                                                  END FILE                                                  *
*************************************************************************************************************/
