/*************************************************************************************************************
*                                              INCLUDE FILES                                                 *
*************************************************************************************************************/
#include <app.h>
#include <includes.h>

/*************************************************************************************************************
*                                                CONSTANTS                                                   *
*************************************************************************************************************/
static sSensorDataTypedef SensorData;
static CPU_BOOL GSensorState = DEF_OFF; 



/*************************************************************************************************************
*                                            FUNCTION PROTOTYPES                                             *
*************************************************************************************************************/
void SensorInit (void)
{
    BspMma8491Init();
    SensorData.g.flag = DEF_OFF;
    GSensorState = DEF_OFF; 
}

void SensorDataUpdata (void)
{
    CPU_BOOL flag;
    CPU_INT32U temp;
    Mma8491DataTypeDef gsensor;    
    sEsealBDSensorTypeDef sensor;
    
    EsealBDGetSensor(&sensor);

    if (BspMma8491DataGet(&gsensor) == DEF_TRUE)
    {
        SensorData.g.x = gsensor.x;
        SensorData.g.y = gsensor.y;
        SensorData.g.z = gsensor.z;
        
        if (sensor.shake_en == DEF_ON)
        {
           temp = (sensor.shake * 10000 / 625) / 10;
           
            flag = DEF_OFF;
            if (abs(SensorData.g.x) > temp)
            {
                flag = DEF_ON;
            }
            
            if (abs(SensorData.g.y) > temp)
            {
                flag = DEF_ON;
            }
            
            if (abs(SensorData.g.z) > temp)
            {
                flag = DEF_ON;
            }
        
            if (flag == DEF_ON)
            {
                if (GSensorState == DEF_OFF)
                {
                    EsealBDUpdataExtra(ESEALBD_UPDATA_IRQ_ACCELERATION, 0, 1, (FNCT_COMM)EsealBuffDataIn);
                }
                GSensorState = DEF_ON; 
            }
            else
            {
                GSensorState = DEF_OFF; 
            }
        }
        else
        {
            GSensorState = DEF_OFF; 
        }
        
    }
    
//    if (sensor.shake_en == DEF_ON)
//    {    
    
        
//        if (BspMma8491Read(BSP_MMA8491_REG_STATUS, 7, data) == DEF_ON)
//        {
//           if (data[0]  == 0x0F)
//           {
//                SensorData.g.x = BspMma8491RegOutTo8BS(data[1], data[2]);
//                SensorData.g.y = BspMma8491RegOutTo8BS(data[3], data[4]);
//                SensorData.g.z = BspMma8491RegOutTo8BS(data[5], data[6]);
//                SensorData.g.flag = DEF_ON;
//                
//                flag = DEF_OFF;
//                if (abs(SensorData.g.x) > sensor.shake)
//                {
//                    flag = DEF_ON;
//                }
//                
//                if (abs(SensorData.g.y) > sensor.shake)
//                {
//                    flag = DEF_ON;
//                }
//                
//                if (abs(SensorData.g.z) > sensor.shake)
//                {
//                    flag = DEF_ON;
//                }
//                
//                if (flag == DEF_ON)
//                {
//                    if (GSensorState == DEF_OFF)
//                    {
//                        EsealBDUpdataExtra(ESEALBD_UPDATA_IRQ, 0, 1, (FNCT_COMM)EsealBuffDataIn);
//                    }
//                    
//                    GSensorState = DEF_ON;
//                }
//                else
//                {
//                   GSensorState = DEF_OFF;  
//                }
//                
//                return;
//           } 
//        }
//    }
    

}

void SensorDataGet (sSensorDataTypedef * sensor)
{
    *sensor =  SensorData;
}

void SensorDataSet (sSensorDataTypedef sensor)
{
    SensorData =  sensor;
}



/*************************************************************************************************************
*                                               MODULE END                                                   *
*************************************************************************************************************/
