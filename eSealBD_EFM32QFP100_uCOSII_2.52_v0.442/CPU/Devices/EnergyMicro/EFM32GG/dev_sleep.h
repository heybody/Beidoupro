/*************************************************************************************************************
*                                                  MODULE                                                    *
*************************************************************************************************************/
#ifndef DEV_SLEEP_H
#define DEV_SLEEP_H

#ifdef __cplusplus
extern "C" {
#endif

    
/*************************************************************************************************************
*                                                 DEFINES                                                    *
*************************************************************************************************************/


/*************************************************************************************************************
*                                                  DATA TYPES                                                *
*************************************************************************************************************/
typedef enum
{
    DEV_SLEEP_RUN,
    DEV_SLEEP_NORMAL,
    DEV_SLEEP_DEEP,
    DEV_SLEEP_STOP,
    DEV_SLEEP_SHUTOFF,
} DevSleepTypeDef;
    
/*************************************************************************************************************
*                                            FUNCTION STATEMENT                                              *
*************************************************************************************************************/    
void DevSleep (DevSleepTypeDef sleep);


/*************************************************************************************************************
*                                               MODULE END                                                   *
*************************************************************************************************************/ 
#ifdef __cplusplus
}
#endif

#endif