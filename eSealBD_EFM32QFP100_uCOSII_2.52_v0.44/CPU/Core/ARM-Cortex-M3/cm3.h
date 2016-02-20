/*************************************************************************************************************
*                                                  MODULE                                                    *
*************************************************************************************************************/
#ifndef CM3_H
#define CM3_H

#ifdef __cplusplus
extern "C" {
#endif
    

/*************************************************************************************************************
*                                                 DEFINES                                                    *
*************************************************************************************************************/ 
#define CM3_CODE_BASE                           0x00000000UL    /* Code base address                        */
#define CM3_DATA_BASE                           0x20000000UL    /* Data base address                        */
    
#define CM3_SYSTICK_BASE                        0xE000E010UL    /* System tick base address                 */
#define CM3_NVIC_BASE                           0xE000E100UL    /* System tick base address                 */
#define CM3_SCB_BASE                            0xE000ED00UL    /* System Control Block base address        */

/* Bit fields for CM3 SYSTICK */
#define CM3_SYSTICK_CTRL_COUNT                  0x00010000uL    /* Count flag.                              */
#define CM3_SYSTICK_CTRL_CLK_SRC                0x00000004uL    /* Clock Source.                            */
#define CM3_SYSTICK_CTRL_INTEN                  0x00000002uL    /* Interrupt enable.                        */
#define CM3_SYSTICK_CTRL_ENABLE                 0x00000001uL    /* Counter mode.                            */
    
/* Bit fields for CM3 SCB SCR */
#define CM3_SCB_SCR_SLEEPONEXIT                 (0x1UL << 1)    /* SCB SCR: SLEEPONEXIT                     */
#define CM3_SCB_SCR_SLEEPDEEP                   (0x1UL << 2)    /* SCB SCR: SLEEPDEEP                       */
#define CM3_SCB_SCR_SEVONPEND                   (0x1UL << 4)    /* SCB SCR: SEVONPEND                       */


/*************************************************************************************************************
*                                                  DATA TYPES                                                *
*************************************************************************************************************/
typedef struct
{
    DEF_IO CPU_INT32U CTRL;     /* Offset: 0x00  SysTick Control and Status Register                        */
    DEF_IO CPU_INT32U LOAD;     /* Offset: 0x04  SysTick Reload Value Register                              */
    DEF_IO CPU_INT32U VAL;      /* Offset: 0x08  SysTick Current Value Register                             */
    DEF_I  CPU_INT32U CALIB;    /* Offset: 0x0C  SysTick Calibration Register                               */
} CM3SysTickRegTypeDef;

typedef struct
{
    DEF_IO CPU_INT32U ISER[8];          /* Offset: 0x000  Interrupt Set Enable Register                     */
           CPU_INT32U RESERVED0[24];                                   
    DEF_IO CPU_INT32U ICER[8];          /* Offset: 0x080  Interrupt Clear Enable Register                   */
           CPU_INT32U RSERVED1[24];                                    
    DEF_IO CPU_INT32U ISPR[8];          /* Offset: 0x100  Interrupt Set Pending Register                    */
           CPU_INT32U RESERVED2[24];                                   
    DEF_IO CPU_INT32U ICPR[8];          /* Offset: 0x180  Interrupt Clear Pending Register                  */
           CPU_INT32U RESERVED3[24];                                   
    DEF_IO CPU_INT32U IABR[8];          /* Offset: 0x200  Interrupt Active bit Register                     */
           CPU_INT32U RESERVED4[56];                                   
    DEF_IO CPU_INT8U  IP[240];          /* Offset: 0x300  Interrupt Priority Register (8Bit wide)           */
           CPU_INT32U RESERVED5[644];                                  
    DEF_O  CPU_INT32U STIR;             /* Offset: 0xE00  Software Trigger Interrupt Register               */
} CM3NVICRegType; 

typedef struct
{
    DEF_I  CPU_INT32U CPUID;    /* Offset: 0x00  CPU ID Base Register                                       */
    DEF_IO CPU_INT32U ICSR;     /* Offset: 0x04  Interrupt Control State Register                           */
    DEF_IO CPU_INT32U VTOR;     /* Offset: 0x08  Vector Table Offset Register                               */
    DEF_IO CPU_INT32U AIRCR;    /* Offset: 0x0C  Application Interrupt / Reset Control Register             */
    DEF_IO CPU_INT32U SCR;      /* Offset: 0x10  System Control Register                                    */
    DEF_IO CPU_INT32U CCR;      /* Offset: 0x14  Configuration Control Register                             */
    DEF_IO CPU_INT8U  SHP[12];  /* Offset: 0x18  System Handlers Priority Registers (4-7, 8-11, 12-15)      */
    DEF_IO CPU_INT32U SHCSR;    /* Offset: 0x24  System Handler Control and State Register                  */
    DEF_IO CPU_INT32U CFSR;     /* Offset: 0x28  Configurable Fault Status Register                         */
    DEF_IO CPU_INT32U HFSR;     /* Offset: 0x2C  Hard Fault Status Register                                 */
    DEF_IO CPU_INT32U DFSR;     /* Offset: 0x30  Debug Fault Status Register                                */
    DEF_IO CPU_INT32U MMFAR;    /* Offset: 0x34  Mem Manage Address Register                                */
    DEF_IO CPU_INT32U BFAR;     /* Offset: 0x38  Bus Fault Address Register                                 */
    DEF_IO CPU_INT32U AFSR;     /* Offset: 0x3C  Auxiliary Fault Status Register                            */
    DEF_I  CPU_INT32U PFR[2];   /* Offset: 0x40  Processor Feature Register                                 */
    DEF_I  CPU_INT32U DFR;      /* Offset: 0x48  Debug Feature Register                                     */
    DEF_I  CPU_INT32U ADR;      /* Offset: 0x4C  Auxiliary Feature Register                                 */
    DEF_I  CPU_INT32U MMFR[4];  /* Offset: 0x50  Memory Model Feature Register                              */
    DEF_I  CPU_INT32U ISAR[5];  /* Offset: 0x60  ISA Feature Register                                       */
} CM3SCBRegType; 


/*************************************************************************************************************
*                                                 DEFINES                                                    *
*************************************************************************************************************/ 
#define CM3_SYSTICK                             ((CM3SysTickRegTypeDef *)CM3_SYSTICK_BASE)
#define CM3_NVIC                                ((CM3NVICRegType *)CM3_NVIC_BASE)
#define CM3_SCB                                 ((CM3SCBRegType *)CM3_SCB_BASE)


/*************************************************************************************************************
*                                            FUNCTION PROTOTYPES                                             *
*************************************************************************************************************/
static inline void CM3NVICClearPendingIRQ (CPU_INT32U irq)
{
    CM3_NVIC->ICPR[irq >> 5] = (1 << (irq & 0x0000001F));   /* Clear pending interrupt                      */
}

static inline void CM3NVICEnableIRQ (CPU_INT32U irq)
{
    CM3_NVIC->ISER[irq >> 5] = (1 << (irq & 0x0000001F));   /* enable interrupt                             */
}

static inline void CM3NVICDisableIRQ (CPU_INT32U irq)
{
    CM3_NVIC->ICER[irq >> 5] = (1 << (irq & 0x0000001F));   /* disable interrupt                            */
}

static inline void CM3NVICSetPriority(CPU_INT32U irq, CPU_INT32U priority)
{
    CM3_NVIC->IP[irq] = ((priority << 5) & 0xff);   /* set Priority for device specific Interrupts          */
}

static inline void CM3NVICSetVectorTable (CPU_INT32U table, CPU_INT32U offset)
{   
    CM3_SCB->VTOR = table | (offset & (CPU_INT32U)0x1FFFFF80);
}

static inline void CM3CoreSleep(void)
{
    CM3_SCB->SCR &= ~CM3_SCB_SCR_SLEEPDEEP;
    
    __asm("wfi");
}

static inline void CM3CoreDeepSleep(void)
{
    CM3_SCB->SCR |= CM3_SCB_SCR_SLEEPDEEP;
    
    __asm("wfi");
}

static inline void SysTickDisable (void)
{
    CM3_SYSTICK->CTRL &= ~CM3_SYSTICK_CTRL_INTEN;
}

static inline void CM3SetMSP (CPU_INT32U stack)
{
    __asm("msr msp, r0");
    __asm("bx lr");
}

static inline void CM3EnableIrq (void)
{
    __asm("cpsie i");
    __asm("bx lr");
}

static inline void CM3DisableIrq (void)
{
    __asm("cpsid i");
    __asm("bx lr");
}


/*************************************************************************************************************
*                                            FUNCTION STATEMENT                                              *
*************************************************************************************************************/
void SysTickInit (CPU_INT32U cnts);
void SysTickDelay (CPU_INT32U t);
void SysTickTimimg (void);


/*************************************************************************************************************
*                                               MODULE END                                                   *
*************************************************************************************************************/
#ifdef __cplusplus
}
#endif

#endif


