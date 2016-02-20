/*************************************************************************************************************
*                                                  MODULE                                                    *
*************************************************************************************************************/
#ifndef UART_H
#define UART_H

#ifdef __cplusplus
extern "C" {
#endif
    

/*************************************************************************************************************
*                                                 DEFINES                                                    *
*************************************************************************************************************/
#define UART0                                  ((USARTRegTypeDef *)UART0_BASE)
#define UART1                                  ((USARTRegTypeDef *)UART1_BASE)
    
/* Bit fields for USART CTRL */
#define USART_CTRL_RESETVALUE                   0x00000000UL    /* Default value for USART_CTRL             */
#define USART_CTRL_MASK                         0x1DFFFF7FUL    /* Mask for USART_CTRL                      */
#define USART_CTRL_SYNC_SHIFT                   0               /* Shift value for USART_CTRL_SYNC          */
#define USART_CTRL_SYNC_MASK                    (0x1UL << 0)    /* Bit mask for USART_CTRL_SYNC             */
#define USART_CTRL_SYNC_DEFAULT                 (0x0UL << 0)    /* Mode DEFAULT for USART_CTRL_SYNC         */
#define USART_CTRL_SYNC_ASYNC                   (0x0UL << 0)    /* USART Asynchronous Mode                  */
#define USART_CTRL_SYNC_SYNC                    (0x1UL << 0)    /* USART Synchronous Mode                   */
#define USART_CTRL_LOOPBK_SHIFT                 1               /* Shift value for USART_CTRL_LOOPBK        */
#define USART_CTRL_LOOPBK_MASK                  (0x1UL << 1)    /* Bit mask for USART_CTRL_LOOPBK           */
#define USART_CTRL_LOOPBK_DEFAULT               (0x0UL << 1)    /* Mode DEFAULT for USART_CTRL_LOOPBK       */
#define USART_CTRL_LOOPBK                       (0x1UL << 1)    /* Loopback Enable                          */
#define USART_CTRL_CCEN_SHIFT                   2               /* Shift value for USART_CTRL_CCEN          */
#define USART_CTRL_CCEN_MASK                    (0x1UL << 2)    /* Bit mask for USART_CTRL_CCEN             */
#define USART_CTRL_CCEN_DEFAULT                 (0x0UL << 2)    /* Mode DEFAULT for USART_CTRL_CCEN         */
#define USART_CTRL_CCEN                         (0x1UL << 2)    /* Collision Check Enable                   */
#define USART_CTRL_MPM_SHIFT                    3               /* Shift value for USART_CTRL_MPM           */
#define USART_CTRL_MPM_MASK                     (0x1UL << 3)    /* Bit mask for USART_CTRL_MPM              */
#define USART_CTRL_MPM_DEFAULT                  (0x0UL << 3)    /* Mode DEFAULT for USART_CTRL_MPM          */
#define USART_CTRL_MPM                          (0x1UL << 3)    /* Multi-Processor Mode                     */
#define USART_CTRL_MPAB_SHIFT                   4               /* Shift value for USART_CTRL_MPAB          */
#define USART_CTRL_MPAB_MASK                    (0x1UL << 4)    /* Bit mask for USART_CTRL_MPAB             */
#define USART_CTRL_MPAB_DEFAULT                 (0x0UL << 4)    /* Mode DEFAULT for USART_CTRL_MPAB         */
#define USART_CTRL_MPAB_0                       (0x0UL << 4)    /* Multi-Processor Address-Bit whit 0       */
#define USART_CTRL_MPAB_1                       (0x1UL << 4)    /* Multi-Processor Address-Bit whit 1       */
#define USART_CTRL_OVS_SHIFT                    5               /* Shift value for USART_CTRL_OVS           */
#define USART_CTRL_OVS_MASK                     (0x3UL << 5)    /* Bit mask for USART_CTRL_OVS              */
#define USART_CTRL_OVS_DEFAULT                  (0x0UL << 5)    /* Mode DEFAULT for USART_CTRL_OVS          */
#define USART_CTRL_OVS_X16                      (0x0UL << 5)    /* Mode X16 for USART_CTRL_OVS              */
#define USART_CTRL_OVS_X8                       (0x1UL << 5)    /* Mode X8 for USART_CTRL_OVS               */
#define USART_CTRL_OVS_X6                       (0x2UL << 5)    /* Mode X6 for USART_CTRL_OVS               */
#define USART_CTRL_OVS_X4                       (0x3UL << 5)    /* Mode X4 for USART_CTRL_OVS               */
#define USART_CTRL_CLKPOL_SHIFT                 8               /* Shift value for USART_CTRL_CLKPOL        */
#define USART_CTRL_CLKPOL_MASK                  (0x1UL << 8)    /* Bit mask for USART_CTRL_CLKPOL           */
#define USART_CTRL_CLKPOL_DEFAULT               (0x0UL << 8)    /* Mode DEFAULT for USART_CTRL_CLKPOL       */
#define USART_CTRL_CLKPOL_IDLELOW               (0x0UL << 8)    /* Mode IDLELOW for USART_CTRL_CLKPOL       */
#define USART_CTRL_CLKPOL_IDLEHIGH              (0x1UL << 8)    /* Mode IDLEHIGH for USART_CTRL_CLKPOL      */
#define USART_CTRL_CLKPHA_SHIFT                 9               /* Shift value for USART_CTRL_CLKPHA        */
#define USART_CTRL_CLKPHA_MASK                  (0x1UL << 9)    /* Bit mask for USART_CTRL_CLKPHA           */
#define USART_CTRL_CLKPHA_DEFAULT               (0x0UL << 9)    /* Mode DEFAULT for USART_CTRL_CLKPHA       */
#define USART_CTRL_CLKPHA_SAMPLELEADING         (0x0UL << 9)    /* Mode SAMPLELEADING for USART_CTRL_CLKPHA */
#define USART_CTRL_CLKPHA_SAMPLETRAILING        (0x1UL << 9)    /* Mode SAMPLETRAILING for USART_CTRL_CLKPHA */
#define USART_CTRL_MSBF_SHIFT                   10              /* Shift value for USART_CTRL_MSBF          */
#define USART_CTRL_MSBF_MASK                    (0x1UL << 10)   /* Bit mask for USART_CTRL_MSBF             */
#define USART_CTRL_MSBF_DEFAULT                 (0x0UL << 10)   /* Mode DEFAULT for USART_CTRL_MSBF         */
#define USART_CTRL_MSBF_LSB                     (0x0UL << 10)   /* Least Significant Bit First              */
#define USART_CTRL_MSBF_MSB                     (0x1UL << 10)   /* Most Significant Bit First               */
#define USART_CTRL_CSMA_SHIFT                   11              /* Shift value for USART_CTRL_CSMA          */
#define USART_CTRL_CSMA_MASK                    (0x1UL << 11)   /* Bit mask for USART_CTRL_CSMA             */
#define USART_CTRL_CSMA_DEFAULT                 (0x0UL << 11)   /* Mode DEFAULT for USART_CTRL_CSMA         */
#define USART_CTRL_CSMA_NOACTION                (0x0UL << 11)   /* Mode NOACTION for USART_CTRL_CSMA        */
#define USART_CTRL_CSMA_GOTOSLAVEMODE           (0x1UL << 11)   /* Mode GOTOSLAVEMODE for USART_CTRL_CSMA   */
#define USART_CTRL_TXBIL_SHIFT                  12              /* Shift value for USART_CTRL_TXBIL         */
#define USART_CTRL_TXBIL_MASK                   (0x1UL << 12)   /* Bit mask for USART_CTRL_TXBIL            */
#define USART_CTRL_TXBIL_DEFAULT                (0x0UL << 12)   /* Mode DEFAULT for USART_CTRL_TXBIL        */
#define USART_CTRL_TXBIL_EMPTY                  (0x0UL << 12)   /* Mode EMPTY for USART_CTRL_TXBIL          */
#define USART_CTRL_TXBIL_HALFFULL               (0x1UL << 12)   /* Mode HALFFULL for USART_CTRL_TXBIL       */
#define USART_CTRL_RXINV_SHIFT                  13              /* Shift value for USART_CTRL_RXINV         */
#define USART_CTRL_RXINV_MASK                   (0x1UL << 13)   /* Bit mask for USART_CTRL_RXINV            */
#define USART_CTRL_RXINV_DEFAULT                (0x0UL << 13)   /* Mode DEFAULT for USART_CTRL_RXINV        */
#define USART_CTRL_RXINV                        (0x1UL << 13)   /* Receiver Input Invert                    */
#define USART_CTRL_TXINV_SHIFT                  14              /* Shift value for USART_CTRL_TXINV         */
#define USART_CTRL_TXINV_MASK                   (0x1UL << 14)   /* Bit mask for USART_CTRL_TXINV            */
#define USART_CTRL_TXINV_DEFAULT                (0x0UL << 14)   /* Mode DEFAULT for USART_CTRL_TXINV        */
#define USART_CTRL_TXINV                        (0x1UL << 14)   /* Transmitter output Invert                */
#define USART_CTRL_CSINV_SHIFT                  15              /* Shift value for USART_CTRL_CSINV         */
#define USART_CTRL_CSINV_MASK                   (0x1UL << 15)   /* Bit mask for USART_CTRL_CSINV            */
#define USART_CTRL_CSINV_DEFAULT                (0x0UL << 15)   /* Mode DEFAULT for USART_CTRL_CSINV        */
#define USART_CTRL_CSINV_LOW                    (0x0UL << 15)   /* Chip select is active low                */
#define USART_CTRL_CSINV_HIGH                   (0x1UL << 15)   /* Chip select is active high               */
#define USART_CTRL_AUTOCS_SHIFT                 16              /* Shift value for USART_CTRL_AUTOCS        */
#define USART_CTRL_AUTOCS_MASK                  (0x1UL << 16)   /* Bit mask for USART_CTRL_AUTOCS           */
#define USART_CTRL_AUTOCS_DEFAULT               (0x0UL << 16)   /* Mode DEFAULT for USART_CTRL_AUTOCS       */
#define USART_CTRL_AUTOCS                       (0x1UL << 16)   /* Automatic Chip Select                    */
#define USART_CTRL_AUTOTRI_SHIFT                17              /* Shift value for USART_CTRL_AUTOTRI       */
#define USART_CTRL_AUTOTRI_MASK                 (0x1UL << 17)   /* Bit mask for USART_CTRL_AUTOTRI          */
#define USART_CTRL_AUTOTRI_DEFAULT              (0x0UL << 17)   /* Mode DEFAULT for USART_CTRL_AUTOTRI      */
#define USART_CTRL_AUTOTRI                      (0x1UL << 17)   /* Automatic TX Tristate                    */
#define USART_CTRL_SCMODE_SHIFT                 18              /* Shift value for USART_CTRL_SCMODE        */
#define USART_CTRL_SCMODE_MASK                  (0x1UL << 18)   /* Bit mask for USART_CTRL_SCMODE           */
#define USART_CTRL_SCMODE_DEFAULT               (0x0UL << 18)   /* Mode DEFAULT for USART_CTRL_SCMODE       */
#define USART_CTRL_SCMODE                       (0x1UL << 18)   /* SmartCard Mode                           */
#define USART_CTRL_SCRETRANS_SHIFT              19              /* Shift value for USART_CTRL_SCRETRANS     */
#define USART_CTRL_SCRETRANS_MASK               (0x1UL << 19)   /* Bit mask for USART_CTRL_SCRETRANS        */
#define USART_CTRL_SCRETRANS_DEFAULT            (0x0UL << 19)   /* Mode DEFAULT for USART_CTRL_SCRETRANS    */
#define USART_CTRL_SCRETRANS                    (0x1UL << 19)   /* SmartCard Retransmit                     */
#define USART_CTRL_SKIPPERRF_SHIFT              20              /* Shift value for USART_CTRL_SKIPPERRF     */
#define USART_CTRL_SKIPPERRF_MASK               (0x1UL << 20)   /* Bit mask for USART_CTRL_SKIPPERRF        */
#define USART_CTRL_SKIPPERRF_DEFAULT            (0x0UL << 20)   /* Mode DEFAULT for USART_CTRL_SKIPPERRF    */
#define USART_CTRL_SKIPPERRF                    (0x1UL << 20)   /* Skip Parity Error Frames                 */
#define USART_CTRL_BIT8DV_SHIFT                 21              /* Shift value for USART_CTRL_BIT8DV        */
#define USART_CTRL_BIT8DV_MASK                  (0x1UL << 21)   /* Bit mask for USART_CTRL_BIT8DV           */
#define USART_CTRL_BIT8DV_DEFAULT               (0x0UL << 21)   /* Mode DEFAULT for USART_CTRL_BIT8DV       */
#define USART_CTRL_BIT8DV_0                     (0x0UL << 21)   /* Bit 8 Default Value with 0               */
#define USART_CTRL_BIT8DV_1                     (0x1UL << 21)   /* Bit 8 Default Value with 1               */
#define USART_CTRL_ERRSDMA_SHIFT                22              /* Shift value for USART_CTRL_ERRSDMA       */
#define USART_CTRL_ERRSDMA_MASK                 (0x1UL << 22)   /* Bit mask for USART_CTRL_ERRSDMA          */
#define USART_CTRL_ERRSDMA_DEFAULT              (0x0UL << 22)   /* Mode DEFAULT for USART_CTRL_ERRSDMA      */
#define USART_CTRL_ERRSDMA                      (0x1UL << 22)   /* Halt DMA On Error                        */
#define USART_CTRL_ERRSRX_SHIFT                 23              /* Shift value for USART_CTRL_ERRSRX        */
#define USART_CTRL_ERRSRX_MASK                  (0x1UL << 23)   /* Bit mask for USART_CTRL_ERRSRX           */
#define USART_CTRL_ERRSRX_DEFAULT               (0x0UL << 23)   /* Mode DEFAULT for USART_CTRL_ERRSRX       */
#define USART_CTRL_ERRSRX                       (0x1UL << 23)   /* Disable RX On Error                      */
#define USART_CTRL_ERRSTX_SHIFT                 24              /* Shift value for USART_CTRL_ERRSTX        */
#define USART_CTRL_ERRSTX_MASK                  (0x1UL << 24)   /* Bit mask for USART_CTRL_ERRSTX           */
#define USART_CTRL_ERRSTX_DEFAULT               (0x0UL << 24)   /* Mode DEFAULT for USART_CTRL_ERRSTX       */
#define USART_CTRL_ERRSTX                       (0x1UL << 24)   /* Disable TX On Error                      */
#define USART_CTRL_TXDELAY_SHIFT                26              /* Shift value for USART_CTRL_TXDELAY       */
#define USART_CTRL_TXDELAY_MASK                 (0x3UL << 26)   /* Bit mask for USART_CTRL_TXDELAY          */
#define USART_CTRL_TXDELAY_DEFAULT              (0x0UL << 26)   /* Mode DEFAULT for USART_CTRL_TXDELAY      */
#define USART_CTRL_TXDELAY_NONE                 (0x0UL << 26)   /* Mode NONE for USART_CTRL_TXDELAY         */
#define USART_CTRL_TXDELAY_SINGLE               (0x1UL << 26)   /* Mode SINGLE for USART_CTRL_TXDELAY       */
#define USART_CTRL_TXDELAY_DOUBLE               (0x2UL << 26)   /* Mode DOUBLE for USART_CTRL_TXDELAY       */
#define USART_CTRL_TXDELAY_TRIPLE               (0x3UL << 26)   /* Mode TRIPLE for USART_CTRL_TXDELAY       */
#define USART_CTRL_BYTESWAP_SHIFT               28              /* Shift value for USART_CTRL_BYTESWAP      */
#define USART_CTRL_BYTESWAP_MASK                (0x1UL << 28)   /* Bit mask for USART_CTRL_BYTESWAP         */
#define USART_CTRL_BYTESWAP_DEFAULT             (0x0UL << 28)   /* Mode DEFAULT for USART_CTRL_BYTESWAP     */
#define USART_CTRL_BYTESWAP                     (0x1UL << 28)   /* Byteswap In Double Accesses              */

/* Bit fields for USART FRAME */
#define USART_FRAME_RESETVALUE                  0x00001005UL    /* Default value for USART_FRAME            */
#define USART_FRAME_MASK                        0x0000330FUL    /* Mask for USART_FRAME                     */
#define USART_FRAME_DATABITS_SHIFT              0               /* Shift value for USART_FRAME_DATABITS     */
#define USART_FRAME_DATABITS_MASK               (0xFUL << 0)    /* Bit mask for USART_FRAME_DATABITS        */
#define USART_FRAME_DATABITS_DEFAULT            (0x5UL << 0)    /* Mode DEFAULT for USART_FRAME_DATABITS    */
#define USART_FRAME_DATABITS_FOUR               (0x1UL << 0)    /* Mode FOUR for USART_FRAME_DATABITS       */
#define USART_FRAME_DATABITS_FIVE               (0x2UL << 0)    /* Mode FIVE for USART_FRAME_DATABITS       */
#define USART_FRAME_DATABITS_SIX                (0x3UL << 0)    /* Mode SIX for USART_FRAME_DATABITS        */
#define USART_FRAME_DATABITS_SEVEN              (0x4UL << 0)    /* Mode SEVEN for USART_FRAME_DATABITS      */
#define USART_FRAME_DATABITS_EIGHT              (0x5UL << 0)    /* Mode EIGHT for USART_FRAME_DATABITS      */
#define USART_FRAME_DATABITS_NINE               (0x6UL << 0)    /* Mode NINE for USART_FRAME_DATABITS       */
#define USART_FRAME_DATABITS_TEN                (0x7UL << 0)    /* Mode TEN for USART_FRAME_DATABITS        */
#define USART_FRAME_DATABITS_ELEVEN             (0x8UL << 0)    /* Mode ELEVEN for USART_FRAME_DATABITS     */
#define USART_FRAME_DATABITS_TWELVE             (0x9UL << 0)    /* Mode TWELVE for USART_FRAME_DATABITS     */
#define USART_FRAME_DATABITS_THIRTEEN           (0xAUL << 0)    /* Mode THIRTEEN for USART_FRAME_DATABITS   */
#define USART_FRAME_DATABITS_FOURTEEN           (0xBUL << 0)    /* Mode FOURTEEN for USART_FRAME_DATABITS   */
#define USART_FRAME_DATABITS_FIFTEEN            (0xCUL << 0)    /* Mode FIFTEEN for USART_FRAME_DATABITS    */
#define USART_FRAME_DATABITS_SIXTEEN            (0xDUL << 0)    /* Mode SIXTEEN for USART_FRAME_DATABITS    */
#define USART_FRAME_PARITY_SHIFT                8               /* Shift value for USART_FRAME_PARITY       */
#define USART_FRAME_PARITY_MASK                 (0x3UL << 8)    /* Bit mask for USART_FRAME_PARITY          */
#define USART_FRAME_PARITY_DEFAULT              (0x0UL << 8)    /* Mode DEFAULT for USART_FRAME_PARITY      */
#define USART_FRAME_PARITY_NONE                 (0x0UL << 8)    /* Mode NONE for USART_FRAME_PARITY         */
#define USART_FRAME_PARITY_EVEN                 (0x2UL << 8)    /* Mode EVEN for USART_FRAME_PARITY         */
#define USART_FRAME_PARITY_ODD                  (0x3UL << 8)    /* Mode ODD for USART_FRAME_PARITY          */
#define USART_FRAME_STOPBITS_SHIFT              12              /* Shift value for USART_FRAME_STOPBITS     */
#define USART_FRAME_STOPBITS_MASK               (0x3UL << 12)   /* Bit mask for USART_FRAME_STOPBITS        */
#define USART_FRAME_STOPBITS_DEFAULT            (0x1UL << 12)   /* Mode DEFAULT for USART_FRAME_STOPBITS    */
#define USART_FRAME_STOPBITS_HALF               (0x0UL << 12)   /* Mode HALF for USART_FRAME_STOPBITS       */
#define USART_FRAME_STOPBITS_ONE                (0x1UL << 12)   /* Mode ONE for USART_FRAME_STOPBITS        */
#define USART_FRAME_STOPBITS_ONEANDAHALF        (0x2UL << 12)   /* Mode ONEANDAHALF for USART_FRAME_STOPBITS */
#define USART_FRAME_STOPBITS_TWO                (0x3UL << 12)   /* Mode TWO for USART_FRAME_STOPBITS        */

/* Bit fields for USART TRIGCTRL */
#define USART_TRIGCTRL_RESETVALUE               0x00000000UL    /* Default value for USART_TRIGCTRL         */
#define USART_TRIGCTRL_MASK                     0x00000037UL    /* Mask for USART_TRIGCTRL                  */
#define USART_TRIGCTRL_TSEL_SHIFT               0               /* Shift value for USART_TRIGCTRL_TSEL      */
#define USART_TRIGCTRL_TSEL_MASK                (0x7UL << 0)    /* Bit mask for USART_TRIGCTRL_TSEL         */
#define USART_TRIGCTRL_TSEL_DEFAULT             (0x0UL << 0)    /* Mode DEFAULT for USART_TRIGCTRL_TSEL     */
#define USART_TRIGCTRL_TSEL_PRSCH0              (0x0UL << 0)    /* Mode PRSCH0 for USART_TRIGCTRL_TSEL      */
#define USART_TRIGCTRL_TSEL_PRSCH1              (0x1UL << 0)    /* Mode PRSCH1 for USART_TRIGCTRL_TSEL      */
#define USART_TRIGCTRL_TSEL_PRSCH2              (0x2UL << 0)    /* Mode PRSCH2 for USART_TRIGCTRL_TSEL      */
#define USART_TRIGCTRL_TSEL_PRSCH3              (0x3UL << 0)    /* Mode PRSCH3 for USART_TRIGCTRL_TSEL      */
#define USART_TRIGCTRL_TSEL_PRSCH4              (0x4UL << 0)    /* Mode PRSCH4 for USART_TRIGCTRL_TSEL      */
#define USART_TRIGCTRL_TSEL_PRSCH5              (0x5UL << 0)    /* Mode PRSCH5 for USART_TRIGCTRL_TSEL      */
#define USART_TRIGCTRL_TSEL_PRSCH6              (0x6UL << 0)    /* Mode PRSCH6 for USART_TRIGCTRL_TSEL      */
#define USART_TRIGCTRL_TSEL_PRSCH7              (0x7UL << 0)    /* Mode PRSCH7 for USART_TRIGCTRL_TSEL      */
#define USART_TRIGCTRL_RXTEN_SHIFT              4               /* Shift value for USART_TRIGCTRL_RXTEN     */
#define USART_TRIGCTRL_RXTEN_MASK               (0x1UL << 4)    /* Bit mask for USART_TRIGCTRL_RXTEN        */
#define USART_TRIGCTRL_RXTEN_DEFAULT            (0x0UL << 4)    /* Mode DEFAULT for USART_TRIGCTRL_RXTEN    */
#define USART_TRIGCTRL_RXTEN                    (0x1UL << 4)    /* Receive Trigger Enable                   */
#define USART_TRIGCTRL_TXTEN_SHIFT              5               /* Shift value for USART_TRIGCTRL_TXTEN     */
#define USART_TRIGCTRL_TXTEN_MASK               (0x1UL << 5)    /* Bit mask for USART_TRIGCTRL_TXTEN        */
#define USART_TRIGCTRL_TXTEN_DEFAULT            (0x0UL << 5)    /* Mode DEFAULT for USART_TRIGCTRL_TXTEN    */
#define USART_TRIGCTRL_TXTEN                    (0x1UL << 5)    /* Transmit Trigger Enable                  */
 
/* Bit fields for USART CMD */
#define USART_CMD_RESETVALUE                    0x00000000UL    /* Default value for USART_CMD              */
#define USART_CMD_MASK                          0x00000FFFUL    /* Mask for USART_CMD                       */
#define USART_CMD_RXEN_SHIFT                    0               /* Shift value for USART_CMD_RXEN           */
#define USART_CMD_RXEN_MASK                     (0x1UL << 0)    /* Bit mask for USART_CMD_RXEN              */
#define USART_CMD_RXEN_DEFAULT                  (0x0UL << 0)    /* Mode DEFAULT for USART_CMD_RXEN          */
#define USART_CMD_RXEN                          (0x1UL << 0)    /* Receiver Enable                          */
#define USART_CMD_RXDIS_SHIFT                   1               /* Shift value for USART_CMD_RXDIS          */
#define USART_CMD_RXDIS_MASK                    (0x1UL << 1)    /* Bit mask for USART_CMD_RXDIS             */
#define USART_CMD_RXDIS_DEFAULT                 (0x0UL << 1)    /* Mode DEFAULT for USART_CMD_RXDIS         */
#define USART_CMD_RXDIS                         (0x1UL << 1)    /* Receiver Disable                         */
#define USART_CMD_TXEN_SHIFT                    2               /* Shift value for USART_CMD_TXEN           */
#define USART_CMD_TXEN_MASK                     (0x1UL << 2)    /* Bit mask for USART_CMD_TXEN              */
#define USART_CMD_TXEN_DEFAULT                  (0x0UL << 2)    /* Mode DEFAULT for USART_CMD_TXEN          */
#define USART_CMD_TXEN                          (0x1UL << 2)    /* Transmitter Enable                       */
#define USART_CMD_TXDIS_SHIFT                   3               /* Shift value for USART_CMD_TXDIS          */
#define USART_CMD_TXDIS_MASK                    (0x1UL << 3)    /* Bit mask for USART_CMD_TXDIS             */
#define USART_CMD_TXDIS_DEFAULT                 (0x0UL << 3)    /* Mode DEFAULT for USART_CMD_TXDIS         */
#define USART_CMD_TXDIS                         (0x1UL << 3)    /* Transmitter Disable                      */
#define USART_CMD_MASTEREN_SHIFT                4               /* Shift value for USART_CMD_MASTEREN       */
#define USART_CMD_MASTEREN_MASK                 (0x1UL << 4)    /* Bit mask for USART_CMD_MASTEREN          */
#define USART_CMD_MASTEREN_DEFAULT              (0x0UL << 4)    /* Mode DEFAULT for USART_CMD_MASTEREN      */
#define USART_CMD_MASTEREN                      (0x1UL << 4)    /* Master Enable                            */
#define USART_CMD_MASTERDIS_SHIFT               5               /* Shift value for USART_CMD_MASTERDIS      */
#define USART_CMD_MASTERDIS_MASK                (0x1UL << 5)    /* Bit mask for USART_CMD_MASTERDIS         */
#define USART_CMD_MASTERDIS_DEFAULT             (0x0UL << 5)    /* Mode DEFAULT for USART_CMD_MASTERDIS     */
#define USART_CMD_MASTERDIS                     (0x1UL << 5)    /* Master Disable                           */
#define USART_CMD_RXBLOCKEN_SHIFT               6               /* Shift value for USART_CMD_RXBLOCKEN      */
#define USART_CMD_RXBLOCKEN_MASK                (0x1UL << 6)    /* Bit mask for USART_CMD_RXBLOCKEN         */
#define USART_CMD_RXBLOCKEN_DEFAULT             (0x0UL << 6)    /* Mode DEFAULT for USART_CMD_RXBLOCKEN     */
#define USART_CMD_RXBLOCKEN                     (0x1UL << 6)    /* Receiver Block Enable                    */
#define USART_CMD_RXBLOCKDIS_SHIFT              7               /* Shift value for USART_CMD_RXBLOCKDIS     */
#define USART_CMD_RXBLOCKDIS_MASK               (0x1UL << 7)    /* Bit mask for USART_CMD_RXBLOCKDIS        */
#define USART_CMD_RXBLOCKDIS_DEFAULT            (0x0UL << 7)    /* Mode DEFAULT for USART_CMD_RXBLOCKDIS    */
#define USART_CMD_RXBLOCKDIS                    (0x1UL << 7)    /* Receiver Block Disable                   */
#define USART_CMD_TXTRIEN_SHIFT                 8               /* Shift value for USART_CMD_TXTRIEN        */
#define USART_CMD_TXTRIEN_MASK                  (0x1UL << 8)    /* Bit mask for USART_CMD_TXTRIEN           */
#define USART_CMD_TXTRIEN_DEFAULT               (0x0UL << 8)    /* Mode DEFAULT for USART_CMD_TXTRIEN       */
#define USART_CMD_TXTRIEN                       (0x1UL << 8)    /* Transmitter Tristate Enable              */
#define USART_CMD_TXTRIDIS_SHIFT                9               /* Shift value for USART_CMD_TXTRIDIS       */
#define USART_CMD_TXTRIDIS_MASK                 (0x1UL << 9)    /* Bit mask for USART_CMD_TXTRIDIS          */
#define USART_CMD_TXTRIDIS_DEFAULT              (0x0UL << 9)    /* Mode DEFAULT for USART_CMD_TXTRIDIS      */
#define USART_CMD_TXTRIDIS                      (0x1UL << 9)    /* Transmitter Tristate Disable             */
#define USART_CMD_CLEARTX_SHIFT                 10              /* Shift value for USART_CMD_CLEARTX        */
#define USART_CMD_CLEARTX_MASK                  (0x1UL << 10)   /* Bit mask for USART_CMD_CLEARTX           */
#define USART_CMD_CLEARTX_DEFAULT               (0x0UL << 10)   /* Mode DEFAULT for USART_CMD_CLEARTX       */
#define USART_CMD_CLEARTX                       (0x1UL << 10)   /* Clear TX                                 */
#define USART_CMD_CLEARRX_SHIFT                 11              /* Shift value for USART_CMD_CLEARRX        */
#define USART_CMD_CLEARRX_MASK                  (0x1UL << 11)   /* Bit mask for USART_CMD_CLEARRX           */
#define USART_CMD_CLEARRX_DEFAULT               (0x0UL << 11)   /* Mode DEFAULT for USART_CMD_CLEARRX       */
#define USART_CMD_CLEARRX                       (0x1UL << 11)   /* Clear RX                                 */

/* Bit fields for USART STATUS */
#define USART_STATUS_RESETVALUE                 0x00000040UL    /* Default value for USART_STATUS           */
#define USART_STATUS_MASK                       0x000001FFUL    /* Mask for USART_STATUS                    */
#define USART_STATUS_RXENS_SHIFT                0               /* Shift value for USART_STATUS_RXENS       */
#define USART_STATUS_RXENS_MASK                 (0x1UL << 0)    /* Bit mask for USART_STATUS_RXENS          */
#define USART_STATUS_RXENS_DEFAULT              (0x0UL << 0)    /* Mode DEFAULT for USART_STATUS_RXENS      */
#define USART_STATUS_RXENS                      (0x1UL << 0)    /* Receiver Enable Status                   */
#define USART_STATUS_TXENS_SHIFT                1               /* Shift value for USART_STATUS_TXENS       */
#define USART_STATUS_TXENS_MASK                 (0x1UL << 1)    /* Bit mask for USART_STATUS_TXENS          */
#define USART_STATUS_TXENS_DEFAULT              (0x0UL << 1)    /* Mode DEFAULT for USART_STATUS_TXENS      */
#define USART_STATUS_TXENS                      (0x1UL << 1)    /* Transmitter Enable Status                */
#define USART_STATUS_MASTER_SHIFT               2               /* Shift value for USART_STATUS_MASTER      */
#define USART_STATUS_MASTER_MASK                (0x1UL << 2)    /* Bit mask for USART_STATUS_MASTER         */
#define USART_STATUS_MASTER_DEFAULT             (0x0UL << 2)    /* Mode DEFAULT for USART_STATUS_MASTER     */
#define USART_STATUS_MASTER                     (0x1UL << 2)    /* SPI Master Mode                          */
#define USART_STATUS_RXBLOCK_SHIFT              3               /* Shift value for USART_STATUS_RXBLOCK     */
#define USART_STATUS_RXBLOCK_MASK               (0x1UL << 3)    /* Bit mask for USART_STATUS_RXBLOCK        */
#define USART_STATUS_RXBLOCK_DEFAULT            (0x0UL << 3)    /* Mode DEFAULT for USART_STATUS_RXBLOCK    */
#define USART_STATUS_RXBLOCK                    (0x1UL << 3)    /* Block Incoming Data                      */
#define USART_STATUS_TXTRI_SHIFT                4               /* Shift value for USART_STATUS_TXTRI       */
#define USART_STATUS_TXTRI_MASK                 (0x1UL << 4)    /* Bit mask for USART_STATUS_TXTRI          */
#define USART_STATUS_TXTRI_DEFAULT              (0x0UL << 4)    /* Mode DEFAULT for USART_STATUS_TXTRI      */
#define USART_STATUS_TXTRI                      (0x1UL << 4)    /* Transmitter Tristated                    */
#define USART_STATUS_TXC_SHIFT                  5               /* Shift value for USART_STATUS_TXC         */
#define USART_STATUS_TXC_MASK                   (0x1UL << 5)    /* Bit mask for USART_STATUS_TXC            */
#define USART_STATUS_TXC_DEFAULT                (0x0UL << 5)    /* Mode DEFAULT for USART_STATUS_TXC        */
#define USART_STATUS_TXC                        (0x1UL << 5)    /* TX Complete                              */
#define USART_STATUS_TXBL_SHIFT                 6               /* Shift value for USART_STATUS_TXBL        */
#define USART_STATUS_TXBL_MASK                  (0x1UL << 6)    /* Bit mask for USART_STATUS_TXBL           */
#define USART_STATUS_TXBL_DEFAULT               (0x0UL << 6)    /* Mode DEFAULT for USART_STATUS_TXBL       */
#define USART_STATUS_TXBL                       (0x1UL << 6)    /* TX Buffer Level                          */
#define USART_STATUS_RXDATAV_SHIFT              7               /* Shift value for USART_STATUS_RXDATAV     */
#define USART_STATUS_RXDATAV_MASK               (0x1UL << 7)    /* Bit mask for USART_STATUS_RXDATAV        */
#define USART_STATUS_RXDATAV_DEFAULT            (0x0UL << 7)    /* Mode DEFAULT for USART_STATUS_RXDATAV    */
#define USART_STATUS_RXDATAV                    (0x1UL << 7)    /* RX Data Valid                            */
#define USART_STATUS_RXFULL_SHIFT               8               /* Shift value for USART_STATUS_RXFULL      */
#define USART_STATUS_RXFULL_MASK                (0x1UL << 8)    /* Bit mask for USART_STATUS_RXFULL         */
#define USART_STATUS_RXFULL_DEFAULT             (0x0UL << 8)    /* Mode DEFAULT for USART_STATUS_RXFULL     */
#define USART_STATUS_RXFULL                     (0x1UL << 8)    /* RX FIFO Full                             */

/* Bit fields for USART CLKDIV */
#define USART_CLKDIV_RESETVALUE                 0x00000000UL    /* Default value for USART_CLKDIV           */
#define USART_CLKDIV_MASK                       0x001FFFC0UL    /* Mask for USART_CLKDIV                    */
#define USART_CLKDIV_DIV_SHIFT                  6               /* Shift value for USART_CLKDIV_DIV         */
#define USART_CLKDIV_DIV_MASK                   (0x1FFUL << 6)  /* Bit mask for USART_CLKDIV_DIV            */
#define USART_CLKDIV_DIV_DEFAULT                (0x0UL   << 6)  /* Mode DEFAULT for USART_CLKDIV_DIV        */

/* Bit fields for USART RXDATAX */
#define USART_RXDATAX_RESETVALUE                0x00000000UL    /* Default value for USART_RXDATAX          */
#define USART_RXDATAX_MASK                      0x0000C1FFUL    /* Mask for USART_RXDATAX                   */
#define USART_RXDATAX_RXDATA_SHIFT              0               /* Shift value for USART_RXDATAX_RXDATA     */
#define USART_RXDATAX_RXDATA_MASK               (0x1FFUL << 0)  /* Bit mask for USART_RXDATAX_RXDATA        */
#define USART_RXDATAX_RXDATA_DEFAULT            (0x0UL   << 0)  /* Mode DEFAULT for USART_RXDATAX_RXDATA    */
#define USART_RXDATAX_PERR_SHIFT                14              /* Shift value for USART_RXDATAX_PERR       */
#define USART_RXDATAX_PERR_MASK                 (0x1UL << 14)   /* Bit mask for USART_RXDATAX_PERR          */
#define USART_RXDATAX_PERR_DEFAULT              (0x0UL << 14)   /* Mode DEFAULT for USART_RXDATAX_PERR      */
#define USART_RXDATAX_PERR                      (0x1UL << 14)   /* Data Parity Error                        */
#define USART_RXDATAX_FERR_SHIFT                15              /* Shift value for USART_RXDATAX_FERR       */
#define USART_RXDATAX_FERR_MASK                 (0x1UL << 15)   /* Bit mask for USART_RXDATAX_FERR          */
#define USART_RXDATAX_FERR_DEFAULT              (0x0UL << 15)   /* Mode DEFAULT for USART_RXDATAX_FERR      */
#define USART_RXDATAX_FERR                      (0x1UL << 15)   /* Data Framing Error                       */

/* Bit fields for USART RXDATA */
#define USART_RXDATA_RESETVALUE                 0x00000000UL    /* Default value for USART_RXDATA           */
#define USART_RXDATA_MASK                       0x000000FFUL    /* Mask for USART_RXDATA                    */
#define USART_RXDATA_RXDATA_SHIFT               0               /* Shift value for USART_RXDATA_RXDATA      */
#define USART_RXDATA_RXDATA_MASK                (0xFFUL << 0)   /* Bit mask for USART_RXDATA_RXDATA         */
#define USART_RXDATA_RXDATA_DEFAULT             (0x0UL  << 0)   /* Mode DEFAULT for USART_RXDATA_RXDATA     */

/* Bit fields for USART RXDOUBLEX */
#define USART_RXDOUBLEX_RESETVALUE              0x00000000UL    /* Default value for USART_RXDOUBLEX        */
#define USART_RXDOUBLEX_MASK                    0xC1FFC1FFUL    /* Mask for USART_RXDOUBLEX                 */
#define USART_RXDOUBLEX_RXDATA0_SHIFT           0               /* Shift value for USART_RXDOUBLEX_RXDATA0  */
#define USART_RXDOUBLEX_RXDATA0_MASK            (0x1FFUL << 0)  /* Bit mask for USART_RXDOUBLEX_RXDATA0     */
#define USART_RXDOUBLEX_RXDATA0_DEFAULT         (0x0UL   << 0)  /* Mode DEFAULT for USART_RXDOUBLEX_RXDATA0 */
#define USART_RXDOUBLEX_PERR0_SHIFT             14              /* Shift value for USART_RXDOUBLEX_PERR0    */
#define USART_RXDOUBLEX_PERR0_MASK              (0x1UL << 14)   /* Bit mask for USART_RXDOUBLEX_PERR0       */
#define USART_RXDOUBLEX_PERR0_DEFAULT           (0x0UL << 14)   /* Mode DEFAULT for USART_RXDOUBLEX_PERR0   */
#define USART_RXDOUBLEX_PERR0                   (0x1UL << 14)   /* Data Parity Error 0                      */
#define USART_RXDOUBLEX_FERR0_SHIFT             15              /* Shift value for USART_RXDOUBLEX_FERR0    */
#define USART_RXDOUBLEX_FERR0_MASK              (0x1UL << 15)   /* Bit mask for USART_RXDOUBLEX_FERR0       */
#define USART_RXDOUBLEX_FERR0_DEFAULT           (0x0UL << 15)   /* Mode DEFAULT for USART_RXDOUBLEX_FERR0   */
#define USART_RXDOUBLEX_FERR0                   (0x1UL << 15)   /* Data Framing Error 0                     */
#define USART_RXDOUBLEX_RXDATA1_SHIFT           16              /* Shift value for USART_RXDOUBLEX_RXDATA1  */
#define USART_RXDOUBLEX_RXDATA1_MASK            (0x1FFUL << 16) /* Bit mask for USART_RXDOUBLEX_RXDATA1     */
#define USART_RXDOUBLEX_RXDATA1_DEFAULT         (0x0UL   << 0)  /* Mode DEFAULT for USART_RXDOUBLEX_RXDATA1 */
#define USART_RXDOUBLEX_PERR1_SHIFT             30              /* Shift value for USART_RXDOUBLEX_PERR1    */
#define USART_RXDOUBLEX_PERR1_MASK              (0x1UL << 30)   /* Bit mask for USART_RXDOUBLEX_PERR1       */
#define USART_RXDOUBLEX_PERR1_DEFAULT           (0x0UL << 30)   /* Mode DEFAULT for USART_RXDOUBLEX_PERR1   */
#define USART_RXDOUBLEX_PERR1                   (0x1UL << 30)   /* Data Parity Error 1                      */
#define USART_RXDOUBLEX_FERR1_SHIFT             31              /* Shift value for USART_RXDOUBLEX_FERR1    */
#define USART_RXDOUBLEX_FERR1_MASK              (0x1UL << 31)   /* Bit mask for USART_RXDOUBLEX_FERR1       */
#define USART_RXDOUBLEX_FERR1_DEFAULT           (0x0UL << 31)   /* Mode DEFAULT for USART_RXDOUBLEX_FERR1   */
#define USART_RXDOUBLEX_FERR1                   (0x1UL << 31)   /* Data Framing Error 1                     */

/* Bit fields for USART RXDOUBLE */
#define USART_RXDOUBLE_RESETVALUE               0x00000000UL    /* Default value for USART_RXDOUBLE         */
#define USART_RXDOUBLE_MASK                     0x0000FFFFUL    /* Mask for USART_RXDOUBLE                  */
#define USART_RXDOUBLE_RXDATA0_SHIFT            0               /* Shift value for USART_RXDOUBLE_RXDATA0   */
#define USART_RXDOUBLE_RXDATA0_MASK             (0xFFUL << 0)   /* Bit mask for USART_RXDOUBLE_RXDATA0      */
#define USART_RXDOUBLE_RXDATA0_DEFAULT          (0x0UL  << 0)   /* Mode DEFAULT for USART_RXDOUBLE_RXDATA0  */
#define USART_RXDOUBLE_RXDATA1_SHIFT            8               /* Shift value for USART_RXDOUBLE_RXDATA1   */
#define USART_RXDOUBLE_RXDATA1_MASK             (0xFFUL << 8)   /* Bit mask for USART_RXDOUBLE_RXDATA1      */
#define USART_RXDOUBLE_RXDATA1_DEFAULT          (0x0UL  << 8)   /* Mode DEFAULT for USART_RXDOUBLE_RXDATA1  */

/* Bit fields for USART RXDATAXP */
#define USART_RXDATAXP_RESETVALUE               0x00000000UL    /* Default value for USART_RXDATAXP         */
#define USART_RXDATAXP_MASK                     0x0000C1FFUL    /* Mask for USART_RXDATAXP                  */
#define USART_RXDATAXP_RXDATAP_SHIFT            0               /* Shift value for USART_RXDATAXP_RXDATAP   */
#define USART_RXDATAXP_RXDATAP_MASK             (0x1FFUL << 0)  /* Bit mask for USART_RXDATAXP_RXDATAP      */
#define USART_RXDATAXP_RXDATAP_DEFAULT          (0x0UL << 0)    /* Mode DEFAULT for USART_RXDATAXP_RXDATAP  */
#define USART_RXDATAXP_PERRP_SHIFT              14              /* Shift value for USART_RXDATAXP_PERRP     */
#define USART_RXDATAXP_PERRP_MASK               (0x1UL << 14)   /* Bit mask for USART_RXDATAXP_PERRP        */
#define USART_RXDATAXP_PERRP_DEFAULT            (0x0UL << 14)   /* Mode DEFAULT for USART_RXDATAXP_PERRP    */
#define USART_RXDATAXP_PERRP                    (0x1UL << 14)   /* Data Parity Error Peek                   */
#define USART_RXDATAXP_FERRP_SHIFT              15              /* Shift value for USART_RXDATAXP_FERRP     */
#define USART_RXDATAXP_FERRP_MASK               (0x1UL << 15)   /* Bit mask for USART_RXDATAXP_FERRP        */
#define USART_RXDATAXP_FERRP_DEFAULT            (0x0UL << 15)   /* Mode DEFAULT for USART_RXDATAXP_FERRP    */
#define USART_RXDATAXP_FERRP                    (0x1UL << 15)   /* Data Framing Error Peek                  */

/* Bit fields for USART RXDOUBLEXP */
#define USART_RXDOUBLEXP_RESETVALUE             0x00000000UL    /* Default value for USART_RXDOUBLEXP       */
#define USART_RXDOUBLEXP_MASK                   0xC1FFC1FFUL    /* Mask for USART_RXDOUBLEXP                */
#define USART_RXDOUBLEXP_RXDATAP0_SHIFT         0               /* Shift value for USART_RXDOUBLEXP_RXDATAP0 */
#define USART_RXDOUBLEXP_RXDATAP0_MASK          (0x1FFUL << 0)  /* Bit mask for USART_RXDOUBLEXP_RXDATAP0   */
#define USART_RXDOUBLEXP_RXDATAP0_DEFAULT       (0x0UL   << 0)  /* Mode DEFAULT for USART_RXDOUBLEXP_RXDATAP0 */
#define USART_RXDOUBLEXP_PERRP0_SHIFT           14              /* Shift value for USART_RXDOUBLEXP_PERRP0  */
#define USART_RXDOUBLEXP_PERRP0_MASK            (0x1UL << 14)   /* Bit mask for USART_RXDOUBLEXP_PERRP0     */
#define USART_RXDOUBLEXP_PERRP0_DEFAULT         (0x0UL << 14)   /* Mode DEFAULT for USART_RXDOUBLEXP_PERRP0 */
#define USART_RXDOUBLEXP_PERRP0                 (0x1UL << 14)   /* Data Parity Error 0 Peek                 */
#define USART_RXDOUBLEXP_FERRP0_SHIFT           15              /* Shift value for USART_RXDOUBLEXP_FERRP0  */
#define USART_RXDOUBLEXP_FERRP0_MASK            (0x1UL << 15)   /* Bit mask for USART_RXDOUBLEXP_FERRP0     */
#define USART_RXDOUBLEXP_FERRP0_DEFAULT         (0x0UL << 15)   /* Mode DEFAULT for USART_RXDOUBLEXP_FERRP0 */
#define USART_RXDOUBLEXP_FERRP0                 (0x1UL << 15)   /* Data Framing Error 0 Peek                */
#define USART_RXDOUBLEXP_RXDATAP1_SHIFT         16              /* Shift value for USART_RXDOUBLEXP_RXDATAP1 */
#define USART_RXDOUBLEXP_RXDATAP1_MASK          (0x1FFUL << 16) /* Bit mask for USART_RXDOUBLEXP_RXDATAP1   */
#define USART_RXDOUBLEXP_RXDATAP1_DEFAULT       (0x0UL   << 16) /* Mode DEFAULT for USART_RXDOUBLEXP_RXDATAP1 */
#define USART_RXDOUBLEXP_PERRP1_SHIFT           30              /* Shift value for USART_RXDOUBLEXP_PERRP1  */
#define USART_RXDOUBLEXP_PERRP1_MASK            (0x1UL << 30)   /* Bit mask for USART_RXDOUBLEXP_PERRP1     */
#define USART_RXDOUBLEXP_PERRP1_DEFAULT         (0x0UL << 30)   /* Mode DEFAULT for USART_RXDOUBLEXP_PERRP1 */
#define USART_RXDOUBLEXP_PERRP1                 (0x1UL << 30)   /* Data Parity Error 1 Peek                 */
#define USART_RXDOUBLEXP_FERRP1_SHIFT           31              /* Shift value for USART_RXDOUBLEXP_FERRP1  */
#define USART_RXDOUBLEXP_FERRP1_MASK            (0x0UL << 31)   /* Bit mask for USART_RXDOUBLEXP_FERRP1     */
#define USART_RXDOUBLEXP_FERRP1_DEFAULT         (0x1UL << 31)   /* Mode DEFAULT for USART_RXDOUBLEXP_FERRP1 */
#define USART_RXDOUBLEXP_FERRP1                 (0x1UL << 31)   /* Data Framing Error 1 Peek                */

/* Bit fields for USART TXDATAX */
#define USART_TXDATAX_RESETVALUE                0x00000000UL    /* Default value for USART_TXDATAX          */
#define USART_TXDATAX_MASK                      0x0000F9FFUL    /* Mask for USART_TXDATAX                   */
#define USART_TXDATAX_TXDATAX_SHIFT             0               /* Shift value for USART_TXDATAX_TXDATAX    */
#define USART_TXDATAX_TXDATAX_MASK              (0x1FFUL << 0)  /* Bit mask for USART_TXDATAX_TXDATAX       */
#define USART_TXDATAX_TXDATAX_DEFAULT           (0x0UL   << 0)  /* Mode DEFAULT for USART_TXDATAX_TXDATAX   */
#define USART_TXDATAX_UBRXAT_SHIFT              11              /* Shift value for USART_TXDATAX_UBRXAT     */
#define USART_TXDATAX_UBRXAT_MASK               (0x1UL << 11)   /* Bit mask for USART_TXDATAX_UBRXAT        */
#define USART_TXDATAX_UBRXAT_DEFAULT            (0x0UL << 11)   /* Mode DEFAULT for USART_TXDATAX_UBRXAT    */
#define USART_TXDATAX_UBRXAT                    (0x1UL << 11)   /* Unblock RX After Transmission            */
#define USART_TXDATAX_TXTRIAT_SHIFT             12              /* Shift value for USART_TXDATAX_TXTRIAT    */
#define USART_TXDATAX_TXTRIAT_MASK              (0x1UL << 12)   /* Bit mask for USART_TXDATAX_TXTRIAT       */
#define USART_TXDATAX_TXTRIAT_DEFAULT           (0x0UL << 12)   /* Mode DEFAULT for USART_TXDATAX_TXTRIAT   */
#define USART_TXDATAX_TXTRIAT                   (0x1UL << 12)   /* Set TXTRI After Transmission             */
#define USART_TXDATAX_TXBREAK_SHIFT             13              /* Shift value for USART_TXDATAX_TXBREAK    */
#define USART_TXDATAX_TXBREAK_MASK              (0x1UL << 13)   /* Bit mask for USART_TXDATAX_TXBREAK       */
#define USART_TXDATAX_TXBREAK_DEFAULT           (0x0UL << 13)   /* Mode DEFAULT for USART_TXDATAX_TXBREAK   */
#define USART_TXDATAX_TXBREAK                   (0x1UL << 13)   /* Transmit Data As Break                   */
#define USART_TXDATAX_TXDISAT_SHIFT             14              /* Shift value for USART_TXDATAX_TXDISAT    */
#define USART_TXDATAX_TXDISAT_MASK              (0x1UL << 14)   /* Bit mask for USART_TXDATAX_TXDISAT       */
#define USART_TXDATAX_TXDISAT_DEFAULT           (0x0UL << 14)   /* Mode DEFAULT for USART_TXDATAX_TXDISAT   */
#define USART_TXDATAX_TXDISAT                   (0x1UL << 14)   /* Clear TXEN After Transmission            */
#define USART_TXDATAX_RXENAT_SHIFT              15              /* Shift value for USART_TXDATAX_RXENAT     */
#define USART_TXDATAX_RXENAT_MASK               (0x1UL << 15)   /* Bit mask for USART_TXDATAX_RXENAT        */
#define USART_TXDATAX_RXENAT_DEFAULT            (0x0UL << 15)   /* Mode DEFAULT for USART_TXDATAX_RXENAT    */
#define USART_TXDATAX_RXENAT                    (0x1UL << 15)   /* Enable RX After Transmission             */

/* Bit fields for USART TXDATA */
#define USART_TXDATA_RESETVALUE                 0x00000000UL    /* Default value for USART_TXDATA           */
#define USART_TXDATA_MASK                       0x000000FFUL    /* Mask for USART_TXDATA                    */
#define USART_TXDATA_TXDATA_SHIFT               0               /* Shift value for USART_TXDATA_TXDATA      */
#define USART_TXDATA_TXDATA_MASK                (0xFFUL << 0)   /* Bit mask for USART_TXDATA_TXDATA         */
#define USART_TXDATA_TXDATA_DEFAULT             (0x0UL  << 0)   /* Mode DEFAULT for USART_TXDATA_TXDATA     */

/* Bit fields for USART TXDOUBLEX */
#define USART_TXDOUBLEX_RESETVALUE              0x00000000UL    /* Default value for USART_TXDOUBLEX        */
#define USART_TXDOUBLEX_MASK                    0xF9FFF9FFUL    /* Mask for USART_TXDOUBLEX                 */
#define USART_TXDOUBLEX_TXDATA0_SHIFT           0               /* Shift value for USART_TXDOUBLEX_TXDATA0  */
#define USART_TXDOUBLEX_TXDATA0_MASK            (0x1FFUL << 0)  /* Bit mask for USART_TXDOUBLEX_TXDATA0     */
#define USART_TXDOUBLEX_TXDATA0_DEFAULT         (0x0UL   << 0)  /* Mode DEFAULT for USART_TXDOUBLEX_TXDATA0 */
#define USART_TXDOUBLEX_UBRXAT0_SHIFT           11              /* Shift value for USART_TXDOUBLEX_UBRXAT0  */
#define USART_TXDOUBLEX_UBRXAT0_MASK            (0x1UL << 11)   /* Bit mask for USART_TXDOUBLEX_UBRXAT0     */
#define USART_TXDOUBLEX_UBRXAT0_DEFAULT         (0x0UL << 11)   /* Mode DEFAULT for USART_TXDOUBLEX_UBRXAT0 */
#define USART_TXDOUBLEX_UBRXAT0                 (0x1UL << 11)   /* Unblock RX After Transmission            */
#define USART_TXDOUBLEX_TXTRIAT0_SHIFT          12              /* Shift value for USART_TXDOUBLEX_TXTRIAT0 */
#define USART_TXDOUBLEX_TXTRIAT0_MASK           (0x1UL << 12)   /* Bit mask for USART_TXDOUBLEX_TXTRIAT0    */
#define USART_TXDOUBLEX_TXTRIAT0_DEFAULT        (0x0UL << 12)   /* Mode DEFAULT for USART_TXDOUBLEX_TXTRIAT0 */
#define USART_TXDOUBLEX_TXTRIAT0                (0x1UL << 12)   /* Set TXTRI After Transmission             */
#define USART_TXDOUBLEX_TXBREAK0_SHIFT          13              /* Shift value for USART_TXDOUBLEX_TXBREAK0 */
#define USART_TXDOUBLEX_TXBREAK0_MASK           (0x1UL << 13)   /* Bit mask for USART_TXDOUBLEX_TXBREAK0    */
#define USART_TXDOUBLEX_TXBREAK0_DEFAULT        (0x0UL << 13)   /* Mode DEFAULT for USART_TXDOUBLEX_TXBREAK0 */
#define USART_TXDOUBLEX_TXBREAK0                (0x1UL << 13)   /* Transmit Data As Break                   */
#define USART_TXDOUBLEX_TXDISAT0_SHIFT          14              /* Shift value for USART_TXDOUBLEX_TXDISAT0 */
#define USART_TXDOUBLEX_TXDISAT0_MASK           (0x1UL << 14)   /* Bit mask for USART_TXDOUBLEX_TXDISAT0    */
#define USART_TXDOUBLEX_TXDISAT0_DEFAULT        (0x0UL << 14)   /* Mode DEFAULT for USART_TXDOUBLEX_TXDISAT0 */
#define USART_TXDOUBLEX_TXDISAT0                (0x1UL << 14)   /* Clear TXEN After Transmission            */
#define USART_TXDOUBLEX_RXENAT0_SHIFT           15              /* Shift value for USART_TXDOUBLEX_RXENAT0  */
#define USART_TXDOUBLEX_RXENAT0_MASK            (0x1UL << 15)   /* Bit mask for USART_TXDOUBLEX_RXENAT0     */
#define USART_TXDOUBLEX_RXENAT0_DEFAULT         (0x0UL << 15)   /* Mode DEFAULT for USART_TXDOUBLEX_RXENAT0 */
#define USART_TXDOUBLEX_RXENAT0                 (0x1UL << 15)   /* Enable RX After Transmission             */
#define USART_TXDOUBLEX_TXDATA1_SHIFT           16              /* Shift value for USART_TXDOUBLEX_TXDATA1  */
#define USART_TXDOUBLEX_TXDATA1_MASK            (0x1FFUL << 16) /* Bit mask for USART_TXDOUBLEX_TXDATA1     */
#define USART_TXDOUBLEX_TXDATA1_DEFAULT         (0x0UL   << 16) /* Mode DEFAULT for USART_TXDOUBLEX_TXDATA1 */
#define USART_TXDOUBLEX_UBRXAT1_SHIFT           27              /* Shift value for USART_TXDOUBLEX_UBRXAT1  */
#define USART_TXDOUBLEX_UBRXAT1_MASK            (0x1UL << 27)   /* Bit mask for USART_TXDOUBLEX_UBRXAT1     */
#define USART_TXDOUBLEX_UBRXAT1_DEFAULT         (0x0UL << 27)   /* Mode DEFAULT for USART_TXDOUBLEX_UBRXAT1 */
#define USART_TXDOUBLEX_UBRXAT1                 (0x1UL << 27)   /* Unblock RX After Transmission            */
#define USART_TXDOUBLEX_TXTRIAT1_SHIFT          28              /* Shift value for USART_TXDOUBLEX_TXTRIAT1 */
#define USART_TXDOUBLEX_TXTRIAT1_MASK           (0x1UL << 28)   /* Bit mask for USART_TXDOUBLEX_TXTRIAT1    */
#define USART_TXDOUBLEX_TXTRIAT1_DEFAULT        (0x0UL << 28)   /* Mode DEFAULT for USART_TXDOUBLEX_TXTRIAT1 */
#define USART_TXDOUBLEX_TXTRIAT1                (0x1UL << 28)   /* Set TXTRI After Transmission             */
#define USART_TXDOUBLEX_TXBREAK1_SHIFT          29              /* Shift value for USART_TXDOUBLEX_TXBREAK1 */
#define USART_TXDOUBLEX_TXBREAK1_MASK           (0x1UL << 29)   /* Bit mask for USART_TXDOUBLEX_TXBREAK1    */
#define USART_TXDOUBLEX_TXBREAK1_DEFAULT        (0x0UL << 29)   /* Mode DEFAULT for USART_TXDOUBLEX_TXBREAK1 */
#define USART_TXDOUBLEX_TXBREAK1                (0x1UL << 29)   /* Transmit Data As Break                   */
#define USART_TXDOUBLEX_TXDISAT1_SHIFT          30              /* Shift value for USART_TXDOUBLEX_TXDISAT1 */
#define USART_TXDOUBLEX_TXDISAT1_MASK           (0x1UL << 30)   /* Bit mask for USART_TXDOUBLEX_TXDISAT1    */
#define USART_TXDOUBLEX_TXDISAT1_DEFAULT        (0x0UL << 30)   /* Mode DEFAULT for USART_TXDOUBLEX_TXDISAT1 */
#define USART_TXDOUBLEX_TXDISAT1                (0x1UL << 30)   /* Clear TXEN After Transmission            */
#define USART_TXDOUBLEX_RXENAT1_SHIFT           31              /* Shift value for USART_TXDOUBLEX_RXENAT1  */
#define USART_TXDOUBLEX_RXENAT1_MASK            (0x1UL << 31)   /* Bit mask for USART_TXDOUBLEX_RXENAT1     */
#define USART_TXDOUBLEX_RXENAT1_DEFAULT         (0x0UL << 31)   /* Mode DEFAULT for USART_TXDOUBLEX_RXENAT1 */
#define USART_TXDOUBLEX_RXENAT1                 (0x1UL << 31)   /* Enable RX After Transmission             */

/* Bit fields for USART TXDOUBLE */
#define USART_TXDOUBLE_RESETVALUE               0x00000000UL    /* Default value for USART_TXDOUBLE */
#define USART_TXDOUBLE_MASK                     0x0000FFFFUL    /* Mask for USART_TXDOUBLE */
#define USART_TXDOUBLE_TXDATA0_SHIFT            0               /* Shift value for USART_TXDOUBLE_TXDATA0 */
#define USART_TXDOUBLE_TXDATA0_MASK             (0xFFUL >> 0)   /* Bit mask for USART_TXDOUBLE_TXDATA0 */
#define USART_TXDOUBLE_TXDATA0_DEFAULT          (0x0UL  >> 0)   /* Mode DEFAULT for USART_TXDOUBLE_TXDATA0 */
#define USART_TXDOUBLE_TXDATA1_SHIFT            8               /* Shift value for USART_TXDOUBLE_TXDATA1 */
#define USART_TXDOUBLE_TXDATA1_MASK             (0xFFUL >> 8)   /* Bit mask for USART_TXDOUBLE_TXDATA1 */
#define USART_TXDOUBLE_TXDATA1_DEFAULT          (0x0UL  >> 0)   /* Mode DEFAULT for USART_TXDOUBLE_TXDATA1 */

/* Bit fields for USART IF */
#define USART_IF_RESETVALUE                     0x00000002UL    /* Default value for USART_IF               */
#define USART_IF_MASK                           0x00001FFFUL    /* Mask for USART_IF                        */
#define USART_IF_TXC_SHIFT                      0               /* Shift value for USART_IF_TXC             */
#define USART_IF_TXC_MASK                       (0x1UL << 0)    /* Bit mask for USART_IF_TXC                */
#define USART_IF_TXC_DEFAULT                    (0x0UL << 0)    /* Mode DEFAULT for USART_IF_TXC            */
#define USART_IF_TXC                            (0x1UL << 0)    /* TX Complete Interrupt Flag               */
#define USART_IF_TXBL_SHIFT                     1               /* Shift value for USART_IF_TXBL            */
#define USART_IF_TXBL_MASK                      (0x1UL << 1)    /* Bit mask for USART_IF_TXBL               */
#define USART_IF_TXBL_DEFAULT                   (0x0UL << 1)    /* Mode DEFAULT for USART_IF_TXBL           */
#define USART_IF_TXBL                           (0x1UL << 1)    /* TX Buffer Level Interrupt Flag           */
#define USART_IF_RXDATAV_SHIFT                  2               /* Shift value for USART_IF_RXDATAV         */
#define USART_IF_RXDATAV_MASK                   (0x1UL << 2)    /* Bit mask for USART_IF_RXDATAV            */
#define USART_IF_RXDATAV_DEFAULT                (0x0UL << 2)    /* Mode DEFAULT for USART_IF_RXDATAV        */
#define USART_IF_RXDATAV                        (0x1UL << 2)    /* RX Data Valid Interrupt Flag             */
#define USART_IF_RXFULL_SHIFT                   3               /* Shift value for USART_IF_RXFULL          */
#define USART_IF_RXFULL_MASK                    (0x1UL << 3)    /* Bit mask for USART_IF_RXFULL             */
#define USART_IF_RXFULL_DEFAULT                 (0x0UL << 3)    /* Mode DEFAULT for USART_IF_RXFULL         */
#define USART_IF_RXFULL                         (0x1UL << 3)    /* RX Buffer Full Interrupt Flag            */
#define USART_IF_RXOF_SHIFT                     4               /* Shift value for USART_IF_RXOF            */
#define USART_IF_RXOF_MASK                      (0x1UL << 4)    /* Bit mask for USART_IF_RXOF               */
#define USART_IF_RXOF_DEFAULT                   (0x0UL << 4)    /* Mode DEFAULT for USART_IF_RXOF           */
#define USART_IF_RXOF                           (0x1UL << 4)    /* RX Overflow Interrupt Flag               */
#define USART_IF_RXUF_SHIFT                     5               /* Shift value for USART_IF_RXUF            */
#define USART_IF_RXUF_MASK                      (0x1UL << 5)    /* Bit mask for USART_IF_RXUF               */
#define USART_IF_RXUF_DEFAULT                   (0x0UL << 5)    /* Mode DEFAULT for USART_IF_RXUF           */
#define USART_IF_RXUF                           (0x1UL << 5)    /* RX Underflow Interrupt Flag              */
#define USART_IF_TXOF_SHIFT                     6               /* Shift value for USART_IF_TXOF            */
#define USART_IF_TXOF_MASK                      (0x1UL << 6)    /* Bit mask for USART_IF_TXOF               */
#define USART_IF_TXOF_DEFAULT                   (0x0UL << 6)    /* Mode DEFAULT for USART_IF_TXOF           */
#define USART_IF_TXOF                           (0x1UL << 6)    /* TX Overflow Interrupt Flag               */
#define USART_IF_TXUF_SHIFT                     7               /* Shift value for USART_IF_TXUF            */
#define USART_IF_TXUF_MASK                      0x80UL          /* Bit mask for USART_IF_TXUF               */
#define USART_IF_TXUF_DEFAULT                   0x00000000UL    /* Mode DEFAULT for USART_IF_TXUF           */
#define USART_IF_TXUF                           (0x1UL << 7)    /* TX Underflow Interrupt Flag              */
#define USART_IF_PERR_SHIFT                     8               /* Shift value for USART_IF_PERR            */
#define USART_IF_PERR_MASK                      (0x1UL << 8)    /* Bit mask for USART_IF_PERR               */
#define USART_IF_PERR_DEFAULT                   (0x0UL << 8)    /* Mode DEFAULT for USART_IF_PERR           */
#define USART_IF_PERR                           (0x1UL << 8)    /* Parity Error Interrupt Flag              */
#define USART_IF_FERR_SHIFT                     9               /* Shift value for USART_IF_FERR            */
#define USART_IF_FERR_MASK                      (0x1UL << 9)    /* Bit mask for USART_IF_FERR               */
#define USART_IF_FERR_DEFAULT                   (0x0UL << 9)    /* Mode DEFAULT for USART_IF_FERR           */
#define USART_IF_FERR                           (0x1UL << 9)    /* Framing Error Interrupt Flag             */
#define USART_IF_MPAF_SHIFT                     10              /* Shift value for USART_IF_MPAF            */
#define USART_IF_MPAF_MASK                      (0x1UL << 10)   /* Bit mask for USART_IF_MPAF               */
#define USART_IF_MPAF_DEFAULT                   (0x0UL << 10)   /* Mode DEFAULT for USART_IF_MPAF           */
#define USART_IF_MPAF                           (0x1UL << 10)   /* Multi-Processor Address Frame Interrupt Flag */
#define USART_IF_SSM_SHIFT                      11              /* Shift value for USART_IF_SSM             */
#define USART_IF_SSM_MASK                       (0x1UL << 11)   /* Bit mask for USART_IF_SSM                */
#define USART_IF_SSM_DEFAULT                    (0x0UL << 11)   /* Mode DEFAULT for USART_IF_SSM            */
#define USART_IF_SSM                            (0x1UL << 11)   /* Slave-Select In Master Mode Interrupt Flag */
#define USART_IF_CCF_SHIFT                      12              /* Shift value for USART_IF_CCF             */
#define USART_IF_CCF_MASK                       (0x1UL << 12)   /* Bit mask for USART_IF_CCF                */
#define USART_IF_CCF_DEFAULT                    (0x0UL << 12)   /* Mode DEFAULT for USART_IF_CCF            */
#define USART_IF_CCF                            (0x1UL << 12)   /* Collision Check Fail Interrupt Flag      */

/* Bit fields for USART IFS */
#define USART_IFS_RESETVALUE                    0x00000000UL    /* Default value for USART_IFS              */
#define USART_IFS_MASK                          0x00001FF9UL    /* Mask for USART_IFS                       */
#define USART_IFS_TXC_SHIFT                     0               /* Shift value for USART_IFS_TXC            */
#define USART_IFS_TXC_MASK                      (0x1UL << 0)    /* Bit mask for USART_IFS_TXC               */
#define USART_IFS_TXC_DEFAULT                   (0x0UL << 0)    /* Mode DEFAULT for USART_IFS_TXC           */
#define USART_IFS_TXC                           (0x1UL << 0)    /* Set TX Complete Interrupt Flag           */
#define USART_IFS_RXFULL_SHIFT                  3               /* Shift value for USART_IFS_RXFULL         */
#define USART_IFS_RXFULL_MASK                   (0x1UL << 3)    /* Bit mask for USART_IFS_RXFULL            */
#define USART_IFS_RXFULL_DEFAULT                (0x0UL << 3)    /* Mode DEFAULT for USART_IFS_RXFULL        */
#define USART_IFS_RXFULL                        (0x1UL << 3)    /* Set RX Buffer Full Interrupt Flag        */
#define USART_IFS_RXOF_SHIFT                    4               /* Shift value for USART_IFS_RXOF           */
#define USART_IFS_RXOF_MASK                     (0x1UL << 4)    /* Bit mask for USART_IFS_RXOF              */
#define USART_IFS_RXOF_DEFAULT                  (0x0UL << 4)    /* Mode DEFAULT for USART_IFS_RXOF          */
#define USART_IFS_RXOF                          (0x1UL << 4)    /* Set RX Overflow Interrupt Flag           */
#define USART_IFS_RXUF_SHIFT                    5               /* Shift value for USART_IFS_RXUF           */
#define USART_IFS_RXUF_MASK                     (0x1UL << 5)    /* Bit mask for USART_IFS_RXUF              */
#define USART_IFS_RXUF_DEFAULT                  (0x0UL << 5)    /* Mode DEFAULT for USART_IFS_RXUF          */
#define USART_IFS_RXUF                          (0x1UL << 5)    /* Set RX Underflow Interrupt Flag          */
#define USART_IFS_TXOF_SHIFT                    6               /* Shift value for USART_IFS_TXOF           */
#define USART_IFS_TXOF_MASK                     (0x1UL << 6)    /* Bit mask for USART_IFS_TXOF              */
#define USART_IFS_TXOF_DEFAULT                  (0x0UL << 6)    /* Mode DEFAULT for USART_IFS_TXOF          */
#define USART_IFS_TXOF                          (0x1UL << 6)    /* Set TX Overflow Interrupt Flag           */
#define USART_IFS_TXUF_SHIFT                    7               /* Shift value for USART_IFS_TXUF           */
#define USART_IFS_TXUF_MASK                     (0x1UL << 7)    /* Bit mask for USART_IFS_TXUF              */
#define USART_IFS_TXUF_DEFAULT                  (0x0UL << 7)    /* Mode DEFAULT for USART_IFS_TXUF          */
#define USART_IFS_TXUF                          (0x1UL << 7)    /* Set TX Underflow Interrupt Flag          */
#define USART_IFS_PERR_SHIFT                    8               /* Shift value for USART_IFS_PERR           */
#define USART_IFS_PERR_MASK                     (0x1UL << 8)    /* Bit mask for USART_IFS_PERR              */
#define USART_IFS_PERR_DEFAULT                  (0x0UL << 8)    /* Mode DEFAULT for USART_IFS_PERR          */
#define USART_IFS_PERR                          (0x1UL << 8)    /* Set Parity Error Interrupt Flag          */
#define USART_IFS_FERR_SHIFT                    9               /* Shift value for USART_IFS_FERR           */
#define USART_IFS_FERR_MASK                     (0x1UL << 9)    /* Bit mask for USART_IFS_FERR              */
#define USART_IFS_FERR_DEFAULT                  (0x0UL << 9)    /* Mode DEFAULT for USART_IFS_FERR          */
#define USART_IFS_FERR                          (0x1UL << 9)    /* Set Framing Error Interrupt Flag         */
#define USART_IFS_MPAF_SHIFT                    10              /* Shift value for USART_IFS_MPAF           */
#define USART_IFS_MPAF_MASK                     (0x1UL << 10)   /* Bit mask for USART_IFS_MPAF              */
#define USART_IFS_MPAF_DEFAULT                  (0x0UL << 10)   /* Mode DEFAULT for USART_IFS_MPAF          */
#define USART_IFS_MPAF                          (0x1UL << 10)   /* Set Multi-Processor Address Frame Interrupt Flag */
#define USART_IFS_SSM_SHIFT                     11              /* Shift value for USART_IFS_SSM            */
#define USART_IFS_SSM_MASK                      (0x1UL << 11)   /* Bit mask for USART_IFS_SSM               */
#define USART_IFS_SSM_DEFAULT                   (0x0UL << 11)   /* Mode DEFAULT for USART_IFS_SSM           */
#define USART_IFS_SSM                           (0x1UL << 11)   /* Set Slave-Select in Master mode Interrupt Flag */
#define USART_IFS_CCF_SHIFT                     12              /* Shift value for USART_IFS_CCF            */
#define USART_IFS_CCF_MASK                      (0x1UL << 12)   /* Bit mask for USART_IFS_CCF               */
#define USART_IFS_CCF_DEFAULT                   (0x0UL << 12)   /* Mode DEFAULT for USART_IFS_CCF           */
#define USART_IFS_CCF                           (0x1UL << 12)   /* Set Collision Check Fail Interrupt Flag  */

/* Bit fields for USART IFC */
#define USART_IFC_RESETVALUE                    0x00000000UL    /* Default value for USART_IFC              */
#define USART_IFC_MASK                          0x00001FF9UL    /* Mask for USART_IFC                       */
#define USART_IFC_TXC_SHIFT                     0               /* Shift value for USART_IFC_TXC            */
#define USART_IFC_TXC_MASK                      (0x1UL << 0)    /* Bit mask for USART_IFC_TXC               */
#define USART_IFC_TXC_DEFAULT                   (0x0UL << 0)    /* Mode DEFAULT for USART_IFC_TXC           */
#define USART_IFC_TXC                           (0x1UL << 0)    /* Clear TX Complete Interrupt Flag         */
#define USART_IFC_RXFULL_SHIFT                  3               /* Shift value for USART_IFC_RXFULL         */
#define USART_IFC_RXFULL_MASK                   (0x1UL << 3)    /* Bit mask for USART_IFC_RXFULL            */
#define USART_IFC_RXFULL_DEFAULT                (0x0UL << 3)    /* Mode DEFAULT for USART_IFC_RXFULL        */
#define USART_IFC_RXFULL                        (0x1UL << 3)    /* Clear RX Buffer Full Interrupt Flag      */
#define USART_IFC_RXOF_SHIFT                    4               /* Shift value for USART_IFC_RXOF           */
#define USART_IFC_RXOF_MASK                     (0x1UL << 4)    /* Bit mask for USART_IFC_RXOF              */
#define USART_IFC_RXOF_DEFAULT                  (0x0UL << 4)    /* Mode DEFAULT for USART_IFC_RXOF          */
#define USART_IFC_RXOF                          (0x1UL << 4)    /* Clear RX Overflow Interrupt Flag         */
#define USART_IFC_RXUF_SHIFT                    5               /* Shift value for USART_IFC_RXUF           */
#define USART_IFC_RXUF_MASK                     (0x1UL << 5)    /* Bit mask for USART_IFC_RXUF              */
#define USART_IFC_RXUF_DEFAULT                  (0x0UL << 5)    /* Mode DEFAULT for USART_IFC_RXUF          */
#define USART_IFC_RXUF                          (0x1UL << 5)    /* Clear RX Underflow Interrupt Flag        */
#define USART_IFC_TXOF_SHIFT                    6               /* Shift value for USART_IFC_TXOF           */
#define USART_IFC_TXOF_MASK                     (0x1UL << 6)    /* Bit mask for USART_IFC_TXOF              */
#define USART_IFC_TXOF_DEFAULT                  (0x0UL << 6)    /* Mode DEFAULT for USART_IFC_TXOF          */
#define USART_IFC_TXOF                          (0x1UL << 6)    /* Clear TX Overflow Interrupt Flag         */
#define USART_IFC_TXUF_SHIFT                    7               /* Shift value for USART_IFC_TXUF           */
#define USART_IFC_TXUF_MASK                     (0x1UL << 7)    /* Bit mask for USART_IFC_TXUF              */
#define USART_IFC_TXUF_DEFAULT                  (0x0UL << 7)    /* Mode DEFAULT for USART_IFC_TXUF          */
#define USART_IFC_TXUF                          (0x1UL << 7)    /* Clear TX Underflow Interrupt Flag        */
#define USART_IFC_PERR_SHIFT                    8               /* Shift value for USART_IFC_PERR           */
#define USART_IFC_PERR_MASK                     (0x1UL << 8)    /* Bit mask for USART_IFC_PERR              */
#define USART_IFC_PERR_DEFAULT                  (0x0UL << 8)    /* Mode DEFAULT for USART_IFC_PERR          */
#define USART_IFC_PERR                          (0x1UL << 8)    /* Clear Parity Error Interrupt Flag        */
#define USART_IFC_FERR_SHIFT                    9               /* Shift value for USART_IFC_FERR           */
#define USART_IFC_FERR_MASK                     (0x1UL << 9)    /* Bit mask for USART_IFC_FERR              */
#define USART_IFC_FERR_DEFAULT                  (0x0UL << 9)    /* Mode DEFAULT for USART_IFC_FERR          */
#define USART_IFC_FERR                          (0x1UL << 9)    /* Clear Framing Error Interrupt Flag       */
#define USART_IFC_MPAF_SHIFT                    10              /* Shift value for USART_IFC_MPAF           */
#define USART_IFC_MPAF_MASK                     (0x1UL << 10)   /* Bit mask for USART_IFC_MPAF              */
#define USART_IFC_MPAF_DEFAULT                  (0x0UL << 10)   /* Mode DEFAULT for USART_IFC_MPAF          */
#define USART_IFC_MPAF                          (0x1UL << 10)   /* Clear Multi-Processor Address Frame Interrupt Flag */
#define USART_IFC_SSM_SHIFT                     11              /* Shift value for USART_IFC_SSM            */
#define USART_IFC_SSM_MASK                      (0x1UL << 11)   /* Bit mask for USART_IFC_SSM               */
#define USART_IFC_SSM_DEFAULT                   (0x0UL << 11)   /* Mode DEFAULT for USART_IFC_SSM           */
#define USART_IFC_SSM                           (0x1UL << 11)   /* Clear Slave-Select In Master Mode Interrupt Flag */
#define USART_IFC_CCF_SHIFT                     12              /* Shift value for USART_IFC_CCF            */
#define USART_IFC_CCF_MASK                      (0x1UL << 12)   /* Bit mask for USART_IFC_CCF               */
#define USART_IFC_CCF_DEFAULT                   (0x0UL << 12)   /* Mode DEFAULT for USART_IFC_CCF           */
#define USART_IFC_CCF                           (0x1UL << 12)   /* Clear Collision Check Fail Interrupt Flag */

/* Bit fields for USART IEN */
#define USART_IEN_RESETVALUE                    0x00000000UL    /* Default value for USART_IEN              */
#define USART_IEN_MASK                          0x00001FFFUL    /* Mask for USART_IEN                       */
#define USART_IEN_TXC_SHIFT                     0               /* Shift value for USART_IEN_TXC            */
#define USART_IEN_TXC_MASK                      (0x1UL << 0)    /* Bit mask for USART_IEN_TXC               */
#define USART_IEN_TXC_DEFAULT                   (0x0UL << 0)    /* Mode DEFAULT for USART_IEN_TXC           */
#define USART_IEN_TXC                           (0x1UL << 0)    /* TX Complete Interrupt Enable             */
#define USART_IEN_TXBL_SHIFT                    1               /* Shift value for USART_IEN_TXBL           */
#define USART_IEN_TXBL_MASK                     (0x1UL << 1)    /* Bit mask for USART_IEN_TXBL              */
#define USART_IEN_TXBL_DEFAULT                  (0x0UL << 1)    /* Mode DEFAULT for USART_IEN_TXBL          */
#define USART_IEN_TXBL                          (0x1UL << 1)    /* TX Buffer Level Interrupt Enable         */
#define USART_IEN_RXDATAV_SHIFT                 2               /* Shift value for USART_IEN_RXDATAV        */
#define USART_IEN_RXDATAV_MASK                  (0x1UL << 2)    /* Bit mask for USART_IEN_RXDATAV           */
#define USART_IEN_RXDATAV_DEFAULT               (0x0UL << 2)    /* Mode DEFAULT for USART_IEN_RXDATAV       */
#define USART_IEN_RXDATAV                       (0x1UL << 2)    /* RX Data Valid Interrupt Enable           */
#define USART_IEN_RXFULL_SHIFT                  3               /* Shift value for USART_IEN_RXFULL         */
#define USART_IEN_RXFULL_MASK                   (0x1UL << 3)    /* Bit mask for USART_IEN_RXFULL            */
#define USART_IEN_RXFULL_DEFAULT                (0x0UL << 3)    /* Mode DEFAULT for USART_IEN_RXFULL        */
#define USART_IEN_RXFULL                        (0x1UL << 3)    /* RX Buffer Full Interrupt Enable          */
#define USART_IEN_RXOF_SHIFT                    4               /* Shift value for USART_IEN_RXOF           */
#define USART_IEN_RXOF_MASK                     (0x1UL << 4)    /* Bit mask for USART_IEN_RXOF              */
#define USART_IEN_RXOF_DEFAULT                  (0x0UL << 4)    /* Mode DEFAULT for USART_IEN_RXOF          */
#define USART_IEN_RXOF                          (0x1UL << 4)    /* RX Overflow Interrupt Enable             */
#define USART_IEN_RXUF_SHIFT                    5               /* Shift value for USART_IEN_RXUF           */
#define USART_IEN_RXUF_MASK                     (0x1UL << 5)    /* Bit mask for USART_IEN_RXUF              */
#define USART_IEN_RXUF_DEFAULT                  (0x0UL << 5)    /* Mode DEFAULT for USART_IEN_RXUF          */
#define USART_IEN_RXUF                          (0x1UL << 5)    /* RX Underflow Interrupt Enable            */
#define USART_IEN_TXOF_SHIFT                    6               /* Shift value for USART_IEN_TXOF           */
#define USART_IEN_TXOF_MASK                     (0x1UL << 6)    /* Bit mask for USART_IEN_TXOF              */
#define USART_IEN_TXOF_DEFAULT                  (0x0UL << 6)    /* Mode DEFAULT for USART_IEN_TXOF          */
#define USART_IEN_TXOF                          (0x1UL << 6)    /* TX Overflow Interrupt Enable             */
#define USART_IEN_TXUF_SHIFT                    7               /* Shift value for USART_IEN_TXUF           */
#define USART_IEN_TXUF_MASK                     (0x1UL << 7)    /* Bit mask for USART_IEN_TXUF              */
#define USART_IEN_TXUF_DEFAULT                  (0x0UL << 7)    /* Mode DEFAULT for USART_IEN_TXUF          */
#define USART_IEN_TXUF                          (0x1UL << 7)    /* TX Underflow Interrupt Enable            */
#define USART_IEN_PERR_SHIFT                    8               /* Shift value for USART_IEN_PERR           */
#define USART_IEN_PERR_MASK                     (0x1UL << 8)    /* Bit mask for USART_IEN_PERR              */
#define USART_IEN_PERR_DEFAULT                  (0x0UL << 8)    /* Mode DEFAULT for USART_IEN_PERR          */
#define USART_IEN_PERR                          (0x1UL << 8)    /* Parity Error Interrupt Enable            */
#define USART_IEN_FERR_SHIFT                    9               /* Shift value for USART_IEN_FERR           */
#define USART_IEN_FERR_MASK                     (0x1UL << 9)    /* Bit mask for USART_IEN_FERR              */
#define USART_IEN_FERR_DEFAULT                  (0x0UL << 9)    /* Mode DEFAULT for USART_IEN_FERR          */
#define USART_IEN_FERR                          (0x1UL << 9)    /* Framing Error Interrupt Enable           */
#define USART_IEN_MPAF_SHIFT                    10              /* Shift value for USART_IEN_MPAF           */
#define USART_IEN_MPAF_MASK                     (0x1UL << 10)   /* Bit mask for USART_IEN_MPAF              */
#define USART_IEN_MPAF_DEFAULT                  (0x0UL << 10)   /* Mode DEFAULT for USART_IEN_MPAF          */
#define USART_IEN_MPAF                          (0x1UL << 10)   /* Multi-Processor Address Frame Interrupt Enable */
#define USART_IEN_SSM_SHIFT                     11              /* Shift value for USART_IEN_SSM            */
#define USART_IEN_SSM_MASK                      (0x1UL << 11)   /* Bit mask for USART_IEN_SSM               */
#define USART_IEN_SSM_DEFAULT                   (0x0UL << 11)   /* Mode DEFAULT for USART_IEN_SSM           */
#define USART_IEN_SSM                           (0x1UL << 11)   /* Slave-Select In Master Mode Interrupt Enable */
#define USART_IEN_CCF_SHIFT                     12              /* Shift value for USART_IEN_CCF            */
#define USART_IEN_CCF_MASK                      (0x1UL << 12)   /* Bit mask for USART_IEN_CCF               */
#define USART_IEN_CCF_DEFAULT                   (0x0UL << 12)   /* Mode DEFAULT for USART_IEN_CCF           */
#define USART_IEN_CCF                           (0x1UL << 12)   /* Collision Check Fail Interrupt Enable    */

/* Bit fields for USART IRCTRL */
#define USART_IRCTRL_RESETVALUE                 0x00000000UL    /* Default value for USART_IRCTRL           */
#define USART_IRCTRL_MASK                       0x000000FFUL    /* Mask for USART_IRCTRL                    */
#define USART_IRCTRL_IREN_SHIFT                 0               /* Shift value for USART_IRCTRL_IREN        */
#define USART_IRCTRL_IREN_MASK                  (0x1UL << 0)    /* Bit mask for USART_IRCTRL_IREN           */
#define USART_IRCTRL_IREN_DEFAULT               (0x0UL << 0)    /* Mode DEFAULT for USART_IRCTRL_IREN       */
#define USART_IRCTRL_IREN                       (0x1UL << 0)    /* Enable IrDA Module                       */
#define USART_IRCTRL_IRPW_SHIFT                 1               /* Shift value for USART_IRCTRL_IRPW        */
#define USART_IRCTRL_IRPW_MASK                  (0x3UL << 1)    /* Bit mask for USART_IRCTRL_IRPW           */
#define USART_IRCTRL_IRPW_DEFAULT               (0x0UL << 1)    /* Mode DEFAULT for USART_IRCTRL_IRPW       */
#define USART_IRCTRL_IRPW_ONE                   (0x0UL << 1)    /* Mode ONE for USART_IRCTRL_IRPW           */
#define USART_IRCTRL_IRPW_TWO                   (0x1UL << 1)    /* Mode TWO for USART_IRCTRL_IRPW           */
#define USART_IRCTRL_IRPW_THREE                 (0x2UL << 1)    /* Mode THREE for USART_IRCTRL_IRPW         */
#define USART_IRCTRL_IRPW_FOUR                  (0x3UL << 1)    /* Mode FOUR for USART_IRCTRL_IRPW          */
#define USART_IRCTRL_IRFILT_SHIFT               3               /* Shift value for USART_IRCTRL_IRFILT      */
#define USART_IRCTRL_IRFILT_MASK                (0x1UL << 3)    /* Bit mask for USART_IRCTRL_IRFILT         */
#define USART_IRCTRL_IRFILT_DEFAULT             (0x0UL << 3)    /* Mode DEFAULT for USART_IRCTRL_IRFILT     */
#define USART_IRCTRL_IRFILT                     (0x1UL << 3)    /* IrDA RX Filter                           */
#define USART_IRCTRL_IRPRSSEL_SHIFT             4               /* Shift value for USART_IRCTRL_IRPRSSEL    */
#define USART_IRCTRL_IRPRSSEL_MASK              (0x7UL << 4)    /* Bit mask for USART_IRCTRL_IRPRSSEL       */
#define USART_IRCTRL_IRPRSSEL_DEFAULT           (0x0UL << 4)    /* Mode DEFAULT for USART_IRCTRL_IRPRSSEL   */
#define USART_IRCTRL_IRPRSSEL_PRSCH0            (0x0UL << 4)    /* Mode PRSCH0 for USART_IRCTRL_IRPRSSEL    */
#define USART_IRCTRL_IRPRSSEL_PRSCH1            (0x1UL << 4)    /* Mode PRSCH1 for USART_IRCTRL_IRPRSSEL    */
#define USART_IRCTRL_IRPRSSEL_PRSCH2            (0x2UL << 4)    /* Mode PRSCH2 for USART_IRCTRL_IRPRSSEL    */
#define USART_IRCTRL_IRPRSSEL_PRSCH3            (0x3UL << 4)    /* Mode PRSCH3 for USART_IRCTRL_IRPRSSEL    */
#define USART_IRCTRL_IRPRSSEL_PRSCH4            (0x4UL << 4)    /* Mode PRSCH4 for USART_IRCTRL_IRPRSSEL    */
#define USART_IRCTRL_IRPRSSEL_PRSCH5            (0x5UL << 4)    /* Mode PRSCH5 for USART_IRCTRL_IRPRSSEL    */
#define USART_IRCTRL_IRPRSSEL_PRSCH6            (0x6UL << 4)    /* Mode PRSCH6 for USART_IRCTRL_IRPRSSEL    */
#define USART_IRCTRL_IRPRSSEL_PRSCH7            (0x7UL << 4)    /* Mode PRSCH7 for USART_IRCTRL_IRPRSSEL    */
#define USART_IRCTRL_IRPRSEN_SHIFT              7               /* Shift value for USART_IRCTRL_IRPRSEN     */
#define USART_IRCTRL_IRPRSEN_MASK               (0x1UL << 7)    /* Bit mask for USART_IRCTRL_IRPRSEN        */
#define USART_IRCTRL_IRPRSEN_DEFAULT            (0x0UL << 7)    /* Mode DEFAULT for USART_IRCTRL_IRPRSEN    */
#define USART_IRCTRL_IRPRSEN                    (0x1UL << 7)    /* IrDA PRS Channel Enable                  */

/* Bit fields for USART ROUTE */
#define USART_ROUTE_RESETVALUE                  0x00000000UL    /* Default value for USART_ROUTE            */
#define USART_ROUTE_MASK                        0x0000030FUL    /* Mask for USART_ROUTE                     */
#define USART_ROUTE_RXPEN_SHIFT                 0               /* Shift value for USART_ROUTE_RXPEN        */
#define USART_ROUTE_RXPEN_MASK                  0x1UL           /* Bit mask for USART_ROUTE_RXPEN           */
#define USART_ROUTE_RXPEN_DEFAULT               (0x0UL << 0)    /* Mode DEFAULT for USART_ROUTE_RXPEN       */
#define USART_ROUTE_RXPEN                       (0x1UL << 0)    /* RX Pin Enable                            */
#define USART_ROUTE_TXPEN_SHIFT                 1               /* Shift value for USART_ROUTE_TXPEN        */
#define USART_ROUTE_TXPEN_MASK                  (0x1UL << 1)    /* Bit mask for USART_ROUTE_TXPEN           */
#define USART_ROUTE_TXPEN_DEFAULT               (0x0UL << 1)    /* Mode DEFAULT for USART_ROUTE_TXPEN       */
#define USART_ROUTE_TXPEN                       (0x1UL << 1)    /* TX Pin Enable                            */
#define USART_ROUTE_CSPEN_SHIFT                 2               /* Shift value for USART_ROUTE_CSPEN        */
#define USART_ROUTE_CSPEN_MASK                  (0x1UL << 2)    /* Bit mask for USART_ROUTE_CSPEN           */
#define USART_ROUTE_CSPEN_DEFAULT               (0x0UL << 2)    /* Mode DEFAULT for USART_ROUTE_CSPEN       */
#define USART_ROUTE_CSPEN                       (0x1UL << 2)    /* CS Pin Enable                            */
#define USART_ROUTE_CLKPEN_SHIFT                3               /* Shift value for USART_ROUTE_CLKPEN       */
#define USART_ROUTE_CLKPEN_MASK                 (0x1UL << 3)    /* Bit mask for USART_ROUTE_CLKPEN          */
#define USART_ROUTE_CLKPEN_DEFAULT              (0x0UL << 3)    /* Mode DEFAULT for USART_ROUTE_CLKPEN      */
#define USART_ROUTE_CLKPEN                      (0x1UL << 3)    /* CLK Pin Enable                           */
#define USART_ROUTE_LOCATION_SHIFT              8               /* Shift value for USART_ROUTE_LOCATION     */
#define USART_ROUTE_LOCATION_MASK               (0x7UL << 8)    /* Bit mask for USART_ROUTE_LOCATION        */
#define USART_ROUTE_LOCATION_DEFAULT            (0x0UL << 8)    /* Mode DEFAULT for USART_ROUTE_LOCATION    */
#define USART_ROUTE_LOCATION_LOC0               (0x0UL << 8)    /* Mode LOC0 for USART_ROUTE_LOCATION       */
#define USART_ROUTE_LOCATION_LOC1               (0x1UL << 8)    /* Mode LOC1 for USART_ROUTE_LOCATION       */
#define USART_ROUTE_LOCATION_LOC2               (0x2UL << 8)    /* Mode LOC2 for USART_ROUTE_LOCATION       */
#define USART_ROUTE_LOCATION_LOC3               (0x3UL << 8)    /* Mode LOC3 for USART_ROUTE_LOCATION       */
#define USART_ROUTE_LOCATION_LOC4               (0x4UL << 8)    /* Mode LOC4 for USART_ROUTE_LOCATION       */
#define USART_ROUTE_LOCATION_LOC5               (0x5UL << 8)    /* Mode LOC5 for USART_ROUTE_LOCATION       */

#define UART_TX_IRQ_MASK                       (USART_IF_TXC | USART_IF_TXBL | USART_IF_TXOF | USART_IF_TXUF)
#define UART_RX_IRQ_MASK                       (USART_IF_RXDATAV | USART_IF_RXFULL | USART_IF_RXOF | USART_IF_RXUF)
    
/*************************************************************************************************************
*                                                  DATA TYPES                                                *
*************************************************************************************************************/
/* Data Types for USART CTRL */
typedef enum
{
    UART_0 = UART0_BASE, 
    UART_1 = UART1_BASE, 
} UARTTypeDef;

typedef enum
{
    UART_MODE_ASYNC = USART_CTRL_SYNC_ASYNC, 
    UART_MODE_SYNC  = USART_CTRL_SYNC_SYNC, 
} UARTModeTypeDef;

typedef enum
{
    UART_MPMA_BIT_0 = USART_CTRL_MPAB_0, 
    UART_MPMA_BIT_1 = USART_CTRL_MPAB_1, 
} UARTMPMABitTypeDef;

typedef enum
{
    UART_OVERSAMPLING_X16 = USART_CTRL_OVS_X16, 
    UART_OVERSAMPLING_X8  = USART_CTRL_OVS_X8, 
    UART_OVERSAMPLING_X6  = USART_CTRL_OVS_X6, 
    UART_OVERSAMPLING_X4  = USART_CTRL_OVS_X4, 
} UARTOversamplingTypeDef;

typedef enum
{
    UART_CLK_POLARITY_LOW  = USART_CTRL_CLKPOL_IDLELOW, 
    UART_CLK_POLARITY_HIGH = USART_CTRL_CLKPOL_IDLEHIGH, 
} UARTClockPolarityTypeDef;

typedef enum
{
    UART_SAMPLE_CLK_EDGE_LEADING  = USART_CTRL_CLKPHA_SAMPLELEADING, 
    UART_SAMPLE_CLK_EDGE_TRAILING = USART_CTRL_CLKPHA_SAMPLETRAILING, 
} UARTSampleClockEdgeTypeDef;

typedef enum
{
    UART_MSBF_LSB = USART_CTRL_MSBF_LSB, 
    UART_MSBF_MSB = USART_CTRL_MSBF_MSB, 
} UARTMSBFTypeDef;

typedef enum
{
    UART_CSMA_NOACTION      = USART_CTRL_CSMA_NOACTION, 
    UART_CSMA_GOTOSLAVEMODE = USART_CTRL_CSMA_GOTOSLAVEMODE, 
} UARTCSMATypeDef;

typedef enum
{
    UART_TX_INT_LEVEL_EMPTY    = USART_CTRL_TXBIL_EMPTY, 
    UART_TX_INT_LEVEL_HALFFULL = USART_CTRL_TXBIL_HALFFULL, 
} UARTTxIntLevelTypeDef;

typedef enum
{
    UART_CS_ACTIVE_LOW  = USART_CTRL_CSINV_LOW, 
    UART_CS_ACTIVE_HIGH = USART_CTRL_CSINV_HIGH, 
} UARTCSActiveTypeDef;

typedef enum
{
    UART_BIT8DV_0 = USART_CTRL_BIT8DV_0, 
    UART_BIT8DV_1 = USART_CTRL_BIT8DV_1,
} UARTBit8DefaultValueTypeDef;

typedef enum
{
    UART_TX_DELAY_NONE   = USART_CTRL_TXDELAY_NONE, 
    UART_TX_DELAY_SINGLE = USART_CTRL_TXDELAY_SINGLE, 
    UART_TX_DELAY_DOUBLE = USART_CTRL_TXDELAY_DOUBLE, 
    UART_TX_DELAY_TRIPLE = USART_CTRL_TXDELAY_TRIPLE, 
} UARTTxDelayTypeDef;

typedef enum
{
    UART_CLOCK_MODE0 = USART_CTRL_CLKPOL_IDLELOW | USART_CTRL_CLKPHA_SAMPLELEADING,    /* Clock idle low, 
                                                                                           sample on rising 
                                                                                           edge.            */
    UART_CLOCK_MODE1 = USART_CTRL_CLKPOL_IDLELOW | USART_CTRL_CLKPHA_SAMPLETRAILING,   /* Clock idle low, 
                                                                                           sample on falling 
                                                                                           edge.            */
    UART_CLOCK_MODE2 = USART_CTRL_CLKPOL_IDLEHIGH | USART_CTRL_CLKPHA_SAMPLELEADING,   /* Clock idle high, 
                                                                                           sample on falling 
                                                                                           edge.            */  
    UART_CLOCK_MODE3 = USART_CTRL_CLKPOL_IDLEHIGH | USART_CTRL_CLKPHA_SAMPLETRAILING,  /* Clock idle high, 
                                                                                           sample on rising 
                                                                                           edge.            */
} UARTClockModeTypeDef;

typedef enum
{
    UART_SYNC_MODE_MASTER, 
    UART_SYNC_MODE_SLAVE, 
} UARTSyncModeTypeDef;

/* Data Types for USART FRAME */
typedef enum
{
    UART_DATABIT_FOUR     = USART_FRAME_DATABITS_FOUR, 
    UART_DATABIT_FIVE     = USART_FRAME_DATABITS_FIVE,
    UART_DATABIT_SIX      = USART_FRAME_DATABITS_SIX,
    UART_DATABIT_SEVEN    = USART_FRAME_DATABITS_SEVEN,
    UART_DATABIT_EIGHT    = USART_FRAME_DATABITS_EIGHT,
    UART_DATABIT_NINE     = USART_FRAME_DATABITS_NINE,
    UART_DATABIT_TEN      = USART_FRAME_DATABITS_TEN,
    UART_DATABIT_ELEVEN   = USART_FRAME_DATABITS_ELEVEN,
    UART_DATABIT_TWELVE   = USART_FRAME_DATABITS_TWELVE,
    UART_DATABIT_THIRTEEN = USART_FRAME_DATABITS_THIRTEEN,
    UART_DATABIT_FOURTEEN = USART_FRAME_DATABITS_FOURTEEN,
    UART_DATABIT_FIFTEEN  = USART_FRAME_DATABITS_FIFTEEN,
    UART_DATABIT_SIXTEEN  = USART_FRAME_DATABITS_SIXTEEN,
} UARTDataBitTypeDef;

typedef enum
{
    UART_PARITY_NONE = USART_FRAME_PARITY_NONE, 
    UART_PARITY_EVEN = USART_FRAME_PARITY_EVEN, 
    UART_PARITY_ODD  = USART_FRAME_PARITY_ODD, 
} UARTParityModeTypeDef;

typedef enum
{
    UART_STOP_BIT_HALF         = USART_FRAME_STOPBITS_HALF, 
    UART_STOP_BIT_ONE          = USART_FRAME_STOPBITS_ONE, 
    UART_STOP_BIT_ONEANDAHALF  = USART_FRAME_STOPBITS_ONEANDAHALF, 
    UART_STOP_BIT_TWO          = USART_FRAME_STOPBITS_TWO,
} UARTStopModeTypeDef;

/* Data Types for USART TRIGCTRL */
typedef enum
{
    UART_TRIGGER_PRS_CH0 = USART_TRIGCTRL_TSEL_PRSCH0, 
    UART_TRIGGER_PRS_CH1 = USART_TRIGCTRL_TSEL_PRSCH1, 
    UART_TRIGGER_PRS_CH2 = USART_TRIGCTRL_TSEL_PRSCH2, 
    UART_TRIGGER_PRS_CH3 = USART_TRIGCTRL_TSEL_PRSCH3, 
    UART_TRIGGER_PRS_CH4 = USART_TRIGCTRL_TSEL_PRSCH4, 
    UART_TRIGGER_PRS_CH5 = USART_TRIGCTRL_TSEL_PRSCH5, 
    UART_TRIGGER_PRS_CH6 = USART_TRIGCTRL_TSEL_PRSCH6,
    UART_TRIGGER_PRS_CH7 = USART_TRIGCTRL_TSEL_PRSCH7, 
} UARTTriggerPRSChTypeDef;

/* Data Types for USART CMD */
typedef enum
{
    UART_RX  = USART_CMD_RXEN,
    UART_TX  = USART_CMD_TXEN,
    UART_RTX = USART_CMD_RXEN | USART_CMD_TXEN,
} UARTCmdRTxTypeDef;

/* Data Types for USART STATUS */
typedef enum
{
    UART_STATUS_FLAG_RXEN    = USART_STATUS_RXENS, 
    UART_STATUS_FLAG_TXEN    = USART_STATUS_TXENS, 
    UART_STATUS_FLAG_MASTER  = USART_STATUS_MASTER, 
    UART_STATUS_FLAG_RXBLOCK = USART_STATUS_RXBLOCK, 
    UART_STATUS_FLAG_TXTRI   = USART_STATUS_TXTRI, 
    UART_STATUS_FLAG_TXC     = USART_STATUS_TXC,  
    UART_STATUS_FLAG_TXBL    = USART_STATUS_TXBL, 
    UART_STATUS_FLAG_RXDATAV = USART_STATUS_RXDATAV,  
    UART_STATUS_FLAG_RXFULL  = USART_STATUS_RXFULL, 
} UARTStatusTypeDef;

/* Data Types for USART RXDATAX */
typedef enum
{
    UART_RXDATAX_FLAG_PERR = USART_RXDATAX_PERR, 
    UART_RXDATAX_FLAG_FERR = USART_RXDATAX_FERR, 
} UARTRxDataExErrorTypeDef;

/* Data Types for USART RXDOUBLEX */
typedef enum
{
    UART_RXDOUBLEX_RXDATA0 = USART_RXDOUBLEX_RXDATA0_SHIFT, 
    UART_RXDOUBLEX_RXDATA1 = USART_RXDOUBLEX_RXDATA1_SHIFT, 
} UARTRxDoubleDataExTypeDef;

typedef enum
{
    UART_RXDOUBLEX_FLAG_PERR0 = USART_RXDOUBLEX_PERR0, 
    UART_RXDOUBLEX_FLAG_FERR0 = USART_RXDOUBLEX_FERR0, 
    UART_RXDOUBLEX_FLAG_PERR1 = USART_RXDOUBLEX_PERR1, 
    UART_RXDOUBLEX_FLAG_FERR1 = USART_RXDOUBLEX_FERR1, 
} UARTRxDoubleDataExErrorTypeDef;

/* Data Types for USART RXDATAXP */
typedef enum
{
    UART_RXDATAXP_FLAG_PERRP = USART_RXDATAXP_PERRP, 
    UART_RXDATAXP_FLAG_FERRP = USART_RXDATAXP_FERRP, 
} UARTRxDataExErrorPkTypeDef;

/* Data Types for USART RXDOUBLEXP */
typedef enum
{
    UART_RXDOUBLEXP_RXDATAP0 = USART_RXDOUBLEXP_RXDATAP0_SHIFT, 
    UART_RXDOUBLEXP_RXDATAP1 = USART_RXDOUBLEXP_RXDATAP1_SHIFT, 
} UARTRxDoubleDataExPkTypeDef;

/* Data Types for USART RXDOUBLEXP */
typedef enum
{
    UART_RXDOUBLEXP_FLAG_PERRP0 = USART_RXDOUBLEXP_PERRP0, 
    UART_RXDOUBLEXP_FLAG_FERRP0 = USART_RXDOUBLEXP_FERRP0, 
    UART_RXDOUBLEXP_FLAG_PERRP1 = USART_RXDOUBLEXP_PERRP1, 
    UART_RXDOUBLEXP_FLAG_FERRP1 = USART_RXDOUBLEXP_FERRP1, 
} UARTRxDoubleDataExPkErrorTypeDef;

/* Data Types for USART TXDOUBLEX */
typedef enum
{
    UART_TXDOUBLEX_TXDATA0 = USART_TXDOUBLEX_TXDATA0_SHIFT, 
    UART_TXDOUBLEX_TXDATA1 = USART_TXDOUBLEX_TXDATA1_SHIFT, 
} UARTTxDoubleDataExTypeDef;

/* Data Types for USART Interrupt */
typedef enum
{
    UART_INT_TXC     = USART_IF_TXC, 
    UART_INT_TXBL    = USART_IF_TXBL, 
    UART_INT_RXDATAV = USART_IF_RXDATAV, 
    UART_INT_RXFULL  = USART_IF_RXFULL, 
    UART_INT_RXOF    = USART_IF_RXOF, 
    UART_INT_RXUF    = USART_IF_RXUF, 
    UART_INT_TXOF    = USART_IF_TXOF, 
    UART_INT_TXUF    = USART_IF_TXUF, 
    UART_INT_PERR    = USART_IF_PERR, 
    UART_INT_FERR    = USART_IF_FERR, 
    UART_INT_MPAF    = USART_IF_MPAF, 
    UART_INT_SSM     = USART_IF_SSM,
    UART_INT_CCF     = USART_IF_CCF,
} UARTIntTypeDef;

/* Data Types for USART IRCTRL */
typedef enum
{
    UART_IRDA_TX_PULSE_WIDTH_ONE   = USART_IRCTRL_IRPW_ONE, 
    UART_IRDA_TX_PULSE_WIDTH_TWO   = USART_IRCTRL_IRPW_TWO, 
    UART_IRDA_TX_PULSE_WIDTH_THREE = USART_IRCTRL_IRPW_THREE, 
    UART_IRDA_TX_PULSE_WIDTH_FOUR  = USART_IRCTRL_IRPW_FOUR, 
} UARTIrDATxPulseWidthTypeDef;

typedef enum
{
    UART_IRDA_PRS_CH0 = USART_IRCTRL_IRPRSSEL_PRSCH0, 
    UART_IRDA_PRS_CH1 = USART_IRCTRL_IRPRSSEL_PRSCH1, 
    UART_IRDA_PRS_CH2 = USART_IRCTRL_IRPRSSEL_PRSCH2, 
    UART_IRDA_PRS_CH3 = USART_IRCTRL_IRPRSSEL_PRSCH3, 
    UART_IRDA_PRS_CH4 = USART_IRCTRL_IRPRSSEL_PRSCH4, 
    UART_IRDA_PRS_CH5 = USART_IRCTRL_IRPRSSEL_PRSCH5, 
    UART_IRDA_PRS_CH6 = USART_IRCTRL_IRPRSSEL_PRSCH6,
    UART_IRDA_PRS_CH7 = USART_IRCTRL_IRPRSSEL_PRSCH7, 
} UARTIrDAPRSChTypeDef;

/* Data Types for USART ROUTE */
typedef enum
{
    UART_LOC0 = USART_ROUTE_LOCATION_LOC0,
    UART_LOC1 = USART_ROUTE_LOCATION_LOC1,
    UART_LOC2 = USART_ROUTE_LOCATION_LOC2,
    UART_LOC3 = USART_ROUTE_LOCATION_LOC3,
    UART_LOC4 = USART_ROUTE_LOCATION_LOC4,
    UART_LOC5 = USART_ROUTE_LOCATION_LOC5,
} UARTLocationTypeDef;

/*************************************************************************************************************
*                                            FUNCTION PROTOTYPES                                             *
*************************************************************************************************************/
/* Function for USART CTRL */
static inline void UARTModeSet (UARTTypeDef x, UARTModeTypeDef mode)
{
    USARTRegTypeDef *usart;
    
    usart = (USARTRegTypeDef *)x;
    
    usart->CTRL &= ~USART_CTRL_SYNC_MASK;
    usart->CTRL |= mode;
}

static inline UARTModeTypeDef UARTModeGet (UARTTypeDef x)
{
    USARTRegTypeDef *usart;
    
    usart = (USARTRegTypeDef *)x;
    
    return  (UARTModeTypeDef)(usart->CTRL & USART_CTRL_SYNC_MASK);
}

static inline CPU_BOOL UARTModeFlagGet (UARTTypeDef x, UARTModeTypeDef mode)
{
    USARTRegTypeDef *usart;
    
    usart = (USARTRegTypeDef *)x;
    
    if (usart->CTRL & mode)
    {
        return DEF_ON;
    }
    else
    {
        return DEF_ON;
    }
}

static inline void UARTLookbackEnable (UARTTypeDef x)
{
    USARTRegTypeDef *usart;
    
    usart = (USARTRegTypeDef *)x;
    
    usart->CTRL |= USART_CTRL_LOOPBK;
}

static inline void UARTLookbackDisable (UARTTypeDef x)
{
    USARTRegTypeDef *usart;
    
    usart = (USARTRegTypeDef *)x;
    
    usart->CTRL &= ~USART_CTRL_LOOPBK;
}

static inline CPU_BOOL UARTLookbackFlagGet (UARTTypeDef x)
{
    USARTRegTypeDef *usart;
    
    usart = (USARTRegTypeDef *)x;
    
    if (usart->CTRL & USART_CTRL_LOOPBK_MASK)
    {
        return DEF_ON;
    }
    else
    {
        return DEF_OFF;
    }
}

static inline void UARTCollisionCheckEnable (UARTTypeDef x)
{
    USARTRegTypeDef *usart;
    
    usart = (USARTRegTypeDef *)x;
    
    usart->CTRL |= USART_CTRL_CCEN;
}

static inline void UARTCollisionCheckDisable (UARTTypeDef x)
{
    USARTRegTypeDef *usart;
    
    usart = (USARTRegTypeDef *)x;
    
    usart->CTRL &= ~USART_CTRL_CCEN;
}

static inline CPU_BOOL UARTCollisionCheckFlagGet (UARTTypeDef x)
{
    USARTRegTypeDef *usart;
    
    usart = (USARTRegTypeDef *)x;
    
    if (usart->CTRL & USART_CTRL_CCEN_MASK)
    {
        return DEF_ON;
    }
    else
    {
        return DEF_OFF;
    }
}

static inline void UARTMultiProcessorModeEnable (UARTTypeDef x)
{
    USARTRegTypeDef *usart;
    
    usart = (USARTRegTypeDef *)x;
    
    usart->CTRL |= USART_CTRL_MPM;
}

static inline void UARTMultiProcessorModeDisable (UARTTypeDef x)
{
    USARTRegTypeDef *usart;
    
    usart = (USARTRegTypeDef *)x;
    
    usart->CTRL &= ~USART_CTRL_MPM;
}

static inline CPU_BOOL UARTMultiProcessorModeFlagGet (UARTTypeDef x)
{
    USARTRegTypeDef *usart;
    
    usart = (USARTRegTypeDef *)x;
    
     if (usart->CTRL & USART_CTRL_MPM_MASK)
    {
        return DEF_ON;
    }
    else
    {
        return DEF_OFF;
    }
}

static inline void UARTMPMABitSet (UARTTypeDef x, UARTMPMABitTypeDef bit)
{
    USARTRegTypeDef *usart;
    
    usart = (USARTRegTypeDef *)x;
    
    usart->CTRL &= ~USART_CTRL_MPM_MASK;
    usart->CTRL |= bit;
}

static inline UARTMPMABitTypeDef UARTMPMABitGet (UARTTypeDef x)
{
    USARTRegTypeDef *usart;
    
    usart = (USARTRegTypeDef *)x;
    
    return (UARTMPMABitTypeDef)(usart->CTRL & USART_CTRL_MPM_MASK);
}

static inline CPU_BOOL UARTMPMABitFlagGet (UARTTypeDef x, UARTMPMABitTypeDef bit)
{
    USARTRegTypeDef *usart;
    
    usart = (USARTRegTypeDef *)x;
    
    if (usart->CTRL & bit)
    {
        return DEF_ON;
    }
    else
    {
        return DEF_OFF;
    }
}

static inline void UARTOversamplingSet (UARTTypeDef x, UARTOversamplingTypeDef oversampling)
{
    USARTRegTypeDef *usart;
    
    usart = (USARTRegTypeDef *)x;
    
    usart->CTRL &= ~USART_CTRL_OVS_MASK;
    usart->CTRL |= oversampling;
}

static inline UARTOversamplingTypeDef UARTOversamplingGet (UARTTypeDef x)
{
    USARTRegTypeDef *usart;
    
    usart = (USARTRegTypeDef *)x;
    
    return (UARTOversamplingTypeDef)(usart->CTRL & USART_CTRL_OVS_MASK);
}

static inline CPU_BOOL UARTOversamplingFlagGet (UARTTypeDef x, UARTOversamplingTypeDef oversampling)
{
    USARTRegTypeDef *usart;
    
    usart = (USARTRegTypeDef *)x;
    
    if (usart->CTRL & oversampling)
    {
        return DEF_ON;
    }
    else
    {
        return DEF_OFF;
    }
}

static inline void UARTClockPolaritySet (UARTTypeDef x, UARTClockPolarityTypeDef polarity)
{
    USARTRegTypeDef *usart;
    
    usart = (USARTRegTypeDef *)x;
    
    usart->CTRL &= ~USART_CTRL_CLKPOL_MASK;
    usart->CTRL |= polarity;
}

static inline UARTClockPolarityTypeDef UARTClockPolarityGet (UARTTypeDef x)
{
    USARTRegTypeDef *usart;
    
    usart = (USARTRegTypeDef *)x;
    
    return (UARTClockPolarityTypeDef)(usart->CTRL & USART_CTRL_CLKPOL_MASK);
}

static inline CPU_BOOL UARTClockPolarityFlagGet (UARTTypeDef x, UARTClockPolarityTypeDef polarity)
{
    USARTRegTypeDef *usart;
    
    usart = (USARTRegTypeDef *)x;
    
    if (usart->CTRL & polarity)
    {
        return DEF_ON;
    }
    else
    {
        return DEF_OFF;
    }
}

static inline void UARTSampleClockEdgeSet (UARTTypeDef x, UARTSampleClockEdgeTypeDef edge)
{
    USARTRegTypeDef *usart;
    
    usart = (USARTRegTypeDef *)x;
    
    usart->CTRL &= ~USART_CTRL_CLKPHA_MASK;
    usart->CTRL |= edge;
}

static inline UARTSampleClockEdgeTypeDef UARTSampleClockEdgeGet (UARTTypeDef x)
{
    USARTRegTypeDef *usart;
    
    usart = (USARTRegTypeDef *)x;
    
    return (UARTSampleClockEdgeTypeDef)(usart->CTRL & USART_CTRL_CLKPHA_MASK);
}

static inline CPU_BOOL UARTSampleClockEdgeFlagGet (UARTTypeDef x, UARTSampleClockEdgeTypeDef edge)
{
    USARTRegTypeDef *usart;
    
    usart = (USARTRegTypeDef *)x;
    
    if (usart->CTRL & edge)
    {
        return DEF_ON;
    }
    else
    {
        return DEF_OFF;
    }
}

static inline void UARTMSBFSet (UARTTypeDef x, UARTMSBFTypeDef msb)
{
    USARTRegTypeDef *usart;
    
    usart = (USARTRegTypeDef *)x;
    
    usart->CTRL &= ~USART_CTRL_MSBF_MASK;
    usart->CTRL |= msb;
}

static inline UARTMSBFTypeDef UARTMSBFGet (UARTTypeDef x)
{
    USARTRegTypeDef *usart;
    
    usart = (USARTRegTypeDef *)x;
    
    return (UARTMSBFTypeDef)(usart->CTRL & USART_CTRL_MSBF_MASK);
}

static inline CPU_BOOL UARTMSBFFlagGet (UARTTypeDef x, UARTMSBFTypeDef msb)
{
    USARTRegTypeDef *usart;
    
    usart = (USARTRegTypeDef *)x;
    
    if (usart->CTRL & msb)
    {
        return DEF_ON;
    }
    else
    {
        return DEF_OFF;
    }
}

static inline void UARTCSMASet (UARTTypeDef x, UARTCSMATypeDef csma)
{
    USARTRegTypeDef *usart;
    
    usart = (USARTRegTypeDef *)x;
    
    usart->CTRL &= ~USART_CTRL_CSMA_MASK;
    usart->CTRL |= csma;
}

static inline UARTCSMATypeDef UARTCSMAGet (UARTTypeDef x)
{
    USARTRegTypeDef *usart;
    
    usart = (USARTRegTypeDef *)x;
    
    return (UARTCSMATypeDef)(usart->CTRL & USART_CTRL_CSMA_MASK);
}

static inline CPU_BOOL UARTCSMAFlagGet (UARTTypeDef x, UARTCSMATypeDef csma)
{
    USARTRegTypeDef *usart;
    
    usart = (USARTRegTypeDef *)x;
    
    if (usart->CTRL & csma)
    {
        return DEF_ON;
    }
    else
    {
        return DEF_OFF;
    }
}

static inline void UARTTxIntLevelSet (UARTTypeDef x, UARTTxIntLevelTypeDef level)
{
    USARTRegTypeDef *usart;
    
    usart = (USARTRegTypeDef *)x;
    
    usart->CTRL &= ~USART_CTRL_TXBIL_MASK;
    usart->CTRL |= level;
}

static inline UARTTxIntLevelTypeDef UARTTxIntLevelGet (UARTTypeDef x)
{
    USARTRegTypeDef *usart;
    
    usart = (USARTRegTypeDef *)x;
    
    return (UARTTxIntLevelTypeDef)(usart->CTRL & USART_CTRL_TXBIL_MASK);
}

static inline CPU_BOOL UARTTxIntLevelFlagGet (USARTTypeDef x, UARTTxIntLevelTypeDef level)
{
    USARTRegTypeDef *usart;
    
    usart = (USARTRegTypeDef *)x;
    
    if (usart->CTRL & level)
    {
        return DEF_ON;
    }
    else
    {
        return DEF_OFF;
    }
}

static inline void UARTRxInputInvertEnable (UARTTypeDef x)
{
    USARTRegTypeDef *usart;
    
    usart = (USARTRegTypeDef *)x;
    
    usart->CTRL |= USART_CTRL_RXINV;
}

static inline void UARTRxInputInvertDisable (UARTTypeDef x)
{
    USARTRegTypeDef *usart;
    
    usart = (USARTRegTypeDef *)x;
    
    usart->CTRL &= ~USART_CTRL_RXINV;
}

static inline CPU_BOOL UARTRxInputInvertFlagGet (UARTTypeDef x)
{
    USARTRegTypeDef *usart;
    
    usart = (USARTRegTypeDef *)x;
    
    if (usart->CTRL & USART_CTRL_RXINV_MASK)
    {
        return DEF_ON;
    }
    else
    {
        return DEF_ON;
    }
}

static inline void UARTTxOutputInvertEnable (UARTTypeDef x)
{
    USARTRegTypeDef *usart;
    
    usart = (USARTRegTypeDef *)x;
    
    usart->CTRL |= USART_CTRL_TXINV;
}

static inline void UARTTxOutputInvertDisable (UARTTypeDef x)
{
    USARTRegTypeDef *usart;
    
    usart = (USARTRegTypeDef *)x;
    
    usart->CTRL &= ~USART_CTRL_TXINV;
}

static inline CPU_BOOL UARTTxOutputInvertFlagGet (UARTTypeDef x)
{
    USARTRegTypeDef *usart;
    
    usart = (USARTRegTypeDef *)x;
    
    if (usart->CTRL & USART_CTRL_TXINV_MASK)
    {
        return DEF_ON;
    }
    else
    {
        return DEF_OFF;
    }
}

static inline void UARTCSActiveSet (UARTTypeDef x, UARTCSActiveTypeDef active)
{
    USARTRegTypeDef *usart;
    
    usart = (USARTRegTypeDef *)x;
    
    usart->CTRL &= ~USART_CTRL_CSINV_MASK;
    usart->CTRL |= active;
}

static inline UARTCSActiveTypeDef UARTCSActiveGet (UARTTypeDef x)
{
    USARTRegTypeDef *usart;
    
    usart = (USARTRegTypeDef *)x;
    
    return (UARTCSActiveTypeDef)(usart->CTRL & USART_CTRL_CSINV_MASK);
}

static inline CPU_BOOL UARTCSActiveFlagGet (UARTTypeDef x, UARTCSActiveTypeDef active)
{
    USARTRegTypeDef *usart;
    
    usart = (USARTRegTypeDef *)x;
    
    if (usart->CTRL & active)
    {
        return DEF_ON;
    }
    else
    {
        return DEF_OFF;
    }
}

static inline void UARTCSAutoEnable (UARTTypeDef x)
{
    USARTRegTypeDef *usart;
    
    usart = (USARTRegTypeDef *)x;
    
    usart->CTRL |= USART_CTRL_AUTOCS;
}

static inline void UARTCSAutoDisable (UARTTypeDef x)
{
    USARTRegTypeDef *usart;
    
    usart = (USARTRegTypeDef *)x;
    
    usart->CTRL &= ~USART_CTRL_AUTOCS;
}

static inline CPU_BOOL UARTCSAutoFlagGet (UARTTypeDef x)
{
    USARTRegTypeDef *usart;
    
    usart = (USARTRegTypeDef *)x;
    
    if (usart->CTRL & USART_CTRL_AUTOCS_MASK)
    {
        return DEF_ON;
    }
    else
    {
        return DEF_OFF;
    }
}

static inline void UARTTxAutoTRIEnable (UARTTypeDef x)
{
    USARTRegTypeDef *usart;
    
    usart = (USARTRegTypeDef *)x;
    
    usart->CTRL |= USART_CTRL_AUTOTRI;
}

static inline void UARTTxAutoTRIDisable (UARTTypeDef x)
{
    USARTRegTypeDef *usart;
    
    usart = (USARTRegTypeDef *)x;
    
    usart->CTRL &= ~USART_CTRL_AUTOTRI;
}

static inline CPU_BOOL UARTTxAutoTRIFlagGet (UARTTypeDef x)
{
    USARTRegTypeDef *usart;
    
    usart = (USARTRegTypeDef *)x;
    
    if (usart->CTRL & USART_CTRL_AUTOTRI_MASK)
    {
        return DEF_ON;
    }
    else
    {
        return DEF_OFF;
    }
}

static inline void UARTSmartCardModeEnable (UARTTypeDef x)
{
    USARTRegTypeDef *usart;
    
    usart = (USARTRegTypeDef *)x;
    
    usart->CTRL |= USART_CTRL_SCMODE;
}

static inline void UARTSmartCardModeDisable (UARTTypeDef x)
{
    USARTRegTypeDef *usart;
    
    usart = (USARTRegTypeDef *)x;
    
    usart->CTRL &= ~USART_CTRL_SCMODE;
}

static inline CPU_BOOL UARTSmartCardModeGetFlag (UARTTypeDef x)
{
    USARTRegTypeDef *usart;
    
    usart = (USARTRegTypeDef *)x;
    
    if (usart->CTRL & USART_CTRL_SCMODE_MASK)
    {
        return DEF_ON;
    }
    else
    {
        return DEF_OFF;
    }
}

static inline void UARTSmartCardRetransmitEnable (UARTTypeDef x)
{
    USARTRegTypeDef *usart;
    
    usart = (USARTRegTypeDef *)x;
    
    usart->CTRL |= USART_CTRL_SCRETRANS;
}

static inline void UARTSmartCardRetransmitDisable (UARTTypeDef x)
{
    USARTRegTypeDef *usart;
    
    usart = (USARTRegTypeDef *)x;
    
    usart->CTRL &= ~USART_CTRL_SCRETRANS;
}

static inline CPU_BOOL UARTSmartCardRetransmitFlagGet (UARTTypeDef x)
{
    USARTRegTypeDef *usart;
    
    usart = (USARTRegTypeDef *)x;
    
    if (usart->CTRL & USART_CTRL_SCRETRANS_MASK)
    {
        return DEF_ON;
    }
    else
    {
        return DEF_OFF;
    }
}

static inline void UARTParityErrorEnable (UARTTypeDef x)
{
    USARTRegTypeDef *usart;
    
    usart = (USARTRegTypeDef *)x;
    
    usart->CTRL |= USART_CTRL_SKIPPERRF;
}

static inline void UARTParityErrorDisable (UARTTypeDef x)
{
    USARTRegTypeDef *usart;
    
    usart = (USARTRegTypeDef *)x;
    
    usart->CTRL &= ~USART_CTRL_SKIPPERRF;
}

static inline CPU_BOOL UARTParityErrorFlagGet (UARTTypeDef x)
{
    USARTRegTypeDef *usart;
    
    usart = (USARTRegTypeDef *)x;
    
    if (usart->CTRL & USART_CTRL_SKIPPERRF_MASK)
    {
        return DEF_ON;
    }
    else
    {
        return DEF_OFF;
    }
}

static inline void UARTBit8DefaultValueSet (UARTTypeDef x, UARTBit8DefaultValueTypeDef value)
{
    USARTRegTypeDef *usart;
    
    usart = (USARTRegTypeDef *)x;
    
    usart->CTRL &= ~USART_CTRL_BIT8DV_MASK;
    usart->CTRL |= value;
}

static inline UARTBit8DefaultValueTypeDef UARTBit8DefaultValueGet (UARTTypeDef x)
{
    USARTRegTypeDef *usart;
    
    usart = (USARTRegTypeDef *)x;
    
    return (UARTBit8DefaultValueTypeDef)(usart->CTRL & USART_CTRL_BIT8DV_MASK);
}

static inline CPU_BOOL UARTBit8DefaultValueFlagGet (UARTTypeDef x, UARTBit8DefaultValueTypeDef value)
{
    USARTRegTypeDef *usart;
    
    usart = (USARTRegTypeDef *)x;
    
    if (usart->CTRL & value)
    {
        return DEF_ON;
    }
    else
    {
        return DEF_OFF;
    }
}

static inline void UARTHaltDMAOnErrorEnable (UARTTypeDef x)
{
    USARTRegTypeDef *usart;
    
    usart = (USARTRegTypeDef *)x;
    
    usart->CTRL |= USART_CTRL_ERRSDMA;
}

static inline void UARTHaltDMAOnErrorDisable (UARTTypeDef x)
{
    USARTRegTypeDef *usart;
    
    usart = (USARTRegTypeDef *)x;
    
    usart->CTRL &= ~USART_CTRL_ERRSDMA;
}

static inline CPU_BOOL UARTHaltDMAOnErrorFlagGet (UARTTypeDef x)
{
    USARTRegTypeDef *usart;
    
    usart = (USARTRegTypeDef *)x;
    
    if (usart->CTRL & USART_CTRL_ERRSDMA_MASK)
    {
        return DEF_ON;
    }
    else
    {
        return DEF_OFF;
    }
}

static inline void UARTDisableRxOnErrorEnable (UARTTypeDef x)
{
    USARTRegTypeDef *usart;
    
    usart = (USARTRegTypeDef *)x;
    
    usart->CTRL |= USART_CTRL_ERRSRX;
}

static inline void UARTDisableRxOnErrorDisable (UARTTypeDef x)
{
    USARTRegTypeDef *usart;
    
    usart = (USARTRegTypeDef *)x;
    
    usart->CTRL &= ~USART_CTRL_ERRSRX;
}

static inline CPU_BOOL UARTDisableRxOnErrorFlagGet (UARTTypeDef x)
{
    USARTRegTypeDef *usart;
    
    usart = (USARTRegTypeDef *)x;
    
    if (usart->CTRL & USART_CTRL_ERRSRX_MASK)
    {
        return DEF_ON;
    }
    else
    {
        return DEF_OFF;
    }
}

static inline void UARTDisableTxOnErrorEnable (UARTTypeDef x)
{
    USARTRegTypeDef *usart;
    
    usart = (USARTRegTypeDef *)x;
    
    usart->CTRL |= USART_CTRL_ERRSTX;
}

static inline void UARTDisableTxOnErrorDisable (UARTTypeDef x)
{
    USARTRegTypeDef *usart;
    
    usart = (USARTRegTypeDef *)x;
    
    usart->CTRL &= ~USART_CTRL_ERRSTX;
}

static inline CPU_BOOL UARTDisableTxOnErrorFlagGet (UARTTypeDef x)
{
    USARTRegTypeDef *usart;
    
    usart = (USARTRegTypeDef *)x;
    
    if (usart->CTRL & USART_CTRL_ERRSTX_MASK)
    {
        return DEF_ON;
    }
    else
    {
        return DEF_OFF;
    }
}

static inline void UARTTxDelaySet (UARTTypeDef x, UARTTxDelayTypeDef delay)
{
    USARTRegTypeDef *usart;
    
    usart = (USARTRegTypeDef *)x;
    
    usart->CTRL &= ~USART_CTRL_TXDELAY_MASK;
    usart->CTRL |= delay;
}

static inline UARTTxDelayTypeDef UARTTxDelayGet (UARTTypeDef x)
{
    USARTRegTypeDef *usart;
    
    usart = (USARTRegTypeDef *)x;
    
    return (UARTTxDelayTypeDef)(usart->CTRL & USART_CTRL_TXDELAY_MASK);
}

static inline CPU_BOOL UARTTxDelayFlagGet (UARTTypeDef x, UARTTxDelayTypeDef delay)
{
    USARTRegTypeDef *usart;
    
    usart = (USARTRegTypeDef *)x;
    
    if (usart->CTRL & delay)
    {
        return DEF_ON;
    }
    else
    {
        return DEF_OFF;
    }
}

static inline void UARTByteswapInDoubleAccessesEnable (UARTTypeDef x)
{
    USARTRegTypeDef *usart;
    
    usart = (USARTRegTypeDef *)x;
    
    usart->CTRL |= USART_CTRL_BYTESWAP;
}

static inline void UARTByteswapInDoubleAccessesDisable (UARTTypeDef x)
{
    USARTRegTypeDef *usart;
    
    usart = (USARTRegTypeDef *)x;
    
    usart->CTRL &= ~USART_CTRL_BYTESWAP;
}

static inline CPU_BOOL UARTByteswapInDoubleAccessesFlagGet (UARTTypeDef x)
{
    USARTRegTypeDef *usart;
    
    usart = (USARTRegTypeDef *)x;
    
    if (usart->CTRL & USART_CTRL_BYTESWAP_MASK)
    {
        return DEF_ON;
    }
    else
    {
        return DEF_OFF;
    }
}

/* Function for USART FRAME */
static inline void UARTDataBitSet (UARTTypeDef x, UARTDataBitTypeDef bit)
{
    USARTRegTypeDef *usart;
    
    usart = (USARTRegTypeDef *)x;
    
    usart->FRAME &= ~USART_FRAME_DATABITS_MASK;
    usart->FRAME |= bit;
}

static inline UARTDataBitTypeDef UARTDataBitGet (UARTTypeDef x)
{
    USARTRegTypeDef *usart;
    
    usart = (USARTRegTypeDef *)x;
    
    return (UARTDataBitTypeDef)(usart->FRAME & USART_FRAME_DATABITS_MASK);
}

static inline CPU_BOOL UARTDataBitFlagGet (UARTTypeDef x, UARTDataBitTypeDef bit)
{
    USARTRegTypeDef *usart;
    
    usart = (USARTRegTypeDef *)x;
    
    if (usart->CTRL & bit)
    {
        return DEF_ON;
    }
    else
    {
        return DEF_OFF;
    }
}

static inline void UARTParityModeSet (UARTTypeDef x, UARTParityModeTypeDef parity)
{
    USARTRegTypeDef *usart;
    
    usart = (USARTRegTypeDef *)x;
    
    usart->FRAME &= ~USART_FRAME_PARITY_MASK;
    usart->FRAME |= parity;
}

static inline UARTParityModeTypeDef UARTParityModeGet (UARTTypeDef x)
{
    USARTRegTypeDef *usart;
    
    usart = (USARTRegTypeDef *)x;
    
    return (UARTParityModeTypeDef)(usart->FRAME & USART_FRAME_PARITY_MASK);
}

static inline CPU_BOOL UARTParityModeFlagGet (UARTTypeDef x, UARTParityModeTypeDef parity)
{
    USARTRegTypeDef *usart;
    
    usart = (USARTRegTypeDef *)x;
    
    if (usart->CTRL & parity)
    {
        return DEF_ON;
    }
    else
    {
        return DEF_OFF;
    }
}

static inline void UARTStopModeSet (UARTTypeDef x, UARTStopModeTypeDef stop)
{
    USARTRegTypeDef *usart;
    
    usart = (USARTRegTypeDef *)x;
    
    usart->FRAME &= ~USART_FRAME_STOPBITS_MASK;
    usart->FRAME |= stop;
}

static inline UARTStopModeTypeDef UARTStopModeGet (UARTTypeDef x)
{
    USARTRegTypeDef *usart;
    
    usart = (USARTRegTypeDef *)x;
    
    return (UARTStopModeTypeDef)(usart->FRAME & USART_FRAME_STOPBITS_MASK);
}

static inline CPU_BOOL UARTStopModeFlagGet (UARTTypeDef x, UARTStopModeTypeDef stop)
{
    USARTRegTypeDef *usart;
    
    usart = (USARTRegTypeDef *)x;
    
    if (usart->CTRL & stop)
    {
        return DEF_ON;
    }
    else
    {
        return DEF_OFF;
    }
}

/* Function for USART TRIGCTRL */
static inline void UARTTriggerPRSChSet (UARTTypeDef x, UARTTriggerPRSChTypeDef ch)
{
    USARTRegTypeDef *usart;
    
    usart = (USARTRegTypeDef *)x;
    
    usart->TRIGCTRL &= ~USART_TRIGCTRL_TSEL_MASK;
    usart->TRIGCTRL |= ch;
}

static inline UARTTriggerPRSChTypeDef UARTTriggerPRSChGet (UARTTypeDef x)
{
    USARTRegTypeDef *usart;
    
    usart = (USARTRegTypeDef *)x;
    
    return (UARTTriggerPRSChTypeDef)(usart->TRIGCTRL & USART_TRIGCTRL_TSEL_MASK);
}

static inline CPU_BOOL UARTTriggerPRSChFlagGet (UARTTypeDef x, UARTTriggerPRSChTypeDef ch)
{
    USARTRegTypeDef *usart;
    
    usart = (USARTRegTypeDef *)x;
    
    if (usart->CTRL & ch)
    {
        return DEF_ON;
    }
    else
    {
        return DEF_OFF;
    }
}

static inline void UARTRxTriggerPRSEnable (UARTTypeDef x)
{
    USARTRegTypeDef *usart;
    
    usart = (USARTRegTypeDef *)x;
    
    usart->TRIGCTRL |= USART_TRIGCTRL_RXTEN;
}

static inline void UARTRxTriggerPRSDisable (UARTTypeDef x)
{
    USARTRegTypeDef *usart;
    
    usart = (USARTRegTypeDef *)x;
    
    usart->TRIGCTRL &= ~USART_TRIGCTRL_RXTEN;
}

static inline CPU_BOOL UARTRxTriggerPRSFlagGet (UARTTypeDef x)
{
    USARTRegTypeDef *usart;
    
    usart = (USARTRegTypeDef *)x;
    
    if (usart->CTRL & USART_TRIGCTRL_RXTEN_MASK)
    {
        return DEF_ON;
    }
    else
    {
        return DEF_OFF;
    }
}

static inline void UARTTxTriggerPRSEnable (UARTTypeDef x)
{
    USARTRegTypeDef *usart;
    
    usart = (USARTRegTypeDef *)x;
    
    usart->TRIGCTRL |= USART_TRIGCTRL_TXTEN;
}

static inline void UARTTxTriggerPRSDisable (UARTTypeDef x)
{
    USARTRegTypeDef *usart;
    
    usart = (USARTRegTypeDef *)x;
    
    usart->TRIGCTRL &= ~USART_TRIGCTRL_TXTEN;
}

static inline CPU_BOOL UARTTxTriggerPRSFlagGet (UARTTypeDef x)
{
    USARTRegTypeDef *usart;
    
    usart = (USARTRegTypeDef *)x;
    
    if (usart->CTRL & USART_TRIGCTRL_TXTEN_MASK)
    {
        return DEF_ON;
    }
    else
    {
        return DEF_OFF;
    }
}

/* Function for USART CMD */
static inline void UARTCmd (UARTTypeDef x, CPU_INT32U cmd)
{
    USARTRegTypeDef *usart;
    
    usart = (USARTRegTypeDef *)x;
    
    usart->CMD |= cmd;
}

static inline void UARTCmdRxEnable (UARTTypeDef x)
{
    USARTRegTypeDef *usart;
    
    usart = (USARTRegTypeDef *)x;
    
    usart->CMD |= USART_CMD_RXEN;
}

static inline void UARTCmdRxDisable (UARTTypeDef x)
{
    USARTRegTypeDef *usart;
    
    usart = (USARTRegTypeDef *)x;
    
    usart->CMD |= USART_CMD_RXDIS;
}

static inline void UARTCmdTxEnable (UARTTypeDef x)
{
    USARTRegTypeDef *usart;
    
    usart = (USARTRegTypeDef *)x;
    
    usart->CMD |= USART_CMD_TXEN;
}

static inline void UARTCmdTxDisable (UARTTypeDef x)
{
    USARTRegTypeDef *usart;
    
    usart = (USARTRegTypeDef *)x;
    
    usart->CMD |= USART_CMD_TXDIS;
}

static inline void UARTCmdMasterEnable (UARTTypeDef x)
{
    USARTRegTypeDef *usart;
    
    usart = (USARTRegTypeDef *)x;
    
    usart->CMD |= USART_CMD_MASTEREN;
}

static inline void UARTCmdMasterDisable (UARTTypeDef x)
{
    USARTRegTypeDef *usart;
    
    usart = (USARTRegTypeDef *)x;
    
    usart->CMD |= USART_CMD_MASTERDIS;
}

static inline void UARTCmdRxBlockEnable (UARTTypeDef x)
{
    USARTRegTypeDef *usart;
    
    usart = (USARTRegTypeDef *)x;
    
    usart->CMD |= USART_CMD_RXBLOCKEN;
}

static inline void UARTCmdRxBlockDisable (UARTTypeDef x)
{
    USARTRegTypeDef *usart;
    
    usart = (USARTRegTypeDef *)x;
    
    usart->CMD |= USART_CMD_RXBLOCKDIS;
}

static inline void UARTCmdTxTristateEnable (UARTTypeDef x)
{
    USARTRegTypeDef *usart;
    
    usart = (USARTRegTypeDef *)x;
    
    usart->CMD |= USART_CMD_TXTRIEN;
}

static inline void UARTCmdTxTristateDisable (UARTTypeDef x)
{
    USARTRegTypeDef *usart;
    
    usart = (USARTRegTypeDef *)x;
    
    usart->CMD |= USART_CMD_TXTRIDIS;
}

static inline void UARTCmdTxClear (UARTTypeDef x)
{
    USARTRegTypeDef *usart;
    
    usart = (USARTRegTypeDef *)x;
    
    usart->CMD |= USART_CMD_CLEARTX;
}

static inline void UARTCmdRxClear (UARTTypeDef x)
{
    USARTRegTypeDef *usart;
    
    usart = (USARTRegTypeDef *)x;
    
    usart->CMD |= USART_CMD_CLEARRX;
}

/* Function for USART STATUS */
static inline UARTStatusTypeDef UARTStatusGet (UARTTypeDef x)
{
    USARTRegTypeDef *usart;
    
    usart = (USARTRegTypeDef *)x;
    
    return (UARTStatusTypeDef)(usart->STATUS & USART_STATUS_MASK);
}

static inline CPU_BOOL UARTStatusFlagGet (UARTTypeDef x, UARTStatusTypeDef flag)
{
    USARTRegTypeDef *usart;
    
    usart = (USARTRegTypeDef *)x;
    
    if (usart->STATUS & flag)
    {
        return DEF_ON;
    }
    else
    {
        return DEF_OFF;
    }
}

/* Function for USART CLKDIV */
void static inline UARTClockDivSet (UARTTypeDef x, CPU_INT32U div)
{
    USARTRegTypeDef *usart;
    
    usart = (USARTRegTypeDef *)x;
    usart->CLKDIV = (div << USART_CLKDIV_DIV_SHIFT);
}

static inline CPU_INT32U UARTClockDivGet (UARTTypeDef x)
{
    USARTRegTypeDef *usart;
    
    usart = (USARTRegTypeDef *)x;
    
    return ((usart->CLKDIV & USART_CLKDIV_DIV_MASK) >> USART_CLKDIV_DIV_SHIFT);
}

/* Function for USART RXDATAX */
static inline CPU_INT16U UARTRxDataExGet (UARTTypeDef x)
{
    USARTRegTypeDef *usart;
    
    usart = (USARTRegTypeDef *)x;
    
    return (CPU_INT16U)(usart->RXDATAX & USART_RXDATAX_RXDATA_MASK);
}

static inline UARTRxDataExErrorTypeDef UARTRxDataExErrorGet (UARTTypeDef x)
{
    USARTRegTypeDef *usart;
    
    usart = (USARTRegTypeDef *)x;
    
    return (UARTRxDataExErrorTypeDef)(usart->RXDATAX & (USART_RXDATAX_PERR_MASK | USART_RXDATAX_FERR_MASK));
}

static inline CPU_BOOL UARTRxDataExErrorFlagGet (UARTTypeDef x, UARTRxDataExErrorTypeDef flag)
{
    USARTRegTypeDef *usart;
    
    usart = (USARTRegTypeDef *)x;
    
    if (usart->RXDATAX & flag)
    {
        return DEF_ON;
    }
    else
    {
        return DEF_OFF;
    }
}

/* Function for USART RXDATA */
static inline CPU_INT8U UARTRxDataGet (UARTTypeDef x)
{
    USARTRegTypeDef *usart;
    
    usart = (USARTRegTypeDef *)x;
    
    return (CPU_INT8U)(usart->RXDATA & USART_RXDATA_MASK);
}

/* Function for USART RXDOUBLEX */
static inline CPU_INT16U UARTRxDoubleDataExGet (UARTTypeDef x, UARTRxDoubleDataExTypeDef rx)
{
    USARTRegTypeDef *usart;
    
    usart = (USARTRegTypeDef *)x;
    
    return (CPU_INT16U)((usart->RXDOUBLEX & (USART_RXDOUBLEX_RXDATA0_MASK << rx)) >> rx);
}

static inline UARTRxDoubleDataExErrorTypeDef UARTRxDoubleDataExErrorGet (UARTTypeDef x)
{
    USARTRegTypeDef *usart;
    
    usart = (USARTRegTypeDef *)x;
    
    return (UARTRxDoubleDataExErrorTypeDef)(usart->RXDOUBLEX & 
                                            (USART_RXDOUBLEX_PERR0_MASK | USART_RXDOUBLEX_PERR0_MASK | 
                                             USART_RXDOUBLEX_PERR1_MASK | USART_RXDOUBLEX_PERR1_MASK));
}

static inline CPU_BOOL UARTRxDoubleDataExErrorFlagGet (UARTTypeDef x, UARTRxDoubleDataExErrorTypeDef flag)
{
    USARTRegTypeDef *usart;
    
    usart = (USARTRegTypeDef *)x;
    
    if (usart->RXDOUBLEX & flag)
    {
        return DEF_ON;
    }
    else
    {
        return DEF_OFF;
    }
}

/* Function for USART RXDOUBLE */
static inline CPU_INT16U UARTRxDoubleDataGet (UARTTypeDef x)
{
    USARTRegTypeDef *usart;
    
    usart = (USARTRegTypeDef *)x;
    
    return (CPU_INT16U)(usart->RXDOUBLE & USART_RXDOUBLE_MASK);
}

/* Function for USART RXDATAXP */
static inline CPU_INT16U UARTRxDataExPkGet (UARTTypeDef x)
{
    USARTRegTypeDef *usart;
    
    usart = (USARTRegTypeDef *)x;
    
    return (CPU_INT16U)(usart->RXDATAXP & USART_RXDATAXP_RXDATAP_MASK);
}

static inline UARTRxDataExErrorPkTypeDef UARTRxDataExPkErrorGet (UARTTypeDef x)
{
    USARTRegTypeDef *usart;
    
    usart = (USARTRegTypeDef *)x;
    
    return (UARTRxDataExErrorPkTypeDef)(usart->RXDATAXP & (USART_RXDATAXP_PERRP_MASK | USART_RXDATAXP_FERRP_MASK));
}

static inline CPU_BOOL UARTRxDataExErrorPkFlagGet (UARTTypeDef x, UARTRxDataExErrorPkTypeDef flag)
{
    USARTRegTypeDef *usart;
    
    usart = (USARTRegTypeDef *)x;
    
    if (usart->RXDATAXP & flag)
    {
        return DEF_ON;
    }
    else
    {
        return DEF_OFF;
    }
}

/* Function for USART RXDATAXP */
static inline CPU_INT16U UARTRxDoubleDataExPkGet (UARTTypeDef x, UARTRxDoubleDataExPkTypeDef rx)
{
    USARTRegTypeDef *usart;
    
    usart = (USARTRegTypeDef *)x;
    
    return (CPU_INT16U)((usart->RXDOUBLEXP & (USART_RXDOUBLEXP_RXDATAP0_MASK << rx)) >> rx);
}

static inline UARTRxDoubleDataExPkErrorTypeDef UARTRxDoubleDataExPkErrorGet (UARTTypeDef x)
{
    USARTRegTypeDef *usart;
    
    usart = (USARTRegTypeDef *)x;
    
    return (UARTRxDoubleDataExPkErrorTypeDef)(usart->RXDOUBLEXP & 
                                              (USART_RXDOUBLEXP_PERRP0_MASK | USART_RXDOUBLEXP_PERRP0_MASK | 
                                               USART_RXDOUBLEXP_PERRP1_MASK | USART_RXDOUBLEXP_PERRP1_MASK));
}

static inline CPU_BOOL UARTRxDoubleDataExPkErrorFlagGet (UARTTypeDef x, UARTRxDoubleDataExPkErrorTypeDef flag)
{
    USARTRegTypeDef *usart;
    
    usart = (USARTRegTypeDef *)x;
    
    if (usart->RXDOUBLEXP & flag)
    {
        return DEF_ON;
    }
    else
    {
        return DEF_OFF;
    }
}

/* Function for USART TXDATAX */
static inline void UARTTxDataExSet (UARTTypeDef x, CPU_INT16U data)
{
    USARTRegTypeDef *usart;
    
    usart = (USARTRegTypeDef *)x;
    
    usart->TXDATAX &= ~USART_TXDATAX_TXDATAX_MASK;
    usart->TXDATAX |= (data & USART_TXDATAX_TXDATAX_MASK);
}

static inline void UARTAfterTxDataExUnblockRxEnable (UARTTypeDef x)
{
    USARTRegTypeDef *usart;
    
    usart = (USARTRegTypeDef *)x;
    
    usart->TXDATAX |= USART_TXDATAX_UBRXAT;
}

static inline void UARTAfterTxDataExUnblockRxDisable (UARTTypeDef x)
{
    USARTRegTypeDef *usart;
    
    usart = (USARTRegTypeDef *)x;
    
    usart->TXDATAX &= ~USART_TXDATAX_UBRXAT;
}

static inline void UARTAfterTxDataExSetTxTRIEnable (UARTTypeDef x)
{
    USARTRegTypeDef *usart;
    
    usart = (USARTRegTypeDef *)x;
    
    usart->TXDATAX |= USART_TXDATAX_TXTRIAT;
}

static inline void UARTAfterTxDataExSetTxTRIDisable (UARTTypeDef x)
{
    USARTRegTypeDef *usart;
    
    usart = (USARTRegTypeDef *)x;
    
    usart->TXDATAX &= ~USART_TXDATAX_TXTRIAT;
}

static inline void UARTTxDataExAsBreakEnable (UARTTypeDef x)
{
    USARTRegTypeDef *usart;
    
    usart = (USARTRegTypeDef *)x;
    
    usart->TXDATAX |= USART_TXDATAX_TXBREAK;
}

static inline void UARTTxDataExAsBreakDisable (UARTTypeDef x)
{
    USARTRegTypeDef *usart;
    
    usart = (USARTRegTypeDef *)x;
    
    usart->TXDATAX &= ~USART_TXDATAX_TXBREAK;
}

static inline void UARTAfterTxDataExDisableTxEnable (UARTTypeDef x)
{
    USARTRegTypeDef *usart;
    
    usart = (USARTRegTypeDef *)x;
    
    usart->TXDATAX |= USART_TXDATAX_TXDISAT;
}

static inline void UARTAfterTxDataExDisableTxDisable (UARTTypeDef x)
{
    USARTRegTypeDef *usart;
    
    usart = (USARTRegTypeDef *)x;
    
    usart->TXDATAX &= ~USART_TXDATAX_TXDISAT;
}

static inline void UARTAfterTxDataExEnableRxEnable (UARTTypeDef x)
{
    USARTRegTypeDef *usart;
    
    usart = (USARTRegTypeDef *)x;
    
    usart->TXDATAX |= USART_TXDATAX_RXENAT;
}

static inline void UARTAfterTxDataExEnableRxDisable (UARTTypeDef x)
{
    USARTRegTypeDef *usart;
    
    usart = (USARTRegTypeDef *)x;
    
    usart->TXDATAX &= ~USART_TXDATAX_RXENAT;
}

/* Function for USART TXDATA */
static inline void UARTTxDataSet (UARTTypeDef x, CPU_INT8U data)
{
    USARTRegTypeDef *usart;
    
    usart = (USARTRegTypeDef *)x;
    
    usart->TXDATA = data;
}

/* Function for USART TXDOUBLEX */
static inline void UARTTxDoubleDataExSet (UARTTypeDef x, UARTTxDoubleDataExTypeDef tx, CPU_INT16U data)
{
    USARTRegTypeDef *usart;
    
    usart = (USARTRegTypeDef *)x;
    
    usart->TXDOUBLEX |= (data << tx);
}

static inline void UARTAfterTxDoubleDataExUnblockRxEnable (UARTTypeDef x, UARTTxDoubleDataExTypeDef tx)
{
    USARTRegTypeDef *usart;
    
    usart = (USARTRegTypeDef *)x;
    
    usart->TXDOUBLEX |= (USART_TXDOUBLEX_UBRXAT0 << tx);
}

static inline void UARTAfterTxDoubleDataExUnblockRxDisable (UARTTypeDef x, UARTTxDoubleDataExTypeDef tx)
{
    USARTRegTypeDef *usart;
    
    usart = (USARTRegTypeDef *)x;
    
    usart->TXDOUBLEX &= ~(USART_TXDOUBLEX_UBRXAT0 << tx);
}

static inline void UARTAfterTxDoubleDataExSetTxTRIEnable (UARTTypeDef x, UARTTxDoubleDataExTypeDef tx)
{
    USARTRegTypeDef *usart;
    
    usart = (USARTRegTypeDef *)x;
    
    usart->TXDOUBLEX |= (USART_TXDOUBLEX_TXTRIAT0 << tx);
}

static inline void UARTAfterTxDoubleDataExSetTxTRIDisable (UARTTypeDef x, UARTTxDoubleDataExTypeDef tx)
{
    USARTRegTypeDef *usart;
    
    usart = (USARTRegTypeDef *)x;
    
    usart->TXDOUBLEX &= ~(USART_TXDOUBLEX_TXTRIAT0 << tx);
}

static inline void UARTTxDoubleDataExAsBreakEnable (UARTTypeDef x, UARTTxDoubleDataExTypeDef tx)
{
    USARTRegTypeDef *usart;
    
    usart = (USARTRegTypeDef *)x;
    
    usart->TXDOUBLEX |= (USART_TXDOUBLEX_TXBREAK0 << tx);
}

static inline void UARTTxDoubleDataExAsBreakDisable (UARTTypeDef x, UARTTxDoubleDataExTypeDef tx)
{
    USARTRegTypeDef *usart;
    
    usart = (USARTRegTypeDef *)x;
    
    usart->TXDOUBLEX &= ~(USART_TXDOUBLEX_TXBREAK0 << tx);
}

static inline void UARTAfterTxDoubleDataExDisableTxEnable (UARTTypeDef x, UARTTxDoubleDataExTypeDef tx)
{
    USARTRegTypeDef *usart;
    
    usart = (USARTRegTypeDef *)x;
    
    usart->TXDOUBLEX |= (USART_TXDOUBLEX_TXDISAT0 << tx);
}

static inline void UARTAfterTxDoubleDataExDisableTxDisable (UARTTypeDef x, UARTTxDoubleDataExTypeDef tx)
{
    USARTRegTypeDef *usart;
    
    usart = (USARTRegTypeDef *)x;
    
    usart->TXDOUBLEX &= ~(USART_TXDOUBLEX_TXDISAT0 << tx);
}

static inline void UARTAfterTxDoubleDataExEnableRxEnable (UARTTypeDef x, UARTTxDoubleDataExTypeDef tx)
{
    USARTRegTypeDef *usart;
    
    usart = (USARTRegTypeDef *)x;
    
    usart->TXDOUBLEX |= (USART_TXDOUBLEX_RXENAT0 << tx);
}

static inline void UARTAfterTxDoubleDataExEnableRxDisable (UARTTypeDef x, UARTTxDoubleDataExTypeDef tx)
{
    USARTRegTypeDef *usart;
    
    usart = (USARTRegTypeDef *)x;
    
    usart->TXDOUBLEX &= ~(USART_TXDOUBLEX_RXENAT0 << tx);
}

/* Function for USART TXDOUBLE */
static inline void UARTTxDoubleData1Set (UARTTypeDef x, CPU_INT16U data)
{
    USARTRegTypeDef *usart;
    
    usart = (USARTRegTypeDef *)x;

    usart->TXDOUBLE = (data & USART_TXDATA_TXDATA_MASK);
}

/* Function for USART IF */
static inline CPU_INT32U UARTIntGet (UARTTypeDef x)
{
    USARTRegTypeDef *usart;
    
    usart = (USARTRegTypeDef *)x;
    
    return (CPU_INT32U)(usart->IF & USART_IF_MASK);
}

static inline CPU_BOOL UARTIntFlagGet (UARTTypeDef x, UARTIntTypeDef flag)
{
    USARTRegTypeDef *usart;
    
    usart = (USARTRegTypeDef *)x;
    
    if (usart->IF & flag)
    {
        return DEF_ON;
    }
    else
    {
        return DEF_OFF;
    }
}

/* Function for USART IFS */
static inline void UARTIntSet (UARTTypeDef x, CPU_INT32U flag)
{
    USARTRegTypeDef *usart;
    
    usart = (USARTRegTypeDef *)x;
    
    usart->IFS |= flag;
}

/* Function for USART IFC */
static inline void UARTIntClear (UARTTypeDef x, CPU_INT32U flag)
{
    USARTRegTypeDef *usart;
    
    usart = (USARTRegTypeDef *)x;
    
    usart->IFC |= flag;
}

/* Function for USART IEN */
static inline void UARTIntEnable (UARTTypeDef x, CPU_INT32U flag)
{
    USARTRegTypeDef *usart;
    
    usart = (USARTRegTypeDef *)x;
    
    usart->IEN |= flag;
}

static inline void UARTIntDisable (UARTTypeDef x, CPU_INT32U flag)
{
    USARTRegTypeDef *usart;
    
    usart = (USARTRegTypeDef *)x;
    
    usart->IEN &= ~flag;
}

static inline CPU_INT32U UARTIntStatusGet (UARTTypeDef x)
{
    USARTRegTypeDef *usart;
    
    usart = (USARTRegTypeDef *)x;
    
    return (CPU_INT32U)(usart->IEN & USART_IEN_MASK);
}

static inline CPU_BOOL UARTIntStatusFlagGet (UARTTypeDef x, UARTIntTypeDef flag)
{
    USARTRegTypeDef *usart;
    
    usart = (USARTRegTypeDef *)x;
    
    if (usart->IEN & flag)
    {
        return DEF_ON;
    }
    else
    {
        return DEF_OFF;
    }
}

static inline CPU_INT32U UARTIntEnableGet (UARTTypeDef x)
{
    USARTRegTypeDef *usart;
    CPU_INT32U en;
    
    usart = (USARTRegTypeDef *)x;
    
    en = 0;
    en = usart->IEN;

    /* Bitwise AND of pending and enabled interrupts */
    return (CPU_INT32U)((usart->IF & en) & USART_IF_MASK);
}

static inline CPU_BOOL UARTIntEnableFlagGet (UARTTypeDef x, UARTIntTypeDef flag)
{
    USARTRegTypeDef *usart;
    CPU_INT32U en;
    
    usart = (USARTRegTypeDef *)x;
    
    en = 0;
    en = usart->IEN;
    
    if ((usart->IF & en) & flag)
    {
        return DEF_ON;
    }
    else
    {
        return DEF_OFF;
    }
}

/* Function for USART IRCTRL */
static inline void UARTIrDAEnable (UARTTypeDef x)
{
    USARTRegTypeDef *usart;
    
    usart = (USARTRegTypeDef *)x;
    
    usart->IRCTRL |= USART_IRCTRL_IREN;
}

static inline void UARTIrDADisable (UARTTypeDef x)
{
    USARTRegTypeDef *usart;
    
    usart = (USARTRegTypeDef *)x;
    
    usart->IRCTRL &= ~USART_IRCTRL_IREN;
}

static inline CPU_BOOL UARTIrDAFlagGet (UARTTypeDef x)
{
    USARTRegTypeDef *usart;
    
    usart = (USARTRegTypeDef *)x;
    
    if (usart->IRCTRL & USART_IRCTRL_IREN_MASK)
    {
        return DEF_ON;
    }
    else
    {
        return DEF_OFF;
    }
}

static inline void UARTIrDATxPulseWidthSet (UARTTypeDef x, UARTIrDATxPulseWidthTypeDef pusle)
{
    USARTRegTypeDef *usart;
    
    usart = (USARTRegTypeDef *)x;
    
    usart->IRCTRL &= ~USART_IRCTRL_IRPW_MASK;
    usart->IRCTRL |= pusle;
}

static inline UARTIrDATxPulseWidthTypeDef UARTIrDATxPulseWidthGet (UARTTypeDef x)
{
    USARTRegTypeDef *usart;
    
    usart = (USARTRegTypeDef *)x;
    
    return  (UARTIrDATxPulseWidthTypeDef)(usart->IRCTRL & USART_IRCTRL_IRPW_MASK);
}

static inline CPU_BOOL UARTIrDATxPulseWidthFlagGet (UARTTypeDef x, UARTIrDATxPulseWidthTypeDef pusle)
{
    USARTRegTypeDef *usart;
    
    usart = (USARTRegTypeDef *)x;
    
    if (usart->IRCTRL & pusle)
    {
        return DEF_ON;
    }
    else
    {
        return DEF_ON;
    }
}

static inline void UARTIrDARxFilterEnable (UARTTypeDef x)
{
    USARTRegTypeDef *usart;
    
    usart = (USARTRegTypeDef *)x;
    
    usart->IRCTRL |= USART_IRCTRL_IRFILT;
}

static inline void UARTIrDARxFilterDisable (UARTTypeDef x)
{
    USARTRegTypeDef *usart;
    
    usart = (USARTRegTypeDef *)x;
    
    usart->IRCTRL &= ~USART_IRCTRL_IRFILT;
}

static inline CPU_BOOL UARTIrDARxFilterFlagGet (UARTTypeDef x)
{
    USARTRegTypeDef *usart;
    
    usart = (USARTRegTypeDef *)x;
    
    if (usart->IRCTRL & USART_IRCTRL_IRFILT_MASK)
    {
        return DEF_ON;
    }
    else
    {
        return DEF_OFF;
    }
}

static inline void UARTIrDAPRSChSet (UARTTypeDef x, UARTIrDAPRSChTypeDef ch)
{
    USARTRegTypeDef *usart;
    
    usart = (USARTRegTypeDef *)x;
    
    usart->IRCTRL &= ~USART_IRCTRL_IRPRSSEL_MASK;
    usart->IRCTRL |= ch;
}

static inline UARTIrDAPRSChTypeDef UARTIrDAPRSChGet (UARTTypeDef x)
{
    USARTRegTypeDef *usart;
    
    usart = (USARTRegTypeDef *)x;
    
    return (UARTIrDAPRSChTypeDef)(usart->IRCTRL & USART_IRCTRL_IRPRSSEL_MASK);
}

static inline CPU_BOOL UARTIrDAPRSChFlagGet (UARTTypeDef x, UARTIrDAPRSChTypeDef ch)
{
    USARTRegTypeDef *usart;
    
    usart = (USARTRegTypeDef *)x;
    
    if (usart->IRCTRL & ch)
    {
        return DEF_ON;
    }
    else
    {
        return DEF_OFF;
    }
}

static inline void UARTIrDAPRSEnable (UARTTypeDef x)
{
    USARTRegTypeDef *usart;
    
    usart = (USARTRegTypeDef *)x;
    
    usart->IRCTRL |= USART_IRCTRL_IRPRSEN;
}

static inline void UARTIrDAPRSDisable (UARTTypeDef x)
{
    USARTRegTypeDef *usart;
    
    usart = (USARTRegTypeDef *)x;
    
    usart->IRCTRL &= ~USART_IRCTRL_IRPRSEN;
}

static inline CPU_BOOL UARTIrDAPRSFlagGet (UARTTypeDef x)
{
    USARTRegTypeDef *usart;
    
    usart = (USARTRegTypeDef *)x;
    
    if (usart->IRCTRL & USART_IRCTRL_IRPRSEN_MASK)
    {
        return DEF_ON;
    }
    else
    {
        return DEF_OFF;
    }
}

/* Function for USART ROUTE */
static inline void UARTRxPinEnable (UARTTypeDef x)
{
    USARTRegTypeDef *usart;
    
    usart = (USARTRegTypeDef *)x;
    
    usart->ROUTE |= USART_ROUTE_RXPEN;
}

static inline void UARTRxPinDisable (UARTTypeDef x)
{
    USARTRegTypeDef *usart;
    
    usart = (USARTRegTypeDef *)x;
    
    usart->ROUTE &= ~USART_ROUTE_RXPEN;
}

static inline CPU_BOOL UARTRxPinFlagGet (UARTTypeDef x)
{
    USARTRegTypeDef *usart;
    
    usart = (USARTRegTypeDef *)x;
    
    if (usart->ROUTE & USART_ROUTE_RXPEN_MASK)
    {
        return DEF_ON;
    }
    else
    {
        return DEF_OFF;
    }
}

static inline void UARTTxPinEnable (UARTTypeDef x)
{
    USARTRegTypeDef *usart;
    
    usart = (USARTRegTypeDef *)x;
    
    usart->ROUTE |= USART_ROUTE_TXPEN;
}

static inline void UARTTxPinDisable (UARTTypeDef x)
{
    USARTRegTypeDef *usart;
    
    usart = (USARTRegTypeDef *)x;
    
    usart->ROUTE &= ~USART_ROUTE_TXPEN;
}

static inline CPU_BOOL UARTTxPinFlagGet (UARTTypeDef x)
{
    USARTRegTypeDef *usart;
    
    usart = (USARTRegTypeDef *)x;
    
    if (usart->ROUTE & USART_ROUTE_TXPEN_MASK)
    {
        return DEF_ON;
    }
    else
    {
        return DEF_OFF;
    }
}

static inline void UARTCsPinEnable (UARTTypeDef x)
{
    USARTRegTypeDef *usart;
    
    usart = (USARTRegTypeDef *)x;
    
    usart->ROUTE |= USART_ROUTE_CSPEN;
}

static inline void UARTCsPinDisable (UARTTypeDef x)
{
    USARTRegTypeDef *usart;
    
    usart = (USARTRegTypeDef *)x;
    
    usart->ROUTE &= ~USART_ROUTE_CSPEN;
}

static inline CPU_BOOL UARTCsPinFlagGet (UARTTypeDef x)
{
    USARTRegTypeDef *usart;
    
    usart = (USARTRegTypeDef *)x;
    
    if (usart->ROUTE & USART_ROUTE_CSPEN_MASK)
    {
        return DEF_ON;
    }
    else
    {
        return DEF_OFF;
    }
}

static inline void UARTClkPinEnable (UARTTypeDef x)
{
    USARTRegTypeDef *usart;
    
    usart = (USARTRegTypeDef *)x;
    
    usart->ROUTE |= USART_ROUTE_CLKPEN;
}

static inline void UARTClkPinDisable (UARTTypeDef x)
{
    USARTRegTypeDef *usart;
    
    usart = (USARTRegTypeDef *)x;
    
    usart->ROUTE &= ~USART_ROUTE_CLKPEN;
}

static inline CPU_BOOL UARTClkPinFlagGet (UARTTypeDef x)
{
    USARTRegTypeDef *usart;
    
    usart = (USARTRegTypeDef *)x;
    
    if (usart->ROUTE & USART_ROUTE_CLKPEN_MASK)
    {
        return DEF_ON;
    }
    else
    {
        return DEF_OFF;
    }
}

static inline void UARTLocationSet (UARTTypeDef x, UARTLocationTypeDef locatoin)
{
    USARTRegTypeDef *usart;
    
    usart = (USARTRegTypeDef *)x;
    
    usart->ROUTE &= ~USART_ROUTE_LOCATION_MASK;
    usart->ROUTE |= locatoin;
}

static inline UARTLocationTypeDef UARTLocationGet (UARTTypeDef x)
{
    USARTRegTypeDef *usart;
    
    usart = (USARTRegTypeDef *)x;
    
    return (UARTLocationTypeDef)(usart->ROUTE & USART_ROUTE_LOCATION_MASK);
}

static inline CPU_BOOL UARTLocationFlagGet (UARTTypeDef x, UARTLocationTypeDef locatoin)
{
    USARTRegTypeDef *usart;
    
    usart = (USARTRegTypeDef *)x;
    
    if (usart->ROUTE & locatoin)
    {
        return DEF_ON;
    }
    else
    {
        return DEF_OFF;
    }
}


/*************************************************************************************************************
*                                            FUNCTION STATEMENT                                              *
*************************************************************************************************************/
void UARTClockEnable (UARTTypeDef x);
void UARTClockDisable (UARTTypeDef x);
void UARTBaudAsyncSet (UARTTypeDef x, CPU_INT32U baud, UARTOversamplingTypeDef oversample);
CPU_INT32U UARTBaudAsyncGet (UARTTypeDef x);
void UARTBaudSyncSet (UARTTypeDef x, CPU_INT32U baud);
CPU_INT32U UARTBaudSyncGet (UARTTypeDef x);
void UARTAsyncConfig (UARTTypeDef x, UARTDataBitTypeDef bits, 
                       UARTParityModeTypeDef parity, UARTStopModeTypeDef stop);
void UARTSyncConfig (UARTTypeDef x, UARTDataBitTypeDef bits, 
                      UARTClockModeTypeDef clock, UARTMSBFTypeDef msb, UARTSyncModeTypeDef mode);
void UARTEnable (UARTTypeDef x,UARTCmdRTxTypeDef rtx);
void UARTDisable (UARTTypeDef x,UARTCmdRTxTypeDef rtx);
CPU_INT8U UARTRxByte (UARTTypeDef x);
CPU_INT16U UARTRxHalfWord (UARTTypeDef x);
void UARTTxByte (UARTTypeDef x, CPU_INT8U byte);
void UARTTxHalfWord (UARTTypeDef x, CPU_INT16U data);


/*************************************************************************************************************
*                                               MODULE END                                                   *
*************************************************************************************************************/     
#ifdef __cplusplus
}
#endif

#endif 

