/*************************************************************************************************************
*                                                  MODULE                                                    *
*************************************************************************************************************/
#ifndef GPRS_H
#define GPRS_H

#ifdef __cplusplus
extern "C" {
#endif

  
/*************************************************************************************************************
*                                                 DEFINES                                                    *
*************************************************************************************************************/  
#define AT_CMD_ERROR                            0
#define AT_CMD_OK                               1
#define AT_CMD_TIME_OUT                         2
  
#define GPRS_PROCESS_OK                         0 
#define GPRS_PROCESS_ERROR                      1
#define GPRS_PROCESS_INVALID                    2
#define GPRS_PROCESS_TIME_OUT                   3  
#define GPRS_PROCESS_RESTART                    4 
    
#define GPRS_STATE_CREG_QUERY                   0
#define GPRS_STATE_CREG_SET                     1
#define GPRS_STATE_COPS_SEARCH                  2
#define GPRS_STATE_COPS_SET                     3
#define GPRS_STATE_COPS_QUERY                   4

#define GPRS_STATE_AT                           0  
#define GPRS_STATE_ATEX                         1
#define GPRS_STATE_ZIPTIMEOUT                   2
#define GPRS_STATE_ZSTR                         3
#define GPRS_STATE_ZPPPSTATUS                   4	
#define GPRS_STATE_ZPPPOPEN                     5
#define GPRS_STATE_ZIPSTATUS                    6
#define GPRS_STATE_ZIPSETUP                     7
#define GPRS_STATE_RESTART                      8
  
#define GPRS_DEST_IP_ADDRESS                    (59ul << 24) | (78ul << 16) | (192ul << 8) | 18ul
#define GPRS_DEST_PORT                          19000
#define GPRS_DEST_N                             3
#define GPRS_LINK_TYPE_TCP                      0 
#define GPRS_LINK_TYPE_UDP                      1
  
#define GPRS_DISPLAY_SWITCH                     DEF_ON
#define GPRS_CONNECT_TIMEOUT                    20
#define GPRS_SEND_DATA_TIMEOUT                  30  
  

/*************************************************************************************************************
*                                                  DATA TYPES                                                *
*************************************************************************************************************/
typedef struct 
{   
    CPU_INT32U ip;
    CPU_INT16U port;
    CPU_INT8U  n;
    CPU_INT8U  type; 
} IPDataTypeDef;

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


/*************************************************************************************************************
*                                            FUNCTION STATEMENT                                              *
*************************************************************************************************************/
void GSMInit (void);
void GSMPowerOn (void);
void GSMPowerOff (void);
void GSMReset (void);
void GSMRestart (void);
void ClearUart1FIFO (void);
void GSMProcess (IPDataTypeDef* gprs_set, CPU_INT8U state);
CPU_INT8U GetATReply(CPU_INT8U *pdata, CPU_INT16U delay, CPU_INT16U len);
CPU_INT8U ATcmdAT (void);
CPU_INT8U ATcmdATEX (CPU_BOOL flag);
CPU_INT8U ATcmdZIPTIMEOUT (CPU_INT8U connect_timeout, CPU_INT8U send_data_timeout);
CPU_INT8U ATcmdZSTR (void);
CPU_INT8U ATcmdZPPPSTATUS (void);
CPU_INT8U ATcmdZPPPOPEN (void);
CPU_INT8U ATcmdZEDT (void);
CPU_INT8U ATcmdZIPSTATUS (CPU_INT8U n);
CPU_INT8U ATcmdZIPSETUP (CPU_INT8U n, CPU_INT32U ip, CPU_INT16U port);
CPU_INT8U ATcmdZIPSEND (CPU_INT8U n, CPU_INT16U len);
void GPRSWakeUpMode (void);
void GPRSWakeUpModeEXIT (void);
CPU_INT8U ATcmdCERGQuery (void);
CPU_INT8U ATcmdCOPSSearch (GSMNetTypeDef *net);
CPU_INT8U ATcmdCERGSet (void);
CPU_INT8U ATcmdCOPSSet (GSMNetNameTypeDef net);
CPU_INT8U ATcmdCOPSQuery (void);

/*************************************************************************************************************
*                                               MODULE END                                                   *
*************************************************************************************************************/
#ifdef __cplusplus
}
#endif

#endif
