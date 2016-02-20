/*************************************************************************************************************
*                                              INCLUDE FILES                                                 *
*************************************************************************************************************/
#include <string.h>
#include <utc.h>
#include <util.h>


/*************************************************************************************************************
*                                              LOCAL TABLES                                                  *
*************************************************************************************************************/
static sUtcTypeDef Utc;


/*************************************************************************************************************
*                                            FUNCTION PROTOTYPES                                             *
*************************************************************************************************************/
void UtcInit (void)
{
    Utc.year   = 0x07DD;
    Utc.month  = 0x05;
    Utc.date   = 0x0D;
    Utc.hour   = 0x00;
    Utc.minute = 0x00;
    Utc.second = 0x00;   
}

void UtcSetTime (sUtcTypeDef *tm)
{
    Utc.year   = tm->year;
    Utc.month  = tm->month;
    Utc.date   = tm->date;
    Utc.hour   = tm->hour;
    Utc.minute = tm->minute;
    Utc.second = tm->second;  
}

void UtcUpdateSecond (void)
{
    if (Utc.second < UTC_SECOND_DISPLAY_MAX)
    {
        Utc.second++;     
    }
    
    else
    {
        UtcUpdateMinute();
        Utc.second = 0;      
    }
}

void UtcUpdateMinute (void)
{
    if (Utc.minute < UTC_MINUTE_DISPLAY_MAX)
    {
        Utc.minute++;
    }
    
    else 
    {
        Utc.minute = 0;
        UtcUpdateHour();     
    }
}

void UtcUpdateHour (void)
{
    if (Utc.hour < UTC_HOUR_DISPLAY_MAX)
    {
        Utc.hour++;       
    }
    
    else
    {
        Utc.hour = 0;
        UtcUpdateDate();   
    }  
}

void UtcUpdateDate (void)
{
   unsigned char day;
   
   day = UtcGetMonthSize(Utc.year, Utc.month);
   if (Utc.date < day)
   {
       Utc.date++;   
   }
   
   else
   {
       Utc.date = 1;
       UtcUpdateMonth();
   }
}

void UtcUpdateMonth (void)
{
    if (Utc.month < UTC_MONTH_DISPLAY_MAX)
    {
        Utc.month++;
    }
    
    else
    {
        Utc.month = UTC_JANUARY_MONTH;
        UtcUpdateYear();
    }
}

void UtcUpdateYear (void)
{
    Utc.year++;   
}


unsigned char UtcGetMonthSize (unsigned short year, unsigned char month)
{
    unsigned char day;
      
    switch (month)
    {
    case UTC_JANUARY_MONTH:
    case UTC_MARCH_MONTH:
    case UTC_MAY_MONTH:
    case UTC_JULY_MONTH:
    case UTC_AUGUST_MONTH:
    case UTC_OCTOBER_MONTH:
    case UTC_DECEMBER_MONTH:                day = UTC_SOLAR_MONTH_MAX;
                                            break;
                                            
    case UTC_APRIL_MONTH:
    case UTC_JUNE_MONTH:
    case UTC_SEPTEMBER_MONTH:
    case UTC_NOVEMBER_MONTH:                day = UTC_LUNAR_MONTH_MAX;
                                            break;
                                            
    case UTC_FEBRUARY_MONTH:                if (UtcGetLeapYearFlag(year))
                                            {
                                                day = UTC_LEAP_SECOND_MONTH_MAX;
                                            }
                                            else
                                            {
                                                day = UTC_SECOND_MONTH_MAX;
                                            }
        
    default:                                break;
    }
    return day;
}

void UtcGetTime (sUtcTypeDef *tm)
{
    tm->year   = Utc.year;
    tm->month  = Utc.month;
    tm->date   = Utc.date;
    tm->hour   = Utc.hour;
    tm->minute = Utc.minute;
    tm->second = Utc.second;
}

unsigned char UtcGetLeapYearFlag (unsigned short year)
{
    if (0 == (year % 100))
    {
        if (0 == (year % 400))
        {
            return 1;
        } 
    }
    else 
    {
        if (0 == (year % 4))
        {
           return 1;
        }
    }
    
    return 0;    
}





unsigned int UtcTwoTimeDiffSecondGet(sUtcTypeDef *now, sUtcTypeDef *dst, unsigned int len)
{
   
    unsigned int mth;
    unsigned int day;
    unsigned int hour;
    unsigned int second;
    
    
    if ((0 == memcmp(now, dst, len)) | (memcmp(now, dst, len) < 0))    
   {
       return 0;
   }
   else 
   {
       mth = ((now->year - dst->year)*12 + now->month) - dst->month;
       
       if (UTC_JANUARY_MONTH == now->month)
       {
           day = UTC_SOLAR_MONTH_MAX;
       }
       else 
       {
           day = UtcGetMonthSize(now->year, now->month - 1);
       }
       
       hour = ((mth*day + now->date) - dst->date)*24 + now->hour;
       second = (((hour - dst->hour)*60 + now->minute) - dst->minute)*60 + now->second - dst->second;
       return second;    
   }
}


/*************************************************************************************************************
*                                               MODULE END                                                   *
*************************************************************************************************************/
