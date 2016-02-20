/*************************************************************************************************************
*                                              INCLUDE FILES                                                 *
*************************************************************************************************************/
#include <bsp.h>
#include <fifo.h>
#include <string.h>
#include <ucos_ii.h>
#include <queue.h>
#include <util.h>

#include <gnss.h>

/*************************************************************************************************************
*                                              GLOBLE TABLES                                                  *
*************************************************************************************************************/
extern OS_EVENT *InmarsatRxMsg;


/*************************************************************************************************************
*                                              LOCAL TABLES                                                  *
*************************************************************************************************************/
static unsigned char InmarsatMsgPayloadTag = 0x06;
static sInmarsatMsgDataTypeDef InmarsatMsgData;
static unsigned char InmarsatRxMsgFIFO[INMARSAT_RX_MSG_FIFO_SIZE + FIFO_INFO_SIZE];
static CPU_BOOL InmarsatRxFlag = DEF_OFF;
static CPU_INT8U InmarsatGPSData[256];


/*************************************************************************************************************
*                                            FUNCTION PROTOTYPES                                             *
*************************************************************************************************************/
void InmarsatInit (void)
{
    QueueInit(&InmarsatMsgData.queue);
    FIFOInit((FIFODataTypeDef *)InmarsatRxMsgFIFO);
    InmarsatMsgData.flag = 0;
    GNSSPackageInit((sGnssPackageTypeDef *)InmarsatGPSData);
}

void InmarsatMsgToASCII (const unsigned char *msg, unsigned short len, unsigned char *pdata, unsigned short *plen)
{
    unsigned short count;

    count = 0;
    for (unsigned int i =0; i < len; i++)
    {
        pdata[count++] = (((msg[i] >> 4) & 0x0F) < 0x0A) ? ((msg[i] >> 4) & 0x0F) + 0x30 : ((msg[i] >> 4) & 0x0F) + 0x37;
        pdata[count++] = ((msg[i] & 0x0F) < 0x0A) ? (msg[i] & 0x0F) + 0x30 : (msg[i] & 0x0F) + 0x37;
    }

    *plen = count;
}

void InmarsatMsgToHex (const unsigned char *msg, unsigned short len, unsigned char *pdata, unsigned short *plen)
{
    unsigned short count;
    unsigned char  hex_h;
    unsigned char  hex_l;

    count = 0;
    for (unsigned int i =0; i < len / 2; i++)
    {
        hex_h = (msg[i * 2] > 0x39) ? msg[i * 2] - 0x37 : msg[i * 2] - 0x30;
        hex_l = (msg[i * 2 + 1] > 0x39) ? msg[i * 2 + 1] - 0x37 : msg[i * 2 + 1] - 0x30;
        pdata[count++] = ((hex_h & 0x0F) << 4) | (hex_l & 0x0F);
    }

    *plen = count;
}

unsigned short InmarsatCheckSum (const unsigned char *pdata, unsigned short len)
{
    unsigned short checksum;

    checksum = 0;
    for (unsigned int i =1; i < len; i++)
    {
        checksum += pdata[i];
    }

    checksum = ~checksum;

    return checksum;
}

void InmarsatAddEscapeSymbol (const unsigned char *package, unsigned short len, unsigned char *buff, unsigned short *buff_len)
{
    unsigned short count;

    count = 0;

    buff[count++] = package[0];
    buff[count++] = package[1];

    for (unsigned short i = 2; i < len - 1; i++)
    {
        switch(package[i])
        {
            case 0x01:	buff[count++] = 0x10;
                        buff[count++] = 0x21;
                        break;
            case 0x04:	buff[count++] = 0x10;
                        buff[count++] = 0x24;
                        break;
            case 0x10:	buff[count++] = 0x10;
                        buff[count++] = 0x30;
                        break;
            case 0x11:	buff[count++] = 0x10;
                        buff[count++] = 0x31;
                        break;
            case 0x13:	buff[count++] = 0x10;
                        buff[count++] = 0x13;
                        break;
            default:	buff[count++] = package[i];
                        //break;
        }	
    }

    buff[count++] = package[len - 1];

    *buff_len = count;
}

void InmarsatRemoveEscapeSymbol (const unsigned char *package, unsigned short len, unsigned char *buff, unsigned short *buff_len)
{
    unsigned short count;

    count = 0;

    buff[count++] = package[0];
    buff[count++] = package[1];

    for (unsigned short i = 2; i < len - 1; i++)
    {
        if (package[i] == 0x10)
        {
            i++;
            switch(package[i])
            {
                    case 0x21:	buff[count++] = 0x01;
                                            break;
                    case 0x24:	buff[count++] = 0x04;
                                            break;
                    case 0x30:	buff[count++] = 0x10;
                                            break;
                    case 0x31:	buff[count++] = 0x11;
                                            break;
                    case 0x33:	buff[count++] = 0x13;
                                            break;
                    default:	break;
            }	
        }
        else
        {
                buff[count++] = package[i];
        }
    }

    buff[count++] = package[len - 1];

    *buff_len = count;
}

unsigned char InmarsatSendMsg (const unsigned char *msg, unsigned short msg_len)//, unsigned char *pdata, unsigned short *pdata_len)
{
    unsigned char  msg_package[INMARSAT_MSG_PACKAGE_MAX_SIZE];
    unsigned char  msg_buff[INMARSAT_MSG_BUFF_MAX_SIZE];
    unsigned char  msg_data[INMARSAT_MSG_PACKAGE_MAX_SIZE];
    unsigned char  *p;
    unsigned short len;
    unsigned short buff_len;
    unsigned short data_len;
    unsigned int   count;
    sInmarsatHeadTypeDef *head;
    sInmarsatMsgPayloadTypeDef *payload;
    sInmarsatMsgTxParaTypeDef *para;
    sInmarsatMsgTxParaDataATypeDef *data_a;
    sInmarsatMsgTxParaDataBTypeDef *data_b;
    sInmarsatTailTypeDef *tail;
    sInmarsatMsgTypeDef *item;
    void *temp;
    
    InmarsatMsgToASCII(msg, msg_len, msg_data, &data_len);
    
    len = INMARSAT_MSG_PAYLOAD_LEN + INMARSAT_MSG_TX_PARA_LEN + data_len;
    
    //*pdata_len = len;
    
    //InmarsatMsgPayloadTag++;
    
    head = (sInmarsatHeadTypeDef *)msg_package;
    
    head->soh    = INMARSAT_SOH;
    head->prefix = INMARSAT_PREFIX_TERMINAL;
    head->length = NToHS(len);
    
    payload = (sInmarsatMsgPayloadTypeDef *)&head->payload;
    
    payload->pyd_class = INMARSAT_MSG_CLASS;
    payload->pyd_type  = INMARSAT_MSG_TYPE_SEND;
    payload->pyd_tag   = InmarsatMsgPayloadTag;
    
    para = (sInmarsatMsgTxParaTypeDef *)&payload->pyd_para;
    
    para->map         = NToHS(INMARSAT_MSG_TX_PARA_MAP);
    para->control     = NToHS(INMARSAT_MSG_TX_PARA_CONTROL);
    para->time        = NToHL(INMARSAT_MSG_TX_PARA_TIME);
    para->life        = NToHL(INMARSAT_MSG_TX_PARA_LIFE);
    para->reserved[0] = 0x00;
    para->reserved[1] = 0x00;
    para->reserved[2] = 0x00;
    para->word        = INMARSAT_MSG_TX_PARA_WORD;
    para->address     = INMARSAT_MSG_TX_PARA_ADDRESS;
    para->descriptor  = INMARSAT_MSG_TX_PARA_DESCRIPTOR;
    
    data_a = (sInmarsatMsgTxParaDataATypeDef *)&para->data;
    
    data_a->len = INMARSAT_MSG_TX_PARA_DATA_A_LEN;
    
    data_b = (sInmarsatMsgTxParaDataBTypeDef *)&data_a->data;
    
    data_b->len = NToHS(data_len);
    memcpy(&data_b->data, msg_data, data_len);
    
    p = (unsigned char *)&data_b->data;
    
    tail = (sInmarsatTailTypeDef *)&p[data_len];
    
    tail->checksum = NToHS(InmarsatCheckSum(msg_package, INMARSAT_HEAD_LEN + len));
    tail->eot      = INMARSAT_EOT;
    
    InmarsatAddEscapeSymbol(msg_package, INMARSAT_HEAD_LEN + len + INMARSAT_TAIL_LEN, msg_buff, &buff_len);
    
    count = 0;
    while (InmarsatMsgData.flag == 1)
    {
        count++;
        if (count == 100)
        {
                return 1;
        }

        OSTimeDly(10);
    }
    
    QueueIn(&InmarsatMsgData.queue, &temp, sizeof(sInmarsatMsgTypeDef), INMARSAT_MSG_QUEUE_SIZE);
    item = (sInmarsatMsgTypeDef *)temp;
    
    item->len = buff_len;
    memcpy(item->data, msg_buff, buff_len);
    
    //*pdata_len = buff_len;
    //memcpy(pdata, msg_buff, buff_len);
    
    return 0;
}

void InmarsatPackageSendMsg (const unsigned char *msg, unsigned short msg_len, unsigned char *pdata, unsigned short *pdata_len)
{
    unsigned char  msg_package[INMARSAT_MSG_PACKAGE_MAX_SIZE];
    unsigned char  msg_buff[INMARSAT_MSG_BUFF_MAX_SIZE];
    unsigned char  msg_data[INMARSAT_MSG_PACKAGE_MAX_SIZE];
    unsigned char  *p;
    unsigned short len;
    unsigned short buff_len;
    unsigned short data_len;
//    unsigned int   count;
    sInmarsatHeadTypeDef *head;
    sInmarsatMsgPayloadTypeDef *payload;
    sInmarsatMsgTxParaTypeDef *para;
    sInmarsatMsgTxParaDataATypeDef *data_a;
    sInmarsatMsgTxParaDataBTypeDef *data_b;
    sInmarsatTailTypeDef *tail;
//    sInmarsatMsgTypeDef *item;
//    void *temp;

    InmarsatMsgToASCII(msg, msg_len, msg_data, &data_len);
    
    len = INMARSAT_MSG_PAYLOAD_LEN + INMARSAT_MSG_TX_PARA_LEN + data_len;
    
    //*pdata_len = len;
    
    //InmarsatMsgPayloadTag++;
    
    head = (sInmarsatHeadTypeDef *)msg_package;
    
    head->soh    = INMARSAT_SOH;
    head->prefix = INMARSAT_PREFIX_TERMINAL;
    head->length = NToHS(len);
    
    payload = (sInmarsatMsgPayloadTypeDef *)&head->payload;
    
    payload->pyd_class = INMARSAT_MSG_CLASS;
    payload->pyd_type  = INMARSAT_MSG_TYPE_SEND;
    payload->pyd_tag   = InmarsatMsgPayloadTag;
    
    para = (sInmarsatMsgTxParaTypeDef *)&payload->pyd_para;
    
    para->map         = NToHS(INMARSAT_MSG_TX_PARA_MAP);
    para->control     = NToHS(INMARSAT_MSG_TX_PARA_CONTROL);
    para->time        = NToHL(INMARSAT_MSG_TX_PARA_TIME);
    para->life        = NToHL(INMARSAT_MSG_TX_PARA_LIFE);
    para->reserved[0] = 0x00;
    para->reserved[1] = 0x00;
    para->reserved[2] = 0x00;
    para->word        = INMARSAT_MSG_TX_PARA_WORD;
    para->address     = INMARSAT_MSG_TX_PARA_ADDRESS;
    para->descriptor  = INMARSAT_MSG_TX_PARA_DESCRIPTOR;
    
    data_a = (sInmarsatMsgTxParaDataATypeDef *)&para->data;
    
    data_a->len = INMARSAT_MSG_TX_PARA_DATA_A_LEN;
    
    data_b = (sInmarsatMsgTxParaDataBTypeDef *)&data_a->data;
    
    data_b->len = NToHS(data_len);
    memcpy(&data_b->data, msg_data, data_len);
    
    p = (unsigned char *)&data_b->data;
    
    tail = (sInmarsatTailTypeDef *)&p[data_len];
    
    tail->checksum = NToHS(InmarsatCheckSum(msg_package, INMARSAT_HEAD_LEN + len));
    tail->eot      = INMARSAT_EOT;
    
    InmarsatAddEscapeSymbol(msg_package, INMARSAT_HEAD_LEN + len + INMARSAT_TAIL_LEN, msg_buff, &buff_len);
    
//    count = 0;
//    while (InmarsatMsgData.flag == 1)
//    {
//        count++;
//        if (count == 100)
//        {
//                return 1;
//        }
//
//        OSTimeDly(10);
//    }
    
//    QueueIn(&InmarsatMsgData.queue, &temp, sizeof(sInmarsatMsgTypeDef), INMARSAT_MSG_QUEUE_SIZE);
//    item = (sInmarsatMsgTypeDef *)temp;
//    
//    item->len = buff_len;
//    memcpy(item->data, msg_buff, buff_len);
    
    *pdata_len = buff_len;
    memcpy(pdata, msg_buff, buff_len);
    
//    count = count;
//    item = item;
//    temp = temp;
    
//    return 0;
}

CPU_INT8U InmarsatPackageSend (CPU_INT8U *pdata, CPU_INT16U *len)
{
    sInmarsatMsgTypeDef *item;
    void *temp;
    CPU_INT8U ret;
    
    ret = 0;
    InmarsatMsgData.flag = 1;
    if (QueueIsEmpty(&InmarsatMsgData) == 0) 
    {
        QueueOut(&InmarsatMsgData.queue, &temp, sizeof(sInmarsatMsgTypeDef), INMARSAT_MSG_QUEUE_SIZE);
        item = (sInmarsatMsgTypeDef *)temp;
        *len = item->len;       
        memcpy(pdata, item->data, item->len);
    
        ret = 1;
    }
    InmarsatMsgData.flag = 0;
    
    return ret;
}

void InmarsatReceiveProcess (const unsigned char *pdata, unsigned short len)
{
    unsigned char  msg_buff[INMARSAT_MSG_PACKAGE_MAX_SIZE];
    unsigned char  msg_data[INMARSAT_MSG_PACKAGE_MAX_SIZE];
    unsigned char  msg[INMARSAT_MSG_PACKAGE_MAX_SIZE];
    unsigned short i;
    unsigned short data_len;
    unsigned short buff_len;
    unsigned short msg_len;
    unsigned short checksum;
    sInmarsatHeadTypeDef *head;
    sInmarsatMsgPayloadTypeDef *payload;
    sInmarsatMsgRxParaTypeDef *para;
    sInmarsatMsgGPSParaTypeDef *gps;
    unsigned char  *p;
   // unsigned char  byte;
    
    head = (sInmarsatHeadTypeDef *)msg_buff;
    payload = (sInmarsatMsgPayloadTypeDef *)&head->payload;
    para = (sInmarsatMsgRxParaTypeDef *)&payload->pyd_para;
    gps = (sInmarsatMsgGPSParaTypeDef *)&payload->pyd_para;
    
    InmarsatRemoveEscapeSymbol(pdata, len, msg_buff, &buff_len);
    
    checksum = ((unsigned short)pdata[len - 3]  << 8) | (unsigned short)pdata[len - 2];
    
    if (checksum == InmarsatCheckSum(msg_buff, buff_len - INMARSAT_TAIL_LEN))
    {
        if ((payload->pyd_class == 0xD5) && (payload->pyd_type == 0x02))
        {
            OSTimeDly(10);
        }
    
        if ((payload->pyd_class == 0xD3) && (payload->pyd_type == 0x24))
        {
            if (InmarsatRxFlag == DEF_ON)
            {
                OSMboxPost(InmarsatRxMsg, &InmarsatRxFlag);
            }
        }
    
        if ((payload->pyd_class == 0xD5) && (payload->pyd_type == 0x07))
        {
            p = (unsigned char *)&para->data;
    
            data_len = 0;
            for (i = 0; i < NToHS(para->len) / 2; i++)
            {  
                    msg_data[data_len++] = (p[i * 2] << 4) | p[i * 2 + 1];
    
                    //FIFOIn((FIFODataTypeDef *)InmarsatRxMsgFIFO, &byte, INMARSAT_RX_MSG_FIFO_SIZE);
            }
    
            InmarsatMsgToHex(msg_data, data_len, msg, &msg_len);
    
            for (i = 0; i < msg_len; i++)
            {  
                    FIFOIn((FIFODataTypeDef *)InmarsatRxMsgFIFO, &msg[i], INMARSAT_RX_MSG_FIFO_SIZE);
            }
        }
        
        if ((payload->pyd_class == 0xD6) && (payload->pyd_type == 0x02))
        {
            //if (gps->map == 0x05)
            //{

            GNSSPackegReceive((sGnssPackageTypeDef *)InmarsatGPSData, &gps->data, NToHS(head->length) - INMARSAT_MSG_GPS_HEAD_LEN);

            //}
        }
    }
}


void InmarsatReceivePackageInit (sInmarsatPackageTypeDef *package)
{
    package->flag  = 0;
    package->count = 0;
}

void InmarsatPackageReceive (sInmarsatPackageTypeDef *package, CPU_INT8U *pdata, CPU_INT16U len)
{
/*
    sInmarsatHeadTypeDef *head;
    
    head = (sInmarsatHeadTypeDef *)package->data;
*/    
    for (unsigned short i = 0; i < len; i++)
    {
        if ((pdata[i] == INMARSAT_SOH) && (package->flag == 0))
        {
            package->flag = 1;
            package->count = 0;
        }
            
        if (package->flag == 1)
        {
            package->data[package->count] = pdata[i];

            if (package->data[package->count] == INMARSAT_EOT)
            {
                InmarsatReceiveProcess((unsigned char *)(&package->data), package->count + 1);
                package->flag = 0;
            }

            package->count++;
        }
    }
}

unsigned char InmarsatRxMsgFIFOIsEmpty (void)
{
    return FIFOIsEmpty((FIFODataTypeDef *)InmarsatRxMsgFIFO);
}

unsigned char InmarsatRxMsgData (void)
{
    unsigned char byte;
    
    FIFOOut((FIFODataTypeDef *)InmarsatRxMsgFIFO, &byte, INMARSAT_RX_MSG_FIFO_SIZE);
    
    return byte;
}


void InmarsatComRxFIFOClear (void)
{
    while (!InmarsatRxMsgFIFOIsEmpty())
    {
        InmarsatRxMsgData();
    }       
}
void InmarsatMsgDataOut (CPU_INT8U *pdata, CPU_INT16U len, CPU_INT8U *err)
{
    CPU_INT8U send_data[INMARSAT_DATA_MAX_SIZE];
    CPU_INT16U send_len;
    //CPU_INT8U count;
    CPU_INT8U time_count;  
    CPU_INT8U status;
       
    InmarsatPackageSendMsg(pdata, len, send_data, &send_len);

    InmarsatComRxFIFOClear();
    InmarsatRxFlag = DEF_ON;
    time_count = 0;
    
    COM4SendData(send_data, send_len);
    
    while (1)
    {
        OSMboxPend(InmarsatRxMsg, 1000, &status);
        time_count++;
        if ((time_count > 180) || (err == OS_NO_ERR))
        {
            break;
        }
    }
    
    InmarsatRxFlag = DEF_OFF;
    
}


/*************************************************************************************************************
*                                               MODULE END                                                   *
*************************************************************************************************************/



//Inmarsat device info request 
/*#define CLASS_REQUEST              0xD3
#define TYPE_REQUEST_SNR           0x94

  
int InmarsatAddEscapeSymbol(int len, unsigned char * databeforeaddescape, unsigned char * dataaferaddescape)
{   
	int length=0;
	unsigned char * source      = databeforeaddescape;
	unsigned char * destination = dataaferaddescape;
	//The transfor of SOH
	*destination = *source;
	source++;
	destination++;
	length++;
	//The transfor of message except SOH and EOT
	for(int i = 1; i < len-1; i++)
    {
	  switch(*source)
	  {
	   case 0x01: *destination = 0x10; destination++; *destination = 0x21; destination++; source++; length=length+ 2; break;
	   case 0x04: *destination = 0x10; destination++; *destination = 0x24; destination++; source++; length=length+ 2; break;
	   case 0x10: *destination = 0x10; destination++; *destination = 0x30; destination++; source++; length=length+ 2; break;         
	   case 0x11: *destination = 0x10; destination++; *destination = 0x31; destination++; source++; length=length+ 2; break;
       case 0x13: *destination = 0x10; destination++; *destination = 0x33; destination++; source++; length=length+ 2; break;
	   default:   *destination = *source; destination++; source++; length++;
	  }	
	}
	//The transfor of EOT
    *destination = *source;
	length++;

    return length;
}


int InmarsatSendMessage(int len,unsigned char * data,unsigned char * message)
{
  unsigned char data_package[512];
  int length;
  int framelength;
  sInmarsatMessageHeadTypeDef * head;
  sInmarsatMessagePayloadATypeDef * payloada;
  sInmarsatMessagePayloadBTypeDef * payloadb;
  sInmarsatMessageTailTypeDef * tail;
  
  unsigned short checksum;
  unsigned short staging;
  unsigned char * tmp;
  const unsigned char parameter[18]={0x00, 0x01, 0x00, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0E, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};
  
  memset(data_package,0x00,512);

  head = (sInmarsatMessageHeadTypeDef *)data_package;
  head->soh = START_OF_HEADER;
  head->prefix = PREFIX_TERMINAL_MESSAGE;
  head->message_length = 3+ 18 + 3+ 0 + len;
  head->message_length = HToNS(head->message_length);
  head->message_class = CLASS_MESSAGE;
  head->message_type = TYPE_SEND_MESSAGE;

  //head tag
  head->tag = 0xCC;

  memcpy(&head->parameters[0], parameter, 18);

  payloada = (sInmarsatMessagePayloadATypeDef *)&head->data;
  payloada->len = 0x00;
  payloadb = (sInmarsatMessagePayloadBTypeDef *)(&payloada->data + 0);
  payloadb->len = len;
  payloadb->len = HToNS(payloadb->len);
  if(len != 0x0000)
  {
	   memcpy(&payloadb->data, data, len);
  }
  length = 3+ 18 + 3+ 0 + len + 7;
 
  tail = (sInmarsatMessageTailTypeDef *)(&payloadb->data+ len);

  tmp = (unsigned char *)&head->prefix;
  staging = 0x0000;
   
  while(tmp != (unsigned char *)tail)
  {
	
    staging = staging + *tmp;
	tmp++;
  }
  
  checksum = 0xFFFF - staging;
  tail->checksum = HToNS(checksum);
  tail->eot = EOT;
   
  framelength = InmarsatAddEscapeSymbol(length,data_package,message);
  return framelength;
}


void InmarsatDump(int len, unsigned char * data)
{
  printf("\n before dump \n");
  for(int i =0; i < len; i++)
  {
     printf("%x ",*(data+i));
  }
}




unsigned short InmarsatCalChecksum(unsigned char * head, unsigned char * tail)
{
  unsigned char * tmp = head+1;
  unsigned short result = 0x0000;
  while(tmp != tail){
      result = result + *tmp;
	  tmp++;
  }

  result = 0xFFFF - result;
  result = HToNS(result);
  return result;
}
void InmarsatRequestDeviceInfo()
{ 
  int len = 10;
  unsigned char request[16];
  unsigned char request_addescape[32];
  sInmarsatRequestDeviceInfoHeadTypeDef * head;
  sInmarsatRequestDeviceInfoTailTypeDef * tail;
  
  head = (sInmarsatRequestDeviceInfoHeadTypeDef *)request;
  head->soh     = START_OF_HEADER;
  head->prefix  = PREFIX_TERMINAL_MESSAGE;
  head->request_length = 3u;
  head->request_length = HToNS(head->request_length);
  head->request_class = CLASS_REQUEST;
  head->request_type = TYPE_REQUEST_SNR;
  head->tag = 0xA3;
  
  tail = (sInmarsatRequestDeviceInfoTailTypeDef *)(&head->tag + 1);
  tail->checksum = InmarsatCalChecksum((unsigned char *)&head->soh,(unsigned char *)&tail->checksum);
  tail->eot = EOT;

  
  
  for(int i = 0; i<len;i++){
     printf("%x ",request[i]);
  }
  InmarsatDump(10,request);

  int length = InmarsatAddEscapeSymbol(len, request, request_addescape);
  InmarsatDump(length, request_addescape);
}

int InmarsatRemoveEscapeSymbol(int len,unsigned char *datawithescape, unsigned char *datawithoutescape)
{
  unsigned char * source = datawithescape;
  unsigned char * destination = datawithoutescape;
  unsigned char * head;
  unsigned char * tail;
  unsigned char * tmp;
  int length = 0;
  tmp = source;
  //find the head of the frame
  for(int i=0; i<len; i++)
  {
	  if(*tmp == START_OF_HEADER)
	  {   head = tmp;
		  break;
	  } else {
	     tmp++;
	  }
  }
  
  printf("before get tail \n");
  tmp=source;
  //find the tail of the frame;
  for(int j=0; j<len; j++)
  {
	  if(*tmp == EOT)
	  {
	    tail = tmp;
		break;
	  } else {
	    tmp++;
	  } 
  }
  
  
  printf("-- head is %d \n",head);
  printf("-- tail is %d \n",tail);
  printf("--- the value of head %x \n", *head);
  printf("--- the value of tail %x \n", *tail);
  
  *destination = *head;
  destination++;
  head++;
  length++;
  while( head != tail)
  {
	  if(*head != 0x10)
	  {
	    *destination = *head;
        destination++;
		head++;
		length++;
	  } else {
	    switch(*(head+1))
		{
		 case 0x21: *destination = 0x01; destination++; head= head+ 2; length++; break;
		 case 0x24: *destination = 0x04; destination++; head= head+ 2; length++; break;
		 case 0x30: *destination = 0x10; destination++; head= head+ 2; length++; break;
		 case 0x31: *destination = 0x11; destination++; head= head+ 2; length++; break;
		 case 0x33: *destination = 0x13; destination++; head= head+ 2; length++; break;
		 default: *destination = *head; destination++; head++; length++;
		}
	  }
  }
  *destination = *tmp;
  length++;
  
  printf("---- the length is %d \n",length);
  InmarsatDump(length, datawithoutescape);
  return length;
}*/