/*************************************************************************************************************
*                                                  MODULE                                                    *
*************************************************************************************************************/
#ifndef MSC_H
#define MSC_H

#ifdef __cplusplus
extern "C" {
#endif
    

/*************************************************************************************************************
*                                                 DEFINES                                                    *
*************************************************************************************************************/
#define MSC                                     ((MSCRegTypeDef *)MSC_BASE)
    
/* Bit fields for MSC CTRL */
#define MSC_CTRL_RESETVALUE                     0x00000001UL    /* Default value for MSC_CTRL               */
#define MSC_CTRL_MASK                           0x00000001UL    /* Mask for MSC_CTRL                        */
#define MSC_CTRL_BUSFAULT_SHIFT                 0               /* Shift value for MSC_CTRL_BUSFAULT        */
#define MSC_CTRL_BUSFAULT_MASK                  (0x1UL << 0)    /* Bit mask for MSC_CTRL_BUSFAULT           */
#define MSC_CTRL_BUSFAULT_DEFAULT               (0x1UL << 0)    /* Mode DEFAULT for MSC_CTRL_BUSFAULT       */
#define MSC_CTRL_BUSFAULT_GENERATE              (0x0UL << 0)    /* Mode GENERATE for MSC_CTRL_BUSFAULT      */
#define MSC_CTRL_BUSFAULT_IGNORE                (0x1UL << 0)    /* Mode IGNORE for MSC_CTRL_BUSFAULT        */
    
/* Bit fields for MSC READCTRL */
#define MSC_READCTRL_RESETVALUE                 0x00000001UL    /* Default value for MSC_READCTRL           */
#define MSC_READCTRL_MASK                       0x00000007UL    /* Mask for MSC_READCTRL                    */
#define MSC_READCTRL_MODE_SHIFT                 0               /* Shift value for MSC_READCTRL_MODE        */
#define MSC_READCTRL_MODE_MASK                  (0x7UL << 0)    /* Bit mask for MSC_READCTRL_MODE           */
#define MSC_READCTRL_MODE_DEFAULT               (0x1UL << 0)    /* Mode DEFAULT for MSC_READCTRL_MODE       */
#define MSC_READCTRL_MODE_WS0                   (0x0UL << 0)    /* Mode WS0 for MSC_READCTRL_MODE           */
#define MSC_READCTRL_MODE_WS1                   (0x1UL << 0)    /* Mode WS1 for MSC_READCTRL_MODE           */
#define MSC_READCTRL_MODE_WS0SCBTP              (0x2UL << 0)    /* Mode WS0SCBTP for MSC_READCTRL_MODE      */
#define MSC_READCTRL_MODE_WS1SCBTP              (0x3UL << 0)    /* Mode WS1SCBTP for MSC_READCTRL_MODE      */   
    
/* Bit fields for MSC WRITECTRL */
#define MSC_WRITECTRL_RESETVALUE                0x00000000UL    /* Default value for MSC_WRITECTRL          */
#define MSC_WRITECTRL_MASK                      0x00000003UL    /* Mask for MSC_WRITECTRL                   */
#define MSC_WRITECTRL_WREN_SHIFT                0               /* Shift value for MSC_WREN                 */
#define MSC_WRITECTRL_WREN_MASK                 (0x1UL << 0)    /* Bit mask for MSC_WRITECTRL_WREN          */
#define MSC_WRITECTRL_WREN_DEFAULT              (0x0UL << 0)    /* Mode DEFAULT for MSC_WRITECTRL_WREN      */
#define MSC_WRITECTRL_WREN                      (0x1UL << 0)    /* Enable Write/Erase Controller            */
#define MSC_WRITECTRL_IRQERASEABORT_SHIFT       1               /* Shift value for MSC_IRQERASEABORT        */
#define MSC_WRITECTRL_IRQERASEABORT_MASK        (0x1UL << 0)    /* Bit mask for MSC_WRITECTRL_IRQERASEABORT */
#define MSC_WRITECTRL_IRQERASEABORT_DEFAULT     (0x0UL << 0)    /* Mode DEFAULT for MSC_WRITECTRL_IRQERASEABORT */
#define MSC_WRITECTRL_IRQERASEABORT             (0x1UL << 1)    /* Abort Page Erase on Interrupt            */
    
/* Bit fields for MSC WRITECMD */
#define MSC_WRITECMD_RESETVALUE                 0x00000000UL    /* Default value for MSC_WRITECMD           */
#define MSC_WRITECMD_MASK                       0x0000001FUL    /* Mask for MSC_WRITECMD                    */
#define MSC_WRITECMD_LADDRIM_SHIFT              0               /* Shift value for MSC_WRITECMD_LADDRIM     */
#define MSC_WRITECMD_LADDRIM_MASK               (0x1UL << 0)    /* Bit mask for MSC_WRITECMD_LADDRIM        */
#define MSC_WRITECMD_LADDRIM_DEFAULT            (0x0UL << 0)    /* Mode DEFAULT for MSC_WRITECMD_LADDRIM    */
#define MSC_WRITECMD_LADDRIM                    (0x1UL << 0)    /* Load MSC_ADDRB into ADDR                 */
#define MSC_WRITECMD_ERASEPAGE_SHIFT            1               /* Shift value for MSC_WRITECMD_ERASEPAGE   */
#define MSC_WRITECMD_ERASEPAGE_MASK             (0x1UL << 1)    /* Bit mask for MSC_WRITECMD_ERASEPAGE      */
#define MSC_WRITECMD_ERASEPAGE_DEFAULT          (0x0UL << 0)    /* Mode DEFAULT for MSC_WRITECMD_ERASEPAGE  */
#define MSC_WRITECMD_ERASEPAGE                  (0x1UL << 1)    /* Erase Page                               */
#define MSC_WRITECMD_WRITEEND_SHIFT             2               /* Shift value for MSC_WRITECMD_WRITEEND    */
#define MSC_WRITECMD_WRITEEND_MASK              (0x1UL << 2)    /* Bit mask for MSC_WRITECMD_WRITEEND       */
#define MSC_WRITECMD_WRITEEND_DEFAULT           (0x0UL << 2)    /* Mode DEFAULT for MSC_WRITECMD_WRITEEND   */
#define MSC_WRITECMD_WRITEEND                   (0x1UL << 2)    /* End Write Mode                           */
#define MSC_WRITECMD_WRITEONCE_SHIFT            3               /* Shift value for MSC_WRITECMD_WRITEONCE   */
#define MSC_WRITECMD_WRITEONCE_MASK             (0x1UL << 3)    /* Bit mask for MSC_WRITECMD_WRITEONCE      */
#define MSC_WRITECMD_WRITEONCE_DEFAULT          (0x0UL << 3)    /* Mode DEFAULT for MSC_WRITECMD_WRITEONCE  */
#define MSC_WRITECMD_WRITEONCE                  (0x1UL << 3)    /* Word Write-Once Trigger                  */
#define MSC_WRITECMD_WRITETRIG_SHIFT            4               /* Shift value for MSC_WRITECMD_WRITETRIG   */
#define MSC_WRITECMD_WRITETRIG_MASK             (0x1UL << 4)    /* Bit mask for MSC_WRITECMD_WRITETRIG      */
#define MSC_WRITECMD_WRITETRIG_DEFAULT          (0x0UL << 4)    /* Mode DEFAULT for MSC_WRITECMD_WRITETRIG  */
#define MSC_WRITECMD_WRITETRIG                  (0x1UL << 4)    /* Word Write Sequence Trigger              */

/* Bit fields for MSC ADDRB */
#define MSC_ADDRB_RESETVALUE                    0x00000000UL    /* Default value for MSC_ADDRB              */
#define MSC_ADDRB_MASK                          0xFFFFFFFFUL    /* Mask for MSC_ADDRB                       */
#define MSC_ADDRB_ADDRB_SHIFT                   0               /* Shift value for MSC_ADDRB_ADDRB          */
#define MSC_ADDRB_ADDRB_MASK                    0xFFFFFFFFUL    /* Bit mask for MSC_ADDRB_ADDRB             */
#define MSC_ADDRB_ADDRB_DEFAULT                 0x00000000UL    /* Mode DEFAULT for MSC_ADDRB_ADDRB         */

/* Bit fields for MSC WDATA */
#define MSC_WDATA_RESETVALUE                    0x00000000UL    /* Default value for MSC_WDATA              */
#define MSC_WDATA_MASK                          0xFFFFFFFFUL    /* Mask for MSC_WDATA                       */
#define MSC_WDATA_WDATA_SHIFT                   0               /* Shift value for MSC_WDATA_WDATA          */
#define MSC_WDATA_WDATA_MASK                    0xFFFFFFFFUL    /* Bit mask for MSC_WDATA_WDATA             */
#define MSC_WDATA_WDATA_DEFAULT                 0x00000000UL    /* Mode DEFAULT for MSC_WDATA_WDATA         */

/* Bit fields for MSC STATUS */
#define MSC_STATUS_RESETVALUE                   0x00000008UL    /* Default value for MSC_STATUS             */
#define MSC_STATUS_MASK                         0x0000003FUL    /* Mask for MSC_STATUS                      */
#define MSC_STATUS_BUSY_SHIFT                   0               /* Shift value for MSC_STATUS_BUSY          */
#define MSC_STATUS_BUSY_MASK                    (0x1UL << 0)    /* Bit mask for MSC_STATUS_BUSY             */
#define MSC_STATUS_BUSY_DEFAULT                 (0x0UL << 0)    /* Mode DEFAULT for MSC_STATUS_BUSY         */
#define MSC_STATUS_BUSY                         (0x1UL << 0)    /* Erase/Write Busy                         */
#define MSC_STATUS_LOCKED_SHIFT                 1               /* Shift value for MSC_STATUS_LOCKED        */
#define MSC_STATUS_LOCKED_MASK                  (0x1UL << 1)    /* Bit mask for MSC_STATUS_LOCKED           */
#define MSC_STATUS_LOCKED_DEFAULT               (0x0UL << 1)    /* Mode DEFAULT for MSC_STATUS_LOCKED       */
#define MSC_STATUS_LOCKED                       (0x1UL << 1)    /* Access Locked                            */
#define MSC_STATUS_INVADDR_SHIFT                2               /* Shift value for MSC_STATUS_INVADDR       */
#define MSC_STATUS_INVADDR_MASK                 (0x1UL << 2)    /* Bit mask for MSC_STATUS_INVADDR          */
#define MSC_STATUS_INVADDR_DEFAULT              (0x0UL << 2)    /* Mode DEFAULT for MSC_STATUS_INVADDR      */
#define MSC_STATUS_INVADDR                      (0x1UL << 2)    /* Invalid Write Address or Erase Page      */
#define MSC_STATUS_WDATAREADY_SHIFT             3               /* Shift value for MSC_STATUS_WDATAREADY    */
#define MSC_STATUS_WDATAREADY_MASK              (0x1UL << 3)    /* Bit mask for MSC_STATUS_WDATAREADY       */
#define MSC_STATUS_WDATAREADY_DEFAULT           (0x1UL << 3)    /* Mode DEFAULT for MSC_STATUS_WDATAREADY   */
#define MSC_STATUS_WDATAREADY                   (0x1UL << 3)    /* WDATA Write Ready                        */
#define MSC_STATUS_WORDTIMEOUT_SHIFT            4               /* Shift value for MSC_STATUS_WORDTIMEOUT   */
#define MSC_STATUS_WORDTIMEOUT_MASK             (0x1UL << 4)    /* Bit mask for MSC_STATUS_WORDTIMEOUT      */
#define MSC_STATUS_WORDTIMEOUT_DEFAULT          (0x0UL << 4)    /* Mode DEFAULT for MSC_STATUS_WORDTIMEOUT  */
#define MSC_STATUS_WORDTIMEOUT                  (0x1UL << 4)    /* Flash Write Word Timeout                 */
#define MSC_STATUS_ERASEABORTED_SHIFT           5               /* Shift value for MSC_STATUS_ERASEABORTED  */
#define MSC_STATUS_ERASEABORTED_MASK            (0x1UL << 5)    /* Bit mask for MSC_STATUS_ERASEABORTED     */
#define MSC_STATUS_ERASEABORTED_DEFAULT         (0x0UL << 5)    /* Mode DEFAULT for MSC_STATUS_ERASEABORTED */
#define MSC_STATUS_ERASEABORTED                 (0x1UL << 5)    /* The Current Flash Erase Operation Aborted */

/* Bit fields for MSC IF */
#define MSC_IF_RESETVALUE                       0x00000000UL    /* Default value for MSC_IF                 */
#define MSC_IF_MASK                             0x00000003UL    /* Mask for MSC_IF                          */
#define MSC_IF_ERASE_SHIFT                      0               /* Shift value for MSC_IF_ERASE             */
#define MSC_IF_ERASE_MASK                       (0x1UL << 0)    /* Bit mask for MSC_IF_ERASE                */
#define MSC_IF_ERASE_DEFAULT                    (0x0UL << 0)    /* Mode DEFAULT for MSC_IF_ERASE            */
#define MSC_IF_ERASE                            (0x1UL << 0)    /* Erase Done Interrupt Read Flag           */
#define MSC_IF_WRITE_SHIFT                      1               /* Shift value for MSC_IF_WRITE             */
#define MSC_IF_WRITE_MASK                       (0x1UL << 1)    /* Bit mask for MSC_IF_WRITE                */
#define MSC_IF_WRITE_DEFAULT                    (0x0UL << 1)    /* Mode DEFAULT for MSC_IF_WRITE            */
#define MSC_IF_WRITE                            (0x1UL << 1)    /* Write Done Interrupt Read Flag           */

/* Bit fields for MSC IFS */
#define MSC_IFS_RESETVALUE                      0x00000000UL    /* Default value for MSC_IFS                */
#define MSC_IFS_MASK                            0x00000003UL    /* Mask for MSC_IFS                         */
#define MSC_IFS_ERASE_SHIFT                     0               /* Shift value for MSC_IFS_ERASE            */
#define MSC_IFS_ERASE_MASK                      (0x1UL << 0)    /* Bit mask for MSC_IFS_ERASE               */
#define MSC_IFS_ERASE_DEFAULT                   (0x0UL << 0)    /* Mode DEFAULT for MSC_IFS_ERASE           */
#define MSC_IFS_ERASE                           (0x1UL << 0)    /* Erase Done Interrupt Set                 */
#define MSC_IFS_WRITE_SHIFT                     1               /* Shift value for MSC_IFS_WRITE            */
#define MSC_IFS_WRITE_MASK                      (0x1UL << 1)    /* Bit mask for MSC_IFS_WRITE               */
#define MSC_IFS_WRITE_DEFAULT                   (0x0UL << 1)    /* Mode DEFAULT for MSC_IFS_WRITE           */
#define MSC_IFS_WRITE                           (0x1UL << 1)    /* Write Done Interrupt Set                 */

/* Bit fields for MSC IFC */
#define MSC_IFC_RESETVALUE                      0x00000000UL    /* Default value for MSC_IFC                */
#define MSC_IFC_MASK                            0x00000003UL    /* Mask for MSC_IFC                         */
#define MSC_IFC_ERASE_SHIFT                     0               /* Shift value for MSC_IFC_ERASE            */
#define MSC_IFC_ERASE_MASK                      (0x1UL << 0)    /* Bit mask for MSC_IFC_ERASE               */
#define MSC_IFC_ERASE_DEFAULT                   (0x0UL << 0)    /* Mode DEFAULT for MSC_IFC_ERASE           */
#define MSC_IFC_ERASE                           (0x1UL << 0)    /* Erase Done Interrupt Clear               */
#define MSC_IFC_WRITE_SHIFT                     1               /* Shift value for MSC_IFC_WRITE            */
#define MSC_IFC_WRITE_MASK                      (0x1UL << 1)    /* Bit mask for MSC_IFC_WRITE               */
#define MSC_IFC_WRITE_DEFAULT                   (0x0UL << 1)    /* Mode DEFAULT for MSC_IFC_WRITE           */
#define MSC_IFC_WRITE                           (0x1UL << 1)    /* Write Done Interrupt Clear               */

/* Bit fields for MSC IEN */
#define MSC_IEN_RESETVALUE                      0x00000000UL    /* Default value for MSC_IEN                */
#define MSC_IEN_MASK                            0x00000003UL    /* Mask for MSC_IEN                         */
#define MSC_IEN_ERASE_SHIFT                     0               /* Shift value for MSC_IEN_ERASE            */
#define MSC_IEN_ERASE_MASK                      (0x1UL << 0)    /* Bit mask for MSC_IEN_ERASE               */
#define MSC_IEN_ERASE_DEFAULT                   (0x0UL << 0)    /* Mode DEFAULT for MSC_IEN_ERASE           */
#define MSC_IEN_ERASE                           (0x1UL << 0)    /* Erase Done Interrupt Enable              */
#define MSC_IEN_WRITE_SHIFT                     1               /* Shift value for MSC_IEN_WRITE            */
#define MSC_IEN_WRITE_MASK                      (0x1UL << 1)    /* Bit mask for MSC_IEN_WRITE               */
#define MSC_IEN_WRITE_DEFAULT                   (0x0UL << 1)    /* Mode DEFAULT for MSC_IEN_WRITE           */
#define MSC_IEN_WRITE                           (0x1UL << 1)    /* Write Done Interrupt Enable              */

/* Bit fields for MSC LOCK */
#define MSC_LOCK_RESETVALUE                     0x00000000UL    /* Default value for MSC_LOCK               */
#define MSC_LOCK_MASK                           0x0000FFFFUL    /* Mask for MSC_LOCK                        */
#define MSC_LOCK_LOCKKEY_SHIFT                  0               /* Shift value for MSC_LOCK_LOCKKEY         */
#define MSC_LOCK_LOCKKEY_MASK                   (0xFFFFUL << 0) /* Bit mask for MSC_LOCK_LOCKKEY            */
#define MSC_LOCK_LOCKKEY_DEFAULT                (0x0UL    << 0) /* Mode DEFAULT for MSC_LOCK_LOCKKEY        */
#define MSC_LOCK_LOCKKEY_LOCK                   (0x0UL    << 0) /* Mode LOCK for MSC_LOCK_LOCKKEY           */
#define MSC_LOCK_LOCKKEY_UNLOCKED               (0x0UL    << 0) /* Mode UNLOCKED for MSC_LOCK_LOCKKEY       */
#define MSC_LOCK_LOCKKEY_LOCKED                 (0x1UL    << 0) /* Mode LOCKED for MSC_LOCK_LOCKKEY         */
#define MSC_LOCK_LOCKKEY_UNLOCK                 (0x1B71UL << 0) /* Mode UNLOCK for MSC_LOCK_LOCKKEY         */
    
#define MSC_MAX_FREQ_0WS                        16000000UL      /* Maximum allowed core frequency when using 0 
                                                                   wait states on flash access.             */
#define MSC_MAX_FREQ_1WS                        32000000UL
                       
#define MSC_PROGRAM_TIMEOUT                     10000000UL
    
#define	MSC_FLASH_BANK_SIZE                     4096
    
    
/*************************************************************************************************************
*                                                  DATA TYPES                                                *
*************************************************************************************************************/
typedef enum
{
    MSC_HANDLE_OK,          /* Flash write/erase successful.                                                */
    MSC_HANDLE_INVADDR,     /* Invalid address. Write to an address that is not flash.                      */
    MSC_HANDLE_LOCKED,      /* Flash address is locked.                                                     */
    MSC_HANDLE_TIMEOUT,     /* Timeout while writing to flash.                                              */
    MSC_HANDLE_UNALIGNED,   /* Unaligned access to flash.                                                   */
    MSC_HANDLE_ERROR,       /* Unaligned access to flash.                                                   */
} MSCHandleTypeDef;    
 
typedef enum
{
    MSC_IRQ_WRITE = MSC_IF_WRITE, 
    MSC_IRQ_ERASE = MSC_IF_ERASE, 
} MSCIrqTypeDef;

/*************************************************************************************************************
*                                            FUNCTION PROTOTYPES                                             *
*************************************************************************************************************/
static inline void MSCLock (void)
{
    MSC->LOCK = 0;  /* Lock the MSC */
}

static inline void MSCUnlock (void)
{
    MSC->WRITECTRL |= MSC_WRITECTRL_WREN;
    MSC->LOCK = MSC_LOCK_LOCKKEY_UNLOCK;    /* Unlock the MSC */
    MSC->WRITECTRL &= ~MSC_WRITECTRL_WREN;
}

static inline void MSCIntEnable (CPU_INT32U flag)
{
    MSC->IEN |= flag;
}

static inline void MSCIntDisable (CPU_INT32U flag)
{
    MSC->IEN &= ~flag;
}

static inline CPU_INT32U MSCIntGet (void)
{
    return MSC->IF;
}

static inline CPU_BOOL MSCIntFlagGet (MSCIrqTypeDef irq)
{
    if (MSC->IF & irq)
    {
        return DEF_ON;
    }
    else
    {
        return DEF_OFF;
    }
}

static inline void MSCIntSet (CPU_INT32U flag)
{
    MSC->IFS = flag;
}

static inline void MSCIntClear (CPU_INT32U flag)
{
    MSC->IFC = flag;
}

static inline CPU_INT32U MSCIntStatusGet (void)
{
    return MSC->IEN;
}

static inline CPU_INT32U MSCIntEnabledGet (void)
{
    CPU_INT32U en;

    en = 0;
    en = MSC->IEN;

    /* Bitwise AND of pending and enabled interrupts */
    return MSC->IF & en;
}


/*************************************************************************************************************
*                                            FUNCTION STATEMENT                                              *
*************************************************************************************************************/
void MSCFlashWaitStateControl(CPU_INT32U clk);
MSCHandleTypeDef MSCErasePage (CPU_INT32U addr);
MSCHandleTypeDef MSCWriteWord (CPU_INT32U addr, CPU_INT32U  word);


/*************************************************************************************************************
*                                               MODULE END                                                   *
*************************************************************************************************************/     
#ifdef __cplusplus
}
#endif

#endif 

