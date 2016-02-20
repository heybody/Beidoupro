/*************************************************************************************************************
*                                              INCLUDE FILES                                                 *
*************************************************************************************************************/
#include <app.h>


/*************************************************************************************************************
*                                            GLOBAL VARIABLES                                                *
*************************************************************************************************************/
sGnssInfoTypeDef  GNSSGPSInfo;
sGnssInfoTypeDef  GNSSBDInfo;
sGnssInfoTypeDef  GNSSGNInfo;


/*************************************************************************************************************
*                                              LOCAL TABLES                                                  *
*************************************************************************************************************/
static unsigned int bFlag = 0;


/*************************************************************************************************************
*                                              INCLUDE FILES                                                 *
*************************************************************************************************************/
float GNSSInfoConvert (unsigned int *pdata, unsigned int len)
{
    float ret;
    unsigned int i;
    float times;
    unsigned int point_site;

    times = 1;
    ret = 0;

    if (len == 0)
    {
        return ret;
    }

    for (i = 0; i < len; i++)
    {
        if (pdata[i] == '.')
        {
            point_site = i;

            break;
        }
    }

    if (i == len)
    {
        point_site = len;
    }

    for (i = 0; i < point_site; i++)
    {
        ret += (pdata[point_site - i - 1] - 0x30) * times;
        times *= 10;
    }

    times = (float)pow (10, -1);

    for (i = point_site + 1; i < len; i++)
    {
        ret += (pdata[i] - 0x30) * times;
        times *= (float)pow (10, -1);
    }

    return ret;
}

void GNSSRMCInfoGet (unsigned char *pdata, unsigned int len, sGnssInfoTypeDef *locainfo)
{
    unsigned int info_len;
    unsigned int info_count;
    unsigned int info[32];
    unsigned int ret;
    unsigned int times;
    unsigned int i;
    unsigned int j;

    times = 1;
    ret = 0;
    info_len = 0;
    info_count = 0;

    for (i = 0; i < len; i++)
    {
        if ((pdata[i] == ',') || (pdata[i] == '*'))
        {
            switch (info_count)
            {
                case 1:     locainfo->time.hour = (info[0] - 0x30) * 10 + (info[1] - 0x30);
                            locainfo->time.min  = (info[2] - 0x30) * 10 + (info[3] - 0x30);
                            locainfo->time.sec  = (info[4] - 0x30) * 10 + (info[5] - 0x30);
                            for (j = 7; j < info_len; j++)
                            {
                                ret += (info[info_len - (j - 7) - 1] - 0x30) * times;
                                times *= 10;
                            }
                            locainfo->time.ms = ret;
                            break;
                case 2:     locainfo->navigation_status = info[0];
                            break;
                case 3:     if (locainfo->navigation_status == 'V')
                            {
                                break;
                            }
                            times = 1;
                            ret = 0;
                            for (j = 0; j < 4; j++)
                            {
                                ret += (info[3 - j] - 0x30) * times;
                                times *= 10;
                            }
                            locainfo->lonlat.latitude_h = ret;
                            times = 1;
                            ret = 0;
                            for (j = 5; j < info_len; j++)
                            {
                                ret += (info[info_len - (j - 5) - 1] - 0x30) * times;
                                times *= 10;
                            }
                            locainfo->lonlat.latitude_l = ret;
                            break;
                case 4:     if (locainfo->navigation_status == 'V')
                            {
                                break;
                            }
                            locainfo->lonlat.latitude_direction = info[0];
                            break;
                case 5:     if (locainfo->navigation_status == 'V')
                            {
                                break;
                            }
                            times = 1;
                            ret = 0;
                            for (j = 0; j < 5; j++)
                            {
                                ret += (info[4 - j] - 0x30) * times;
                                times *= 10;
                            }
                            locainfo->lonlat.longitude_h = ret;
                            times = 1;
                            ret = 0;
                            for (j = 6; j < info_len; j++)
                            {
                                ret += (info[info_len - (j - 6) - 1] - 0x30) * times;
                                times *= 10;
                            }
                            locainfo->lonlat.longitude_l = ret;
                            break;
                case 6:     if (locainfo->navigation_status == 'V')
                            {
                                break;
                            }
                            locainfo->lonlat.longitude_direction = info[0];
                            break;
                case 7:     if (locainfo->navigation_status == 'V')
                            {
                                break;
                            }
                            locainfo->ground_speed = GNSSInfoConvert(info, info_len);
                            break;
                case 8:     if (locainfo->navigation_status == 'V')
                            {
                                break;
                            }
                            locainfo->ground_speed_direction = GNSSInfoConvert(info, info_len);
                            break;
                case 9:	    locainfo->time.day  = (info[0] - 0x30) * 10 + (info[1] - 0x30);
                            locainfo->time.month = (info[2] - 0x30) * 10 + (info[3] - 0x30);
                            locainfo->time.year = (info[4] - 0x30) * 10 + (info[5] - 0x30);
                            break;
                case 10:    if (locainfo->navigation_status == 'V')
                            {
                                break;
                            }
                            locainfo->declination = GNSSInfoConvert(info, info_len);
                            break;
                case 11:    if (locainfo->navigation_status == 'V')
                            {
                                break;
                            }
                            locainfo->declination_direction = info[0];
                            break;
                case 12:    locainfo->navigation_mode = info[0];
                            break;
            }
            info_count++;
            info_len = 0;
        }
        else
        {
            info[info_len] = pdata[i];
            info_len++;
        }
    }
}

void GNSSGGAInfoGet (unsigned char *pdata, unsigned int len, sGnssInfoTypeDef *locainfo)
{
    unsigned int info_len;
    unsigned int info_count;
    unsigned int info[32];
    unsigned int ret;
    unsigned int times;
    unsigned int i;
    unsigned int j;
    unsigned char valid;

    times = 1;
    ret = 0;
    info_len = 0;
    info_count = 0;

    for (i = 0; i < len; i++)
    {
        if ((pdata[i] == ',') || (pdata[i] == '*'))
        {
            switch (info_count)
            {
                case 6: valid = info[0];
		        break;
            }
            info_count++;
            info_len = 0;
        }
        else
        {
            info[info_len] = pdata[i];
            info_len++;
        }
    }

    info_len = 0;
    info_count = 0;

    for (i = 0; i < len; i++)
    {
        if ((pdata[i] == ',') || (pdata[i] == '*'))
        {
            switch (info_count)
            {
                case 1:     locainfo->time.hour = (info[0] - 0x30) * 10 + (info[1] - 0x30);
                            locainfo->time.min  = (info[2] - 0x30) * 10 + (info[3] - 0x30);
                            locainfo->time.sec  = (info[4] - 0x30) * 10 + (info[5] - 0x30);
                            for (j = 7; j < info_len; j++)
                            {
                                ret += (info[info_len - (j - 7) - 1] - 0x30) * times;
                                times *= 10;
                            }
                            locainfo->time.ms = ret;
                            break;
                case 2:     if (valid == '0')
                            {
                                break;
                            }
                            times = 1;
                            ret = 0;
                            for (j = 0; j < 4; j++)
                            {
                                ret += (info[3 - j] - 0x30) * times;
                                times *= 10;
                            }
                            locainfo->lonlat.latitude_h = ret;
                            times = 1;
                            ret = 0;
                            for (j = 5; j < info_len; j++)
                            {
                                ret += (info[info_len - (j - 5) - 1] - 0x30) * times;
                                times *= 10;
                            }
                            locainfo->lonlat.latitude_l = ret;
                            break;
                case 3:	    if (valid == '0')
                            {
                                break;
                            }
                            locainfo->lonlat.latitude_direction = info[0];
                            break;
                case 4:     if (valid == '0')
                            {
                                break;
                            }
                            times = 1;
                            ret = 0;
                            for (j = 0; j < 5; j++)
                            {
                                ret += (info[4 - j] - 0x30) * times;
                                times *= 10;
                            }
                            locainfo->lonlat.longitude_h = ret;
                            times = 1;
                            ret = 0;
                            for (j = 6; j < info_len; j++)
                            {
                                ret += (info[info_len - (j - 6) - 1] - 0x30) * times;
                                times *= 10;
                            }
                            locainfo->lonlat.longitude_l = ret;
                            break;
                case 5:     if (valid == '0')
                            {
                                break;
                            }
                            locainfo->lonlat.longitude_direction = info[0];
                            break;
                case 6:     locainfo->loca_status = info[0];
                            break;
                case 7:     locainfo->loca_starnum = (unsigned char)GNSSInfoConvert(info, info_len);
                            break;
                case 8:     locainfo->hdop = GNSSInfoConvert(info, info_len);
                            break;
                case 9:     locainfo->high = GNSSInfoConvert(info, info_len);
                            break;
                case 10:    locainfo->high_unit = info[0];
                            break;
                case 11:    locainfo->high_unusual = GNSSInfoConvert(info, info_len);
                            break;
                case 12:    locainfo->high_unusual_unit = info[0];
                            break;
                case 13:    locainfo->diff_data_age = (unsigned int)GNSSInfoConvert(info, info_len);
                            break;
                case 14:    locainfo->diff_plat_id = GNSSInfoConvert(info, info_len);
                            break;
                case 15:    locainfo->vdop = GNSSInfoConvert(info, info_len);
                            break;
            }
            info_count++;
            info_len = 0;
        }
        else
        {
            info[info_len] = pdata[i];
            info_len++;
        }
    }
}

void GNSSGSAInfoGet (unsigned char *pdata, unsigned int len, sGnssInfoTypeDef *locainfo)
{
    unsigned int info_len;
    unsigned int info_count;
    unsigned int info[32];

    info_len = 0;
    info_count = 0;

    for (unsigned int i = 0; i < len; i++)
    {
        if ((pdata[i] == ',') || (pdata[i] == '*'))
        {
            switch (info_count)
            {
                case 1:     locainfo->work_mode = info[0];
                            break;
                case 2:     locainfo->select_work_mode = info[0];
                            break;
                case 3:     locainfo->star_prn[0] = (unsigned char)GNSSInfoConvert(info, info_len);
                            break;
                case 4:	    locainfo->star_prn[1] = (unsigned char)GNSSInfoConvert(info, info_len);
                            break;
                case 5:	    locainfo->star_prn[2] = (unsigned char)GNSSInfoConvert(info, info_len);
                            break;
                case 6:     locainfo->star_prn[3] = (unsigned char)GNSSInfoConvert(info, info_len);
                            break;
                case 7:     locainfo->star_prn[4] = (unsigned char)GNSSInfoConvert(info, info_len);
                            break;
                case 8:     locainfo->star_prn[5] = (unsigned char)GNSSInfoConvert(info, info_len);
                            break;
                case 9:     locainfo->star_prn[6] = (unsigned char)GNSSInfoConvert(info, info_len);
                            break;
                case 10:    locainfo->star_prn[7] = (unsigned char)GNSSInfoConvert(info, info_len);
                            break;
                case 11:    locainfo->star_prn[8] = (unsigned char)GNSSInfoConvert(info, info_len);
                            break;
                case 12:    locainfo->star_prn[9] = (unsigned char)GNSSInfoConvert(info, info_len);
                            break;
                case 13:    locainfo->star_prn[10] = (unsigned char)GNSSInfoConvert(info, info_len);
                            break;
                case 14:    locainfo->star_prn[11] = (unsigned char)GNSSInfoConvert(info, info_len);
                            break;
                case 15:    locainfo->pdop = GNSSInfoConvert(info, info_len);
                            break;
                case 16:    locainfo->hdop = GNSSInfoConvert(info, info_len);
                            break;
                case 17:    locainfo->vdop = GNSSInfoConvert(info, info_len);
                            break;
                case 18:    locainfo->tdop = GNSSInfoConvert(info, info_len);
                            break;
            }
            info_count++;
            info_len = 0;
        }
        else
        {
            info[info_len] = pdata[i];
            info_len++;
        }
    }
}

void GNSSGSVInfoGet (unsigned char *pdata, unsigned int len, sGnssInfoTypeDef *locainfo)
{
    unsigned int info_len;
    unsigned int info_count;
    unsigned int info[32];

    info_len = 0;
    info_count = 0;

    for (unsigned int i = 0; i < len; i++)
    {
        if ((pdata[i] == ',') || (pdata[i] == '*'))
        {
            switch (info_count)
            {
                case 2:     if (info[0] == '1')
                            {
                                bFlag = 0;
                            }
                            break;
                case 3:	    locainfo->viusal_starnum = (unsigned char)GNSSInfoConvert(info, info_len);
			    break;
                case 4:	    locainfo->viusal_star[bFlag].name = (unsigned char)GNSSInfoConvert(info, info_len);
			    break;
                case 5:	    locainfo->viusal_star[bFlag].elevation = (unsigned char)GNSSInfoConvert(info, info_len);
                            break;
                case 6:     locainfo->viusal_star[bFlag].azimuth = (unsigned short)GNSSInfoConvert(info, info_len);
                            break;
                case 7:     locainfo->viusal_star[bFlag].db = GNSSInfoConvert(info, info_len);
                            bFlag++;
                            break;
                case 8:     locainfo->viusal_star[bFlag].name = (unsigned char)GNSSInfoConvert(info, info_len);
                            break;
                case 9:	    locainfo->viusal_star[bFlag].elevation = (unsigned char)GNSSInfoConvert(info, info_len);
                            break;
                case 10:    locainfo->viusal_star[bFlag].azimuth = (unsigned short)GNSSInfoConvert(info, info_len);
                            break;
                case 11:    locainfo->viusal_star[bFlag].db = GNSSInfoConvert(info, info_len);
                            bFlag++;
                            break;
                case 12:    locainfo->viusal_star[bFlag].name = (unsigned char)GNSSInfoConvert(info, info_len);
                            break;
                case 13:    locainfo->viusal_star[bFlag].elevation = (unsigned char)GNSSInfoConvert(info, info_len);
                            break;
                case 14:    locainfo->viusal_star[bFlag].azimuth = (unsigned short)GNSSInfoConvert(info, info_len);
                            break;
                case 15:    locainfo->viusal_star[bFlag].db = GNSSInfoConvert(info, info_len);
                            bFlag++;
                            break;
                case 16:    locainfo->viusal_star[bFlag].name = (unsigned char)GNSSInfoConvert(info, info_len);
                            break;
                case 17:    locainfo->viusal_star[bFlag].elevation = (unsigned char)GNSSInfoConvert(info, info_len);
                            break;
                case 18:    locainfo->viusal_star[bFlag].azimuth = (unsigned short)GNSSInfoConvert(info, info_len);
                            break;
                case 19:    locainfo->viusal_star[bFlag].db = GNSSInfoConvert(info, info_len);
                            bFlag++;
                            break;
            }

            if (bFlag > 19)
            {
                bFlag = 0;
            }

            info_count++;
            info_len = 0;
        }
        else
        {
            info[info_len] = pdata[i];
            info_len++;
        }
    }
}

void GNSSGLLInfoGet (unsigned char *pdata, unsigned int len, sGnssInfoTypeDef *locainfo)
{
    unsigned int info_len;
    unsigned int info_count;
    unsigned int info[32];
    unsigned int ret;
    unsigned int times;
    unsigned int i;
    unsigned int j;
    unsigned int lengh;
    unsigned char valid;

    times = 1;
    ret = 0;
    info_len = 0;
    info_count = 0;

    for (i = 0; i < len; i++)
    {
        if ((pdata[i] == ',') || (pdata[i] == '*'))
        {
            switch (info_count)
            {
                case 6: valid = info[0];
                        break;
            }

            info_count++;
            info_len = 0;
        }
        else
        {
            info[info_len] = pdata[i];
            info_len++;
        }
    }

    info_len = 0;
    info_count = 0;

    for (i = 0; i < len; i++)
    {
        if ((pdata[i] == ',') || (pdata[i] == '*'))
        {
            switch (info_count)
            {
                case 1:     if (valid == 'V')
                            {
                                break;
                            }
                            times = 1;
                            ret = 0;
                            for (j = 0; j < 4; j++)
                            {
                                ret += (info[3 - j] - 0x30) * times;
                                times *= 10;
                            }
                            locainfo->lonlat.latitude_h = ret;
                            times = 1;
                            ret = 0;
//
                            if (info_len > 5)
                            {
                                lengh =5;
                            }
                            else
                            {
                                lengh = info_len;
                            }
//
                            for (j = 0; j < lengh; j++)
                            {
                                //ret += (info[info_len - (j - 5) - 1] - 0x30) * times;
                                //times *= 10;
                                ret = ret * 10 + (info[5 + j] -0x30);
                            }
                            locainfo->lonlat.latitude_l = ret;
                            break;
                case 2:     if (valid == 'V')
                            {
                                break;
                            }
                            locainfo->lonlat.latitude_direction = info[0];
                            break;
                case 3:     if (valid == 'V')
                            {
                                break;
                            }
                            times = 1;
                            ret = 0;
                            for (j = 0; j < 5; j++)
                            {
                                ret += (info[4 - j] - 0x30) * times;
                                times *= 10;
                            }
                            locainfo->lonlat.longitude_h = ret;
                            times = 1;
                            ret = 0;

//
                            if (info_len > 5)
                            {
                                lengh = 5;
                            }
                            else
                            {
                                lengh = info_len;
                            }
//
                            for (j = 0; j < lengh; j++)
                            {
                                //ret += (info[info_len - (j - 6) - 1] - 0x30) * times;
                                //times *= 10;
                                ret = ret * 10 + (info[6 + j] -0x30);
                            }
                            locainfo->lonlat.longitude_l = ret;
                            break;
                case 4:	    if (valid == 'V')
                            {
                                break;
                            }
                            locainfo->lonlat.longitude_direction = info[0];
                            break;
                case 5:     locainfo->time.hour = (info[0] - 0x30) * 10 + (info[1] - 0x30);
                            locainfo->time.min  = (info[2] - 0x30) * 10 + (info[3] - 0x30);
                            locainfo->time.sec  = (info[4] - 0x30) * 10 + (info[5] - 0x30);
                            for (j = 7; j < info_len; j++)
                            {
                                ret += (info[info_len - (j - 7) - 1] - 0x30) * times;
                                times *= 10;
                            }
                            locainfo->time.ms = ret;
			    break;
                case 6:     locainfo->data_status = info[0];
			    break;
                case 7:     locainfo->loca_mode = info[0];
			    break;
            }
            info_count++;
	    info_len = 0;
        }
        else
        {
            info[info_len] = pdata[i];
            info_len++;
        }
    }
}

void GNSSInfoProcess (unsigned char *pdata, unsigned int len, sGnssInfoTypeDef *locainfo)
{
    if ((pdata[3] == 'R') && (pdata[4] == 'M') && (pdata[5] == 'C'))
    {
        GNSSRMCInfoGet(pdata, len, locainfo);
    }

    if ((pdata[3] == 'G') && (pdata[4] == 'G') && (pdata[5] == 'A'))
    {
        GNSSGGAInfoGet(pdata, len, locainfo);
    }

    if ((pdata[3] == 'G') && (pdata[4] == 'L') && (pdata[5] == 'L'))
    {
        //GNSSGLLInfoGet(pdata, len, locainfo);
    }

    if ((pdata[3] == 'G') && (pdata[4] == 'S') && (pdata[5] == 'A'))
    {
        GNSSGSAInfoGet(pdata, len, locainfo);
    }

    if ((pdata[3] == 'G') && (pdata[4] == 'S') && (pdata[5] == 'V'))
    {
        //GNSSGSVInfoGet(pdata, len, locainfo);//bflag×¢ÊÍ
    }
}

void GNSSPackageProcess (unsigned char *pdata, unsigned int len)
{
    if ((pdata[0] == '$') && (pdata[1] == 'G') && (pdata[2] == 'P'))
    {
        GNSSGPSInfo.star_name[0] = 'G';
        GNSSGPSInfo.star_name[1] = 'P';
        GNSSInfoProcess(pdata, len, &GNSSGPSInfo);
    }

    if ((pdata[0] == '$') && (pdata[1] == 'B') && (pdata[2] == 'D'))
    {
        GNSSBDInfo.star_name[0] = 'B';
        GNSSBDInfo.star_name[1] = 'D';
        GNSSInfoProcess(pdata, len, &GNSSBDInfo);
    }

    if ((pdata[0] == '$') && (pdata[1] == 'G') && (pdata[2] == 'N'))
    {
        GNSSGNInfo.star_name[0] = 'G';
        GNSSGNInfo.star_name[1] = 'N';
        GNSSInfoProcess(pdata, len, &GNSSGNInfo);
    }
}

void GNSSPackageInit (sGnssPackageTypeDef *package)
{
    package->flag = 0;
    package->count = 0;
}

void GNSSPackegReceive (sGnssPackageTypeDef *package, unsigned char *pdata, unsigned int len)
{
    unsigned char  byte;
    unsigned char  checksum = 0;
    unsigned char  checksum1;

    for (unsigned int i = 0; i < len; i++)
    {
        byte  = pdata[i];

        if ((byte == '$') && (package->flag == 0))
        {
            package->flag = 1;
            package->count = 0;
        }

        if (package->flag == 1)
        {
            package->data[package->count] = byte;

            if ((package->count > 1) && (package->data[package->count] == 0x0A) && (package->data[package->count - 1] == 0x0D))
            {
                if (package->count < 5)
                {
                    package->flag = 0;
                    package->count = 0;
                    continue;
                }

                for (unsigned int j = 1; j < (package->count - 4); j++)
                {
                    checksum ^= package->data[j];
                }

                checksum1 = checksum << 4;
                if (((checksum >> 4) == (package->data[package->count -3] - 0x30)) && ((checksum1 >> 4) == (package->data[package->count - 2] - 0x30)))
                {
                    GNSSPackageProcess((unsigned char *)&package->data, package->count + 1);

                    package->flag = 0;
                    package->count = 0;
                    continue;
                }
                else
                {
                    package->flag = 0;
                    package->count = 0;
                    continue;
                }
            }

            package->count++;
            if (package->count > GNSS_DATA_MAX_SIZE)
            {
                package->flag = 0;
                package->count = 0;
                continue;
            }
        }
    }
}

void GNSSInfoGet (sGnssInfoTypeDef *locainfo)
{
    if ((locainfo->star_name[0] == 'G') && (locainfo->star_name[1] == 'P'))
    {
        memcpy(locainfo, &GNSSGPSInfo, sizeof (sGnssInfoTypeDef) - 1);
    }

    if ((locainfo->star_name[0] == 'B') && (locainfo->star_name[1] == 'D'))
    {
        memcpy(locainfo, &GNSSBDInfo, sizeof (sGnssInfoTypeDef) - 1);
    }

    if ((locainfo->star_name[0] == 'G') && (locainfo->star_name[1] == 'N'))
    {
        memcpy(locainfo, &GNSSGNInfo, sizeof (sGnssInfoTypeDef) - 1);
    }
}


/*************************************************************************************************************
*                                               MODULE END                                                   *
*************************************************************************************************************/