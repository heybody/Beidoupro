/*************************************************************************************************************
*                                              INCLUDE FILES                                                 *
*************************************************************************************************************/
#include <includes.h>

#include <app.h>


/*************************************************************************************************************
*                                                VARIABLES                                                   *
*************************************************************************************************************/
static OS_STK TaskAppStartStk[TASK_STK_SIZE];
static OS_STK TaskAppComm0Stk[TASK_STK_SIZE];
static OS_STK TaskAppComm1Stk[TASK_APP_COMM1_SIZE];
static OS_STK TaskAppComm2Stk[TASK_STK_SIZE];
static OS_STK TaskAppComm3Stk[TASK_STK_SIZE];
static OS_STK TaskAppComm4Stk[TASK_STK_SIZE];
static OS_STK TaskAppComm5Stk[TASK_STK_SIZE];

static OS_STK TaskAppEsealBDStk[TASK_STK_SIZE];
static OS_STK TaskAppEsealBDUpdataStk[TASK_STK_SIZE];

static OS_STK TaskAppComStk[TASK_STK_SIZE];
static OS_STK TaskAppRfStk[TASK_APP_RF_STK_SIZE];



/*************************************************************************************************************
*                                            FUNCTION STATEMENT                                              *
*************************************************************************************************************/
static void TaskAppStart (void *parg);
static void TaskAppComm0 (void *parg);
static void TaskAppComm1 (void *parg);
static void TaskAppComm2 (void *parg);
static void TaskAppComm3 (void *parg);
static void TaskAppComm4 (void *parg);
static void TaskAppComm5 (void *parg);
static void TaskAppEsealBD (void *parg);
static void TaskAppEsealBDUpdata (void *parg);

static void TaskAppCom (void *parg);
static void TaskAppRf (void *parg);

static void AppTaskCreate (void);
void GprsTaskReset (void);


/*************************************************************************************************************
*                                            GLOBAL VARIABLES                                                *
*************************************************************************************************************/
OS_EVENT *BDCaopMsg;
OS_EVENT *InmarsatRxMsg;
OS_EVENT *GprsAckMsg;

OS_EVENT *MsgRF0TxComplete;
OS_EVENT *MsgRF0RxComplete;
extern CPU_INT32U EsealBDID;
extern const sEsealBDWorkTypeDef EsealBDWork;


/*************************************************************************************************************
*                                              LOCAL TABLES                                                  *
*************************************************************************************************************/
//static sRFMsgTypeDef RFMsg;


/*************************************************************************************************************
*                                            FUNCTION PROTOTYPES                                             *
*************************************************************************************************************/
void main (void)
{
    DevInit();

    CM3EnableIrq();

    OSInit();

    OSTaskCreate(TaskAppStart, (void *)0, &TaskAppStartStk[TASK_STK_SIZE - 1], TASK_APP_START_PRIO);

    OSStart();

}

void TaskAppStart (void *parg)
{
    (void)parg;

    SysTickInit(DevClockCoreGet() / (CPU_INT32U)OS_TICKS_PER_SEC);

#if OS_TASK_STAT_EN > 0
    OSStatInit();
#endif

    AppTaskCreate();

    SocketInit();
    SocketPortOpen(ON_LINE_PORT, OnlineProcess, SOCKET_OPEN_PIPE_NULL);
    SocketPortOpen(ESEALBD_OPERATION_PORT, EsealBDOperationProcess, SOCKET_OPEN_PIPE_NULL);
    SocketPortOpen(ESEALBD_OFFLINE_PORT, EsealBDOfflineProcess, SOCKET_OPEN_PIPE_NULL);
    SocketPortOpen(ESEALBD_UPDATA_PORT, EsealBDUpdataProcess, SOCKET_OPEN_PIPE_NULL);
    SocketPortOpen(ESEALBD_SENSOR_PORT, EsealBDSebsorProcess, SOCKET_OPEN_PIPE_NULL);
    SocketPortOpen(0xA000, EsealBDOperationProcess, SOCKET_OPEN_PIPE_NULL);
    SocketPortOpen(ESEALBD_GPRS_PORT, EsealBDGprsProcess, SOCKET_OPEN_PIPE_NULL);

    EsealBDInit();
    BspKeyInit(BSP_KEY1);
    BspLedInit(BSP_LED1);

    BspLedOn(BSP_LED1);

#if APP_WATCH_DOG_EN > 0
    DevWatchDogInit(DEV_WDOG0, WDOG_TIMEOUT_4000ms);
    DevWatchDogFeed(DEV_WDOG0);
#endif
    SensorInit();
    while (1)
    {
        OSTimeDly(1000);
        SensorDataUpdata();
        EsealSafeCheck();
        EsealBDUpdataUtc();
        BspLedToggle(BSP_LED1);

#if APP_WATCH_DOG_EN > 0
        DevWatchDogFeed(DEV_WDOG0);
#endif

    }
}

void AppTaskCreate (void)
{
    OSTaskCreate(TaskAppComm0, (void *)0, &TaskAppComm0Stk[TASK_STK_SIZE - 1], TASK_APP_COMM0_PRIO);
    OSTaskCreate(TaskAppComm1, (void *)0, &TaskAppComm1Stk[TASK_APP_COMM1_SIZE - 1], TASK_APP_COMM1_PRIO);
    OSTaskCreate(TaskAppComm2, (void *)0, &TaskAppComm2Stk[TASK_STK_SIZE - 1], TASK_APP_COMM2_PRIO);
    OSTaskCreate(TaskAppComm3, (void *)0, &TaskAppComm3Stk[TASK_STK_SIZE - 1], TASK_APP_COMM3_PRIO);
    OSTaskCreate(TaskAppComm4, (void *)0, &TaskAppComm4Stk[TASK_STK_SIZE - 1], TASK_APP_COMM4_PRIO);
    OSTaskCreate(TaskAppComm5, (void *)0, &TaskAppComm5Stk[TASK_STK_SIZE - 1], TASK_APP_COMM5_PRIO);
    OSTaskCreate(TaskAppEsealBD, (void *)0, &TaskAppEsealBDStk[TASK_STK_SIZE - 1], TASK_APP_ESEALBD_PRIO);
    OSTaskCreate(TaskAppEsealBDUpdata, (void *)0, &TaskAppEsealBDUpdataStk[TASK_STK_SIZE - 1], TASK_APP_ESEALBD_UPDATA_PRIO);
    OSTaskCreate(TaskAppCom, (void *)0, &TaskAppComStk[TASK_STK_SIZE - 1], TASK_APP_COM_PRIO);
    OSTaskCreate(TaskAppRf, (void *)0, &TaskAppRfStk[TASK_APP_RF_STK_SIZE - 1], TASK_APP_RF_PRIO);

    BDCaopMsg = OSMboxCreate((void *)0);
    InmarsatRxMsg = OSMboxCreate((void *)0);
    GprsAckMsg = OSMboxCreate((void *)0);

    MsgRF0TxComplete = OSMboxCreate((void *)0);
    MsgRF0RxComplete = OSMboxCreate((void *)0);



}

void TaskAppComm0 (void *parg)
{
    CPU_INT8U data[GNSS_DATA_MAX_SIZE];
    CPU_INT8U byte;

    (void)parg;

    BspHM1103CInit();

    GNSSPackageInit((sGnssPackageTypeDef *)data);

    while (1)
    {
        while (COM0RxFIFOIsEmpty() == DEF_FALSE)
        {
            byte = COM0RxFIFOOut();

            if (EsealBDID < 20000)
            {
                GNSSPackegReceive((sGnssPackageTypeDef *)data, &byte, 1);
            }
        }

        OSTimeDly(20);
    }
}

CPU_INT8U GprsPipe;

void TaskAppComm1 (void *parg)
{
    (void)parg;
    CPU_INT8U data[512];
    CPU_INT8U temp[256];
    CPU_INT16U len;

    CPU_BOOL flag;
    //GprsSendStatusTypeDef gprs_send_status;
    //CPU_INT32U  ticks;
    //CPU_INT16U  send_delay;

    GprsStateFlagSet(GPRS_GPRS_STATE_BUSY);
    GprsSocketStatusSet(DEF_OFF);

    COM1Init(115200);

    SocketPackageInit((sSocketPackageTypeDef *)data);
    SocketPipeRegister(&GprsPipe);
    SocketPortBind(ESEALBD_UPDATA_PORT, GprsPipe);
    SocketPortBind(ESEALBD_GPRS_PORT, GprsPipe);

    GprsInit();



    GprsProcessUblox(GPRS_STATE_AT_CHECK);

    ATcmdRemoveAllSMS();
    GprsStateFlagSet(GPRS_GPRS_STATE_FREE);
    while (1)
    {
        while (GprsStateFlagGet() == GPRS_GPRS_STATE_BUSY)
        {
            OSTimeDly(10);
        }

        GprsStateFlagSet(GPRS_GPRS_STATE_BUSY);

        flag = DEF_ON;

        // »½ÐÑ
        ATcmdWakeUp();
        //
        while (flag)
        {
            if (GprsSocketRxBufferGet(temp, &len, sizeof(temp)) == GPRS_PROCESS_OK)
            {
                GprsSocketStatusSet(DEF_ON);

                if (len < sizeof(temp))
                {
                    flag = DEF_OFF;
                }

                SocketPackageReceive((sSocketPackageTypeDef *)data, temp, len, ESEALBD_UPDATA_CMD_MAX_SIZE,
                                     GprsPipe, (FNCT_COMM)EsealBuffDataIn);

            }
            else
            {
                GprsSocketStatusSet(DEF_OFF);

                GprsProcessUblox(GPRS_STATE_RESTART);

                flag = DEF_OFF;
            }


        }

        GSMSmsDataGet(temp, &len);
        SocketPackageReceive((sSocketPackageTypeDef *)data, temp, len, ESEALBD_UPDATA_CMD_MAX_SIZE,
                             GprsPipe, (FNCT_COMM)EsealBuffDataIn);

        //
        ATcmdSetSleep(2000);
        OSTimeDly(1000);
        //
        GprsStateFlagSet(GPRS_GPRS_STATE_FREE);

        OSTimeDly(30000);
    }

}

CPU_INT8U Comm2Data[ESEALBD_OPERATION_CMD_MAX_SIZE];

void TaskAppComm2 (void *parg)
{
    //CPU_INT8U data[ESEALBD_OPERATION_CMD_MAX_SIZE];
    CPU_INT8U byte;
    CPU_INT8U pipe;
    CPU_INT16U count;
    (void)parg;

    BspBleInit();

    SocketPackageInit((sSocketPackageTypeDef *)Comm2Data);
    SocketPipeRegister(&pipe);
    SocketPortBind(ESEALBD_OPERATION_PORT, pipe);
    SocketPortBind(0xA000, pipe);
    SocketPortBind(ESEALBD_OFFLINE_PORT, pipe);
    count = 0;
    while (1)
    {
        while (COM2RxFIFOIsEmpty() == DEF_FALSE)
        {
            byte = COM2RxFIFOOut();
            SocketPackageReceive((sSocketPackageTypeDef *)Comm2Data, &byte, 1,
                                 ESEALBD_OPERATION_CMD_MAX_SIZE, pipe, (FNCT_COMM)COM2TxFIFOIn);

            count = 0;
        }

        OSTimeDly(100);

        count++;

        if (count > 20)
        {
            count = 0;

            SocketPackageInit((sSocketPackageTypeDef *)Comm2Data);
        }
    }
}

void TaskAppComm3 (void *parg)
{
    CPU_INT8U data[ESEALBD_UPDATA_CMD_MAX_SIZE];
    CPU_INT8U byte;
    sBDPackageTypeDef package;
    CPU_INT8U pipe;
    (void)parg;
    CPU_INT32U delay;

    COM3Init(115200);

    BDComInit();

    SocketPackageInit((sSocketPackageTypeDef *)data);
    SocketPipeRegister(&pipe);
    SocketPortBind(ESEALBD_UPDATA_PORT, pipe);

    sBDPackageInit(&package);

    package.flag  = DEF_OFF;
    package.count = 0;
    delay = 0;
    while (1)
    {
        while (COM3RxFIFOIsEmpty() == DEF_FALSE)
        {
            byte = COM3RxFIFOOut();
            BDComReceive(&package, &byte, 1);
            delay = 0;
        }

        while (BDComRxFIFOIsEmpty() == DEF_FALSE)
        {
            byte = BDComRxData();

            SocketPackageReceive((sSocketPackageTypeDef *)data, &byte, 1,
                                 ESEALBD_UPDATA_CMD_MAX_SIZE, pipe, (FNCT_COMM)BDBuffDataIn);
        }

        OSTimeDly(20);
        delay++;

        if (delay > (50 * 10))
        {
            SocketPackageInit((sSocketPackageTypeDef *)data);
            sBDPackageInit(&package);
        }
    }
}

void TaskAppComm4 (void *parg)
{
    CPU_INT8U byte;
    CPU_INT8U pipe;
    CPU_INT8U data[INMARSAT_DATA_MAX_SIZE];
    sInmarsatPackageTypeDef package;
    (void)parg;

    COM4Init(9600);

    SocketPackageInit((sSocketPackageTypeDef *)data);
    SocketPipeRegister(&pipe);
    SocketPortBind(ESEALBD_UPDATA_PORT, pipe);

    InmarsatReceivePackageInit(&package);

    while (1)
    {

        while (COM4RxFIFOIsEmpty() == DEF_FALSE)
        {
            byte = COM4RxFIFOOut();
            InmarsatPackageReceive(&package, &byte, 1);
        }

        while (InmarsatRxMsgFIFOIsEmpty() == DEF_FALSE)
        {
            byte = InmarsatRxMsgData();
            SocketPackageReceive((sSocketPackageTypeDef *)data, &byte, 1,
                                 ESEALBD_UPDATA_CMD_MAX_SIZE, pipe, (FNCT_COMM)InmarsatSendMsg);
        }

        OSTimeDly(20);
    }
}

void TaskAppComm5 (void *parg)
{
    CPU_INT8U data[ON_LINE_DATA_MAX_SIZE];
    CPU_INT8U byte;
    CPU_INT8U pipe;

    (void)parg;

    COM5Init(115200);

    SocketPackageInit((sSocketPackageTypeDef *)data);
    SocketPipeRegister(&pipe);
    SocketPortBind(ON_LINE_PORT, pipe);
    SocketPortBind(ESEALBD_SENSOR_PORT, pipe);

    while (1)
    {
        while (COM5RxFIFOIsEmpty() == DEF_FALSE)
        {
            byte = COM5RxFIFOOut();
            SocketPackageReceive((sSocketPackageTypeDef *)data, &byte, 1,
                                 ON_LINE_DATA_MAX_SIZE, pipe, (FNCT_COMM)COM5RxFIFOOut);
        }

        OSTimeDly(20);
    }
}

__no_init  static CPU_INT32U BDcnt;

void TaskAppEsealBD (void *parg)
{
    (void)parg;

    OSTimeDly(2000);

    while (1)
    {
        BDcnt++;
        EsealBDProcess(BDcnt);
        OSTimeDly(1000);
    }
}

void TaskAppEsealBDUpdata (void *parg)
{

    (void)parg;

    CPU_INT32U count;

    EsealBuffInit();
    //OSTimeDly(2000);
    OSTimeDly(60000);
    while (1)
    {
        count++;
        EsealBDProcessUpdata(count);
        OSTimeDly(1000);
    }
}



void TaskAppCom (void *parg)
{
    (void)parg;

    while (1)
    {
        COM0TxFIFOOut();
        //COM1TxFIFOOut();
        COM2TxFIFOOut();
        COM3TxFIFOOut();
        COM4TxFIFOOut();
        COM5TxFIFOOut();

        OSTimeDly(5);
    }
}

void TaskAppRf(void *parg)
{
    (void)parg;
//    CPU_INT8U data[128];
//    CPU_INT32U len;
//    CPU_BOOL RFFlag;
//    CPU_INT8U result;
//
//    if (RFInit(RF_A7153_0, RF_CH_DEFAULT) == DEF_FALSE)
//    {
//        RFFlag = DEF_OFF;
//    }
//    else
//    {
//        RFFlag = DEF_ON;
//    }
//
//    if (RFFlag == DEF_ON)
//    {
//        RFTRxIntRegister(RF_A7153_0, RF0TRxComplete);
//        RFTRxIntClear(RF_A7153_0);
//        RFTRxIntEnable(RF_A7153_0);
//        RFSleep(RF_A7153_0);
//    }

    while (1)
    {
//        memset(data, 0xcc, sizeof(data));
//        result = RFSetRx(RF_A7153_0, RF_CH_DEFAULT, 10);
//
//        if (result == RF_RX_OK)
//        {
//            if (RFRxData(RF_A7153_0, data, &len) == RF_RXD_OK)
//            {
//
//                 OSTimeDlyHMSM(0, 0, 0, 1000);
//
//                 RFTxInit(RF_A7153_0, RF_CH_DEFAULT, data, len);
//
//                 RFTx(RF_A7153_0, 1000);
//
//                 RFBuffInit(RF_A7153_0);
//
//            }
//        }
//
//        RFSleep(RF_A7153_0);

        OSTimeDlyHMSM(0, 0, 0, 10);
    }
}

void GprsTaskReset (void)
{
    OSTaskDel(TASK_APP_COMM1_PRIO);

    SocketPipeUnregister(GprsPipe);

    //OSTimeDlyHMSM(0, 0, 0, 10);
    GprsStateFlagSet(GPRS_GPRS_STATE_BUSY);
    GprsSocketStatusSet(DEF_OFF);
    OSTaskCreate(TaskAppComm1, (void *)0, &TaskAppComm1Stk[TASK_APP_COMM1_SIZE - 1], TASK_APP_COMM1_PRIO);
}


/*************************************************************************************************************
*                                               MODULE END                                                   *
*************************************************************************************************************/
