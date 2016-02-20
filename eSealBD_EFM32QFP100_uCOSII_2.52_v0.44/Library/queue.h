/*************************************************************************************************************
*                                                  MODULE                                                    *
*************************************************************************************************************/
#ifndef QUEUE_H
#define QUEUE_H

#ifdef __cplusplus
extern "C" {
#endif


/*************************************************************************************************************
*                                                  DATA TYPES                                                *
*************************************************************************************************************/
typedef struct 
{
    unsigned int front;
    unsigned int rear;
    unsigned int count;
    void *item;       
}sQueue;


/*************************************************************************************************************
*                                            FUNCTION STATEMENT                                              *
*************************************************************************************************************/
void QueueInit (void *hq);
unsigned char QueueIsEmpty (void *hq);
unsigned char QueueIsFull (void *hq, unsigned int queue_size);
void QueueIn (void *hq, void **item, unsigned int item_size, unsigned int queue_size);
unsigned char QueueOut (void *hq, void **item, unsigned int item_size, unsigned int queue_size);


/*************************************************************************************************************
*                                               MODULE END                                                   *
*************************************************************************************************************/
#ifdef __cplusplus
}
#endif

#endif
