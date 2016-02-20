/*************************************************************************************************************
*                                              INCLUDE FILES                                                 *
*************************************************************************************************************/
#include <util.h>
#include <crc.h>

#include <head.h>


/*************************************************************************************************************
*                                            FUNCTION PROTOTYPES                                             *
*************************************************************************************************************/
void HeadReplayData (unsigned short port, unsigned short type, unsigned char *pdata, 
                     unsigned short len, FNCT_COMM comm)
{
    sHeadTypeDef *head;
    
    head = (sHeadTypeDef *)&pdata[SOCKET_HEAD_SIZE];
    head->len = NToHS(len);
    
    head->type = NToHS(type);
    
    head->crc = NToHS(GetCRC16(&pdata[SOCKET_HEAD_SIZE + HEAD_CRC_POS], HEAD_HEAD_SIZE - HEAD_CRC_LEN + len)); 
    SocketPackageSend(port, pdata, HEAD_HEAD_SIZE + len); 
    comm(pdata, SOCKET_HEAD_SIZE + HEAD_HEAD_SIZE + len);
}

void HeadReplayError (unsigned short port, unsigned short type, unsigned char error, FNCT_COMM comm)
{
    unsigned char data[SOCKET_HEAD_SIZE + HEAD_HEAD_SIZE + HEAD_REPLAY_SIZE_ERROR];
    unsigned short len;
    sHeadTypeDef *head;
    sHeadReplayErrorTypeDef *replay;
    
    len = HEAD_REPLAY_SIZE_ERROR;
    
    head = (sHeadTypeDef *)&data[SOCKET_HEAD_SIZE];
    replay = (sHeadReplayErrorTypeDef *)&head->data;
    
    replay->error = error;
    
    HeadReplayData(port, type, data, len, comm);
}


/*************************************************************************************************************
*                                               MODULE END                                                   *
*************************************************************************************************************/
