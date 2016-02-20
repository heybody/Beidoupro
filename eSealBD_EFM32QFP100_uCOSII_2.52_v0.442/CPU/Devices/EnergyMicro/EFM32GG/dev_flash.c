/*************************************************************************************************************
*                                              INCLUDE FILES                                                 *
*************************************************************************************************************/
#include <util.h>

#include <app.h>
#include <dev.h>


/*************************************************************************************************************
*                                            FUNCTION PROTOTYPES                                             *
*************************************************************************************************************/
void DevFlashUnlock (void)
{
    
#if APP_WATCH_DOG_EN > 0 
        DevWatchDogFeed(DEV_WDOG0);
#endif
        
    MSCUnlock();
}

void DevFlashLock (void)
{
    MSCLock();
}

CPU_BOOL DevFlashErase (CPU_INT32U address)
{
    if (MSCErasePage(address) == MSC_HANDLE_OK)
    {
        return DEF_TRUE;
    }
    else
    {
        return DEF_FALSE;
    }
}

CPU_BOOL DevFlashWrite (CPU_INT32U address, CPU_INT8U const *pdata, CPU_INT32U len)
{
    CPU_INT32U i;
    CPU_INT32U word;
    CPU_INT32U addr;
    CPU_INT32U word_addr;
    
    addr = address;

    if (len >= 4 - (address % 4))
    {
        if ((addr % 4) != 0)
        {	
            word = NToHL(NToHL((*((CPU_INT32U *)pdata))) >> ((addr % 4) * 8) | (0xFFFFFFFF << ((4 - (addr % 4)) * 8)));
	    word_addr = addr - (addr % 4);
	    if (MSCWriteWord(word_addr, word) != MSC_HANDLE_OK)
            {
                //return DEF_FALSE;
            }

	    pdata += 4 - (addr % 4);	
	    len = len - (4 - (addr % 4));
	    addr = addr - (addr % 4) + 4;		
        }

        for (i = 0; i < len / 4; i++)
        {
            word_addr = addr + i * 4;				
            word = *(((CPU_INT32U *)pdata) + i);
            
            if (MSCWriteWord(word_addr, word) != MSC_HANDLE_OK)
            {
                //return DEF_FALSE;
            }
        }
    
        if ((len % 4) != 0)
        {
            word_addr = addr + i * 4;
            word = NToHL(NToHL((*((CPU_INT32U *)pdata + i))) | (0xFFFFFFFF >> (((addr + len) % 4) * 8))); 
            
            if (MSCWriteWord(word_addr, word) != MSC_HANDLE_OK)
            {
                //return DEF_FALSE;
            }
        }		
    }
    else
    {
        if (address != 0)
        {
            word = NToHL(NToHL((*((CPU_INT32U *)pdata))) >> ((addr % 4) * 8) | ((0xFFFFFFFF << ((4 - (addr % 4)) * 8)) | (0xFFFFFFFF >> ((addr % 4) + len) * 8)));
        }
        else
        {
            word = NToHL(NToHL((*((CPU_INT32U *)pdata))) | (0xFFFFFFFF >> (len * 8)));
        }
		
        word_addr = addr - (addr % 4);
        if (MSCWriteWord(word_addr, word) != MSC_HANDLE_OK)
        {
            //return DEF_FALSE;
        }
    }
    
    return DEF_TRUE;
}

void DevFlashRead (CPU_INT32U address, CPU_INT8U *pdata, CPU_INT32U len)
{
    CPU_INT32U i;

    for (i = 0; i < len; i++)
    {
        pdata[i] = (CPU_INT8U)(*(DEF_IO CPU_INT32U*)(address + i));
    }
}


/*************************************************************************************************************
*                                                  END FILE                                                  *
*************************************************************************************************************/