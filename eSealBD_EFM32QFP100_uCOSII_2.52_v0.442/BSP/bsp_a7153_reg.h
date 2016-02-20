/*************************************************************************************************************
*                                                  MODULE                                                    *
*************************************************************************************************************/
#ifndef BSP_A7153_REG_H
#define BSP_A7153_REG_H

#ifdef __cplusplus
extern "C" {
#endif


/*************************************************************************************************************
*                                                 DEFINES                                                    *
*************************************************************************************************************/
#define A7153_REG_ADDR_MODE                     0x00
#define A7153_REG_ADDR_MODECTRL                 0x01
#define A7153_REG_ADDR_MODESEL                  0x02
#define A7153_REG_ADDR_CALIBRATION              0x03
#define A7153_REG_ADDR_PHR                      0x04
#define A7153_REG_ADDR_FIFO                     0x05
#define A7153_REG_ADDR_SFD                      0x06
#define A7153_REG_ADDR_RCOSC1                   0x07
#define A7153_REG_ADDR_RCOSC2                   0x08
#define A7153_REG_ADDR_RCOSC3                   0x09
#define A7153_REG_ADDR_CKO                      0x0A
#define A7153_REG_ADDR_GIO1                     0x0B
#define A7153_REG_ADDR_GIO2                     0x0C
#define A7153_REG_ADDR_XTRPIN                   0x0D
#define A7153_REG_ADDR_DATARATE                 0x0E
#define A7153_REG_ADDR_PLL1                     0x0F
#define A7153_REG_ADDR_TX1                      0x10
#define A7153_REG_ADDR_TX2                      0x11
#define A7153_REG_ADDR_RX                       0x12
#define A7153_REG_ADDR_RXGAIN1                  0x13
#define A7153_REG_ADDR_RXGAIN2                  0x14
#define A7153_REG_ADDR_RXGAIN3                  0x15
#define A7153_REG_ADDR_RXGAIN4                  0x16
#define A7153_REG_ADDR_ADC                      0x17
#define A7153_REG_ADDR_ADCCTRL                  0x18
#define A7153_REG_ADDR_IFCAL1                   0x19
#define A7153_REG_ADDR_VCOCCAL                  0x1A
#define A7153_REG_ADDR_VCOCAL1                  0x1B
#define A7153_REG_ADDR_VCOCAL2                  0x1C
#define A7153_REG_ADDR_VCODEVCAL1               0x1D
#define A7153_REG_ADDR_VCODEVCAL2               0x1E
#define A7153_REG_ADDR_VCOMODDELAY              0x1F
#define A7153_REG_ADDR_CHOFFSET                 0x20
#define A7153_REG_ADDR_BATTERY                  0x21
#define A7153_REG_ADDR_TXTEST                   0x22
#define A7153_REG_ADDR_RXDEM1                   0x23
#define A7153_REG_ADDR_RXDEM2                   0x24
#define A7153_REG_ADDR_CPC                      0x25
#define A7153_REG_ADDR_CRYSTALTEST              0x26
#define A7153_REG_ADDR_PLLTEST                  0x27
#define A7153_REG_ADDR_VCOTEST                  0x28
#define A7153_REG_ADDR_DELAY                    0x29
#define A7153_REG_ADDR_ACKDLY                   0x2A
#define A7153_REG_ADDR_ARTDLY1                  0x2B
#define A7153_REG_ADDR_ARTDLY2                  0x2C
#define A7153_REG_ADDR_CSMA1                    0x2D
#define A7153_REG_ADDR_CSMA2                    0x2E
#define A7153_REG_ADDR_PRETRX                   0x2F
#define A7153_REG_ADDR_INTERRUPT                0x30
#define A7153_REG_ADDR_ADFC                     0x31
#define A7153_REG_ADDR_ADFFRAME                 0x32
#define A7153_REG_ADDR_ADHL                     0x33
#define A7153_REG_ADDR_ACKFRAME                 0x34
#define A7153_REG_ADDR_PNG                      0x35
#define A7153_REG_ADDR_PLL2                     0x36
#define A7153_REG_ADDR_PLL3                     0x37
#define A7153_REG_ADDR_PLL4                     0x38
#define A7153_REG_ADDR_CHGROUP                  0x39
#define A7153_REG_ADDR_RBTO                     0x3A
#define A7153_REG_ADDR_RBT                      0x3B
#define A7153_REG_ADDR_CODE1                    0x3C
#define A7153_REG_ADDR_CODE2                    0x3D
#define A7153_REG_ADDR_CODE3                    0x3E
#define A7153_REG_ADDR_USID                     0x3F

#define A7153_CMD_SLEEP                         0x80    /* 1000,xxxx SLEEP mode                             */
#define A7153_CMD_DSLEEP                        0x88	/* 1110,10xx DEEP SLEEP mode                        */
#define A7153_CMD_IDLE                          0x90	/* 1001,xxxx IDLE mode                              */
#define A7153_CMD_STBY                          0xA0	/* 1010,xxxx Standby mode                           */
#define A7153_CMD_PLL                           0xB0	/* 1011,xxxx PLL mode                               */
#define A7153_CMD_RX                            0xC0	/* 1100,xxxx RX mode                                */
#define A7153_CMD_TX                            0xD0	/* 1101,xxxx TX mode                                */
#define A7153_CMD_LSLEEP                        0xE0	/* 1110,xxxx Low voltage sleep mode                 */
    
#define A7153_OP_WR                             0x00
#define A7153_OP_RD                             0x40

    
/*************************************************************************************************************
*                                               MODULE END                                                   *
*************************************************************************************************************/ 
#ifdef __cplusplus
}
#endif

#endif