/*************************************************************************************************************
*                                                  MODULE                                                    *
*************************************************************************************************************/
#ifndef LEUSART_H
#define LEUSART_H

#ifdef __cplusplus
extern "C" {
#endif
    

/*************************************************************************************************************
*                                                 DEFINES                                                    *
*************************************************************************************************************/
#define LEUART0                                 ((LEUARTRegTypeDef *)LEUART0_BASE)
#define LEUART1                                 ((LEUARTRegTypeDef *)LEUART1_BASE)     
               
/* Bit fields for LEUART CTRL */
#define LEUART_CTRL_RESETVALUE                  0x00000000UL    /* Default value for LEUART_CTRL            */
#define LEUART_CTRL_MASK                        0x0000FFFFUL    /* Mask for LEUART_CTRL                     */
#define LEUART_CTRL_AUTOTRI_SHIFT               0               /* Shift value for LEUART_CTRL_AUTOTRI      */        
#define LEUART_CTRL_AUTOTRI_MASK                (0x1UL << 0)    /* Bit mask for LEUART_CTRL_AUTOTRI         */
#define LEUART_CTRL_AUTOTRI_DEFAULT             (0x0UL << 0)    /* Mode DEFAULT for LEUART_CTRL_AUTOTRI     */
#define LEUART_CTRL_AUTOTRI                     (0x1UL << 0)    /* Automatic Transmitter Tristate           */     
#define LEUART_CTRL_DATABITS_SHIFT              1               /* Shift value for LEUART_CTRL_DATABITS     */
#define LEUART_CTRL_DATABITS_MASK               (0x1UL << 1)    /* Bit mask for LEUART_CTRL_DATABITS        */
#define LEUART_CTRL_DATABITS_DEFAULT            (0x0UL << 1)    /* Mode DEFAULT for LEUART_CTRL_DATABITS    */
#define LEUART_CTRL_DATABITS_EIGHT              (0x0UL << 1)    /* Mode EIGHT for LEUART_CTRL_DATABITS      */
#define LEUART_CTRL_DATABITS_NINE               (0x1UL << 1)    /* Mode NINE for LEUART_CTRL_DATABITS       */                                                                                                             
#define LEUART_CTRL_DATABITS                    (0x1UL << 1)    /* Data-Bit Mode                            */
#define LEUART_CTRL_PARITY_SHIFT                2               /* Shift value for LEUART_CTRL_PARITY       */
#define LEUART_CTRL_PARITY_MASK                 (0x3UL << 2)    /* Bit mask for LEUART_CTRL_PARITY          */
#define LEUART_CTRL_PARITY_DEFAULT              (0x0UL << 2)    /* Mode DEFAULT for LEUART_CTRL_PARITY      */
#define LEUART_CTRL_PARITY_NONE                 (0x0UL << 2)    /* Mode NONE for LEUART_CTRL_PARITY         */
#define LEUART_CTRL_PARITY_EVEN                 (0x2UL << 2)    /* Mode EVEN for LEUART_CTRL_PARITY         */
#define LEUART_CTRL_PARITY_ODD                  (0x3UL << 2)    /* Mode ODD for LEUART_CTRL_PARITY          */    
#define LEUART_CTRL_STOPBITS_SHIFT              4               /* Shift value for LEUART_CTRL_STOPBITS     */
#define LEUART_CTRL_STOPBITS_MASK               (0x1UL << 4)    /* Bit mask for LEUART_CTRL_STOPBITS        */
#define LEUART_CTRL_STOPBITS_DEFAULT            (0x0UL << 4)    /* Mode DEFAULT for LEUART_CTRL_STOPBITS    */
#define LEUART_CTRL_STOPBITS_ONE                (0x0UL << 4)    /* Mode ONE for LEUART_CTRL_STOPBITS        */
#define LEUART_CTRL_STOPBITS_TWO                (0x1UL << 4)    /* Mode TWO for LEUART_CTRL_STOPBITS        */
#define LEUART_CTRL_STOPBITS                    (0x1UL << 4)    /* Stop-Bit Mode                            */   
#define LEUART_CTRL_INV_SHIFT                   5               /* Shift value for LEUART_CTRL_INV          */
#define LEUART_CTRL_INV_MASK                    (0x1UL << 5)    /* Bit mask for LEUART_CTRL_INV             */
#define LEUART_CTRL_INV_DEFAULT                 (0x0UL << 5)    /* Mode DEFAULT for LEUART_CTRL_INV         */    
#define LEUART_CTRL_INV                         (0x1UL << 5)    /* Invert Input And Output                  */ 
#define LEUART_CTRL_ERRSDMA_SHIFT               6               /* Shift value for LEUART_CTRL_ERRSDMA      */
#define LEUART_CTRL_ERRSDMA_MASK                (0x1UL << 6)    /* Bit mask for LEUART_CTRL_ERRSDMA         */
#define LEUART_CTRL_ERRSDMA_DEFAULT             (0x0UL << 6)    /* Mode DEFAULT for LEUART_CTRL_ERRSDMA     */ 
#define LEUART_CTRL_ERRSDMA                     (0x1UL << 6)    /* Clear RX DMA On Error                    */
#define LEUART_CTRL_LOOPBK_SHIFT                7               /* Shift value for LEUART_CTRL_LOOPBK       */
#define LEUART_CTRL_LOOPBK_MASK                 (0x1UL << 7)    /* Bit mask for LEUART_CTRL_LOOPBK          */
#define LEUART_CTRL_LOOPBK_DEFAULT              (0x0UL << 7)    /* Mode DEFAULT for LEUART_CTRL_LOOPBK      */
#define LEUART_CTRL_LOOPBK                      (0x1UL << 7)    /* Loopback Enable                          */
#define LEUART_CTRL_SFUBRX_SHIFT                8               /* Shift value for LEUART_CTRL_SFUBRX       */
#define LEUART_CTRL_SFUBRX_MASK                 (0x1UL << 8)    /* Bit mask for LEUART_CTRL_SFUBRX          */
#define LEUART_CTRL_SFUBRX_DEFAULT              (0x0UL << 8)    /* Mode DEFAULT for LEUART_CTRL_SFUBRX      */
#define LEUART_CTRL_SFUBRX                      (0x1UL << 8)    /* Start-Frame UnBlock RX                   */    
#define LEUART_CTRL_MPM_SHIFT                   9               /* Shift value for LEUART_CTRL_MPM          */
#define LEUART_CTRL_MPM_MASK                    (0x1UL << 9)    /* Bit mask for LEUART_CTRL_MPM             */
#define LEUART_CTRL_MPM_DEFAULT                 (0x0UL << 9)    /* Mode DEFAULT for LEUART_CTRL_MPM         */ 
#define LEUART_CTRL_MPM_NMPM                    (0x0UL << 9)    /* NOT Multi-Processor Mode                 */ 
#define LEUART_CTRL_MPM                         (0x1UL << 9)    /* Multi-Processor Mode Enable              */   
#define LEUART_CTRL_MPAB_SHIFT                  10              /* Shift value for LEUART_CTRL_MPAB         */
#define LEUART_CTRL_MPAB_MASK                   (0x1UL << 10)   /* Bit mask for LEUART_CTRL_MPAB            */
#define LEUART_CTRL_MPAB_DEFAULT                (0x0UL << 10)   /* Mode DEFAULT for LEUART_CTRL_MPAB        */   
#define LEUART_CTRL_MPAB_0                      (0x0UL << 10)   /* Multi-Processor Address-Bit With 0       */   
#define LEUART_CTRL_MPAB_1                      (0x1UL << 10)   /* Multi-Processor Address-Bit With 1       */ 
#define LEUART_CTRL_BIT8DV_SHIFT                11              /* Shift value for LEUART_CTRL_BIT8DV       */
#define LEUART_CTRL_BIT8DV_MASK                 (0x1UL << 11)   /* Bit mask for LEUART_CTRL_BIT8DV          */
#define LEUART_CTRL_BIT8DV_DEFAULT              (0x0UL << 11)   /* Mode DEFAULT for LEUART_CTRL_BIT8DV      */
#define LEUART_CTRL_BIT8DV_0                    (0x0UL << 11)   /* Bit 8 Default Value With 0               */
#define LEUART_CTRL_BIT8DV_1                    (0x1UL << 11)   /* Bit 8 Default Value With 1               */
#define LEUART_CTRL_RXDMAWU_SHIFT               12              /* Shift value for LEUART_CTRL_RXDMAWU      */
#define LEUART_CTRL_RXDMAWU_MASK                (0x1UL << 12)   /* Bit mask for LEUART_CTRL_RXDMAWU         */
#define LEUART_CTRL_RXDMAWU_DEFAULT             (0x0UL << 12)   /* Mode DEFAULT for LEUART_CTRL_RXDMAWU     */    
#define LEUART_CTRL_RXDMAWU                     (0x1UL << 12)   /* RX DMA Wakeup                            */
#define LEUART_CTRL_TXDMAWU_SHIFT               13              /* Shift value for LEUART_CTRL_TXDMAWU      */
#define LEUART_CTRL_TXDMAWU_MASK                (0x1UL << 13)   /* Bit mask for LEUART_CTRL_TXDMAWU         */
#define LEUART_CTRL_TXDMAWU_DEFAULT             (0x0UL << 13)   /* Mode DEFAULT for LEUART_CTRL_TXDMAWU     */
#define LEUART_CTRL_TXDMAWU                     (0x1UL << 13)   /* TX DMA Wakeup                            */
#define LEUART_CTRL_TXDELAY_SHIFT               14              /* Shift value for LEUART_CTRL_TXDELAY      */
#define LEUART_CTRL_TXDELAY_MASK                (0x3UL << 14)   /* Bit mask for LEUART_CTRL_TXDELAY         */
#define LEUART_CTRL_TXDELAY_DEFAULT             (0x0UL << 14)   /* Mode DEFAULT for LEUART_CTRL_TXDELAY     */
#define LEUART_CTRL_TXDELAY_NONE                (0x0UL << 14)   /* Mode NONE for LEUART_CTRL_TXDELAY        */
#define LEUART_CTRL_TXDELAY_SINGLE              (0x1UL << 14)   /* Mode SINGLE for LEUART_CTRL_TXDELAY      */
#define LEUART_CTRL_TXDELAY_DOUBLE              (0x2UL << 14)   /* Mode DOUBLE for LEUART_CTRL_TXDELAY      */
#define LEUART_CTRL_TXDELAY_TRIPLE              (0x3UL << 14)   /* Mode TRIPLE for LEUART_CTRL_TXDELAY      */    
    
/* Bit fields for LEUART CMD */
#define LEUART_CMD_RESETVALUE                   0x00000000UL    /* Default value for LEUART_CMD             */
#define LEUART_CMD_MASK                         0x000000FFUL    /* Mask for LEUART_CMD                      */
#define LEUART_CMD_RXEN_SHIFT                   0               /* Shift value for LEUART_CMD_RXEN          */
#define LEUART_CMD_RXEN_MASK                    (0x1UL << 0)    /* Bit mask for LEUART_CMD_RXEN             */
#define LEUART_CMD_RXEN_DEFAULT                 (0x0UL << 0)    /* Mode DEFAULT for LEUART_CMD_RXEN         */
#define LEUART_CMD_RXEN                         (0x1UL << 0)    /* Receiver Enable                          */    
#define LEUART_CMD_RXDIS_SHIFT                  1               /* Shift value for LEUART_CMD_RXDIS         */
#define LEUART_CMD_RXDIS_MASK                   (0x1UL << 1)    /* Bit mask for LEUART_CMD_RXDIS            */
#define LEUART_CMD_RXDIS_DEFAULT                (0x0UL << 1)    /* Mode DEFAULT for LEUART_CMD_RXDIS        */    
#define LEUART_CMD_RXDIS                        (0x1UL << 1)    /* Receiver Disable                         */      
#define LEUART_CMD_TXEN_SHIFT                   2               /* Shift value for LEUART_CMD_TXEN          */
#define LEUART_CMD_TXEN_MASK                    (0x1UL << 2)    /* Bit mask for LEUART_CMD_TXEN             */
#define LEUART_CMD_TXEN_DEFAULT                 (0x0UL << 2)    /* Mode DEFAULT for LEUART_CMD_TXEN         */    
#define LEUART_CMD_TXEN                         (0x1UL << 2)    /* Transmitter Enable                       */
#define LEUART_CMD_TXDIS_SHIFT                  3               /* Shift value for LEUART_CMD_TXDIS         */
#define LEUART_CMD_TXDIS_MASK                   (0x1UL << 3)    /* Bit mask for LEUART_CMD_TXDIS            */
#define LEUART_CMD_TXDIS_DEFAULT                (0x0UL << 3)    /* Mode DEFAULT for LEUART_CMD_TXDIS        */    
#define LEUART_CMD_TXDIS                        (0x1UL << 3)    /* Transmitter Disable                      */    
#define LEUART_CMD_RXBLOCKEN_SHIFT              4               /* Shift value for LEUART_CMD_RXBLOCKEN     */
#define LEUART_CMD_RXBLOCKEN_MASK               (0x1UL << 4)    /* Bit mask for LEUART_CMD_RXBLOCKEN        */
#define LEUART_CMD_RXBLOCKEN_DEFAULT            (0x0UL << 4)    /* Mode DEFAULT for LEUART_CMD_RXBLOCKEN    */
#define LEUART_CMD_RXBLOCKEN                    (0x1UL << 4)    /* Receiver Block Enable                    */    
#define LEUART_CMD_RXBLOCKDIS_SHIFT             5               /* Shift value for LEUART_CMD_RXBLOCKDIS    */
#define LEUART_CMD_RXBLOCKDIS_MASK              (0x1UL << 5)    /* Bit mask for LEUART_CMD_RXBLOCKDIS       */
#define LEUART_CMD_RXBLOCKDIS_DEFAULT           (0x0UL << 5)    /* Mode DEFAULT for LEUART_CMD_RXBLOCKDIS   */
#define LEUART_CMD_RXBLOCKDIS                   (0x1UL << 5)    /* Receiver Block Disable                   */
#define LEUART_CMD_CLEARTX_SHIFT                6               /* Shift value for LEUART_CMD_CLEARTX       */
#define LEUART_CMD_CLEARTX_MASK                 (0x1UL << 6)    /* Bit mask for LEUART_CMD_CLEARTX          */
#define LEUART_CMD_CLEARTX_DEFAULT              (0x0UL << 6)    /* Mode DEFAULT for LEUART_CMD_CLEARTX      */
#define LEUART_CMD_CLEARTX                      (0x1UL << 6)    /* Clear TX                                 */
#define LEUART_CMD_CLEARRX_SHIFT                7               /* Shift value for LEUART_CMD_CLEARRX       */
#define LEUART_CMD_CLEARRX_MASK                 (0x1UL << 7)    /* Bit mask for LEUART_CMD_CLEARRX          */
#define LEUART_CMD_CLEARRX_DEFAULT              (0x0UL << 7)    /* Mode DEFAULT for LEUART_CMD_CLEARRX      */    
#define LEUART_CMD_CLEARRX                      (0x1UL << 7)    /* Clear RX                                 */

/* Bit fields for LEUART STATUS */
#define LEUART_STATUS_RESETVALUE                0x00000010UL    /* Default value for LEUART_STATUS          */
#define LEUART_STATUS_MASK                      0x0000003FUL    /* Mask for LEUART_STATUS                   */
#define LEUART_STATUS_RXENS_SHIFT               0               /* Shift value for LEUART_STATUS_RXENS      */
#define LEUART_STATUS_RXENS_MASK                (0x1UL << 0)    /* Bit mask for LEUART_STATUS_RXENS         */
#define LEUART_STATUS_RXENS_DEFAULT             (0x0UL << 0)    /* Mode DEFAULT for LEUART_STATUS_RXENS     */
#define LEUART_STATUS_RXENS                     (0x1UL << 0)    /* Receiver Enable Status                   */
#define LEUART_STATUS_TXENS_SHIFT               1               /* Shift value for LEUART_STATUS_TXENS      */
#define LEUART_STATUS_TXENS_MASK                (0x1UL << 1)    /* Bit mask for LEUART_STATUS_TXENS         */
#define LEUART_STATUS_TXENS_DEFAULT             (0x0UL << 1)    /* Mode DEFAULT for LEUART_STATUS_TXENS     */
#define LEUART_STATUS_TXENS                     (0x1UL << 1)    /* Transmitter Enable Status                */
#define LEUART_STATUS_RXBLOCK_SHIFT             2               /* Shift value for LEUART_STATUS_RXBLOCK    */
#define LEUART_STATUS_RXBLOCK_MASK              (0x1UL << 2)    /* Bit mask for LEUART_STATUS_RXBLOCK       */
#define LEUART_STATUS_RXBLOCK_DEFAULT           (0x0UL << 2)    /* Mode DEFAULT for LEUART_STATUS_RXBLOCK   */
#define LEUART_STATUS_RXBLOCK                   (0x1UL << 2)    /* Block Incoming Data                      */
#define LEUART_STATUS_TXC_SHIFT                 3               /* Shift value for LEUART_STATUS_TXC        */
#define LEUART_STATUS_TXC_MASK                  (0x1UL << 3)    /* Bit mask for LEUART_STATUS_TXC           */
#define LEUART_STATUS_TXC_DEFAULT               (0x0UL << 3)    /* Mode DEFAULT for LEUART_STATUS_TXC       */
#define LEUART_STATUS_TXC                       (0x1UL << 3)    /* TX Complete                              */
#define LEUART_STATUS_TXBL_SHIFT                4               /* Shift value for LEUART_STATUS_TXBL       */
#define LEUART_STATUS_TXBL_MASK                 (0x1UL << 4)    /* Bit mask for LEUART_STATUS_TXBL          */
#define LEUART_STATUS_TXBL_DEFAULT              (0x1UL << 4)    /* Mode DEFAULT for LEUART_STATUS_TXBL      */
#define LEUART_STATUS_TXBL                      (0x1UL << 4)    /* TX Buffer Level                          */
#define LEUART_STATUS_RXDATAV_SHIFT             5               /* Shift value for LEUART_STATUS_RXDATAV    */
#define LEUART_STATUS_RXDATAV_MASK              (0x1UL << 5)    /* Bit mask for LEUART_STATUS_RXDATAV       */
#define LEUART_STATUS_RXDATAV_DEFAULT           (0x0UL << 5)    /* Mode DEFAULT for LEUART_STATUS_RXDATAV   */
#define LEUART_STATUS_RXDATAV                   (0x1UL << 5)    /* RX Data Valid                            */
    
/* Bit fields for LEUART CLKDIV */
#define LEUART_CLKDIV_RESETVALUE                0x00000000UL    /* Default value for LEUART_CLKDIV          */
#define LEUART_CLKDIV_MASK                      0x00007FF8UL    /* Mask for LEUART_CLKDIV                   */
#define LEUART_CLKDIV_DIV_SHIFT                 3               /* Shift value for LEUART_DIV               */
#define LEUART_CLKDIV_DIV_MASK                  (0x7FF1UL << 3) /* Bit mask for LEUART_DIV                  */
#define LEUART_CLKDIV_DIV_DEFAULT               (0x0UL    << 3) /* Mode DEFAULT for LEUART_CLKDIV           */

/* Bit fields for LEUART STARTFRAME */
#define LEUART_STARTFRAME_RESETVALUE            0x00000000UL    /* Default value for LEUART_STARTFRAME      */
#define LEUART_STARTFRAME_MASK                  0x000001FFUL    /* Mask for LEUART_STARTFRAME               */
#define LEUART_STARTFRAME_STARTFRAME_SHIFT      0               /* Shift value for LEUART_STARTFRAME        */
#define LEUART_STARTFRAME_STARTFRAME_MASK       (0x1FFUL << 0)  /* Bit mask for LEUART_STARTFRAME           */
#define LEUART_STARTFRAME_STARTFRAME_DEFAULT    (0x0UL   << 0)  /* Mode DEFAULT for LEUART_STARTFRAME       */
    
/* Bit fields for LEUART SIGFRAME */ 
#define LEUART_SIGFRAME_RESETVALUE              0x00000000UL    /* Default value for LEUART_SIGFRAME        */
#define LEUART_SIGFRAME_MASK                    0x000001FFUL    /* Mask for LEUART_SIGFRAME                 */
#define LEUART_SIGFRAME_SIGFRAME_SHIFT          0               /* Shift value for LEUART_SIGFRAME_SIGFRAME */
#define LEUART_SIGFRAME_SIGFRAME_MASK           (0x1FFUL << 0)  /* Bit mask for LEUART_SIGFRAME_SIGFRAME    */
#define LEUART_SIGFRAME_SIGFRAME_DEFAULT        (0x0UL   << 0)  /* Mode DEFAULT for LEUART_SIGFRAME_SIGFRAME*/

/* Bit fields for LEUART RXDATAX */   
#define LEUART_RXDATAX_RESETVALUE               0x00000000UL    /* Default value for LEUART_RXDATAX         */
#define LEUART_RXDATAX_MASK                     0x0000C1FFUL    /* Mask for LEUART_RXDATAX                  */
#define LEUART_RXDATAX_RXDATA_SHIFT             0               /* Shift value for LEUART_RXDATAX_RXDATA    */
#define LEUART_RXDATAX_RXDATA_MASK              (0x1FFUL << 0)  /* Bit mask for LEUART_RXDATAX_RXDATA       */
#define LEUART_RXDATAX_RXDATA_DEFAULT           (0x0UL   << 0)  /* Mode DEFAULT for LEUART_RXDATAX_RXDATA   */
#define LEUART_RXDATAX_PERR_SHIFT               14              /* Shift value for LEUART_RXDATAX_PERR      */
#define LEUART_RXDATAX_PERR_MASK                (0x1UL << 14)   /* Bit mask for LEUART_RXDATAX_PERR         */
#define LEUART_RXDATAX_PERR_DEFAULT             (0x0UL << 14)   /* Mode DEFAULT for LEUART_RXDATAX_PERR     */
#define LEUART_RXDATAX_PERR                     (0x1UL << 14)   /* Receive Data Parity Error                */    
#define LEUART_RXDATAX_FERR_SHIFT               15              /* Shift value for LEUART_RXDATAX_FERR      */
#define LEUART_RXDATAX_FERR_MASK                (0x1UL << 15)   /* Bit mask for LEUART_RXDATAX_FERR         */
#define LEUART_RXDATAX_FERR_DEFAULT             (0x0UL << 15)   /* Mode DEFAULT for LEUART_RXDATAX_FERR     */
#define LEUART_RXDATAX_FERR                     (0x1UL << 15)   /* Receive Data Framing Error               */
    
/* Bit fields for LEUART RXDATA */
#define LEUART_RXDATA_RESETVALUE                0x00000000UL    /* Default value for LEUART_RXDATA          */
#define LEUART_RXDATA_MASK                      0x000000FFUL    /* Mask for LEUART_RXDATA                   */
#define LEUART_RXDATA_RXDATA_SHIFT              0               /* Shift value for LEUART_RXDATA_RXDATA     */
#define LEUART_RXDATA_RXDATA_MASK               (0xFFUL << 0)   /* Bit mask for LEUART_RXDATA_RXDATA        */
#define LEUART_RXDATA_RXDATA_DEFAULT            (0x0UL  << 0)   /* Mode DEFAULT for LEUART_RXDATA_RXDATA    */
    
/* Bit fields for LEUART RXDATAXP */
#define LEUART_RXDATAXP_RESETVALUE              0x00000000UL    /* Default value for LEUART_RXDATAXP        */
#define LEUART_RXDATAXP_MASK                    0x0000C1FFUL    /* Mask for LEUART_RXDATAXP                 */
#define LEUART_RXDATAXP_RXDATAP_SHIFT           0               /* Shift value for LEUART_RXDATAXP_RXDATAP  */
#define LEUART_RXDATAXP_RXDATAP_MASK            (0x1FFUL << 0)  /* Bit mask for LEUART_RXDATAXP_RXDATAP     */
#define LEUART_RXDATAXP_RXDATAP_DEFAULT         (0x0UL   << 0)  /* Mode DEFAULT for LEUART_RXDATAXP_RXDATAP */
#define LEUART_RXDATAXP_PERRP_SHIFT             14              /* Shift value for LEUART_RXDATAXP_PERRP    */
#define LEUART_RXDATAXP_PERRP_MASK              (0x1UL << 14)   /* Bit mask for LEUART_RXDATAXP_PERRP       */
#define LEUART_RXDATAXP_PERRP_DEFAULT           (0x0UL << 14)   /* Mode DEFAULT for LEUART_RXDATAXP_PERRP   */
#define LEUART_RXDATAXP_PERRP                   (0x1UL << 14)   /* Receive Data Parity Error Peek           */
#define LEUART_RXDATAXP_FERRP_SHIFT             15              /* Shift value for LEUART_RXDATAXP_FERRP    */
#define LEUART_RXDATAXP_FERRP_MASK              (0x1UL << 15)   /* Bit mask for LEUART_RXDATAXP_FERRP       */
#define LEUART_RXDATAXP_FERRP_DEFAULT           (0x0UL << 15)   /* Mode DEFAULT for LEUART_RXDATAXP_FERRP   */
#define LEUART_RXDATAXP_FERRP                   (0x1UL << 15)   /* Receive Data Framing Error Peek          */

/* Bit fields for LEUART TXDATAX */
#define LEUART_TXDATAX_RESETVALUE               0x00000000UL    /* Default value for LEUART_TXDATAX         */
#define LEUART_TXDATAX_MASK                     0x0000E1FFUL    /* Mask for LEUART_TXDATAX                  */
#define LEUART_TXDATAX_TXDATA_SHIFT             0               /* Shift value for LEUART_TXDATAX_TXDATA    */
#define LEUART_TXDATAX_TXDATA_MASK              (0x1FFUL << 0)  /* Bit mask for LEUART_TXDATAX_TXDATA       */
#define LEUART_TXDATAX_TXDATA_DEFAULT           (0x0UL   << 0)  /* Mode DEFAULT for LEUART_TXDATAX_TXDATA   */
#define LEUART_TXDATAX_TXBREAK_SHIFT            13              /* Shift value for LEUART_TXDATAX_TXBREAK   */
#define LEUART_TXDATAX_TXBREAK_MASK             (0x1UL << 13)   /* Bit mask for LEUART_TXDATAX_TXBREAK      */
#define LEUART_TXDATAX_TXBREAK_DEFAULT          (0x0UL << 13)   /* Mode DEFAULT for LEUART_TXDATAX_TXBREAK  */
#define LEUART_TXDATAX_TXBREAK                  (0x1UL << 13)   /* Transmit Data As Break                   */
#define LEUART_TXDATAX_TXDISAT_SHIFT            14              /* Shift value for LEUART_TXDATAX_TXDISAT   */
#define LEUART_TXDATAX_TXDISAT_MASK             (0x1UL << 14)   /* Bit mask for LEUART_TXDATAX_TXDISAT      */
#define LEUART_TXDATAX_TXDISAT_DEFAULT          (0x0UL << 14)   /* Mode DEFAULT for LEUART_TXDATAX_TXDISAT  */
#define LEUART_TXDATAX_TXDISAT                  (0x1UL << 14)   /* Disable TX After LEUART_TXDATAX_TXDISAT  */
#define LEUART_TXDATAX_RXENAT_SHIFT             15              /* Shift value for LEUART_TXDATAX_RXENAT    */
#define LEUART_TXDATAX_RXENAT_MASK              (0x1UL << 15)   /* Bit mask for LEUART_TXDATAX_RXENAT       */
#define LEUART_TXDATAX_RXENAT_DEFAULT           (0x0UL << 15)   /* Mode DEFAULT for LEUART_TXDATAX_RXENAT   */
#define LEUART_TXDATAX_RXENAT                   (0x1UL << 15)   /* Enable RX After Transmission             */

/* Bit fields for LEUART TXDATA */
#define LEUART_TXDATA_RESETVALUE                0x00000000UL    /* Default value for LEUART_TXDATA          */
#define LEUART_TXDATA_MASK                      0x000000FFUL    /* Mask for LEUART_TXDATA                   */
#define LEUART_TXDATA_TXDATA_SHIFT              0               /* Shift value for LEUART_TXDATA_TXDATA     */
#define LEUART_TXDATA_TXDATA_MASK               (0xFFUL << 0)   /* Bit mask for LEUART_TXDATA_TXDATA        */
#define LEUART_TXDATA_TXDATA_DEFAULT            (0x0UL  << 0)   /* Mode DEFAULT for LEUART_TXDATA_TXDATA    */
    
/* Bit fields for LEUART IF */
#define LEUART_IF_RESETVALUE                    0x00000002UL    /* Default value for LEUART_IF              */
#define LEUART_IF_MASK                          0x000007FFUL    /* Mask for LEUART_IF                       */
#define LEUART_IF_TXC_SHIFT                     0               /* Shift value for LEUART_IF_TXC            */
#define LEUART_IF_TXC_MASK                      (0x1UL << 0)    /* Bit mask for LEUART_IF_TXC               */
#define LEUART_IF_TXC_DEFAULT                   (0x0UL << 0)    /* Mode DEFAULT for LEUART_IF_TXC           */
#define LEUART_IF_TXC                           (0x1UL << 0)    /* TX Complete Interrupt Flag               */
#define LEUART_IF_TXBL_SHIFT                    1               /* Shift value for LEUART_IF_TXBL           */
#define LEUART_IF_TXBL_MASK                     (0x1UL << 1)    /* Bit mask for LEUART_IF_TXBL              */
#define LEUART_IF_TXBL_DEFAULT                  (0x1UL << 1)    /* Mode DEFAULT for LEUART_IF_TXBL          */
#define LEUART_IF_TXBL                          (0x1UL << 1)    /* TX Buffer Level Interrupt Flag           */
#define LEUART_IF_RXDATAV_SHIFT                 2               /* Shift value for LEUART_IF_RXDATAV        */
#define LEUART_IF_RXDATAV_MASK                  (0x1UL << 2)    /* Bit mask for LEUART_IF_RXDATAV           */
#define LEUART_IF_RXDATAV_DEFAULT               (0x0UL << 2)    /* Mode DEFAULT for LEUART_IF_RXDATAV       */
#define LEUART_IF_RXDATAV                       (0x1UL << 2)    /* RX Data Valid Interrupt Flag             */
#define LEUART_IF_RXOF_SHIFT                    3               /* Shift value for LEUART_IF_RXOF           */
#define LEUART_IF_RXOF_MASK                     (0x1UL << 3)    /* Bit mask for LEUART_IF_RXOF              */
#define LEUART_IF_RXOF_DEFAULT                  (0x0UL << 3)    /* Mode DEFAULT for LEUART_IF_RXOF          */
#define LEUART_IF_RXOF                          (0x1UL << 3)    /* RX Overflow Interrupt Flag               */
#define LEUART_IF_RXUF_SHIFT                    4               /* Shift value for LEUART_IF_RXUF           */
#define LEUART_IF_RXUF_MASK                     (0x1UL << 4)    /* Bit mask for LEUART_IF_RXUF              */
#define LEUART_IF_RXUF_DEFAULT                  (0x0UL << 4)    /* Mode DEFAULT for LEUART_IF_RXUF          */
#define LEUART_IF_RXUF                          (0x1UL << 4)    /* RX Underflow Interrupt Flag              */    
#define LEUART_IF_TXOF_SHIFT                    5               /* Shift value for LEUART_IF_TXOF           */
#define LEUART_IF_TXOF_MASK                     (0x1UL << 5)    /* Bit mask for LEUART_IF_TXOF              */
#define LEUART_IF_TXOF_DEFAULT                  (0x0UL << 5)    /* Mode DEFAULT for LEUART_IF_TXOF          */
#define LEUART_IF_TXOF                          (0x1UL << 5)    /* TX Overflow Interrupt Flag               */
#define LEUART_IF_PERR_SHIFT                    6               /* Shift value for LEUART_IF_PERR           */
#define LEUART_IF_PERR_MASK                     (0x1UL << 6)    /* Bit mask for LEUART_IF_PERR              */
#define LEUART_IF_PERR_DEFAULT                  (0x0UL << 6)    /* Mode DEFAULT for LEUART_IF_PERR          */
#define LEUART_IF_PERR                          (0x1UL << 6)    /* Parity Error Interrupt Flag              */
#define LEUART_IF_FERR_SHIFT                    7               /* Shift value for LEUART_IF_FERR           */
#define LEUART_IF_FERR_MASK                     (0x1UL << 7)    /* Bit mask for LEUART_IF_FERR              */
#define LEUART_IF_FERR_DEFAULT                  (0x0UL << 7)    /* Mode DEFAULT for LEUART_IF_FERR          */
#define LEUART_IF_FERR                          (0x1UL << 7)    /* Framing Error Interrupt Flag             */
#define LEUART_IF_MPAF_SHIFT                    8               /* Shift value for LEUART_IF_MPAF           */
#define LEUART_IF_MPAF_MASK                     (0x1UL << 8)    /* Bit mask for LEUART_IF_MPAF              */
#define LEUART_IF_MPAF_DEFAULT                  (0x0UL << 8)    /* Mode DEFAULT for LEUART_IF_MPAF          */
#define LEUART_IF_MPAF                          (0x1UL << 8)    /* Multi-Processor Address Interrupt Flag   */
#define LEUART_IF_STARTF_SHIFT                  9               /* Shift value for LEUART_IF_STARTF         */
#define LEUART_IF_STARTF_MASK                   (0x1UL << 9)    /* Bit mask for LEUART_IF_STARTF            */
#define LEUART_IF_STARTF_DEFAULT                (0x0UL << 9)    /* Mode DEFAULT for LEUART_IF_STARTF        */
#define LEUART_IF_STARTF                        (0x1UL << 9)    /* Start Frame Interrupt Flag               */
#define LEUART_IF_SIGF_SHIFT                    10              /* Shift value for LEUART_IF_SIGF           */
#define LEUART_IF_SIGF_MASK                     (0x1UL << 10)   /* Bit mask for LEUART_IF_SIGF              */
#define LEUART_IF_SIGF_DEFAULT                  (0x0UL << 10)   /* Mode DEFAULT for LEUART_IF_SIGF          */
#define LEUART_IF_SIGF                          (0x1UL << 10)   /* Signal Frame Interrupt Flag              */
    
/* Bit fields for LEUART IFS */
#define LEUART_IFS_RESETVALUE                   0x00000000UL    /* Default value for LEUART_IFS             */
#define LEUART_IFS_MASK                         0x000007F9UL    /* Mask for LEUART_IFS                      */
#define LEUART_IFS_TXC_SHIFT                    0               /* Shift value for LEUART_IFS_TXC           */
#define LEUART_IFS_TXC_MASK                     (0x1UL << 0)    /* Bit mask for LEUART_IFS_TXC              */
#define LEUART_IFS_TXC_DEFAULT                  (0x0UL << 0)    /* Mode DEFAULT for LEUART_IFS_TXC          */
#define LEUART_IFS_TXC                          (0x1UL << 0)    /* Set TX Complete Interrupt Flag           */
#define LEUART_IFS_RXOF_SHIFT                   3               /* Shift value for LEUART_IFS_RXOF          */
#define LEUART_IFS_RXOF_MASK                    (0x1UL << 3)    /* Bit mask for LEUART_IFS_RXOF             */
#define LEUART_IFS_RXOF_DEFAULT                 (0x0UL << 3)    /* Mode DEFAULT for LEUART_IFS_RXOF         */
#define LEUART_IFS_RXOF                         (0x1UL << 3)    /* Set RX Overflow Interrupt Flag           */
#define LEUART_IFS_RXUF_SHIFT                   4               /* Shift value for LEUART_IFS_RXUF          */
#define LEUART_IFS_RXUF_MASK                    (0x1UL << 4)    /* Bit mask for LEUART_IFS_RXUF             */
#define LEUART_IFS_RXUF_DEFAULT                 (0x0UL << 4)    /* Mode DEFAULT for LEUART_IFS_RXUF         */
#define LEUART_IFS_RXUF                         (0x1UL << 4)    /* Set RX Underflow Interrupt Flag          */
#define LEUART_IFS_TXOF_SHIFT                   5               /* Shift value for LEUART_IFS_TXOF          */
#define LEUART_IFS_TXOF_MASK                    (0x1UL << 5)    /* Bit mask for LEUART_IFS_TXOF             */
#define LEUART_IFS_TXOF_DEFAULT                 (0x0UL << 5)    /* Mode DEFAULT for LEUART_IFS_TXOF         */
#define LEUART_IFS_TXOF                         (0x1UL << 5)    /* Set TX Overflow Interrupt Flag           */
#define LEUART_IFS_PERR_SHIFT                   6               /* Shift value for LEUART_IFS_PERR          */
#define LEUART_IFS_PERR_MASK                    (0x1UL << 6)    /* Bit mask for LEUART_IFS_PERR             */
#define LEUART_IFS_PERR_DEFAULT                 (0x0UL << 6)    /* Mode DEFAULT for LEUART_IFS_PERR         */
#define LEUART_IFS_PERR                         (0x1UL << 6)    /* Set Parity Error Interrupt Flag          */
#define LEUART_IFS_FERR_SHIFT                   7               /* Shift value for LEUART_IFS_FERR          */
#define LEUART_IFS_FERR_MASK                    (0x1UL << 7)    /* Bit mask for LEUART_IFS_FERR             */
#define LEUART_IFS_FERR_DEFAULT                 (0x0UL << 7)    /* Mode DEFAULT for LEUART_IFS_FERR         */
#define LEUART_IFS_FERR                         (0x1UL << 7)    /* Set Framing Error Interrupt Flag         */
#define LEUART_IFS_MPAF_SHIFT                   8               /* Shift value for LEUART_IFS_MPAF          */
#define LEUART_IFS_MPAF_MASK                    (0x1UL << 8)    /* Bit mask for LEUART_IFS_MPAF             */
#define LEUART_IFS_MPAF_DEFAULT                 (0x0UL << 8)    /* Mode DEFAULT for LEUART_IFS              */
#define LEUART_IFS_MPAF                         (0x1UL << 8)    /* Multi-Processor Address Interrupt Flag   */
#define LEUART_IFS_STARTF_SHIFT                 9               /* Shift value for LEUART_IFS_STARTF        */
#define LEUART_IFS_STARTF_MASK                  (0x1UL << 9)    /* Bit mask for LEUART_IFS_STARTF           */
#define LEUART_IFS_STARTF_DEFAULT               (0x0UL << 9)    /* Mode DEFAULT for LEUART_IFS_STARTF       */
#define LEUART_IFS_STARTF                       (0x1UL << 9)    /* Set Start Frame Interrupt Flag           */
#define LEUART_IFS_SIGF_SHIFT                   10              /* Shift value for LEUART_IFS_SIGF          */
#define LEUART_IFS_SIGF_MASK                    (0x1UL << 10)   /* Bit mask for LEUART_IFS_SIGF             */
#define LEUART_IFS_SIGF_DEFAULT                 (0x0UL << 10)   /* Mode DEFAULT for LEUART_IFS_SIGF         */
#define LEUART_IFS_SIGF                         (0x1UL << 10)   /* Set Signal Frame Interrupt Flag          */
    
/* Bit fields for LEUART IFC */
#define LEUART_IFC_RESETVALUE                   0x00000000UL    /* Default value for LEUART_IFC             */
#define LEUART_IFC_MASK                         0x000007F9UL    /* Mask for LEUART_IFC                      */
#define LEUART_IFC_TXC_SHIFT                    0               /* Shift value for LEUART_IFC_TXC           */
#define LEUART_IFC_TXC_MASK                     (0x1UL << 0)    /* Bit mask for LEUART_IFC_TXC              */
#define LEUART_IFC_TXC_DEFAULT                  (0x0UL << 0)    /* Mode DEFAULT for LEUART_IFC_TXC          */
#define LEUART_IFC_TXC                          (0x1UL << 0)    /* Clear TX Complete Interrupt Flag         */
#define LEUART_IFC_RXOF_SHIFT                   3               /* Shift value for LEUART_IFC_RXOF          */
#define LEUART_IFC_RXOF_MASK                    (0x1UL << 3)    /* Bit mask for LEUART_IFC_RXOF             */
#define LEUART_IFC_RXOF_DEFAULT                 (0x0UL << 3)    /* Mode DEFAULT for LEUART_IFC_RXOF         */
#define LEUART_IFC_RXOF                         (0x1UL << 3)    /* Clear RX Overflow Interrupt Flag         */
#define LEUART_IFC_RXUF_SHIFT                   4               /* Shift value for LEUART_IFC_RXUF          */
#define LEUART_IFC_RXUF_MASK                    (0x1UL << 4)    /* Bit mask for LEUART_IFC_RXUF             */
#define LEUART_IFC_RXUF_DEFAULT                 (0x0UL << 4)    /* Mode DEFAULT for LEUART_IFC_RXUF         */
#define LEUART_IFC_RXUF                         (0x1UL << 4)    /* Clear RX Underflow Interrupt Flag        */
#define LEUART_IFC_TXOF_SHIFT                   5               /* Shift value for LEUART_IFC_TXOF          */
#define LEUART_IFC_TXOF_MASK                    (0x1UL << 5)    /* Bit mask for LEUART_IFC_TXOF             */
#define LEUART_IFC_TXOF_DEFAULT                 (0x0UL << 5)    /* Mode DEFAULT for LEUART_IFC_TXOF         */
#define LEUART_IFC_TXOF                         (0x1UL << 5)    /* Clear TX Overflow Interrupt Flag         */
#define LEUART_IFC_PERR_SHIFT                   6               /* Shift value for LEUART_IFC_PERR          */
#define LEUART_IFC_PERR_MASK                    (0x1UL << 6)    /* Bit mask for LEUART_IFC_PERR             */
#define LEUART_IFC_PERR_DEFAULT                 (0x0UL << 6)    /* Mode DEFAULT for LEUART_IFC_PERR         */
#define LEUART_IFC_PERR                         (0x1UL << 6)    /* Clear Parity Error Interrupt Flag        */
#define LEUART_IFC_FERR_SHIFT                   7               /* Shift value for LEUART_IFC_FERR          */
#define LEUART_IFC_FERR_MASK                    (0x1UL << 7)    /* Bit mask for LEUART_IFC_FERR             */
#define LEUART_IFC_FERR_DEFAULT                 (0x0UL << 7)    /* Mode DEFAULT for LEUART_IFC_FERR         */
#define LEUART_IFC_FERR                         (0x1UL << 7)    /* Clear Framing Error Interrupt Flag       */
#define LEUART_IFC_MPAF_SHIFT                   8               /* Shift value for LEUART_IFC_MPAF          */
#define LEUART_IFC_MPAF_MASK                    (0x1UL << 8)    /* Bit mask for LEUART_IFC_MPAF             */
#define LEUART_IFC_MPAF_DEFAULT                 (0x0UL << 8)    /* Mode DEFAULT for LEUART_IFC_MPAF         */
#define LEUART_IFC_MPAF                         (0x1UL << 8)    /* Clear Multi-Processor Address Int Flag   */
#define LEUART_IFC_STARTF_SHIFT                 9               /* Shift value for LEUART_IFC_STARTF        */
#define LEUART_IFC_STARTF_MASK                  (0x1UL << 9)    /* Bit mask for LEUART_IFC_STARTF           */
#define LEUART_IFC_STARTF_DEFAULT               (0x0UL << 9)    /* Mode DEFAULT for LEUART_IFC_STARTF       */
#define LEUART_IFC_STARTF                       (0x1UL << 9)    /* Clear Start-Frame Interrupt Flag         */
#define LEUART_IFC_SIGF_SHIFT                   10              /* Shift value for LEUART_IFC_SIGF          */
#define LEUART_IFC_SIGF_MASK                    (0x1UL << 10)   /* Bit mask for LEUART_IFC_SIGF             */
#define LEUART_IFC_SIGF_DEFAULT                 (0x0UL << 10)   /* Mode DEFAULT for LEUART_IFC_SIGF         */
#define LEUART_IFC_SIGF                         (0x1UL << 10)   /* Clear Signal-Frame Interrupt Flag        */
 
/* Bit fields for LEUART IEN */
#define LEUART_IEN_RESETVALUE                   0x00000000UL    /* Default value for LEUART_IEN             */
#define LEUART_IEN_MASK                         0x000007FFUL    /* Mask for LEUART_IEN                      */
#define LEUART_IEN_TXC_SHIFT                    0               /* Shift value for LEUART_IEN_TXC           */
#define LEUART_IEN_TXC_MASK                     (0x1UL << 0)    /* Bit mask for LEUART_IEN_TXC              */
#define LEUART_IEN_TXC_DEFAULT                  (0x0UL << 0)    /* Mode DEFAULT for LEUART_IEN_TXC          */
#define LEUART_IEN_TXC                          (0x1UL << 0)    /* TX Complete Interrupt Enable             */
#define LEUART_IEN_TXBL_SHIFT                   1               /* Shift value for LEUART_IEN_TXBL          */
#define LEUART_IEN_TXBL_MASK                    (0x1UL << 1)    /* Bit mask for LEUART_IEN_TXBL             */
#define LEUART_IEN_TXBL_DEFAULT                 (0x0UL << 1)    /* Mode DEFAULT for LEUART_IEN_TXBL         */
#define LEUART_IEN_TXBL                         (0x1UL << 1)    /* TX Buffer Level Interrupt Enable         */
#define LEUART_IEN_RXDATAV_SHIFT                2               /* Shift value for LEUART_IEN_RXDATAV       */
#define LEUART_IEN_RXDATAV_MASK                 (0x1UL << 2)    /* Bit mask for LEUART_IEN_RXDATAV          */
#define LEUART_IEN_RXDATAV_DEFAULT              (0x0UL << 2)    /* Mode DEFAULT for LEUART_IEN_RXDATAV      */
#define LEUART_IEN_RXDATAV                      (0x1UL << 2)    /* RX Data Valid Interrupt Enable           */
#define LEUART_IEN_RXOF_SHIFT                   3               /* Shift value for LEUART_IEN_RXOF          */
#define LEUART_IEN_RXOF_MASK                    (0x1UL << 3)    /* Bit mask for LEUART_IEN_RXOF             */
#define LEUART_IEN_RXOF_DEFAULT                 (0x0UL << 3)    /* Mode DEFAULT for LEUART_IEN_RXOF         */
#define LEUART_IEN_RXOF                         (0x1UL << 3)    /* RX Overflow Interrupt Enable             */
#define LEUART_IEN_RXUF_SHIFT                   4               /* Shift value for LEUART_IEN_RXUF          */
#define LEUART_IEN_RXUF_MASK                    (0x1UL << 4)    /* Bit mask for LEUART_IEN_RXUF             */
#define LEUART_IEN_RXUF_DEFAULT                 (0x0UL << 4)    /* Mode DEFAULT for LEUART_IEN_RXUF         */
#define LEUART_IEN_RXUF                         (0x1UL << 4)    /* RX Underflow Interrupt Enable            */
#define LEUART_IEN_TXOF_SHIFT                   5               /* Shift value for LEUART_IEN_TXOF          */
#define LEUART_IEN_TXOF_MASK                    (0x1UL << 5)    /* Bit mask for LEUART_IEN_TXOF             */
#define LEUART_IEN_TXOF_DEFAULT                 (0x0UL << 5)    /* Mode DEFAULT for LEUART_IEN_TXOF         */
#define LEUART_IEN_TXOF                         (0x1UL << 5)    /* TX Overflow Interrupt Enable             */
#define LEUART_IEN_PERR_SHIFT                   6               /* Shift value for LEUART_IEN_PERR          */
#define LEUART_IEN_PERR_MASK                    (0x1UL << 6)    /* Bit mask for LEUART_IEN_PERR             */
#define LEUART_IEN_PERR_DEFAULT                 (0x0UL << 6)    /* Mode DEFAULT for LEUART_IEN_PERR         */
#define LEUART_IEN_PERR                         (0x1UL << 6)    /* Parity Error Interrupt Enable            */
#define LEUART_IEN_FERR_SHIFT                   7               /* Shift value for LEUART_IEN_FERR          */
#define LEUART_IEN_FERR_MASK                    (0x1UL << 7)    /* Bit mask for LEUART_IEN_FERR             */
#define LEUART_IEN_FERR_DEFAULT                 (0x0UL << 7)    /* Mode DEFAULT for LEUART_IEN_FERR         */
#define LEUART_IEN_FERR                         (0x1UL << 7)    /* Framing Error Interrupt Enable           */
#define LEUART_IEN_MPAF_SHIFT                   8               /* Shift value for LEUART_IEN_MPAF          */
#define LEUART_IEN_MPAF_MASK                    (0x1UL << 8)    /* Bit mask for LEUART_IEN_MPAF             */
#define LEUART_IEN_MPAF_DEFAULT                 (0x0UL << 8)    /* Mode DEFAULT for LEUART_IEN_MPAF         */
#define LEUART_IEN_MPAF                         (0x1UL << 8)    /* Multi-Processor Address Int Enable       */
#define LEUART_IEN_STARTF_SHIFT                 9               /**< Shift value for LEUART_IEN_STARTF      */
#define LEUART_IEN_STARTF_MASK                  (0x1UL << 9)    /**< Bit mask for LEUART_IEN_STARTF         */
#define LEUART_IEN_STARTF_DEFAULT               (0x0UL << 9)    /**< Mode DEFAULT for LEUART_IEN_STARTF     */
#define LEUART_IEN_STARTF                       (0x1UL << 9)    /**< Start Frame Interrupt Enable           */
#define LEUART_IEN_SIGF_SHIFT                   10              /* Shift value for LEUART_IEN_SIGF          */
#define LEUART_IEN_SIGF_MASK                    (0x1UL << 10)   /* Bit mask for LEUART_IEN_SIGF             */
#define LEUART_IEN_SIGF_DEFAULT                 (0x0UL << 10)   /* Mode DEFAULT for LEUART_IEN_SIGF         */
#define LEUART_IEN_SIGF                         (0x1UL << 10)   /* Signal Frame Interrupt Enable            */

/* Bit fields for LEUART PULSECTRL */
#define LEUART_PULSECTRL_RESETVALUE             0x00000000UL    /* Default value for LEUART_PULSECTRL       */
#define LEUART_PULSECTRL_MASK                   0x0000003FUL    /* Mask for LEUART_PULSECTRL                */
#define LEUART_PULSECTRL_PULSEW_SHIFT           0               /* Shift value for LEUART_PULSECTRL_PULSEW  */
#define LEUART_PULSECTRL_PULSEW_MASK            (0xFUL << 0)    /* Bit mask for LEUART_PULSECTRL_PULSEW     */
#define LEUART_PULSECTRL_PULSEW_DEFAULT         (0x0UL << 0)    /* Mode DEFAULT for LEUART_PULSECTRL_PULSEW */
#define LEUART_PULSECTRL_PULSEEN_SHIFT          4               /* Shift value for LEUART_PULSECTRL_PULSEEN */
#define LEUART_PULSECTRL_PULSEEN_MASK           (0x1UL << 4)    /* Bit mask for LEUART_PULSECTRL_PULSEEN    */
#define LEUART_PULSECTRL_PULSEEN_DEFAULT        (0x0UL << 4)    /* Mode DEF for LEUART_PULSECTRL_PULSEEN    */
#define LEUART_PULSECTRL_PULSEEN                (0x1UL << 4)    /* Pulse Generator/Extender Enable          */
#define LEUART_PULSECTRL_PULSEFILT_SHIFT        5               /* Shift value for LEUART_PULSECTRL_PULSEF  */
#define LEUART_PULSECTRL_PULSEFILT_MASK         (0x1UL << 5)    /* Bit mask for LEUART_PULSECTRL_PULSEFILT  */
#define LEUART_PULSECTRL_PULSEFILT_DEFAULT      (0x0UL << 5)    /* Mode DEF for LEUART_PULSECTRL_PULSEFILT  */
#define LEUART_PULSECTRL_PULSEFILT              (0x1UL << 5)    /* Pulse Filter                             */

/* Bit fields for LEUART FREEZE */
#define LEUART_FREEZE_RESETVALUE                0x00000000UL    /* Default value for LEUART_FREEZE          */
#define LEUART_FREEZE_MASK                      0x00000001UL    /* Mask for LEUART_FREEZE                   */
#define LEUART_FREEZE_REGFREEZE_SHIFT           0               /* Shift value for LEUART_FREEZE_REGFREEZE  */
#define LEUART_FREEZE_REGFREEZE_MASK            (0x1UL << 0)    /* Bit mask for LEUART_FREEZE_REGFREEZE     */
#define LEUART_FREEZE_REGFREEZE_DEFAULT         (0x0UL << 0)    /* Mode DEFAULT for LEUART_FREEZE_REGFREEZE */
#define LEUART_FREEZE_REGFREEZE_UPDATE          (0x0UL << 0)    /* Mode UPDATE for LEUART_FREEZE_REGFREEZE  */
#define LEUART_FREEZE_REGFREEZE_FREEZE          (0x1UL << 1)    /* Mode FREEZE for LEUART_FREEZE_REGFREEZE  */
#define LEUART_FREEZE_REGFREEZE                 (0x1UL << 0)    /* Register Update Freeze                   */

/* Bit fields for LEUART SYNCBUSY */
#define LEUART_SYNCBUSY_RESETVALUE              0x00000000UL    /* Default value for LEUART_SYNCBUSY        */
#define LEUART_SYNCBUSY_MASK                    0x000000FFUL    /* Mask for LEUART_SYNCBUSY                 */
#define LEUART_SYNCBUSY_CTRL_SHIFT              0               /* Shift value for LEUART_SYNCBUSY_CTRL     */
#define LEUART_SYNCBUSY_CTRL_MASK               (0x1UL << 0)    /* Bit mask for LEUART_SYNCBUSY_CTRL        */
#define LEUART_SYNCBUSY_CTRL_DEFAULT            (0x0UL << 0)    /* Mode DEFAULT for LEUART_SYNCBUSY_CTRL    */
#define LEUART_SYNCBUSY_CTRL                    (0x1UL << 0)    /* LEUARTn_CTRL Register Busy               */
#define LEUART_SYNCBUSY_CMD_SHIFT               1               /* Shift value for LEUART_SYNCBUSY_CMD      */
#define LEUART_SYNCBUSY_CMD_MASK                (0x1UL << 1)    /* Bit mask for LEUART_SYNCBUSY_CMD         */
#define LEUART_SYNCBUSY_CMD_DEFAULT             (0x0UL << 1)    /* Mode DEFAULT for LEUART_SYNCBUSY_CMD     */
#define LEUART_SYNCBUSY_CMD                     (0x1UL << 1)    /* LEUARTn_CMD Register Busy                */
#define LEUART_SYNCBUSY_CLKDIV_SHIFT            2               /* Shift value for LEUART_SYNCBUSY_CLKDIV   */
#define LEUART_SYNCBUSY_CLKDIV_MASK             (0x1UL << 2)    /* Bit mask for LEUART_SYNCBUSY_CLKDIV      */
#define LEUART_SYNCBUSY_CLKDIV_DEFAULT          (0x0UL << 2)    /* Mode DEFAULT for LEUART_SYNCBUSY_CLKDIV  */
#define LEUART_SYNCBUSY_CLKDIV                  (0x1UL << 2)    /* LEUARTn_CLKDIV LEUART_SYNCBUSY_CLKDIV Bus*/
#define LEUART_SYNCBUSY_STARTFRAME_SHIFT        3               /* Shift value for LEUART_SYNCBUSY_STARTFRAM*/
#define LEUART_SYNCBUSY_STARTFRAME_MASK         (0x1UL << 3)    /* Bit mask for LEUART_SYNCBUSY_STARTFRAME  */
#define LEUART_SYNCBUSY_STARTFRAME_DEFAULT      (0x0UL << 3)    /* Mode DEFAULT for LEUART_SYNCBUSY_STARTFRA*/
#define LEUART_SYNCBUSY_STARTFRAME              (0x1UL << 3)    /* LEUARTn_STARTFRAME Register Busy         */
#define LEUART_SYNCBUSY_SIGFRAME_SHIFT          4               /* Shift value for LEUART_SYNCBUSY_SIGFRAME */
#define LEUART_SYNCBUSY_SIGFRAME_MASK           (0x1UL << 4)    /* Bit mask for LEUART_SYNCBUSY_SIGFRAME    */
#define LEUART_SYNCBUSY_SIGFRAME_DEFAULT        (0x0UL << 4)    /* Mode DEFAULT for LEUART_SYNCBUSY_SIGFRAME*/
#define LEUART_SYNCBUSY_SIGFRAME                (0x1UL << 4)    /* LEUARTn_SIGFRAME Register Busy           */
#define LEUART_SYNCBUSY_TXDATAX_SHIFT           5               /* Shift value for LEUART_SYNCBUSY_TXDATAX  */
#define LEUART_SYNCBUSY_TXDATAX_MASK            (0x1UL << 5)    /* Bit mask for LEUART_SYNCBUSY_TXDATAX     */
#define LEUART_SYNCBUSY_TXDATAX_DEFAULT         (0x0UL << 5)    /* Mode DEFAULT for LEUART_SYNCBUSY_TXDATAX */
#define LEUART_SYNCBUSY_TXDATAX                 (0x1UL << 5)    /* LEUARTn_TXDATAX Register Busy            */
#define LEUART_SYNCBUSY_TXDATA_SHIFT            6               /* Shift value for LEUART_SYNCBUSY_TXDATA   */
#define LEUART_SYNCBUSY_TXDATA_MASK             (0x1UL << 6)    /* Bit mask for LEUART_SYNCBUSY_TXDATA      */
#define LEUART_SYNCBUSY_TXDATA_DEFAULT          (0x0UL << 6)    /* Mode DEFAULT for LEUART_SYNCBUSY_TXDATA  */
#define LEUART_SYNCBUSY_TXDATA                  (0x1UL << 6)    /* LEUARTn_TXDATA Register Busy             */
#define LEUART_SYNCBUSY_PULSECTRL_SHIFT         7               /* Shift value for LEUART_SYNCBUSY_PULSECTRL*/
#define LEUART_SYNCBUSY_PULSECTRL_MASK          (0x1UL << 7)    /* Bit mask for LEUART_SYNCBUSY_PULSECTRL   */
#define LEUART_SYNCBUSY_PULSECTRL_DEFAULT       (0x0UL << 7)    /* Mode DEFAULT for LEUART_SYNCBUSY_PULSECTR*/
#define LEUART_SYNCBUSY_PULSECTRL               (0x1UL << 7)    /* LEUARTn_PULSECTRL Register Busy          */

/* Bit fields for LEUART ROUTE */
#define LEUART_ROUTE_RESETVALUE                 0x00000000UL    /* Default value for LEUART_ROUTE           */
#define LEUART_ROUTE_MASK                       0x00000303UL    /* Mask for LEUART_ROUTE                    */
#define LEUART_ROUTE_RXPEN_SHIFT                0               /* Shift value for LEUART_ROUTE_RXPEN       */
#define LEUART_ROUTE_RXPEN_MASK                 (0x1UL << 0)    /* Bit mask for LEUART_ROUTE_RXPEN          */
#define LEUART_ROUTE_RXPEN_DEFAULT              (0x0UL << 0)    /* Mode DEFAULT for LEUART_ROUTE_RXPEN      */
#define LEUART_ROUTE_RXPEN                      (0x1UL << 0)    /* RX Pin Enable                            */
#define LEUART_ROUTE_TXPEN_SHIFT                1               /* Shift value for LEUART_ROUTE_TXPEN       */
#define LEUART_ROUTE_TXPEN_MASK                 (0x1UL << 1)    /* Bit mask for LEUART_ROUTE_TXPEN          */
#define LEUART_ROUTE_TXPEN_DEFAULT              (0x0UL << 1)    /* Mode DEFAULT for LEUART_ROUTE_TXPEN      */
#define LEUART_ROUTE_TXPEN                      (0x1UL << 1)    /* TX Pin Enable                            */
#define LEUART_ROUTE_LOCATION_SHIFT             8               /* Shift value for LEUART_ROUTE_LOCATION    */
#define LEUART_ROUTE_LOCATION_MASK              (0x3UL << 8)    /* Bit mask for LEUART_ROUTE_LOCATION       */
#define LEUART_ROUTE_LOCATION_DEFAULT           (0x0UL << 8)    /* Mode DEFAULT for LEUART_ROUTE_LOCATION   */
#define LEUART_ROUTE_LOCATION_LOC0              (0x0UL << 8)    /* Mode LOC0 for LEUART_ROUTE_LOCATION      */
#define LEUART_ROUTE_LOCATION_LOC1              (0x1UL << 8)    /* Mode LOC1 for LEUART_ROUTE_LOCATION      */
#define LEUART_ROUTE_LOCATION_LOC2              (0x2UL << 8)    /* Mode LOC2 for LEUART_ROUTE_LOCATION      */
#define LEUART_ROUTE_LOCATION_LOC3              (0x3UL << 8)    /* Mode LOC3 for LEUART_ROUTE_LOCATION      */

#define LEUART_TX_IRQ_MASK                      (LEUART_IF_TXBL | LEUART_IF_TXOF)
#define LEUART_RX_IRQ_MASK                      (LEUART_IF_RXDATAV | LEUART_IF_RXOF | LEUART_IF_RXUF)
       
/*************************************************************************************************************
*                                                  DATA TYPES                                                *
*************************************************************************************************************/
/* Data Types for LEUART CTRL */    
typedef enum
{
    LEUART_0 = LEUART0_BASE, 
    LEUART_1 = LEUART1_BASE, 
} LEUARTTypeDef;   

typedef enum
{
    LEUART_DATABIT_EIGHT = LEUART_CTRL_DATABITS_EIGHT,
    LEUART_DATABIT_NINE  = LEUART_CTRL_DATABITS_NINE,
} LEUARTDataBitTypeDef;

typedef enum
{
    LEUART_PARITY_NONE = LEUART_CTRL_PARITY_NONE,
    LEUART_PARITY_EVEN = LEUART_CTRL_PARITY_EVEN,
    LEUART_PARITY_ODD  = LEUART_CTRL_PARITY_ODD,
} LEUARTParityModeTypeDef;

typedef enum
{
    LEUART_STOP_BIT_ONE = LEUART_CTRL_STOPBITS_ONE,
    LEUART_STOP_BIT_TWO = LEUART_CTRL_STOPBITS_TWO,
} LEUARTStopModeTypeDef;

typedef enum
{
    LEUART_MPMA_BIT_0 = LEUART_CTRL_MPAB_0, 
    LEUART_MPMA_BIT_1 = LEUART_CTRL_MPAB_1, 
} LEUARTMPMABitTypeDef;

typedef enum
{
    LEUART_BIT8DV_0 = LEUART_CTRL_BIT8DV_0,
    LEUART_BIT8DV_1 = LEUART_CTRL_BIT8DV_1,
} LEUARTBit8DefaultValueTypeDef;

typedef enum
{
    LEUART_TX_DELAY_NONE   = LEUART_CTRL_TXDELAY_NONE, 
    LEUART_TX_DELAY_SINGLE = LEUART_CTRL_TXDELAY_SINGLE, 
    LEUART_TX_DELAY_DOUBLE = LEUART_CTRL_TXDELAY_DOUBLE, 
    LEUART_TX_DELAY_TRIPLE = LEUART_CTRL_TXDELAY_TRIPLE, 
} LEUARTTxDelayTypeDef;

/* Data Types for LEUART CMD*/
typedef enum
{
    LEUART_RX  = LEUART_CMD_RXEN,
    LEUART_TX  = LEUART_CMD_TXEN,
    LEUART_RTX = LEUART_CMD_RXEN | LEUART_CMD_TXEN,
} LEUARTCmdRTxTypeDef;

/* Data Types for LEUART STATUS */ 
typedef enum
{
    LEUART_STATUS_FLAG_RXEN    = LEUART_STATUS_RXENS, 
    LEUART_STATUS_FLAG_TXEN    = LEUART_STATUS_TXENS,  
    LEUART_STATUS_FLAG_RXBLOCK = LEUART_STATUS_RXBLOCK, 
    LEUART_STATUS_FLAG_TXC     = LEUART_STATUS_TXC,  
    LEUART_STATUS_FLAG_TXBL    = LEUART_STATUS_TXBL, 
    LEUART_STATUS_FLAG_RXDATAV = LEUART_STATUS_RXDATAV,  
} LEUARTStatusTypeDef;

/* Data Types for LEUART RXDATAX */
typedef enum
{
    LEUART_RXDATAX_FLAG_PERR = LEUART_RXDATAX_PERR, 
    LEUART_RXDATAX_FLAG_FERR = LEUART_RXDATAX_FERR, 
} LEUARTRxDataExErrorTypeDef;

/* Data Types for LEUART RXDATAXP */
typedef enum
{
    LEUART_RXDATAXP_FLAG_PERRP = LEUART_RXDATAXP_PERRP, 
    LEUART_RXDATAXP_FLAG_FERRP = LEUART_RXDATAXP_FERRP, 
} LEUARTRxDataExPkErrorTypeDef;

/* Data Types for LEUART IF */
typedef enum 
{
    LEUART_INT_TXC     = LEUART_IF_TXC,
    LEUART_INT_TXBL    = LEUART_IF_TXBL,
    LEUART_INT_RXDATAV = LEUART_IF_RXDATAV,
    LEUART_INT_RXOF    = LEUART_IF_RXOF,
    LEUART_INT_RXUF    = LEUART_IF_RXUF,
    LEUART_INT_TXOF    = LEUART_IF_TXOF,
    LEUART_INT_PERR    = LEUART_IF_PERR,
    LEUART_INT_FERR    = LEUART_IF_FERR,
    LEUART_INT_MPAF    = LEUART_IF_MPAF,
    LEUART_INT_STARTF  = LEUART_IF_STARTF,
    LEUART_INT_SIGF    = LEUART_IF_SIGF,
} LEUARTIntTypeDef;

/* Data Types for LEUART FREEZE */
typedef enum 
{
    LEUART_FREEZE_UPDATE = LEUART_FREEZE_REGFREEZE_UPDATE,
    LEUART_FREEZE_FREEZE = LEUART_FREEZE_REGFREEZE_FREEZE,
} LEUARTRegFreezeModeTypeDef;

/* Data Types for LEUART SYNCBUSY */
typedef enum 
{
    LEUART_SYNCBUSY_REG_CTRL       = LEUART_SYNCBUSY_CTRL,
    LEUART_SYNCBUSY_REG_CMD        = LEUART_SYNCBUSY_CMD,
    LEUART_SYNCBUSY_REG_CLKDIV     = LEUART_SYNCBUSY_CLKDIV,
    LEUART_SYNCBUSY_REG_STARTFRAME = LEUART_SYNCBUSY_STARTFRAME,
    LEUART_SYNCBUSY_REG_SIGFRAME   = LEUART_SYNCBUSY_SIGFRAME,
    LEUART_SYNCBUSY_REG_TXDATAX    = LEUART_SYNCBUSY_TXDATAX,
    LEUART_SYNCBUSY_REG_TXDATA     = LEUART_SYNCBUSY_TXDATA,
    LEUART_SYNCBUSY_REG_PULSECTRL  = LEUART_SYNCBUSY_PULSECTRL,
} LEUARTSyncRegBusyFlagTypeDef;

/* Data Types for LEUART ROUTE */
typedef enum
{
    LEUART_ROUTE_LOCATE_LOC0 = LEUART_ROUTE_LOCATION_LOC0,
    LEUART_ROUTE_LOCATE_LOC1 = LEUART_ROUTE_LOCATION_LOC1,
    LEUART_ROUTE_LOCATE_LOC2 = LEUART_ROUTE_LOCATION_LOC2,
    LEUART_ROUTE_LOCATE_LOC3 = LEUART_ROUTE_LOCATION_LOC3,
} LEUARTLocationTypeDef;

/*************************************************************************************************************
*                                            FUNCTION PROTOTYPES                                             *
*************************************************************************************************************/
/* Function for USART CTRL */
static inline void LEUARTTxAutoTRIEnable (LEUARTTypeDef n)
{
    LEUARTRegTypeDef *leuart;
    
    leuart = (LEUARTRegTypeDef *)n;
    
    leuart->CTRL |= LEUART_CTRL_AUTOTRI;
}

static inline void LEUARTTxAutoTRIDisable (LEUARTTypeDef n)
{
    LEUARTRegTypeDef *leuart;
    
    leuart = (LEUARTRegTypeDef *)n;
    
    leuart->CTRL &= ~LEUART_CTRL_AUTOTRI;
}

static inline CPU_BOOL LEUARTTxAutoTRIFlagGet (LEUARTTypeDef n)
{
    LEUARTRegTypeDef *leuart;
    
    leuart = (LEUARTRegTypeDef *)n;
    
    if (leuart->CTRL & LEUART_CTRL_AUTOTRI_MASK)
    {
        return DEF_ON;
    }
    else 
    {
        return DEF_OFF;
    }
}

static inline void LEUARTDataBitSet (LEUARTTypeDef n, LEUARTDataBitTypeDef bits)
{
    LEUARTRegTypeDef *leuart;
    
    leuart = (LEUARTRegTypeDef *)n;
    
    leuart->CTRL &= ~LEUART_CTRL_DATABITS_MASK;
    leuart->CTRL |= bits;
}

static inline USARTDataBitTypeDef LEUARTDataBitModeGet (LEUARTTypeDef n)
{
    LEUARTRegTypeDef *leuart;
    
    leuart = (LEUARTRegTypeDef *)n;
    
    return  (USARTDataBitTypeDef)(leuart->CTRL & LEUART_CTRL_DATABITS_MASK);
}

static inline CPU_BOOL LEUARTDataBitModeFlagGet (LEUARTTypeDef n, USARTDataBitTypeDef mode)
{
    LEUARTRegTypeDef *leuart;
    
    leuart = (LEUARTRegTypeDef *)n;
    
    if (leuart->CTRL & mode)
    {
        return DEF_ON;
    }
    else
    {
        return DEF_OFF;
    }
}

static inline void LEUARTParityModeSet (LEUARTTypeDef n, LEUARTParityModeTypeDef parity)
{
    LEUARTRegTypeDef *leuart;
    
    leuart = (LEUARTRegTypeDef *)n;
    
    leuart->CTRL &= ~LEUART_CTRL_PARITY_MASK;
    leuart->CTRL |= parity;
}

static inline LEUARTParityModeTypeDef LEUARTParityModeGet (LEUARTTypeDef n)
{
    LEUARTRegTypeDef *leuart;
    
    leuart = (LEUARTRegTypeDef *)n;
    
    return (LEUARTParityModeTypeDef)(leuart->CTRL & LEUART_CTRL_PARITY_MASK);
}

static inline CPU_BOOL LEUARTParityModeFlagGet (LEUARTTypeDef n, LEUARTParityModeTypeDef parity)
{
    LEUARTRegTypeDef *leuart;
    
    leuart = (LEUARTRegTypeDef *)n;
    
    if (leuart->CTRL & parity)
    {
        return DEF_ON;
    }
    else 
    {
        return DEF_OFF;
    }
}

static inline void LEUARTStopModeSet (LEUARTTypeDef n, LEUARTStopModeTypeDef stop)
{
    LEUARTRegTypeDef *leuart;
    
    leuart = (LEUARTRegTypeDef *)n;
    
    leuart->CTRL &= ~LEUART_CTRL_STOPBITS_MASK;
    leuart->CTRL |= stop;
}

static inline LEUARTStopModeTypeDef LEUARTStopModeGet (LEUARTTypeDef n)
{
    LEUARTRegTypeDef *leuart;
    
    leuart = (LEUARTRegTypeDef *)n;
    
    return (LEUARTStopModeTypeDef)(leuart->CTRL & LEUART_CTRL_STOPBITS_MASK);
}

static inline CPU_BOOL LEUARTStopModeFlagGet (LEUARTTypeDef n, LEUARTStopModeTypeDef stop)
{
    LEUARTRegTypeDef *leuart;
    
    leuart = (LEUARTRegTypeDef *)n;
    
    if (leuart->CTRL & stop)
    {
        return DEF_ON;
    }
    else 
    {
        return DEF_OFF;
    }
}

static inline void LEUARTInputAndOutputInvertEnable (LEUARTTypeDef n)
{
    LEUARTRegTypeDef *leuart;
    
    leuart = (LEUARTRegTypeDef *)n;
    
    leuart->CTRL |= LEUART_CTRL_INV;
}

static inline void LEUARTInputAndOutputInvertDisable (LEUARTTypeDef n)
{
    LEUARTRegTypeDef *leuart;
    
    leuart = (LEUARTRegTypeDef *)n;
    
    leuart->CTRL &= ~LEUART_CTRL_INV;
}

static inline CPU_BOOL LEUARTInputAndOutputInvertFlagGet (LEUARTTypeDef n)
{
    LEUARTRegTypeDef *leuart;
    
    leuart = (LEUARTRegTypeDef *)n;
    
    if (leuart->CTRL & LEUART_CTRL_INV_MASK)
    {
        return DEF_ON;
    }
    else 
    {
        return DEF_OFF;
    }
}

static inline void LEUARTClearRxDMAOnErrorEnable (LEUARTTypeDef n)
{
    LEUARTRegTypeDef *leuart;
    
    leuart = (LEUARTRegTypeDef *)n;
    
    leuart->CTRL |= LEUART_CTRL_ERRSDMA;
}

static inline void LEUARTClearRxDMAOnErrorDisable (LEUARTTypeDef n)
{
    LEUARTRegTypeDef *leuart;
    
    leuart = (LEUARTRegTypeDef *)n;
    
    leuart->CTRL &= ~LEUART_CTRL_ERRSDMA;
}

static inline CPU_BOOL LEUARTClearRxDMAOnErrorFlagGet (LEUARTTypeDef n)
{
    LEUARTRegTypeDef *leuart;
    
    leuart = (LEUARTRegTypeDef *)n;
    
    if (leuart->CTRL & LEUART_CTRL_ERRSDMA_MASK)
    {
        return DEF_ON;
    }
    else 
    {
        return DEF_OFF;
    }
}

static inline void LEUARTLookbackEnable (LEUARTTypeDef n)
{
    LEUARTRegTypeDef *leuart;
    
    leuart = (LEUARTRegTypeDef *)n;
    
    leuart->CTRL |= LEUART_CTRL_LOOPBK;
}   

static inline void LEUARTLookbackDisable (LEUARTTypeDef n)
{
    LEUARTRegTypeDef *leuart;
    
    leuart = (LEUARTRegTypeDef *)n;
    
    leuart->CTRL &= ~LEUART_CTRL_LOOPBK;
}

static inline CPU_BOOL LEUARTLookbackFlagGet (LEUARTTypeDef n)
{
    LEUARTRegTypeDef *leuart;
    
    leuart = (LEUARTRegTypeDef *)n;
    
    if (leuart->CTRL & LEUART_CTRL_LOOPBK_MASK)
    {
        return DEF_ON;
    }
    else 
    {
        return DEF_OFF;
    }
}

static inline void LEUARTStartFrameUnBlockRxEnable (LEUARTTypeDef n)
{
    LEUARTRegTypeDef *leuart;
    
    leuart = (LEUARTRegTypeDef *)n;
    
    leuart->CTRL |= LEUART_CTRL_SFUBRX;
}

static inline void LEUARTStartFrameUnBlockRxDisable (LEUARTTypeDef n)
{
    LEUARTRegTypeDef *leuart;
    
    leuart = (LEUARTRegTypeDef *)n;
    
    leuart->CTRL &= ~LEUART_CTRL_SFUBRX;
}

static inline CPU_BOOL LEUARTStartFrameUnBlockRxFlagGet (LEUARTTypeDef n)
{
    LEUARTRegTypeDef *leuart;
    
    leuart = (LEUARTRegTypeDef *)n;
    
    if (leuart->CTRL & LEUART_CTRL_SFUBRX_MASK)
    {
        return DEF_ON;
    }
    else 
    {
        return DEF_OFF;
    }
}

static inline void LEUARTMultiProcessorModeEnable (LEUARTTypeDef n)
{
    LEUARTRegTypeDef *leuart;
    
    leuart = (LEUARTRegTypeDef *)n;
    
    leuart->CTRL |= LEUART_CTRL_MPM;
}

static inline void LEUARTMultiProcessorModeDisable (LEUARTTypeDef n)
{
    LEUARTRegTypeDef *leuart;
    
    leuart = (LEUARTRegTypeDef *)n;
    
    leuart->CTRL &= ~LEUART_CTRL_MPM;
}

static inline CPU_BOOL LEUARTMultiProcessorModeFlagGet (LEUARTTypeDef n)
{
    LEUARTRegTypeDef *leuart;
    
    leuart = (LEUARTRegTypeDef *)n;
    
    if (leuart->CTRL & LEUART_CTRL_MPM_MASK)
    {
        return DEF_ON;
    }
    else 
    {
        return DEF_OFF;
    }
}

static inline void LEUARTMPMABitSet (USARTTypeDef n, LEUARTMPMABitTypeDef bit)
{
    LEUARTRegTypeDef *leuart;
    
    leuart = (LEUARTRegTypeDef *)n;
    
    leuart->CTRL &= ~LEUART_CTRL_MPAB_MASK;
    leuart->CTRL |= bit;
}

static inline LEUARTMPMABitTypeDef LEUARTMPMABitGet (USARTTypeDef n)
{
    LEUARTRegTypeDef *leuart;
    
    leuart = (LEUARTRegTypeDef *)n;
    
    return (LEUARTMPMABitTypeDef)(leuart->CTRL & LEUART_CTRL_MPAB_MASK);
}

static inline CPU_BOOL LEUARTMPMABitFlagGet (USARTTypeDef n, LEUARTMPMABitTypeDef bit)
{
    LEUARTRegTypeDef *leuart;
    
    leuart = (LEUARTRegTypeDef *)n;
    
    if (leuart->CTRL & bit)
    {
        return DEF_ON;
    }
    else
    {
        return DEF_OFF;
    }
}

static inline void LEUARTBit8DefaultValueSet (LEUARTTypeDef n, LEUARTBit8DefaultValueTypeDef value)
{
    LEUARTRegTypeDef *leuart;
    
    leuart = (LEUARTRegTypeDef *)n;
    
    leuart->CTRL &= ~LEUART_CTRL_BIT8DV_MASK;
    leuart->CTRL |= value;
}

static inline LEUARTBit8DefaultValueTypeDef LEUARTBit8DefaultValueGet (LEUARTTypeDef n)
{
    LEUARTRegTypeDef *leuart;
    
    leuart = (LEUARTRegTypeDef *)n;
    
    return (LEUARTBit8DefaultValueTypeDef)(leuart->CTRL & LEUART_CTRL_BIT8DV_MASK);
}

static inline CPU_BOOL LEUARTBit8DefaultValueFlagGet (LEUARTTypeDef n, LEUARTBit8DefaultValueTypeDef value)
{
    LEUARTRegTypeDef *leuart;
    
    leuart = (LEUARTRegTypeDef *)n;
    
    if (leuart->CTRL & value)
    {
        return DEF_ON;
    }
    else 
    {
        return DEF_OFF;
    }
}

static inline void LEUARTRxDMAWakeUpEnable (LEUARTTypeDef n)
{
    LEUARTRegTypeDef *leuart;
    
    leuart = (LEUARTRegTypeDef *)n;
    
    leuart->CTRL |= LEUART_CTRL_RXDMAWU;
}

static inline void LEUARTRxDMAWakeUpDisable (LEUARTTypeDef n)
{
    LEUARTRegTypeDef *leuart;
    
    leuart = (LEUARTRegTypeDef *)n;
    
    leuart->CTRL &= ~LEUART_CTRL_RXDMAWU;
}

static inline CPU_BOOL LEUARTRxDMAWakeUpFlagGet (LEUARTTypeDef n)
{
    LEUARTRegTypeDef *leuart;
    
    leuart = (LEUARTRegTypeDef *)n;
    
    if (leuart->CTRL & LEUART_CTRL_RXDMAWU_MASK)
    {
        return DEF_ON;
    }
    else 
    {
        return DEF_OFF;
    }
}

static inline void LEUARTTxDMAWakeUpEnable (LEUARTTypeDef n)
{
    LEUARTRegTypeDef *leuart;
    
    leuart = (LEUARTRegTypeDef *)n;
    
    leuart->CTRL |= LEUART_CTRL_TXDMAWU;
}

static inline void LEUARTTxDMAWakeUpDisable (LEUARTTypeDef n)
{
    LEUARTRegTypeDef *leuart;
    
    leuart = (LEUARTRegTypeDef *)n;
    
    leuart->CTRL &= ~LEUART_CTRL_TXDMAWU;
}

static inline CPU_BOOL LEUARTTxDMAWakeUpFlagGet (LEUARTTypeDef n)
{
    LEUARTRegTypeDef *leuart;
    
    leuart = (LEUARTRegTypeDef *)n;
    
    if (leuart->CTRL & LEUART_CTRL_TXDMAWU_MASK)
    {
        return DEF_ON;
    }
    else 
    {
        return DEF_OFF;
    }    
}

static inline void LEUARTTxDelaySet (LEUARTTypeDef n, LEUARTTxDelayTypeDef delay)
{
    LEUARTRegTypeDef *leuart;
    
    leuart = (LEUARTRegTypeDef *)n;
    
    leuart->CTRL &= ~LEUART_CTRL_TXDELAY_MASK;
    leuart->CTRL |= delay; 
}

static inline LEUARTTxDelayTypeDef LEUARTTxDelayGet (LEUARTTypeDef n)
{
    LEUARTRegTypeDef *leuart;
    
    leuart = (LEUARTRegTypeDef *)n;
    
    return (LEUARTTxDelayTypeDef)(leuart->CTRL & LEUART_CTRL_TXDELAY_MASK);
}

static inline CPU_BOOL LEUARTTxDelayFlagGet (LEUARTTypeDef n, LEUARTTxDelayTypeDef delay)
{
    LEUARTRegTypeDef *leuart;
    
    leuart = (LEUARTRegTypeDef *)n;
    
    if (leuart->CTRL & delay)
    {
        return DEF_ON;
    }
    else 
    {
        return DEF_OFF;
    }
}

/* Function for USART CMD */
static inline void LEUARTCmd (LEUARTTypeDef n, CPU_INT32U cmd)
{
    LEUARTRegTypeDef *leuart;
    
    leuart = (LEUARTRegTypeDef *)n;
    
    leuart->CMD |= cmd;
}

static inline void LEUARTCmdRxEnable (LEUARTTypeDef n)
{
    LEUARTRegTypeDef *leuart;
    
    leuart = (LEUARTRegTypeDef *)n;
    
    leuart->CMD |= LEUART_CMD_RXEN;
}

static inline void LEUARTCmdRxDisable (LEUARTTypeDef n)
{
    LEUARTRegTypeDef *leuart;
    
    leuart = (LEUARTRegTypeDef *)n;
    
    leuart->CMD |= LEUART_CMD_RXDIS;
}

static inline void LEUARTCmdTxEnable (LEUARTTypeDef n)
{
    LEUARTRegTypeDef *leuart;
    
    leuart = (LEUARTRegTypeDef *)n;
    
    leuart->CMD |= LEUART_CMD_TXEN;
}

static inline void LEUARTCmdTxDisable (LEUARTTypeDef n)
{
    LEUARTRegTypeDef *leuart;
    
    leuart = (LEUARTRegTypeDef *)n;
    
    leuart->CMD |= LEUART_CMD_TXDIS;
}

static inline void LEUARTCmdReceiverBlockEnable (LEUARTTypeDef n)
{
    LEUARTRegTypeDef *leuart;
    
    leuart = (LEUARTRegTypeDef *)n;
    
    leuart->CMD |= LEUART_CMD_RXBLOCKEN;
}

static inline void LEUARTCmdReceiverBlockDisable (LEUARTTypeDef n)
{
    LEUARTRegTypeDef *leuart;
    
    leuart = (LEUARTRegTypeDef *)n;
    
    leuart->CMD |= LEUART_CMD_RXBLOCKDIS;
}

static inline void LEUARTCmdTxClear (LEUARTTypeDef n)
{
    LEUARTRegTypeDef *leuart;
    
    leuart = (LEUARTRegTypeDef *)n;
    
    leuart->CMD |= LEUART_CMD_CLEARTX;
}

static inline void LEUARTCmdRxClear (LEUARTTypeDef n)
{
    LEUARTRegTypeDef *leuart;
    
    leuart = (LEUARTRegTypeDef *)n;
    
    leuart->CMD |= LEUART_CMD_CLEARRX;
}

/* Function for USART STATUS */
static inline LEUARTStatusTypeDef LEUARTStatusGet (LEUARTTypeDef n)
{
    LEUARTRegTypeDef *leuart;
    
    leuart = (LEUARTRegTypeDef *)n;
    
    return (LEUARTStatusTypeDef)(leuart->STATUS & LEUART_STATUS_MASK);
}

static inline CPU_BOOL LEUARTStatusFlagGet (LEUARTTypeDef n, LEUARTStatusTypeDef flag)
{
    LEUARTRegTypeDef *leuart;
    
    leuart = (LEUARTRegTypeDef *)n;
    
    if (leuart->STATUS & flag)
    {
        return DEF_ON;
    }
    else
    {
        return DEF_OFF;
    }
}

/* Function for LEUART CLKDIV */
static inline void LEUARTClockDivSet (LEUARTTypeDef n, CPU_INT32U div)
{
    LEUARTRegTypeDef *leuart;
    
    leuart = (LEUARTRegTypeDef *)n;
    
    leuart->CLKDIV = (div << LEUART_CLKDIV_DIV_SHIFT);
}

static inline CPU_INT32U LEUARTClockDivGet (LEUARTTypeDef n)
{
    LEUARTRegTypeDef *leuart;
    
    leuart = (LEUARTRegTypeDef *)n;
    
    return ((leuart->CLKDIV & LEUART_CLKDIV_DIV_MASK) >> LEUART_CLKDIV_DIV_SHIFT);
}

/* Function for LEUART  STARTFRAME */
static inline void LEUARTStartFrameSet (LEUARTTypeDef n, CPU_INT32U frame)
{
    LEUARTRegTypeDef *leuart;
    
    leuart = (LEUARTRegTypeDef *)n;
    
    leuart->STARTFRAME = (frame << LEUART_STARTFRAME_STARTFRAME_SHIFT);
}

static inline CPU_INT32U LEUARTStartFrameGet (LEUARTTypeDef n)
{
    LEUARTRegTypeDef *leuart;
    
    leuart = (LEUARTRegTypeDef *)n;
    
    return ((leuart->STARTFRAME & LEUART_STARTFRAME_STARTFRAME_MASK) >> LEUART_STARTFRAME_STARTFRAME_SHIFT);
}

/* Function for LEUART  SIGFRAME */
static inline void LEUARTSignalFrameSet (LEUARTTypeDef n, CPU_INT32U signal)
{
    LEUARTRegTypeDef *leuart;
    
    leuart = (LEUARTRegTypeDef *)n;
    
    leuart->SIGFRAME = (signal << LEUART_SIGFRAME_SIGFRAME_SHIFT);
}

static inline CPU_INT32U LEUARTSignalFrameGet (LEUARTTypeDef n)
{
    LEUARTRegTypeDef *leuart;
    
    leuart = (LEUARTRegTypeDef *)n;
    
    return ((leuart->SIGFRAME & LEUART_SIGFRAME_SIGFRAME_MASK) >> LEUART_SIGFRAME_SIGFRAME_SHIFT);
}

/* Function for LEUART  RXDATAX */
static inline CPU_INT16U LEUARTRxDataExGet (LEUARTTypeDef n)
{
    LEUARTRegTypeDef *leuart;
    
    leuart = (LEUARTRegTypeDef *)n;
    
    return (CPU_INT16U)(leuart->RXDATAX & LEUART_RXDATAX_RXDATA_MASK);
}

static inline LEUARTRxDataExErrorTypeDef LEUARTRxDataExErrorGet (USARTTypeDef n)
{
    LEUARTRegTypeDef *leuart;
    
    leuart = (LEUARTRegTypeDef *)n;
    
    return (LEUARTRxDataExErrorTypeDef)(leuart->RXDATAX & (LEUART_RXDATAX_PERR_MASK | LEUART_RXDATAX_FERR_MASK));
}

static inline CPU_BOOL LEUARTRxDataExErrorFlagGet (LEUARTTypeDef n, LEUARTRxDataExErrorTypeDef flag)
{
    LEUARTRegTypeDef *leuart;
    
    leuart = (LEUARTRegTypeDef *)n;
    
    if (leuart->RXDATAX & flag)
    {
        return DEF_ON;
    }
    else
    {
        return DEF_OFF;
    }
}

/* Function for LEUART  RXDATA */
static inline CPU_INT8U LEUARTRxDataGet (LEUARTTypeDef n)
{
    LEUARTRegTypeDef *leuart;
    
    leuart = (LEUARTRegTypeDef *)n;
    
    return (CPU_INT8U)(leuart->RXDATA & LEUART_RXDATA_MASK);
}

/* Function for USART RXDATAXP */
static inline CPU_INT16U LEUARTRxDataExPkGet (LEUARTTypeDef n)
{
    LEUARTRegTypeDef *leuart;
    
    leuart = (LEUARTRegTypeDef *)n;
    
    return (CPU_INT16U)(leuart->RXDATAXP & LEUART_RXDATAXP_RXDATAP_MASK);
}

static inline LEUARTRxDataExPkErrorTypeDef LEUARTRxDataExPkErrorGet (LEUARTTypeDef n)
{
    LEUARTRegTypeDef *leuart;
    
    leuart = (LEUARTRegTypeDef *)n;
    
    return (LEUARTRxDataExPkErrorTypeDef)(leuart->RXDATAXP & 
                                          (LEUART_RXDATAXP_PERRP_MASK | LEUART_RXDATAXP_FERRP_MASK));
}

static inline CPU_BOOL LEUARTRxDataExPkErrorFlagGet (LEUARTTypeDef n, LEUARTRxDataExPkErrorTypeDef flag)
{
    LEUARTRegTypeDef *leuart;
    
    leuart = (LEUARTRegTypeDef *)n;
    
    if (leuart->RXDATAXP & flag)
    {
        return DEF_ON;
    }
    else
    {
        return DEF_OFF;
    }
}

/* Function for LEUART TXDATAX */
static inline void LEUARTTxDataExSet (LEUARTTypeDef n, CPU_INT16U data)
{
    LEUARTRegTypeDef *leuart;
    
    leuart = (LEUARTRegTypeDef *)n;
    
    //leuart->TXDATAX &= ~LEUART_TXDATAX_TXDATA_MASK;
    leuart->TXDATAX |= (data & LEUART_TXDATAX_TXDATA_MASK);
}

static inline void LEUARTTransmitDataAsBreakEnable (LEUARTTypeDef n)
{
    LEUARTRegTypeDef *leuart;
    
    leuart = (LEUARTRegTypeDef *)n;
    
    leuart->TXDATAX |= LEUART_TXDATAX_TXBREAK;
}

static inline void LEUARTTransmitDataAsBreakDisable (LEUARTTypeDef n)
{
    LEUARTRegTypeDef *leuart;
    
    leuart = (LEUARTRegTypeDef *)n;
    
    leuart->TXDATAX &= ~LEUART_TXDATAX_TXBREAK;
}

static inline void LEUARTDisableTXAfterTransmissionSet (LEUARTTypeDef n)
{
    LEUARTRegTypeDef *leuart;
    
    leuart = (LEUARTRegTypeDef *)n;
    
    leuart->TXDATAX |= LEUART_TXDATAX_TXDISAT;
}

static inline void LEUARTEnableRXAfterTransmissionSet (LEUARTTypeDef n)
{
    LEUARTRegTypeDef *leuart;
    
    leuart = (LEUARTRegTypeDef *)n;
    
    leuart->TXDATAX |= LEUART_TXDATAX_RXENAT;
}

/* Function for LEUART TXDATA */
static inline void LEUARTTxDataSet (LEUARTTypeDef n, CPU_INT8U data)
{
    LEUARTRegTypeDef *leuart;
    
    leuart = (LEUARTRegTypeDef *)n;
    
    //leuart->TXDATA &= ~LEUART_TXDATA_TXDATA_MASK;
    leuart->TXDATA |= (data & LEUART_TXDATA_TXDATA_MASK);
}

/* Function for LEUART IF */
static inline CPU_INT32U LEUARTIntGet (LEUARTTypeDef n)
{
    LEUARTRegTypeDef *leuart;
    
    leuart = (LEUARTRegTypeDef *)n;
    
    return (CPU_INT32U)(leuart->IF & LEUART_IF_MASK);
}

static inline CPU_BOOL LEUARTIntFlagGet (LEUARTTypeDef n, LEUARTIntTypeDef flag)
{
    LEUARTRegTypeDef *leuart;
    
    leuart = (LEUARTRegTypeDef *)n;
    
    if (leuart->IF & flag)
    {
        return DEF_ON;
    }
    else
    {
        return DEF_OFF;
    }
}

/* Function for LEUART IFS */
static inline void LEUARTIntSet (LEUARTTypeDef n, CPU_INT32U flag)
{
    LEUARTRegTypeDef *leuart;
    
    leuart = (LEUARTRegTypeDef *)n;
    
    leuart->IFS |= flag;
}

/* Function for LEUART IFC */
static inline void LEUARTIntClear (LEUARTTypeDef n, CPU_INT32U flag)
{
    LEUARTRegTypeDef *leuart;
    
    leuart = (LEUARTRegTypeDef *)n;
    
    leuart->IFC |= flag;
}

/* Function for LEUART IEN */
static inline void LEUARTIntEnable (LEUARTTypeDef n, CPU_INT32U flag)
{
    LEUARTRegTypeDef *leuart;
    
    leuart = (LEUARTRegTypeDef *)n;
    
    leuart->IEN |= flag;
}

static inline void LEUARTIntDisable (LEUARTTypeDef n, CPU_INT32U flag)
{
    LEUARTRegTypeDef *leuart;
    
    leuart = (LEUARTRegTypeDef *)n;
    
    leuart->IEN &= ~flag;
}

static inline CPU_INT32U LEUARTIntStatusGet (LEUARTTypeDef n)
{
    LEUARTRegTypeDef *leuart;
    
    leuart = (LEUARTRegTypeDef *)n;
    
    return (CPU_INT32U)(leuart->IEN & LEUART_IEN_MASK);
}

static inline CPU_BOOL LEUARTIntStatusFlagGet (LEUARTTypeDef n, LEUARTIntTypeDef flag)
{
    LEUARTRegTypeDef *leuart;
    
    leuart = (LEUARTRegTypeDef *)n;
    
    if (leuart->IEN & flag)
    {
        return DEF_ON;
    }
    else
    {
        return DEF_OFF;
    }
}

static inline CPU_INT32U LEUARTIntEnableGet (LEUARTTypeDef n)
{
    LEUARTRegTypeDef *leuart;
    CPU_INT32U en;
    
    leuart = (LEUARTRegTypeDef *)n;
    
    en = 0;
    en = leuart->IEN;

    /* Bitwise AND of pending and enabled interrupts */
    return (CPU_INT32U)((leuart->IF & en) & LEUART_IF_MASK);
}

static inline CPU_BOOL LEUARTIntEnableFlagGet (LEUARTTypeDef n, LEUARTIntTypeDef flag)
{
    LEUARTRegTypeDef *leuart;
    CPU_INT32U en;
    
    leuart = (LEUARTRegTypeDef *)n;
    
    en = 0;
    en = leuart->IEN;
    
    if ((leuart->IF & en) & flag)
    {
        return DEF_ON;
    }
    else
    {
        return DEF_OFF;
    }
}

/* Function for LEUART PULSECTRL */
static inline void LEUARTPulseWidthSet (LEUARTTypeDef n,  CPU_INT32U width)
{
    LEUARTRegTypeDef *leuart;
    
    leuart = (LEUARTRegTypeDef *)n;
    
    leuart->PULSECTRL &= ~LEUART_PULSECTRL_PULSEW_MASK;
    
    leuart->PULSECTRL |= width;
}

static inline CPU_INT8U LEUARTPulseWidthGet (LEUARTTypeDef n)
{
    LEUARTRegTypeDef *leuart;
    
    leuart = (LEUARTRegTypeDef *)n;
    
    return (CPU_INT8U)(leuart->PULSECTRL & LEUART_PULSECTRL_PULSEW_MASK);
}

static inline void LEUARTPulseGeneratorExtenderEnable (LEUARTTypeDef n)
{
    LEUARTRegTypeDef *leuart;
    
    leuart = (LEUARTRegTypeDef *)n;
    
    leuart->PULSECTRL |= LEUART_PULSECTRL_PULSEEN;
}

static inline void LEUARTPulseGeneratorExtenderDisable (LEUARTTypeDef n)
{
    LEUARTRegTypeDef *leuart;
    
    leuart = (LEUARTRegTypeDef *)n;
    
    leuart->PULSECTRL &= ~LEUART_PULSECTRL_PULSEEN;
}

static inline CPU_BOOL LEUARTPulseGeneratorExtenderFlagGet (LEUARTTypeDef n)
{
    LEUARTRegTypeDef *leuart;
    
    leuart = (LEUARTRegTypeDef *)n;
    
    if (leuart->PULSECTRL & LEUART_PULSECTRL_PULSEEN_MASK)
    {
        return DEF_ON;
    }
    else 
    {
        return DEF_OFF;
    }
}

static inline void LEUARTPulseFilterEnable (LEUARTTypeDef n)
{
    LEUARTRegTypeDef *leuart;
    
    leuart = (LEUARTRegTypeDef *)n;

    leuart->PULSECTRL |= LEUART_PULSECTRL_PULSEFILT;
}

static inline void LEUARTPulseFilterDisable (LEUARTTypeDef n)
{
    LEUARTRegTypeDef *leuart;
    
    leuart = (LEUARTRegTypeDef *)n;

    leuart->PULSECTRL &= ~LEUART_PULSECTRL_PULSEFILT; 
}

static inline CPU_BOOL LEUARTPulseFilterFlagGet (LEUARTTypeDef n)
{
    LEUARTRegTypeDef *leuart;
    
    leuart = (LEUARTRegTypeDef *)n;
    
    if (leuart->PULSECTRL & LEUART_PULSECTRL_PULSEFILT_MASK)
    {
        return DEF_ON;
    }
    else 
    {
        return DEF_OFF;
    }
}
 
/* Function for LEUART FREEZE */
static inline void LEUARTRegFreezeModeSet (LEUARTTypeDef n, LEUARTRegFreezeModeTypeDef mode)
{
    LEUARTRegTypeDef *leuart;
    
    leuart = (LEUARTRegTypeDef *)n; 
    
    leuart->FREEZE &= ~LEUART_FREEZE_REGFREEZE_MASK;
    
    leuart->FREEZE |= mode;
}

static inline LEUARTRegFreezeModeTypeDef LEUARTRegFreezeModeGet (LEUARTTypeDef n)
{
    LEUARTRegTypeDef *leuart;
    
    leuart = (LEUARTRegTypeDef *)n;
    
    return (LEUARTRegFreezeModeTypeDef)(leuart->FREEZE & LEUART_FREEZE_REGFREEZE_MASK);
}

static inline CPU_BOOL LEUARTRegFreezeModeFlagGet (LEUARTTypeDef n, LEUARTRegFreezeModeTypeDef mode)
{
    LEUARTRegTypeDef *leuart;
    
    leuart = (LEUARTRegTypeDef *)n;
    
    if (leuart->FREEZE & mode)
    {
        return DEF_ON;
    }
    else
    {
        return DEF_OFF;
    }
}

/* Function for LEUART SYNCBUSY */
static inline CPU_INT8U LEUARTSyncRegBusyGet (LEUARTTypeDef n)
{
    LEUARTRegTypeDef *leuart;
    
    leuart = (LEUARTRegTypeDef *)n;
    
    return (CPU_INT8U)(leuart->SYNCBUSY & LEUART_SYNCBUSY_MASK);
}

static inline CPU_BOOL LEUARTSyncRegBusyFlagGet (LEUARTTypeDef n, LEUARTSyncRegBusyFlagTypeDef flag)
{
    LEUARTRegTypeDef *leuart;
    
    leuart = (LEUARTRegTypeDef *)n;
    
    if (leuart->SYNCBUSY & flag)
    {
        return DEF_ON;
    }
    else
    {
        return DEF_OFF;
    }
}

/* Function for LEUART ROUTE */
static inline void LEUARTRxPinEnable (LEUARTTypeDef n)
{
    LEUARTRegTypeDef *leuart;
    
    leuart = (LEUARTRegTypeDef *)n;
    
    leuart->ROUTE |= LEUART_ROUTE_RXPEN;
}

static inline void LEUARTRxPinDisable (LEUARTTypeDef n)
{
    LEUARTRegTypeDef *leuart;
    
    leuart = (LEUARTRegTypeDef *)n;
    
    leuart->ROUTE &= ~LEUART_ROUTE_RXPEN;
}

static inline CPU_BOOL LEUARTRxPinFlagGet (LEUARTTypeDef n)
{
    LEUARTRegTypeDef *leuart;
    
    leuart = (LEUARTRegTypeDef *)n;
    
    if (leuart->ROUTE & LEUART_ROUTE_RXPEN_MASK)
    {
        return DEF_ON;
    }
    else
    {
        return DEF_OFF;
    }
}

static inline void LEUARTTxPinEnable (LEUARTTypeDef n)
{
    LEUARTRegTypeDef *leuart;
    
    leuart = (LEUARTRegTypeDef *)n;
    
    leuart->ROUTE |= LEUART_ROUTE_TXPEN;
}

static inline void LEUARTTxPinDisable (LEUARTTypeDef n)
{
    LEUARTRegTypeDef *leuart;
    
    leuart = (LEUARTRegTypeDef *)n;
    
    leuart->ROUTE &= ~LEUART_ROUTE_TXPEN;
}

static inline CPU_BOOL LEUARTTxPinFlagGet (LEUARTTypeDef n)
{
    LEUARTRegTypeDef *leuart;
    
    leuart = (LEUARTRegTypeDef *)n;
    
    if (leuart->ROUTE & LEUART_ROUTE_TXPEN_MASK)
    {
        return DEF_ON;
    }
    else
    {
        return DEF_OFF;
    }
}

static inline void LEUARTLocationSet (LEUARTTypeDef n, LEUARTLocationTypeDef location)
{
    LEUARTRegTypeDef *leuart;
    
    leuart = (LEUARTRegTypeDef *)n;
    
    leuart->ROUTE &= ~LEUART_ROUTE_LOCATION_MASK;
    
    leuart->ROUTE |= location;
}

static inline LEUARTLocationTypeDef LEUARTLocationGet (LEUARTTypeDef n)
{
    LEUARTRegTypeDef *leuart;
    
    leuart = (LEUARTRegTypeDef *)n;
    
    return (LEUARTLocationTypeDef)(leuart->ROUTE & LEUART_ROUTE_LOCATION_MASK);
}

static inline CPU_BOOL LEUARTLocationFlagGet (LEUARTTypeDef n, LEUARTLocationTypeDef location)
{
    LEUARTRegTypeDef *leuart;
    
    leuart = (LEUARTRegTypeDef *)n;
    
    if (leuart->ROUTE & location)
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
void LEUARTClockEnable (LEUARTTypeDef x);
void LEUARTClockDisable (LEUARTTypeDef x);
void LEUARTBaudSet (LEUARTTypeDef x, CPU_INT32U baud);
CPU_INT32U LEUARTBaudGet (LEUARTTypeDef x);
void LEUARTConfig (LEUARTTypeDef x, LEUARTDataBitTypeDef bits, 
                   LEUARTParityModeTypeDef parity, LEUARTStopModeTypeDef stop);
void LEUARTEnable (LEUARTTypeDef x, LEUARTCmdRTxTypeDef rtx);
void LEUARTDisable (LEUARTTypeDef x, LEUARTCmdRTxTypeDef rtx);
CPU_INT8U LEUARTRxByte (LEUARTTypeDef x);
void LEUARTTxByte (LEUARTTypeDef x, CPU_INT8U byte);
    
/*************************************************************************************************************
*                                               MODULE END                                                   *
*************************************************************************************************************/     
#ifdef __cplusplus
}
#endif

#endif 