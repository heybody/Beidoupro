/*************************************************************************************************************
*                                              INCLUDE FILES                                                 *
*************************************************************************************************************/
#include <ucos_ii.h>

#include <app.h>


/*************************************************************************************************************
*                                              INCLUDE FILES                                                 *
*************************************************************************************************************/
void GSMInit (void)
{
    BspMG2639Disable();
    OSTimeDly(3000); 
    BspMG2639IOInit();
    BspMG2639Enable();
    BspMG2639WakeupPinL();
    
    GSMRestart();  
}

void GSMPowerOn (void)
{    
    BspMG2639PowerkeyPinL();
    OSTimeDly(500); 
    BspMG2639PowerkeyPinH();
    OSTimeDly(3000); 
    BspMG2639PowerkeyPinL(); 
    
    GSMReset();
    
    OSTimeDly(1000); 
    
    BspMG2639PowerkeyPinL();
    OSTimeDly(500); 
    BspMG2639PowerkeyPinH();
    OSTimeDly(3000); 
    BspMG2639PowerkeyPinL(); 
}

void GSMPowerOff (void)
{
    GSMReset();
}

void GSMReset (void)
{   
    BspMG2639SystemResetPinL(); 
    OSTimeDly(300);     
    BspMG2639SystemResetPinH();
    OSTimeDly(600);    
    BspMG2639SystemResetPinL(); 
}

void GSMNetSelect (void)
{ 
    CPU_INT8U state;
    CPU_INT8U replay;
    CPU_BOOL flag;
    GSMNetTypeDef net;
    CPU_INT8U n;
    
    flag = DEF_ON;
    state = GPRS_STATE_CREG_QUERY;
    net.n = 0;
    n = 0;
    
    while (flag)
    {
        switch (state)
        {
            case GPRS_STATE_CREG_QUERY:     replay = ATcmdCERGQuery();
                                            if ((replay == '1' )|| (replay == '5' ))
                                            {
                                                flag = DEF_OFF;
                                            } 
                                            else if (replay == '2')
                                            {  
                                                OSTimeDly(1000);    
                                                state = GPRS_STATE_CREG_QUERY;
                                            }
                                            else if (replay == '0')
                                            {
                                                state = GPRS_STATE_COPS_SEARCH;
                                            }
                                            else
                                            {
                                                flag = DEF_OFF;
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

void GSMRestart (void)
{  
    GSMReset();
    GSMPowerOn();
    OSTimeDly(5000); 
    GSMNetSelect();
}


void GSMProcess (IPDataTypeDef* tcpip, CPU_INT8U init)
{ 
    CPU_BOOL flag;
    CPU_INT8U state;
    CPU_INT8U replay;
    CPU_INT16U gprs_restart;
    CPU_INT16U tcp_restart;
    state = init;

    flag = DEF_ON;
    gprs_restart = 0;
    tcp_restart = 0;
    
    while (flag)
    {
        switch (state)
        {
            case GPRS_STATE_AT:	        replay = ATcmdAT();
                                        if (replay == GPRS_PROCESS_OK)
                                        {
                                            state = GPRS_STATE_ATEX;
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
            case GPRS_STATE_ATEX:       replay = ATcmdATEX(GPRS_DISPLAY_SWITCH);
                                        if (replay == GPRS_PROCESS_OK)
                                        {
                                            state = GPRS_STATE_ZIPTIMEOUT;			
                                        }
                                        else if (replay == GPRS_PROCESS_ERROR)
                                        {
                                            state = GPRS_STATE_AT;
                                        }
                                        else if (replay == GPRS_PROCESS_TIME_OUT)
                                        {
                                            state = GPRS_STATE_AT;
                                        }
                                        break;
            case GPRS_STATE_ZIPTIMEOUT:	replay = ATcmdZIPTIMEOUT(GPRS_CONNECT_TIMEOUT, GPRS_SEND_DATA_TIMEOUT);
                                        if (replay == GPRS_PROCESS_OK)
                                        {
                                            state = GPRS_STATE_ZSTR;
                                        }
                                        else if (replay == GPRS_PROCESS_ERROR)
                                        {
                                            state = GPRS_STATE_AT;
                                        }
                                        else if (replay == GPRS_PROCESS_TIME_OUT)
                                        {
                                            state = GPRS_STATE_AT;
                                        }                                        
                                        break; 
            case GPRS_STATE_ZSTR:	replay = ATcmdZSTR();
                                        if (replay == GPRS_PROCESS_OK)
                                        {
                                             state = GPRS_STATE_ZPPPSTATUS;
                                             gprs_restart = 0;
                                        }
                                        else if (replay == GPRS_PROCESS_ERROR)
                                        {
                                            state = GPRS_STATE_ZSTR;
                                            gprs_restart++;
                                            
                                            if (gprs_restart > 80)
                                            {
                                                gprs_restart = 0;
                                                state = GPRS_STATE_RESTART;
                                            }
                                        }
                                        else if (replay == GPRS_PROCESS_TIME_OUT)
                                        {
                                            gprs_restart = 0;
                                            state = GPRS_STATE_AT;
                                        } 
                                        break;
            case GPRS_STATE_ZPPPSTATUS:	replay = ATcmdZPPPSTATUS();
                                        if (replay == GPRS_PROCESS_OK)
                                        {
                                            state = GPRS_STATE_ZIPSTATUS;
                                        }
                                        else if (replay == GPRS_PROCESS_ERROR)
                                        {
                                            state = GPRS_STATE_ZPPPOPEN;
                                        }
                                        else if (replay == GPRS_PROCESS_TIME_OUT)
                                        {
                                            state = GPRS_STATE_ZSTR;
                                        }
                                        break;
            case GPRS_STATE_ZPPPOPEN:	replay = ATcmdZPPPOPEN();
                                        if (replay == GPRS_PROCESS_OK)
                                        {
                                            state = GPRS_STATE_ZPPPSTATUS;
                                        }
                                        else if (replay == GPRS_PROCESS_ERROR)
                                        {
                                            state = GPRS_STATE_ZSTR;
                                        }
                                        else if (replay == GPRS_PROCESS_TIME_OUT)
                                        {
                                            state = GPRS_STATE_ZSTR;
                                        }
                                        else if (replay == GPRS_PROCESS_RESTART)
                                        {
                                            state = GPRS_STATE_RESTART;
                                        }

                                        break;
            case GPRS_STATE_ZIPSTATUS:	replay = ATcmdZIPSTATUS(tcpip->n);
                                        if (replay == GPRS_PROCESS_OK)
                                        {
                                            flag = DEF_OFF;
                                        }
                                        else if (replay == GPRS_PROCESS_ERROR)
                                        {
                                            state = GPRS_STATE_ZIPSETUP;
                                        }
                                        else if (replay == GPRS_PROCESS_TIME_OUT)
                                        {
                                            state = GPRS_STATE_ZSTR;
                                        }
                                        break;
            case GPRS_STATE_ZIPSETUP:	replay = ATcmdZIPSETUP(tcpip->n, tcpip->ip, tcpip->port);
                                        if (replay == GPRS_PROCESS_OK)
                                        {
                                            state = GPRS_STATE_ZIPSTATUS;  
                                        }
                                        else if (replay == GPRS_PROCESS_ERROR)
                                        {
                                            state = GPRS_STATE_ZSTR;
                                        }
                                        else if (replay == GPRS_PROCESS_INVALID)
                                        {
                                            state = GPRS_STATE_AT;
                                        }
                                        else if (replay == GPRS_PROCESS_TIME_OUT)
                                        {
                                            state = GPRS_STATE_ZPPPSTATUS;
                                        }
                                        
                                        if (replay != GPRS_PROCESS_OK)
                                        {
                                            tcp_restart++;
                                            if (tcp_restart == 10)
                                            {
                                                state = GPRS_STATE_RESTART;
                                            }
                                        }
                                        else
                                        {
                                            tcp_restart = 0;
                                        }
                                        
                                        break;                            
            case GPRS_STATE_RESTART:    GSMRestart ();
                                        tcp_restart = 0;
                                        state = GPRS_STATE_AT;
                                        break;
            default:                    break;
        }
    }
}


CPU_INT8U ATcmdAT (void)
{
    CPU_INT8U data[256];
    CPU_INT8U count;
    CPU_INT8U reply;
    
    count = 3;
    memset(data, 0, 16);
    
    while (count > 0)
    {
        COM1RxFIFOClear();
        
        COM1SendData("AT\r\n", strlen("AT\r\n")); 
        memset(data, 0, sizeof(data));
        reply = GetATReply(data, 30, sizeof(data));

        if (reply == AT_CMD_OK)
        {                   
            return GPRS_PROCESS_OK;
        }
        
        if ((reply == AT_CMD_TIME_OUT) && (count == 1))
        {                   
            return GPRS_PROCESS_TIME_OUT;
        }        
        
        count--;
    }   
    
    return GPRS_PROCESS_ERROR;
}

CPU_INT8U ATcmdATEX (CPU_BOOL flag)
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

CPU_INT8U ATcmdZIPTIMEOUT (CPU_INT8U connect_timeout, CPU_INT8U send_data_timeout)
{
    CPU_INT8U data[256];
    CPU_INT16U i;
    CPU_INT8U reply;
    
    i = sprintf((char *)data, "AT+ZIPTIMEOUT=%d,%d\r\n", connect_timeout, send_data_timeout);
    
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

CPU_INT8U ATcmdZEDT (void)
{
    CPU_INT8U data[256];
    CPU_INT16U i;
    CPU_INT8U reply;
    
    
    
    i = sprintf((char *)data, "AT+ZEDT=1\r\n");
    
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

void GPRSWakeUpMode (void)
{
    ATcmdZEDT();  
}

CPU_INT8U ATcmdZSTR (void)
{
    CPU_INT8U data[256];
    CPU_INT8U count;
    CPU_INT8U reply;   
    
    count = 2;
    
    while (count > 0)
    {
        COM1RxFIFOClear();
        COM1SendData("AT+ZSTR=2\r\n", sizeof("AT+ZSTR=2\r\n") - 1);
        memset(data, 0, sizeof(data));
        reply = GetATReply(data, 15, sizeof(data));
        if (reply == AT_CMD_OK)
        {     
            if (strstr((char *)data, "+ZSTR: 2, 1") != NULL)
            {               
                return GPRS_PROCESS_OK;
            }            
        }
        else if (reply == AT_CMD_TIME_OUT)
        {
            return GPRS_PROCESS_TIME_OUT;	
        }
        
        OSTimeDlyHMSM(0, 0, 0, 200); 
        
        count--;
    }
    
    OSTimeDlyHMSM(0, 0, 0, 500);
    
    return GPRS_PROCESS_ERROR;
}

CPU_INT8U ATcmdZPPPSTATUS (void)
{
    CPU_INT8U data[256];
    CPU_INT8U reply;  
    
    COM1RxFIFOClear();
    COM1SendData("AT+ZPPPSTATUS\r\n", sizeof("AT+ZPPPSTATUS\r\n") - 1); 
    memset(data, 0, sizeof(data));
    reply = GetATReply(data, 30, sizeof(data));
    if (reply == AT_CMD_OK)
    {      
        if(strstr((char *)data, "+ZPPPSTATUS:ESTABLISHED") != NULL)
        {
            return GPRS_PROCESS_OK;
        }
        else
        {
            return GPRS_PROCESS_ERROR;
        }
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

CPU_INT8U ATcmdZPPPOPEN(void)
{
    CPU_INT8U data[256];
    CPU_INT8U reply; 
    memset(data, 0, sizeof(data));
    
    COM1RxFIFOClear();
    COM1SendData("AT+ZPPPOPEN\r\n", sizeof("AT+ZPPPOPEN\r\n") - 1); 
    memset(data, 0, sizeof(data));
    reply = GetATReply(data, 50, sizeof(data));
    if (reply == AT_CMD_OK)
    {
        if((strstr((char *)data, "ESTABLISHED") != NULL) || (strstr((char *)data, "CONNECTED") != NULL))
        {
             return GPRS_PROCESS_OK;
        }
        else
        {
            return GPRS_PROCESS_ERROR;
        }
    }
    else if (reply == AT_CMD_ERROR)
    {
        if (strstr((char *)data, "+ZPPPOPEN:FAIL") != NULL)
        {
             return GPRS_PROCESS_RESTART;
        }
        else
        {
            return GPRS_PROCESS_ERROR;	
        }
    }
    else
    {
        return GPRS_PROCESS_TIME_OUT;	
    }
}

CPU_INT8U ATcmdZIPSTATUS (CPU_INT8U n)
{
    CPU_INT8U data[256];
    CPU_INT16U i;
    CPU_INT8U reply; 
    
    i = sprintf((char *)data, "AT+ZIPSTATUS=%d\r\n", n);
    
    COM1RxFIFOClear();
    COM1SendData(data, i);    
    memset(data, 0, sizeof(data));
    reply = GetATReply(data, 20, sizeof(data));
    if (reply == AT_CMD_OK)
    {
        if(strstr((char *)data, "+ZIPSTATUS:ESTABLISHED") != NULL)
        {
            return GPRS_PROCESS_OK;
        }
        else
        {
            return GPRS_PROCESS_ERROR;
        }
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

CPU_INT8U ATcmdZIPSETUP (CPU_INT8U n, CPU_INT32U ip, CPU_INT16U port)
{
    CPU_INT8U data[256];
    CPU_INT16U i;
    CPU_INT8U reply; 
    
    i = sprintf((char *)data, 
                "AT+ZIPSETUP=%d,%d.%d.%d.%d,%d\r\n",
                n,
                (CPU_INT8U)((ip & 0xFF000000) >> 24), 
                (CPU_INT8U)((ip & 0x00FF0000) >> 16),
                (CPU_INT8U)((ip & 0x0000FF00) >> 8),
                (CPU_INT8U)(ip & 0x000000FF),
                port);
    
    COM1RxFIFOClear();
    COM1SendData(data, i); 
    memset(data, 0, sizeof(data));
    reply = GetATReply(data, (GPRS_CONNECT_TIMEOUT + 2) * 10, sizeof(data));
    if (reply == AT_CMD_OK)
    {      
        if((strstr((char *)data, "ZIPSETUP:CONNECTED") != NULL) || (strstr((char *)data, "ZIPSETUP:ESTABLISHED") != NULL))
        {
            return GPRS_PROCESS_OK;
        }
        else
        {
            return GPRS_PROCESS_ERROR;
        }
    }
    else if (reply == AT_CMD_ERROR)
    {
        if(strstr((char *)data, "+ZIPSETUP:INVALID") != NULL)
        {
            return GPRS_PROCESS_INVALID;
        }
        else
        {
            return GPRS_PROCESS_ERROR;
        }
   }
   else
   {
        return GPRS_PROCESS_TIME_OUT;	
   }
}

CPU_INT8U ATcmdZIPSEND (CPU_INT8U n, CPU_INT16U len)
{
    CPU_INT8U data[256];
    CPU_INT16U i;
 
    i = sprintf((char *)data, "AT+ZIPSEND=%d,%d\r\n", n, len);
    
    COM1RxFIFOClear();
    COM1SendData(data, i); 
    memset(data, 0, sizeof(data));
    GetATReply(data, 30, sizeof(data));    
    
    if(strstr((char *)data, ">") != NULL)
    {
        return GPRS_PROCESS_OK;
    }
    else
    {
        return GPRS_PROCESS_ERROR;
    }
}	

CPU_INT8U GetATReply (CPU_INT8U *pdata, CPU_INT16U delay, CPU_INT16U len)
{
    CPU_INT16U i;
    i = 0;
    
    while (delay > 0)
    {           
        while (!COM1RxFIFOIsEmpty())
        {
            pdata[i++] = COM1RxFIFOOut();  
            
            if (i >= len)
            {
                return AT_CMD_ERROR;
            }
        }
        
        pdata[i] = NULL;
        
        if (strstr((char *)pdata, "OK\r\n") != NULL)
        {
            return AT_CMD_OK;
        }        
        
        if (strstr((char *)pdata, "ERROR\r\n") != NULL)
        {
            return AT_CMD_ERROR;
        }   
        
        delay--;
        
        /*if(delay == 0)
        {
            return AT_CMD_TIME_OUT; 
        }*/
        
        OSTimeDlyHMSM(0, 0, 0, 100);  
    }    
    
    if (i == 0)
    {
        return AT_CMD_TIME_OUT;
    }
    else
    {
        return AT_CMD_ERROR;
    }
    
}

CPU_INT8U ATcmdZIPCLOSE (CPU_INT8U n)
{
    CPU_INT8U data[256];
    CPU_INT16U i;
    CPU_INT8U reply; 
    
    i = sprintf((char *)data, "AT+ZIPCLOSE=%d\r\n", n);
    
    COM1RxFIFOClear();
    COM1SendData(data, i); 
    memset(data, 0, sizeof(data));
    reply = GetATReply(data, 500, sizeof(data));
    if(reply == AT_CMD_OK)
    {
        if(strstr((char *)data, "OK\r\n") != NULL)
        {
            return GPRS_PROCESS_OK;
        }
        else
        {
            return GPRS_PROCESS_ERROR;
        }
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

CPU_INT8U ATcmdCERGQuery (void)
{
    CPU_INT8U data[256];
    CPU_INT8U reply;
    CPU_INT8U i;
    //CPU_INT8U mode;
    CPU_INT8U stat;
    
    //mode = '0';
    stat = '0';
    
    COM1RxFIFOClear();
        
    COM1SendData("AT+CREG?\r\n", strlen("AT+CREG?\r\n")); 
    memset(data, 0, sizeof(data));
    reply = GetATReply(data, 30, sizeof(data));

    if (reply == AT_CMD_OK)
    {  
        for (i = 0; i < 30; i++)
        {
            if (data[i] == ':')
            {
                //mode = data[i + 2];
                stat = data[i + 5];
                //stat = '0';//test
                break;
            }
        }
            
        return stat;
    }      

    return GPRS_PROCESS_ERROR;
}

CPU_INT8U ATcmdCOPSSearch (GSMNetTypeDef *net)
{
    CPU_INT8U  data[256];
    CPU_INT8U  reply;
    CPU_INT32U i, j, k;
    
    net->n = 0;

    COM1RxFIFOClear();
        
    COM1SendData("AT+COPS=?\r\n", strlen("AT+COPS?\r\n")); 
    memset(data, 0, sizeof(data));
    reply = GetATReply(data, 200, sizeof(data));

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

CPU_INT8U ATcmdCERGSet (void)
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

CPU_INT8U ATcmdCOPSSet (GSMNetNameTypeDef net)
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

CPU_INT8U ATcmdCOPSQuery (void)
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


/*************************************************************************************************************
*                                               MODULE END                                                   *
*************************************************************************************************************/