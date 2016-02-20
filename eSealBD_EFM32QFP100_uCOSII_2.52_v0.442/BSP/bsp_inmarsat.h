/*************************************************************************************************************
*                                                  MODULE                                                    *
*************************************************************************************************************/
#ifndef INMARSAT_H
#define INMARSAT_H

#ifdef __cplusplus
extern "C" {
#endif


/*************************************************************************************************************
*                                                 DEFINES                                                    *
*************************************************************************************************************/
#define INMARSAT_SOH                            0x01
#define INMARSAT_PREFIX_TERMINAL                0x03
#define INMARSAT_EOT                            0x04

#define INMARSAT_MSG_CLASS                      0x05
#define INMARSAT_MSG_TYPE_SEND                  0xC2

#define INMARSAT_MSG_TX_PARA_MAP                0x0001
#define INMARSAT_MSG_TX_PARA_CONTROL            0x1000
#define INMARSAT_MSG_TX_PARA_TIME               0x00000000
#define INMARSAT_MSG_TX_PARA_LIFE               0x00000E10
#define INMARSAT_MSG_TX_PARA_WORD               0x00
#define INMARSAT_MSG_TX_PARA_ADDRESS            0x00
#define INMARSAT_MSG_TX_PARA_DESCRIPTOR         0x00
#define INMARSAT_MSG_TX_PARA_DATA_A_LEN         0u

#define INMARSAT_HEAD_LEN		                4u
#define INMARSAT_TAIL_LEN		                3u

#define INMARSAT_MSG_PAYLOAD_LEN                3u
#define INMARSAT_MSG_TX_PARA_LEN                21u
#define INMARSAT_MSG_GPS_HEAD_LEN               6u

#define INMARSAT_MSG_DATA_A_MAX_SIZE            23u
#define INMARSAT_MSG_DATA_B_MAX_SIZE	        200u

#define INMARSAT_MSG_PACKAGE_MAX_SIZE	        256u
#define INMARSAT_MSG_BUFF_MAX_SIZE	        512u
#define INMARSAT_MSG_QUEUE_SIZE		        1u
#define INMARSAT_RX_MSG_FIFO_SIZE               1024u  

#define INMARSAT_DATA_MAX_SIZE                  512u

    
/*************************************************************************************************************
*                                                  DATA TYPES                                                *
*************************************************************************************************************/
#pragma pack(1)

typedef struct
{
    unsigned char  soh;
    unsigned char  prefix;
    unsigned short length;
    unsigned char  payload;
} sInmarsatHeadTypeDef;

typedef struct
{
    unsigned char  pyd_class;
    unsigned char  pyd_type;
    unsigned char  pyd_tag;
    unsigned char  pyd_para;
} sInmarsatMsgPayloadTypeDef;

typedef struct
{
    unsigned short map;
    unsigned short control;
    unsigned int   time;
    unsigned int   life;
    unsigned char  reserved[3];
	unsigned char  word;
	unsigned char  address;
	unsigned char  descriptor;
	unsigned char  data;
} sInmarsatMsgTxParaTypeDef;

typedef struct
{
    unsigned char  map;
    unsigned char  reserved[2];
    unsigned char  data;
} sInmarsatMsgGPSParaTypeDef;

typedef struct
{
    unsigned short sn;
    unsigned char  state;
    unsigned char  isn;
    unsigned int   time;
    unsigned char  type;
	unsigned char  number;
	unsigned char  sub;
	unsigned short len;
	unsigned char  data;
} sInmarsatMsgRxParaTypeDef;

typedef struct
{
    unsigned char len;
    unsigned char data;
} sInmarsatMsgTxParaDataATypeDef;

typedef struct
{
    unsigned short len;
    unsigned char  data;
} sInmarsatMsgTxParaDataBTypeDef;

typedef struct 
{
    unsigned short checksum;
    unsigned char  eot;
} sInmarsatTailTypeDef;

typedef struct
{
    unsigned short len;
    unsigned char  data[INMARSAT_MSG_BUFF_MAX_SIZE];
} sInmarsatMsgTypeDef;

typedef struct 
{
    unsigned int front;
    unsigned int rear; 
    unsigned int count;
    sInmarsatMsgTypeDef item[INMARSAT_MSG_QUEUE_SIZE];       
} sInmarsatMsgQueueTypeDef;

typedef struct 
{
    sInmarsatMsgQueueTypeDef queue;
    unsigned char flag;
} sInmarsatMsgDataTypeDef;

typedef struct
{
    unsigned char  flag;
    unsigned short count;
    unsigned char  data[INMARSAT_MSG_BUFF_MAX_SIZE];
} sInmarsatPackageTypeDef;


#pragma pack()


/*************************************************************************************************************
*                                            FUNCTION STATEMENT                                              *
*************************************************************************************************************/
void InmarsatInit (void);
unsigned char InmarsatSendMsg (const unsigned char *msg, unsigned short msg_len);//, unsigned char *pdata, unsigned short *pdata_len);
void InmarsatPackageSendMsg (const unsigned char *msg, unsigned short msg_len, unsigned char *pdata, unsigned short *pdata_len);
unsigned char InmarsatPackageSend (unsigned char *pdata, unsigned short *len);
void InmarsatReceivePackageInit (sInmarsatPackageTypeDef *package);
void InmarsatPackageReceive (sInmarsatPackageTypeDef *package, unsigned char *pdata, unsigned short len);
unsigned char InmarsatRxMsgFIFOIsEmpty (void);
unsigned char InmarsatRxMsgData (void);
void InmarsatComRxFIFOClear (void);
void InmarsatMsgDataOut (CPU_INT8U *pdata, CPU_INT16U len, CPU_INT8U *err);


/*************************************************************************************************************
*                                               MODULE END                                                   *
*************************************************************************************************************/
#ifdef __cplusplus
}
#endif

#endif
