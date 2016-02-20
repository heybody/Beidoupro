/*************************************************************************************************************
*                                                  MODULE                                                    *
*************************************************************************************************************/
#ifndef BSP_MG2639_H
#define BSP_MG2639_H


#ifdef __cplusplus
extern "C" {
#endif

    
/*************************************************************************************************************
*                                                 DEFINES                                                    *
*************************************************************************************************************/   
#define BSP_MG2639_PWRKEY_N_PIN             DEV_GPIO_PIN_4
#define BSP_MG2639_PWRKEY_N_PORT            DEV_GPIO_PORTC     

#define BSP_MG2639_SYSRST_PIN               DEV_GPIO_PIN_4
#define BSP_MG2639_SYSRST_PORT              DEV_GPIO_PORTB 
    
#define BSP_MG2639_WAKEUP_PIN               DEV_GPIO_PIN_3
#define BSP_MG2639_WAKEUP_PORT              DEV_GPIO_PORTB
    
#define BSP_MG2639_EN_PIN                   DEV_GPIO_PIN_5
#define BSP_MG2639_EN_PORT                  DEV_GPIO_PORTC

  
/*************************************************************************************************************
*                                                  DATA TYPES                                                *
*************************************************************************************************************/
void BspMG2639IOInit(void);
void BspMG2639Enable (void);
void BspMG2639Disable(void);
void BspMG2639PowerkeyPinH (void);
void BspMG2639PowerkeyPinL (void);
void BspMG2639SystemResetPinH (void);
void BspMG2639SystemResetPinL (void);
void BspMG2639WakeupPinH (void);
void BspMG2639WakeupPinL (void);


/*************************************************************************************************************
*                                               MODULE END                                                   *
*************************************************************************************************************/
#ifdef __cplusplus
}
#endif

#endif
