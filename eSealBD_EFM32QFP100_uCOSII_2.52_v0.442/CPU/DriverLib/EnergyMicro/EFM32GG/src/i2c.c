/*************************************************************************************************************
*                                              INCLUDE FILES                                                 *
*************************************************************************************************************/
#include <efm32.h>


/*************************************************************************************************************
*                                            FUNCTION PROTOTYPES                                             *
*************************************************************************************************************/
I2CStateTypedef I2CStateGet (I2CTypedef x)
{
    I2CRegTypeDef *i2c;
    I2CStateTypedef ret;
    
    i2c = (I2CRegTypeDef *)x;
    
    ret = (I2CStateTypedef)(i2c->STATE & I2C_STATE_STATE_MASK);
    
    return ret;
}

CPU_BOOL I2CBusholdStateGet (I2CTypedef x)
{
    I2CRegTypeDef *i2c;
    CPU_BOOL ret;
    
    i2c = (I2CRegTypeDef *)x;
    
    if (i2c->STATE & I2C_STATE_STATE_MASK)
    {
        ret = DEF_ON;
    }
    else
    {
        ret = DEF_OFF;
    }
    return ret;
}

CPU_BOOL I2CNackedStateGet (I2CTypedef x)
{
    I2CRegTypeDef *i2c;
    CPU_BOOL ret;
    
    i2c = (I2CRegTypeDef *)x;
    
    if (i2c->STATE & I2C_STATE_NACKED_MASK)
    {
        ret = DEF_ON;
    }
    else
    {
        ret = DEF_OFF;
    }
    return ret;
}

CPU_BOOL I2CTransmitterStateGet (I2CTypedef x)
{
    I2CRegTypeDef *i2c;
    CPU_BOOL ret;
    
    i2c = (I2CRegTypeDef *)x;
    
    if (i2c->STATE & I2C_STATE_TRANSMITTER_MASK)
    {
        ret = DEF_ON;
    }
    else
    {
        ret = DEF_OFF;
    }
    return ret;
}

CPU_BOOL I2CMasterStateGet (I2CTypedef x)
{
    I2CRegTypeDef *i2c;
    CPU_BOOL ret;
    
    i2c = (I2CRegTypeDef *)x;
    
    if (i2c->STATE & I2C_STATE_MASTER_MASK)
    {
        ret = DEF_ON;
    }
    else
    {
        ret = DEF_OFF;
    }
    return ret;
}

CPU_BOOL I2CBusyStateGet (I2CTypedef x)
{
    I2CRegTypeDef *i2c;
    CPU_BOOL ret;
    
    i2c = (I2CRegTypeDef *)x;
    
    if (i2c->STATE & I2C_STATE_BUSY_MASK)
    {
        ret = DEF_ON;
    }
    else
    {
        ret = DEF_OFF;
    }
    return ret;
}

CPU_BOOL I2CRxdatavStatusGet (I2CTypedef x)
{
    I2CRegTypeDef *i2c;
    CPU_BOOL ret;
    
    i2c = (I2CRegTypeDef *)x;
    
    if (i2c->STATUS & I2C_STATUS_RXDATAV_MASK)
    {
        ret = DEF_ON;
    }
    else
    {
        ret = DEF_OFF;
    }
    return ret;
}

CPU_BOOL I2CTxblStatusGet (I2CTypedef x)
{
    I2CRegTypeDef *i2c;
    CPU_BOOL ret;
    
    i2c = (I2CRegTypeDef *)x;
    
    if (i2c->STATUS & I2C_STATUS_TXBL_MASK)
    {
        ret = DEF_ON;
    }
    else
    {
        ret = DEF_OFF;
    }
    return ret;
}

CPU_BOOL I2CTxcStatusGet (I2CTypedef x)
{
    I2CRegTypeDef *i2c;
    CPU_BOOL ret;
    
    i2c = (I2CRegTypeDef *)x;
    
    if (i2c->STATUS & I2C_STATUS_TXC_MASK)
    {
        ret = DEF_ON;
    }
    else
    {
        ret = DEF_OFF;
    }
    return ret;
}

CPU_BOOL I2CPabortStatusGet (I2CTypedef x)
{
    I2CRegTypeDef *i2c;
    CPU_BOOL ret;
    
    i2c = (I2CRegTypeDef *)x;
    
    if (i2c->STATUS & I2C_STATUS_PABORT_MASK)
    {
        ret = DEF_ON;
    }
    else
    {
        ret = DEF_OFF;
    }
    return ret;
}

CPU_BOOL I2CPcontStatusGet (I2CTypedef x)
{
    I2CRegTypeDef *i2c;
    CPU_BOOL ret;
    
    i2c = (I2CRegTypeDef *)x;
    
    if (i2c->STATUS & I2C_STATUS_PCONT_MASK)
    {
        ret = DEF_ON;
    }
    else
    {
        ret = DEF_OFF;
    }
    return ret;
}

CPU_BOOL I2CPnackStatusGet (I2CTypedef x)
{
    I2CRegTypeDef *i2c;
    CPU_BOOL ret;
    
    i2c = (I2CRegTypeDef *)x;
    
    if (i2c->STATUS & I2C_STATUS_PNACK_MASK)
    {
        ret = DEF_ON;
    }
    else
    {
        ret = DEF_OFF;
    }
    return ret;
}

CPU_BOOL I2CPackStatusGet (I2CTypedef x)
{
    I2CRegTypeDef *i2c;
    CPU_BOOL ret;
    
    i2c = (I2CRegTypeDef *)x;
    
    if (i2c->STATUS & I2C_STATUS_PACK_MASK)
    {
        ret = DEF_ON;
    }
    else
    {
        ret = DEF_OFF;
    }
    return ret;
}

CPU_BOOL I2CPstopStatusGet (I2CTypedef x)
{
    I2CRegTypeDef *i2c;
    CPU_BOOL ret;
    
    i2c = (I2CRegTypeDef *)x;
    
    if (i2c->STATUS & I2C_STATUS_PSTOP_MASK)
    {
        ret = DEF_ON;
    }
    else
    {
        ret = DEF_OFF;
    }
    return ret;
}

CPU_BOOL I2CPstopStartGet (I2CTypedef x)
{
    I2CRegTypeDef *i2c;
    CPU_BOOL ret;
    
    i2c = (I2CRegTypeDef *)x;
    
    if (i2c->STATUS & I2C_STATUS_PSTART_MASK)
    {
        ret = DEF_ON;
    }
    else
    {
        ret = DEF_OFF;
    }
    return ret;
}

CPU_INT16U I2CClkdivGet (I2CTypedef x)
{
    I2CRegTypeDef *i2c;
    CPU_INT16U ret;
    
    i2c = (I2CRegTypeDef *)x;
    
    ret = (I2C_CLKDIV_MASK & i2c->CLKDIV) >> I2C_CLKDIV_DIV_SHIFT;

    return ret;
}

CPU_INT8U I2CSaddrGet (I2CTypedef x)
{
    I2CRegTypeDef *i2c;
    CPU_INT8U ret;
    
    i2c = (I2CRegTypeDef *)x;
    
    ret = (I2C_SADDR_ADDR_MASK & i2c->SADDR) >> I2C_SADDR_ADDR_SHIFT;

    return ret;
}

CPU_INT8U I2CSaddrMaskGet (I2CTypedef x)
{
    I2CRegTypeDef *i2c;
    CPU_INT8U ret;
    
    i2c = (I2CRegTypeDef *)x;
    
    ret = (I2C_SADDRMASK_MASK_MASK & i2c->SADDRMASK) >> I2C_SADDRMASK_MASK_SHIFT;

    return ret;
}

CPU_INT8U I2CRxdataGet (I2CTypedef x)
{
    I2CRegTypeDef *i2c;
    CPU_INT8U ret;
    
    i2c = (I2CRegTypeDef *)x;
    
    ret = (I2C_RXDATA_RXDATA_MASK & i2c->RXDATA) >> I2C_RXDATA_RXDATA_SHIFT;

    return ret;
}

CPU_INT8U I2CRxdatapGet (I2CTypedef x)
{
    I2CRegTypeDef *i2c;
    CPU_INT8U ret;
    
    i2c = (I2CRegTypeDef *)x;
    
    ret = (I2C_RXDATA_RXDATA_MASK & i2c->RXDATA) >> I2C_RXDATA_RXDATA_SHIFT;

    return ret;
}

I2CLocationTypedef I2CRouteGet (I2CTypedef x)
{
    I2CRegTypeDef *i2c;
    I2CLocationTypedef ret;
    
    i2c = (I2CRegTypeDef *)x;
    
    ret = (I2CLocationTypedef)(i2c->ROUTE & I2C_ROUTE_LOCATION_MASK);
    
    return ret;
} 