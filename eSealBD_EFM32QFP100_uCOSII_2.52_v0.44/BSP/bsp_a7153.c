/*************************************************************************************************************
*                                              INCLUDE FILES                                                 *
*************************************************************************************************************/
#include <bsp.h>


/*************************************************************************************************************
*                                                CONSTANTS                                                   *
*************************************************************************************************************/
const CPU_INT16U BspA7153RegCfgValue[]=
{
    0x00,       /* REG_MODE                     */ 
    0x82,       /* REG_MODECTRL                 */         
    0x00,       /* REG_MODESEL                  */
    0x1C,       /* REG_CALIBRATION              */ //00
    0x40,       /* REG_PHR                      */
    0x00,       /* REG_FIFO                     */                      
    0xA7,       /* REG_SFD                      */
    0x3A,       /* REG_RCOSC1:0xE6              */
    0x48,       /* REG_RCOSC2:0x58              */
    0x50,       /* REG_RCOSC3                   */
    0x00,       /* REG_CKO                      *///02
    0xCD,       /* REG_GIO1                     */
    0x05,       /* REG_GIO2                     */
    0x90,       /* REG_XTRPIN                   *///00
    0x9D,       /* REG_DATARATE                 */
    0x64,       /* REG_PLL1                     */
    0x17,       /* REG_TX1                      */
    0x40,       /* REG_TX2                      */
    0x50,       /* REG_RX                       */
    0x00,       /* REG_RXGAIN1                  */
    0x00,       /* REG_RXGAIN2                  *///80
    0x19,       /* REG_RXGAIN3                  */
    0x0B,       /* REG_RXGAIN4                  *///8A
    0x00,       /* REG_ADC                      */
    0x63,       /* REG_ADCCTRL                  */
    0x07,       /* REG_IFCAL1                   */
    0x44,       /* REG_VCOCCAL                  */
    0x44,       /* REG_VCOCAL1                  */
    0x80,       /* REG_VCOCAL2                  */
    0x30,       /* REG_VCODEVCAL1               */
    0x19,       /* REG_VCODEVCAL2               *///1B
    0x03,       /* REG_VCOMODDELAY              */
    0x37,       /* REG_CHOFFSET                 */
    0x40,       /* REG_BATTERY                  *///44
    0x06,       /* REG_TXTEST                   */
    0x16,       /* REG_RXDEM1                   */
    0x80,       /* REG_RXDEM2                   */
    0xF3,       /* REG_CPC                      */
    0xEB,       /* REG_CRYSTALTEST:0xE5         */
    0x51,       /* REG_PLLTEST                  */
    0x02,       /* REG_VCOTEST                  */
    0xF4,       /* REG_DELAY:0xF4               *///54
    0x18,       /* REG_ACKDLY                   */
    0x08,       /* REG_ARTDLY1                  */
    0x1D,       /* REG_ARTDLY2                  */
    0x64,	/* REG_CSMA1                    */
    0x53,       /* REG_CSMA2                    */
    0x00,       /* REG_PRETRX                   */
    0x10,       /* REG_INTERRUPT                */

    0x0080,     /* REG_ADFC                     *///7C80
    0x0000,     /* REG_ADFFRAME                 */         
    0x0000,     /* REG_ADHL                     */
    0x0200,     /* REG_ACKFRAME                 */
    0x7153,     /* REG_PNG                      */
    0x0096,     /* REG_PLL2                     */                      
    0x0004,     /* REG_PLL3                     */
    0x0800,     /* REG_PLL4                     */
    0x3C78,     /* REG_CHGROUP                  */
};

const BspA7153DeveiceTypeDef BspA7153Deveice[BSP_A7153_NUM] = 
{
    {
        .scs_pin   = BSP_A7153_0_SCS_PIN,\
        .scs_port  = BSP_A7153_0_SCS_PORT,\
        .gio2_pin  = BSP_A7153_0_GIO2_PIN,\
        .gio2_port = BSP_A7153_0_GIO2_PORT,\
        .spi       = DEV_SPI0
    }
};

const CPU_INT8U BspA7153PowerLevel[BSP_A7153_POWER_LEVEL] = 
{
    0x00,       /* Power: -12.48dB, Current: 10.49mA */
    0x08,       /* Power: -9.82dB,  Current: 11.23mA */
    0x08,       /* Power: -9.82dB,  Current: 11.23mA */
    0x20,       /* Power: -9.78dB,  Current: 10.92mA */
    0x10,       /* Power: -7.91dB,  Current: 12.48mA */
    0x18,       /* Power: -6.72dB,  Current: 15.75mA */
    0x30,       /* Power: -5.89dB,  Current: 13.32mA */
    0x28,       /* Power: -4.96dB,  Current: 11.81mA */
    0x11,       /* Power: -3.75dB,  Current: 12.83mA */
    0x0A,       /* Power: -2.98dB,  Current: 12.36mA */
    0x31,       /* Power: -1.93dB,  Current: 13.81mA */
    0x2A,       /* Power: -1.12dB,  Current: 13.27mA */
    0x06,       /* Power:  0.18dB,  Current: 13.60mA */
    0x2C,       /* Power:  1.07dB,  Current: 14.62mA */
    0x3B,       /* Power:  2.03dB,  Current: 18.39mA */
    0x37,       /* Power:  3.13dB,  Current: 17.21mA */
    0x3F,       /* Power:  3.90dB,  Current: 19.90mA */
};

/*************************************************************************************************************
*                                              LOCAL TABLES                                                  *
*************************************************************************************************************/
static CPU_INT8U BspA7153Power[BSP_A7153_NUM];


/*************************************************************************************************************
*                                            FUNCTION PROTOTYPES                                             *
*************************************************************************************************************/
CPU_BOOL BspA7153Init (BspA7153TypeDef n, CPU_INT8U sfd, CPU_INT8U ch)
{   
    BspA7153IOCfg(n);
    DevSPIClockEnable(BspA7153Deveice[n].spi);
    DevSPIIOConfig(BspA7153Deveice[n].spi, DEV_SPI_PIN_LOC0, DEF_OFF);
    DevSPIInit(BspA7153Deveice[n].spi, DEV_SPI_BIT_8, DEV_SPI_CLOCK_MODE0, 
               DEV_SPI_MSBF_MSB, DEV_SPI_MASTER, 6000000, DEF_OFF);
    
    BspA7153Reset(n);
    BspA7153SetSFD(n, sfd);
    BspA7153RegCfg(n);
    BspA7125Cal(n);
    
    BspA7153Power[n] = 12;
    
    BspA7153SetCH(n, ch);
 
    if (ch != BspA7153GetCH(n))
    {
        return DEF_FALSE;
    }
    
    BspA7153StrobeCMD(n, A7153_CMD_STBY);
    
    return DEF_TRUE;
}

void BspA7153IOCfg (BspA7153TypeDef n)
{  
    DevGPIOPinConfig(BspA7153Deveice[n].scs_port, BspA7153Deveice[n].scs_pin, DEV_GPIO_PIN_MODE_OUT_PP, 
                     DEV_GPIO_PIN_DRIVE_STANDARD, DEV_GPIO_PIN_FRQ_NORMAL);
    DevGPIOPinConfig(BspA7153Deveice[n].gio2_port, BspA7153Deveice[n].gio2_pin, DEV_GPIO_PIN_MODE_IN, 
                     DEV_GPIO_PIN_DRIVE_STANDARD, DEV_GPIO_PIN_FRQ_NORMAL);
}

void BspA7153SCSH (BspA7153TypeDef n)
{
    DevGPIOPinOutSet(BspA7153Deveice[n].scs_port, BspA7153Deveice[n].scs_pin);
}

void BspA7153SCSL (BspA7153TypeDef n)
{
    DevGPIOPinOutClear(BspA7153Deveice[n].scs_port, BspA7153Deveice[n].scs_pin);
}

void BspA7153Reset (BspA7153TypeDef n)
{
    BspA7153WrReg8Bit(n, A7153_REG_ADDR_MODE, 0x80);
}

void BspA7153SetSFD (BspA7153TypeDef n, CPU_INT8U sfd)
{
    BspA7153WrReg8Bit(n, A7153_REG_ADDR_SFD, sfd);
}

void BspA7153SetCH (BspA7153TypeDef n, CPU_INT8U ch)
{
    BspA7153WrReg8Bit(n, A7153_REG_ADDR_PLL1, ch * 2);
}

CPU_INT8U BspA7153GetCH (BspA7153TypeDef n)
{
    CPU_INT8U ch;
    
    ch = BspA7153RdReg8Bit(n, A7153_REG_ADDR_PLL1);
    
    return ch / 2;

}

CPU_BOOL BspA7153PowerSet (BspA7153TypeDef n, CPU_INT8U power)
{
    if (power > BSP_A7153_POWER_LEVEL)
    {
        return DEF_FALSE;
    }
    
    BspA7153WrReg8Bit(n, A7153_REG_ADDR_TXTEST, BspA7153PowerLevel[power]);
    
    BspA7153Power[n] = power;
    
    return DEF_TRUE;
}

CPU_INT8U BspA7153PowerGet (BspA7153TypeDef n)
{
    return BspA7153Power[n];
}

void BspA7153SetPayloadLen (BspA7153TypeDef n, CPU_INT8U payload_len)
{
    BspA7153WrReg8Bit(n, A7153_REG_ADDR_PHR, payload_len);
}

void BspA7153WriteReset (BspA7153TypeDef n)
{
    BspA7153WrReg8Bit(n, A7153_REG_ADDR_MODE, DEF_BIT6);
}

void BspA7153ReadReset (BspA7153TypeDef n)
{
    BspA7153WrReg8Bit(n, A7153_REG_ADDR_MODE, DEF_BIT5);
}

void BspA7153FIFOClear (BspA7153TypeDef n)
{
    BspA7153WrReg8Bit(n, A7153_REG_ADDR_MODE, DEF_BIT3);
}

CPU_INT8U BspA7153GetRN (BspA7153TypeDef n)
{
    return BspA7153RdReg16Bit(n, A7153_REG_ADDR_PNG);
}

void BspA7153RegCfg (BspA7153TypeDef n)
{
    CPU_INT8U reg;
        
    for (reg = A7153_REG_ADDR_MODECTRL; reg <= A7153_REG_ADDR_PHR; reg++)
    {
        BspA7153WrReg8Bit(n, reg, BspA7153RegCfgValue[reg]);
    }
        
    for (reg = A7153_REG_ADDR_SFD; reg <= A7153_REG_ADDR_RXGAIN1; reg++)
    {
        BspA7153WrReg8Bit(n, reg, BspA7153RegCfgValue[reg]);
    }
        
    for (reg = A7153_REG_ADDR_RXGAIN3; reg <= A7153_REG_ADDR_INTERRUPT; reg++)
    {
        BspA7153WrReg8Bit(n, reg, BspA7153RegCfgValue[reg]);
    }
    
    BspA7153WrReg16Bit(n, reg, BspA7153RegCfgValue[reg]);
    
    for (reg = A7153_REG_ADDR_ADHL; reg <= A7153_REG_ADDR_CHGROUP; reg++)
    {
        BspA7153WrReg16Bit(n, reg, BspA7153RegCfgValue[reg]);
    }
}

void BspA7153StrobeCMD (BspA7153TypeDef n, CPU_INT8U cmd)
{
    BspA7153SCSL(n);
    DevSPITxData(BspA7153Deveice[n].spi, &cmd, 1); 
    BspA7153SCSH(n);
}

void BspA7153WrReg8Bit (BspA7153TypeDef n, CPU_INT8U reg, CPU_INT8U value)
{
    CPU_INT8U temp;
    temp = reg | A7153_OP_WR;
    
    BspA7153SCSL(n);
    DevSPITxData(BspA7153Deveice[n].spi, &temp, 1);
    DevSPITxData(BspA7153Deveice[n].spi, &value, 1);
    BspA7153SCSH(n);
}

CPU_INT8U BspA7153RdReg8Bit (BspA7153TypeDef n, CPU_INT8U reg)
{
    CPU_INT8U value;
    CPU_INT8U temp;
    temp = reg | A7153_OP_RD;
          
    BspA7153SCSL(n);
    DevSPITxData(BspA7153Deveice[n].spi, &temp, 1);
    DevSPIRxData(BspA7153Deveice[n].spi, &value, 1);
    BspA7153SCSH(n);
        
    return value;
}

void BspA7153WrReg16Bit (BspA7153TypeDef n, CPU_INT8U reg, CPU_INT16U value)
{
    CPU_INT8U temp;
    temp = reg | A7153_OP_WR;
    
    BspA7153SCSL(n); 
    DevSPITxData(BspA7153Deveice[n].spi, &temp, 1);
    temp = (CPU_INT8U)(value >> 8);
    DevSPITxData(BspA7153Deveice[n].spi, &temp, 1);
    temp = (CPU_INT8U)value;
    DevSPITxData(BspA7153Deveice[n].spi, &temp, 1);
    BspA7153SCSH(n);
}

CPU_INT16U BspA7153RdReg16Bit (BspA7153TypeDef n, CPU_INT8U reg)
{
    CPU_INT8U temp;
    CPU_INT16U value; 
    temp = reg | A7153_OP_RD;
          
    BspA7153SCSL(n);
    DevSPITxData(BspA7153Deveice[n].spi, &temp, 1);
    DevSPIRxData(BspA7153Deveice[n].spi, &temp, 1);
    value = (temp << 8) & 0xFF00;
    DevSPIRxData(BspA7153Deveice[n].spi, &temp, 1);
    value |= temp;
    BspA7153SCSH(n);
        
    return value;
}

void BspA7153WrFIFO (BspA7153TypeDef n, CPU_INT8U *pdata, CPU_INT32U len)
{
    CPU_INT8U temp;
    temp = A7153_REG_ADDR_FIFO | A7153_OP_WR;
    BspA7153WriteReset(n);
    
    BspA7153SCSL(n);
    DevSPITxData(BspA7153Deveice[n].spi, &temp, 1);
    DevSPITxData(BspA7153Deveice[n].spi, pdata, len);
    BspA7153SCSH(n);
}

void BspA7153RdFIFO (BspA7153TypeDef n, CPU_INT8U *pdata, CPU_INT32U len)
{  
    CPU_INT8U temp;
    temp = A7153_REG_ADDR_FIFO | A7153_OP_RD;
    BspA7153ReadReset(n);
    
    BspA7153SCSL(n);
    DevSPITxData(BspA7153Deveice[n].spi, &temp, 1);
    DevSPIRxData(BspA7153Deveice[n].spi, pdata, len);
    BspA7153SCSH(n);
}

void BspA7125Cal (BspA7153TypeDef n)
{
    CPU_INT8U tmp;
    CPU_INT8U fb, fbcf, adag, vb, vbcf, vcb, vccf, deva, adev;
    CPU_INT8U rh, rl, ru;

    BspA7153StrobeCMD(n, A7153_CMD_STBY);               
    
    BspA7153WrReg8Bit(n, A7153_REG_ADDR_CALIBRATION, 0x02);  /* calibration IF procedure   */
    do
    {
        tmp = BspA7153RdReg8Bit(n, A7153_REG_ADDR_CALIBRATION);
        tmp &= 0x02;
    }
    while (tmp);

    BspA7153WrReg8Bit(n, A7153_REG_ADDR_CALIBRATION, 0x01);  /* calibration RSSI procedure */
    do
    {
        tmp = BspA7153RdReg8Bit(n, A7153_REG_ADDR_CALIBRATION);
        tmp &= 0x01;
    }
    while (tmp);

    BspA7153StrobeCMD(n, A7153_CMD_PLL);  /* calibration VDC,VBC procedure    */
    BspA7153CHGroupCal(n, 30);      /* calibrate channel group Bank I   */
    BspA7153CHGroupCal(n, 90);      /* calibrate channel group Bank II  */
    BspA7153CHGroupCal(n, 150);     /* calibrate channel group Bank III */
    
    BspA7153StrobeCMD(n, A7153_CMD_STBY); 

    tmp = BspA7153RdReg8Bit(n, A7153_REG_ADDR_IFCAL1);    /* for check    */
    fb = tmp & 0x0F;
    fbcf = (tmp >> 4) & 0x01;

    tmp = BspA7153RdReg8Bit(n, A7153_REG_ADDR_RXGAIN2);
    rh = tmp;

    tmp = BspA7153RdReg8Bit(n, A7153_REG_ADDR_RXGAIN3);
    rl = tmp;

    tmp = BspA7153RdReg8Bit(n, A7153_REG_ADDR_RXGAIN4);
    ru = tmp;

    tmp = BspA7153RdReg8Bit(n, A7153_REG_ADDR_VCOCAL1);
    vb = tmp & 0x07;
    vbcf = (tmp >> 3) & 0x01;

    tmp = BspA7153RdReg8Bit(n, A7153_REG_ADDR_VCOCAL2);
    adag = tmp;

    tmp = BspA7153RdReg8Bit(n, A7153_REG_ADDR_VCOCCAL);
    vcb = tmp & 0x0F;
    vccf= (tmp >> 4) & 0x01;

    tmp = BspA7153RdReg8Bit(n, A7153_REG_ADDR_VCODEVCAL1);
    deva = tmp & 0xFF;

    tmp = BspA7153RdReg8Bit(n, A7153_REG_ADDR_VCODEVCAL2);
    adev = tmp & 0xFF;

    BspA7153WrReg8Bit(n, A7153_REG_ADDR_CALIBRATION, 0x20);  /* calibration RC_OSC procedure                    */     
    do
    {
        tmp = BspA7153RdReg8Bit(n, A7153_REG_ADDR_CALIBRATION);
        tmp &= 0x20;
    }
    while (tmp);

    if (vbcf || fbcf || vccf)
    {
        while (DEF_TRUE);
    }
    
    fb = fb;
    adag = adag;
    vb = vb;
    vcb = vcb;
    deva = deva;
    adev = adev;
    rh = rh;
    rl = rl;
    ru = ru;
}


void BspA7153CHGroupCal (BspA7153TypeDef n, CPU_INT8U ch)
{
    CPU_INT8U tmp;
    CPU_INT8U vb, vbcf;
    CPU_INT8U vcb, vccf;
    CPU_INT8U deva, adev;

    BspA7153WrReg8Bit(n, A7153_REG_ADDR_PLL1, ch);
    BspA7153WrReg8Bit(n, A7153_REG_ADDR_CALIBRATION, 0x1C);
    do
    {
        tmp = BspA7153RdReg8Bit(n, A7153_REG_ADDR_CALIBRATION);
        tmp &= 0x1C;
    }
    while (tmp);

    tmp = BspA7153RdReg8Bit(n, A7153_REG_ADDR_VCOCAL1);      /* for check */
    vb = tmp & 0x07;
    vbcf = (tmp >> 3) & 0x01;

    tmp = BspA7153RdReg8Bit(n, A7153_REG_ADDR_VCOCCAL);
    vcb = tmp & 0x0F;
    vccf= (tmp >> 4) & 0x01;

    tmp = BspA7153RdReg8Bit(n, A7153_REG_ADDR_VCODEVCAL1);
    deva = tmp;

    tmp = BspA7153RdReg8Bit(n, A7153_REG_ADDR_VCODEVCAL2);
    adev = tmp;

    if (vbcf || vccf)
    {
        while (DEF_TRUE);
    }
    
    vb = vb;
    vcb = vcb;
    deva = deva;
    adev = adev;
}


/*************************************************************************************************************
*                                               MODULE END                                                   *
*************************************************************************************************************/