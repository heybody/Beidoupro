/*************************************************************************************************************
*                                                  MODULE                                                    *
*************************************************************************************************************/
#ifndef DEV_FIFO_H
#define DEV_FIFO_H

#ifdef __cplusplus
extern "C" {
#endif
    
    
/*************************************************************************************************************
*                                                 DEFINES                                                    *
*************************************************************************************************************/ 
#define	FIFO_OK                                 0
#define	FIFO_ERROR_FULL                         1
#define	FIFO_ERROR_EMPTY                        2
#define	FIFO_ERROR_COUNT                        3

#define	FIFO_INFO_SIZE                          12
    
#define	FIFO_STATUS_FULL                        1
#define	FIFO_STATUS_EMPTY                       2
#define	FIFO_STATUS_OTHER                       3
    

/*************************************************************************************************************
*                                                  DATA TYPES                                                *
*************************************************************************************************************/
#pragma pack(1)
    
typedef struct
{
    CPU_INT32U front;
    CPU_INT32U rear; 
    CPU_INT32U flag;    
} FIFOInfoTypeDef;  

typedef struct
{
    FIFOInfoTypeDef info;
    CPU_INT8U pdata;     
} FIFODataTypeDef;

#pragma pack()  


/*************************************************************************************************************
*                                            FUNCTION STATEMENT                                              *
*************************************************************************************************************/  
void FIFOInit (FIFODataTypeDef *pfifo);
CPU_INT8U FIFOIn (FIFODataTypeDef *pfifo, CPU_INT8U *byte, CPU_INT32U size);
CPU_INT8U FIFOOut (FIFODataTypeDef *pfifo, CPU_INT8U *byte, CPU_INT32U size);
CPU_BOOL FIFOIsEmpty (FIFODataTypeDef *pfifo);
CPU_BOOL FIFOIsFull (FIFODataTypeDef *pfifo, CPU_INT32U size);
CPU_INT32U GetFIFOCount (FIFODataTypeDef *pfifo, CPU_INT32U size);


/*************************************************************************************************************
*                                               MODULE END                                                   *
*************************************************************************************************************/ 
#ifdef __cplusplus
}
#endif

#endif