/*************************************************************************************************************
*                                              INCLUDE FILES                                                 *
*************************************************************************************************************/
#include <dev.h>


/*************************************************************************************************************
*                                              LOCAL TABLES                                                  *
*************************************************************************************************************/
static FNCT_VOID DevI2cIntVectTbl[DEV_I2C_NUM][DEV_I2C_INT_NUM];
static volatile CPU_INT32U DevI2cIrqRegisterFlag[DEV_I2C_NUM];

static DevI2cIntTypedef DevI2cIntVectPrioTb[DEV_I2C_INT_NUM] = 
{
    DEV_I2C_INT_START,
    DEV_I2C_INT_RSTART,
    DEV_I2C_INT_ADDR,
    DEV_I2C_INT_TXC,
    DEV_I2C_INT_TXBL,
    DEV_I2C_INT_RXDATAV,
    DEV_I2C_INT_ACK,
    DEV_I2C_INT_NACK,
    DEV_I2C_INT_MSTOP,
    DEV_I2C_INT_ARBLOST,
    DEV_I2C_INT_BUSERR,
    DEV_I2C_INT_BUSHOLD,
    DEV_I2C_INT_TXOF,
    DEV_I2C_INT_RXUF,
    DEV_I2C_INT_BITO,
    DEV_I2C_INTF_CLTO,
    DEV_I2C_INT_SSTOP,
};

/*************************************************************************************************************
*                                              LOCAL FUNCTION                                                *
*************************************************************************************************************/
static CPU_INT8U DevI2cVectPrioGet (DevI2cIntTypedef type);



/*************************************************************************************************************
*                                                CONSTANTS                                                   *
*************************************************************************************************************/
const DevI2CTableTypeDef DevI2CTable [DEV_I2C_NUM] = 
{
    {
        .port = i2c0,\
        .pin[DEV_I2C_PIN_LOC0].sda_port = DEV_I2C0_LOC0_SDA_PORT,\
        .pin[DEV_I2C_PIN_LOC0].scl_port = DEV_I2C0_LOC0_SCL_PORT,\
        .pin[DEV_I2C_PIN_LOC0].sda_pin = DEV_I2C0_LOC0_SDA_PIN,\
        .pin[DEV_I2C_PIN_LOC0].scl_pin = DEV_I2C0_LOC0_SCL_PIN,\
        .pin[DEV_I2C_PIN_LOC0].loc = DEV_I2C0_LOC0,\
        .pin[DEV_I2C_PIN_LOC1].sda_port = DEV_I2C0_LOC1_SDA_PORT,\
        .pin[DEV_I2C_PIN_LOC1].scl_port = DEV_I2C0_LOC1_SCL_PORT,\
        .pin[DEV_I2C_PIN_LOC1].sda_pin = DEV_I2C0_LOC1_SDA_PIN,\
        .pin[DEV_I2C_PIN_LOC1].scl_pin = DEV_I2C0_LOC1_SCL_PIN,\
        .pin[DEV_I2C_PIN_LOC1].loc = DEV_I2C0_LOC1,\
        .pin[DEV_I2C_PIN_LOC2].sda_port = DEV_I2C0_LOC2_SDA_PORT,\
        .pin[DEV_I2C_PIN_LOC2].scl_port = DEV_I2C0_LOC2_SCL_PORT,\
        .pin[DEV_I2C_PIN_LOC2].sda_pin = DEV_I2C0_LOC2_SDA_PIN,\
        .pin[DEV_I2C_PIN_LOC2].scl_pin = DEV_I2C0_LOC2_SCL_PIN,\
        .pin[DEV_I2C_PIN_LOC2].loc = DEV_I2C0_LOC2,\
        .pin[DEV_I2C_PIN_LOC3].sda_port = DEV_I2C0_LOC3_SDA_PORT,\
        .pin[DEV_I2C_PIN_LOC3].scl_port = DEV_I2C0_LOC3_SCL_PORT,\
        .pin[DEV_I2C_PIN_LOC3].sda_pin = DEV_I2C0_LOC3_SDA_PIN,\
        .pin[DEV_I2C_PIN_LOC3].scl_pin = DEV_I2C0_LOC3_SCL_PIN,\
        .pin[DEV_I2C_PIN_LOC3].loc = DEV_I2C0_LOC3,\
        .pin[DEV_I2C_PIN_LOC4].sda_port = DEV_I2C0_LOC4_SDA_PORT,\
        .pin[DEV_I2C_PIN_LOC4].scl_port = DEV_I2C0_LOC4_SCL_PORT,\
        .pin[DEV_I2C_PIN_LOC4].sda_pin = DEV_I2C0_LOC4_SDA_PIN,\
        .pin[DEV_I2C_PIN_LOC4].scl_pin = DEV_I2C0_LOC4_SCL_PIN,\
        .pin[DEV_I2C_PIN_LOC4].loc = DEV_I2C0_LOC4,\
        .pin[DEV_I2C_PIN_LOC5].sda_port = DEV_I2C0_LOC5_SDA_PORT,\
        .pin[DEV_I2C_PIN_LOC5].scl_port = DEV_I2C0_LOC5_SCL_PORT,\
        .pin[DEV_I2C_PIN_LOC5].sda_pin = DEV_I2C0_LOC5_SDA_PIN,\
        .pin[DEV_I2C_PIN_LOC5].scl_pin = DEV_I2C0_LOC5_SCL_PIN,\
        .pin[DEV_I2C_PIN_LOC5].loc = DEV_I2C0_LOC5,\
    },\
    {
        .port = i2c1,\
        .pin[DEV_I2C_PIN_LOC0].sda_port = DEV_I2C1_LOC0_SDA_PORT,\
        .pin[DEV_I2C_PIN_LOC0].scl_port = DEV_I2C1_LOC0_SCL_PORT,\
        .pin[DEV_I2C_PIN_LOC0].sda_pin = DEV_I2C1_LOC0_SDA_PIN,\
        .pin[DEV_I2C_PIN_LOC0].scl_pin = DEV_I2C1_LOC0_SCL_PIN,\
        .pin[DEV_I2C_PIN_LOC0].loc = DEV_I2C1_LOC0,\
        .pin[DEV_I2C_PIN_LOC1].sda_port = DEV_I2C1_LOC1_SDA_PORT,\
        .pin[DEV_I2C_PIN_LOC1].scl_port = DEV_I2C1_LOC1_SCL_PORT,\
        .pin[DEV_I2C_PIN_LOC1].sda_pin = DEV_I2C1_LOC1_SDA_PIN,\
        .pin[DEV_I2C_PIN_LOC1].scl_pin = DEV_I2C1_LOC1_SCL_PIN,\
        .pin[DEV_I2C_PIN_LOC1].loc = DEV_I2C1_LOC1,\
        .pin[DEV_I2C_PIN_LOC2].sda_port = DEV_I2C1_LOC2_SDA_PORT,\
        .pin[DEV_I2C_PIN_LOC2].scl_port = DEV_I2C1_LOC2_SCL_PORT,\
        .pin[DEV_I2C_PIN_LOC2].sda_pin = DEV_I2C1_LOC2_SDA_PIN,\
        .pin[DEV_I2C_PIN_LOC2].scl_pin = DEV_I2C1_LOC2_SCL_PIN,\
        .pin[DEV_I2C_PIN_LOC2].loc = DEV_I2C1_LOC2,\
    },\
};

void  DevI2CInit (DevI2CTypeDef x, DevI2cInitTypeDef init)
{
    GPIOClockEnable();
   // DevI2CClockEnable(DevI2CTable[x].port);
        
  /*  I2CRouteSet(DevI2CTable[x].port, init.route);
    
    switch (init.route)
    {
        case ROUTE_LOCATION_LOC0 :GPIOModeSet(I2C_ROUTE_LOCATION_LOC0_SDA_PORT, I2C_ROUTE_LOCATION_LOC0_SDA_PIN,
                                              GPIO_MODE_WIREDAND);
                                  GPIOModeSet(I2C_ROUTE_LOCATION_LOC0_SCL_PORT, I2C_ROUTE_LOCATION_LOC0_SCL_PIN,
                                              GPIO_MODE_WIREDAND);
                                  break;
        case ROUTE_LOCATION_LOC1 :GPIOModeSet(I2C_ROUTE_LOCATION_LOC1_SDA_PORT, I2C_ROUTE_LOCATION_LOC1_SDA_PIN,
                                              GPIO_MODE_WIREDAND);
                                  GPIOModeSet(I2C_ROUTE_LOCATION_LOC1_SCL_PORT, I2C_ROUTE_LOCATION_LOC1_SCL_PIN,
                                              GPIO_MODE_WIREDAND);
                                  break;
        case ROUTE_LOCATION_LOC2 :GPIOModeSet(I2C_ROUTE_LOCATION_LOC2_SDA_PORT, I2C_ROUTE_LOCATION_LOC2_SDA_PIN,
                                              GPIO_MODE_WIREDAND);
                                  GPIOModeSet(I2C_ROUTE_LOCATION_LOC2_SCL_PORT, I2C_ROUTE_LOCATION_LOC2_SCL_PIN,
                                              GPIO_MODE_WIREDAND);
                                  break;
        case ROUTE_LOCATION_LOC4 :GPIOModeSet(I2C_ROUTE_LOCATION_LOC1_SDA_PORT, I2C_ROUTE_LOCATION_LOC1_SDA_PIN,
                                              GPIO_MODE_WIREDAND);
                                  GPIOModeSet(I2C_ROUTE_LOCATION_LOC1_SCL_PORT, I2C_ROUTE_LOCATION_LOC1_SCL_PIN,
                                              GPIO_MODE_WIREDAND);
                                  break;
        case ROUTE_LOCATION_LOC5 :GPIOModeSet(I2C_ROUTE_LOCATION_LOC2_SDA_PORT, I2C_ROUTE_LOCATION_LOC2_SDA_PIN,
                                              GPIO_MODE_WIREDAND);
                                  GPIOModeSet(I2C_ROUTE_LOCATION_LOC2_SCL_PORT, I2C_ROUTE_LOCATION_LOC2_SCL_PIN,
                                              GPIO_MODE_WIREDAND);
                                  break;
        case ROUTE_LOCATION_LOC6 :GPIOModeSet(I2C_ROUTE_LOCATION_LOC3_SDA_PORT, I2C_ROUTE_LOCATION_LOC3_SDA_PIN,
                                              GPIO_MODE_WIREDAND);
                                  GPIOModeSet(I2C_ROUTE_LOCATION_LOC3_SCL_PORT, I2C_ROUTE_LOCATION_LOC3_SCL_PIN,
                                              GPIO_MODE_WIREDAND);
                                  break;
        default :                 break;
                                  
    }
 */   
    switch (init.mode)
    {
        case MASTER:            I2CSLAVEDisable(DevI2CTable[x].port);
                                break;
        case SLAVE:             I2CSaddrSet(DevI2CTable[x].port, init.slave_addr);
                                I2CSaddrMaskSet(DevI2CTable[x].port, 0x7F);
                                I2CSLAVEEnable(DevI2CTable[x].port);
                                break;
        default:break;    
    
    }
    
    I2CLHRSet (DevI2CTable[x].port, CLHR_STANDARD);
        
    I2CClkdivSet(DevI2CTable[x].port, init.div);
    
    I2CIntDisable(DevI2CTable[x].port, IF_ALL);

    I2CIFClear(DevI2CTable[x].port, IF_ALL);
    
    I2CRouteSCLPinEnable(DevI2CTable[x].port);
    
    I2CRouteSDAPinEnable(DevI2CTable[x].port);
    
    I2CEnable(DevI2CTable[x].port);
    
    I2CCmdABORT(DevI2CTable[x].port);
}

void DevI2CIOConfig (DevI2CTypeDef x, DevI2cPinLoctionTypeDef loc)
{
    I2CRouteSet(DevI2CTable[x].port, (I2CLocationTypedef)DevI2CTable[x].pin[loc].loc);
    
    DevGPIOPinConfig(DevI2CTable[x].pin[loc].sda_port, DevI2CTable[x].pin[loc].sda_pin, DEV_GPIO_PIN_MODE_OUT_OD, 
                     DEV_GPIO_PIN_DRIVE_STANDARD, DEV_GPIO_PIN_FRQ_NORMAL);
    
    DevGPIOPinConfig(DevI2CTable[x].pin[loc].scl_port, DevI2CTable[x].pin[loc].scl_pin, DEV_GPIO_PIN_MODE_OUT_OD,
                     DEV_GPIO_PIN_DRIVE_STANDARD, DEV_GPIO_PIN_FRQ_NORMAL);
}

void  DevI2CClockEnable (DevI2CTypeDef x)
{
    if (x == DEV_I2C0)
    {
        CMUHFPeripheralClockEnable(I2C0Clock);
    }
    else if (x == DEV_I2C1)
    {
       CMUHFPeripheralClockEnable(I2C1Clock);
    }
}

void  DevI2CClockDisable (DevI2CTypeDef x)
{
    if (x == DEV_I2C0)
    {
        CMUHFPeripheralClockDisable(I2C0Clock);
    }
    else if (x == DEV_I2C1)
    {
       CMUHFPeripheralClockDisable(I2C1Clock);
    }
}

void DevI2CTxStartAddr (DevI2CTypeDef x, CPU_INT8U addr, DevI2cRWModeType mode)
{
    CPU_INT8U temp;
    //CPU_INT8U data;
    temp = addr << 1;
    
    if (mode == READ)
    {
         temp |= 0x01;
    }
    
    I2CIFClear(DevI2CTable[x].port, IF_ALL);
    
    DevI2cSendCmd (x, CLEARPC);

    DevI2cSendCmd (x, ABORT);
    
    DevI2cSendCmd (x, START);

    DevI2CTxData (x, &temp, 1);
}


void DevI2CTxData (DevI2CTypeDef x, CPU_INT8U *pdata, CPU_INT16U len)
{
    CPU_INT16U i;
    
    for (i = 0; i < len; i++)
    {   
        if (I2CBusholdStateGet(DevI2CTable[x].port) == DEF_ON)
        {
            I2CCmdCONT(DevI2CTable[x].port);
        }
        
        I2CTxdata(DevI2CTable[x].port, pdata[i]);
        while(I2CIFGet(DevI2CTable[x].port) & IF_TXC == DEF_ZERO);
        I2CIFClear(DevI2CTable[x].port, IF_TXC);
       // while(I2CIFGet(DevI2CTable[x].port) & IF_ACK == DEF_ZERO);
        //I2CIFClear(DevI2CTable[x].port, IF_ACK);
    }
}

CPU_BOOL DevI2CSlaverAckFlagGet (DevI2CTypeDef x)
{
    if (I2CIFGet(DevI2CTable[x].port) & IF_ACK)
    {
        return DEF_ON;
    }
    
    return DEF_OFF;
}

void DevI2CIntInit (DevI2CTypeDef x)
{
    CPU_INT8U irq;
    
    for (irq = 0; irq < DEV_I2C_INT_NUM; irq++)
    {
        DevI2cIntRegister(x, (DevI2cIntTypedef)(1 << irq), IntHandlerDefault);
    }
    
    if (x == DEV_I2C0)
    {
        IntVectRegister (INT_I2C0, DevI2c0IntHandler);
        
        DevI2cIrqRegisterFlag[x] = 0;
        
        IntEnable(INT_I2C0);
    }
    else if (x == DEV_I2C1)
    {
        IntVectRegister (INT_I2C1, DevI2c1IntHandler);
        
        DevI2cIrqRegisterFlag[x] = 0;
        
        IntEnable(INT_I2C1);
    }
    
}

void DevI2CIntEnable (DevI2CTypeDef x, DevI2cIntTypedef irq)
{
   I2CIntEnable (DevI2CTable[x].port, (I2CIntFlagTypedef)irq);
}

void DevI2CIntDisable (DevI2CTypeDef x, DevI2cIntTypedef irq)
{
   I2CIntDisable (DevI2CTable[x].port, (I2CIntFlagTypedef)irq);
}

void DevI2cIntRegister (DevI2CTypeDef x, DevI2cIntTypedef irq, FNCT_VOID isr)
{
    DevI2cIntVectTbl[x][DevI2cVectPrioGet(irq)] = isr;
    DevI2cIrqRegisterFlag[x] |=  irq;
}

void DevI2cIntUnregister (DevI2CTypeDef x, DevI2cIntTypedef irq, FNCT_VOID isr)
{
    DevI2cIntVectTbl[x][DevI2cVectPrioGet(irq)] = isr;
    DevI2cIrqRegisterFlag[x] &= ~ irq;
}

void DevI2c0IntHandler(void)
{
    FNCT_VOID isr;
    CPU_INT16U flag;
    CPU_INT16U n;
    DevI2cIntTypedef type;
    
    flag = I2CIFGet(DevI2CTable[DEV_I2C0].port);
    
    flag = flag & DevI2cIrqRegisterFlag[DEV_I2C0]; 

    
    if (flag != DEF_ZERO)
    {
        for (n = 0; n < 16; n++)
        {
           if (flag & (1 << n))
           {
                type =  (DevI2cIntTypedef)(1 << n);
                isr = DevI2cIntVectTbl[DEV_I2C0][DevI2cVectPrioGet(type)];
                isr();
                
                flag &= ~(1 << n);
                
                if (flag == DEF_ZERO)
                {
                    break;
                }
                //I2CIFClear(DevI2CTable[DEV_I2C0].port, (I2CIntFlagTypedef)type);  
           }
        }
    }

}

void DevI2c1IntHandler(void)
{
    FNCT_VOID isr;
    CPU_INT16U flag;
    CPU_INT16U n;
    DevI2cIntTypedef type;
    
    flag = I2CIFGet(DevI2CTable[DEV_I2C1].port);
    
    flag = flag & DevI2cIrqRegisterFlag[DEV_I2C1]; 

    
    if (flag != DEF_ZERO)
    {
        for (n = 0; n < 16; n++)
        {
           if (flag & (1 << n))
           {
                type =  (DevI2cIntTypedef)(1 << n);
                isr = DevI2cIntVectTbl[DEV_I2C1][DevI2cVectPrioGet(type)];
                isr();
                
                flag &= ~(1 << n);
                
                if (flag == DEF_ZERO)
                {
                    break;
                }
                //I2CIFClear(DevI2CTable[DEV_I2C0].port, (I2CIntFlagTypedef)type);  
           }
        }
    }

}

static CPU_INT8U DevI2cVectPrioGet (DevI2cIntTypedef type)
{
    CPU_INT8U n;
    
    type = type;
    
    for (n = 0; n < DEV_I2C_INT_NUM; n++)
    {
         if (type == DevI2cIntVectPrioTb[n])
         {
            break;
         }
    }
    
    return n;
}


CPU_INT8U DevI2CRxData (DevI2CTypeDef x)
{
     return I2CRxdatapGet(DevI2CTable[DEV_I2C0].port);
}

void DevI2cSendCmd (DevI2CTypeDef x, DevI2cCmdTypedef cmd)
{
    I2CSendCmd(DevI2CTable[DEV_I2C0].port,  (CPU_INT8U)cmd);
}