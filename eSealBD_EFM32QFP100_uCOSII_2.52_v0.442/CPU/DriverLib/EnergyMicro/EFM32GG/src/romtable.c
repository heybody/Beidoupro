/*************************************************************************************************************
*                                              INCLUDE FILES                                                 *
*************************************************************************************************************/
#include <efm32.h>


/*************************************************************************************************************
*                                            FUNCTION PROTOTYPES                                             *
*************************************************************************************************************/
void ROMTABLEInit (void)
{
    CPU_INT32U value;
    ROMTABLERevisionTypeDef rev;
    volatile CPU_INT32U *reg;

    value = *(volatile CPU_INT32U *)0x0FE081FCUL;
    
    ROMTABLERevisionGet(&rev);

    if ((value >> 24) == 0)
    {
        reg = (volatile CPU_INT32U *)0x400CA00CUL;
        *reg &= ~(0x00000070UL);
        
        reg = (volatile CPU_INT32U *)0x400C6020UL;
        *reg &= ~(0xE0000000UL);
        *reg |= ~(7UL << 25);
    }
    
    if ((value >> 24) <= 3)
    {
        reg = (volatile CPU_INT32U *)0x400C6020UL;
        *reg &= ~(0x00001F80UL);

        reg = (volatile CPU_INT32U *)0x400C8040UL;
        *reg = 0;
        reg = (volatile CPU_INT32U *)0x400C8044UL;
        *reg = 0;
        reg = (volatile CPU_INT32U *)0x400C8058UL;
        *reg = 0;
        reg = (volatile CPU_INT32U *)0x400C8060UL;
        *reg = 0;
        reg = (volatile CPU_INT32U *)0x400C8078UL;
        *reg = 0;
    }
    
    if (rev.major == 0x01)
    {
        if (rev.minor == 0x00)
        {
            reg = (volatile CPU_INT32U *)0x400C8040UL;
            *reg |= 0x00000002UL;
        }

        if (rev.minor <= 0x01)
        {
            reg = (volatile CPU_INT32U *)0x400C8044UL;
            *reg |= 0x00000001UL;
        }
    }

    /* Ensure correct ADC/DAC calibration value */
    value = *(volatile CPU_INT32U *)0x0FE081F0UL;
    
    if (value < 0x4C8ABA00UL)
    {
        CPU_INT32U cal;

        /* Enable ADC/DAC clocks */
        reg = (volatile CPU_INT32U *)0x400C8044UL;
        *reg |= (1 << 14 | 1 << 11);
    
        /* Retrive calibration values */
        cal = ((*(volatile CPU_INT32U *)(0x0FE081B4UL) & 0x00007F00UL) >> 8) << 24;
        cal |= ((*(volatile CPU_INT32U *)(0x0FE081B4UL) & 0x0000007FUL) >> 0) << 16;
        cal |= ((*(volatile CPU_INT32U *)(0x0FE081B4UL) & 0x00007F00UL) >> 8) << 8;
        cal |= ((*(volatile CPU_INT32U *)(0x0FE081B4UL) & 0x0000007FUL) >> 0) << 0;
    
        /* ADC0->CAL = 1.25 reference */
        reg = (volatile CPU_INT32U *)0x40002034UL;
        *reg = cal;
    
        /* DAC0->CAL = 1.25 reference */
        reg = (volatile CPU_INT32U *)0x4000402CUL;
        cal = *(volatile CPU_INT32U *)0x0FE081C8UL;
        *reg = cal;
    
        /* Turn off ADC/DAC clocks */
        reg = (volatile CPU_INT32U *)0x400C8044UL;
        *reg &= ~(1 << 14 | 1 << 11);
    }
}

void ROMTABLERevisionGet (ROMTABLERevisionTypeDef *rev)
{
    CPU_INT32U temp;
    
    rev->major = ROMTABLE->PID_0 & 0x0000003FUL;
    
    temp = (ROMTABLE->PID_3 & 0x000000F0UL) >> 4;
    
    rev->minor = (ROMTABLE->PID_2 & 0x000000F0UL) | temp;
}


/*************************************************************************************************************
*                                                  END FILE                                                  *
*************************************************************************************************************/