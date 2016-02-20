/*************************************************************************************************************
*                                              INCLUDE FILES                                                 *
*************************************************************************************************************/
#include <bsp.h>

/*************************************************************************************************************
*                                                STATICS                                                   *
*************************************************************************************************************/
static CPU_INT8U I2c0RxBuffer[256];
static CPU_INT8U I2c0RxCount = DEF_ZERO;   

/*************************************************************************************************************
*                                                CONSTANTS                                                   *
*************************************************************************************************************/
void BspMma8491Init (void)
{
    DevI2cInitTypeDef init;
        
    init.mode = MASTER;
    //init.route = ROUTE_LOCATION_LOC1;
    init.div = 0x2;
     //DevI2CClockEnable();
    DevI2CClockEnable(DEV_I2C0);
    DevI2CIOConfig(DEV_I2C0, DEV_I2C_PIN_LOC1);
    DevI2CInit (DEV_I2C0, init);
    
    I2c0RxCount = DEF_ZERO;
    
    DevGPIOPinConfig(BSP_MMA8491_I2C_EN_PORT, BSP_MMA8491_I2C_EN_PIN, DEV_GPIO_PIN_MODE_OUT_PP, 
                     DEV_GPIO_PIN_DRIVE_STANDARD, DEV_GPIO_PIN_FRQ_NORMAL);
    BspMma8491EnPinL(); 
    DevI2CIntInit(DEV_I2C0);
    DevI2cIntRegister(DEV_I2C0, DEV_I2C_INT_RXDATAV, BspMma8491RxISR);
    DevI2CIntEnable(DEV_I2C0, DEV_I2C_INT_RXDATAV);
}

CPU_BOOL BspMma8491Read (CPU_INT8U reg, CPU_INT8U count, CPU_INT8U *pdata)
{
    CPU_INT32U delay;
    CPU_BOOL ret;
    CPU_BOOL ack_flag;

    ret = DEF_OFF;
    
    /* PULSE THE EN PIN FOR SENSOR */ 
    BspMma8491EnPinPulse();
    
    /* I2C START FRAME FOR WRITE ACCESS WITH ACK TIMEOUT */
    DevI2CTxStartAddr (DEV_I2C0, BSP_MMA8491_ADDR, WRITE);
    delay = 0;
    ack_flag = DEF_OFF;
    while (delay < BSP_MMA8491_RX_ACK_TIMEOUT)
    {
       delay++; 
       
       if (DevI2CSlaverAckFlagGet(DEV_I2C0) == DEF_ON )
       {
           ack_flag = DEF_ON;
           break;
       }    
    }
    
    /* I2C START FRAME FOR READ ACCESS WITH RX TIMEOUT */
    if (ack_flag == DEF_ON)
    {
        //DevI2CIntEnable(DEV_I2C0, DEV_I2C_INT_RXDATAV);
        DevI2CTxData(DEV_I2C0, &reg, 1);
        
        DevI2CTxStartAddr (DEV_I2C0, BSP_MMA8491_ADDR, READ);
        
        delay = 0;
        I2c0RxCount = 0;
        while (delay < BSP_MMA8491_RX_DATA_TIMEOUT)
        {
           delay++; 
           
           if (I2c0RxCount == count )
           {
                //DevI2CIntDisable(DEV_I2C0, DEV_I2C_INT_RXDATAV);
                memcpy(pdata, I2c0RxBuffer, count);
                ret = DEF_ON;
                break;
           }    
        }
    }

    DevI2cSendCmd(DEV_I2C0, STOP);
    delay = 500;
    while(delay--);
    
    BspMma8491EnPinL();
    
    return ret;

}

void BspMma8491RxISR (void)
{
    I2c0RxBuffer[I2c0RxCount++] = DevI2CRxData(DEV_I2C0);
    DevI2cSendCmd(DEV_I2C0, ACK);
}

void BspMma8491EnPinH (void)
{
    DevGPIOPinOutSet(BSP_MMA8491_I2C_EN_PORT, BSP_MMA8491_I2C_EN_PIN);
}

void BspMma8491EnPinL (void)
{
    DevGPIOPinOutClear(BSP_MMA8491_I2C_EN_PORT, BSP_MMA8491_I2C_EN_PIN);
}

void BspMma8491EnPinPulse (void)
{
    CPU_INT32U i;
    
    i = 200;
    BspMma8491EnPinL (); 
    while(i--);
    
    i = 2500;
    BspMma8491EnPinH ();
    while (i--); 
}

CPU_INT16S BspMma8491RegOutTo14BS (CPU_INT8U reg_msb, CPU_INT8U reg_lsb)
{
   CPU_INT16S ret;
   CPU_INT16U temp;
  
  
    if(reg_msb & 0x80)
    {
        reg_msb &= ~0x80;
        
        temp =  reg_msb << 8;
        temp |=  reg_lsb;
        temp >>= 2;
        temp |= 0xE000;

        ret = temp;
    }
    else
    {
        temp =  reg_msb << 8;
        temp |=  reg_lsb;
        temp >>= 2;
        ret = temp;

        
    }

    
    return ret;
}

CPU_INT8S BspMma8491RegOutTo8BS (CPU_INT8U reg_msb, CPU_INT8U reg_lsb)
{
   CPU_INT8S ret;
   CPU_INT16U temp;
   CPU_INT8S  temp8;
   
    if(reg_msb & 0x80)
    {
        //reg_msb &= ~0x80;
        
        temp =  (reg_msb & 0x7F) << 8;
        temp |=  reg_lsb;
        temp >>= 2;
        temp |= 0x6000;

        temp =  (~temp + 1) & 0x7FFF;
        
        temp8 =  temp >> 6;
        
        ret = 0 - temp8;
    }
    else
    {
//        temp =  reg_msb << 8;
//        temp |=  reg_lsb;
//        temp >>= 8;
//        ret = temp;
        ret =  reg_msb;
    }
    

    return ret;

}

CPU_BOOL BspMma8491DataGet (Mma8491DataTypeDef *sensor)
{
    CPU_INT8U data[8];
    
    if (BspMma8491Read(BSP_MMA8491_REG_STATUS, 7, data) == DEF_ON)
    {
        if (data[0]  == 0x0F)
        {
            sensor->x = BspMma8491RegOutTo8BS(data[1], data[2]);
            sensor->y = BspMma8491RegOutTo8BS(data[3], data[4]);
            sensor->z = BspMma8491RegOutTo8BS(data[5], data[6]);
            return DEF_TRUE;
        }
    }
    
    return DEF_FALSE;
      
}
