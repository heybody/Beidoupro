/*************************************************************************************************************
*                                                  MODULE                                                    *
*************************************************************************************************************/
#ifndef UTC_H
#define UTC_H

#ifdef __cplusplus
extern "C" {
#endif


/*************************************************************************************************************
*                                                 DEFINES                                                    *
*************************************************************************************************************/     
#define UTC_LEAP_YEAR_SIZE                      366u
#define UTC_NONLEAP_YEAR_SIZE                   365u
    
#define UTC_SECOND_DISPLAY_MAX                  59u
#define UTC_MINUTE_DISPLAY_MAX                  59u
#define UTC_HOUR_DISPLAY_MAX                    23u
#define UTC_MONTH_DISPLAY_MAX                   12u
    
#define UTC_JANUARY_MONTH                       1u
#define UTC_FEBRUARY_MONTH                      2u
#define UTC_MARCH_MONTH                         3u
#define UTC_APRIL_MONTH                         4u
#define UTC_MAY_MONTH                           5u
#define UTC_JUNE_MONTH                          6u
#define UTC_JULY_MONTH                          7u
#define UTC_AUGUST_MONTH                        8u
#define UTC_SEPTEMBER_MONTH                     9u
#define UTC_OCTOBER_MONTH                       10u
#define UTC_NOVEMBER_MONTH                      11u
#define UTC_DECEMBER_MONTH                      12u
    

#define UTC_YEAR_WD_SIZE                           2u
#define UTC_MONTH_WD_SIZE                          1u
#define UTC_DATE_WD_SIZE                           1u
#define UTC_HOUR_WD_SIZE                           1u
#define UTC_MINUTE_WD_SIZE                         1u
#define UTC_SECOND_WD_SIZE                         1u
    
#define UTC_OK                                  1u
#define UTC_ERROR                               0u
    
/*************************************************************************************************************
*                                                  DATA TYPES                                                *
*************************************************************************************************************/
typedef enum
{
    UTC_SOLAR_MONTH_MAX       = 31u,
    UTC_LUNAR_MONTH_MAX       = 30u,
    UTC_LEAP_SECOND_MONTH_MAX = 29,
    UTC_SECOND_MONTH_MAX      = 28,
} eUtcMonthSizeTypeDef;

#pragma pack(1) 
    
typedef struct
{
    unsigned short year;
    unsigned char  month;
    unsigned char  date;
    unsigned char  hour;
    unsigned char  minute;
    unsigned char  second;
} sUtcTypeDef;

              
#pragma pack()
    
    
    
/*************************************************************************************************************
*                                            FUNCTION STATEMENT                                              *
*************************************************************************************************************/
void UtcInit (void);
void UtcSetTime (sUtcTypeDef *tm);
unsigned char UtcGetLeapYearFlag (unsigned short year);
void UtcUpdateSecond (void);
void UtcUpdateMinute (void);
void UtcUpdateHour (void);
void UtcUpdateDate (void);
void UtcUpdateMonth (void);
void UtcUpdateYear (void);
unsigned char UtcGetMonthSize (unsigned short year, unsigned char month);
void UtcGetTime (sUtcTypeDef *tm);



unsigned int UtcTwoTimeDiffSecondGet(sUtcTypeDef *now, sUtcTypeDef *dst, unsigned int len);

/*************************************************************************************************************
*                                               MODULE END                                                   *
*************************************************************************************************************/
#ifdef __cplusplus
}
#endif

#endif