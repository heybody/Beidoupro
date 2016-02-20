类别     端口     映射    Tx       Rx
UART     COM0     LOC0    PC0      PC1      北斗2代/GPS
         COM1     LOC0    PC2      PC3      GSM
         COM2     LOC2    PA3      PA4      BLE
	 COM3     LOC3    PE2      PE3      北斗1代
	 COM4     LOC0    PD4      PD5      海事D+
	 COM5     LOC0    PC6      PC7      DEBUG
类别              映射    类型     引脚
SPI（usart0）     LOC0    MOSI     PE10     24L01
                          MISO     PE11
                          CLK      PE12
                 (可选)   CS       PE13    

说明：COM4和COM5是低功耗串口，dev_clock.c中可进行高速时钟和低速时钟切换：

高速时钟DevClockInit函数需添加以下代码：
    CMUHFRCOFrqSet(HFRCO_BAND_14MHZ);
    CMUHFCoreClockSet(HFCORECLK_HFCLK);
    CMUHFCLKSelectSet(HFClkHFRCOSource);                     
    
    CMULFCLKEnable(LFAClock, LFClkHFCoreClkLEDivSource);
    CMULFCLKEnable(LFBClock, LFClkHFCoreClkLEDivSource);
    
    CMULFBLEUART0ClockSet(LFB_LEUART0_LFBCLK_DIV1);
    CMULFBLEUART1ClockSet(LFB_LEUART1_LFBCLK_DIV1);
    CMUHFPERCLKEnable();
    CMUHFCOREClockEnable(LEClock);
低速时钟DevClockInit函数需添加以下代码：
    CMUOscillatorEnable(OscLFRCO);
    
    //CMUHFCLKSelectSet(HFClkHFRCOSource);
    //CMUHFRCOFrqSet(HFRCO_BAND_28MHZ);
    CMUHFCoreClockSet(HFCORECLK_HFCLK);
    CMULFCLKEnable(LFAClock, LFClkLFRCOSource);
    CMULFCLKEnable(LFBClock, LFClkHFCoreClkLEDivSource);
    CMULFBLEUART0ClockSet(LFB_LEUART0_LFBCLK_DIV1);
    
    CMULFCLKEnable(LFAClock, LFClkLFRCOSource);
    CMULFCLKEnable(LFBClock, LFClkLFRCOSource);
    
    CMUHFPERCLKEnable();
    CMUHFCOREClockEnable(LEClock);
时钟输出DevClockInit函数需添加以下代码：
    CMUOscillatorEnable(OscLFRCO);
    CMUHFCoreClockSet(HFCORECLK_HFCLK);
    CMULFCLKEnable(LFAClock, LFClkLFRCOSource);
    CMULFCLKEnable(LFBClock, LFClkHFCoreClkLEDivSource);
    CMULFBLEUART0ClockSet(LFB_LEUART0_LFBCLK_DIV1);
    
    CMULFCLKEnable(LFAClock, LFClkLFRCOSource);
    CMULFCLKEnable(LFBClock, LFClkLFRCOSource);
    
    CMUCLKOUTLocationSet(CLKOUT0_LOC0);
    CMUCLKOUT0Sel(CLKOUT0_SEL_HFRCO);
    CMUCLKOUT1Sel(CLKOUT1_SEL_LFRCO);
    CMUCLKOUTPinEnable (CLKOUT0_PIN);
    CMUCLKOUTPinEnable (CLKOUT1_PIN);
    
    CMUHFPERCLKEnable();
    CMUHFCOREClockEnable(LEClock);





