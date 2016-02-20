/*************************************************************************************************************
*                                                  MODULE                                                    *
*************************************************************************************************************/
#ifndef HEAD_H
#define HEAD_H

#ifdef __cplusplus
extern "C" {
#endif

/*************************************************************************************************************
*                                              INCLUDE FILES                                                 *
*************************************************************************************************************/
#include <socket.h>
    
    
/*************************************************************************************************************
*                                                 DEFINES                                                    *
*************************************************************************************************************/
#define HEAD_HEAD_SIZE                          6u
    
#define HEAD_CRC_POS                            2u    
#define HEAD_CRC_LEN                            2u
#define HEAD_DATA_POS                           6u

#define HEAD_REPLAY_SIZE_ERROR                  1u
    
#define HEAD_ERROR_TYPE_CRC                     0u
    
#define HEAD_TYPE_REPLAY_ERROR                  0x000Fu
    

/*************************************************************************************************************
*                                                  DATA TYPES                                                *
*************************************************************************************************************/
typedef struct
{
    unsigned short crc;
    unsigned short type;
    unsigned short len;
    unsigned char  data;
} sHeadTypeDef;

typedef struct
{
    unsigned char  error;
} sHeadReplayErrorTypeDef;


/*************************************************************************************************************
*                                            FUNCTION STATEMENT                                              *
*************************************************************************************************************/
void HeadReplayData (unsigned short port, unsigned short type, unsigned char *pdata, 
                     unsigned short len, FNCT_COMM comm);
void HeadReplayError (unsigned short port, unsigned short type, unsigned char error, FNCT_COMM comm);


/*************************************************************************************************************
*                                               MODULE END                                                   *
*************************************************************************************************************/
#ifdef __cplusplus
}
#endif

#endif
