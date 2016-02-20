/*************************************************************************************************************
*                                                  MODULE                                                    *
*************************************************************************************************************/
#ifndef GNSS_H
#define GNSS_H

#ifdef __cplusplus
extern "C" {
#endif


/*************************************************************************************************************
*                                                 DEFINES                                                    *
*************************************************************************************************************/ 
#define GNSS_DATA_MAX_SIZE                      256u


/*************************************************************************************************************
*                                                  DATA TYPES                                                *
*************************************************************************************************************/
#pragma pack(1)

typedef struct
{
    unsigned char  flag;
    unsigned short count;
    unsigned char  data[GNSS_DATA_MAX_SIZE];
} sGnssPackageTypeDef;

typedef struct  
{
    unsigned char  name;
    unsigned char  elevation;
    unsigned short azimuth;
    float    db;
} sStarInfoTypeDef;

typedef struct
{
    unsigned char  year;
    unsigned char  month;
    unsigned char  day;
    unsigned char  hour;
    unsigned char  min;
    unsigned char  sec;
    unsigned short ms;
} sTimeInfoTypeDef;

typedef struct
{
    unsigned char  latitude_direction;
    unsigned short latitude_h;
    unsigned int   latitude_l;
    unsigned char  longitude_direction;
    unsigned short longitude_h;
    unsigned int   longitude_l; 
} sLonLatInfoTypeDef;

typedef struct
{
    unsigned char      star_name[2];
    sTimeInfoTypeDef   time;
    sLonLatInfoTypeDef lonlat;
    unsigned char      loca_status;
    unsigned char      loca_starnum;
    float              high;
    unsigned char      high_unit;
    float              high_unusual;
    unsigned char      high_unusual_unit;
    unsigned int       diff_data_age;
    float              diff_plat_id;
    float              pdop;
    float              hdop;
    float              vdop;
    float              tdop;
    unsigned char      data_status;
    unsigned char      loca_mode;
    unsigned char      work_mode;
    unsigned char      select_work_mode;
    unsigned char      star_prn[12];
    unsigned char      viusal_starnum;
    sStarInfoTypeDef   viusal_star[20];
    unsigned char      navigation_status;
    float              ground_speed;
    float              ground_speed_direction;
    float              declination;
    unsigned char      declination_direction;
    unsigned char      navigation_mode;
} sGnssInfoTypeDef;

#pragma pack()


/*************************************************************************************************************
*                                            FUNCTION STATEMENT                                              *
*************************************************************************************************************/
float GMSSInfoConvert (unsigned int *pdata, unsigned int len);
void GNSSRMCInfoGet (unsigned char *pdata, unsigned int len, sGnssInfoTypeDef *locainfo);
void GNSSGGAInfoGet (unsigned char *pdata, unsigned int len, sGnssInfoTypeDef *locainfo);
void GNSSGSAInfoGet (unsigned char *pdata, unsigned int len, sGnssInfoTypeDef *locainfo);
void GNSSGSVInfoGet (unsigned char *pdata, unsigned int len, sGnssInfoTypeDef *locainfo);
void GNSSGLLInfoGet (unsigned char *pdata, unsigned int len, sGnssInfoTypeDef *locainfo);
void GNSSInfoProcess (unsigned char *pdata, unsigned int len, sGnssInfoTypeDef *locainfo);
void GNSSPackageProcess (unsigned char *pdata, unsigned int len);
void GNSSPackageInit (sGnssPackageTypeDef *package);
void GNSSPackegReceive (sGnssPackageTypeDef *package, unsigned char *pdata, unsigned int len);
void GNSSInfoGet (sGnssInfoTypeDef *locainfo);


/*************************************************************************************************************
*                                               MODULE END                                                   *
*************************************************************************************************************/
#ifdef __cplusplus
}
#endif

#endif
