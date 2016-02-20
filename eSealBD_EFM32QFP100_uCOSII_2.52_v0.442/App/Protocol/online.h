/*************************************************************************************************************
*                                                  MODULE                                                    *
*************************************************************************************************************/
#ifndef ONLINE_H
#define ONLINE_H

#ifdef __cplusplus
extern "C" {
#endif


/*************************************************************************************************************
*                                                 DEFINES                                                    *
*************************************************************************************************************/
#define FIRMWARE_VERSION                        24u

#define FIRMWARE_BOOT_STATUS_ADDR               0x00001000UL
#define FIRMWARE_INIT_INFO_ADDR                 0x00002000UL
#define FIRMWARE_UPDATA_INFO_ADDR               0x00003000UL
#define FIRMWARE_LOAD_INFO_ADDR                 0x00004000UL
#define FIRMWARE_INIT_RUN_ADDR                  0x00020000UL
#define FIRMWARE_UPDATA_RUN_ADDR                0x00040000UL
#define FIRMWARE_LOAD_ADDR                      0x00060000UL

#define STDFEM_SERIAL_ID_NUMBER                 0x1234UL

#define FIRMWARE_BOOT_INIT                      0x494E4954UL
#define FIRMWARE_BOOT_UPDATA                    0x55504441UL

#define FIRMWARE_MAX_SIZE                       (128u * 1024u)
#define TIME_MAX_SIZE                           6u
#define DEVEICE_MAX_SIZE                        2u
#define INCREASE_SIZE                           1u

#define ON_LINE_PORT                            0xB000

#define ON_LINE_HEAD_SIZE                       6u
#define ON_LINE_DATA_MAX_SIZE                   (256u + 32u)

#define ON_LINE_CRC_POS                         2u
#define ON_LINE_CRC_LEN                         2u
#define ON_LINE_DATA_POS                        6u

#define ON_LINE_REPLAY_SIZE_VER                 6u
#define ON_LINE_REPLAY_SIZE_INFO                5u
#define ON_LINE_REPLAY_SIZE_PACK                7u
#define ON_LINE_REPLAY_SIZE_REBOOT              5u
#define ON_LINE_REPLAY_SIZE_SN                  9u
#define ON_LINE_REPLAY_SIZE_ERROR               5u

#define ON_LINE_VER_PRESENT                     0u
#define ON_LINE_VER_INIT                        1u

#define ON_LINE_INFO_READY                      0u
#define ON_LINE_INFO_VER_SAME                   1u
#define ON_LINE_INFO_PACKEG_NULL                2u
#define ON_LINE_INFO_SIZE_NULL                  3u
#define ON_LINE_INFO_SIZE_ERROR                 4u

#define ON_LINE_PACK_OK                         0u
#define ON_LINE_PACK_OK_COUNT                   1u
#define ON_LINE_PACK_ERROR_COUNT                2u
#define ON_LINE_PACK_ERROR_SIZE                 3u
#define ON_LINE_PACK_ON_INFO                    4u
#define ON_LINE_PACK_ERROR_CRC                  5u
#define ON_LINE_PACK_ERROR_OUT                  6u
#define ON_LINE_PACK_ERROR_VER                  7u
#define ON_LINE_PACK_DEFAULT_DATA               0x0000

#define ON_LINE_REBOOT_SAME                     0u
#define ON_LINE_REBOOT_OK                       1u
#define ON_LINE_REBOOT_ERROR                    2u

#define ON_LINE_SN_INIT                         0u
#define ON_LINE_SN_UPDATE                       1u

#define ON_LINE_ERROR_TYPE_CRC                  0u

#define ON_LINE_TYPE_VER                        0x0B00u
#define ON_LINE_TYPE_RESET                      0x0B01u
#define ON_LINE_TYPE_INFO                       0x0B02u
#define ON_LINE_TYPE_PACK                       0x0B03u
#define ON_LINE_TYPE_REBOOT                     0x0B04u
#define ON_LINE_TYPE_SN                         0x0002U

#define ON_LINE_TYPE_REPLAY_VER                 0x0B10u
#define ON_LINE_TYPE_REPLAY_INFO                0x0B11u
#define ON_LINE_TYPE_REPLAY_PACK                0x0B12u
#define ON_LINE_TYPE_REPLAY_REBOOT              0x0B13u
#define ON_LINE_TYPE_REPLAY_ERROR               0x0B1Fu
#define ON_LINE_TYPE_REPLAY_SN                  0x1002u


/*************************************************************************************************************
*                                                  DATA TYPES                                                *
*************************************************************************************************************/
#pragma pack(1)

typedef struct
{
    CPU_INT16U deveice;
    CPU_INT8U  time[TIME_MAX_SIZE];
} sSNTypeDef;

typedef struct
{
    CPU_INT16U init_version;
    CPU_INT32U init_run_addr;
    CPU_INT32U updata_info_addr;
    CPU_INT32U updata_run_addr;
    CPU_INT32U load_info_addr;
    CPU_INT32U load_addr;
    sSNTypeDef sn;
} sBootInfoTypeDef;

typedef struct
{
    CPU_INT16U code_ver;
    CPU_INT32U code_size;
    CPU_INT16U code_crc;
    CPU_INT16U info_crc;
    sSNTypeDef sn;
} sFirmwareInfoTypeDef;

typedef struct
{
    CPU_INT16U crc;
    CPU_INT16U type;
    CPU_INT16U len;
    CPU_INT8U data;
} sOnLineHeadTypeDef;

typedef struct
{
    CPU_INT32U id;
    CPU_INT8U type;
} sOnLineVerTypeDef;

typedef struct
{
    CPU_INT32U id;
    CPU_INT16U version;
    CPU_INT16U package;
    CPU_INT32U size;
    CPU_INT16U crc;
} sOnLineInfoTypeDef;

typedef struct
{
    CPU_INT32U id;
    CPU_INT16U version;
    CPU_INT16U count;
    CPU_INT16U len;
    CPU_INT8U data;
} sOnLinePackTypeDef;

typedef struct
{
    CPU_INT32U id;
    CPU_INT32U status;
} sOnLineRebootTypeDef;

typedef struct
{
    CPU_INT8U type;
} sOnLineSNTypeDef;

typedef struct
{
    CPU_INT32U id;
    CPU_INT16U version;
} sOnLineVerReplayTypeDef;

typedef struct
{
    CPU_INT32U id;
    CPU_INT8U status;
} sOnLineInfoReplayTypeDef;

typedef struct
{
    CPU_INT32U id;
    CPU_INT8U error;
    CPU_INT16U data;
} sOnLinePackReplayTypeDef;

typedef struct
{
    CPU_INT32U id;
    CPU_INT8U status;
} sOnLineRebootReplayTypeDef;

typedef struct
{
    sSNTypeDef sn;
    CPU_INT8U status;
} sOnLineSNReplayTypeDef;

typedef struct
{
    CPU_INT32U id;
    CPU_INT8U error;
} sOnLineErrorReplayTypeDef;

#pragma pack()


/*************************************************************************************************************
*                                            FUNCTION STATEMENT                                              *
*************************************************************************************************************/
void Boot (void);
CPU_INT16U FirmwareVersionGet (void);
void OnlineProcess (CPU_INT8U *pdata, CPU_INT32U len, FNCT_COMM comm);
void OnlineFirmwareVersionGet (CPU_INT8U *pdata, CPU_INT32U len, FNCT_COMM comm);
sSNTypeDef STDFEMSNGet(void);
void OnlineError (CPU_INT8U error, FNCT_COMM comm);
void OnlineReset (void);
void OnlineInfo (CPU_INT8U *pdata, CPU_INT32U len, FNCT_COMM comm);
void OnlinePackage (CPU_INT8U *pdata, CPU_INT32U len, FNCT_COMM comm);
void OnlineReboot (CPU_INT8U *pdata, CPU_INT32U len, FNCT_COMM comm);
void OnlineSN(CPU_INT8U *pdata, CPU_INT32U len, FNCT_COMM comm);
void SystemReset (void);


/*************************************************************************************************************
*                                               MODULE END                                                   *
*************************************************************************************************************/
#ifdef __cplusplus
}
#endif

#endif
