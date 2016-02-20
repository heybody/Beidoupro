/*************************************************************************************************
*                                                  MODULE                                        *
*************************************************************************************************/
#ifndef GPRS_UBLOX_H
#define GPRS_UBLOX_H

#ifdef __cplusplus
extern "C" {
#endif

//#include "type_def.h"
//#include "gnss.h"
/*************************************************************************************************
*                                                 DEFINES                                        *
*************************************************************************************************/
#define AT_CMD_OK                                                   1
#define AT_CMD_ERROR                                                0
#define AT_CMD_TIME_OUT                                             2

#define GPRS_LOCA_OK						                        1 
#define GPRS_LOCA_ERROR						                        0
#define GPRS_LOCA_INVALID					                        2
#define GPRS_LOCA_TIME_OUT					                        3

#define SIM_STATE_OK						                        1 
#define SIM_STATE_ERROR					                            0

#define GPRS_CONNECT_OK						                        1 
#define GPRS_CONNECT_ERROR					                        0
#define GPRS_CONNECT_TIME_OUT			                            2

#define GPRS_TCPIP_OK						                        1 
#define GPRS_TCPIP_ERROR					                        0
#define GPRS_TCPIP_TIME_OUT					                        2

#define GPRS_MESSAGE_OK						                        1 
#define GPRS_MESSAGE_ERROR					                        0
#define GPRS_MESSAGE_TIME_OUT				                        2

#define GPRS_MESSAGE_EXIST					                        1 
#define GPRS_MESSAGE_EMPTY					                        0

#define GPRS_GPS_OK						                            1 
#define GPRS_GPS_ERROR						                        0
#define GPRS_GPS_TIME_OUT					                        2
    
    
#define GPRS_ECHO_SET                                               DEF_ON
#define GPRS_DEST_IP_ADDRESS                                        (121ul << 24) | (40ul << 16) | (88ul << 8) | 79ul//(222ul << 24) | (66ul << 16) | (163ul << 8) | 10ul
#define GPRS_DEST_PORT                                              19010
    
    
//#define GPRS_DEST_IP_ADDRESS                                      (222ul << 24) | (66ul << 16) | (163ul << 8) | 10ul//(222ul << 24) | (66ul << 16) | (163ul << 8) | 10ul
//#define GPRS_DEST_PORT                                            5201 
    
//#define GPRS_DEST_IP_ADDRESS                                      (180ul << 24) | (153ul << 16) | (127ul << 8) | 26ul//(222ul << 24) | (66ul << 16) | (163ul << 8) | 10ul
//#define GPRS_DEST_PORT                                            19000   
    
#define GPRS_COM_DATA_MAX_SIZE                                      121
#define GPRS_DATA_QUEUE_SIZE                                        1

#define GPRS_STATE_CREG_QUERY                                       0
#define GPRS_STATE_CREG_SET                                         1
#define GPRS_STATE_COPS_SEARCH                                      2
#define GPRS_STATE_COPS_SET                                         3
#define GPRS_STATE_COPS_QUERY                                       4
    
#define GPRS_SOCKET_ACK_TIME_OUT					                (78 - 35)
    
    
/*************************************************************************************************
*                                                  DATA TYPES                                    *
*************************************************************************************************/
#pragma pack(1)

typedef struct  
{
    CPU_INT16U year;
    CPU_INT8U  month;
    CPU_INT8U  day;
    CPU_INT8U  hour;
    CPU_INT8U  minute;
    CPU_INT8U  second;
    CPU_INT8U  msecond;
} sTimeTypeDef;

typedef struct  
{
    CPU_INT16U latfront;
    CPU_INT32U latback;
    CPU_INT16U longfront;
    CPU_INT32U longback;
} sLatLongTypeDef;

typedef struct  
{
    sTimeTypeDef time;
    sLatLongTypeDef  latlong;
    CPU_INT32U high;
    CPU_INT16U speed;
    CPU_INT16U direction;
    CPU_INT8U  sensor_used;
} sLocaInfoTypeDef;

typedef struct  
{
    CPU_INT8U	phone[11];
    sTimeTypeDef  time;
    CPU_INT8U	len;
    CPU_INT8U   data[256];
} sMessageInfoTypeDef;


//queue
typedef struct
{
    CPU_INT8U len;
    CPU_INT8U data[GPRS_COM_DATA_MAX_SIZE];
} sGprsDataItemTypeDef;


typedef struct 
{
    CPU_INT32U front;
    CPU_INT32U rear; 
    CPU_INT32U count;
    sGprsDataItemTypeDef item[GPRS_DATA_QUEUE_SIZE];       
} sGprsDataQueueTypeDef;

typedef struct 
{
    volatile CPU_BOOL flag;
    sGprsDataQueueTypeDef queue;
} sGprsDataTypeDef;

typedef enum 
{
    GPRS_TX_QUEUE_OK,
    GPRS_TX_QUEUE_ERROR_ITEM_SIZE,
    GPRS_TX_QUEUE_ERROR_QUEUE_SIZE,
} GprsTXQueueTypeDef;

typedef struct 
{
    CPU_INT32U send_tick;
    CPU_INT32U rec_tick;
    CPU_BOOL rec_flag;
    CPU_BOOL send_flag;
} GprsSendStatusTypeDef;

#pragma pack()

typedef enum
{
    GPRS_STATE_AT_CHECK,  
    GPRS_STATE_ATEX_SET,      
    GPRS_STATE_SOCKET_HEX_SET,      
    GPRS_STATE_CARD_CHECK,      
    GPRS_STATE_CSQ_CHECK,
    GPRS_STATE_CREG_CHECK,
    GPRS_STATE_CGREG_CHECK,
    GPRS_STATE_USPDA_SET,
    GPRS_STATE_TCPIP_CREAT,     
    GPRS_STATE_TCPIP_SET,
    GPRS_STATE_TCPIP_ACK_SET,
    GPRS_STATE_RESTART,
    GPRS_STATE_SMS_SET_TXT,    
    GPRS_STATE_SMS_SET_LOC,    
    GPRS_STATE_SMS_SET_DISINDICATE,    
} GprsStateTypeDef;

typedef enum
{
    GPRS_PROCESS_OK,
    GPRS_PROCESS_ERROR,
    GPRS_PROCESS_TIME_OUT,
} GprsStateRetTypeDef;

typedef enum
{
    GPRS_GPRS_STATE_BUSY,
    GPRS_GPRS_STATE_FREE,
} GprsStateFlagTypeDef;

typedef struct 
{   
    CPU_INT8U  name[32];
    CPU_INT8U  len;
} GSMNetNameTypeDef;

typedef struct 
{   
    CPU_INT8U  n;
    GSMNetNameTypeDef  net[5];
} GSMNetTypeDef;


/*************************************************************************************************
*                                        FUNCTION STATEMENT                                   *
*************************************************************************************************/
void GprsProcessUblox (GprsStateTypeDef init);
void GprsRestart (void);
CPU_BOOL GprsSocketStatusGet(void);
void GprsSocketStatusSet(CPU_BOOL status);
void GprsRst (void);
void GprsInit (void);
CPU_INT8U GprsCurrentSocketGet (void);
GprsStateRetTypeDef GprsSocketRxBufferGet (CPU_INT8U *pdata, CPU_INT16U *len, CPU_INT16U max);

CPU_INT32U ATcmdInfoGet (CPU_INT8U *pdata, CPU_INT32U len);
CPU_INT8U GetATReply(CPU_INT8U *pdata, CPU_INT16U delay, CPU_INT16U len);
GprsStateRetTypeDef ATcmdAT (void);
GprsStateRetTypeDef ATcmdSIMState (void);
GprsStateRetTypeDef ATcmdStopSleep(void);
GprsStateRetTypeDef ATcmdConnect(void);
GprsStateRetTypeDef ATcmdBTS(sLocaInfoTypeDef *locainfo);
GprsStateRetTypeDef ATcmdTCPIPCreat(CPU_INT8U *socket);
GprsStateRetTypeDef ATcmdTCPIPSetup(CPU_INT32U ip, CPU_INT16U port, CPU_INT8U socket);
GprsStateRetTypeDef ATcmdTCPIPSendAssic(CPU_INT8U *pdata, CPU_INT16U len, CPU_INT8U socket);
GprsStateRetTypeDef ATcmdTCPIPSendHex (CPU_INT8U *pdata, CPU_INT16U len, CPU_INT8U socket);
GprsStateRetTypeDef ATcmdTCPIPSendHexRequire (CPU_INT8U socket, CPU_INT8U len);

GprsStateRetTypeDef ATcmdTCPIPRecDataLenGet(CPU_INT8U socket, CPU_INT16U *len);
GprsStateRetTypeDef ATcmdTCPIPReceive(CPU_INT8U *pdata, CPU_INT16U len, CPU_INT8U socket);
GprsStateRetTypeDef ATcmdTCPIPClose(CPU_INT8U socket);
GprsStateRetTypeDef ATcmdSetTcpAck (CPU_INT8U socket, CPU_INT16U second);

GprsStateRetTypeDef ATcmdCSQ(void);
GprsStateRetTypeDef ATcmdCREG(void);
GprsStateRetTypeDef ATcmdCGREG(void);
GprsStateRetTypeDef ATSocketReceiveGetAssic (CPU_INT8U *pdata, CPU_INT8U len, CPU_INT8U socket);
GprsStateRetTypeDef ATSocketReceiveGetHex (CPU_INT8U *pdata, CPU_INT16U *len, CPU_INT16U max, CPU_INT8U socket);
GprsStateRetTypeDef ATcmdATEX (CPU_BOOL flag);
GprsStateRetTypeDef ATcmdSocketSendHexMode (void);

GprsStateRetTypeDef ATcmdSetSleep(CPU_INT16U timeout);
GprsStateRetTypeDef ATcmdWakeUp(void);


void GprsBuffInit (void);
void GprsBuffDataOut (CPU_INT8U *pdata, CPU_INT16U len, CPU_INT8U *err);
GprsTXQueueTypeDef GprsBuffDataIn (CPU_INT8U *pdata, CPU_INT16U len);
GprsStateFlagTypeDef GprsStateFlagGet (void);
void GprsStateFlagSet (GprsStateFlagTypeDef flag);

void GSMNetSelect (void);
GprsStateRetTypeDef ATcmdCERGQuery (CPU_INT8U *state);
GprsStateRetTypeDef ATcmdCOPSSearch (GSMNetTypeDef *net);
GprsStateRetTypeDef ATcmdCERGSet (void);
GprsStateRetTypeDef ATcmdCOPSSet (GSMNetNameTypeDef net);
GprsStateRetTypeDef ATcmdCOPSQuery (void);

//sms
GprsStateRetTypeDef ATcmdSetSMSDisindicate (void);
GprsStateRetTypeDef ATcmdSetSMSTXTMode (void);
GprsStateRetTypeDef ATcmdSetSMSMemeryLoc (void);
GprsStateRetTypeDef ATcmdRemoveAllSMS (void);
GprsStateRetTypeDef ATcmdRemoveIndexSMS (CPU_INT16U index);
GprsStateRetTypeDef ATcmdQuerySMSStatus (CPU_INT16U *sms_num, CPU_INT16U *max_num);
GprsStateRetTypeDef ATcmdGetSMSMessage (CPU_INT16U index, CPU_INT8U *pdata, CPU_INT16U *len);
GprsStateRetTypeDef ATcmdSMSModeSet (CPU_INT8U mode);
void GSMSmsDataGet (CPU_INT8U *pdata, CPU_INT16U *len);

void GprsSendStatusInit (void);
void GprsSendStatusGet (GprsSendStatusTypeDef *status);
void GprsSendStatusSet (GprsSendStatusTypeDef status);










/*************************************************************************************************
*                                           MODULE END                                           *
*************************************************************************************************/
#ifdef __cplusplus
}
#endif

#endif
