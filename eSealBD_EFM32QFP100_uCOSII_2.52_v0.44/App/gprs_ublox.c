/*************************************************************************************************************
*                                              INCLUDE FILES                                                 *
*************************************************************************************************************/
#include <app.h>
#include <includes.h>

/*************************************************************************************************************
*                                            GLOBAL VARIABLES                                                *
*************************************************************************************************************/
extern OS_EVENT *GprsAckMsg;


/*************************************************************************************************************
*                                            GLOBAL FUNTION                                                *
*************************************************************************************************************/
extern void GprsTaskReset();


/*************************************************************************************************************
*                                            LOCAL VARIABLES                                                 *
*************************************************************************************************************/
static CPU_INT8U GrpsSocketNumBuffer = 0;
static CPU_BOOL USPDAFlag = DEF_ON;
static sGprsDataTypeDef GprsData;
static GprsStateFlagTypeDef GprsStateFlag = GPRS_GPRS_STATE_FREE;;
static CPU_BOOL GprsStatus = DEF_OFF;
static CPU_INT16U ATcmdParaConvertToHex (CPU_INT8U *pdata, CPU_INT8U len);
static GprsSendStatusTypeDef GprsSendStatus;


/*************************************************************************************************************
*                                              INCLUDE FILES                                                 *
*************************************************************************************************************/
void GprsSendStatusInit (void)
{
    GprsSendStatus.send_tick = 0;
    GprsSendStatus.rec_tick = 0;    
    GprsSendStatus.rec_flag = DEF_OFF;
    GprsSendStatus.send_flag = DEF_OFF;
}

void GprsSendStatusGet (GprsSendStatusTypeDef *status)
{
    *status = GprsSendStatus;
}

void GprsSendStatusSet (GprsSendStatusTypeDef status)
{
    GprsSendStatus = status;
}

void GprsProcessUblox (GprsStateTypeDef init)
{    
    CPU_BOOL flag;
    CPU_BOOL connect_flag;
    GprsStateRetTypeDef replay;
    CPU_INT16U gprs_restart;
    GprsStateTypeDef state;
    CPU_INT8U buffer;
    state = init;
    
    //gprs_flag = DEF_ON;
    flag = DEF_ON;
    connect_flag = DEF_ON;
    gprs_restart = 0;
    
    while (flag)
    {
        switch (state)
        {
            case GPRS_STATE_AT_CHECK:   replay = ATcmdAT();
                                        if (replay == GPRS_PROCESS_OK)
                                        {
                                            state = GPRS_STATE_ATEX_SET;
                                        }
                                        else if (replay == GPRS_PROCESS_ERROR)
                                        {   
                                            state = GPRS_STATE_RESTART;
                                        }
                                        else if (replay == GPRS_PROCESS_TIME_OUT)
                                        {
                                            state = GPRS_STATE_RESTART;
                                        }
                                        break;
            case GPRS_STATE_ATEX_SET:   replay = ATcmdATEX(GPRS_ECHO_SET);
                                        if (replay == GPRS_PROCESS_OK)
                                        {
                                            state = GPRS_STATE_SOCKET_HEX_SET;
                                        }
                                        else if (replay == GPRS_PROCESS_ERROR)
                                        {   
                                            state = GPRS_STATE_AT_CHECK;
                                        }
                                        else if (replay == GPRS_PROCESS_TIME_OUT)
                                        {
                                            state = GPRS_STATE_RESTART;
                                        }
                                        break;  
                                        
            case GPRS_STATE_SOCKET_HEX_SET:   replay = ATcmdSocketSendHexMode();
                                        if (replay == GPRS_PROCESS_OK)
                                        {
                                            state = GPRS_STATE_CARD_CHECK;
                                        }
                                        else if (replay == GPRS_PROCESS_ERROR)
                                        {   
                                            state = GPRS_STATE_AT_CHECK;
                                        }
                                        else if (replay == GPRS_PROCESS_TIME_OUT)
                                        {
                                            state = GPRS_STATE_RESTART;
                                        }
                                        break;
            case GPRS_STATE_CARD_CHECK: replay = ATcmdSIMState();
                                        if (replay == GPRS_PROCESS_OK)
                                        {
                                            state = GPRS_STATE_CSQ_CHECK;			
                                        }
                                        else if (replay == GPRS_PROCESS_ERROR)
                                        {
                                            state = GPRS_STATE_AT_CHECK;
                                        }
                                        else if (replay == GPRS_PROCESS_TIME_OUT)
                                        {
                                           // state = GPRS_STATE_AT_CHECK;
                                             state = GPRS_STATE_RESTART;
                                        }
                                        break;
            case GPRS_STATE_CSQ_CHECK:	replay = ATcmdCSQ();
                                        if (replay == GPRS_PROCESS_OK)
                                        {
                                            state = GPRS_STATE_SMS_SET_TXT;
                                        }
                                        else if (replay == GPRS_PROCESS_ERROR)
                                        {
                                            state = GPRS_STATE_AT_CHECK;
                                        }
                                        else if (replay == GPRS_PROCESS_TIME_OUT)
                                        {
                                            state = GPRS_STATE_AT_CHECK;
                                        }                                        
                                        break;  
            case GPRS_STATE_SMS_SET_TXT:	replay = ATcmdSetSMSTXTMode();
                                        if (replay == GPRS_PROCESS_OK)
                                        {
                                            state = GPRS_STATE_SMS_SET_LOC;
                                        }
                                        else if (replay == GPRS_PROCESS_ERROR)
                                        {
                                            state = GPRS_STATE_AT_CHECK;
                                        }
                                        else if (replay == GPRS_PROCESS_TIME_OUT)
                                        {
                                            state = GPRS_STATE_AT_CHECK;
                                        }                                        
                                        break;         
            case GPRS_STATE_SMS_SET_LOC:	replay = ATcmdSetSMSMemeryLoc();
                                        if (replay == GPRS_PROCESS_OK)
                                        {
                                            state = GPRS_STATE_SMS_SET_DISINDICATE;
                                        }
                                        else if (replay == GPRS_PROCESS_ERROR)
                                        {
                                            state = GPRS_STATE_AT_CHECK;
                                        }
                                        else if (replay == GPRS_PROCESS_TIME_OUT)
                                        {
                                            state = GPRS_STATE_AT_CHECK;
                                        }                                        
                                        break;
            case GPRS_STATE_SMS_SET_DISINDICATE:	replay = ATcmdSetSMSDisindicate();
                                        if (replay == GPRS_PROCESS_OK)
                                        {
                                            state = GPRS_STATE_CREG_CHECK;
                                        }
                                        else if (replay == GPRS_PROCESS_ERROR)
                                        {
                                            state = GPRS_STATE_AT_CHECK;
                                        }
                                        else if (replay == GPRS_PROCESS_TIME_OUT)
                                        {
                                            state = GPRS_STATE_AT_CHECK;
                                        }                                        
                                        break;
                                        
            case GPRS_STATE_CREG_CHECK:	replay = ATcmdCREG();
                                        if (replay == GPRS_PROCESS_OK)
                                        {
                                             state = GPRS_STATE_CGREG_CHECK;
                                             gprs_restart = 0;
                                        }
                                        else if (replay == GPRS_PROCESS_ERROR)
                                        {
                                            state = GPRS_STATE_CSQ_CHECK;
                                            gprs_restart++;
                                        }
                                        else if (replay == GPRS_PROCESS_TIME_OUT)
                                        {
                                            gprs_restart = 0;
                                            state = GPRS_STATE_AT_CHECK;
                                        } 
                                        break;

            case GPRS_STATE_CGREG_CHECK:replay = ATcmdCGREG();
                                        if (replay == GPRS_PROCESS_OK)
                                        {
                                             state = GPRS_STATE_USPDA_SET;
                                        }
                                        else if (replay == GPRS_PROCESS_ERROR)
                                        {
                                            state = GPRS_STATE_CSQ_CHECK;
                                        }
                                        else if (replay == GPRS_PROCESS_TIME_OUT)
                                        {
                                            state = GPRS_STATE_AT_CHECK;
                                        } 
                                        break;     
            case GPRS_STATE_USPDA_SET  :if (USPDAFlag == DEF_ON)
                                        {
                                            
                                            replay = ATcmdConnect();
                                            if (replay == GPRS_PROCESS_OK)
                                            {    
                                                 USPDAFlag = DEF_OFF;
                                                 state = GPRS_STATE_TCPIP_CREAT;
                                            }
                                            else if (replay == GPRS_PROCESS_ERROR)
                                            {
                                                state = GPRS_STATE_RESTART;
                                            }
                                            else if (replay == GPRS_PROCESS_TIME_OUT)
                                            {
                                                state = GPRS_STATE_AT_CHECK;
                                            }
                                            
                                        }
                                        else
                                        {
                                            state  = GPRS_STATE_TCPIP_CREAT;
                                        }
                                        
                                        break;                                         
            case GPRS_STATE_TCPIP_CREAT: replay = ATcmdTCPIPCreat(&buffer);
                                       
                                        if (replay == GPRS_PROCESS_OK) 
                                        {   
                                            if (GrpsSocketNumBuffer != buffer)
                                            {
                                                ATcmdTCPIPClose(GrpsSocketNumBuffer);
                                            }
                                            //SocketDelFlag = DEF_OFF;
                                            GrpsSocketNumBuffer = buffer;
                                            
                                            GprsSendStatusInit();
                                            
                                            connect_flag = DEF_ON;
                                            
                                            state = GPRS_STATE_TCPIP_SET;
                                            
                                            gprs_restart = 0;
                                        }
                                        else if (replay == GPRS_PROCESS_ERROR)
                                        {
                                             //GprsStatus = DEF_OFF;
                                            ATcmdTCPIPClose(GrpsSocketNumBuffer);
                                            
                                            ////////////20140528///////////////////
                                            state = GPRS_STATE_CGREG_CHECK;
                                            //state =  GPRS_STATE_RESTART;
                                            OSTimeDly(1000);
                                            gprs_restart += 30;
                                        }
                                        else if (replay == GPRS_PROCESS_TIME_OUT)
                                        {
                                            //GprsStatus = DEF_OFF;
                                            state = GPRS_STATE_AT_CHECK;
                                            gprs_restart = 0;
                                        } 
                                        break;  
            case GPRS_STATE_TCPIP_SET  :replay = ATcmdTCPIPSetup(GPRS_DEST_IP_ADDRESS, GPRS_DEST_PORT, GrpsSocketNumBuffer);
                                        if (replay == GPRS_PROCESS_OK)
                                        {
                                            flag = DEF_OFF;
                                           // state = GPRS_STATE_TCPIP_ACK_SET;
                                         }
                                        else if (replay == GPRS_PROCESS_ERROR)
                                        {
                                            if (connect_flag == DEF_ON)
                                            {
                                                OSTimeDly(3000);
                                                state = GPRS_STATE_TCPIP_SET;
                                            }
                                            else
                                            {
                                                state = GPRS_STATE_CGREG_CHECK;
                                            }

                                           connect_flag = DEF_OFF; 
                                        }
                                        else if (replay == GPRS_PROCESS_TIME_OUT)
                                        {
                                            state = GPRS_STATE_AT_CHECK;
                                        } 
                                        break;                              
                                        
//            case GPRS_STATE_TCPIP_ACK_SET: replay = ATcmdSetTcpAck(GrpsSocketNumBuffer, 61);
//                                        if (replay == GPRS_PROCESS_OK)
//                                        {
//                                            flag = DEF_OFF;
//                                        }
//                                        else if (replay == GPRS_PROCESS_ERROR)
//                                        {
//                                            state = GPRS_STATE_AT_CHECK;
//                                        }
//                                        else if (replay == GPRS_PROCESS_TIME_OUT)
//                                        {
//                                            state = GPRS_STATE_AT_CHECK;
//                                        } 
//                                        break;  
                                        
            case GPRS_STATE_RESTART:    GprsRestart ();
                                        gprs_restart = 0;
                                        USPDAFlag = DEF_ON;
                                        connect_flag = DEF_ON;
                                        state = GPRS_STATE_AT_CHECK;
                                        break;
            default:                    break;
        }
        
        if (gprs_restart > 80)
        {
            gprs_restart = 0;
            state = GPRS_STATE_RESTART;
        }
        
    }



}

CPU_BOOL GprsSocketStatusGet(void)
{
    return GprsStatus;
}

void GprsSocketStatusSet(CPU_BOOL status)
{
    GprsStatus = status;
}

void GprsInit(void)
{
  GprsStatus = DEF_OFF;
        
   BspUbloxIOConfig();
   
   BspUbloxPowewrOn();
   
   OSTimeDly(1500); 

   GprsRestart();
}

void GprsRestart (void)
{
    GprsStatus = DEF_OFF;
    
    GprsSendStatusInit();
    
    BspUbloxRstPinH();
    OSTimeDly(1000); 
    BspUbloxRstPinL();
    OSTimeDly(4000); 
    
    GSMNetSelect();
}

void GprsRst (void)
{
     GprsStatus = DEF_OFF;    
     
     BspUbloxRstPinH();
     OSTimeDly(1000); 
     BspUbloxRstPinL();
     OSTimeDly(4000);
     GSMNetSelect();     
}

CPU_INT8U GprsCurrentSocketGet (void)
{
    return  GrpsSocketNumBuffer;
}
//接受数据判断
CPU_INT8U GetATReply (CPU_INT8U *pdata, CPU_INT16U delay, CPU_INT16U len)
{
    CPU_INT8U str[378];
    CPU_INT16U j;
    CPU_INT16U count;
    count = 0;
    j = 0;

    while (delay > 0)
    {
        while (!COM1RxFIFOIsEmpty())
        {
            str[count] = COM1RxFIFOOut();
            count++;
        }

        for (j = 0; j < count; j++)
        {
            pdata[j] = str[j];

            if (j >= len)
            {
                return AT_CMD_ERROR;
            }
        }
        
        pdata[j] = NULL;
        delay--;

        if (((strstr((char *)pdata, "OK\r\n") != NULL) && (len != 128))|| ((strstr((char *)pdata, "+UULOC:") != NULL) && (strstr((char *)pdata, ",0\r\n") != NULL)) 
          || (strstr((char *)pdata, "\r\n> ") != NULL))
        {
            return AT_CMD_OK;
        }

        if (strstr((char *)pdata, "ERROR") != NULL)
        {
            return AT_CMD_ERROR;
        }

        OSTimeDlyHMSM(0, 0, 0, 100);  
    }

    if (j == 0)
    {
        return AT_CMD_TIME_OUT;
    }
    else
    {
        if (((strstr((char *)pdata, "OK\r\n") != NULL) && (len != 128))|| ((strstr((char *)pdata, "+UULOC:") != NULL) && (strstr((char *)pdata, ",0\r\n") != NULL)) 
          || (strstr((char *)pdata, "\r\n> ") != NULL))
        {
            return AT_CMD_OK;
        }
        return AT_CMD_ERROR;
    }
}


//指令AT
GprsStateRetTypeDef ATcmdAT (void)
{
	CPU_INT8U data[64];
	CPU_INT8U reply_state;
        memset(data, 0xcc, sizeof(data));
	COM1RxFIFOClear();
	COM1SendData((CPU_INT8U *)"AT\r", strlen("AT\r")); 

	reply_state = GetATReply(data, 30, 64);
	//memset(data, 0xcc, sizeof(data));
	switch (reply_state)
	{
	case AT_CMD_OK:			return GPRS_PROCESS_OK;
				        break;
	case AT_CMD_ERROR:		return GPRS_PROCESS_ERROR;
				        break;
	case AT_CMD_TIME_OUT:	        return GPRS_PROCESS_TIME_OUT;
				        break;
	default:		        break;
	} 

	return GPRS_PROCESS_ERROR;
}
	
//查询SIM卡状态
GprsStateRetTypeDef ATcmdSIMState (void)
{
	CPU_INT8U data[96];
	CPU_INT8U reply_state;
        
        memset(data, 0xcc, sizeof(data));
	COM1RxFIFOClear();
	COM1SendData((CPU_INT8U *)"AT+CPIN?\r", strlen("AT+CPIN?\r")); 

	reply_state = GetATReply(data, 40, 96);
	//memset(data, 0xcc, sizeof(data));
        
	switch (reply_state)
	{
            case AT_CMD_OK:		    return GPRS_PROCESS_OK;
                                            break;
            case AT_CMD_ERROR:		    return GPRS_PROCESS_ERROR;
                                            break;
            case AT_CMD_TIME_OUT:	    return GPRS_PROCESS_TIME_OUT;
                                            break;
            default:		            break;
	}     

	return GPRS_PROCESS_ERROR;
}

//终止休眠状态
GprsStateRetTypeDef ATcmdStopSleep (void)
{
	CPU_INT8U data[64];
	CPU_INT8U reply_state;
	CPU_INT8U count;
	count = 3;

	while (count > 0)
	{
            memset(data, 0xcc, sizeof(data));
            COM1RxFIFOClear();
            COM1SendData((CPU_INT8U *)"AT+UPSV=0\r", strlen("AT+UPSV=0\r")); 

            reply_state = GetATReply(data, 30, 64);
            //memset(data, 0xcc, sizeof(data));
            
            if (reply_state == AT_CMD_OK)
            {
                return GPRS_PROCESS_OK;
            }
            else if (reply_state == AT_CMD_ERROR)
            {
                return GPRS_PROCESS_ERROR;	
            }

            count--;
	}

	return GPRS_PROCESS_TIME_OUT;
}
//////////////////////////////////////////////////
//设置模块的TCP心跳包时间设置
GprsStateRetTypeDef ATcmdSetTcpAck (CPU_INT8U socket, CPU_INT16U second)
{
    CPU_INT8U data[64];
	CPU_INT8U reply_state; 
    CPU_INT8U i;
    CPU_INT32U mile_second;
    
    mile_second = second * 1000;
    
    memset(data, 0xcc, sizeof(data));
	COM1RxFIFOClear();
    
    i = sprintf((char *)data, "AT+USOSO=%d,6,2,%d\r",socket, mile_second);
    
	COM1SendData(data, i); 

	reply_state = GetATReply(data, 60, 64);
	//memset(data, 0xcc, sizeof(data));
        
	switch (reply_state)
	{
            case AT_CMD_OK:		    return GPRS_PROCESS_OK;
                                            break;
            case AT_CMD_ERROR:		    return GPRS_PROCESS_ERROR;
                                            break;
            case AT_CMD_TIME_OUT:	    return GPRS_PROCESS_TIME_OUT;
                                            break;
            default:		            break;
	} 

	return GPRS_PROCESS_ERROR;
}

///////////////////////////////////
//激活连接
GprsStateRetTypeDef ATcmdConnect (void)
{
	CPU_INT8U data[64];
	CPU_INT8U reply_state; 
        memset(data, 0xcc, sizeof(data));
	COM1RxFIFOClear();
	COM1SendData((CPU_INT8U *)"AT+UPSDA=0,3\r", strlen("AT+UPSDA=0,3\r")); 

	reply_state = GetATReply(data, 60, 64);
	//memset(data, 0xcc, sizeof(data));
        
	switch (reply_state)
	{
            case AT_CMD_OK:		    return GPRS_PROCESS_OK;
                                            break;
            case AT_CMD_ERROR:		    return GPRS_PROCESS_ERROR;
                                            break;
            case AT_CMD_TIME_OUT:	    return GPRS_PROCESS_TIME_OUT;
                                            break;
            default:		            break;
	} 

	return GPRS_PROCESS_ERROR;
}

CPU_INT32U ATcmdInfoGet (CPU_INT8U *pdata, CPU_INT32U len)
{
    CPU_INT32U ret;
    CPU_INT32U i;
    CPU_INT32U times;

    times = 1;
    ret = 0;

    if (len == 0)
    {
            return ret;
    }

    for (i = 0; i < len; i++)
    {
            ret += (pdata[len - i - 1] - 0x30) * times;
            times *= 10;	
    }
    return ret;
}

//基站定位
GprsStateRetTypeDef ATcmdBTS (sLocaInfoTypeDef *locainfo)
{
    CPU_INT8U data[128];
    CPU_INT8U info[32];
    CPU_INT8U reply_state;
    CPU_INT8U info_len;
    CPU_INT8U info_count;
    CPU_INT16U i,j,sPoint;
    info_len = 0;
    info_count = 0;
    memset(data, 0xcc, sizeof(data));
    COM1RxFIFOClear();
    COM1SendData((CPU_INT8U *)"AT+uloc=2,2,1,60,1000\r", strlen("AT+uloc=2,2,1,60,1000\r")); 

    reply_state = GetATReply(data, 700, 128);
    if (reply_state == AT_CMD_OK)
    {
            for (i = 0; i < 128; i++)
            {
                    if (data[i] == ',')
                    {
                            info_count++;
                            switch (info_count)
                            {
                            case 1:		locainfo->time.year = (data[i-4] - 0x30) * 1000 + (data[i-3] - 0x30) * 100 + (data[i-2] - 0x30) * 10 + (data[i-1] - 0x30);
                                                    locainfo->time.month = (data[i-7] - 0x30) * 10 + (data[i-6] - 0x30);
                                                    locainfo->time.day = (data[i-10] - 0x30) * 10 + (data[i-9] - 0x30);
                                                    break;
                            case 2:		locainfo->time.hour = (data[i-12] - 0x30) * 10 + (data[i-11] - 0x30);
                                                    locainfo->time.minute = (data[i-9] - 0x30) * 10 + (data[i-8] - 0x30);
                                                    locainfo->time.second = (data[i-6] - 0x30) * 10 + (data[i-5] - 0x30);
                                                    locainfo->time.msecond = (data[i-3] - 0x30) * 100 + (data[i-2] - 0x30) * 10 + (data[i-1] - 0x30);
                                                    break;
                            case 3:		for (j = 0; j < info_len; j++)
                                                    {
                                                            if (info[j] == '.')
                                                                    sPoint = j;
                                                    }
                                                    locainfo->latlong.latfront = ATcmdInfoGet(info, sPoint);
                                                    locainfo->latlong.latback = ATcmdInfoGet(&info[sPoint+1], info_len - sPoint - 1);
                                                    break;
                            case 4:		for (j = 0; j < info_len; j++)
                                                    {
                                                            if (info[j] == '.')
                                                                    sPoint = j;
                                                    }
                                                    locainfo->latlong.longfront = ATcmdInfoGet(info, sPoint);
                                                    locainfo->latlong.longback = ATcmdInfoGet(&info[sPoint+1], info_len - sPoint - 1);
                                                    break;
                            case 5:     locainfo->high = ATcmdInfoGet(info, info_len);
                                                    break;
                            case 7:		locainfo->speed = ATcmdInfoGet(info, info_len);
                                                    break;
                            case 8:		locainfo->direction = ATcmdInfoGet(info, info_len);
                                                    break;
                            case 10:	locainfo->sensor_used = ATcmdInfoGet(info, info_len);
                                                    break;
                            default:	break;
                            }
                            info_len = 0;
                    }
                    else
                    {
                            info[info_len] = data[i];
                            info_len++;
                    }
            }
            //memset(data, 0xcc, sizeof(data));
            return GPRS_PROCESS_OK;
    }
    else if (reply_state == AT_CMD_ERROR)
    {
            //memset(data, 0xcc, sizeof(data));
            return GPRS_PROCESS_ERROR;	
    }
    else
    {
            //memset(data, 0xcc, sizeof(data));
            return GPRS_PROCESS_TIME_OUT;	
    }
}

//创建一个TCP Socket
GprsStateRetTypeDef ATcmdTCPIPCreat (CPU_INT8U *socket)
{
	CPU_INT8U data[96];
	CPU_INT8U reply_state;
	CPU_INT8U info[32];;
	CPU_INT8U info_len;
	CPU_INT8U info_count;
	CPU_INT16U i;
	info_len = 0;
	info_count = 0;
        
        memset(data, 0xcc, sizeof(data));
	COM1RxFIFOClear();
	COM1SendData((CPU_INT8U *)"AT+USOCR=6\r", strlen("AT+USOCR=6\r")); 

	reply_state = GetATReply(data, 40, 96);

	if (reply_state == AT_CMD_OK)
	{
		for (i = 0; i < strlen((char const *)data); i++)
		{
			if (data[i] == ' ')
			{
				info_count++;
				switch (info_count)
				{
				case 1:  *socket = data[i+1] - 0x30;
					break;
				default:	break;
				}
				info_len = 0;
			}
			else
			{
				info[info_len] = data[i];
				info_len++;
			}
		}
		return GPRS_PROCESS_OK;
	}
	else if (reply_state == AT_CMD_ERROR)
	{
		return GPRS_PROCESS_ERROR;	
	}

    info[0] = info[0];
    return GPRS_PROCESS_TIME_OUT;	
}

//访问服务器的地址和端口号
GprsStateRetTypeDef ATcmdTCPIPSetup (CPU_INT32U ip, CPU_INT16U port, CPU_INT8U socket)
{
    CPU_INT8U spdata[96];
    CPU_INT8U data[64];
    CPU_INT8U reply_state; 
    CPU_INT16U i;

    i = sprintf((char *)spdata,
            "AT+USOCO=%d,\"%d.%d.%d.%d\",%d\r",
            socket,
            (CPU_INT8U)((ip & 0xFF000000) >> 24), 
            (CPU_INT8U)((ip & 0x00FF0000) >> 16),
            (CPU_INT8U)((ip & 0x0000FF00) >> 8),
            (CPU_INT8U)(ip & 0x000000FF),
            port);
    memset(data, 0xcc, sizeof(data));
    COM1RxFIFOClear();
    COM1SendData(spdata, i); 

    reply_state = GetATReply(data, 200, 64);
    //memset(data, 0xcc, sizeof(data));
    switch (reply_state)
    {
        case AT_CMD_OK:			return GPRS_PROCESS_OK;
                                        break;
        case AT_CMD_ERROR:		return GPRS_PROCESS_ERROR;
                                        break;
        case AT_CMD_TIME_OUT:	        return GPRS_PROCESS_TIME_OUT;
                                        break;
        default:		        break;
    } 

    return GPRS_PROCESS_ERROR;
}

//tcpip 发送数据 ASSIC
GprsStateRetTypeDef ATcmdTCPIPSendAssic (CPU_INT8U *pdata, CPU_INT16U len, CPU_INT8U socket)
{
    CPU_INT8U spdata[256];
    CPU_INT8U data[256];
    CPU_INT8U reply_state;
    CPU_INT16U i;
    CPU_INT16U j;

    memset ((char *)spdata, 0 , sizeof (spdata));
    i = sprintf((char *)spdata, "AT+USOWR=%d,%d,\"", socket, len);

    for (j = 0; j < len; j++)
    {
            spdata[i+j] = pdata[j];
    }
    spdata[i+len] = '\"';
    spdata[i+len+1] = '\r';
    spdata[i+len+2] = '\n';
    memset(data, 0xcc, sizeof(data));
    COM1RxFIFOClear();
    COM1SendData(spdata, i+len+3); 

    reply_state = GetATReply(data, 100, 256);
    //memset(data, 0xcc, sizeof(data));
    switch (reply_state)
    {
        case AT_CMD_OK:			return GPRS_PROCESS_OK;
                                        break;
        case AT_CMD_ERROR:		return GPRS_PROCESS_ERROR;
                                        break;
        case AT_CMD_TIME_OUT:	        return GPRS_PROCESS_TIME_OUT;
                                        break;
        default:		        break;
    } 
    
    return GPRS_PROCESS_ERROR;
}

//tcpip 发送数据 HEX
GprsStateRetTypeDef ATcmdTCPIPSendHex (CPU_INT8U *pdata, CPU_INT16U len, CPU_INT8U socket)
{
    CPU_INT8U spdata[256];
    CPU_INT8U data[256];
    CPU_INT8U reply_state;
    CPU_INT16U i;
    CPU_INT8U *p;
    
    memset ((char *)spdata, 0 , sizeof (spdata));
    memset((char *)data, 0, sizeof(data));

    i = sprintf((char *)spdata, "AT+USOWR=%d,%d,", socket, len);
    spdata[i] = 0x0d;
    
    COM1RxFIFOClear();
    COM1SendData(spdata, i + 1); 

    reply_state = GetATReply(data, 10, 32);
    
    p = (CPU_INT8U *)strstr((char const *)data, "\r\n@");

    if (p != NULL)
    {
       COM1SendData(pdata, len); 
       reply_state = GetATReply(data, 100, 256);
        switch (reply_state)
        {
            case AT_CMD_OK:	        return GPRS_PROCESS_OK;
                                        break;
            case AT_CMD_ERROR:		return GPRS_PROCESS_ERROR;
                                        break;
            case AT_CMD_TIME_OUT:       return GPRS_PROCESS_TIME_OUT;
                                        break;
            default:		        break;
        } 
    }
    else
    {
        COM1SendData(pdata, len); 
        pdata[0] = 0x0d;
        pdata[1] = 0x0a;
        COM1SendData(pdata, 2);
    }
    
    return GPRS_PROCESS_ERROR;
}

//tcpip 发送数据 HEX 
GprsStateRetTypeDef ATcmdTCPIPSendHexRequire (CPU_INT8U socket, CPU_INT8U len)
{
    CPU_INT8U spdata[256];
    CPU_INT8U data[256];
    CPU_INT8U reply_state;
    CPU_INT16U i;
    CPU_INT8U *p;
    
    memset ((char *)spdata, 0 , sizeof (spdata));
    memset((char *)data, 0, sizeof(data));

    i = sprintf((char *)spdata, "AT+USOWR=%d,%d,", socket, len);
    spdata[i] = 0x0d;
    
    COM1RxFIFOClear();
    COM1SendData(spdata, i + 1); 

    reply_state = GetATReply(data, 50, 32);
    
    p = (CPU_INT8U *)strstr((char const *)data, "\r\n@");

    if (p != NULL)
    {
        return GPRS_PROCESS_OK;

    }
    else
    {
        COM1SendData(data, len); 
        data[0] = 0x0d;
        data[1] = 0x0a;
        COM1SendData(data, 2);
    }
    reply_state = reply_state;
    return GPRS_PROCESS_ERROR;
}
//tcpip 判断接收数据长度
GprsStateRetTypeDef ATcmdTCPIPRecDataLenGet(CPU_INT8U socket, CPU_INT16U *len)
{
	CPU_INT8U data[64];
        CPU_INT8U spdata[64];
	CPU_INT8U reply_state;
	//CPU_INT8U begin_site;
        CPU_INT8U info_len;
        
        CPU_INT16U i;
        CPU_INT8U *p_s;
        CPU_INT8U *p_e;
        
	//begin_site = 0;
        *len = 0;
        memset(data, 0xcc, sizeof(data));
	COM1RxFIFOClear();
        i = sprintf((char *)spdata, "AT+USOrd=%d,0\r", socket);
        COM1SendData(spdata, i); 

	reply_state = GetATReply(data, 30, 64);

	if (reply_state == AT_CMD_OK)
	{

               p_s = (CPU_INT8U *)strstr((char *)data, "+USORD: ");
                
                if (p_s != NULL)
                {
                    p_s = (CPU_INT8U *)strstr((char *)p_s, ",");
                    if (p_s != NULL)
                    {
                        p_e = (CPU_INT8U *)strstr((char *)p_s, "\r\n\r\nOK\r\n");
                        
                        if (p_e != NULL)
                        {
                            info_len = (CPU_INT32U)p_e - ((CPU_INT32U)p_s +  1);
                            *len = ATcmdInfoGet(&p_s[1], info_len);
                             return GPRS_PROCESS_OK;
                            
                        }
                    
                    }
                }
            }

        if (reply_state == AT_CMD_TIME_OUT)
        {
            return GPRS_PROCESS_TIME_OUT;
        }
        
	return GPRS_PROCESS_ERROR;
}

//tcpip 接收数据
GprsStateRetTypeDef ATcmdTCPIPReceive(CPU_INT8U *pdata, CPU_INT16U len, CPU_INT8U socket)
{
    CPU_INT8U spdata[64];
    CPU_INT8U data[256];
    CPU_INT8U info[256];
    CPU_INT8U info_count;
    CPU_INT8U info_len;
    CPU_INT8U reply_state; 
    CPU_INT16U i, j, k;
    info_count = 0;
    info_len = 0;

    i = sprintf((char *)spdata, "AT+USOrd=%d,%d\r", socket, len);
    memset(data, 0xcc, sizeof(data));
    COM1RxFIFOClear();
    COM1SendData(spdata, i);

    reply_state = GetATReply(data, 80, 256);
    
    if (reply_state == AT_CMD_OK)
    {
        for (j = 0; j < 256; j++)
        {
            if (data[j] == '\"')
            {
                info_count++;
                switch (info_count)
                {
                    case 2:	for (k = 0; k < info_len; k++)
                                {
                                    pdata[k] = info[k];
                                }
                                break;
                    default:    break;
                }
                
                info_len = 0;
            }
            else
            {
                    info[info_len] = data[j];
                    info_len++;
            }
        }
        //memset(data, 0xcc, sizeof(data));
        return GPRS_PROCESS_OK;
    }
    //memset(data, 0xcc, sizeof(data));
    return GPRS_PROCESS_ERROR;
}

// 接收socket数据 ASSIC
GprsStateRetTypeDef ATSocketReceiveGetAssic (CPU_INT8U *pdata, CPU_INT8U len, CPU_INT8U socket)
{
    CPU_INT8U data[256];

    CPU_INT8U count;
    CPU_INT32U rec_count;;
    CPU_INT8U info_len;

    CPU_INT16U i;
    CPU_INT8U delay;
    CPU_BOOL flag;
    CPU_BOOL rec_flag;
    CPU_INT8U* p_s;
    CPU_INT8U* p_e;
    
    if (len == 0)
    {
        return  GPRS_PROCESS_OK;
    }
    flag = DEF_ON;
    rec_flag = DEF_OFF;
    
    delay = 10;
    count = 0;
    rec_count = 0;
    
    i = sprintf((char *)data, "AT+USOrd=%d,%d\r", socket, len);

    COM1RxFIFOClear();
    COM1SendData(data, i);
    
    memset(data, 0x00, sizeof(data));
    //data[sizeof(data) - 1] = 0;
    
    while (flag)
    {
        delay--;
        if (delay == 0)
        {
            flag = DEF_OFF;
        }
        else
        {
            OSTimeDlyHMSM(0, 0, 0, 100);  
        }
        
        while (!COM1RxFIFOIsEmpty())
        {
            data[count] = COM1RxFIFOOut();
            count++;
        }
        
        p_s = (CPU_INT8U *)strstr((char const *)data, (char *)("+USORD: "));
        
        if ( p_s != NULL)
        {
            p_s = (CPU_INT8U *)strstr((char const *)p_s, (char *)(","));
            if (p_s != NULL)
            {
                p_e = (CPU_INT8U *)strstr((char const *)p_s, (char *)(",\""));
                
                if (p_e != NULL)
                {
                    info_len = (CPU_INT32U)p_e - (CPU_INT32U)p_s - 1;
                    
                    rec_count = 0;
                    
                    for (i = 0; i < info_len; i++)
                    {
                        rec_count *= 10;
                        rec_count += (p_s[i + 1] - 0x30);
                    }
                    //rec_count = ATcmdInfoGet(&p_s[1], info_len);  
                    
                    if (count > ((CPU_INT32U)p_e - (CPU_INT32U)data + rec_count + 2))
                    {
                        memcpy (pdata, &p_e[2], rec_count);
                        //return GPRS_PROCESS_OK;
                        rec_flag = DEF_ON;
                        flag = DEF_OFF;
                    }
                }
                                                          

            }
        }
    }
    
    if (rec_flag == DEF_ON)
    {
      return GPRS_PROCESS_OK;
    
    }
    
    if (count == 0)
    {
        return GPRS_PROCESS_ERROR;
    }
    else
    {
        return GPRS_PROCESS_TIME_OUT;
    }
}


// 接收socket数据 HEX
GprsStateRetTypeDef ATSocketReceiveGetHex (CPU_INT8U *pdata, CPU_INT16U *len, CPU_INT16U max, CPU_INT8U socket)
{
    CPU_INT8U data[512];

    CPU_INT16U count;
    CPU_INT16U rec_count;;
    CPU_INT8U info_len;

    CPU_INT16U i;
    CPU_INT8U j; 
    CPU_INT8U delay;
    CPU_BOOL flag;
    CPU_BOOL rec_flag;
    CPU_INT8U* p_s;
    CPU_INT8U* p_e;
    
    if (len == 0)
    {
        return  GPRS_PROCESS_OK;
    }
    flag = DEF_ON;
    rec_flag = DEF_OFF;
    
    delay = 10;
    count = 0;
    rec_count = 0;
    
    i = sprintf((char *)data, "AT+USOrd=%d,%d\r", socket, max);

    COM1RxFIFOClear();
    COM1SendData(data, i);
    
    memset(data, 0x00, sizeof(data));
    //data[sizeof(data) - 1] = 0;
    
    while (flag)
    {
        delay--;
        if (delay == 0)
        {
            flag = DEF_OFF;
        }
        else
        {
            OSTimeDlyHMSM(0, 0, 0, 100);  
        }
        
        while (!COM1RxFIFOIsEmpty())
        {
            data[count] = COM1RxFIFOOut();
            count++;
        }
        
        p_s = (CPU_INT8U *)strstr((char const *)data, (char *)("+USORD: "));
        
        if ( p_s != NULL)
        {
            p_s = (CPU_INT8U *)strstr((char const *)p_s, (char *)(","));
            if (p_s != NULL)
            {
                p_e = (CPU_INT8U *)strstr((char const *)p_s, (char *)(",\""));
                
                if (p_e != NULL)
                {
                    info_len = (CPU_INT32U)p_e - (CPU_INT32U)p_s - 1;
                    
                    rec_count = 0;
                    
                    for (i = 0; i < info_len; i++)
                    {
                        rec_count *= 10;
                        rec_count += (p_s[i + 1] - 0x30);
                        *len =  rec_count;
                    }
                    //rec_count = ATcmdInfoGet(&p_s[1], info_len);  
                    
                    if (count > ((CPU_INT32U)p_e - (CPU_INT32U)data + rec_count * 2 + 2))
                    {
                       // memcpy (pdata, &p_e[2], rec_count);
                        //return GPRS_PROCESS_OK;
                        for (j = 0; j < rec_count; j++)
                        {
                            if (p_e[2 + 2 * j] >= 'A')
                            {
                                p_e[2 + 2 * j] -= 'A';
                                p_e[2 + 2 * j] += 0x0A;
                            }
                            else
                            {
                                p_e[2 + 2 * j] -= '0';
                            }
                            
                            if (p_e[2 + 2 * j + 1] >= 'A')
                            {
                                p_e[2 + 2 * j + 1] -= 'A';
                                p_e[2 + 2 * j + 1] += 0x0A;
                            }
                            else
                            {
                                p_e[2 + 2 * j + 1] -= '0';
                            }
                            
                            pdata[j] = p_e[2 + 2 * j] * 16 + p_e[2 + 2 * j + 1] ; 
                        
                        }
                          
                        rec_flag = DEF_ON;
                        flag = DEF_OFF;
                    }
                }
                                                          

            }
        }
    }
    
    if (rec_flag == DEF_ON)
    {
      return GPRS_PROCESS_OK;
    
    }
    
    if (count == 0)
    {
        return GPRS_PROCESS_ERROR;
    }
    else
    {
        return GPRS_PROCESS_TIME_OUT;
    }
}
//tcpip 关闭
GprsStateRetTypeDef ATcmdTCPIPClose (CPU_INT8U socket)
{
    CPU_INT8U data[64];
    CPU_INT8U spdata[64];
    CPU_INT8U reply_state;
    CPU_INT16U  i;
    memset(data, 0xcc, sizeof(data));
    COM1RxFIFOClear();
    i = sprintf((char *)spdata, "AT+USOCL=%d\r", socket);
    COM1SendData(spdata, i); 

    reply_state = GetATReply(data, 30, 64);
   // memset(data, 0xcc, sizeof(data));
    switch (reply_state)
    {
        case AT_CMD_OK:			return GPRS_PROCESS_OK;
                                        break;
        case AT_CMD_ERROR:		return GPRS_PROCESS_ERROR;
                                        break;
        case AT_CMD_TIME_OUT:	        return GPRS_PROCESS_TIME_OUT;
                                        break;
        default:		        break;
    } 

    return GPRS_PROCESS_ERROR;
}

////设置短信格式为txt
//CPU_INT8U ATcmdMessageSetTxt (void)
//{
//	CPU_INT8U data[64];
//	CPU_INT8U reply_state; 
//
//	COM1RxFIFOClear();
//	COM1SendData((CPU_INT8U *)"AT+CMGF=1\r", strlen("AT+CMGF=1\r")); 
//
//	reply_state = GetATReply(data, 30, 64);
//	memset(data, 0xcc, sizeof(data));
//	switch (reply_state)
//	{
//	case AT_CMD_OK:			return GPRS_PROCESS_OK;
//		                        break;
//	case AT_CMD_ERROR:		return GPRS_PROCESS_ERROR;
//		                        break;
//	case AT_CMD_TIME_OUT:	        return GPRS_PROCESS_TIME_OUT;
//		                        break;
//	default:		        break;
//	} 
//
//	return GPRS_MESSAGE_ERROR;
//}

////发送短信
//CPU_INT8U ATcmdMessageSend (CPU_INT8U *cardnum, CPU_INT8U *pdata, CPU_INT16U len)
//{
//	CPU_INT8U spdata[256];
//	CPU_INT8U data1[64];
//	CPU_INT8U data2[64];
//	CPU_INT8U reply_state; 
//	CPU_INT16U i, j;
//
//	i = sprintf((char *)spdata, "AT+CMGS=\"");
//
//	for (j = 0; j < 11; j++)
//	{
//		spdata[i+j] = cardnum[j];
//	}
//	spdata[i+j] = '\"';
//	spdata[i+j+1] = '\r';
//		
//	COM1RxFIFOClear();
//	COM1SendData(spdata, i+13); 
//
//	reply_state = GetATReply(data1, 30, 64);
//	memset(data1, 0xcc, sizeof(data1));
//
//	if (reply_state == AT_CMD_OK)
//	{
//		for (j = 0; j < len; j++)
//		{
//			spdata[j] = pdata[j];
//		}
//		spdata[len] = 0x1a;
//
//		COM1RxFIFOClear();
//		COM1SendData(spdata, len+1); 
//
//		reply_state = GetATReply(data2, 50, 64);
//		memset(data2, 0xcc, sizeof(data2));
//		switch (reply_state)
//		{
//                    case AT_CMD_OK:			return GPRS_PROCESS_OK;
//                                                        break;
//                    case AT_CMD_ERROR:		        return GPRS_PROCESS_ERROR;
//                                                        break;
//                    case AT_CMD_TIME_OUT:	        return GPRS_PROCESS_TIME_OUT;
//                                                        break;
//                    default:			        break;
//		} 
//
//		return GPRS_PROCESS_ERROR;
//	}
//
//	return GPRS_PROCESS_ERROR;
//}
//
////清空短信
//CPU_INT8U ATcmdMessageDeleteAll (void)
//{
//	CPU_INT8U data[64];
//	CPU_INT8U reply_state;
//
//	COM1RxFIFOClear();
//	COM1SendData((CPU_INT8U *)"AT+CMGD=0,4\r", strlen("AT+CMGD=0,4\r")); 
//
//	reply_state = GetATReply(data, 30, 64);
//	memset(data, 0xcc, sizeof(data));
//	switch (reply_state)
//	{
//            case AT_CMD_OK:		    return GPRS_PROCESS_OK;
//                                            break;
//            case AT_CMD_ERROR:		    return GPRS_PROCESS_ERROR;
//                                            break;
//            case AT_CMD_TIME_OUT:	    return GPRS_PROCESS_TIME_OUT;
//                                            break;
//            default:		            break;
//	} 
//
//	return GPRS_PROCESS_ERROR;
//}
//
////接收短信
//CPU_INT8U ATcmdMessageReceive (sMessageInfoTypeDef *message)
//{
//	CPU_INT8U spdata[64];
//	CPU_INT8U data[1024];
//	CPU_INT8U data1[64];
//	CPU_INT8U info[256];
//	CPU_INT8U reply_state;
//	CPU_INT16U i, j, k;
//	CPU_INT8U info_len;
//	CPU_INT8U info_count;
//	CPU_INT8U flag;
//	CPU_INT8U serial_number;
//	serial_number = 0;
//	info_len = 0;
//	info_count = 0;
//	flag = 0;
//
//	COM1RxFIFOClear();
//	COM1SendData((CPU_INT8U *)"AT+CMGL\r", strlen("AT+CMGL\r")); 
//
//	reply_state = GetATReply(data, 400, 1024);
//
//	if (reply_state == AT_CMD_OK)
//	{
//		for (i = 0; i < 1024; i++)
//		{
//			if ((data[i-3] == 'L') && (data[i-4] == 'G') && (data[i-5] == 'M') && (data[i-6] == 'C') && (data[i-7] == '+'))
//			{
//				flag = 1;
//			}
//			if (flag == 1)
//			{
//				if ((data[i] == ',') || ((data[i] == '\r') && (data[i+1] == '\n')))
//				{
//					info_count++;
//					switch (info_count)
//					{
//					case 1:	serial_number = ATcmdInfoGet(info, info_len);
//						    break;
//					case 3: for (j = 0; j < (info_len-5); j++)
//							{
//								message->phone[j] = info[j+4] - 0x30;
//							}
//							break;
//					case 5: message->time.year = (info[1] - 0x30)*10 + (info[2] - 0x30) + 2000;
//						    message->time.month = (info[4] - 0x30)*10 + (info[5] - 0x30);
//							message->time.day = (info[7] - 0x30)*10 + (info[8] - 0x30);
//							break;
//					case 6: message->time.hour = (info[0] - 0x30)*10 + (info[1] - 0x30);
//							message->time.minute = (info[3] - 0x30)*10 + (info[4] - 0x30);
//							message->time.second = (info[6] - 0x30)*10 + (info[7] - 0x30);
//							message->time.msecond = (info[9] - 0x30)*10 + (info[10] - 0x30);
//							break;
//					case 7: message->len = info_len-1;
//							for (j = 0; j < info_len-1; j++)
//							{
//								message->data[j] = info[j+1];
//							}
//							flag = 0;
//							break;
//					default:  break;
//					}
//					info_len = 0;
//				}
//				else
//				{
//					info[info_len] = data[i];
//					info_len++;
//				}
//			}
//		}
//		memset(data, 0xcc, sizeof(data));
//		if (serial_number != 0)
//		{
//                    COM1RxFIFOClear();
//
//                    k = sprintf((char *)spdata, "AT+CMGD=%d\r", serial_number);
//                    
//                    COM1SendData(spdata, k); 
//
//                    reply_state = GetATReply(data1, 600, 64);
//                    memset(data1, 0xcc, sizeof(data1));
//
//                    if (reply_state == AT_CMD_OK)
//                    {
//                            return GPRS_MESSAGE_EXIST;
//                    }
//                    return GPRS_MESSAGE_ERROR;
//		}
//		return GPRS_MESSAGE_EMPTY;
//	}
//	return GPRS_MESSAGE_ERROR;
//}
//


/*
///开启GPS定位
CPU_INT8U ATcmdGPSOpen (void)
{
	CPU_INT8U data[64];
	CPU_INT8U reply_state;

	COM1RxFIFOClear();
	COM1SendData((CPU_INT8U *)"AT+UGPS=1,0\r", strlen("AT+UGPS=1,0\r")); 

	reply_state = GetATReply(data, 30, 64);
	memset(data, 0xcc, sizeof(data));
	switch (reply_state)
	{
	case AT_CMD_OK:			return GPRS_GPS_OK;
		break;
	case AT_CMD_ERROR:		return GPRS_GPS_ERROR;
		break;
	case AT_CMD_TIME_OUT:	return GPRS_GPS_TIME_OUT;
		break;
	default:				break;
	} 

	return GPRS_GPS_ERROR;
}

///AGPS辅助定位开启
CPU_INT8U ATcmdGPSAssistOpen (void)
{
	CPU_INT8U data[64];
	CPU_INT8U reply_state; 

	COM1RxFIFOClear();
	COM1SendData((CPU_INT8U *)"AT+UGPS=1,4\r", strlen("AT+UGPS=1,4\r")); 

	reply_state = GetATReply(data, 30, 64);
	memset(data, 0xcc, sizeof(data));
	switch (reply_state)
	{
	case AT_CMD_OK:			return GPRS_GPS_OK;
		break;
	case AT_CMD_ERROR:		return GPRS_GPS_ERROR;
		break;
	case AT_CMD_TIME_OUT:	return GPRS_GPS_TIME_OUT;
		break;
	default:				break;
	} 

	return GPRS_GPS_ERROR;
}

//GGA
CPU_INT8U ATcmdGPSGGAInfo (sGnssInfoTypeDef *gpsinfo)
{
	CPU_INT8U data[64];
	CPU_INT8U data1[256];
	CPU_INT8U info[256];
	CPU_INT8U info_len;
	CPU_INT8U reply_state; 
	CPU_INT16U i;
	CPU_BOOL  flag;
	flag = 0;
	info_len = 0;

	COM1RxFIFOClear();
	COM1SendData((CPU_INT8U *)"AT+UGGGA=1\r", strlen("AT+UGGGA=1\r")); 

	reply_state = GetATReply(data, 30, 64);
	memset(data, 0xcc, sizeof(data));

	if (reply_state == AT_CMD_OK)
	{
		COM1RxFIFOClear();
		COM1SendData((CPU_INT8U *)"AT+UGGGA?\r", strlen("AT+UGGGA?\r"));

		reply_state = GetATReply(data1, 120, 256);

		if (reply_state == AT_CMD_OK)
		{
			for (i = 0; i < 256; i++)
			{
				if (data1[i] == '$')
				{
					flag = 1;
				}
				if (flag == 1)
				{
					info[info_len++] = data1[i];

					if (info[info_len -1] == '*')
					{
						GNSSGGAInfoGet (info, info_len, gpsinfo);
					}
				}
			}
			memset(data1, 0xcc, sizeof(data1));
			return GPRS_GPS_OK;
		}
		memset(data1, 0xcc, sizeof(data1));
		return GPRS_GPS_ERROR;
	}
	memset(data1, 0xcc, sizeof(data1));
	return GPRS_GPS_ERROR;
}

//RMC
CPU_INT8U ATcmdGPSRMCInfo (sGnssInfoTypeDef *gpsinfo)
{
	CPU_INT8U data[64];
	CPU_INT8U data1[256];
	CPU_INT8U info[256];
	CPU_INT8U info_len;
	CPU_INT8U reply_state; 
	CPU_INT16U i;
	CPU_BOOL  flag;
	flag = 0;
	info_len = 0;

	COM1RxFIFOClear();
	COM1SendData((CPU_INT8U *)"AT+UGRMC=1\r", strlen("AT+UGRMC=1\r")); 

	reply_state = GetATReply(data, 30, 64);
	memset(data, 0xcc, sizeof(data));

	if (reply_state == AT_CMD_OK)
	{
		COM1RxFIFOClear();
		COM1SendData((CPU_INT8U *)"AT+UGRMC?\r", strlen("AT+UGRMC?\r"));

		reply_state = GetATReply(data1, 120, 256);

		if (reply_state == AT_CMD_OK)
		{
			for (i = 0; i < 256; i++)
			{
				if (data1[i] == '$')
				{
					flag = 1;
				}
				if (flag == 1)
				{
					info[info_len++] = data1[i];

					if (info[info_len -1] == '*')
					{
						GNSSRMCInfoGet (info, info_len, gpsinfo);
					}
				}
			}
			memset(data1, 0xcc, sizeof(data1));
			return GPRS_GPS_OK;
		}
		memset(data1, 0xcc, sizeof(data1));
		return GPRS_GPS_ERROR;
	}
	memset(data1, 0xcc, sizeof(data1));
	return GPRS_GPS_ERROR;
}

//GSA
CPU_INT8U ATcmdGPSGSAInfo (sGnssInfoTypeDef *gpsinfo)
{
	CPU_INT8U data[64];
	CPU_INT8U data1[256];
	CPU_INT8U info[256];
	CPU_INT8U info_len;
	CPU_INT8U reply_state; 
	CPU_INT16U i;
	CPU_BOOL  flag;
	flag = 0;
	info_len = 0;

	COM1RxFIFOClear();
	COM1SendData((CPU_INT8U *)"AT+UGGSA=1\r", strlen("AT+UGGSA=1\r")); 

	reply_state = GetATReply(data, 30, 64);
	memset(data, 0xcc, sizeof(data));

	if (reply_state == AT_CMD_OK)
	{
		COM1RxFIFOClear();
		COM1SendData((CPU_INT8U *)"AT+UGGSA?\r", strlen("AT+UGGSA?\r"));

		reply_state = GetATReply(data1, 120, 256);

		if (reply_state == AT_CMD_OK)
		{
			for (i = 0; i < 256; i++)
			{
				if (data1[i] == '$')
				{
					flag = 1;
				}
				if (flag == 1)
				{
					info[info_len++] = data1[i];

					if (info[info_len -1] == '*')
					{
						GNSSGSAInfoGet (info, info_len, gpsinfo);
					}
				}
			}
			memset(data1, 0xcc, sizeof(data1));
			return GPRS_GPS_OK;
		}
		memset(data1, 0xcc, sizeof(data1));
		return GPRS_GPS_ERROR;
	}
	memset(data1, 0xcc, sizeof(data1));
	return GPRS_GPS_ERROR;
}

//GLL
CPU_INT8U ATcmdGPSGLLInfo (sGnssInfoTypeDef *gpsinfo)
{
	CPU_INT8U data[64];
	CPU_INT8U data1[256];
	CPU_INT8U info[256];
	CPU_INT8U info_len;
	CPU_INT8U reply_state; 
	CPU_INT16U i;
	CPU_BOOL  flag;
	flag = 0;
	info_len = 0;

	COM1RxFIFOClear();
	COM1SendData((CPU_INT8U *)"AT+UGGLL=1\r", strlen("AT+UGGLL=1\r")); 

	reply_state = GetATReply(data, 30, 64);
	memset(data, 0xcc, sizeof(data));

	if (reply_state == AT_CMD_OK)
	{
		COM1RxFIFOClear();
		COM1SendData((CPU_INT8U *)"AT+UGGLL?\r", strlen("AT+UGGLL?\r"));

		reply_state = GetATReply(data1, 120, 256);

		if (reply_state == AT_CMD_OK)
		{
			for (i = 0; i < 256; i++)
			{
				if (data1[i] == '$')
				{
					flag = 1;
				}
				if (flag == 1)
				{
					info[info_len++] = data1[i];

					if (info[info_len -1] == '*')
					{
						GNSSGSAInfoGet (info, info_len, gpsinfo);
					}
				}
			}
			memset(data1, 0xcc, sizeof(data1));
			return GPRS_GPS_OK;
		}
		memset(data1, 0xcc, sizeof(data1));
		return GPRS_GPS_ERROR;
	}
	memset(data1, 0xcc, sizeof(data1));
	return GPRS_GPS_ERROR;
}
*/

//点亮led6
//CPU_INT8U ATcmdLed (void)
//{
//	CPU_INT8U data[64];
//	CPU_INT8U reply_state; 
//
//	COM1RxFIFOClear();
//	COM1SendData((CPU_INT8U *)"AT+UGPIOC=16,2\r", strlen("AT+UGPIOC=16,2\r")); 
//
//	reply_state = GetATReply(data, 30, 64);
//	memset(data, 0xcc, sizeof(data));
//	switch (reply_state)
//	{
//	case AT_CMD_OK:			return GPRS_PROCESS_OK;
//		break;
//	case AT_CMD_ERROR:		return GPRS_PROCESS_ERROR;
//		break;
//	case AT_CMD_TIME_OUT:	return GPRS_PROCESS_TIME_OUT;
//		break;
//	default:				break;
//	} 
//
//	return GPRS_PROCESS_ERROR;
//}

//查询信号质量
GprsStateRetTypeDef ATcmdCSQ (void)
{
	CPU_INT8U data[96];
	CPU_INT8U reply_state;
	CPU_INT8U info[32];
	CPU_INT8U info_len;
	CPU_INT8U info_count;
	CPU_INT16U i, db;
	info_len = 0;
	info_count = 0;
        
        memset(data, 0xcc, sizeof(data));
	COM1RxFIFOClear();
	COM1SendData((CPU_INT8U *)"AT+CSQ\r", strlen("AT+CSQ\r")); 

	reply_state = GetATReply(data, 40, 96);

	if (reply_state == AT_CMD_OK)
	{
		for (i = 0; i < 96; i++)
		{
			if ((data[i] == ',') || (data[i] == ' '))
			{
				info_count++;
				switch (info_count)
				{
				case 2: db = ATcmdInfoGet(info, info_len);
					break;
				default:	break;
				}
				info_len = 0;
			}
			else
			{
				info[info_len] = data[i];
				info_len++;
			}
		}
		if ((db == 0) || (db == 99))
		{
			//memset(data, 0xcc, sizeof(data));
			return GPRS_PROCESS_ERROR;
		}
		else
		{
			//memset(data, 0xcc, sizeof(data));
			return GPRS_PROCESS_OK;
		}
	}
	else if (reply_state == AT_CMD_ERROR)
	{
		//memset(data, 0xcc, sizeof(data));
		return GPRS_PROCESS_ERROR;	
	}
	else
	{
		//memset(data, 0xcc, sizeof(data));
		return GPRS_PROCESS_TIME_OUT;	
	}
}

//读取网络注册状态
GprsStateRetTypeDef ATcmdCREG (void)
{
	CPU_INT8U data[96];
	CPU_INT8U reply_state;
	CPU_INT8U info[32];
	CPU_INT8U info_len;
	CPU_INT8U info_count;
	CPU_INT16U i,state;
	info_len = 0;
	info_count = 0;
        memset(data, 0xcc, sizeof(data));
	COM1RxFIFOClear();
	COM1SendData((CPU_INT8U *)"AT+CREG?\r", strlen("AT+CREG?\r")); 

	reply_state = GetATReply(data, 100, 96);
	//memset(data, 0xcc, sizeof(data));

	if (reply_state == AT_CMD_OK)
	{
		for (i = 0; i < strlen((char const *)data); i++)
		{
			if (data[i] == ',')
			{
				info_count++;
				switch (info_count)
				{
				case 1:  state = data[i+1] - 0x30;
					break;
				default:	break;
				}
				info_len = 0;
			}
			else
			{
				info[info_len] = data[i];
				info_len++;
			}
		}
		if ((state == 1) || (state == 5))
		{
			//memset(data, 0xcc, sizeof(data));
			return GPRS_PROCESS_OK;
		}
		else
		{
			//memset(data, 0xcc, sizeof(data));
			return GPRS_PROCESS_ERROR;
		}
	}
	else if (reply_state == AT_CMD_ERROR)
	{
		//memset(data, 0xcc, sizeof(data));
		return GPRS_PROCESS_ERROR;	
	}
	else

    info[0] = info[0];
    return GPRS_PROCESS_TIME_OUT;	
}

//读取gprs网络注册状态
GprsStateRetTypeDef ATcmdCGREG (void)
{
	CPU_INT8U data[96];
	CPU_INT8U reply_state;
	CPU_INT8U info[32];
	CPU_INT8U info_len;
	CPU_INT8U info_count;
	CPU_INT16U i,state;
	info_len = 0;
	info_count = 0;
        memset(data, 0xcc, sizeof(data));
	COM1RxFIFOClear();
	COM1SendData((CPU_INT8U *)"AT+CGREG?\r", strlen("AT+CGREG?\r")); 

	reply_state = GetATReply(data, 40, 96);

	if (reply_state == AT_CMD_OK)
	{
		for (i = 0; i < 96; i++)
		{
			if (data[i] == ',')
			{
				info_count++;
				switch (info_count)
				{
				case 1:  state = data[i+1] - 0x30;
					break;
				default:	break;
				}
				info_len = 0;
			}
			else
			{
				info[info_len] = data[i];
				info_len++;
			}
		}
		if ((state == 1)||(state == 5))
		{
			return GPRS_PROCESS_OK;
		}
		else
		{
			return GPRS_PROCESS_ERROR;
		}
	}
	else if (reply_state == AT_CMD_ERROR)
	{
		return GPRS_PROCESS_ERROR;	
	}
    
    info[0] = info[0];
    return GPRS_PROCESS_TIME_OUT;	

    

}

GprsStateRetTypeDef ATcmdATEX (CPU_BOOL flag)
{
    CPU_INT8U data[256];
    CPU_INT16U i;
    CPU_INT8U reply;
    
    i = sprintf((char *)data, "ATE%d\r\n", flag);
    
    COM1RxFIFOClear();
    COM1SendData(data, i);
    memset(data, 0, sizeof(data));
    reply = GetATReply(data, 20, sizeof(data));
    
    if (reply == AT_CMD_OK)
    {   		
        return GPRS_PROCESS_OK;
    }
    else if (reply == AT_CMD_ERROR)
    {
        return GPRS_PROCESS_ERROR;	
    }
    else
    {
        return GPRS_PROCESS_TIME_OUT;	
    }
}

//设置成HEX模式
GprsStateRetTypeDef ATcmdSocketSendHexMode (void)
{
    CPU_INT8U data[64];
    CPU_INT8U reply_state; 

    memset(data, 0xcc, sizeof(data));
    COM1RxFIFOClear();
    COM1SendData((CPU_INT8U *)"AT+UDCONF=1,1\r", strlen("AT+UDCONF=1,1\r"));

    reply_state = GetATReply(data, 30, 64);

    switch (reply_state)
    {
        case AT_CMD_OK:	            return GPRS_PROCESS_OK;
                                        break;
        case AT_CMD_ERROR:		    return GPRS_PROCESS_ERROR;
                                        break;
        case AT_CMD_TIME_OUT:	    return GPRS_PROCESS_TIME_OUT;
                                        break;
        default:			    break;
    } 

    return GPRS_PROCESS_ERROR;
}

GprsStateRetTypeDef ATcmdSetSleep(CPU_INT16U timeout)
{
    CPU_INT8U data[64];
    CPU_INT8U reply_state; 
    CPU_INT8U i;
    
    ATcmdWakeUp();
    
    i = sprintf((char *)data, "AT+UPSV=1,%d\r", timeout);

    COM1RxFIFOClear();
    COM1SendData(data, i);

    reply_state = GetATReply(data, 30, 64);

    switch (reply_state)
    {
        case AT_CMD_OK:	            return GPRS_PROCESS_OK;
                                    break;
        case AT_CMD_ERROR:	    return GPRS_PROCESS_ERROR;
                                    break;
        case AT_CMD_TIME_OUT:	    return GPRS_PROCESS_TIME_OUT;
                                    break;
        default:		    break;
    } 

    return GPRS_PROCESS_ERROR;
}

GprsStateRetTypeDef ATcmdWakeUp(void)
{
    CPU_INT8U data[64];
    CPU_INT8U reply_state; 
    CPU_INT8U i;
    
    i = sprintf((char *)data, "AT+UPSV=0\r\n");

    COM1RxFIFOClear();
    COM1SendData(data, i);
    reply_state = GetATReply(data, 15, 64);
    
    COM1RxFIFOClear();
    COM1SendData(data, i);
    reply_state = GetATReply(data, 20, 64);
    
    i = sprintf((char *)data, "AT+UPSV=0\r\n");
    COM1RxFIFOClear();
    COM1SendData(data, i);
    reply_state = GetATReply(data, 25, 64);
    
    reply_state = reply_state;
    
    return GPRS_PROCESS_OK;
}


void GprsBuffInit (void)
{
    QueueInit(&GprsData.queue);
    GprsData.flag = DEF_OFF;
}

//void GprsBuffDataOut (CPU_INT8U *pdata, CPU_INT16U len)
//{
//    CPU_BOOL flag;
//    CPU_INT8U count;
//    GprsSendStatusTypeDef gprs_send_status;
//    
//    flag = DEF_ON;
//    count = 0;
//    while(GprsStateFlagGet() == GPRS_GPRS_STATE_BUSY)
//    {
//        OSTimeDly(10);
//    }
//    
//    GprsStateFlagSet(GPRS_GPRS_STATE_BUSY);
//    
//    // 唤醒
//    ATcmdWakeUp();
//    //
//    
//    while (flag)
//    {
//        if (ATcmdTCPIPSendHex(pdata, len, GrpsSocketNumBuffer) == GPRS_PROCESS_OK)
//        {
//            //
//            gprs_send_status.rec_flag = DEF_OFF;
//            gprs_send_status.send_flag = DEF_ON;
//            gprs_send_status.send_tick = OSTimeGet();
//            GprsSendStatusSet(gprs_send_status);
//            //
//            
//            
//            ///////////20140528/////////////////
////            GprsStateFlagSet(GPRS_GPRS_STATE_FREE);  
////            
////            OSTimeDlyHMSM(0, 0, 2, 20);
////            
////            while(GprsStateFlagGet() == GPRS_GPRS_STATE_BUSY)
////            {
////                OSTimeDly(10);
////            }
////            
////            GprsStateFlagSet(GPRS_GPRS_STATE_BUSY);
////            
////            GprsSendStatusSet(gprs_send_status);
////            
////            if (gprs_send_status.rec_flag == DEF_ON)
////            {
////                
////            
////            
////            }
//            ///////////////////////////////////
//            flag = DEF_OFF;
//        }
//        else
//        {
//            if (count > 1)
//            {
//                flag = DEF_OFF;
//            }
//            else
//            {
//                GprsProcessUblox(GPRS_STATE_CSQ_CHECK); 
//                OSTimeDlyHMSM(0, 0, 10, 0);
//            }
//            
//            count++;
//        }
//    }
//    
//    
//    //
//    //ATcmdSetSleep(100);
//    //
//    OSTimeDlyHMSM(0, 0, 5, 0);
//    GprsStateFlagSet(GPRS_GPRS_STATE_FREE);  
//   
//}

void GprsBuffDataOut (CPU_INT8U *pdata, CPU_INT16U len, CPU_INT8U *err)
{
    CPU_BOOL flag;
    GprsSendStatusTypeDef gprs_send_status;
    CPU_INT8U time_count;
    CPU_INT8U mbox_err;
    
    while(GprsStateFlagGet() == GPRS_GPRS_STATE_BUSY)
    {
        OSTimeDly(10);
    }
    
    GprsStateFlagSet(GPRS_GPRS_STATE_BUSY);
    
    // Wake Up Gsm Module
    ATcmdWakeUp();
    //
    
    flag = DEF_OFF;
    *err = ESEALBD_DATA_SEND_FAIL;

    if (ATcmdTCPIPSendHex(pdata, len, GrpsSocketNumBuffer) == GPRS_PROCESS_OK)
    {
        //
        gprs_send_status.rec_flag = DEF_OFF;
        gprs_send_status.send_flag = DEF_ON;
        gprs_send_status.send_tick = OSTimeGet();
        GprsSendStatusSet(gprs_send_status);
        //
        
        time_count = 0;
        
        while (1)
        {
            GprsStateFlagSet(GPRS_GPRS_STATE_FREE);
            
            OSMboxPend(GprsAckMsg, 1000, &mbox_err);
            time_count++;
            
            if (time_count > GPRS_SOCKET_ACK_TIME_OUT)
            {
                flag = DEF_OFF;
                break;
            }
            
            if (mbox_err == OS_NO_ERR)
            {
                flag = DEF_ON;
                break;
            }
        }     
        
    }
    else
    {
        GprsStateFlagSet(GPRS_GPRS_STATE_FREE);
    }
    
    if (flag == DEF_ON)
    {
        *err = ESEALBD_DATA_SEND_SUCCESS;    
    }
    else
    {
        GprsTaskReset();
        OSTimeDlyHMSM(0, 2, 40, 0);
        *err = ESEALBD_DATA_SEND_FAIL;    
    }
}

GprsTXQueueTypeDef GprsBuffDataIn (CPU_INT8U *pdata, CPU_INT16U len)
{
    sGprsDataItemTypeDef *item;
    void *temp;
    
    if (len > GPRS_COM_DATA_MAX_SIZE)
    {
        return GPRS_TX_QUEUE_ERROR_ITEM_SIZE;
    }
    
    while (GprsData.flag)
    {
        OSTimeDly(10);
    }
    
    if (QueueIsFull(&GprsData.queue, GPRS_DATA_QUEUE_SIZE) == DEF_TRUE)
    {
        return GPRS_TX_QUEUE_ERROR_QUEUE_SIZE; 
    }
    
    QueueIn(&GprsData.queue, &temp, sizeof(sGprsDataItemTypeDef), GPRS_DATA_QUEUE_SIZE);
    
    item = (sGprsDataItemTypeDef *)temp;
    
    item->len = len;
    
    memcpy(item->data, pdata, item->len);

    return GPRS_TX_QUEUE_OK;
}

GprsStateRetTypeDef GprsSocketRxBufferGet (CPU_INT8U *pdata, CPU_INT16U *len, CPU_INT16U max)
{
    CPU_INT8U socket;
    
    socket = GprsCurrentSocketGet();
    
    if (ATSocketReceiveGetHex(pdata, len, max, socket) == GPRS_PROCESS_OK)
    {
        return GPRS_PROCESS_OK;
    }

    return GPRS_PROCESS_ERROR;

}

GprsStateFlagTypeDef GprsStateFlagGet (void)
{
   return GprsStateFlag;
}

void GprsStateFlagSet (GprsStateFlagTypeDef flag)
{
    GprsStateFlag = flag;
}

void GSMNetSelect (void)
{ 
    CPU_INT8U state;
    CPU_INT8U replay;
    CPU_BOOL flag;
    GSMNetTypeDef net;
    CPU_INT8U n;
    CPU_INT8U status;
    flag = DEF_ON;
    state = GPRS_STATE_CREG_QUERY;
    net.n = 0;
    n = 0;
    
    while (flag)
    {
        switch (state)
        {
            case GPRS_STATE_CREG_QUERY:     replay = ATcmdCERGQuery(&status);
                                            if (replay == GPRS_PROCESS_OK)
                                            {
                                                if ((status == '1' )|| (status == '5' ))
                                                {
                                                    flag = DEF_OFF;
                                                } 
                                                else if (status == '2')
                                                {  
                                                    OSTimeDly(1000);    
                                                    state = GPRS_STATE_CREG_QUERY;
                                                }
                                                else if (status == '0')
                                                {
                                                    state = GPRS_STATE_COPS_SEARCH;
                                                }
                                                else
                                                {
                                                    flag = DEF_OFF;
                                                }
                                            }
                                            break; 
            case GPRS_STATE_COPS_SEARCH:    OSTimeDly(10000);
                                            replay = ATcmdCOPSSearch(&net);
                                            if (replay == GPRS_PROCESS_OK)
                                            {
                                                state = GPRS_STATE_CREG_SET;
                                            }
                                            else
                                            {
                                                flag = DEF_OFF;
                                            }
                                            break;
            case GPRS_STATE_CREG_SET:       replay = ATcmdCERGSet();
                                            if (replay == GPRS_PROCESS_OK)
                                            {
                                                state = GPRS_STATE_COPS_SET;
                                            }
                                            else
                                            {
                                                flag = DEF_OFF;
                                            }
                                            break;
            case GPRS_STATE_COPS_SET:       if (n < net.n)
                                            {
                                                replay = ATcmdCOPSSet(net.net[n]);
                                                n++;
                                                if (replay == GPRS_PROCESS_OK)
                                                {
                                                    state = GPRS_STATE_COPS_QUERY;
                                                    break;
                                                }
                                                
                                                state = GPRS_STATE_COPS_SET;
                                                break;
                                            }
                                            flag = DEF_OFF;
                                            break;
            case GPRS_STATE_COPS_QUERY:     replay = ATcmdCOPSQuery();
                                            if (replay == GPRS_PROCESS_OK)
                                            {
                                                flag = DEF_OFF;
                                            }
                                            else
                                            {
                                                state = GPRS_STATE_COPS_SET;
                                            }
                                            break;
            default:                        flag = DEF_OFF;
                                            break;
        }
    }
}

GprsStateRetTypeDef ATcmdCERGQuery (CPU_INT8U *state)
{
    CPU_INT8U data[256];
    CPU_INT8U reply;
    CPU_INT8U i;
    CPU_BOOL flag;

    *state = '0';
    
    COM1RxFIFOClear();
        
    COM1SendData("AT+CREG?\r\n", strlen("AT+CREG?\r\n")); 
    memset(data, 0, sizeof(data));
    reply = GetATReply(data, 30, sizeof(data));
    
    if (reply == AT_CMD_OK)
    {  
        flag = DEF_OFF;
        
        for (i = 0; i < 30; i++)
        {
            if (data[i] == ':')
            {
                *state = data[i + 4];
                flag = DEF_ON;
                break;
            }
        }
        
        if(flag == DEF_ON)
        {
            return GPRS_PROCESS_OK;
        }
    }      

    return GPRS_PROCESS_ERROR;
}

GprsStateRetTypeDef ATcmdCOPSSearch (GSMNetTypeDef *net)
{
    CPU_INT8U  data[256];
    CPU_INT8U  reply;
    CPU_INT32U i, j, k;
    CPU_INT8U len;
    
    net->n = 0;
    
    len = sprintf((char *)data, "AT+COPS=?\r\n");
    COM1RxFIFOClear();
    COM1SendData(data, len);     
   // COM1SendData("AT+COPS=?\r\n", strlen("AT+COPS=?\r\n")); 
    memset(data, 0, sizeof(data));
    reply = GetATReply(data, 400, sizeof(data));

    if (reply == AT_CMD_OK)
    {  
        for (i = 0; i < 256; i++)
        {
            if (data[i] == ':')
            {
                for (j = i; j < 256; j++)
                {
                    if ((data[j] == '(') && (data[j + 3] == '"'))
                    {
                        net->net[net->n].len = 0;
                        
                        for (k = j; k < 256; k++)
                        {
                            net->net[net->n].name[net->net[net->n].len] = data[k +3];
                            net->net[net->n].len++;
                            if ((data[k + 3] == '"') && (data[k + 3 + 1] == ','))
                            {
                                break;
                            }
                        }
                        
                        net->n++;
                    }
                }
                
                break;
            }
            
        }
        
    }   
    
    if (net->n != 0)
    {
        return GPRS_PROCESS_OK;
    }

    return GPRS_PROCESS_ERROR;

}

GprsStateRetTypeDef ATcmdCERGSet (void)
{
    CPU_INT8U data[256];
    CPU_INT8U reply;
    
    COM1RxFIFOClear();
        
    COM1SendData("AT+CREG=1\r\n", strlen("AT+CREG=1\r\n")); 
    memset(data, 0, sizeof(data));
    reply = GetATReply(data, 30, sizeof(data));

    if (reply == AT_CMD_OK)
    {  
        return GPRS_PROCESS_OK;
    }      

    return GPRS_PROCESS_ERROR;
}

GprsStateRetTypeDef ATcmdCOPSSet (GSMNetNameTypeDef net)
{
    CPU_INT8U data[256];
    CPU_INT8U reply;
    
    COM1RxFIFOClear();
        
    COM1SendData("AT+COPS=4,0,", strlen("AT+COPS=4,0,")); 
    COM1SendData(net.name, net.len); 
    COM1SendData("\r\n", strlen("\r\n")); 
    memset(data, 0, sizeof(data));
    reply = GetATReply(data, 100, sizeof(data));
    
  //  return GPRS_PROCESS_ERROR;//test
 
    if (reply == AT_CMD_OK)
    {  
        return GPRS_PROCESS_OK;
    }      

    return GPRS_PROCESS_ERROR;
}

GprsStateRetTypeDef ATcmdCOPSQuery (void)
{
    CPU_INT8U data[256];
    CPU_INT8U reply;
    CPU_INT8U i;
    
    COM1RxFIFOClear();
        
    COM1SendData("AT+COPS?\r\n", strlen("AT+COPS?\r\n")); 
    memset(data, 0, sizeof(data));
    reply = GetATReply(data, 30, sizeof(data));

    if (reply == AT_CMD_OK)
    {  
        for (i = 0; i < 30; i++)
        {
            if (data[i] == '"')
            {
                return GPRS_PROCESS_OK;
            }
        }     
    }      

    return GPRS_PROCESS_ERROR;
}

////CLOSE SMS INDICATION
GprsStateRetTypeDef ATcmdSetSMSDisindicate (void)
{
    CPU_INT8U data[256];
    CPU_INT16U i;
    CPU_INT8U reply;
    
    i = sprintf((char *)data, "AT+CNMI=1,1\r\n");
    
    COM1RxFIFOClear();
    COM1SendData(data, i);
    memset(data, 0, sizeof(data));
    reply = GetATReply(data, 20, sizeof(data));
    
    if (reply == AT_CMD_OK)
    {   		
        return GPRS_PROCESS_OK;
    }
    else if (reply == AT_CMD_ERROR)
    {
        return GPRS_PROCESS_ERROR;	
    }
    else
    {
        return GPRS_PROCESS_TIME_OUT;	
    }
}


////SET TXT SMS MDOE
GprsStateRetTypeDef ATcmdSetSMSTXTMode (void)
{
    CPU_INT8U data[256];
    CPU_INT16U i;
    CPU_INT8U reply;
    
    i = sprintf((char *)data, "AT+CMGF=1\r\n");
    
    COM1RxFIFOClear();
    COM1SendData(data, i);
    memset(data, 0, sizeof(data));
    reply = GetATReply(data, 20, sizeof(data));
    
    if (reply == AT_CMD_OK)
    {   		
        return GPRS_PROCESS_OK;
    }
    else if (reply == AT_CMD_ERROR)
    {
        return GPRS_PROCESS_ERROR;	
    }
    else
    {
        return GPRS_PROCESS_TIME_OUT;	
    }
}

////SET SMS MEMERY LOCATION
GprsStateRetTypeDef ATcmdSetSMSMemeryLoc (void)
{
    CPU_INT8U data[256];
    CPU_INT16U i;
    CPU_INT8U reply;
    
    i = sprintf((char *)data, "AT+CPMS=\"MT\",\"MT\",\"MT\"\r\n");
    
    COM1RxFIFOClear();
    COM1SendData(data, i);
    memset(data, 0, sizeof(data));
    reply = GetATReply(data, 20, sizeof(data));
    
    if (reply == AT_CMD_OK)
    {   		
        return GPRS_PROCESS_OK;
    }
    else if (reply == AT_CMD_ERROR)
    {
        return GPRS_PROCESS_ERROR;	
    }
    else
    {
        return GPRS_PROCESS_TIME_OUT;	
    }
}

////REMOVE ALL SMS
GprsStateRetTypeDef ATcmdRemoveAllSMS (void)
{
    CPU_INT8U data[256];
    CPU_INT16U i;
    CPU_INT8U reply;
    
    i = sprintf((char *)data, "AT+CMGD=1,4\r\n");
    
    COM1RxFIFOClear();
    COM1SendData(data, i);
    memset(data, 0, sizeof(data));
    reply = GetATReply(data, 20, sizeof(data));
    
    if (reply == AT_CMD_OK)
    {   		
        return GPRS_PROCESS_OK;
    }
    else if (reply == AT_CMD_ERROR)
    {
        return GPRS_PROCESS_ERROR;	
    }
    else
    {
        return GPRS_PROCESS_TIME_OUT;	
    }
}

////REMOVE INDEX SMS
GprsStateRetTypeDef ATcmdRemoveIndexSMS (CPU_INT16U index)
{
    CPU_INT8U data[129];
    CPU_INT16U i;
    CPU_INT8U reply;
    
    i = sprintf((char *)data, "AT+CMGD=%d\r\n", index);
    
    COM1RxFIFOClear();
    COM1SendData(data, i);
    memset(data, 0, sizeof(data));
    reply = GetATReply(data, 20, sizeof(data));
    
    if (reply == AT_CMD_OK)
    {   		
        return GPRS_PROCESS_OK;
    }
    else if (reply == AT_CMD_ERROR)
    {
        return GPRS_PROCESS_ERROR;	
    }
    else
    {
        return GPRS_PROCESS_TIME_OUT;	
    }
}

////QUERY SMS STATUS
GprsStateRetTypeDef ATcmdQuerySMSStatus (CPU_INT16U *sms_num, CPU_INT16U *max_num)
{
    CPU_INT8U data[129];
    CPU_INT16U i;
    CPU_INT8U reply;
    CPU_INT8U count;
    CPU_INT8U info[128];
    CPU_INT16U info_len;
    
    i = sprintf((char *)data, "AT+CPMS?\r\n");
    
    COM1RxFIFOClear();
    COM1SendData(data, i);
    memset(data, 0, sizeof(data));
    reply = GetATReply(data, 50, sizeof(data));
    
    
    if (reply == AT_CMD_OK)
    {  
        count = 0;
        info_len = 0;
        
        for (i = 0; i < sizeof (data); i++)
        {
            if ((data[i] == ',') || (data[i] == 0x00))
            {
                switch (count)
                {
                    case 1: *sms_num = ATcmdParaConvertToHex(info, info_len);
                            break;
                    case 2: *max_num = ATcmdParaConvertToHex(info, info_len);
                            return GPRS_PROCESS_OK;
                    default:break;
                
                }
                
                count++;
                info_len = 0;
            }
            else
            {
                info[info_len] = data[i];
                info_len++;
            }    
        }
        
        return GPRS_PROCESS_OK;
    }
    else if (reply == AT_CMD_ERROR)
    {
        return GPRS_PROCESS_ERROR;	
    }

    return GPRS_PROCESS_TIME_OUT;	

}

CPU_INT16U ATcmdParaConvertToHex (CPU_INT8U *pdata, CPU_INT8U len)
{
    CPU_INT8U i;
    CPU_INT16U ret;
    
    ret = 0;
    
    for (i = 0; i < len; i++)
    {
        ret = ret * 10;
        ret += (pdata[i] - 0x30);
    }
    
    return ret;
}

////GET SMS MESSAGE
GprsStateRetTypeDef ATcmdGetSMSMessage (CPU_INT16U index, CPU_INT8U *pdata, CPU_INT16U *len)
{
    CPU_INT8U data[378];
    CPU_INT16U i;
    CPU_INT8U reply;
    CPU_INT8U count;
    CPU_INT8U info[256];
    CPU_INT16U info_len;
    CPU_INT8U *p;
    CPU_BOOL flag;
    CPU_INT32U p_e;
    CPU_INT16U j;
    CPU_INT8U temp_h;
    CPU_INT8U temp_l;
    
    i = sprintf((char *)data, "AT+CMGR=%d\r\n", index);
    
    COM1RxFIFOClear();
    COM1SendData(data, i);
    memset(data, 0, sizeof(data));
    reply = GetATReply(data, 30, sizeof(data));
    
    
    if (reply == AT_CMD_OK)
    {  
        count = 0;
        info_len = 0;
        flag = DEF_OFF;
        
        for (i = 0; i < sizeof (data);i++)
        {
            if (data[i] == 0x22)
            {
                switch (count)
                {
                    case 5: p = NULL;
                            
                            p = (unsigned char *)strstr((char *)&data[i], "\r\n\r\nOK\r\n");
                            
                            if (p != NULL)
                            {
                                p_e = (CPU_INT32U)&data[i + 3];
                                *len = (CPU_INT32U)p - p_e;
                                
                                /* 孙工 短信平台短信解析方式*/
                                /*
                                for (j = 0; j < (*len) / 2; j++)
                                {
                                    pdata[j] = (((data[i + 3 + 2 * j] >= 'A') ? (data[i + 3 + 2 * j] - 0x37 ): (data[i + 3 + 2 * j] - 0x30) ) << 4)
                                                | ((data[i + 3 + 2 * j + 1] >= 'A') ? (data[i + 3 + 2 * j + 1] - 0x37 ): (data[i + 3 + 2 * j + 1] - 0x30) ) ;
                                }
                                */
                                /* 云平台解析   */
                                for (j = 0; j < (*len) / 8; j++)
                                {
                                    temp_h = (data[i + 3 + 8 * j + 2] - 0x30) * 16 +  (data[i + 3 + 8 * j + 3] - 0x30);
                                    temp_l = (data[i + 3 + 8 * j + 6] - 0x30) * 16 +  (data[i + 3 + 8 * j + 7] - 0x30);
                                    
                                    pdata[j] = ((temp_h >= 'A') ? (temp_h - 0x37 ): (temp_h - 0x30) ) << 4
                                                | ((temp_l >= 'A') ? (temp_l - 0x37 ): (temp_l - 0x30));
                                }
                                
                                
                                //memcpy (pdata, &data[i + 1], *len);
                                *len = j;
                                flag = DEF_ON;
                                return GPRS_PROCESS_OK;
                            }
                            
                            return GPRS_PROCESS_ERROR;
                            
                    default:break;
                
                }
                
                count++;
                info_len = 0;
            }
            else
            {
                info[info_len] = data[i];
                info_len++;
            }
        }
        
        if (flag == DEF_ON)
        {
            return GPRS_PROCESS_OK;
        }
        else
        {
            //reply == AT_CMD_ERROR;
            return GPRS_PROCESS_ERROR;	
        }
    }
    else if (reply == AT_CMD_ERROR)
    {
        return GPRS_PROCESS_ERROR;	
    }
        
    info[0] = info[0];
    
    return GPRS_PROCESS_TIME_OUT;	

}

void GSMSmsDataGet (CPU_INT8U *pdata, CPU_INT16U *len)
{
    GprsStateRetTypeDef replay;
    CPU_INT16U sms_num;
    CPU_INT16U max_num;
    CPU_INT16U i;
    
    replay = ATcmdQuerySMSStatus(&sms_num, &max_num);
    
    *len = 0;
    if (replay != GPRS_PROCESS_OK)
    {
        return;
    }
    
    if (sms_num == 0)
    {
        return;
    }
    
    for (i = 1; i < max_num + 1; i++)
    {   
        replay = ATcmdGetSMSMessage(i, pdata, len);
        
        if (replay == GPRS_PROCESS_OK)
        {
            ATcmdRemoveIndexSMS(i);
            return;
        }
    }

}

////  SMS MODE SET
GprsStateRetTypeDef ATcmdSMSModeSet (CPU_INT8U mode)
{
    CPU_INT8U data[129];
    CPU_INT16U i;
    CPU_INT8U reply;
    
    i = sprintf((char *)data, "AT+CMGF=%d\r\n", mode);
    
    COM1RxFIFOClear();
    COM1SendData(data, i);
    memset(data, 0, sizeof(data));
    reply = GetATReply(data, 20, sizeof(data));
    
    if (reply == AT_CMD_OK)
    {   		
        return GPRS_PROCESS_OK;
    }
    else if (reply == AT_CMD_ERROR)
    {
        return GPRS_PROCESS_ERROR;	
    }
    else
    {
        return GPRS_PROCESS_TIME_OUT;	
    }
}