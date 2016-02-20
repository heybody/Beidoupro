/*************************************************************************************************************
*                                              INCLUDE FILES                                                 *
*************************************************************************************************************/
#include <cpu.h>

#include <cm3.h>

#include <interrupt.h>

#include <cpu_cfg.h>

#if APP_OS_EN > 0
#include <ucos_ii.h>
#endif


/*************************************************************************************************************
*                                            GLOBAL VARIABLES                                                *
*************************************************************************************************************/
extern const uVectorEntry __vector_table[];


/*************************************************************************************************************
*                                               LOCAL TABLES                                                 *
*************************************************************************************************************/
__no_init uVectorEntry IntVectTbl[CORE_INT_SRC_NBR + PERIPH_INT_SRC_NBR] @ INT_VECT_TABLE_ADDR;


/*************************************************************************************************************
*                                            FUNCTION PROTOTYPES                                             *
*************************************************************************************************************/
void IntInit (void)
{
    CPU_INT32U vect;
    
    IntVectTbl[0].ulPtr = __vector_table[0].ulPtr;
    
    for (vect = 1; vect < CORE_INT_SRC_NBR; vect++) 
    {
        IntVectTbl[vect].pfnHandler = __vector_table[vect].pfnHandler;
    }

    for (vect = CORE_INT_SRC_NBR; vect < (CORE_INT_SRC_NBR + PERIPH_INT_SRC_NBR); vect++) 
    {
        IntVectRegister(vect, IntHandlerDefault);
    }
}

void IntVectRegister (CPU_INT32U vect, FNCT_VOID isr)
{ 
    if ((vect > (CORE_INT_SRC_NBR - 1)) && (vect < (PERIPH_INT_SRC_NBR + CORE_INT_SRC_NBR))) 
    {
        IntVectTbl[vect].pfnHandler = isr;
    }
}

void IntVectUnregister (CPU_INT32U vect)
{ 
    if ((vect > (CORE_INT_SRC_NBR - 1)) && (vect < (PERIPH_INT_SRC_NBR + CORE_INT_SRC_NBR))) 
    {
        IntVectTbl[vect].pfnHandler = IntHandlerDefault;
    }
}

void IntEnable (CPU_INT32U vect)
{
    CM3NVICClearPendingIRQ(vect - CORE_INT_SRC_NBR);
    CM3NVICEnableIRQ(vect - CORE_INT_SRC_NBR);
}

void IntDisable (CPU_INT32U vect)
{
    CM3NVICClearPendingIRQ(vect - CORE_INT_SRC_NBR);
    CM3NVICDisableIRQ(vect - CORE_INT_SRC_NBR);
}

void IntHandlerDefault (void)
{
    while(DEF_TRUE);
}

void NMIISR (void)
{
    while (DEF_TRUE);
}

void FaultISR (void)
{
    while (DEF_TRUE);
}

void MemFaultISR (void)
{
    while (DEF_TRUE);
}

void BusFaultISR (void)
{
    while (DEF_TRUE);
}

void UsageFaultISR (void)
{
    while (DEF_TRUE);
}

void ReservedISR (void)
{
    while (DEF_TRUE);
}

void PendSVISR (void)
{
    while (DEF_TRUE);
}

void SysTickISR (void)
{
#if APP_OS_EN > 0
    
#if OS_CRITICAL_METHOD == 3u
    OS_CPU_SR  cpu_sr;
#endif

    OS_ENTER_CRITICAL();                         /* Tell uC/OS-II that we are starting an ISR               */
    OSIntNesting++;
    OS_EXIT_CRITICAL();

    OSTimeTick();                                /* Call uC/OS-II's OSTimeTick()                            */

    OSIntExit();                                 /* Tell uC/OS-II that we are leaving the ISR               */
#else
    SysTickTimimg();
#endif  
}


/*************************************************************************************************************
*                                                  END FILE                                                  *
*************************************************************************************************************/