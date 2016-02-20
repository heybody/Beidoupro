/*************************************************************************************************************
*                                                  MODULE                                                    *
*************************************************************************************************************/
#ifndef DEV_WDOG_H
#define DEV_WDOG_H

#ifdef __cplusplus
extern "C" {
#endif

/*************************************************************************************************************
*                                                 DEFINES                                                    *
*************************************************************************************************************/
#define DEV_WDOG_NUM                            1u     
  
        
/*************************************************************************************************************
*                                                  DATA TYPES                                                *
*************************************************************************************************************/
typedef enum
{
    DEV_WDOG0 = 0
} DevWatchDogTypeDef;  

typedef enum
{
    WDOG_TIMEOUT_0_25ms = WDOG_CTRL_PERSEL_9,
    WDOG_TIMEOUT_0_5ms  = WDOG_CTRL_PERSEL_17,
    WDOG_TIMEOUT_1ms    = WDOG_CTRL_PERSEL_33,
    WDOG_TIMEOUT_2ms    = WDOG_CTRL_PERSEL_65,
    WDOG_TIMEOUT_4ms    = WDOG_CTRL_PERSEL_129,
    WDOG_TIMEOUT_8ms    = WDOG_CTRL_PERSEL_257,
    WDOG_TIMEOUT_16ms   = WDOG_CTRL_PERSEL_513,
    WDOG_TIMEOUT_32ms   = WDOG_CTRL_PERSEL_1025,
    WDOG_TIMEOUT_62_5ms = WDOG_CTRL_PERSEL_2049,
    WDOG_TIMEOUT_125ms  = WDOG_CTRL_PERSEL_4099,
    WDOG_TIMEOUT_250ms  = WDOG_CTRL_PERSEL_8193,
    WDOG_TIMEOUT_500ms  = WDOG_CTRL_PERSEL_16385,
    WDOG_TIMEOUT_1000ms = WDOG_CTRL_PERSEL_32769,
    WDOG_TIMEOUT_2000ms = WDOG_CTRL_PERSEL_65537,
    WDOG_TIMEOUT_4000ms = WDOG_CTRL_PERSEL_131073,
    WDOG_TIMEOUT_8000ms = WDOG_CTRL_PERSEL_262145
} WatchDogTimeOutTypeDef;
 
typedef struct
{
    CPU_INT32U x;
} DevWatchDogTableTypeDef;
    
/*************************************************************************************************************
*                                            FUNCTION STATEMENT                                              *
*************************************************************************************************************/
void DevWatchDogClockEnable (DevWatchDogTypeDef n);  
void DevWatchDogClockDisable (DevWatchDogTypeDef n);
void DevWatchDogEnable (DevWatchDogTypeDef n);
void DevWatchDogDisable (DevWatchDogTypeDef n);
void DevWatchDogInit (DevWatchDogTypeDef n, WatchDogTimeOutTypeDef value);
void DevWatchDogFeed (DevWatchDogTypeDef n);
void DevWatchDogLock (DevWatchDogTypeDef n);
    

/*************************************************************************************************************
*                                               MODULE END                                                   *
*************************************************************************************************************/ 
#ifdef __cplusplus
}
#endif

#endif