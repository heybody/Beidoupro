/*************************************************************************************************************
*                                              INCLUDE FILES                                                 *
*************************************************************************************************************/
#include <app.h>


/*************************************************************************************************************
*                                                CONSTANTS                                                   *
*************************************************************************************************************/
#pragma location = "ConstSection1"
__root const CPU_INT32U FirmwareBoot = FIRMWARE_BOOT_INIT;

#pragma location = "ConstSection2"
__root const sBootInfoTypeDef BootInfo = 
{
    .init_version     = FIRMWARE_VERSION,\
    .init_run_addr    = FIRMWARE_INIT_RUN_ADDR,\
    .updata_info_addr = FIRMWARE_UPDATA_INFO_ADDR,\
    .updata_run_addr  = FIRMWARE_UPDATA_RUN_ADDR,\
    .load_info_addr   = FIRMWARE_LOAD_INFO_ADDR,\
    .load_addr        = FIRMWARE_LOAD_ADDR,\
    .sn.deveice       = STDFEM_SERIAL_ID_NUMBER,
};

#pragma location = "ConstSection3"
__root const CPU_INT32U FirmwareUpdataInfo = 0;

#pragma location = "ConstSection4"
__root const CPU_INT32U FirmwareLoadInfo = 0;


/*************************************************************************************************************
*                                              LOCAL TABLES                                                  *
*************************************************************************************************************/
static sOnLineInfoTypeDef DownloadInfo;
static CPU_INT32U DownloadPackageSize;
static CPU_INT32U DownloadPackageCount;

/*************************************************************************************************************
*                                            FUNCTION PROTOTYPES                                             *
*************************************************************************************************************/
void Boot (void)
{
    sFirmwareInfoTypeDef *info;
    CPU_INT32U i;
    CPU_INT32U bank;
    CPU_INT32U boot;
    
    if (FirmwareBoot == FIRMWARE_BOOT_UPDATA)
    {
        info = (sFirmwareInfoTypeDef *)BootInfo.load_info_addr;
        if (info->info_crc == GetCRC16((const CPU_INT8U *)info, sizeof (sFirmwareInfoTypeDef) - 10))
        {
            if (info->code_crc == GetCRC16((const CPU_INT8U *)BootInfo.load_addr, info->code_size))
            {
                CM3DisableIrq();
                DevFlashUnlock();
                DevFlashErase(BootInfo.updata_info_addr);
                DevFlashWrite(BootInfo.updata_info_addr, (CPU_INT8U *)BootInfo.load_info_addr, sizeof(sFirmwareInfoTypeDef));
                bank = info->code_size / DEV_FLASH_BANK_SIZE;
                if (info->code_size % DEV_FLASH_BANK_SIZE != 0)
                {
                    bank += 1;
                }
                for (i = 0; i < bank; i++)
                {
                    DevFlashErase(BootInfo.updata_run_addr + i * DEV_FLASH_BANK_SIZE);
                }
                DevFlashWrite(BootInfo.updata_run_addr, (CPU_INT8U *)BootInfo.load_addr, info->code_size);
                DevFlashErase(BootInfo.load_info_addr);
                DevFlashLock();
                CM3EnableIrq();
            }
        }
        
        info = (sFirmwareInfoTypeDef *)BootInfo.updata_info_addr;
        
        if (info->info_crc == GetCRC16((const CPU_INT8U *)info, sizeof (sFirmwareInfoTypeDef) - 10))
        {
            if (info->code_crc == GetCRC16((const CPU_INT8U *)BootInfo.updata_run_addr, info->code_size))
            {
                CM3DisableIrq();
                //CM3NVICSetVectorTable(FLASH_START_BASE, BootInfo.updata_run_addr);
                CM3SetMSP(*(CPU_INT32U *)BootInfo.updata_run_addr);
	
                ((void (*)(void))(*(CPU_INT32U *)(BootInfo.updata_run_addr + 4)))();
            }
        } 
    }
    
    if (FirmwareBoot == FIRMWARE_BOOT_UPDATA)
    {
        boot = FIRMWARE_BOOT_INIT;
        CM3DisableIrq();
        DevFlashUnlock();
        DevFlashErase(FIRMWARE_BOOT_STATUS_ADDR);
        DevFlashWrite(FIRMWARE_BOOT_STATUS_ADDR, (CPU_INT8U *)&boot, 4);
        DevFlashLock();
        CM3EnableIrq();
    }
}

CPU_INT16U FirmwareVersionGet (void)
{
    CPU_INT16U version;
    sFirmwareInfoTypeDef *info;
        
    switch (FirmwareBoot)
    {
        case FIRMWARE_BOOT_INIT:    version = BootInfo.init_version;
                                    break;
        case FIRMWARE_BOOT_UPDATA:  info = (sFirmwareInfoTypeDef *)BootInfo.updata_info_addr;
                                    version = info->code_ver;
                                    break;
        default:                    version = BootInfo.init_version;
                                    break;
    }
    
    return version;
}

sSNTypeDef STDFEMSNGet (void)
{
   sSNTypeDef sn;
   sFirmwareInfoTypeDef *info;
   
   switch (FirmwareBoot)
   {
       case FIRMWARE_BOOT_INIT:      sn = BootInfo.sn;
                                     break;
       case FIRMWARE_BOOT_UPDATA:    info = (sFirmwareInfoTypeDef *)BootInfo.updata_info_addr;
                                     sn = info->sn;
                                     break;
       default:                      sn = BootInfo.sn;
                                     break;
   }
   return sn;
}

void OnlineProcess (CPU_INT8U *pdata, CPU_INT32U len, FNCT_COMM comm)
{
    sOnLineHeadTypeDef *head;

    head = (sOnLineHeadTypeDef *)pdata;
    
    if (NToHS(head->crc) != GetCRC16(&pdata[ON_LINE_CRC_POS], NToHS(head->len) + ON_LINE_HEAD_SIZE - ON_LINE_CRC_LEN))
    {
        OnlineError(ON_LINE_ERROR_TYPE_CRC, comm);
        
        return;
    }
    
    switch (NToHS(head->type))
    {
        case ON_LINE_TYPE_VER:      OnlineFirmwareVersionGet(&head->data, NToHS(head->len), comm);
                                    break;
        case ON_LINE_TYPE_RESET:    OnlineReset();
                                    break;
        case ON_LINE_TYPE_INFO:     OnlineInfo(&head->data, NToHS(head->len), comm);
                                    break;
        case ON_LINE_TYPE_PACK:     OnlinePackage(&head->data, NToHS(head->len), comm);
                                    break;
        case ON_LINE_TYPE_REBOOT:   OnlineReboot(&head->data, NToHS(head->len), comm);
                                    break;
        case ON_LINE_TYPE_SN:       OnlineSN(&head->data, NToHS(head->len), comm);
        default:                    break;
    }
}

void OnlineError (CPU_INT8U error, FNCT_COMM comm)
{
    CPU_INT8U data[SOCKET_HEAD_SIZE + ON_LINE_HEAD_SIZE + ON_LINE_REPLAY_SIZE_ERROR];
    sOnLineHeadTypeDef *head;
    sOnLineErrorReplayTypeDef *replay;
    
    head = (sOnLineHeadTypeDef *)&data[SOCKET_HEAD_SIZE];
    head->len = NToHS(ON_LINE_REPLAY_SIZE_ERROR);
    
    replay = (sOnLineErrorReplayTypeDef *)&head->data;
    
    replay->id = NToHL(0x00000000);
    replay->error = error;
    
    head->type = NToHS(ON_LINE_TYPE_REPLAY_ERROR);
    
    head->crc = NToHS(GetCRC16(&data[SOCKET_HEAD_SIZE + ON_LINE_CRC_POS], ON_LINE_HEAD_SIZE - ON_LINE_CRC_LEN + ON_LINE_REPLAY_SIZE_ERROR));
        
    SocketPackageSend(ON_LINE_PORT, data, ON_LINE_HEAD_SIZE + ON_LINE_REPLAY_SIZE_ERROR); 
    
    comm(data, SOCKET_HEAD_SIZE + ON_LINE_HEAD_SIZE + ON_LINE_REPLAY_SIZE_ERROR);
}

void OnlineFirmwareVersionGet (CPU_INT8U *pdata, CPU_INT32U len, FNCT_COMM comm)
{
    CPU_INT8U data[SOCKET_HEAD_SIZE + ON_LINE_HEAD_SIZE + ON_LINE_REPLAY_SIZE_VER];
    sOnLineVerTypeDef *ver;
    sOnLineHeadTypeDef *head;
    sOnLineVerReplayTypeDef *replay;
    
    ver = (sOnLineVerTypeDef *)pdata;
    head = (sOnLineHeadTypeDef *)&data[SOCKET_HEAD_SIZE];
    
    head->len = NToHS(ON_LINE_REPLAY_SIZE_VER);
    replay = (sOnLineVerReplayTypeDef *)&head->data;
    
    replay->id = NToHL(0x00000000);
    if (ver->type == ON_LINE_VER_PRESENT)
    {
        replay->version = NToHS(FirmwareVersionGet());
    }
    else
    {
        replay->version = NToHS(BootInfo.init_version);
    }
    
    head->type = NToHS(ON_LINE_TYPE_REPLAY_VER);
    
    head->crc = NToHS(GetCRC16(&data[SOCKET_HEAD_SIZE + ON_LINE_CRC_POS], ON_LINE_HEAD_SIZE - ON_LINE_CRC_LEN + ON_LINE_REPLAY_SIZE_VER));
        
    SocketPackageSend(ON_LINE_PORT, data, ON_LINE_HEAD_SIZE + ON_LINE_REPLAY_SIZE_VER); 
    
    comm(data, SOCKET_HEAD_SIZE + ON_LINE_HEAD_SIZE + ON_LINE_REPLAY_SIZE_VER);
}

void OnlineReset (void)
{
    SystemReset();
}

void OnlineInfo (CPU_INT8U *pdata, CPU_INT32U len, FNCT_COMM comm)
{
    CPU_INT8U data[SOCKET_HEAD_SIZE + ON_LINE_HEAD_SIZE + ON_LINE_REPLAY_SIZE_INFO];
    CPU_INT32U i;
    CPU_INT32U bank;
    sOnLineInfoTypeDef *info;
    sOnLineHeadTypeDef *head;
    sOnLineInfoReplayTypeDef *replay;
    
    info = (sOnLineInfoTypeDef *)pdata;
    head = (sOnLineHeadTypeDef *)&data[SOCKET_HEAD_SIZE];
    
    head->len = NToHS(ON_LINE_REPLAY_SIZE_INFO);
    
    replay = (sOnLineInfoReplayTypeDef *)&head->data;
    
    DownloadInfo.version = NToHS(info->version);
    DownloadInfo.package = NToHS(info->package);
    DownloadInfo.size = NToHL(info->size);
    DownloadInfo.crc = NToHS(info->crc);
      
    if (DownloadInfo.version == FirmwareVersionGet())
    {
        replay->status = ON_LINE_INFO_VER_SAME; 
    }
    else if (DownloadInfo.package == 0)
    {
        replay->status = ON_LINE_INFO_PACKEG_NULL; 
    }
    else if (DownloadInfo.size == 0)
    {
        replay->status = ON_LINE_INFO_SIZE_NULL; 
    }
    else if (DownloadInfo.size > FIRMWARE_MAX_SIZE)
    {
        replay->status = ON_LINE_INFO_SIZE_ERROR; 
    }
    else
    {
        replay->status = ON_LINE_INFO_READY;
        
        DownloadPackageCount = 0;
        DownloadPackageSize = 0;
            
        bank = DownloadInfo.size / DEV_FLASH_BANK_SIZE;
            
        if (DownloadInfo.size % DEV_FLASH_BANK_SIZE != 0)
        {
            bank += 1;
        }
        
        CM3DisableIrq();
        DevFlashUnlock(); 
        for (i = 0; i < bank; i++)
        {
            while (DevFlashErase(FIRMWARE_LOAD_ADDR + i * DEV_FLASH_BANK_SIZE) != DEF_TRUE);
        }
        DevFlashLock();
        CM3EnableIrq();
    }
        
    replay->id = NToHL(0x00000000);
    
    head->type = NToHS(ON_LINE_TYPE_REPLAY_INFO);
    
    head->crc = NToHS(GetCRC16(&data[SOCKET_HEAD_SIZE + ON_LINE_CRC_POS], ON_LINE_HEAD_SIZE - ON_LINE_CRC_LEN + ON_LINE_REPLAY_SIZE_INFO));
        
    SocketPackageSend(ON_LINE_PORT, data, ON_LINE_HEAD_SIZE + ON_LINE_REPLAY_SIZE_INFO); 
    
    comm(data, SOCKET_HEAD_SIZE + ON_LINE_HEAD_SIZE + ON_LINE_REPLAY_SIZE_INFO);
}

void OnlinePackage (CPU_INT8U *pdata, CPU_INT32U len, FNCT_COMM comm)
{
    CPU_INT8U data[SOCKET_HEAD_SIZE + ON_LINE_HEAD_SIZE + ON_LINE_REPLAY_SIZE_PACK];
    CPU_BOOL flag;
    CPU_INT16U crc;
    sOnLinePackTypeDef *package;
    sOnLineHeadTypeDef *head;
    sOnLinePackReplayTypeDef *replay;
    sFirmwareInfoTypeDef firmware;
        
    package = (sOnLinePackTypeDef *)pdata;
    head = (sOnLineHeadTypeDef *)&data[SOCKET_HEAD_SIZE];
    replay = (sOnLinePackReplayTypeDef *)&head->data;
    
    replay->id = NToHL(0x00000000);
    
    if ((DownloadInfo.version != NToHS(package->version)) && (DownloadInfo.version != 0))
    {
        replay->error = ON_LINE_PACK_ERROR_VER;
        replay->data = NToHS(ON_LINE_PACK_DEFAULT_DATA);
    }
    else if (DownloadInfo.package == 0)
    {
        replay->error = ON_LINE_PACK_ON_INFO;
        replay->data = NToHS(ON_LINE_PACK_DEFAULT_DATA);
    }
    else if (NToHS(package->count) == DownloadPackageCount)
    {
        CM3DisableIrq();
        DevFlashUnlock();
        flag = DevFlashWrite(FIRMWARE_LOAD_ADDR + DownloadPackageSize, (CPU_INT8U *)&package->data, NToHS(package->len));
        DevFlashLock();
        CM3EnableIrq();
        
        if (flag == DEF_FALSE)
        {
            crc = 0;
            return;
        }
        
        DownloadPackageCount++;
        DownloadPackageSize += NToHS(package->len);
        
        if (DownloadPackageCount == DownloadInfo.package)
        {
            if (DownloadPackageSize == DownloadInfo.size)
            {
                crc = GetCRC16((const CPU_INT8U *)FIRMWARE_LOAD_ADDR, DownloadInfo.size);
                if (DownloadInfo.crc == crc)
                {
                    firmware.code_ver = DownloadInfo.version;
                    firmware.code_size = DownloadInfo.size;
                    firmware.code_crc = DownloadInfo.crc;
                    firmware.info_crc = GetCRC16((const CPU_INT8U *)&firmware, sizeof (sFirmwareInfoTypeDef) - 10);
                    
                    CM3DisableIrq();
                    DevFlashUnlock();
                    DevFlashErase(FIRMWARE_LOAD_INFO_ADDR);
                    DevFlashWrite(FIRMWARE_LOAD_INFO_ADDR, (CPU_INT8U *)&firmware, sizeof (sFirmwareInfoTypeDef));
                    DevFlashLock();
                    CM3EnableIrq();
                    
                    replay->error = ON_LINE_PACK_OK;
                    replay->data = NToHS(ON_LINE_PACK_DEFAULT_DATA);
                }
                else
                {
                    replay->error = ON_LINE_PACK_ERROR_CRC;
                    replay->data = NToHS(ON_LINE_PACK_DEFAULT_DATA);
                }
            }
            else
            {
                replay->error = ON_LINE_PACK_ERROR_SIZE;
                replay->data = NToHS(DownloadPackageSize);
            }
        }
        else if (DownloadPackageSize > DownloadInfo.size)
        {
            replay->error = ON_LINE_PACK_ERROR_OUT;
            replay->data = NToHS(ON_LINE_PACK_DEFAULT_DATA);
        }
        else
        {
            replay->error = ON_LINE_PACK_OK_COUNT;
            replay->data = NToHS(DownloadPackageCount);
        }
    }
    else
    {
        replay->error = ON_LINE_PACK_ERROR_COUNT;
        replay->data = NToHS(DownloadPackageCount);
    }
    
    head->type = NToHS(ON_LINE_TYPE_REPLAY_PACK);
    
    head->crc = NToHS(GetCRC16(&data[SOCKET_HEAD_SIZE + ON_LINE_CRC_POS], ON_LINE_HEAD_SIZE - ON_LINE_CRC_LEN + ON_LINE_REPLAY_SIZE_PACK));
        
    SocketPackageSend(ON_LINE_PORT, data, ON_LINE_HEAD_SIZE + ON_LINE_REPLAY_SIZE_PACK); 
    
    comm(data, SOCKET_HEAD_SIZE + ON_LINE_HEAD_SIZE + ON_LINE_REPLAY_SIZE_PACK);
}

void OnlineReboot (CPU_INT8U *pdata, CPU_INT32U len, FNCT_COMM comm)
{
    CPU_INT8U data[SOCKET_HEAD_SIZE + ON_LINE_HEAD_SIZE + ON_LINE_REPLAY_SIZE_REBOOT];
    CPU_INT32U status;
    sOnLineRebootTypeDef *reboot;
    sOnLineHeadTypeDef *head;
    sOnLineRebootReplayTypeDef *replay;
    
    reboot = (sOnLineRebootTypeDef *)pdata;
    head = (sOnLineHeadTypeDef *)&data[SOCKET_HEAD_SIZE];
    replay = (sOnLineRebootReplayTypeDef *)&head->data;
    
    status = NToHL(reboot->status);
    
    replay->id = NToHL(0x00000000);
    
    if (status == FirmwareBoot)
    {
        replay->status = ON_LINE_REBOOT_SAME;
    }
    else if ((status == FIRMWARE_BOOT_INIT) || (status == FIRMWARE_BOOT_UPDATA))
    {
        CM3DisableIrq();
        DevFlashUnlock();
        DevFlashErase(FIRMWARE_BOOT_STATUS_ADDR);
        DevFlashWrite(FIRMWARE_BOOT_STATUS_ADDR, (CPU_INT8U *)&status, 4);
        DevFlashLock();
        CM3EnableIrq();
        
        replay->status = ON_LINE_REBOOT_OK;
    }
    else
    {
        replay->status = ON_LINE_REBOOT_ERROR;
    }

    head->type = NToHS(ON_LINE_TYPE_REPLAY_REBOOT);
    
    head->crc = NToHS(GetCRC16(&data[SOCKET_HEAD_SIZE + ON_LINE_CRC_POS], ON_LINE_HEAD_SIZE - ON_LINE_CRC_LEN + ON_LINE_REPLAY_SIZE_REBOOT));
        
    SocketPackageSend(ON_LINE_PORT, data, ON_LINE_HEAD_SIZE + ON_LINE_REPLAY_SIZE_REBOOT); 
    
    comm(data, SOCKET_HEAD_SIZE + ON_LINE_HEAD_SIZE + ON_LINE_REPLAY_SIZE_REBOOT);
}

void OnlineSN(CPU_INT8U *pdata, CPU_INT32U len, FNCT_COMM comm)
{
    CPU_INT8U data[SOCKET_HEAD_SIZE + ON_LINE_HEAD_SIZE + ON_LINE_REPLAY_SIZE_SN];
    sFirmwareInfoTypeDef *info;
    sBootInfoTypeDef *bootinfo;
    sOnLineSNTypeDef *sn;
    sOnLineHeadTypeDef *head;
    sOnLineSNReplayTypeDef *replay;
    
    sn = (sOnLineSNTypeDef *)pdata;
    head = (sOnLineHeadTypeDef *)&data[SOCKET_HEAD_SIZE];
    head->len = NToHS(ON_LINE_REPLAY_SIZE_SN);
    
    replay = (sOnLineSNReplayTypeDef *)&head->data;
    
    if (sn->type == ON_LINE_SN_INIT)
    {
        bootinfo = (sBootInfoTypeDef *)FIRMWARE_INIT_INFO_ADDR;
        replay->sn.deveice = NToHS(bootinfo->sn.deveice);
        memcpy(replay->sn.time, bootinfo->sn.time, sizeof(bootinfo->sn.time));
        replay->status = ON_LINE_SN_INIT;
    }
    else
    {
        info = (sFirmwareInfoTypeDef *)FIRMWARE_UPDATA_INFO_ADDR;
        replay->sn.deveice = NToHS(info->sn.deveice);
        memcpy(replay->sn.time, info->sn.time, sizeof(info->sn.time));
        replay->status = ON_LINE_SN_UPDATE;
    }
    
    head->type = NToHS(ON_LINE_TYPE_REPLAY_SN);
    
    head->crc = NToHS(GetCRC16(&data[SOCKET_HEAD_SIZE + ON_LINE_CRC_POS], ON_LINE_HEAD_SIZE - ON_LINE_CRC_LEN + ON_LINE_REPLAY_SIZE_SN));
        
    SocketPackageSend(ON_LINE_PORT, data, ON_LINE_HEAD_SIZE + ON_LINE_REPLAY_SIZE_SN); 
    
    comm(data, SOCKET_HEAD_SIZE + ON_LINE_HEAD_SIZE + ON_LINE_REPLAY_SIZE_SN);
}


/*************************************************************************************************************
*                                               MODULE END                                                   *
*************************************************************************************************************/
