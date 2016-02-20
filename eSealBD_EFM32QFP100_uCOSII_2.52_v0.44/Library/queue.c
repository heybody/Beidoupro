/*************************************************************************************************************
*                                              INCLUDE FILES                                                 *
*************************************************************************************************************/
#include <queue.h>


/*************************************************************************************************************
*                                            FUNCTION PROTOTYPES                                             *
*************************************************************************************************************/
void QueueInit (void *hq)
{
    sQueue *p;

    p = (sQueue *)hq;
    p->front = p->rear = 0;
    p->count = 0;
}

unsigned char QueueIsEmpty (void *hq)
{
    sQueue *p;

    p = (sQueue *)hq;

    if (p->count == 0)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

unsigned char QueueIsFull (void *hq, unsigned int queue_size)
{
    sQueue *p;

    p = (sQueue *)hq;

    if (p->count == queue_size)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void QueueIn (void *hq, void **item, unsigned int item_size, unsigned int queue_size)
{   
    sQueue *p;

    p = (sQueue *)hq;

    *item = (void *)((unsigned int)(&p->item)+ p->rear * item_size);

    if (QueueIsFull(hq, queue_size) == 0)
    {	
        p->rear = (p->rear + 1) % queue_size;
    }
    else
    {
        p->front = (p->front + 1) % queue_size;
        p->rear = (p->rear + 1) % queue_size;
    }
	
	p->count++;

    if (p->count > queue_size)
    {
        p->count = queue_size;
    }
}

unsigned char  QueueOut (void *hq, void **item, unsigned int item_size, unsigned int queue_size)
{
    sQueue *p;

    p = (sQueue *)hq;

    if (p->count == 0)
    {
        return 0;
    }

    *item = (void *)((unsigned int)(&p->item)+ p->front * item_size);

    p->front = (p->front + 1) % queue_size;  
	
    p->count--;

    return 1;
}


/*************************************************************************************************************
*                                               MODULE END                                                   *
*************************************************************************************************************/
