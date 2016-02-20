/*************************************************************************************************************
*                                              INCLUDE FILES                                                 *
*************************************************************************************************************/
#include <app.h>
#include <ucos_ii.h>


/*************************************************************************************************************
*                                            GLOBAL VARIABLES                                              *
*************************************************************************************************************/
extern OS_EVENT *GprsAckMsg;


/*************************************************************************************************************
*                                            FUNCTION PROTOTYPES                                             *
*************************************************************************************************************/
void EsealBDGprsProcess (CPU_INT8U *pdata, CPU_INT32U len, FNCT_COMM comm)
{
    sHeadTypeDef *head;

    head = (sHeadTypeDef *)pdata;
    
    if (NToHS(head->crc) != GetCRC16(&pdata[HEAD_CRC_POS], NToHS(head->len) + HEAD_HEAD_SIZE - HEAD_CRC_LEN))
    {
        return;
    }
    
    switch (NToHS(head->type))
    {
        case ESEALBD_GPRS_TYPE_RET:   EsealBDGprsRet(&head->data, NToHS(head->len), comm);
                                                break;
        default:                                break;
    }
}

void EsealBDGprsRet (CPU_INT8U *pdata, CPU_INT32U len, FNCT_COMM comm)
{

    sEsealBDGprsRetTypeDef *cmd;
    GprsSendStatusTypeDef gprs_send_status;
    CPU_INT32U id;
    CPU_INT8U status;
    
    cmd = (sEsealBDGprsRetTypeDef *)pdata;
    id = EsealBDGetID();
    
    if (NToHL(cmd->id) == id)
    {
        GprsSendStatusGet(&gprs_send_status);
        
        if (gprs_send_status. send_flag == DEF_ON)
        { 
            gprs_send_status.rec_flag = DEF_ON;
            gprs_send_status.rec_tick = OSTimeGet();
            GprsSendStatusSet(gprs_send_status);
            
            status = DEF_ON;
            
            OSMboxPost(GprsAckMsg, &status);
        }
    }
}


/*************************************************************************************************************
*                                               MODULE END                                                   *
*************************************************************************************************************/
