/*************************************************************************************************************
*                                                  MODULE                                                    *
*************************************************************************************************************/
#ifndef DEV_CLOCK_H
#define DEV_CLOCK_H

#ifdef __cplusplus
extern "C" {
#endif

    
/*************************************************************************************************************
*                                                 DEFINES                                                    *
*************************************************************************************************************/
#define DEV_CLOCK_IRQ_NUM                       6u
#define DEV_CLOCK_IRQ_MASK                      (CMU_IF_HFRCORDY | CMU_IF_HFXORDY | CMU_IF_LFRCORDY  \
                                                | CMU_IF_LFXORDY | CMU_IF_AUXHFRCORDY | CMU_IF_CALRDY)


/*************************************************************************************************************
*                                                  DATA TYPES                                                *
*************************************************************************************************************/
typedef enum
{
    DEV_CLOCK_IRQ_HSI              = CMU_IF_HFRCORDY, 
    DEV_CLOCK_IRQ_HSE              = CMU_IF_HFXORDY, 
    DEV_CLOCK_IRQ_LSI              = CMU_IF_LFRCORDY,
    DEV_CLOCK_IRQ_LSE              = CMU_IF_LFXORDY,
    DEV_CLOCK_IRQ_EFM32GG_AUXHFRCO = CMU_IF_AUXHFRCORDY,
    DEV_CLOCK_IRQ_EFM32GG_CAL      = CMU_IF_CALRDY,
} DevClockIrqTypeDef;

    
/*************************************************************************************************************
*                                            FUNCTION STATEMENT                                              *
*************************************************************************************************************/    
void DevClockInit (void);
CPU_INT32U DevClockHSIGet (void);
CPU_INT32U DevClockHSEGet (void);
CPU_INT32U DevClockLSIGet (void);
CPU_INT32U DevClockLSEGet (void);
CPU_INT32U DevClockCoreGet (void);
CPU_INT8U DevClockIntRegister (DevClockIrqTypeDef irq, FNCT_VOID isr);
CPU_INT8U DevClockIntUnregister (DevClockIrqTypeDef irq);
CPU_INT8U DevClockIntEnable (DevClockIrqTypeDef irq);
CPU_INT8U DevClockIntDisable (DevClockIrqTypeDef irq);
void DevClockIntInit (void);
void DevClockIntHandler (void);


/*************************************************************************************************************
*                                               MODULE END                                                   *
*************************************************************************************************************/ 
#ifdef __cplusplus
}
#endif

#endif
