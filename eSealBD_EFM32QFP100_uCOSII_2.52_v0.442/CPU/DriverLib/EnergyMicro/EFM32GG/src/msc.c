/*************************************************************************************************************
*                                              INCLUDE FILES                                                 *
*************************************************************************************************************/
#include <efm32.h>


/*************************************************************************************************************
*                                            FUNCTION PROTOTYPES                                             *
*************************************************************************************************************/
void MSCFlashWaitStateControl (CPU_INT32U clk)
{
    CPU_INT32U cfg;

    cfg = MSC->READCTRL;

    if ((clk > MSC_MAX_FREQ_0WS) && (clk <= MSC_MAX_FREQ_1WS))
    {
        switch (cfg & MSC_READCTRL_MODE_MASK)
        {
            case MSC_READCTRL_MODE_WS0SCBTP:
            case MSC_READCTRL_MODE_WS1SCBTP:    cfg = (cfg & ~MSC_READCTRL_MODE_MASK) | MSC_READCTRL_MODE_WS1SCBTP;
                                                break;
            default:                            cfg = (cfg & ~MSC_READCTRL_MODE_MASK) | MSC_READCTRL_MODE_WS1;
                                                break;
        }
    }

    if (clk <= MSC_MAX_FREQ_0WS)
    {
        switch (cfg & MSC_READCTRL_MODE_MASK)
        {
            case MSC_READCTRL_MODE_WS1SCBTP:
            case MSC_READCTRL_MODE_WS0SCBTP:    cfg = (cfg & ~MSC_READCTRL_MODE_MASK) | MSC_READCTRL_MODE_WS0SCBTP;
                                                break;
            default:                            cfg = (cfg & ~MSC_READCTRL_MODE_MASK) | MSC_READCTRL_MODE_WS0;
                                                break;
        }
    }

    MSC->READCTRL = cfg;
}

__ramfunc MSCHandleTypeDef MSCErasePage (CPU_INT32U addr)
{
    CPU_INT32U timeout;
    
    timeout = MSC_PROGRAM_TIMEOUT;

    /* Address must be aligned to pages */
    if (addr > (FLASH_START_BASE + FLASH_SIZE - 1))
    {
        return MSC_HANDLE_INVADDR;
    }
    
    addr &= ~0x1FF;
    
    MSC->WRITECTRL |= MSC_WRITECTRL_WREN;   /* Enable writing to the MSC */

    /* Load address */
    MSC->ADDRB    = addr;
    MSC->WRITECMD = MSC_WRITECMD_LADDRIM;
    
    /* Check for invalid address */
    if (MSC->STATUS & MSC_STATUS_INVADDR)
    {        
        MSC->WRITECTRL &= ~MSC_WRITECTRL_WREN;  /* Disable writing to the MSC */
        return MSC_HANDLE_INVADDR;
    }

    /* Check for write protected page */
    if (MSC->STATUS & MSC_STATUS_LOCKED)
    {
        MSC->WRITECTRL &= ~MSC_WRITECTRL_WREN;  /* Disable writing to the MSC */
        return MSC_HANDLE_LOCKED;
    }

    MSC->WRITECMD = MSC_WRITECMD_ERASEPAGE;   /* Send erase page command */

    /* Wait for the erase to complete */

    while ((MSC->STATUS & MSC_STATUS_BUSY) && (timeout != 0))
    {
        timeout--;
    }

    if (timeout == 0)
    {
        MSC->WRITECTRL &= ~MSC_WRITECTRL_WREN;  /* Disable writing to the MSC */
        return MSC_HANDLE_TIMEOUT;
    }

    MSC->WRITECTRL &= ~MSC_WRITECTRL_WREN;  /* Disable writing to the MSC */
    return MSC_HANDLE_OK;
}

__ramfunc MSCHandleTypeDef MSCWriteWord (CPU_INT32U addr, CPU_INT32U  word)
{
    CPU_INT32U timeout;

    if (addr > FLASH_START_BASE + FLASH_SIZE)
    {
        return MSC_HANDLE_INVADDR;
    }
    
    if (addr & 0x3)
    {
        return MSC_HANDLE_INVADDR;
    }
    
    MSC->WRITECTRL |= MSC_WRITECTRL_WREN;   /* Enable writing to the MSC */
    
    /* Load address */
    MSC->ADDRB    = addr ;
    MSC->WRITECMD = MSC_WRITECMD_LADDRIM;
        
    /* Check for invalid address */
    if (MSC->STATUS & MSC_STATUS_INVADDR)
    {        
        MSC->WRITECTRL &= ~MSC_WRITECTRL_WREN;  /* Disable writing to the MSC */
        return MSC_HANDLE_INVADDR;
    }
    
    /* Check for write protected page */
    if (MSC->STATUS & MSC_STATUS_LOCKED)
    {
        MSC->WRITECTRL &= ~MSC_WRITECTRL_WREN;  /* Disable writing to the MSC */
        return MSC_HANDLE_LOCKED;
    }
        
    /* Wait for the MSC to be ready for a new data word */
    /* Due to the timing of this function, the MSC should allready by ready */
    timeout = MSC_PROGRAM_TIMEOUT;
    while (((MSC->STATUS & MSC_STATUS_WDATAREADY) == 0) && (timeout != 0))
    {
        timeout--;
    }
        
    if (timeout == 0)
    {
        MSC->WRITECTRL &= ~MSC_WRITECTRL_WREN;  /* Disable writing to the MSC */
        return MSC_HANDLE_TIMEOUT;
    }
        
    MSC->WDATA = word; /* Load data into write data register */

    MSC->WRITECMD = MSC_WRITECMD_WRITEONCE; /* Trigger write once */

    /* Wait for the erase to complete */
    timeout = MSC_PROGRAM_TIMEOUT;
    while ((MSC->STATUS & MSC_STATUS_BUSY) && (timeout != 0))
    {
        timeout--;
    }
    
    if (timeout == 0)
    {
        MSC->WRITECTRL &= ~MSC_WRITECTRL_WREN;  /* Disable writing to the MSC */
        return MSC_HANDLE_TIMEOUT;
    }
          
    MSC->WRITECTRL &= ~MSC_WRITECTRL_WREN;  /* Disable writing to the MSC */ 
    
    if (*(DEF_IO CPU_INT32U*)addr != word)
    {
        return MSC_HANDLE_ERROR;
    }
    
    return MSC_HANDLE_OK;
}


/*************************************************************************************************************
*                                                  END FILE                                                  *
*************************************************************************************************************/
