/*************************************************************************************************************
*                                              INCLUDE FILES                                                 *
*************************************************************************************************************/
#include <app.h>
CPU_BOOL TemperatureState = DEF_OFF;
CPU_BOOL HumidityState = DEF_OFF;
CPU_BOOL AccelerationState = DEF_OFF;


/*************************************************************************************************************
*                                            FUNCTION PROTOTYPES                                             *
*************************************************************************************************************/
/**
 * [EsealBDSebsorProcess  description]
 * @param pdata [传感器模块送来的数据包]
 * @param len   [传感器数据长度]
 * @param comm  [COM5RxFIFOOut]
 */
void EsealBDSebsorProcess (CPU_INT8U *pdata, CPU_INT32U len, FNCT_COMM comm)
{
    sHeadTypeDef *head;

    head = (sHeadTypeDef *)pdata;
    
    if (NToHS(head->crc) != GetCRC16(&pdata[HEAD_CRC_POS], NToHS(head->len) + HEAD_HEAD_SIZE - HEAD_CRC_LEN))
    {
        return;
    }
    
    switch (NToHS(head->type))
    {
        case ESEALBD_SENSOR_TYPE_TEMPERATURE:   EsealBDSensorTemperature(&head->data, NToHS(head->len), comm);
                                                break;
        case ESEALBD_SENSOR_TYPE_HUNIDITY:      EsealBDSensorHumidity(&head->data, NToHS(head->len), comm);
                                                break;
        case ESEALBD_SENSOR_TYPE_ACCELERATION:  EsealBDSensorAcceleration(&head->data, NToHS(head->len), comm);
                                                break;
        default:                                break;
    }
}


/**
 * [EsealBDSensorTemperature  description]
 * @param pdata [传感器裸数据包转为sHeadTypeDef]
 * @param len   【数据长度】
 * @param comm  [COM5RxFIFOOut]
 */
void EsealBDSensorTemperature (CPU_INT8U *pdata, CPU_INT32U len, FNCT_COMM comm)
{
    CPU_INT16S temperature;
    sEsealBDSensorTypeDef sensor;
    sEsealBDTemperatureTypeDef *cmd;
    sEsealBDStateTypeDef state;
    
    EsealBDGetState(&state);
    
    cmd = (sEsealBDTemperatureTypeDef *)pdata;
    
    if (cmd->sign == ESEALBD_SENSOR_SIGN_POSITIVE)
    {
        temperature = (NToHS(cmd->value) / 16 / 16 * 100 + NToHS(cmd->value) / 16 % 16 * 10 + NToHS(cmd->value) % 16) * 10;
    }
    else
    {
        temperature = (CPU_INT16S)(NToHS(cmd->value) / 16 / 16 * 100 + NToHS(cmd->value) / 16 % 16 * 10 + NToHS(cmd->value) % 16) * 10 * (-1);
    }
    
    EsealBDUpdataSensorTemperature(temperature);
    
    EsealBDGetSensor(&sensor);
    
    if (sensor.temperature_en == DEF_ON)
    {
        if (sensor.temperature > 0)
        {
            if (temperature > sensor.temperature)
            {
                if (TemperatureState == DEF_OFF)
                {
                    if (state.safe != 0x00)
                    {
                        //EsealBDUpdata(ESEALBD_UPDATA_IRQ, (FNCT_COMM)BDBuffDataIn);
                        //EsealBDUpdata(ESEALBD_UPDATA_IRQ, (FNCT_COMM)InmarsatSendMsg);
                         EsealBDUpdataExtra(ESEALBD_UPDATA_IRQ_TEMPERATURE, 0, 1, (FNCT_COMM)EsealBuffDataIn);
                    }
                }
                
                TemperatureState = DEF_ON;

            }
            else
            {
                TemperatureState = DEF_OFF;
            }
        }
        else
        {
            if (temperature < sensor.temperature)
            {
                if (TemperatureState == DEF_OFF)
                {
                    if (state.safe != 0x00)
                    {
                        //EsealBDUpdata(ESEALBD_UPDATA_IRQ, (FNCT_COMM)BDBuffDataIn);
                        //EsealBDUpdata(ESEALBD_UPDATA_IRQ, (FNCT_COMM)InmarsatSendMsg);
                         EsealBDUpdataExtra(ESEALBD_UPDATA_IRQ_TEMPERATURE, 0, 1, (FNCT_COMM)EsealBuffDataIn);
                    }
                }
                    TemperatureState = DEF_ON;
                
            }
            else
            {
                TemperatureState = DEF_OFF;
            }
        }
    }
    else
    {
        TemperatureState = DEF_OFF;
    }
}

void EsealBDSensorHumidity (CPU_INT8U *pdata, CPU_INT32U len, FNCT_COMM comm)
{
    CPU_INT16U humidity;
    sEsealBDSensorTypeDef sensor;
    sEsealBDHunmidityTypeDef *cmd;
    sEsealBDStateTypeDef state;
    
    EsealBDGetState(&state);
    
    cmd = (sEsealBDHunmidityTypeDef *)pdata;
    

    humidity = NToHS(cmd->value) / 16 / 16 / 16 * 100 + NToHS(cmd->value) / 16 / 16 % 16 * 10 + NToHS(cmd->value) / 16 % 16;
   
    EsealBDUpdataSensorHumidity(humidity);
    
    EsealBDGetSensor(&sensor);
    
    if (sensor.humidity_en == DEF_ON)
    {
        if (humidity > sensor.humidity)
        {
            if (HumidityState == DEF_OFF)
            {
                if (state.safe != 0x00)
                {
                    //EsealBDUpdata(ESEALBD_UPDATA_IRQ, (FNCT_COMM)BDBuffDataIn);
                    //EsealBDUpdata(ESEALBD_UPDATA_IRQ, (FNCT_COMM)InmarsatSendMsg);
                     EsealBDUpdataExtra(ESEALBD_UPDATA_IRQ_HUMIDITY, 0, 1, (FNCT_COMM)EsealBuffDataIn);
                }
            }
            
            HumidityState = DEF_ON;
        }
        else
        {
            HumidityState = DEF_OFF;
        }
    }
    else
    {
        HumidityState = DEF_OFF;
    }
}

void EsealBDSensorAcceleration (CPU_INT8U *pdata, CPU_INT32U len, FNCT_COMM comm)
{
    CPU_INT16U shake;
    sEsealBDSensorTypeDef sensor;
    sEsealBDAccelerationTypeDef *cmd;
    sEsealBDStateTypeDef state;
    
    EsealBDGetState(&state);
    
    cmd = (sEsealBDAccelerationTypeDef *)pdata;
    
    shake = NToHS(cmd->value_x) / 16 / 16 * 10 + NToHS(cmd->value_x) / 16 % 16 
          + NToHS(cmd->value_y) / 16 / 16 * 10 + NToHS(cmd->value_y) / 16 % 16 
          + NToHS(cmd->value_z) / 16 / 16 * 10 + NToHS(cmd->value_z) / 16 % 16;
   
    EsealBDUpdataSensorShake(shake);
    
    EsealBDGetSensor(&sensor);
    
    if (sensor.shake_en == DEF_ON)
    {
        if (shake > sensor.shake)
        {
            if (AccelerationState == DEF_OFF)
            {
                if (state.safe != 0x00)
                {
//                    EsealBDUpdata(ESEALBD_UPDATA_IRQ, (FNCT_COMM)BDBuffDataIn);
//                    EsealBDUpdata(ESEALBD_UPDATA_IRQ, (FNCT_COMM)InmarsatSendMsg);
//                     EsealBDUpdataExtra(ESEALBD_UPDATA_IRQ_ACCELERATION, 0, 1, (FNCT_COMM)EsealBuffDataIn);

                }
            }
            
            AccelerationState = DEF_ON;
        }
        else
        {
            AccelerationState = DEF_OFF;
        }
    }
    else
    {
        AccelerationState = DEF_OFF;
    }
}


/*************************************************************************************************************
*                                               MODULE END                                                   *
*************************************************************************************************************/
