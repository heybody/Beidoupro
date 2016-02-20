/*************************************************************************************************************
*                                                  MODULE                                                    *
*************************************************************************************************************/
#ifndef BSP_HM1103C_H
#define BSP_HM1103C_H

#ifdef __cplusplus
extern "C" {
#endif

    
/*************************************************************************************************************
*                                                 DEFINES                                                    *
*************************************************************************************************************/ 
#define BSP_HM1103C_RST_PIN                     DEV_GPIO_PIN_7
#define BSP_HM1103C_RST_PORT                    DEV_GPIO_PORTA   

    
/*************************************************************************************************************
*                                            FUNCTION STATEMENT                                              *
*************************************************************************************************************/
void BspHM1103CInit (void);
void BspHM1103CIOInit (void);
void BspHM1103CResetOn (void);
void BspHM1103CResetOff (void);
void BspHM1103CBDColdOpen (FNCT_COMM comm);
void BspHM1103CGPSColdOpen (FNCT_COMM comm);
void BspHM1103CGNSSColdOpen (FNCT_COMM comm);
void BspHM1103CBDWarmOpen (FNCT_COMM comm);
void BspHM1103CGPSWarmOpen (FNCT_COMM comm);
void BspHM1103CGNSSWarmOpen (FNCT_COMM comm);


/*************************************************************************************************************
*                                               MODULE END                                                   *
*************************************************************************************************************/ 
#ifdef __cplusplus
}
#endif

#endif
