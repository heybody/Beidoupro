/*************************************************************************************************************
*                                              INCLUDE FILES                                                 *
*************************************************************************************************************/
#include <dev.h>


/*************************************************************************************************************
*                                            FUNCTION PROTOTYPES                                             *
*************************************************************************************************************/
void FIFOInit (FIFODataTypeDef *pfifo)
{
    pfifo->info.front = 0;
    pfifo->info.rear = 0;
    pfifo->info.flag = FIFO_STATUS_EMPTY;
}

CPU_INT8U FIFOIn (FIFODataTypeDef *pfifo, CPU_INT8U *byte, CPU_INT32U size)
{   
    CPU_INT8U *p;
    
    if (pfifo->info.flag == FIFO_STATUS_FULL)
    {
        return FIFO_ERROR_FULL;
    }
    
    p = (CPU_INT8U *)((CPU_INT32U)(&pfifo->pdata) + pfifo->info.rear);

    *p = *byte;
    
    pfifo->info.rear = (pfifo->info.rear + 1) % size;
    
    if (pfifo->info.rear == pfifo->info.front)
    {
        pfifo->info.flag = FIFO_STATUS_FULL;
    }
    else
    {
        pfifo->info.flag = FIFO_STATUS_OTHER;
    }
    
    return FIFO_OK;
}

CPU_INT8U FIFOOut (FIFODataTypeDef *pfifo, CPU_INT8U *byte, CPU_INT32U size)
{
    CPU_INT8U *p;
    
    if (pfifo->info.flag == FIFO_STATUS_EMPTY)
    {
        return FIFO_ERROR_EMPTY;
    }

    p = (CPU_INT8U *)((CPU_INT32U)(&pfifo->pdata) + pfifo->info.front);
    
    *byte = *p;
    
    pfifo->info.front = (pfifo->info.front + 1) % size;
    
    if (pfifo->info.rear == pfifo->info.front)
    {
        pfifo->info.flag = FIFO_STATUS_EMPTY;
    }
    else
    {
        pfifo->info.flag = FIFO_STATUS_OTHER;
    }
    
    return FIFO_OK;
}

CPU_BOOL FIFOIsEmpty (FIFODataTypeDef *pfifo)
{
    if (pfifo->info.flag == FIFO_STATUS_EMPTY)
    {
        return DEF_TRUE;
    }
    else
    {
        return DEF_FALSE;
    }
}

CPU_BOOL FIFOIsFull (FIFODataTypeDef *pfifo, CPU_INT32U size)
{
    if (pfifo->info.flag == FIFO_STATUS_FULL)
    {
        return DEF_TRUE;
    }
	else
	{
        return DEF_FALSE;
	}
}

CPU_INT32U GetFIFOCount (FIFODataTypeDef *pfifo, CPU_INT32U size)
{
    CPU_INT32U count;
    
    if (pfifo->info.rear < pfifo->info.front)
    {
        count = pfifo->info.rear + size - pfifo->info.front;
    }
    else if (pfifo->info.rear == pfifo->info.front)
    {
        if (pfifo->info.flag == FIFO_STATUS_FULL)
        {
            count = size;
        }
        else
        {
            count = 0;
        }
    }
    else
    {
        count = pfifo->info.rear - pfifo->info.front;
    }
    
        
    return count;
}


/*************************************************************************************************************
*                                                  END FILE                                                  *
*************************************************************************************************************/