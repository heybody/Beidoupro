���     �˿�     ӳ��    Tx       Rx
UART     COM0     LOC0    PC0      PC1      ����2��/GPS
         COM1     LOC0    PC2      PC3      GSM
         COM2     LOC2    PA3      PA4      BLE
	 COM3     LOC3    PE2      PE3      ����1��
	 COM4     LOC0    PD4      PD5      ����D+
	 COM5     LOC0    PC6      PC7      DEBUG
���              ӳ��    ����     ����
SPI��usart0��     LOC0    MOSI     PE10     24L01
                          MISO     PE11
                          CLK      PE12
                 (��ѡ)   CS       PE13    

˵����COM4��COM5�ǵ͹��Ĵ��ڣ�dev_clock.c�пɽ��и���ʱ�Ӻ͵���ʱ���л���

����ʱ��DevClockInit������������´��룺
    CMUHFRCOFrqSet(HFRCO_BAND_14MHZ);
    CMUHFCoreClockSet(HFCORECLK_HFCLK);
    CMUHFCLKSelectSet(HFClkHFRCOSource);                     
    
    CMULFCLKEnable(LFAClock, LFClkHFCoreClkLEDivSource);
    CMULFCLKEnable(LFBClock, LFClkHFCoreClkLEDivSource);
    
    CMULFBLEUART0ClockSet(LFB_LEUART0_LFBCLK_DIV1);
    CMULFBLEUART1ClockSet(LFB_LEUART1_LFBCLK_DIV1);
    CMUHFPERCLKEnable();
    CMUHFCOREClockEnable(LEClock);
����ʱ��DevClockInit������������´��룺
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
ʱ�����DevClockInit������������´��룺
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





