/*************************************************************************************************************
*                                              INCLUDE FILES                                                 *
*************************************************************************************************************/
#include <bsp.h>
#include <fifo.h>
#include <string.h>
#include <ucos_ii.h>
#include <queue.h>


/*************************************************************************************************************
*                                              GLOBLE TABLES                                                  *
*************************************************************************************************************/
extern OS_EVENT *BDCaopMsg;


/*************************************************************************************************************
*                                              LOCAL TABLES                                                  *
*************************************************************************************************************/
static CPU_INT8U BDComTxFIFO[BD_COM_TX_FIFO_SIZE + FIFO_INFO_SIZE];
static CPU_INT8U BDComRxFIFO[BD_COM_RX_FIFO_SIZE + FIFO_INFO_SIZE];

static CPU_INT8U BDSendBuff[BD_COM_DATA_MAX_SIZE];
static BDCOMStatusTypeDef BDStatus;
static sBDDataTypeDef BDData;
static CPU_BOOL BDComCaopFlag = DEF_OFF;


/*************************************************************************************************************
*                                            FUNCTION PROTOTYPES                                             *
*************************************************************************************************************/
void BDComInit (void)
{
    FIFOInit((FIFODataTypeDef *)BDComTxFIFO);
    FIFOInit((FIFODataTypeDef *)BDComRxFIFO);
    BDBuffInit();

    DevGPIOPinConfig(BSP_BD_COM_EN_PORT, BSP_BD_COM_EN_PIN, DEV_GPIO_PIN_MODE_OUT_PP,
                 DEV_GPIO_PIN_DRIVE_STANDARD, DEV_GPIO_PIN_FRQ_NORMAL);
    BspBdCOMEnable();
    //BspBdCOMDisable();

    OSTimeDly(2000);

    while (!BDModuleStatusGet(&BDStatus))
    {
        OSTimeDly(1000);
    }

}

void BspBdCOMEnable (void)
{
    DevGPIOPinOutSet(BSP_BD_COM_EN_PORT, BSP_BD_COM_EN_PIN);
}

void BspBdCOMDisable(void)
{
    DevGPIOPinOutClear(BSP_BD_COM_EN_PORT, BSP_BD_COM_EN_PIN);
}


CPU_INT8U GetReceiveDataLen (CPU_INT8U *pdata, CPU_INT16U len, CPU_INT8U *data_site)
{
    CPU_INT8U i;
    CPU_INT8U info[256];
    CPU_INT8U info_len;
    CPU_INT8U count;
    CPU_INT8U data_len;

    count = 0;
    info_len = 0;
    for (i = 0; i < len; i++)
    {
        if (pdata[i] == ',')
        {
            switch (count)
            {
                case 7: data_len = BDASSICToHex(info, info_len);
                        *data_site = i + 1;
                        return data_len;
                        //break;
                default: break;

            }

            count++;
            info_len = 0;
        }
        else
        {
            info[info_len] = pdata[i];
            info_len++;
        }
    }

    return 0;
}

BDCOMRXTypeDef BDComRxFIFOIn (CPU_INT8U *pdata, CPU_INT16U len)
{
    CPU_INT32U i;
    CPU_INT8U buff[BD_COM_DATA_MAX_SIZE];
    CPU_INT8U data_len;
    CPU_INT8U data_site;

    data_len = GetReceiveDataLen(&pdata[0], len, &data_site);

    for (i = data_site; i < (data_site + data_len); i++)
    {
        buff[i - data_site] = pdata[i];
    }

    if ((BD_COM_RX_FIFO_SIZE - GetFIFOCount((FIFODataTypeDef *)BDComRxFIFO, BD_COM_RX_FIFO_SIZE)) < data_len)
    {
        return BDCOM_ERROR_RX_FIFO_FULL;
    }

    for (i = 0; i < data_len; i++)
    {
        FIFOIn((FIFODataTypeDef *)BDComRxFIFO, &buff[i], BD_COM_RX_FIFO_SIZE);
    }

    return BDCOM_RX_OK;
}

void BDComReceive (sBDPackageTypeDef *package, CPU_INT8U *pdata, CPU_INT16U len)
{
    CPU_INT8U byte;
    CPU_INT8U checksum;

    for (CPU_INT32U i = 0; i < len; i++)
    {
        byte  = pdata[i];

        if ((byte == '$') && (package->flag == 0))
        {
            package->flag = 1;
            package->count = 0;
        }

        if (package->flag == 1)
        {
            package->data[package->count] = byte;

            if ((package->count > 0) && (package->data[package->count] == 0x0A) && (package->data[package->count - 1] == 0x0D))
            {
                checksum = 0;

                for (CPU_INT32U j = 0; j < (package->count - 2); j++)
                {
                    checksum ^= package->data[j];
                }

                if (checksum == package->data[package->count -2])
                {

                    if ((package->data[1] == 'C') && (package->data[2] == 'A') && (package->data[3] == 'O') && (package->data[4] == 'P'))
                    {
                        if (BDComCaopFlag == DEF_ON)
                        {
                            OSMboxPost(BDCaopMsg, &BDComCaopFlag);
                        }
                    }

                    if ((package->data[1] == 'C') && (package->data[2] == 'O') && (package->data[3] == 'U') && (package->data[4] == 'T'))
                    {
                      //  if (BDGetCoutSendID(package->data, package->count + 1) == BD_COMMANDER_ID)
                      //  {
                            BDComRxFIFOIn(package->data, package->count + 1);
                      //  }
                    }

                    package->flag = 0;
                    package->count = 0;
                    continue;
                }
                else
                {
                    package->flag = 0;
                    package->count = 0;
                    continue;
                }
            }

            package->count++;
            if (package->count > BD_COM_DATA_MAX_SIZE)
            {
                package->flag = 0;
                package->count = 0;
                continue;
            }
        }
    }
}

void BDComDATAPack(CPU_INT8U *buff, CPU_INT8U *pdata, CPU_INT16U len)
{
    CPU_INT32U i;
    CPU_INT8U checksum = 0;
//   CPU_INT8U pack[19] = {'$', 'T', 'T', 'C', 'A', ',', '1', ',', '2', '2', '0', '3', '6', '3', ',', '1', ',', '0', ','};
//    CPU_INT8U pack[19] = {'$', 'T', 'T', 'C', 'A', ',', '1', ',', '5', '2', '2', '8', '8', '5', ',', '1', ',', '1', ','};
    //CPU_INT8U pack[19] = {'$', 'T', 'T', 'C', 'A', ',', '1', ',', '2', '2', '5', '3', '7', '1', ',', '1', ',', '0', ','};
     CPU_INT8U pack[19] = {'$', 'T', 'T', 'C', 'A', ',', '1', ',', '5', '2', '2', '8', '8', '5', ',', '1', ',', '0', ','};
    memcpy(&buff[0], &pack[0], 19);
    if (len < 10)
    {
        buff[19] = len + 0x30;
        buff[20] = ',';
        memcpy(&buff[21], &pdata[0], len);
    }
    else
    {
        buff[19] = len / 10 + 0x30;
        buff[20] = len % 10 + 0x30;
        buff[21] = ',';
        memcpy(&buff[22], &pdata[0], len);
        len ++;
    }

    buff[20 + len + 1] = ',';

    for (i = 0; i < (len + 22); i++)
    {
        checksum ^= buff[i];
    }

    buff[len + 22] = checksum;
    buff[len + 23] = 0x0D;
    buff[len + 24] = 0x0A;

    len += BD_COM_PACK_DATA_SIZE;
}


void BDComSendData (CPU_INT8U *pdata, CPU_INT16U len)
{
    COM3SendData(pdata, len);
}

BDCOMTXTypeDef BDComTxFIFOIn (CPU_INT8U *pdata, CPU_INT16U len)
{
    if ((BD_COM_TX_FIFO_SIZE - GetFIFOCount((FIFODataTypeDef *)BDComTxFIFO, BD_COM_TX_FIFO_SIZE)) < len)
    {
        return BDCOM_ERROR_TX_FIFO_FULL;
    }

    for (CPU_INT32U i = 0; i < len; i++)
    {
        FIFOIn((FIFODataTypeDef *)BDComTxFIFO, &pdata[i], BD_COM_TX_FIFO_SIZE);
    }

    return BDCOM_TX_OK;
}

void BDComTxFIFOOut (void)
{
    CPU_INT8U count = 0;
    INT8U err;

    CPU_INT8U byte;
    CPU_INT8U tx_fifo_data[BD_COM_DATA_MAX_SIZE];
    //CPU_INT8U BDbuff[BD_COM_DATA_MAX_SIZE];
    CPU_INT32U i = 0;

    while (!FIFOIsEmpty((FIFODataTypeDef *)BDComTxFIFO))
    {
        FIFOOut((FIFODataTypeDef *)BDComTxFIFO, &byte, BD_COM_TX_FIFO_SIZE);
        tx_fifo_data[i] = byte;

        i++;
    }

    if (i > 0)
    {
        BDComDATAPack(&BDSendBuff[0], &tx_fifo_data[0], i);

BDComFifoTxData:

        BDComRxFIFOClear();
        BDComCaopFlag = DEF_ON;

        if (i < 10)
        {
            BDComSendData(BDSendBuff, i + BD_COM_PACK_DATA_SIZE);
        }
        else
        {
            BDComSendData(BDSendBuff, i + 1 + BD_COM_PACK_DATA_SIZE);
        }

        OSTimeDlyHMSM(0, 0, 60, 0);

        OSMboxPend(BDCaopMsg, 60000, &err);

        BDComCaopFlag = DEF_OFF;

        if (err != OS_NO_ERR)
        {
            count++;
            if (count > 0)
            {
                return;
            }

            goto BDComFifoTxData;
        }
    }
}



CPU_BOOL BDComRxFIFOIsEmpty (void)
{
    return FIFOIsEmpty((FIFODataTypeDef *)BDComRxFIFO);
}

CPU_INT8U BDComRxData (void)
{
    CPU_INT8U byte;

    FIFOOut((FIFODataTypeDef *)BDComRxFIFO, &byte, BD_COM_RX_FIFO_SIZE);

    return byte;
}

void BDComRxFIFOClear (void)
{
    while (!BDComRxFIFOIsEmpty())
    {
        BDComRxData();
    }

}

CPU_INT32U BDGetCoutSendID (CPU_INT8U *pdata, CPU_INT8U len)
{
    CPU_INT8U i, j;
    CPU_INT8U count;
    CPU_INT32U id;
    CPU_INT8U id_start;
    CPU_INT8U id_end;

    count = 0;
    id = 0;

    for (i = 0; i < len; i++)
    {
        if (pdata[i] == ',')
        {
            count++;

            if (count == 4)
            {
                id_start = i + 1;
            }

            if (count == 5)
            {
                id_end = i;
                id = 0;

                for (j = id_start; j < id_end; j++)
                {
                    id *= 10;
                    id += (pdata[j] - 0x30);
                }

                break;
            }
        }
    }

    return id;
}

CPU_BOOL BDModuleStatusGet(BDCOMStatusTypeDef *status)
{
    CPU_INT8U cmd[] = {0x24, 0x51, 0x53 ,0x54 ,0x41 ,0x2C ,0x30 ,0x2C ,0x03 ,0x0D ,0x0A};
    //CPU_INT8U cmd_tsta[] = "$TSTA";
    CPU_INT8U info[16];
    CPU_INT8U info_len;
    CPU_INT8U replay[256];
    CPU_INT16U i;
    CPU_INT8U count;
    CPU_INT8U len;
    CPU_INT8U *p;

    COM3RxFIFOClear();
    i = 0;

    BDComSendData(cmd, sizeof(cmd));
    OSTimeDly(3000);

    while (COM3RxFIFOIsEmpty() == DEF_FALSE)
    {
       replay[i]  = COM3RxFIFOOut();
       i++;

       if (i > sizeof (replay))
       {
            return DEF_OFF;
       }
    }

    p = (CPU_INT8U *)strstr((char *)replay, "$TSTA");//(char *)cmd_tsta);

    if ( p == NULL)
    {
        return DEF_OFF;
    }

    len = i - ((CPU_INT32U)p - (CPU_INT32U)replay);
    count = 0;

    for (i = 0; i < len; i++)
    {
        if (p[i] == ',')
        {

            if ((info_len == 0) && (count != 0))
            {
                return DEF_OFF;
            }

            switch (count)
            {
                case 1: status->ch1_power = BDASSICToHex(info, info_len);
                        break;
                case 2: status->ch2_power = BDASSICToHex(info, info_len);
                        break;
                case 3: status->ch1_lock_wave = BDASSICToHex(info, info_len);
                        break;
                case 4: status->ch2_lock_wave = BDASSICToHex(info, info_len);
                        break;
                case 5: status->responce_wave = BDASSICToHex(info, info_len);
                        break;
                case 6: status->single_status = BDASSICToHex(info, info_len);
                        break;
                case 7: status->power_status = BDASSICToHex(info, info_len);
                        break;
                case 8: status->id = BDASSICToHex(info, info_len);
                        break;
                case 9: status->broadcast_addr = BDASSICToHex(info, info_len);
                        break;
                case 10: status->service_period = BDASSICToHex(info, info_len);
                        break;
                case 11: status->buad = BDASSICToHex(info, info_len);
                        break;
                case 12:status->secret_module = BDASSICToHex(info, info_len);
                        break;
                case 13:status->height_module = BDASSICToHex(info, info_len);
                        break;
                default:break;

            }

            count++;
            info_len = 0;
        }
        else
        {
            info[info_len] = p[i];
            info_len++;
        }
    }


    return DEF_ON;
}

CPU_INT32U BDASSICToHex (CPU_INT8U *p, CPU_INT8U len)
{
    CPU_INT32U val;
    CPU_INT8U i;

    val = 0;

    for (i = 0; i < len; i++)
    {
        val *= 10;
        val += (p[i] - 0x30);
    }

    return val;
}

void BDBuffInit (void)
{
    QueueInit(&BDData.data_queue);
    BDData.data_queue_flag = DEF_OFF;
}


void BDBuffDataOut (CPU_INT8U *pdata, CPU_INT16U len)
{
    CPU_INT8U send_data[BD_COM_DATA_MAX_SIZE];

    CPU_INT8U time_count;
    CPU_INT8U err;

    BDComDATAPack(send_data, pdata, len);
    //count = 0;

    BDComRxFIFOClear();
    BDComCaopFlag = DEF_ON;
    time_count = 0;

    if (len < 10)
    {
        BDComSendData(send_data, len + BD_COM_PACK_DATA_SIZE);
    }
    else
    {
        BDComSendData(send_data, len + 1 + BD_COM_PACK_DATA_SIZE);
    }

    while (1)
    {
        OSMboxPend(BDCaopMsg, 1000, &err);
        time_count++;
        if ((time_count > 90) || (err == OS_NO_ERR))
        {
            break;
        }
    }

    BDComCaopFlag = DEF_OFF;
}


BDCOMTXQueueTypeDef BDBuffDataIn (CPU_INT8U *pdata, CPU_INT16U len)
{
    sBDDataItemTypeDef *item;
    void *temp;

    if (len > BD_COM_DATA_MAX_SIZE)
    {
        return BDCOM_ERROR_TX_SIZE_OUT_OF_RANGE;
    }

    while (BDData.data_queue_flag)
    {
        OSTimeDly(10);
    }

    //BDData.data_queue_flag = DEF_ON;

    QueueIn(&BDData.data_queue, &temp, sizeof(sBDDataItemTypeDef), BD_DATA_QUEUE_SIZE);

    item = (sBDDataItemTypeDef *)temp;

    item->len = len;

    memcpy(item->data, pdata, item->len);

    //BDData.data_queue_flag = DEF_OFF;

    return BDCOM_TX_QUEUE_OK;
}

void sBDPackageInit (sBDPackageTypeDef *package)
{
    package->count = 0;
    package->flag = DEF_OFF;

}

/*************************************************************************************************************
*                                               MODULE END                                                   *
*************************************************************************************************************/
