/*************************************************************************************************************
*                                             EXCEPTION VECTORS                                              *
*************************************************************************************************************/
#pragma language = extended


/*************************************************************************************************************
*                                              INCLUDE FILES                                                 *
*************************************************************************************************************/
#include <cpu.h>

#include <cpu_cfg.h>


/*************************************************************************************************************
*                                         GLOBAL FUNCTION STATEMENT                                          *
*************************************************************************************************************/
extern void __iar_program_start (void);

extern void NMIISR (void);
extern void FaultISR (void);
extern void MemFaultISR (void);
extern void BusFaultISR (void);
extern void UsageFaultISR (void);
extern void ReservedISR (void);

#if APP_OS_EN > 0
extern void OS_CPU_PendSVHandler (void);
#else
extern void PendSVISR (void);
#endif

extern void SysTickISR (void);


/*************************************************************************************************************
*                                          LOCAL FUNCTION STATEMENT                                          *
*************************************************************************************************************/
static CPU_LON32U pulStack[256] @ ".noinit";


/*************************************************************************************************************
*                                      EXCEPTION / INTERRUPT VECTOR TABLE                                    *
*                                                                                                            *
* Note(s) : (1) The Cortex-M3 may have up to 256 external interrupts, which are the final entries            * 
*************************************************************************************************************/
__root const uVectorEntry __vector_table[] @ ".intvec" =
{
    { .ulPtr = (CPU_LON32U)pulStack + sizeof(pulStack) },
                                            /* The initial stack pointer                                    */
    __iar_program_start,                    /* The reset handler                                            */
    NMIISR,                                 /*  2, NMI.                                                     */
    FaultISR,                               /*  3, Hard Fault.                                              */
    MemFaultISR,                            /*  4, Memory Management.                                       */
    BusFaultISR,                            /*  5, Bus Fault.                                               */
    UsageFaultISR,                          /*  6, Usage Fault.                                             */
    ReservedISR,                            /*  7, Reserved.                                                */
    ReservedISR,                            /*  8, Reserved.                                                */
    ReservedISR,                            /*  9, Reserved.                                                */
    ReservedISR,                            /* 10, Reserved.                                                */
    ReservedISR,                            /* 11, SVCall.                                                  */
    ReservedISR,                            /* 12, Debug Monitor.                                           */
    ReservedISR,                            /* 13, Reserved.                                                */
#if APP_OS_EN > 0
    OS_CPU_PendSVHandler,                   /* 14, PendSV Handler.                                          */
#else
    PendSVISR,                              /* 14, PendSV Handler.                                          */
#endif                
    SysTickISR,                             /* 15, Tick ISR Handler                                         */
};


/*************************************************************************************************************
*                                                  END FILE                                                  *
*************************************************************************************************************/
