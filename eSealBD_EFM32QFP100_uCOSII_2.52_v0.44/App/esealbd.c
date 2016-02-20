/*************************************************************************************************************
*                                              INCLUDE FILES                                                 *
*************************************************************************************************************/
#include <app.h>
#include <includes.h>


/*************************************************************************************************************
*                                                GLOBAL FUNCTION                                             *
*************************************************************************************************************/
extern void GprsTaskReset (void);


/*************************************************************************************************************
*                                                CONSTANTS                                                   *
*************************************************************************************************************/
#pragma location = "ConstSection5"
__root const CPU_INT32U EsealBDID  = 11004;//BD:10000,D+20000,

#pragma location = "ConstSection6"
__root const CPU_INT32U EsealBDKey = 0x00000000;

#pragma location = "ConstSection7"
__root const sEsealBDDataTypeDef EsealBDData = 
{
    .len       = 10,\
    .form.year = 13,\
    .form.mon  = 6,\
    .form.day  = 19,\
    .form.hour = 17,\
    .form.min  = 44,\
    .form.sec  = 48,\
    .form.id   = 0x78563412,\
};

#pragma location = "ConstSection8"
__root const sEsealBDWorkTypeDef EsealBDWork = 
{
    .period  = 180,\
    .window  = 10,\
    .channel = ESEALBD_WORK_CH_BD,\
};

//#pragma location = "ConstSection9"
//__root const sEsealBDSensorTypeDef EsealBDSensor = 
//{
//    .temperature_en  = DEF_ON,\
//    .temperature     = 350,\
//    .humidity_en     = DEF_ON,\
//    .humidity        = 500,\
//    .shake_en        = DEF_ON,\
//    .shake           = 12,\
//};

#pragma location = "ConstSection9"
__root const sEsealBDSensorTypeDef EsealBDSensor = 
{
    .temperature_en  = DEF_OFF,\
    .temperature     = 0,\
    .humidity_en     = DEF_OFF,\
    .humidity        = 0,\
    .shake_en        = DEF_OFF,\
    .shake           = 0,\
};

#pragma location = "ConstSection10"
__root const sEsealBDStateTypeDef EsealBDState = 
{
    .power  = DEF_ON,\
    .safe   = ESEALBD_STATE_SAFE_NO_LOCKED,\
};

//typedef enum 
//{
//    ESEALBD_STATE_SAFE_NO_LOCKED = 0x00,
//    ESEALBD_STATE_SAFE_LOCKED    = 0x01,
//    ESEALBD_STATE_SAFE_UNLOCKED  = 0x02,
//} eEsealBDStateSafeTypeDef;
/*************************************************************************************************************
*                                              LOCAL TABLES                                                  *
*************************************************************************************************************/
static CPU_INT32U EsealBDRN;
static CPU_BOOL EsealBDUpdataFlag = DEF_OFF;

static sEsealBDSensorTypeDef EsealBDPresentSensor  = 
{
    .temperature_en  = DEF_OFF,\
    .temperature     = 0,\
    .humidity_en     = DEF_OFF,\
    .humidity        = 0,\
    .shake_en        = DEF_OFF,\
    .shake           = 0,\
};

//static sEsealBDStateTypeDef EsealBDState= 
//{
//    .power  = DEF_OFF,\
//    .safe   = ESEALBD_STATE_SAFE_NO_LOCKED,\
//};

static sEsealUpdataTypeDef  EsealUpdataDate;
static sEsealUpdataExtraTypeDef EsealUpdataExtra;


/*************************************************************************************************************
*                                            FUNCTION PROTOTYPES                                             *
*************************************************************************************************************/
void EsealBDInit (void)
{
    EsealBDRNInit();
}

CPU_INT32U EsealBDGetID (void)
{
    return EsealBDID;
}

void EsealBDRNInit (void)
{
    srand(EsealBDID);
    EsealBDRN = rand();
    EsealBDRN = 0xABABABAB;
}

void EsealBDSetRN (void)
{
    //EsealBDRN = rand();
}

CPU_INT32U EsealBDGetRN (void)
{
    return EsealBDRN;
}

void EsealBDGetForm (CPU_INT8U *form)
{
    memcpy(form, &EsealBDData.form, sizeof (sEsealBDFormTypeDef));
}

CPU_BOOL EsealBDCheckForm (CPU_INT8U *form)
{
    if (memcmp(form, &EsealBDData.form, sizeof (sEsealBDFormTypeDef)) == 0)
    {
        return DEF_TRUE;
    }
    
    return DEF_FALSE;
}

CPU_INT16U EsealBDGetDataSize (void)
{
    return EsealBDData.len;
}

void EsealBDSetData (CPU_INT8U *pdata, CPU_INT16U len)
{
    CM3DisableIrq();
    DevFlashUnlock();
    DevFlashErase(ESEALBD_DATA_ADDR);
    DevFlashWrite(ESEALBD_DATA_ADDR, (CPU_INT8U *)&len, 2);
    DevFlashWrite(ESEALBD_DATA_ADDR + 2, pdata, len);
    DevFlashLock();
    CM3EnableIrq();
}

void EsealBDGetData (CPU_INT8U *pdata, CPU_INT16U len)
{
    memcpy(pdata, &EsealBDData.data, len);
}

void EsealBDGetFormData (CPU_INT8U *pdata, CPU_INT16U len)
{
    memcpy(pdata, &EsealBDData.form, len);
}

void EsealBDClearData (CPU_INT16U len)
{
    CPU_INT16U temp;
    
    temp = 0;
    
    CM3DisableIrq();
    DevFlashUnlock();
    DevFlashErase(ESEALBD_DATA_ADDR);
    DevFlashWrite(ESEALBD_DATA_ADDR, (CPU_INT8U *)&temp, 2);
    DevFlashLock();
    CM3EnableIrq();
}

CPU_INT32U EsealBDGetKey (void)
{
    return EsealBDKey;
}

void EsealBDSetWork (sEsealBDWorkTypeDef work)
{
    CM3DisableIrq();
    DevFlashUnlock();
    DevFlashErase(ESEALBD_WORK_ADDR);
    DevFlashWrite(ESEALBD_WORK_ADDR, (CPU_INT8U *)&work, sizeof (sEsealBDWorkTypeDef));
    DevFlashLock();
    CM3EnableIrq();
}

void EsealBDGetWork (sEsealBDWorkTypeDef *work)
{
    memcpy(work, &EsealBDWork, sizeof (sEsealBDWorkTypeDef));
}

void EsealBDSetSensor (sEsealBDSensorTypeDef sensor)
{
    CM3DisableIrq();
    DevFlashUnlock();
    DevFlashErase(ESEALBD_SENSOR_ADDR);
    DevFlashWrite(ESEALBD_SENSOR_ADDR, (CPU_INT8U *)&sensor, sizeof (sEsealBDSensorTypeDef));
    DevFlashLock();
    CM3EnableIrq();
}

void EsealBDGetSensor (sEsealBDSensorTypeDef *sensor)
{
    memcpy(sensor, &EsealBDSensor, sizeof (sEsealBDSensorTypeDef));
}

void EsealBDUpdataSensorTemperature (CPU_INT16S temperature)
{
    EsealBDPresentSensor.temperature = temperature;
}

void EsealBDUpdataSensorHumidity (CPU_INT16U humidity)
{
    EsealBDPresentSensor.humidity = humidity;
}

void EsealBDUpdataSensorShake (CPU_INT16U shake)
{
    EsealBDPresentSensor.shake = shake;
}

void EsealBDSetState (sEsealBDStateTypeDef state)
{
    CM3DisableIrq();
    DevFlashUnlock();
    DevFlashErase(ESEALBD_STATE_ADDR);
    DevFlashWrite(ESEALBD_STATE_ADDR, (CPU_INT8U *)&state, sizeof (sEsealBDStateTypeDef));
    DevFlashLock();
    CM3EnableIrq();
}

void EsealBDGetState (sEsealBDStateTypeDef *state)
{
    memcpy(state, &EsealBDState, sizeof (sEsealBDStateTypeDef));
    
    if (BspKeyGet(BSP_KEY1) == DEF_OFF)
    {
        state->sw = 0x01;
        //EsealBDState.sw = 0x01;
    }
    else
    {
         state->sw = 0x00;
        //EsealBDState.sw = 0x00;
    }
}

CPU_INT8U EsealBDGetCH (FNCT_COMM comm)
{
    CPU_INT8U ch;
    
    if (comm == (FNCT_COMM)COM1TxFIFOIn)
    {
        ch = ESEALBD_WORK_CH_GPRS; 
    }
    else if (comm == (FNCT_COMM)BDBuffDataIn)//COM3TxFIFOIn)
    {
        ch = ESEALBD_WORK_CH_BD;
    }
    else if (comm == (FNCT_COMM)InmarsatSendMsg)//COM4TxFIFOIn)
    {
        ch = ESEALBD_WORK_CH_D;
    }
    else
    {
        ch = ESEALBD_WORK_CH_GPRS;
    }
    
    return ch;
}

void EsealBDPowerOn (void)
{
    sEsealBDStateTypeDef state;
    
    memcpy(&state, &EsealBDState, sizeof(sEsealBDStateTypeDef));
    
    state.power = DEF_ON;
    
    EsealBDSetState (state);
    
    //state.power = DEF_ON;

}

void EsealBDPowerOff (void)
{
    sEsealBDStateTypeDef state;
    
    memcpy(&state, &EsealBDState, sizeof(sEsealBDStateTypeDef));
    
    state.power = DEF_OFF;
    
    EsealBDSetState (state);
    
    //EsealBDState.power = DEF_OFF;
}

void EsealBDUpdataSafe (CPU_INT8U safe)
{
    sEsealBDStateTypeDef state;
    
    memcpy(&state, &EsealBDState, sizeof(sEsealBDStateTypeDef));

    if (BspKeyGet(BSP_KEY1) == DEF_OFF)
    {
        state.sw = 0x01;
    }
    else
    {
        state.sw = 0x00;
    }
    
    if (safe == 0x00)
    {
        if (state.sw == 0x01)
        {
            state.safe = 0x01;
        }
        
    }
    else
    {
        state.safe = 0x00;
    }
    
    EsealBDSetState (state);
 
}

void EsealBDGetFix (sEsealBDFixTypeDef *fix)
{
    sGnssInfoTypeDef gnss;
    
    gnss.star_name[0] = 'G';
    gnss.star_name[1] = 'P';
    
    GNSSInfoGet(&gnss);
    
    if (gnss.navigation_status == 'A')
    {
        fix->flag = 0x01;
    }
    else
    {
        fix->flag = 0x00;
    }
    
    fix->info = gnss.lonlat;
}

void EsealSafeCheck (void)
{

    sEsealBDStateTypeDef state;
//    sEsealBDSensorTypeDef sensor;
    memcpy(&state, &EsealBDState, sizeof(sEsealBDStateTypeDef));

    if (BspKeyGet(BSP_KEY1) == DEF_OFF)
    {
        state.sw = 0x01;
    }
    else
    {
        state.sw = 0x00;
    }
    
    if (state.safe == 0x01)
    {
        if (state.sw == 0x00)
        {
            state.safe = 0x02;
            
            EsealBDSetState (state);
             EsealBDUpdataExtra(ESEALBD_UPDATA_IRQ, 0, 1, (FNCT_COMM)EsealBuffDataIn);
           // EsealBDUpdata(ESEALBD_UPDATA_IRQ, (FNCT_COMM)EsealBuffDataIn);
            
            //EsealBDUpdata(ESEALBD_UPDATA_IRQ, (FNCT_COMM)BDBuffDataIn);
          //  EsealBDUpdata(ESEALBD_UPDATA_IRQ, (FNCT_COMM)InmarsatSendMsg);
           // EsealBDUpdata(ESEALBD_UPDATA_IRQ, (FNCT_COMM)GprsBuffDataIn);
        }
    }
}

void EsealBDUpdataUtc (void)
{
    sGnssInfoTypeDef gnss;
    sUtcTypeDef utc;
    
    gnss.star_name[0] = 'G';
    gnss.star_name[1] = 'P';
    
    GNSSInfoGet(&gnss);
    
    if (gnss.navigation_status == 'A')// && (gnss.time.sec > 55))
    {
        utc.year   = gnss.time.year + 2000;
        utc.month  = gnss.time.month;
        utc.date   = gnss.time.day;
        utc.hour   = gnss.time.hour;
        utc.minute = gnss.time.min;
        utc.second = gnss.time.sec;
        
        UtcSetTime(&utc);
    }
    else
    {
        UtcUpdateSecond();
    }
}

void EsealBDProcess (CPU_INT32U cnt)
{
    CPU_INT32U period;
    sEsealBDStateTypeDef state;
    
    EsealBDGetState(&state);
    
    if (EsealBDWork.period < 10)
    {
        period = 10;
    }
    else
    {
        period = EsealBDWork.period;
    }
    
    
    //period = 61;
    //test
    //state.safe = 0x01;
    //

    if (state.safe != 0x00)
    {
        EsealBDUpdataExtra(ESEALBD_UPDATA_PERIOD, (period / ESEALBD_UPDATA_PACKAGE_COUNT), 
                           ESEALBD_UPDATA_PACKAGE_COUNT, (FNCT_COMM)EsealBuffDataIn);
    }


}


void EsealBDProcessUpdata (CPU_INT32U cnt)
{
    sEsealBDStateTypeDef state;
    sEsealUpdataItemTypeDef item;
    CPU_INT8U err;
    CPU_INT8U  channel; 
    CPU_INT8U count;
    
    if(EsealBuffDataOut(&item) == ESEAL_TX_QUEUE_OK)
    { 
        count = 0;

        err = ESEALBD_DATA_SEND_FAIL;
        
        while(1)
        { 
           if (err == ESEALBD_DATA_SEND_SUCCESS)
           {
               break;
           }
           
           count++;
           
           if ((GprsSocketStatusGet() == DEF_ON) && (count < ESEALBD_GPRS_RESEND_COUNT))
            {
                channel = ESEALBD_WORK_CH_GPRS;
                
                BspBdCOMDisable();
                
                OSTimeDly (1000);
            }
            else 
            {
                channel = ESEALBD_WORK_CH_BD;
                
                BspBdCOMEnable();
                
                GprsTaskReset();
                
                OSTimeDly (10000);
                
                //break;
            }
            
            switch (channel)
            {
                case ESEALBD_WORK_CH_AUT0: GprsBuffDataOut(item.data, item.len, &err);
                                           break;
                case ESEALBD_WORK_CH_GPRS: GprsBuffDataOut(item.data, item.len, &err);
                                           break;
                case ESEALBD_WORK_CH_BD:   BDBuffDataOut(item.data, item.len, &err);
                                           break;
                case ESEALBD_WORK_CH_GPRS_BD:GprsBuffDataOut(item.data, item.len, &err);
                                            BDBuffDataOut(item.data, item.len, &err);
                                           break;
                case ESEALBD_WORK_CH_D:    InmarsatMsgDataOut(item.data, item.len, &err);
                                           break;
                case ESEALBD_WORK_CH_GPRS_D:GprsBuffDataOut(item.data, item.len, &err);
                                            InmarsatMsgDataOut(item.data, item.len, &err);
                                           break;
                default:                   break;
            
            }

        }
    }

    EsealBDGetState(&state);
    
    if (state.safe == 0x00)
    {
       BspBdCOMDisable(); 
    }

}
    
void EsealGprsProcess (CPU_INT32U cnt)
{
    CPU_INT32U period;
    sEsealBDStateTypeDef state;
    
    EsealBDGetState(&state);
    
    if (EsealBDWork.period < 180)
    {
        period = 180;
    }
    else
    {
        period = EsealBDWork.period;
    }
    
    period = 10;
   // state.safe = 0x01;
    
    //if ((cnt % period) == 0)
    //{
        if (state.safe != 0x00)
        {
            EsealBDUpdataExtra(ESEALBD_UPDATA_PERIOD, (period / 5), 5, (FNCT_COMM)GprsBuffDataIn);
        }
   // }


}

void EsealBDUpdata (eEsealBDUpdataTypeDef type, FNCT_COMM com)
{
    sUtcTypeDef utc;
    sEsealBDFixTypeDef fix;
    sEsealBDStateTypeDef state;
    sEsealBDSensorTypeDef sensor;
    
    UtcGetTime(&utc);
    EsealBDGetFix(&fix);
    EsealBDGetState(&state);
    EsealBDGetSensor(&sensor);
    sensor.temperature = EsealBDPresentSensor.temperature;
    sensor.humidity    = EsealBDPresentSensor.humidity;
    sensor.shake       = EsealBDPresentSensor.shake;
    EsealBDUpdataInfoReplay(type, utc, fix, state, sensor, com);
}

void EsealBDUpdataResetFlagSet (CPU_BOOL flag)
{
    EsealBDUpdataFlag = flag;
}

CPU_BOOL EsealBDUpdataResetFlagGet (void)
{
    return EsealBDUpdataFlag;
}

void EsealBDUpdataExtra (eEsealBDUpdataTypeDef type, CPU_INT16U delay , CPU_INT8U count, FNCT_COMM com)
{
    sUtcTypeDef utc;
    sEsealBDFixTypeDef fix;
    sEsealBDStateTypeDef state;
    sEsealBDSensorTypeDef sensor;
    SensorDataTypeDef group[5];
    sSensorDataTypedef sensor_data; 
    CPU_INT8U sensor_info;
    CPU_INT32U temp;
    CPU_INT8U i;
    CPU_INT16U j;
    
    if (count > 5)
    {
         return;
    }
    
    
    
   
    for (i = 0; i < count; i++)
    {   
        // delay
        for (j = 0; j < delay; j++)
        {
            EsealBDGetState(&state);
            if ((state.safe == 0x00) || (EsealBDUpdataResetFlagGet() == DEF_ON))
            {
                EsealBDUpdataResetFlagSet(DEF_OFF);
                OSTimeDly (1000);
                return;
            }
            else
            {
                OSTimeDly (1000);
            }
        }        
        
        // package common info for the first round
        if (i == 0)
        {
            UtcGetTime(&utc);
            
            EsealBDGetSensor(&sensor);
            sensor_info = 0;
            
            if (sensor.temperature_en == DEF_ON)
            {
                sensor_info |= 0X01;
            }
            
            if (sensor.humidity_en == DEF_ON)
            {
                sensor_info |= 0X02;
            }
            
            if (sensor.shake_en == DEF_ON)
            {
                sensor_info |= 0X04;
            }
            
        
            if (type == ESEALBD_UPDATA_PERIOD)
            {
                EsealUpdataExtra.count = 0;
                EsealUpdataExtra.type = ESEALBD_UPDATA_PERIOD;
                EsealUpdataExtra.delay = delay;
                EsealUpdataExtra.sensor_info = (sEsealBDUpdataExtraSensorTypeDef)sensor_info;
                EsealUpdataExtra.utc = utc;
            }
        }
        

//////////////////////////////////////////        
        
        EsealBDGetState(&state);
        group[i].thg.safety = (state.safe << 4) | state.sw;
        
        EsealBDGetFix(&fix);
        group[i].thg.location_flag  = fix.flag; 
        if (fix.flag == DEF_ON)
        {   
            temp = 0;
            temp = fix.info.latitude_h * 100000 + fix.info.latitude_l;
            
            if (fix.info.latitude_direction == 'S')
            {
                temp |= 0x8000;
            }
            
            group[i].thg.latitude  = temp;
            
            temp = 0;
            temp = fix.info.longitude_h * 100000 + fix.info.longitude_l;
            
            if (fix.info.longitude_direction == 'W')
            {
                temp |= 0x8000;
            }
            
            group[i].thg.longitude  = temp;
            
            
        }
        
        EsealBDGetSensor(&sensor);
        group[i].thg.temperature = EsealBDPresentSensor.temperature;
        group[i].thg.humidity =  (EsealBDPresentSensor.humidity / 10);
        
        SensorDataGet (&sensor_data);
        group[i].thg.gs_x = sensor_data.g.x;
        group[i].thg.gs_y = sensor_data.g.y;
        group[i].thg.gs_z = sensor_data.g.z;
        
        if (type == ESEALBD_UPDATA_PERIOD)
        {
            EsealUpdataExtra.group[i] = group[i];
            EsealUpdataExtra.count++;
        }
        

    }
    
    EsealBDUpdataExtraInfoReplay(type, utc, delay, (sEsealBDUpdataExtraSensorTypeDef)sensor_info, group, count, com);
    if (type == ESEALBD_UPDATA_PERIOD)
    {
        EsealUpdataExtra.count = 0;
        //EsealUpdataExtra.group[EsealUpdataExtra.count] = group[i];
    }
    //EsealBDUpdataInfoReplay(type, utc, fix, state, sensor, com);
}

void EsealUpdataExtraCOllectedInfoInit (void)
{
    EsealUpdataExtra.count = 0;
}

void EsealUpdataExtraCOllectedInfo(FNCT_COMM com)
{
    if (EsealUpdataExtra.count > 0)
    {
        EsealBDUpdataExtraInfoReplay(EsealUpdataExtra.type, EsealUpdataExtra.utc, EsealUpdataExtra.delay,
                                    EsealUpdataExtra.sensor_info, EsealUpdataExtra.group, EsealUpdataExtra.count, com);
        EsealUpdataExtra.count = 0;
    }

}
void EsealBuffInit (void)
{
    QueueInit(&EsealUpdataDate.queue);
    EsealUpdataDate.flag = DEF_OFF;
}

eEsealUpdataTXQueueTypeDef EsealBuffDataOut (sEsealUpdataItemTypeDef *pitem)
{
    sEsealUpdataItemTypeDef item;
    void *temp;
    //CPU_BOOL flag;
    //CPU_INT8U count;
    
    
    if (QueueIsEmpty(&EsealUpdataDate.queue) == DEF_TRUE) 
    {
        return ESEAL_TX_QUEUE_EMPTY; 
    }

    EsealUpdataDate.flag = DEF_ON;

    QueueOut(&EsealUpdataDate.queue, &temp, sizeof(sEsealUpdataItemTypeDef), ESEALBD_DATA_QUEUE_SIZE);
    
    item = *(sEsealUpdataItemTypeDef*)temp;
    
    EsealUpdataDate.flag = DEF_OFF;
    
    *pitem = item;
    return ESEAL_TX_QUEUE_OK; 

}

eEsealUpdataTXQueueTypeDef EsealBuffDataIn (CPU_INT8U *pdata, CPU_INT16U len)
{
    sEsealUpdataItemTypeDef *item;
    void *temp;
    
    if (len > ESEALBD_DATA_MAX_SIZE)
    {
        return ESEAL_TX_QUEUE_ERROR_ITEM_SIZE;
    }
    
    while (EsealUpdataDate.flag)
    {
        OSTimeDly(10);
    }

    if (QueueIsFull(&EsealUpdataDate.queue, ESEALBD_DATA_QUEUE_SIZE) == DEF_TRUE)
    {
        return ESEAL_TX_QUEUE_ERROR_QUEUE_SIZE; 
    }
    
    QueueIn(&EsealUpdataDate.queue, &temp, sizeof(sEsealUpdataItemTypeDef), ESEALBD_DATA_QUEUE_SIZE);
    
    item = (sEsealUpdataItemTypeDef *)temp;
    
    item->len = len;
    
    memcpy(item->data, pdata, item->len); 

    return ESEAL_TX_QUEUE_OK;
}

/*************************************************************************************************************
*                                               MODULE END                                                   *
*************************************************************************************************************/
