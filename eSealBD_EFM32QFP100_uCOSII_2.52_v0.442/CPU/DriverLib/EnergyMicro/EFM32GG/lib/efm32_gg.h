/*************************************************************************************************************
*                                                  MODULE                                                    *
*************************************************************************************************************/
#ifndef EFM32_GG_H
#define EFM32_GG_H

#ifdef __cplusplus
extern "C" {
#endif

    
/*************************************************************************************************************
*                                                 DEFINES                                                    *
*************************************************************************************************************/
#define FLASH_START_BASE                        (0x00000000UL)
#define FLASH_SIZE                              (1024UL * 1024UL)  
    
#define MSC_BASE                                (0x400C0000UL)  /* MSC base address                         */
#define EMU_BASE                                (0x400C6000UL)  /* EMU base address                         */
#define RMU_BASE                                (0x400CA000UL)  /* RMU base address                         */
#define CMU_BASE                                (0x400C8000UL)  /* CMU base address                         */
#define AES_BASE                                (0x400E0000UL)  /* AES base address                         */
#define EBI_BASE                                (0x40008000UL)  /* EBI base address                         */
#define GPIO_BASE                               (0x40006000UL)  /* GPIO base address                        */
#define PRS_BASE                                (0x400CC000UL)  /* PRS base address                         */
#define DMA_BASE                                (0x400C2000UL)  /* DMA base address                         */
#define TIMER0_BASE                             (0x40010000UL)  /* TIMER0 base address                      */
#define TIMER1_BASE                             (0x40010400UL)  /* TIMER1 base address                      */
#define TIMER2_BASE                             (0x40010800UL)  /* TIMER2 base address                      */
#define USART0_BASE                             (0x4000C000UL)  /* USART0 base address                      */
#define USART1_BASE                             (0x4000C400UL)  /* USART1 base address                      */
#define USART2_BASE                             (0x4000C800UL)  /* USART2 base address                      */
#define UART0_BASE                              (0x4000E000UL)  /* UART0 base address                       */
#define UART1_BASE                              (0x4000E400UL)  /* UART1 base address                       */
#define LEUART0_BASE                            (0x40084000UL)  /* LEUART0 base address                     */
#define LEUART1_BASE                            (0x40084400UL)  /* LEUART1 base address                     */
#define LETIMER0_BASE                           (0x40082000UL)  /* LETIMER0 base address                    */
#define PCNT0_BASE                              (0x40086000UL)  /* PCNT0 base address                       */
#define PCNT1_BASE                              (0x40086400UL)  /* PCNT1 base address                       */
#define PCNT2_BASE                              (0x40086800UL)  /* PCNT2 base address                       */
#define I2C0_BASE                               (0x4000A000UL)  /* I2C0 base address                        */
#define I2C1_BASE                               (0x4000A400UL)  /* I2C1 base address                        */
#define ADC0_BASE                               (0x40002000UL)  /* ADC0 base address                        */
#define DAC0_BASE                               (0x40004000UL)  /* DAC0 base address                        */
#define ACMP0_BASE                              (0x40001000UL)  /* ACMP0 base address                       */
#define ACMP1_BASE                              (0x40001400UL)  /* ACMP1 base address                       */
#define VCMP_BASE                               (0x40000000UL)  /* VCMP base address                        */
#define LCD_BASE                                (0x4008A000UL)  /* LCD base address                         */
#define RTC_BASE                                (0x40080000UL)  /* RTC base address                         */
#define WDOG_BASE                               (0x40088000UL)  /* WDOG base address                        */
#define CALIBRATE_BASE                          (0x0FE08000UL)  /* CALIBRATE base address                   */
#define DEVINFO_BASE                            (0x0FE081B0UL)  /* DEVINFO base address                     */
#define ROMTABLE_BASE                           (0xE00FFFD0UL)  /* ROMTABLE base address                    */    
    

/*************************************************************************************************************
*                                                  DATA TYPES                                                *
*************************************************************************************************************/
typedef struct
{
    DEF_IO CPU_INT32U CTRL;         /* Memory System Control Register                                       */
    DEF_IO CPU_INT32U READCTRL;     /* Read Control Register                                                */
    DEF_IO CPU_INT32U WRITECTRL;    /*  Write Control Register                                              */
    DEF_IO CPU_INT32U WRITECMD;     /* Write Command Register                                               */
    DEF_IO CPU_INT32U ADDRB;        /* Page Erase/Write Address Buffer                                      */
           CPU_INT32U RESERVED0[1]; /* Reserved for future use                                              */
    DEF_IO CPU_INT32U WDATA;        /* Write Data Register                                                  */
    DEF_I  CPU_INT32U STATUS;       /* Status Register                                                      */
           CPU_INT32U RESERVED1[3]; /* Reserved for future use                                              */
    DEF_I  CPU_INT32U IF;           /* Interrupt Flag Register                                              */
    DEF_IO CPU_INT32U IFS;          /* Interrupt Flag Set Register                                          */
    DEF_IO CPU_INT32U IFC;          /* Interrupt Flag Clear Register                                        */
    DEF_IO CPU_INT32U IEN;          /* Interrupt Enable Register                                            */
    DEF_IO CPU_INT32U LOCK;         /* Configuration Lock Register                                          */
    DEF_IO CPU_INT32U CMD;          /* Command Register                                                     */
    DEF_I  CPU_INT32U CACHEHITS;    /* Cache Hits Performance Counter                                       */
    DEF_I  CPU_INT32U CACHEMISSES;  /* Cache Misses Performance Counter                                     */
           CPU_INT32U RESERVED2[1]; /* Reserved for future use                                              */
    DEF_IO CPU_INT32U TIMEBASE;     /* Flash Write and Erase Timebase                                       */
} MSCRegTypeDef;

typedef struct
{
    DEF_IO CPU_INT32U CTRL;         /* Control Register                                                     */
    DEF_IO CPU_INT32U MEMCTRL;      /* Memory Control Register                                              */
    DEF_IO CPU_INT32U LOCK;         /* Configuration Lock Register                                          */
           CPU_INT32U RESERVED0[6]; /* Reserved for future use                                              */
    DEF_IO CPU_INT32U AUXCTRL;      /* Auxiliary Control Register                                           */
} EMURegTypeDef;   

typedef struct
{
    DEF_IO CPU_INT32U CTRL;         /* CMU Control Register                                                 */
    DEF_IO CPU_INT32U HFCORECLKDIV; /* High Frequency Core Clock Division Register                          */
    DEF_IO CPU_INT32U HFPERCLKDIV;  /* High Frequency Peripheral Clock Division Register                    */
    DEF_IO CPU_INT32U HFRCOCTRL;    /* HFRCO Control Register                                               */
    DEF_IO CPU_INT32U LFRCOCTRL;    /* LFRCO Control Register                                               */
    DEF_IO CPU_INT32U AUXHFRCOCTRL; /* AUXHFRCO Control Register                                            */
    DEF_IO CPU_INT32U CALCTRL;      /* Calibration Control Register                                         */
    DEF_IO CPU_INT32U CALCNT;       /* Calibration Counter Register                                         */
    DEF_IO CPU_INT32U OSCENCMD;     /* Oscillator Enable/Disable Command Register                           */
    DEF_IO CPU_INT32U CMD;          /* Command Register                                                     */
    DEF_IO CPU_INT32U LFCLKSEL;     /* Low Frequency Clock Select Register                                  */
    DEF_I  CPU_INT32U STATUS;       /* Status Register                                                      */
    DEF_I  CPU_INT32U IF;           /* Interrupt Flag Register                                              */
    DEF_IO CPU_INT32U IFS;          /* Interrupt Flag Set Register                                          */
    DEF_IO CPU_INT32U IFC;          /* Interrupt Flag Clear Register                                        */
    DEF_IO CPU_INT32U IEN;          /* Interrupt Enable Register                                            */
    DEF_IO CPU_INT32U HFCORECLKEN0; /* High Frequency Core Clock Enable Register 0                          */
    DEF_IO CPU_INT32U HFPERCLKEN0;  /* High Frequency Peripheral Clock Enable Register 0                    */
           CPU_INT32U RESERVED0[2]; /* Reserved for future use                                              */
    DEF_I  CPU_INT32U SYNCBUSY;     /* Synchronization Busy Register                                        */
    DEF_IO CPU_INT32U FREEZE;       /* Freeze Register                                                      */
    DEF_IO CPU_INT32U LFACLKEN0;    /* Low Frequency A Clock Enable Register 0  (Async Reg)                 */
           CPU_INT32U RESERVED1[1]; /* Reserved for future use                                              */
    DEF_IO CPU_INT32U LFBCLKEN0;    /* Low Frequency B Clock Enable Register 0 (Async Reg)                  */
           CPU_INT32U RESERVED2[1]; /* Reserved for future use                                              */
    DEF_IO CPU_INT32U LFAPRESC0;    /* Low Frequency A Prescaler Register 0 (Async Reg)                     */
           CPU_INT32U RESERVED3[1]; /* Reserved for future use                                              */
    DEF_IO CPU_INT32U LFBPRESC0;    /* Low Frequency B Prescaler Register 0  (Async Reg)                    */
           CPU_INT32U RESERVED4[1]; /* Reserved for future use                                              */
    DEF_IO CPU_INT32U PCNTCTRL;     /* PCNT Control Register                                                */
    DEF_IO CPU_INT32U LCDCTRL;      /* LCD Control Register                                                 */
    DEF_IO CPU_INT32U ROUTE;        /* I/O Routing Register                                                 */
    DEF_IO CPU_INT32U LOCK;         /* Configuration Lock Register                                          */
} CMURegTypeDef;

typedef struct
{
    DEF_IO CPU_INT32U CTRL;     /* Port Control Register                                                    */
    DEF_IO CPU_INT32U MODEL;    /* Port Pin Mode Low Register                                               */
    DEF_IO CPU_INT32U MODEH;    /* Port Pin Mode High Register                                              */
    DEF_IO CPU_INT32U DOUT;     /* Port Data Out Register                                                   */
    DEF_O  CPU_INT32U DOUTSET;  /* Port Data Out Set Register                                               */
    DEF_O  CPU_INT32U DOUTCLR;  /* Port Data Out Clear Register                                             */
    DEF_O  CPU_INT32U DOUTTGL;  /* Port Data Out Toggle Register                                            */
    DEF_I  CPU_INT32U DIN;      /* Port Data In Register                                                    */
    DEF_IO CPU_INT32U PINLOCKN; /* Port Unlocked Pins Register                                              */
} GPIOPortRegTypeDef;

typedef struct
{
    GPIOPortRegTypeDef PORT[6];         /* Port configuration bits                                          */
           CPU_INT32U RESERVED0[10];    /* Reserved for future use                                          */
    DEF_IO CPU_INT32U EXTIPSELL;        /* External Interrupt Port Select Low Register                      */
    DEF_IO CPU_INT32U EXTIPSELH;        /* External Interrupt Port Select High Register                     */
    DEF_IO CPU_INT32U EXTIRISE;         /* External Interrupt Rising Edge Trigger Register                  */
    DEF_IO CPU_INT32U EXTIFALL;         /* External Interrupt Falling Edge Trigger Register                 */
    DEF_IO CPU_INT32U IEN;              /* Interrupt Enable Register                                        */
    DEF_I  CPU_INT32U IF;               /* Interrupt Flag Register                                          */
    DEF_IO CPU_INT32U IFS;              /* Interrupt Flag Set Register                                      */
    DEF_IO CPU_INT32U IFC;              /* Interrupt Flag Clear Register                                    */
    DEF_IO CPU_INT32U ROUTE;            /* I/O Routing Register                                             */
    DEF_IO CPU_INT32U INSENSE;          /* Input Sense Register                                             */
    DEF_IO CPU_INT32U LOCK;             /* Configuration Lock Register                                      */
    DEF_IO CPU_INT32U CTRL;             /* GPIO Control Register                                            */
    DEF_IO CPU_INT32U CMD;              /* EM4 Wake-up Clear Register                                       */
    DEF_IO CPU_INT32U EM4WUEN;          /* EM4 Wake-up Enable Register                                      */
    DEF_IO CPU_INT32U EM4WUPOL;         /* EM4 Wake-up Polarity Register                                    */
    DEF_I  CPU_INT32U EM4WUCAUSE;       /* EM4 Wake-up Cause Register                                       */
} GPIORegTypeDef;

typedef struct
{
    DEF_IO CPU_INT32U CTRL;         /* Control Register                                                     */
    DEF_IO CPU_INT32U FRAME;        /* USART Frame Format Register                                          */
    DEF_IO CPU_INT32U TRIGCTRL;     /* USART Trigger Control register                                       */
    DEF_IO CPU_INT32U CMD;          /* Command Register                                                     */
    DEF_I CPU_INT32U  STATUS;       /* USART Status Register                                                */
    DEF_IO CPU_INT32U CLKDIV;       /* Clock Control Register                                               */
    DEF_I CPU_INT32U  RXDATAX;      /* RX Buffer Data Extended Register                                     */
    DEF_I CPU_INT32U  RXDATA;       /* RX Buffer Data Register                                              */
    DEF_I CPU_INT32U  RXDOUBLEX;    /* RX Buffer Double Data Extended Register                              */
    DEF_I CPU_INT32U  RXDOUBLE;     /* RX FIFO Double Data Register                                         */
    DEF_I CPU_INT32U  RXDATAXP;     /* RX Buffer Data Extended Peek Register                                */
    DEF_I CPU_INT32U  RXDOUBLEXP;   /* RX Buffer Double Data Extended Peek Register                         */
    DEF_IO CPU_INT32U TXDATAX;      /* TX Buffer Data Extended Register                                     */
    DEF_IO CPU_INT32U TXDATA;       /* TX Buffer Data Register                                              */
    DEF_IO CPU_INT32U TXDOUBLEX;    /* TX Buffer Double Data Extended Register                              */
    DEF_IO CPU_INT32U TXDOUBLE;     /* TX Buffer Double Data Register                                       */
    DEF_I CPU_INT32U  IF;           /* Interrupt Flag Register                                              */
    DEF_IO CPU_INT32U IFS;          /* Interrupt Flag Set Register                                          */
    DEF_IO CPU_INT32U IFC;          /* Interrupt Flag Clear Register                                        */
    DEF_IO CPU_INT32U IEN;          /* Interrupt Enable Register                                            */
    DEF_IO CPU_INT32U IRCTRL;       /* IrDA Control Register                                                */
    DEF_IO CPU_INT32U ROUTE;        /* I/O Routing Register                                                 */
    DEF_IO CPU_INT32U INPUT;        /* USART Input Register                                                 */
    DEF_IO CPU_INT32U I2SCTRL;      /* I2S Control Register                                                */
} USARTRegTypeDef;

typedef struct
{
  DEF_IO CPU_INT32U CTRL;            /* Control Register                                                     */
  DEF_IO CPU_INT32U CMD;             /* Command Register                                                     */
  DEF_I  CPU_INT32U STATUS;          /* Status Register                                                      */
  DEF_IO CPU_INT32U CLKDIV;          /* Clock Control Register                                               */
  DEF_IO CPU_INT32U STARTFRAME;      /* Start Frame Register                                                 */
  DEF_IO CPU_INT32U SIGFRAME;        /* Signal Frame Register                                                */
  DEF_I  CPU_INT32U RXDATAX;         /* Receive Buffer Data Extended Register                                */
  DEF_I  CPU_INT32U RXDATA;          /* Receive Buffer Data Register                                         */
  DEF_I  CPU_INT32U RXDATAXP;        /* Receive Buffer Data Extended Peek Register                           */
  DEF_IO CPU_INT32U TXDATAX;         /* Transmit Buffer Data Extended Register                               */
  DEF_IO CPU_INT32U TXDATA;          /* Transmit Buffer Data Register                                        */
  DEF_I  CPU_INT32U IF;              /* Interrupt Flag Register                                              */
  DEF_IO CPU_INT32U IFS;             /* Interrupt Flag Set Register                                          */
  DEF_IO CPU_INT32U IFC;             /* Interrupt Flag Clear Register                                        */
  DEF_IO CPU_INT32U IEN;             /* Interrupt Enable Register                                            */
  DEF_IO CPU_INT32U PULSECTRL;       /* Pulse Control Register                                               */
  DEF_IO CPU_INT32U FREEZE;          /* Freeze Register                                                      */
  DEF_I  CPU_INT32U SYNCBUSY;        /* Synchronization Busy Register                                        */
         CPU_INT32U RESERVED0[3];    /* Reserved for future use                                              */
  DEF_IO CPU_INT32U ROUTE;           /* I/O Routing Register                                                 */
         CPU_INT32U RESERVED1[19];   /* Reserved for future use                                              */
  DEF_IO CPU_INT32U INPUT;           /* LEUART Input Register                                                */
} LEUARTRegTypeDef;

typedef struct             
{
  DEF_IO CPU_INT32U CTRL;            /* Control Register                                                    */
  DEF_IO CPU_INT32U CMD;             /* Command Register                                                    */
  DEF_I  CPU_INT32U SYNCBUSY;        /* Synchronization Busy Register                                       */
} WDOGRegTypeDef;  

typedef struct
{
    DEF_I CPU_INT32U CAL;           /* Calibration temperature and checksum                                 */
    DEF_I CPU_INT32U ADC0CAL0;      /* ADC0 Calibration register 0                                          */
    DEF_I CPU_INT32U ADC0CAL1;      /* ADC0 Calibration register 1                                          */
    DEF_I CPU_INT32U ADC0CAL2;      /* ADC0 Calibration register 2                                          */
          CPU_INT32U RESERVED0[2];  /* Reserved                                                             */
    DEF_I CPU_INT32U DAC0CAL0;      /* DAC calibrartion register 0                                          */
    DEF_I CPU_INT32U DAC0CAL1;      /* DAC calibrartion register 1                                          */
    DEF_I CPU_INT32U DAC0CAL2;      /* DAC calibrartion register 2                                          */
          CPU_INT32U RESERVED1[2];  /* Reserved                                                             */
    DEF_I CPU_INT32U HFRCOCAL0;     /* HFRCO calibration register 0                                         */
    DEF_I CPU_INT32U HFRCOCAL1;     /* HFRCO calibration register 1                                         */
          CPU_INT32U RESERVED2[3];  /* Reserved                                                             */
    DEF_I CPU_INT32U UNIQUEL;       /* Low 32 bits of device unique number                                  */
    DEF_I CPU_INT32U UNIQUEH;       /* High 32 bits of device unique number                                 */
    DEF_I CPU_INT32U MSIZE;         /* Flash and SRAM Memory size in KiloBytes                              */
    DEF_I CPU_INT32U PART;          /* Part description                                                     */
} DEVINFORegTypeDef;

typedef struct
{
    DEF_I CPU_INT32U PID_4; /* JEP_106_BANK                                                                 */
    DEF_I CPU_INT32U PID_5; /* Unused                                                                       */
    DEF_I CPU_INT32U PID_6; /* Unused                                                                       */
    DEF_I CPU_INT32U PID_7; /* Unused                                                                       */
    DEF_I CPU_INT32U PID_0; /* Chip family LSB, chip major revision                                         */
    DEF_I CPU_INT32U PID_1; /* JEP_106_NO, Chip family MSB                                                  */
    DEF_I CPU_INT32U PID_2; /* Chip minor rev MSB, JEP_106_PRESENT, JEP_106_NO                              */
    DEF_I CPU_INT32U PID_3; /* Chip minor rev LSB                                                           */
    DEF_I CPU_INT32U CID_0; /* Unused                                                                       */
} ROMTableTypeDef;

typedef struct
{
    DEF_IO CPU_INT32U CTRL;         /* Control Register                                                 */
    DEF_IO CPU_INT32U CMD;          /* Command Register                                                 */
    DEF_I CPU_INT32U STATE;         /* State Register                                                   */
    DEF_I CPU_INT32U STATUS;        /* Status Register                                                  */
    DEF_IO CPU_INT32U CLKDIV;       /* Clock Division Register                                          */
    DEF_IO CPU_INT32U SADDR;        /* Slave Address Register                                           */
    DEF_IO CPU_INT32U SADDRMASK;    /* Slave Address Mask Register                                      */
    DEF_I CPU_INT32U RXDATA;        /* Receive Biffer Data Register                                     */
    DEF_I CPU_INT32U RXDATAP;       /* Receive Biffer Data Peek Register                                */
    DEF_IO CPU_INT32U TXDATA;       /* Transmit Buffer Data Register                                    */
    DEF_I CPU_INT32U IF;            /* Interrupt Flag register                                          */
    DEF_IO CPU_INT32U IFS;          /* Interrupt Flag Set Register                                      */
    DEF_IO CPU_INT32U IFC;          /* Interrupt Flag Clear Register                                    */
    DEF_IO CPU_INT32U IEN;          /* Interrupt Enable Register                                        */
    DEF_IO CPU_INT32U ROUTE;        /* I/O Routing Register                                             */
} I2CRegTypeDef;


/*************************************************************************************************************
*                                                 DEFINES                                                    *
*************************************************************************************************************/
#define INT_SRC_NBR                             38u

#define INT_DMA                                 PERIPH_INT_ID0  /* DMA Interrupt.                           */
#define INT_GPIO_EVEN                           PERIPH_INT_ID1  /* GPIO EVEN Interrupt.                     */
#define INT_TIMER0                              PERIPH_INT_ID2  /* TIMER0 Interrupt.                        */
#define INT_USART0_RX                           PERIPH_INT_ID3  /* USART0 RX Interrupt.                     */
#define INT_USART0_TX                           PERIPH_INT_ID4  /* USART0 TX Interrupt.                     */
#define INT_USB                                 PERIPH_INT_ID5  /* USB Interrupt.                           */                               
#define INT_ACMP                                PERIPH_INT_ID6  /* ACMP Interrupt.                          */
#define INT_ADC0                                PERIPH_INT_ID7  /* ADC0 Interrupt.                          */
#define INT_DAC0                                PERIPH_INT_ID8  /* DACO Interrupt.                          */
#define INT_I2C0                                PERIPH_INT_ID9  /* I2C0 Interrupt.                          */
#define INT_I2C1                                PERIPH_INT_ID10 /* I2C1 Interrupt.                          */
#define INT_GPIO_ODD                            PERIPH_INT_ID11 /* GPIO ODD Interrupt.                      */
#define INT_TIMER1                              PERIPH_INT_ID12 /* TIMER1 Interrupt.                        */
#define INT_TIMER2                              PERIPH_INT_ID13 /* TIMER2 Interrupt.                        */
#define INT_TIMER3                              PERIPH_INT_ID14 /* TIMER3 Interrupt.                        */
#define INT_USART1_RX                           PERIPH_INT_ID15 /* USART1 RX Interrupt.                     */
#define INT_USART1_TX                           PERIPH_INT_ID16 /* USART1 TX Interrupt.                     */
#define INT_LESENSE                             PERIPH_INT_ID17 /* LESENSE Interrupt.                       */
#define INT_USART2_RX                           PERIPH_INT_ID18 /* USART2 RX Interrupt.                     */
#define INT_USART2_TX                           PERIPH_INT_ID19 /* USART2 TX Interrupt.                     */
#define INT_UART0_RX                            PERIPH_INT_ID20 /* UART0 RX Interrupt.                      */
#define INT_UART0_TX                            PERIPH_INT_ID21 /* UART0 TX Interrupt.                      */
#define INT_UART1_RX                            PERIPH_INT_ID22 /* UART1 RX Interrupt.                      */
#define INT_UART1_TX                            PERIPH_INT_ID23 /* UART1 TX Interrupt.                      */
#define INT_LEUART0                             PERIPH_INT_ID24 /* LEUART0 Interrupt.                       */
#define INT_LEUART1                             PERIPH_INT_ID25 /* LEUART1 Interrupt.                       */
#define INT_LETIMER0                            PERIPH_INT_ID26 /* LETIME0 Interrupts.                      */
#define INT_PCNT0                               PERIPH_INT_ID27 /* PCNT0 Interrupts.                        */
#define INT_PCNT1                               PERIPH_INT_ID28 /* PCNT1 Interrupt.                         */
#define INT_PCNT2                               PERIPH_INT_ID29 /* PCNT2 Interrupt.                         */
#define INT_RTC                                 PERIPH_INT_ID30 /* RTC Interrupt.                           */
#define INT_BURTC                               PERIPH_INT_ID31 /* BURTC Interrupt.                         */
#define INT_CMU                                 PERIPH_INT_ID32 /* CMU Interrupt.                           */
#define INT_VCMP                                PERIPH_INT_ID33 /* VCMP Interrupt.                          */
#define INT_LCD                                 PERIPH_INT_ID34 /* LCD Interrupt.                           */
#define INT_MSC                                 PERIPH_INT_ID35 /* MSC Interrupt.                           */
#define INT_AES                                 PERIPH_INT_ID36 /* AES Interrupt.                           */
#define INT_EBI                                 PERIPH_INT_ID37 /* EBI Interrupt.                           */


/*************************************************************************************************************
*                                               MODULE END                                                   *
*************************************************************************************************************/     
#ifdef __cplusplus
}
#endif

#endif 
