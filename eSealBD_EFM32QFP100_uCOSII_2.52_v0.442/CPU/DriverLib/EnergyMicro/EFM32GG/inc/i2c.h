/*************************************************************************************************************
*                                                  MODULE                                                    *
*************************************************************************************************************/
#ifndef I2C_H
#define I2C_H

#ifdef __cplusplus
extern "C" {
#endif
    

/*************************************************************************************************************
*                                                 DEFINES                                                    *
*************************************************************************************************************/
#define I2C                                     ((I2CRegTypeDef *)I2C0_BASE)

/* Bit fields for I2C CTRL */
#define I2C_CTRL_RESETVALUE                     0x00000000UL        /* Default value for I2C_CTRL           */
#define I2C_CTRL_MASK                           0x0007B37FUL        /* Mask for I2C_CTRL                    */
#define I2C_CTRL_EN                             (0x1UL << 0)        /* I2C Enable                           */
#define I2C_CTRL_EN_SHIFT                       0                   /* Shift value for I2C_EN               */
#define I2C_CTRL_EN_MASK                        0x1UL               /* Bit mask for I2C_EN                  */
#define I2C_CTRL_EN_DEFAULT                     (0x00000000UL << 0) /* Shifted mode DEFAULT for I2C_CTRL    */
#define I2C_CTRL_SLAVE                          (0x1UL << 1)        /* Addressable as Slave                 */
#define I2C_CTRL_SLAVE_SHIFT                    1                   /* Shift value for I2C_SLAVE            */
#define I2C_CTRL_SLAVE_MASK                     0x2UL               /* Bit mask for I2C_SLAVE               */
#define I2C_CTRL_SLAVE_DEFAULT                  (0x00000000UL << 1) /* Shifted mode DEFAULT for I2C_CTRL    */
#define I2C_CTRL_AUTOACK                        (0x1UL << 2)        /* Automatic Acknowledge                */
#define I2C_CTRL_AUTOACK_SHIFT                  2                   /* Shift value for I2C_AUTOACK          */
#define I2C_CTRL_AUTOACK_MASK                   0x4UL               /* Bit mask for I2C_AUTOACK             */
#define I2C_CTRL_AUTOACK_DEFAULT                (0x00000000UL << 2) /* Shifted mode DEFAULT for I2C_CTRL    */
#define I2C_CTRL_AUTOSE                         (0x1UL << 3)        /* Automatic STOP when Empty            */
#define I2C_CTRL_AUTOSE_SHIFT                   3                   /* Shift value for I2C_AUTOSE           */
#define I2C_CTRL_AUTOSE_MASK                    0x8UL               /* Bit mask for I2C_AUTOSE              */
#define I2C_CTRL_AUTOSE_DEFAULT                 (0x00000000UL << 3) /* Shifted mode DEFAULT for I2C_CTRL    */
#define I2C_CTRL_AUTOSN                         (0x1UL << 4)        /* Automatic STOP on NACK               */
#define I2C_CTRL_AUTOSN_SHIFT                   4                   /* Shift value for I2C_AUTOSN           */
#define I2C_CTRL_AUTOSN_MASK                    0x10UL              /* Bit mask for I2C_AUTOSN              */
#define I2C_CTRL_AUTOSN_DEFAULT                 (0x00000000UL << 4) /* Shifted mode DEFAULT for I2C_CTRL    */
#define I2C_CTRL_ARBDIS                         (0x1UL << 5)        /* Arbitration Disable                  */
#define I2C_CTRL_ARBDIS_SHIFT                   5                   /* Shift value for I2C_ARBDIS           */
#define I2C_CTRL_ARBDIS_MASK                    0x20UL              /* Bit mask for I2C_ARBDIS              */
#define I2C_CTRL_ARBDIS_DEFAULT                 (0x00000000UL << 5) /* Shifted mode DEFAULT for I2C_CTRL    */
#define I2C_CTRL_GCAMEN                         (0x1UL << 6)        /* General Call Address Match Enable    */
#define I2C_CTRL_GCAMEN_SHIFT                   6                   /* Shift value for I2C_GCAMEN           */
#define I2C_CTRL_GCAMEN_MASK                    0x40UL              /* Bit mask for I2C_GCAMEN              */
#define I2C_CTRL_GCAMEN_DEFAULT                 (0x00000000UL << 6) /* Shifted mode DEFAULT for I2C_CTRL    */
#define I2C_CTRL_CLHR_SHIFT                     8                   /* Shift value for I2C_CLHR             */
#define I2C_CTRL_CLHR_MASK                      0x300UL             /* Bit mask for I2C_CLHR                */
#define I2C_CTRL_CLHR_DEFAULT                   (0x00000000UL << 8) /* Shifted mode DEFAULT for I2C_CTRL    */
#define I2C_CTRL_CLHR_STANDARD                  (0x00000000UL << 8) /* Shifted mode STANDARD for I2C_CTRL   */
#define I2C_CTRL_CLHR_ASYMMETRIC                (0x00000001UL << 8) /* Shifted mode ASYMMETRIC for I2C_CTRL */
#define I2C_CTRL_CLHR_FAST                      (0x00000002UL << 8) /* Shifted mode FAST for I2C_CTRL       */
#define I2C_CTRL_BITO_SHIFT                     12                  /* Shift value for I2C_BITO             */
#define I2C_CTRL_BITO_MASK                      0x3000UL            /* Bit mask for I2C_BITO                */
#define I2C_CTRL_BITO_DEFAULT                   (0x00000000UL << 12)/* Shifted mode DEFAULT for I2C_CTRL    */
#define I2C_CTRL_BITO_OFF                       (0x00000000UL << 12)/* Shifted mode OFF for I2C_CTRL        */
#define I2C_CTRL_BITO_40PCC                     (0x00000001UL << 12)/* Shifted mode 40PCC for I2C_CTRL      */
#define I2C_CTRL_BITO_80PCC                     (0x00000002UL << 12)/* Shifted mode 80PCC for I2C_CTRL      */
#define I2C_CTRL_BITO_160PCC                    (0x00000003UL << 12)/* Shifted mode 160PCC for I2C_CTRL     */
#define I2C_CTRL_GIBITO                         (0x1UL << 15)       /* Go Idle on Bus Idle Timeout          */
#define I2C_CTRL_GIBITO_SHIFT                   15                  /* Shift value for I2C_GIBITO           */
#define I2C_CTRL_GIBITO_MASK                    0x8000UL            /* Bit mask for I2C_GIBITO              */
#define I2C_CTRL_GIBITO_DEFAULT                 (0x00000000UL << 15)/* Shifted mode DEFAULT for I2C_CTRL    */
#define I2C_CTRL_CLTO_SHIFT                     16                  /* Shift value for I2C_CLTO             */
#define I2C_CTRL_CLTO_MASK                      0x70000UL           /* Bit mask for I2C_CLTO                */
#define I2C_CTRL_CLTO_DEFAULT                   (0x00000000UL << 16)/* Shifted mode DEFAULT for I2C_CTRL    */
#define I2C_CTRL_CLTO_OFF                       (0x00000000UL << 16)/* Shifted mode OFF for I2C_CTRL        */
#define I2C_CTRL_CLTO_40PCC                     (0x00000001UL << 16)/* Shifted mode 40PCC for I2C_CTRL      */
#define I2C_CTRL_CLTO_80PCC                     (0x00000002UL << 16)/* Shifted mode 80PCC for I2C_CTRL      */
#define I2C_CTRL_CLTO_160PCC                    (0x00000003UL << 16)/* Shifted mode 160PCC for I2C_CTRL     */
#define I2C_CTRL_CLTO_320PPC                    (0x00000004UL << 16)/* Shifted mode 320PPC for I2C_CTRL     */
#define I2C_CTRL_CLTO_1024PPC                   (0x00000005UL << 16)/* Shifted mode 1024PPC for I2C_CTRL    */

/* Bit fields for I2C CMD */
#define I2C_CMD_RESETVALUE                      0x00000000UL        /* Default value for I2C_CMD            */
#define I2C_CMD_MASK                            0x000000FFUL        /* Mask for I2C_CMD                     */
#define I2C_CMD_START                           (0x1UL << 0)        /* Send start condition                 */
#define I2C_CMD_START_SHIFT                     0                   /* Shift value for I2C_START            */
#define I2C_CMD_START_MASK                      0x1UL               /* Bit mask for I2C_START               */
#define I2C_CMD_START_DEFAULT                   (0x00000000UL << 0) /* Shifted mode DEFAULT for I2C_CMD     */
#define I2C_CMD_STOP                            (0x1UL << 1)        /* Send stop condition                  */
#define I2C_CMD_STOP_SHIFT                      1                   /* Shift value for I2C_STOP             */
#define I2C_CMD_STOP_MASK                       0x2UL               /* Bit mask for I2C_STOP                */
#define I2C_CMD_STOP_DEFAULT                    (0x00000000UL << 1) /* Shifted mode DEFAULT for I2C_CMD     */
#define I2C_CMD_ACK                             (0x1UL << 2)        /* Send ACK                             */
#define I2C_CMD_ACK_SHIFT                       2                   /* Shift value for I2C_ACK              */
#define I2C_CMD_ACK_MASK                        0x4UL               /* Bit mask for I2C_ACK                 */
#define I2C_CMD_ACK_DEFAULT                     (0x00000000UL << 2) /* Shifted mode DEFAULT for I2C_CMD     */
#define I2C_CMD_NACK                            (0x1UL << 3)        /* Send NACK                            */
#define I2C_CMD_NACK_SHIFT                      3                   /* Shift value for I2C_NACK             */
#define I2C_CMD_NACK_MASK                       0x8UL               /* Bit mask for I2C_NACK                */
#define I2C_CMD_NACK_DEFAULT                    (0x00000000UL << 3) /* Shifted mode DEFAULT for I2C_CMD     */
#define I2C_CMD_CONT                            (0x1UL << 4)        /* Continue transmission                */
#define I2C_CMD_CONT_SHIFT                      4                   /* Shift value for I2C_CONT             */
#define I2C_CMD_CONT_MASK                       0x10UL              /* Bit mask for I2C_CONT                */
#define I2C_CMD_CONT_DEFAULT                    (0x00000000UL << 4) /* Shifted mode DEFAULT for I2C_CMD     */
#define I2C_CMD_ABORT                           (0x1UL << 5)        /* Abort transmission                   */
#define I2C_CMD_ABORT_SHIFT                     5                   /* Shift value for I2C_ABORT            */
#define I2C_CMD_ABORT_MASK                      0x20UL              /* Bit mask for I2C_ABORT               */
#define I2C_CMD_ABORT_DEFAULT                   (0x00000000UL << 5) /* Shifted mode DEFAULT for I2C_CMD     */
#define I2C_CMD_CLEARTX                         (0x1UL << 6)        /* Clear TX                             */
#define I2C_CMD_CLEARTX_SHIFT                   6                   /* Shift value for I2C_CLEARTX          */
#define I2C_CMD_CLEARTX_MASK                    0x40UL              /* Bit mask for I2C_CLEARTX             */
#define I2C_CMD_CLEARTX_DEFAULT                 (0x00000000UL << 6) /* Shifted mode DEFAULT for I2C_CMD     */
#define I2C_CMD_CLEARPC                         (0x1UL << 7)        /* Clear Pending Commands               */
#define I2C_CMD_CLEARPC_SHIFT                   7                   /* Shift value for I2C_CLEARPC          */
#define I2C_CMD_CLEARPC_MASK                    0x80UL              /* Bit mask for I2C_CLEARPC             */
#define I2C_CMD_CLEARPC_DEFAULT                 (0x00000000UL << 7) /* Shifted mode DEFAULT for I2C_CMD     */

/* Bit fields for I2C STATE */
#define I2C_STATE_RESETVALUE                    0x00000001UL        /* Default value for I2C_STATE          */
#define I2C_STATE_MASK                          0x000000FFUL        /* Mask for I2C_STATE                   */
#define I2C_STATE_BUSY                          (0x1UL << 0)        /* Bus Busy                             */
#define I2C_STATE_BUSY_SHIFT                    0                   /* Shift value for I2C_BUSY             */
#define I2C_STATE_BUSY_MASK                     0x1UL               /* Bit mask for I2C_BUSY                */
#define I2C_STATE_BUSY_DEFAULT                  (0x00000001UL << 0) /* Shifted mode DEFAULT for I2C_STATE   */
#define I2C_STATE_MASTER                        (0x1UL << 1)        /* Master                               */
#define I2C_STATE_MASTER_SHIFT                  1                   /* Shift value for I2C_MASTER           */
#define I2C_STATE_MASTER_MASK                   0x2UL               /* Bit mask for I2C_MASTER              */
#define I2C_STATE_MASTER_DEFAULT                (0x00000000UL << 1) /* Shifted mode DEFAULT for I2C_STATE   */
#define I2C_STATE_TRANSMITTER                   (0x1UL << 2)        /* Transmitter                          */
#define I2C_STATE_TRANSMITTER_SHIFT             2                   /* Shift value for I2C_TRANSMITTER      */
#define I2C_STATE_TRANSMITTER_MASK              0x4UL               /* Bit mask for I2C_TRANSMITTER         */
#define I2C_STATE_TRANSMITTER_DEFAULT           (0x00000000UL << 2) /* Shifted mode DEFAULT for I2C_STATE   */
#define I2C_STATE_NACKED                        (0x1UL << 3)        /* Nack Received                        */
#define I2C_STATE_NACKED_SHIFT                  3                   /* Shift value for I2C_NACKED           */
#define I2C_STATE_NACKED_MASK                   0x8UL               /* Bit mask for I2C_NACKED              */
#define I2C_STATE_NACKED_DEFAULT                (0x00000000UL << 3) /* Shifted mode DEFAULT for I2C_STATE   */
#define I2C_STATE_BUSHOLD                       (0x1UL << 4)        /* Bus Held                             */
#define I2C_STATE_BUSHOLD_SHIFT                 4                   /* Shift value for I2C_BUSHOLD          */
#define I2C_STATE_BUSHOLD_MASK                  0x10UL              /* Bit mask for I2C_BUSHOLD             */
#define I2C_STATE_BUSHOLD_DEFAULT               (0x00000000UL << 4) /* Shifted mode DEFAULT for I2C_STATE   */
#define I2C_STATE_STATE_SHIFT                   5                   /* Shift value for I2C_STATE            */
#define I2C_STATE_STATE_MASK                    0xE0UL              /* Bit mask for I2C_STATE               */

#define I2C_STATE_STATE_DEFAULT                 (0x00000000UL << 5) /* Shifted mode DEFAULT for I2C_STATE   */
#define I2C_STATE_STATE_IDLE                    (0x00000000UL << 5) /* Shifted mode IDLE for I2C_STATE      */
#define I2C_STATE_STATE_WAIT                    (0x00000001UL << 5) /* Shifted mode WAIT for I2C_STATE      */
#define I2C_STATE_STATE_START                   (0x00000002UL << 5) /* Shifted mode START for I2C_STATE     */
#define I2C_STATE_STATE_ADDR                    (0x00000003UL << 5) /* Shifted mode ADDR for I2C_STATE      */
#define I2C_STATE_STATE_ADDRACK                 (0x00000004UL << 5) /* Shifted mode ADDRACK for I2C_STATE   */
#define I2C_STATE_STATE_DATA                    (0x00000005UL << 5) /* Shifted mode DATA for I2C_STATE      */
#define I2C_STATE_STATE_DATAACK                 (0x00000006UL << 5) /* Shifted mode DATAACK for I2C_STATE   */

/* Bit fields for I2C STATUS */
#define I2C_STATUS_RESETVALUE                   0x00000080UL        /* Default value for I2C_STATUS         */
#define I2C_STATUS_MASK                         0x000001FFUL        /* Mask for I2C_STATUS                  */
#define I2C_STATUS_PSTART                       (0x1UL << 0)        /* Pending START                        */
#define I2C_STATUS_PSTART_SHIFT                 0                   /* Shift value for I2C_PSTART           */
#define I2C_STATUS_PSTART_MASK                  0x1UL               /* Bit mask for I2C_PSTART              */
#define I2C_STATUS_PSTART_DEFAULT               (0x00000000UL << 0) /* Shifted mode DEFAULT for I2C_STATUS  */
#define I2C_STATUS_PSTOP                        (0x1UL << 1)        /* Pending STOP                         */
#define I2C_STATUS_PSTOP_SHIFT                  1                   /* Shift value for I2C_PSTOP            */
#define I2C_STATUS_PSTOP_MASK                   0x2UL               /* Bit mask for I2C_PSTOP               */
#define I2C_STATUS_PSTOP_DEFAULT                (0x00000000UL << 1) /* Shifted mode DEFAULT for I2C_STATUS  */
#define I2C_STATUS_PACK                         (0x1UL << 2)        /* Pending ACK                          */
#define I2C_STATUS_PACK_SHIFT                   2                   /* Shift value for I2C_PACK             */
#define I2C_STATUS_PACK_MASK                    0x4UL               /* Bit mask for I2C_PACK                */
#define I2C_STATUS_PACK_DEFAULT                 (0x00000000UL << 2) /* Shifted mode DEFAULT for I2C_STATUS  */
#define I2C_STATUS_PNACK                        (0x1UL << 3)        /* Pending NACK                         */
#define I2C_STATUS_PNACK_SHIFT                  3                   /* Shift value for I2C_PNACK            */
#define I2C_STATUS_PNACK_MASK                   0x8UL               /* Bit mask for I2C_PNACK               */
#define I2C_STATUS_PNACK_DEFAULT                (0x00000000UL << 3) /* Shifted mode DEFAULT for I2C_STATUS  */
#define I2C_STATUS_PCONT                        (0x1UL << 4)        /* Pending continue                     */
#define I2C_STATUS_PCONT_SHIFT                  4                   /* Shift value for I2C_PCONT            */
#define I2C_STATUS_PCONT_MASK                   0x10UL              /* Bit mask for I2C_PCONT               */
#define I2C_STATUS_PCONT_DEFAULT                (0x00000000UL << 4) /* Shifted mode DEFAULT for I2C_STATUS  */
#define I2C_STATUS_PABORT                       (0x1UL << 5)        /* Pending abort                        */
#define I2C_STATUS_PABORT_SHIFT                 5                   /* Shift value for I2C_PABORT           */
#define I2C_STATUS_PABORT_MASK                  0x20UL              /* Bit mask for I2C_PABORT              */
#define I2C_STATUS_PABORT_DEFAULT               (0x00000000UL << 5) /* Shifted mode DEFAULT for I2C_STATUS  */
#define I2C_STATUS_TXC                          (0x1UL << 6)        /* TX Complete                          */
#define I2C_STATUS_TXC_SHIFT                    6                   /* Shift value for I2C_TXC              */
#define I2C_STATUS_TXC_MASK                     0x40UL              /* Bit mask for I2C_TXC                 */
#define I2C_STATUS_TXC_DEFAULT                  (0x00000000UL << 6) /* Shifted mode DEFAULT for I2C_STATUS  */
#define I2C_STATUS_TXBL                         (0x1UL << 7)        /* TX Buffer Level                      */
#define I2C_STATUS_TXBL_SHIFT                   7                   /* Shift value for I2C_TXBL             */
#define I2C_STATUS_TXBL_MASK                    0x80UL              /* Bit mask for I2C_TXBL                */
#define I2C_STATUS_TXBL_DEFAULT                 (0x00000001UL << 7) /* Shifted mode DEFAULT for I2C_STATUS  */
#define I2C_STATUS_RXDATAV                      (0x1UL << 8)        /* RX Data Valid                        */
#define I2C_STATUS_RXDATAV_SHIFT                8                   /* Shift value for I2C_RXDATAV          */
#define I2C_STATUS_RXDATAV_MASK                 0x100UL             /* Bit mask for I2C_RXDATAV             */
#define I2C_STATUS_RXDATAV_DEFAULT              (0x00000000UL << 8) /* Shifted mode DEFAULT for I2C_STATUS  */

/* Bit fields for I2C CLKDIV */
#define I2C_CLKDIV_RESETVALUE                   0x00000000UL        /* Default value for I2C_CLKDIV         */
#define I2C_CLKDIV_MASK                         0x000001FFUL        /* Mask for I2C_CLKDIV                  */
#define I2C_CLKDIV_DIV_SHIFT                    0                   /* Shift value for I2C_DIV              */
#define I2C_CLKDIV_DIV_MASK                     0x1FFUL             /* Bit mask for I2C_DIV                 */
#define I2C_CLKDIV_DIV_DEFAULT                  (0x00000000UL << 0) /* Shifted mode DEFAULT for I2C_CLKDIV  */

/* Bit fields for I2C SADDR */
#define I2C_SADDR_RESETVALUE                    0x00000000UL        /* Default value for I2C_SADDR          */
#define I2C_SADDR_MASK                          0x000000FEUL        /* Mask for I2C_SADDR                   */
#define I2C_SADDR_ADDR_SHIFT                    1                   /* Shift value for I2C_ADDR             */
#define I2C_SADDR_ADDR_MASK                     0xFEUL              /* Bit mask for I2C_ADDR                */
#define I2C_SADDR_ADDR_DEFAULT                  (0x00000000UL << 1) /* Shifted mode DEFAULT for I2C_SADDR   */

/* Bit fields for I2C SADDRMASK */
#define I2C_SADDRMASK_RESETVALUE                0x00000000UL        /* Default value for I2C_SADDRMASK      */
#define I2C_SADDRMASK_MASK                      0x000000FEUL        /* Mask for I2C_SADDRMASK               */
#define I2C_SADDRMASK_MASK_SHIFT                1                   /* Shift value for I2C_MASK             */
#define I2C_SADDRMASK_MASK_MASK                 0xFEUL              /* Bit mask for I2C_MASK                */
#define I2C_SADDRMASK_MASK_DEFAULT              (0x00000000UL << 1) /* Shifted mode DEFAULT for I2C_SADDRMASK*/

/* Bit fields for I2C RXDATA */
#define I2C_RXDATA_RESETVALUE                   0x00000000UL        /* Default value for I2C_RXDATA         */
#define I2C_RXDATA_MASK                         0x000000FFUL        /* Mask for I2C_RXDATA                  */
#define I2C_RXDATA_RXDATA_SHIFT                 0                   /* Shift value for I2C_RXDATA           */
#define I2C_RXDATA_RXDATA_MASK                  0xFFUL              /* Bit mask for I2C_RXDATA              */
#define I2C_RXDATA_RXDATA_DEFAULT               (0x00000000UL << 0) /* Shifted mode DEFAULT for I2C_RXDATA  */

/* Bit fields for I2C RXDATAP */
#define I2C_RXDATAP_RESETVALUE                  0x00000000UL        /* Default value for I2C_RXDATAP        */
#define I2C_RXDATAP_MASK                        0x000000FFUL        /* Mask for I2C_RXDATAP                 */
#define I2C_RXDATAP_RXDATAP_SHIFT               0                   /* Shift value for I2C_RXDATAP          */
#define I2C_RXDATAP_RXDATAP_MASK                0xFFUL              /* Bit mask for I2C_RXDATAP             */
#define I2C_RXDATAP_RXDATAP_DEFAULT             (0x00000000UL << 0) /* Shifted mode DEFAULT for I2C_RXDATAP */

/* Bit fields for I2C TXDATA */
#define I2C_TXDATA_RESETVALUE                   0x00000000UL        /* Default value for I2C_TXDATA         */
#define I2C_TXDATA_MASK                         0x000000FFUL        /* Mask for I2C_TXDATA                  */
#define I2C_TXDATA_TXDATA_SHIFT                 0                   /* Shift value for I2C_TXDATA           */
#define I2C_TXDATA_TXDATA_MASK                  0xFFUL              /* Bit mask for I2C_TXDATA              */
#define I2C_TXDATA_TXDATA_DEFAULT               (0x00000000UL << 0) /* Shifted mode DEFAULT for I2C_TXDATA  */

/* Bit fields for I2C IF */
#define I2C_IF_RESETVALUE                       0x00000010UL        /* Default value for I2C_IF             */
#define I2C_IF_MASK                             0x0001FFFFUL        /* Mask for I2C_IF                      */
#define I2C_IF_START                            (0x1UL << 0)        /* START condition Interrupt Flag       */
#define I2C_IF_START_SHIFT                      0                   /* Shift value for I2C_START            */
#define I2C_IF_START_MASK                       0x1UL               /* Bit mask for I2C_START               */
#define I2C_IF_START_DEFAULT                    (0x00000000UL << 0) /* Shifted mode DEFAULT for I2C_IF      */
#define I2C_IF_RSTART                           (0x1UL << 1)        /* Repeated START condition Interrupt Flag */
#define I2C_IF_RSTART_SHIFT                     1                   /* Shift value for I2C_RSTART           */
#define I2C_IF_RSTART_MASK                      0x2UL               /* Bit mask for I2C_RSTART              */
#define I2C_IF_RSTART_DEFAULT                   (0x00000000UL << 1) /* Shifted mode DEFAULT for I2C_IF      */
#define I2C_IF_ADDR                             (0x1UL << 2)        /* Address Interrupt Flag               */
#define I2C_IF_ADDR_SHIFT                       2                   /* Shift value for I2C_ADDR             */
#define I2C_IF_ADDR_MASK                        0x4UL               /* Bit mask for I2C_ADDR                */
#define I2C_IF_ADDR_DEFAULT                     (0x00000000UL << 2) /* Shifted mode DEFAULT for I2C_IF      */
#define I2C_IF_TXC                              (0x1UL << 3)        /* Transfer Completed Interrupt Flag    */
#define I2C_IF_TXC_SHIFT                        3                   /* Shift value for I2C_TXC              */
#define I2C_IF_TXC_MASK                         0x8UL               /* Bit mask for I2C_TXC                 */
#define I2C_IF_TXC_DEFAULT                      (0x00000000UL << 3) /* Shifted mode DEFAULT for I2C_IF      */
#define I2C_IF_TXBL                             (0x1UL << 4)        /* Transmit Buffer Level Interrupt Flag */
#define I2C_IF_TXBL_SHIFT                       4                   /* Shift value for I2C_TXBL             */
#define I2C_IF_TXBL_MASK                        0x10UL              /* Bit mask for I2C_TXBL                */
#define I2C_IF_TXBL_DEFAULT                     (0x00000000UL << 4) /* Shifted mode DEFAULT for I2C_IF      */
#define I2C_IF_RXDATAV                          (0x1UL << 5)        /* Receive Data Valid Interrupt Flag    */
#define I2C_IF_RXDATAV_SHIFT                    5                   /* Shift value for I2C_RXDATAV          */
#define I2C_IF_RXDATAV_MASK                     0x20UL              /* Bit mask for I2C_RXDATAV             */
#define I2C_IF_RXDATAV_DEFAULT                  (0x00000000UL << 5) /* Shifted mode DEFAULT for I2C_IF      */
#define I2C_IF_ACK                              (0x1UL << 6)        /* Acknowledge Received Interrupt Flag  */
#define I2C_IF_ACK_SHIFT                        6                   /* Shift value for I2C_ACK              */
#define I2C_IF_ACK_MASK                         0x40UL              /* Bit mask for I2C_ACK                 */
#define I2C_IF_ACK_DEFAULT                      (0x00000000UL << 6) /* Shifted mode DEFAULT for I2C_IF      */
#define I2C_IF_NACK                             (0x1UL << 7)        /* Not Acknowledge Received Interrupt Flag */
#define I2C_IF_NACK_SHIFT                       7                   /* Shift value for I2C_NACK             */
#define I2C_IF_NACK_MASK                        0x80UL              /* Bit mask for I2C_NACK                */
#define I2C_IF_NACK_DEFAULT                     (0x00000000UL << 7) /* Shifted mode DEFAULT for I2C_IF      */
#define I2C_IF_MSTOP                            (0x1UL << 8)        /* Master STOP Condition Interrupt Flag */
#define I2C_IF_MSTOP_SHIFT                      8                   /* Shift value for I2C_MSTOP            */
#define I2C_IF_MSTOP_MASK                       0x100UL             /* Bit mask for I2C_MSTOP               */
#define I2C_IF_MSTOP_DEFAULT                    (0x00000000UL << 8) /* Shifted mode DEFAULT for I2C_IF      */
#define I2C_IF_ARBLOST                          (0x1UL << 9)        /* Arbitration Lost Interrupt Flag      */
#define I2C_IF_ARBLOST_SHIFT                    9                   /* Shift value for I2C_ARBLOST          */
#define I2C_IF_ARBLOST_MASK                     0x200UL             /* Bit mask for I2C_ARBLOST             */
#define I2C_IF_ARBLOST_DEFAULT                  (0x00000000UL << 9) /* Shifted mode DEFAULT for I2C_IF      */
#define I2C_IF_BUSERR                           (0x1UL << 10)       /* Bus Error Interrupt Flag             */
#define I2C_IF_BUSERR_SHIFT                     10                  /* Shift value for I2C_BUSERR           */
#define I2C_IF_BUSERR_MASK                      0x400UL             /* Bit mask for I2C_BUSERR              */
#define I2C_IF_BUSERR_DEFAULT                   (0x00000000UL << 10)/* Shifted mode DEFAULT for I2C_IF      */
#define I2C_IF_BUSHOLD                          (0x1UL << 11)       /* Bus Held Interrupt Flag              */
#define I2C_IF_BUSHOLD_SHIFT                    11                  /* Shift value for I2C_BUSHOLD          */
#define I2C_IF_BUSHOLD_MASK                     0x800UL             /* Bit mask for I2C_BUSHOLD             */
#define I2C_IF_BUSHOLD_DEFAULT                  (0x00000000UL << 11)/* Shifted mode DEFAULT for I2C_IF      */
#define I2C_IF_TXOF                             (0x1UL << 12)       /* Transmit Buffer Overflow Interrupt Flag */
#define I2C_IF_TXOF_SHIFT                       12                  /* Shift value for I2C_TXOF             */
#define I2C_IF_TXOF_MASK                        0x1000UL            /* Bit mask for I2C_TXOF                */
#define I2C_IF_TXOF_DEFAULT                     (0x00000000UL << 12)/* Shifted mode DEFAULT for I2C_IF      */
#define I2C_IF_RXUF                             (0x1UL << 13)       /* Receive Buffer Underflow Interrupt Flag */
#define I2C_IF_RXUF_SHIFT                       13                  /* Shift value for I2C_RXUF             */
#define I2C_IF_RXUF_MASK                        0x2000UL            /* Bit mask for I2C_RXUF                */
#define I2C_IF_RXUF_DEFAULT                     (0x00000000UL << 13)/* Shifted mode DEFAULT for I2C_IF      */
#define I2C_IF_BITO                             (0x1UL << 14)       /* Bus Idle Timeout Interrupt Flag      */
#define I2C_IF_BITO_SHIFT                        14                 /* Shift value for I2C_BITO             */
#define I2C_IF_BITO_MASK                         0x4000UL           /* Bit mask for I2C_BITO                */
#define I2C_IF_BITO_DEFAULT                     (0x00000000UL << 14)/* Shifted mode DEFAULT for I2C_IF      */
#define I2C_IF_CLTO                             (0x1UL << 15)       /* Clock Low Timeout Interrupt Flag     */
#define I2C_IF_CLTO_SHIFT                       15                  /* Shift value for I2C_CLTO             */
#define I2C_IF_CLTO_MASK                        0x8000UL            /* Bit mask for I2C_CLTO                */
#define I2C_IF_CLTO_DEFAULT                     (0x00000000UL << 15)/* Shifted mode DEFAULT for I2C_IF      */
#define I2C_IF_SSTOP                            (0x1UL << 16)       /* Slave STOP condition Interrupt Flag  */
#define I2C_IF_SSTOP_SHIFT                      16                  /* Shift value for I2C_SSTOP            */
#define I2C_IF_SSTOP_MASK                       0x10000UL           /* Bit mask for I2C_SSTOP               */
#define I2C_IF_SSTOP_DEFAULT                    (0x00000000UL << 16)/* Shifted mode DEFAULT for I2C_IF      */

/* Bit fields for I2C IFS */
#define I2C_IFS_RESETVALUE                      0x00000000UL        /* Default value for I2C_IFS            */
#define I2C_IFS_MASK                            0x0001FFCFUL        /* Mask for I2C_IFS                     */
#define I2C_IFS_START                           (0x1UL << 0)        /* Set START Interrupt Flag             */
#define I2C_IFS_START_SHIFT                     0                   /* Shift value for I2C_START            */
#define I2C_IFS_START_MASK                      0x1UL               /* Bit mask for I2C_START               */
#define I2C_IFS_START_DEFAULT                   (0x00000000UL << 0) /* Shifted mode DEFAULT for I2C_IFS     */
#define I2C_IFS_RSTART                          (0x1UL << 1)        /* Set Repeated START Interrupt Flag    */
#define I2C_IFS_RSTART_SHIFT                    1                   /* Shift value for I2C_RSTART           */
#define I2C_IFS_RSTART_MASK                     0x2UL               /* Bit mask for I2C_RSTART              */
#define I2C_IFS_RSTART_DEFAULT                  (0x00000000UL << 1) /* Shifted mode DEFAULT for I2C_IFS     */
#define I2C_IFS_ADDR                            (0x1UL << 2)        /* Set Address Interrupt Flag           */
#define I2C_IFS_ADDR_SHIFT                      2                   /* Shift value for I2C_ADDR             */
#define I2C_IFS_ADDR_MASK                       0x4UL               /* Bit mask for I2C_ADDR                */
#define I2C_IFS_ADDR_DEFAULT                    (0x00000000UL << 2) /* Shifted mode DEFAULT for I2C_IFS     */
#define I2C_IFS_TXC                             (0x1UL << 3)        /* Set Transfer Completed Interrupt Flag*/
#define I2C_IFS_TXC_SHIFT                       3                   /* Shift value for I2C_TXC              */
#define I2C_IFS_TXC_MASK                        0x8UL               /* Bit mask for I2C_TXC                 */
#define I2C_IFS_TXC_DEFAULT                     (0x00000000UL << 3) /* Shifted mode DEFAULT for I2C_IFS     */
#define I2C_IFS_ACK                             (0x1UL << 6)        /* Set Acknowledge Received Interrupt Flag */
#define I2C_IFS_ACK_SHIFT                       6                   /* Shift value for I2C_ACK              */
#define I2C_IFS_ACK_MASK                        0x40UL              /* Bit mask for I2C_ACK                 */
#define I2C_IFS_ACK_DEFAULT                     (0x00000000UL << 6) /* Shifted mode DEFAULT for I2C_IFS     */
#define I2C_IFS_NACK                            (0x1UL << 7)        /* Set Not Acknowledge Received Interrupt Flag */
#define I2C_IFS_NACK_SHIFT                      7                   /* Shift value for I2C_NACK             */
#define I2C_IFS_NACK_MASK                       0x80UL              /* Bit mask for I2C_NACK                */
#define I2C_IFS_NACK_DEFAULT                    (0x00000000UL << 7) /* Shifted mode DEFAULT for I2C_IFS     */
#define I2C_IFS_MSTOP                           (0x1UL << 8)        /* Set MSTOP Interrupt Flag             */
#define I2C_IFS_MSTOP_SHIFT                     8                   /* Shift value for I2C_MSTOP            */
#define I2C_IFS_MSTOP_MASK                      0x100UL             /* Bit mask for I2C_MSTOP               */
#define I2C_IFS_MSTOP_DEFAULT                   (0x00000000UL << 8) /* Shifted mode DEFAULT for I2C_IFS     */
#define I2C_IFS_ARBLOST                         (0x1UL << 9)        /* Set Arbitration Lost Interrupt Flag  */
#define I2C_IFS_ARBLOST_SHIFT                   9                   /* Shift value for I2C_ARBLOST          */
#define I2C_IFS_ARBLOST_MASK                    0x200UL             /* Bit mask for I2C_ARBLOST             */
#define I2C_IFS_ARBLOST_DEFAULT                 (0x00000000UL << 9) /* Shifted mode DEFAULT for I2C_IFS     */
#define I2C_IFS_BUSERR                          (0x1UL << 10)       /* Set Bus Error Interrupt Flag         */
#define I2C_IFS_BUSERR_SHIFT                    10                  /* Shift value for I2C_BUSERR           */
#define I2C_IFS_BUSERR_MASK                     0x400UL             /* Bit mask for I2C_BUSERR              */
#define I2C_IFS_BUSERR_DEFAULT                  (0x00000000UL << 10)/* Shifted mode DEFAULT for I2C_IFS     */
#define I2C_IFS_BUSHOLD                         (0x1UL << 11)       /* Set Bus Held Interrupt Flag          */
#define I2C_IFS_BUSHOLD_SHIFT                   11                  /* Shift value for I2C_BUSHOLD          */
#define I2C_IFS_BUSHOLD_MASK                    0x800UL             /* Bit mask for I2C_BUSHOLD             */
#define I2C_IFS_BUSHOLD_DEFAULT                 (0x00000000UL << 11)/* Shifted mode DEFAULT for I2C_IFS     */
#define I2C_IFS_TXOF                            (0x1UL << 12)       /* Set Transmit Buffer Overflow Interrupt Flag */
#define I2C_IFS_TXOF_SHIFT                      12                  /* Shift value for I2C_TXOF             */
#define I2C_IFS_TXOF_MASK                       0x1000UL            /* Bit mask for I2C_TXOF                */
#define I2C_IFS_TXOF_DEFAULT                    (0x00000000UL << 12)/* Shifted mode DEFAULT for I2C_IFS     */
#define I2C_IFS_RXUF                            (0x1UL << 13)       /* Set Receive Buffer Underflow Interrupt Flag */
#define I2C_IFS_RXUF_SHIFT                      13                  /* Shift value for I2C_RXUF             */
#define I2C_IFS_RXUF_MASK                       0x2000UL            /* Bit mask for I2C_RXUF                */
#define I2C_IFS_RXUF_DEFAULT                    (0x00000000UL << 13)/* Shifted mode DEFAULT for I2C_IFS     */
#define I2C_IFS_BITO                            (0x1UL << 14)       /* Set Bus Idle Timeout Interrupt Flag  */
#define I2C_IFS_BITO_SHIFT                      14                  /* Shift value for I2C_BITO             */
#define I2C_IFS_BITO_MASK                       0x4000UL            /* Bit mask for I2C_BITO                */
#define I2C_IFS_BITO_DEFAULT                    (0x00000000UL << 14)/* Shifted mode DEFAULT for I2C_IFS     */
#define I2C_IFS_CLTO                            (0x1UL << 15)       /* Set Clock Low Interrupt Flag         */
#define I2C_IFS_CLTO_SHIFT                      15                  /* Shift value for I2C_CLTO             */
#define I2C_IFS_CLTO_MASK                       0x8000UL            /* Bit mask for I2C_CLTO                */
#define I2C_IFS_CLTO_DEFAULT                    (0x00000000UL << 15)/* Shifted mode DEFAULT for I2C_IFS     */
#define I2C_IFS_SSTOP                           (0x1UL << 16)       /* Set SSTOP Interrupt Flag             */
#define I2C_IFS_SSTOP_SHIFT                     16                  /* Shift value for I2C_SSTOP            */
#define I2C_IFS_SSTOP_MASK                      0x10000UL           /* Bit mask for I2C_SSTOP */
#define I2C_IFS_SSTOP_DEFAULT                   (0x00000000UL << 16)/* Shifted mode DEFAULT for I2C_IFS     */

/* Bit fields for I2C IFC */
#define I2C_IFC_RESETVALUE                      0x00000000UL        /* Default value for I2C_IFC            */
#define I2C_IFC_MASK                            0x0001FFCFUL        /* Mask for I2C_IFC                     */
#define I2C_IFC_START                           (0x1UL << 0)        /* Clear START Interrupt Flag           */
#define I2C_IFC_START_SHIFT                     0                   /* Shift value for I2C_START            */
#define I2C_IFC_START_MASK                      0x1UL               /* Bit mask for I2C_START               */
#define I2C_IFC_START_DEFAULT                   (0x00000000UL << 0) /* Shifted mode DEFAULT for I2C_IFC     */
#define I2C_IFC_RSTART                          (0x1UL << 1)        /* Clear Repeated START Interrupt Flag  */
#define I2C_IFC_RSTART_SHIFT                    1                   /* Shift value for I2C_RSTART           */
#define I2C_IFC_RSTART_MASK                     0x2UL               /* Bit mask for I2C_RSTART              */
#define I2C_IFC_RSTART_DEFAULT                  (0x00000000UL << 1)/* Shifted mode DEFAULT for I2C_IFC      */
#define I2C_IFC_ADDR                            (0x1UL << 2)        /* Clear Address Interrupt Flag         */
#define I2C_IFC_ADDR_SHIFT                      2                   /* Shift value for I2C_ADDR             */
#define I2C_IFC_ADDR_MASK                       0x4UL               /* Bit mask for I2C_ADDR                */
#define I2C_IFC_ADDR_DEFAULT                    (0x00000000UL << 2) /* Shifted mode DEFAULT for I2C_IFC     */
#define I2C_IFC_TXC                             (0x1UL << 3)        /* Clear Transfer Completed Interrupt Flag */
#define I2C_IFC_TXC_SHIFT                       3                   /* Shift value for I2C_TXC              */
#define I2C_IFC_TXC_MASK                        0x8UL               /* Bit mask for I2C_TXC                 */
#define I2C_IFC_TXC_DEFAULT                     (0x00000000UL << 3) /* Shifted mode DEFAULT for I2C_IFC     */
#define I2C_IFC_ACK                             (0x1UL << 6)        /* Clear Acknowledge Received Interrupt Flag */
#define I2C_IFC_ACK_SHIFT                       6                   /* Shift value for I2C_ACK              */
#define I2C_IFC_ACK_MASK                        0x40UL              /* Bit mask for I2C_ACK                 */
#define I2C_IFC_ACK_DEFAULT                     (0x00000000UL << 6) /* Shifted mode DEFAULT for I2C_IFC     */
#define I2C_IFC_NACK                            (0x1UL << 7)        /* Clear Not Acknowledge Received Interrupt Flag */
#define I2C_IFC_NACK_SHIFT                      7                   /* Shift value for I2C_NACK             */
#define I2C_IFC_NACK_MASK                       0x80UL              /* Bit mask for I2C_NACK                */
#define I2C_IFC_NACK_DEFAULT                    (0x00000000UL << 7) /* Shifted mode DEFAULT for I2C_IFC     */
#define I2C_IFC_MSTOP                           (0x1UL << 8)        /* Clear MSTOP Interrupt Flag           */
#define I2C_IFC_MSTOP_SHIFT                     8                   /* Shift value for I2C_MSTOP            */
#define I2C_IFC_MSTOP_MASK                      0x100UL             /* Bit mask for I2C_MSTOP               */
#define I2C_IFC_MSTOP_DEFAULT                   (0x00000000UL << 8) /* Shifted mode DEFAULT for I2C_IFC     */
#define I2C_IFC_ARBLOST                         (0x1UL << 9)        /* Clear Arbitration Lost Interrupt Flag */
#define I2C_IFC_ARBLOST_SHIFT                   9                   /* Shift value for I2C_ARBLOST          */
#define I2C_IFC_ARBLOST_MASK                    0x200UL             /* Bit mask for I2C_ARBLOST             */
#define I2C_IFC_ARBLOST_DEFAULT                 (0x00000000UL << 9) /* Shifted mode DEFAULT for I2C_IFC     */
#define I2C_IFC_BUSERR                          (0x1UL << 10)       /* Clear Bus Error Interrupt Flag       */
#define I2C_IFC_BUSERR_SHIFT                    10                  /* Shift value for I2C_BUSERR           */
#define I2C_IFC_BUSERR_MASK                      0x400UL            /* Bit mask for I2C_BUSERR              */
#define I2C_IFC_BUSERR_DEFAULT                  (0x00000000UL << 10)/* Shifted mode DEFAULT for I2C_IFC     */
#define I2C_IFC_BUSHOLD                         (0x1UL << 11)       /* Clear Bus Held Interrupt Flag        */
#define I2C_IFC_BUSHOLD_SHIFT                   11                  /* Shift value for I2C_BUSHOLD          */
#define I2C_IFC_BUSHOLD_MASK                    0x800UL             /* Bit mask for I2C_BUSHOLD             */
#define I2C_IFC_BUSHOLD_DEFAULT                 (0x00000000UL << 11)/* Shifted mode DEFAULT for I2C_IFC     */
#define I2C_IFC_TXOF                            (0x1UL << 12)       /* Clear Transmit Buffer Overflow Interrupt Flag */
#define I2C_IFC_TXOF_SHIFT                      12                  /* Shift value for I2C_TXOF             */
#define I2C_IFC_TXOF_MASK                       0x1000UL            /* Bit mask for I2C_TXOF                */
#define I2C_IFC_TXOF_DEFAULT                    (0x00000000UL << 12)/* Shifted mode DEFAULT for I2C_IFC     */
#define I2C_IFC_RXUF                            (0x1UL << 13)       /* Clear Receive Buffer Underflow Interrupt Flag */
#define I2C_IFC_RXUF_SHIFT                      13                  /* Shift value for I2C_RXUF             */
#define I2C_IFC_RXUF_MASK                       0x2000UL            /* Bit mask for I2C_RXUF                */
#define I2C_IFC_RXUF_DEFAULT                    (0x00000000UL << 13)/* Shifted mode DEFAULT for I2C_IFC     */
#define I2C_IFC_BITO                            (0x1UL << 14)       /* Clear Bus Idle Timeout Interrupt Flag*/
#define I2C_IFC_BITO_SHIFT                      14                  /* Shift value for I2C_BITO             */
#define I2C_IFC_BITO_MASK                       0x4000UL            /* Bit mask for I2C_BITO                */
#define I2C_IFC_BITO_DEFAULT                    (0x00000000UL << 14)/* Shifted mode DEFAULT for I2C_IFC     */
#define I2C_IFC_CLTO                            (0x1UL << 15)       /* Clear Clock Low Interrupt Flag       */
#define I2C_IFC_CLTO_SHIFT                      15                  /* Shift value for I2C_CLTO             */
#define I2C_IFC_CLTO_MASK                       0x8000UL            /* Bit mask for I2C_CLTO                */
#define I2C_IFC_CLTO_DEFAULT                    (0x00000000UL << 15)/* Shifted mode DEFAULT for I2C_IFC     */
#define I2C_IFC_SSTOP                           (0x1UL << 16)       /* Clear SSTOP Interrupt Flag           */
#define I2C_IFC_SSTOP_SHIFT                     16                  /* Shift value for I2C_SSTOP            */
#define I2C_IFC_SSTOP_MASK                      0x10000UL           /* Bit mask for I2C_SSTOP               */
#define I2C_IFC_SSTOP_DEFAULT                   (0x00000000UL << 16)/* Shifted mode DEFAULT for I2C_IFC     */

/* Bit fields for I2C IEN */
#define I2C_IEN_RESETVALUE                      0x00000000UL        /* Default value for I2C_IEN            */
#define I2C_IEN_MASK                            0x0001FFFFUL        /* Mask for I2C_IEN                     */
#define I2C_IEN_START                           (0x1UL << 0)        /* START Condition Interrupt Enable     */
#define I2C_IEN_START_SHIFT                     0                   /* Shift value for I2C_START            */
#define I2C_IEN_START_MASK                      0x1UL               /* Bit mask for I2C_START               */
#define I2C_IEN_START_DEFAULT                   (0x00000000UL << 0) /* Shifted mode DEFAULT for I2C_IEN     */
#define I2C_IEN_RSTART                          (0x1UL << 1)        /* Repeated START condition Interrupt Enable */
#define I2C_IEN_RSTART_SHIFT                    1                   /* Shift value for I2C_RSTART           */
#define I2C_IEN_RSTART_MASK                     0x2UL               /* Bit mask for I2C_RSTART              */
#define I2C_IEN_RSTART_DEFAULT                  (0x00000000UL << 1) /* Shifted mode DEFAULT for I2C_IEN     */
#define I2C_IEN_ADDR                            (0x1UL << 2)        /* Address Interrupt Enable             */
#define I2C_IEN_ADDR_SHIFT                      2                   /* Shift value for I2C_ADDR             */
#define I2C_IEN_ADDR_MASK                       0x4UL               /* Bit mask for I2C_ADDR                */
#define I2C_IEN_ADDR_DEFAULT                    (0x00000000UL << 2) /* Shifted mode DEFAULT for I2C_IEN     */
#define I2C_IEN_TXC                             (0x1UL << 3)        /* Transfer Completed Interrupt Enable  */
#define I2C_IEN_TXC_SHIFT                       3                   /* Shift value for I2C_TXC              */
#define I2C_IEN_TXC_MASK                        0x8UL               /* Bit mask for I2C_TXC                 */
#define I2C_IEN_TXC_DEFAULT                     (0x00000000UL << 3) /* Shifted mode DEFAULT for I2C_IEN     */
#define I2C_IEN_TXBL                            (0x1UL << 4)        /* Transmit Buffer level Interrupt Enable */
#define I2C_IEN_TXBL_SHIFT                      4                   /* Shift value for I2C_TXBL             */
#define I2C_IEN_TXBL_MASK                       0x10UL              /* Bit mask for I2C_TXBL                */
#define I2C_IEN_TXBL_DEFAULT                    (0x00000000UL << 4) /* Shifted mode DEFAULT for I2C_IEN     */
#define I2C_IEN_RXDATAV                         (0x1UL << 5)        /* Receive Data Valid Interrupt Enable  */
#define I2C_IEN_RXDATAV_SHIFT                   5                   /* Shift value for I2C_RXDATAV          */
#define I2C_IEN_RXDATAV_MASK                    0x20UL              /* Bit mask for I2C_RXDATAV             */
#define I2C_IEN_RXDATAV_DEFAULT                 (0x00000000UL << 5) /* Shifted mode DEFAULT for I2C_IEN     */
#define I2C_IEN_ACK                             (0x1UL << 6)        /* Acknowledge Received Interrupt Enable */
#define I2C_IEN_ACK_SHIFT                       6                   /* Shift value for I2C_ACK              */
#define I2C_IEN_ACK_MASK                        0x40UL              /* Bit mask for I2C_ACK                 */
#define I2C_IEN_ACK_DEFAULT                     (0x00000000UL << 6) /* Shifted mode DEFAULT for I2C_IEN     */
#define I2C_IEN_NACK                            (0x1UL << 7)        /* Not Acknowledge Received Interrupt Enable */
#define I2C_IEN_NACK_SHIFT                      7                   /* Shift value for I2C_NACK             */
#define I2C_IEN_NACK_MASK                       0x80UL              /* Bit mask for I2C_NACK                */
#define I2C_IEN_NACK_DEFAULT                    (0x00000000UL << 7) /* Shifted mode DEFAULT for I2C_IEN     */
#define I2C_IEN_MSTOP                           (0x1UL << 8)        /* MSTOP Interrupt Enable               */
#define I2C_IEN_MSTOP_SHIFT                     8                   /* Shift value for I2C_MSTOP            */
#define I2C_IEN_MSTOP_MASK                      0x100UL             /* Bit mask for I2C_MSTOP               */
#define I2C_IEN_MSTOP_DEFAULT                   (0x00000000UL << 8) /* Shifted mode DEFAULT for I2C_IEN     */
#define I2C_IEN_ARBLOST                         (0x1UL << 9)        /* Arbitration Lost Interrupt Enable    */
#define I2C_IEN_ARBLOST_SHIFT                   9                   /* Shift value for I2C_ARBLOST          */
#define I2C_IEN_ARBLOST_MASK                    0x200UL             /* Bit mask for I2C_ARBLOST             */
#define I2C_IEN_ARBLOST_DEFAULT                 (0x00000000UL << 9) /* Shifted mode DEFAULT for I2C_IEN     */
#define I2C_IEN_BUSERR                          (0x1UL << 10)       /* Bus Error Interrupt Enable           */
#define I2C_IEN_BUSERR_SHIFT                    10                  /* Shift value for I2C_BUSERR           */
#define I2C_IEN_BUSERR_MASK                     0x400UL             /* Bit mask for I2C_BUSERR              */
#define I2C_IEN_BUSERR_DEFAULT                  0x00000000UL        /* Mode DEFAULT for I2C_IEN             */
#define I2C_IEN_BUSHOLD                         (0x1UL << 11)       /* Bus Held Interrupt Enable            */
#define I2C_IEN_BUSHOLD_SHIFT                   11                  /* Shift value for I2C_BUSHOLD          */
#define I2C_IEN_BUSHOLD_MASK                    0x800UL             /* Bit mask for I2C_BUSHOLD             */
#define I2C_IEN_BUSHOLD_DEFAULT                 (0x00000000UL << 11)/* Shifted mode DEFAULT for I2C_IEN     */
#define I2C_IEN_TXOF                            (0x1UL << 12)       /* Transmit Buffer Overflow Interrupt Enable */
#define I2C_IEN_TXOF_SHIFT                      12                  /* Shift value for I2C_TXOF             */
#define I2C_IEN_TXOF_MASK                       0x1000UL            /* Bit mask for I2C_TXOF                */
#define I2C_IEN_TXOF_DEFAULT                    (0x00000000UL << 12)/* Shifted mode DEFAULT for I2C_IEN     */
#define I2C_IEN_RXUF                            (0x1UL << 13)       /* Receive Buffer Underflow Interrupt Enable */
#define I2C_IEN_RXUF_SHIFT                      13                  /* Shift value for I2C_RXUF             */
#define I2C_IEN_RXUF_MASK                       0x2000UL            /* Bit mask for I2C_RXUF                */
#define I2C_IEN_RXUF_DEFAULT                    (0x00000000UL << 13)/* Shifted mode DEFAULT for I2C_IEN     */
#define I2C_IEN_BITO                            (0x1UL << 14)       /* Bus Idle Timeout Interrupt Enable    */
#define I2C_IEN_BITO_SHIFT                      14                  /* Shift value for I2C_BITO             */
#define I2C_IEN_BITO_MASK                       0x4000UL            /* Bit mask for I2C_BITO                */
#define I2C_IEN_BITO_DEFAULT                    (0x00000000UL << 14)/* Shifted mode DEFAULT for I2C_IEN     */
#define I2C_IEN_CLTO                            (0x1UL << 15)       /* Clock Low Interrupt Enable           */
#define I2C_IEN_CLTO_SHIFT                      15                  /* Shift value for I2C_CLTO             */
#define I2C_IEN_CLTO_MASK                       0x8000UL            /* Bit mask for I2C_CLTO                */
#define I2C_IEN_CLTO_DEFAULT                    (0x00000000UL << 15)/* Shifted mode DEFAULT for I2C_IEN     */
#define I2C_IEN_SSTOP                           (0x1UL << 16)       /* SSTOP Interrupt Enable               */
#define I2C_IEN_SSTOP_SHIFT                     16                  /* Shift value for I2C_SSTOP            */
#define I2C_IEN_SSTOP_MASK                      0x10000UL           /* Bit mask for I2C_SSTOP               */
#define I2C_IEN_SSTOP_DEFAULT                   (0x00000000UL << 16)/* Shifted mode DEFAULT for I2C_IEN     */

/* Bit fields for I2C ROUTE */
#define I2C_ROUTE_RESETVALUE                    0x00000000UL        /* Default value for I2C_ROUTE          */
#define I2C_ROUTE_MASK                          0x00000303UL        /* Mask for I2C_ROUTE                   */
#define I2C_ROUTE_SDAPEN                        (0x1UL << 0)        /* SDA Pin Enable                       */
#define I2C_ROUTE_SDAPEN_SHIFT                  0                   /* Shift value for I2C_SDAPEN           */
#define I2C_ROUTE_SDAPEN_MASK                   0x1UL               /* Bit mask for I2C_SDAPEN              */
#define I2C_ROUTE_SDAPEN_DEFAULT                (0x00000000UL << 0) /* Shifted mode DEFAULT for I2C_ROUTE   */
#define I2C_ROUTE_SCLPEN                        (0x1UL << 1)        /* SCL Pin Enable                       */
#define I2C_ROUTE_SCLPEN_SHIFT                  1                   /* Shift value for I2C_SCLPEN           */
#define I2C_ROUTE_SCLPEN_MASK                   0x2UL               /* Bit mask for I2C_SCLPEN              */
#define I2C_ROUTE_SCLPEN_DEFAULT                (0x00000000UL << 1) /* Shifted mode DEFAULT for I2C_ROUTE   */
#define I2C_ROUTE_LOCATION_SHIFT                8                   /* Shift value for I2C_LOCATION         */
#define I2C_ROUTE_LOCATION_MASK                 0x300UL             /* Bit mask for I2C_LOCATION            */
#define I2C_ROUTE_LOCATION_DEFAULT              (0x00000000UL << 8) /* Shifted mode DEFAULT for I2C_ROUTE   */
#define I2C_ROUTE_LOCATION_LOC0                 (0x00000000UL << 8) /* Shifted mode LOC0 for I2C_ROUTE      */
#define I2C_ROUTE_LOCATION_LOC1                 (0x00000001UL << 8) /* Shifted mode LOC1 for I2C_ROUTE      */
#define I2C_ROUTE_LOCATION_LOC2                 (0x00000002UL << 8) /* Shifted mode LOC2 for I2C_ROUTE      */
#define I2C_ROUTE_LOCATION_LOC3                 (0x00000003UL << 8) /* Shifted mode LOC3 for I2C_ROUTE      */
#define I2C_ROUTE_LOCATION_LOC4                 (0x00000004UL << 8) /* Shifted mode LOC4 for I2C_ROUTE      */
#define I2C_ROUTE_LOCATION_LOC5                 (0x00000005UL << 8) /* Shifted mode LOC5 for I2C_ROUTE      */
#define I2C_ROUTE_LOCATION_LOC6                 (0x00000006UL << 8) /* Shifted mode LOC6 for I2C_ROUTE      */
  


    
/*************************************************************************************************************
*                                            TYPE DEFINES                                                   *
*************************************************************************************************************/
typedef enum
{
    i2c0 = I2C0_BASE,
    i2c1 = I2C1_BASE,
} I2CTypedef;   
    
typedef enum
{
    CLTO_OFF = I2C_CTRL_CLTO_OFF,
    CLTO_40PPC = I2C_CTRL_CLTO_40PCC,
    CLTO_80PPC = I2C_CTRL_CLTO_80PCC,
    CLTO_160PPC = I2C_CTRL_CLTO_160PCC,
    CLTO_320PPC = I2C_CTRL_CLTO_320PPC,
    CLTO_1024PPC = I2C_CTRL_CLTO_1024PPC,
} I2CCLTOTypedef;   

typedef enum
{
    BITO_OFF = I2C_CTRL_BITO_OFF,
    BITO_40PPC = I2C_CTRL_BITO_40PCC,
    BITO_80PPC = I2C_CTRL_BITO_80PCC,
    BITO_160PPC = I2C_CTRL_BITO_160PCC,    
} I2CBITOTypedef;   

typedef enum
{
    CLHR_STANDARD = I2C_CTRL_CLHR_STANDARD,
    CLHR_ASYMMETRIC = I2C_CTRL_CLHR_ASYMMETRIC,
    CLHR_FAST = I2C_CTRL_CLHR_FAST,  
} I2CCLTHRTypedef;

typedef enum
{
    STATE_DEFAULT = I2C_STATE_STATE_DEFAULT,
    STATE_IDLE = I2C_STATE_STATE_IDLE, 
    STATE_WAIT = I2C_STATE_STATE_WAIT,
    STATE_START = I2C_STATE_STATE_START, 
    STATE_ADDR = I2C_STATE_STATE_ADDR,
    STATE_ADDRACK = I2C_STATE_STATE_ADDRACK, 
    STATE_DATA = I2C_STATE_STATE_DATA,
    STATE_DATAACK = I2C_STATE_STATE_DATAACK, 
} I2CStateTypedef;

typedef enum
{
    IF_START = I2C_IF_START,
    IF_RSTART = I2C_IF_RSTART,
    IF_ADDR = I2C_IF_ADDR,
    IF_TXC = I2C_IF_TXC,
    IF_TXBL = I2C_IF_TXBL,
    IF_RXDATAV = I2C_IF_RXDATAV,
    IF_ACK = I2C_IF_ACK,
    IF_NACK = I2C_IF_NACK,
    IF_MSTOP = I2C_IF_MSTOP,
    IF_ARBLOST = I2C_IF_ARBLOST,
    IF_BUSERR = I2C_IF_BUSERR,
    IF_BUSHOLD = I2C_IF_BUSHOLD,
    IF_TXOF = I2C_IF_TXOF,
    IF_RXUF = I2C_IF_RXUF,
    IF_BITO = I2C_IF_BITO,
    IF_CLTO = I2C_IF_CLTO,
    IF_SSTOP = I2C_IF_SSTOP,
    IF_ALL  = I2C_IF_MASK,
} I2CIntFlagTypedef;


typedef enum
{
    I2C_LOC0 = I2C_ROUTE_LOCATION_LOC0,
    I2C_LOC1 = I2C_ROUTE_LOCATION_LOC1, 
    I2C_LOC2 = I2C_ROUTE_LOCATION_LOC2,
    I2C_LOC3 = I2C_ROUTE_LOCATION_LOC3,
    I2C_LOC4 = I2C_ROUTE_LOCATION_LOC4, 
    I2C_LOC5 = I2C_ROUTE_LOCATION_LOC5,
    I2C_LOC6 = I2C_ROUTE_LOCATION_LOC6,   
} I2CLocationTypedef;

typedef enum
{
    MASTER = 0,
    SLAVE = 1, 
} I2CModeTypedef;

/*************************************************************************************************************
*                                             FUNCTION STATEMENT                                       *
*************************************************************************************************************/
I2CStateTypedef I2CStateGet (I2CTypedef x);
CPU_BOOL I2CBusholdStateGet (I2CTypedef x);
CPU_BOOL I2CNackedStateGet (I2CTypedef x);
CPU_BOOL I2CTransmitterStateGet (I2CTypedef x);
CPU_BOOL I2CMasterStateGet (I2CTypedef x);
CPU_BOOL I2CBusyStateGet (I2CTypedef x);
CPU_BOOL I2CRxdatavStatusGet (I2CTypedef x);
CPU_BOOL I2CTxblStatusGet (I2CTypedef x);
CPU_BOOL I2CTxcStatusGet (I2CTypedef x);
CPU_BOOL I2CPabortStatusGet (I2CTypedef x);
CPU_BOOL I2CPcontStatusGet (I2CTypedef x);
CPU_BOOL I2CPnackStatusGet (I2CTypedef x);
CPU_BOOL I2CPackStatusGet (I2CTypedef x);
CPU_BOOL I2CPstopStatusGet (I2CTypedef x);
CPU_BOOL I2CPstopStartGet (I2CTypedef x);
CPU_INT16U I2CClkdivGet (I2CTypedef x);
CPU_INT8U I2CSaddrGet (I2CTypedef x);
CPU_INT8U I2CSaddrMaskGet (I2CTypedef x);
CPU_INT8U I2CRxdataGet (I2CTypedef x);
CPU_INT8U I2CRxdatapGet (I2CTypedef x);
I2CLocationTypedef I2CRouteGet (I2CTypedef x);


/*************************************************************************************************************
*                                           INLINE  FUNCTION STATEMENT                                       *
*************************************************************************************************************/
static inline void I2CCLTOSet (I2CTypedef x, I2CCLTOTypedef clto)
{
    I2CRegTypeDef *i2c;
    i2c = (I2CRegTypeDef *)x;
    i2c->CTRL &= ~clto;
    i2c->CTRL |= clto;
}

static inline void I2CGIBITOEnable (I2CTypedef x)
{
    I2CRegTypeDef *i2c;
    i2c = (I2CRegTypeDef *)x;
    
    i2c->CTRL |= I2C_CTRL_GIBITO_MASK;
}

static inline void I2CGIBITODisable (I2CTypedef x)
{
    I2CRegTypeDef *i2c;
    i2c = (I2CRegTypeDef *)x;
    
    i2c->CTRL &= ~I2C_CTRL_GIBITO_MASK;
}

static inline void I2CBITOSet (I2CTypedef x, I2CBITOTypedef bito)
{
    I2CRegTypeDef *i2c;
    i2c = (I2CRegTypeDef *)x;
    
    i2c->CTRL &= ~bito;
    i2c->CTRL |= bito;
}
static inline void I2CLHRSet (I2CTypedef x, I2CCLTHRTypedef clhr)
{
    I2CRegTypeDef *i2c;
    i2c = (I2CRegTypeDef *)x;
    
    i2c->CTRL &= ~I2C_CTRL_CLHR_MASK;
    i2c->CTRL |= clhr;
}

static inline void I2CGCAMENEnable (I2CTypedef x)
{
    I2CRegTypeDef *i2c;
    i2c = (I2CRegTypeDef *)x;
    
    i2c->CTRL |= I2C_CTRL_GCAMEN_MASK;
}

static inline void I2CGCAMENDisable (I2CTypedef x)
{
    I2CRegTypeDef *i2c;
    i2c = (I2CRegTypeDef *)x;
    
    i2c->CTRL &= ~I2C_CTRL_GCAMEN_MASK;
}

static inline void I2CARBDISEnable (I2CTypedef x)
{
    I2CRegTypeDef *i2c;
    i2c = (I2CRegTypeDef *)x;
    
    i2c->CTRL |= I2C_CTRL_ARBDIS_MASK;
}

static inline void I2CARBDISDisable (I2CTypedef x)
{
    I2CRegTypeDef *i2c;
    i2c = (I2CRegTypeDef *)x;
    
    i2c->CTRL &= ~I2C_CTRL_ARBDIS_MASK;
}

static inline void I2CAUTOSNEnable (I2CTypedef x)
{
    I2CRegTypeDef *i2c;
    i2c = (I2CRegTypeDef *)x;
    
    i2c->CTRL |= I2C_CTRL_AUTOSN_MASK;
}

static inline void I2CAUTOSNDisable (I2CTypedef x)
{
    I2CRegTypeDef *i2c;
    i2c = (I2CRegTypeDef *)x;
    
    i2c->CTRL &= ~I2C_CTRL_AUTOSN_MASK;
}

static inline void I2CAUTOSEEnable (I2CTypedef x)
{
    I2CRegTypeDef *i2c;
    i2c = (I2CRegTypeDef *)x;
    
    i2c->CTRL |= I2C_CTRL_AUTOSE_MASK;
}

static inline void I2CAUTOSEDisable (I2CTypedef x)
{
    I2CRegTypeDef *i2c;
    i2c = (I2CRegTypeDef *)x;
    
    i2c->CTRL &= ~I2C_CTRL_AUTOSE_MASK;
}

static inline void I2CAUTOACKEnable (I2CTypedef x)
{
    I2CRegTypeDef *i2c;
    i2c = (I2CRegTypeDef *)x;
    
    i2c->CTRL |= I2C_CTRL_AUTOACK_MASK;
}

static inline void I2CAUTOACKDisable (I2CTypedef x)
{
    I2CRegTypeDef *i2c;
    i2c = (I2CRegTypeDef *)x;
    
    i2c->CTRL &= ~I2C_CTRL_AUTOACK_MASK;
}

static inline void I2CSLAVEEnable (I2CTypedef x)
{
    I2CRegTypeDef *i2c;
    i2c = (I2CRegTypeDef *)x;
    
    i2c->CTRL |= I2C_CTRL_SLAVE_MASK;
}

static inline void I2CSLAVEDisable (I2CTypedef x)
{
    I2CRegTypeDef *i2c;
    i2c = (I2CRegTypeDef *)x;
    
    i2c->CTRL &= ~I2C_CTRL_SLAVE_MASK;
}

static inline void I2CEnable (I2CTypedef x)
{
    I2CRegTypeDef *i2c;
    i2c = (I2CRegTypeDef *)x;
    
    i2c->CTRL |= I2C_CTRL_EN_MASK;
}

static inline void I2CDisable (I2CTypedef x)
{
    I2CRegTypeDef *i2c;
    i2c = (I2CRegTypeDef *)x;
    
    i2c->CTRL &= ~I2C_CTRL_EN_MASK;
}

static inline void I2CSendCmd (I2CTypedef x, CPU_INT8U cmd)
{
    I2CRegTypeDef *i2c;
    i2c = (I2CRegTypeDef *)x;
    
    i2c->CMD = cmd;
}

static inline void I2CCmdCLEARPC (I2CTypedef x)
{
    I2CRegTypeDef *i2c;
    i2c = (I2CRegTypeDef *)x;
    
    i2c->CMD = I2C_CMD_CLEARPC_MASK;
}

static inline void I2CCmdCLEARTX (I2CTypedef x)
{
    I2CRegTypeDef *i2c;
    i2c = (I2CRegTypeDef *)x;
    
    i2c->CMD = I2C_CMD_CLEARTX_MASK;
}

static inline void I2CCmdABORT (I2CTypedef x)
{
    I2CRegTypeDef *i2c;
    i2c = (I2CRegTypeDef *)x;
    
    i2c->CMD = I2C_CMD_ABORT_MASK;
}

static inline void I2CCmdCONT (I2CTypedef x)
{
    I2CRegTypeDef *i2c;
    i2c = (I2CRegTypeDef *)x;
    
    i2c->CMD = I2C_CMD_CONT_MASK;
}

static inline void I2CCmdNACK (I2CTypedef x)
{
    I2CRegTypeDef *i2c;
    i2c = (I2CRegTypeDef *)x;
    
    i2c->CMD = I2C_CMD_NACK_MASK;
}

static inline void I2CCmdACK (I2CTypedef x)
{
    I2CRegTypeDef *i2c;
    i2c = (I2CRegTypeDef *)x;
    
    i2c->CMD = I2C_CMD_ACK_MASK;
}

static inline void I2CCmdSTOP (I2CTypedef x)
{
    I2CRegTypeDef *i2c;
    i2c = (I2CRegTypeDef *)x;
    
    i2c->CMD = I2C_CMD_STOP_MASK;
}

static inline void I2CCmdSTART (I2CTypedef x)
{
    I2CRegTypeDef *i2c;
    i2c = (I2CRegTypeDef *)x;
    
    i2c->CMD = I2C_CMD_START_MASK;
}

static inline void I2CClkdivSet (I2CTypedef x, CPU_INT16U div)
{
    I2CRegTypeDef *i2c;
    
    i2c = (I2CRegTypeDef *)x;
    
    i2c->CLKDIV = (div << I2C_CLKDIV_DIV_SHIFT);
}


static inline void I2CSaddrSet (I2CTypedef x, CPU_INT8U addr)
{
    I2CRegTypeDef *i2c;
    
    i2c = (I2CRegTypeDef *)x;
    
    i2c->SADDR = (addr << I2C_SADDR_ADDR_SHIFT);
}

static inline void I2CSaddrMaskSet (I2CTypedef x, CPU_INT8U mask)
{
    I2CRegTypeDef *i2c;
    
    i2c = (I2CRegTypeDef *)x;
    
    i2c->SADDRMASK = (mask << I2C_SADDRMASK_MASK_SHIFT);
}

static inline void I2CTxdata (I2CTypedef x, CPU_INT8U data)
{
    I2CRegTypeDef *i2c;
    i2c = (I2CRegTypeDef *)x;
    
    i2c->TXDATA = data;
}

static inline I2CIntFlagTypedef I2CIFGet(I2CTypedef x)
{
    I2CRegTypeDef *i2c;
    I2CIntFlagTypedef ret;
    
    i2c = (I2CRegTypeDef *)x;

    ret = (I2CIntFlagTypedef)i2c->IF;
    
    return ret;
}

static inline void I2CIFSet(I2CTypedef x, I2CIntFlagTypedef type)
{
    I2CRegTypeDef *i2c;

    i2c = (I2CRegTypeDef *)x;
    
    i2c->IFS |= type;
}    

static inline void I2CIFClear(I2CTypedef x, I2CIntFlagTypedef type)
{
    I2CRegTypeDef *i2c;

    i2c = (I2CRegTypeDef *)x;
    
    i2c->IFC |= type;
}   

static inline void I2CIntEnable (I2CTypedef x, I2CIntFlagTypedef type)
{
    I2CRegTypeDef *i2c;

    i2c = (I2CRegTypeDef *)x;
    
    i2c->IEN |= type;
}   

static inline void I2CIntDisable (I2CTypedef x, I2CIntFlagTypedef type)
{
    I2CRegTypeDef *i2c;

    i2c = (I2CRegTypeDef *)x;
    
    i2c->IEN &= ~type;
} 

static inline void I2CRouteSet (I2CTypedef x, I2CLocationTypedef route)
{
    I2CRegTypeDef *i2c;

    i2c = (I2CRegTypeDef *)x;
    
    i2c->ROUTE |= route;
} 

static inline void I2CRouteSCLPinEnable(I2CTypedef x)
{
    I2CRegTypeDef *i2c;
    
    i2c = (I2CRegTypeDef *)x;
    
    i2c->ROUTE |= I2C_ROUTE_SCLPEN;
} 

static inline void I2CRouteSCLPinDisable(I2CTypedef x)
{
    I2CRegTypeDef *i2c;
    
    i2c = (I2CRegTypeDef *)x;
    
    i2c->ROUTE &= ~I2C_ROUTE_SCLPEN;
} 

static inline void I2CRouteSDAPinEnable(I2CTypedef x)
{
    I2CRegTypeDef *i2c;
    
    i2c = (I2CRegTypeDef *)x;
    
    i2c->ROUTE |= I2C_ROUTE_SDAPEN;
} 

static inline void I2CRouteSDAPinDisable(I2CTypedef x)
{
    I2CRegTypeDef *i2c;
    
    i2c = (I2CRegTypeDef *)x;
    
    i2c->ROUTE &= ~I2C_ROUTE_SDAPEN;
} 

/*************************************************************************************************************
*                                               MODULE END                                                   *
*************************************************************************************************************/     
#ifdef __cplusplus
}
#endif

#endif 
    