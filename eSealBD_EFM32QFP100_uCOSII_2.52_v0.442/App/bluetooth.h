
#ifndef		_BLUETOOTH_H_
#define		_BLUETOOTH_H_

#include "stdint.h"
#include "ringbuf.h"

#define 	BLE_DATA_STX     										0x02
#define 	BLE_DATA_ETX     										

#define		BLE_DATA														0x80

#define		BLE_DATA_CMD_DIR_UPLOAD							(0x30+BLE_DATA)
#define		BLE_DATA_CMD_DIR_ACK								(0x30)
#define		BLE_DATA_CMD_VACANCY_UPLOAD					(0x31+BLE_DATA)
#define		BLE_DATA_CMD_VACANCY_ACK						(0x31)
#define		BLE_DATA_CMD_BUTTION_OK_UPLOAD			(0x32+BLE_DATA)
#define		BLE_DATA_CMD_BUTTION_OK_ACK					(0x32)
#define		BLE_DATA_CMD_BUTTION_GROUP1_UPLOAD	(0x33+BLE_DATA)
#define		BLE_DATA_CMD_BUTTION_GROUP1_ACK			(0x33)
#define		BLE_DATA_CMD_BUTTION_GROUP2_UPLOAD	(0x34+BLE_DATA)
#define		BLE_DATA_CMD_BUTTION_GROUP2_ACK			(0x34)
#define		BLE_DATA_CMD_BUTTION_GROUP3_UPLOAD	(0x35+BLE_DATA)
#define		BLE_DATA_CMD_BUTTION_GROUP3_ACK			(0x35)
#define		BLE_DATA_CMD_BUTTION_GROUP4_UPLOAD	(0x36+BLE_DATA)
#define		BLE_DATA_CMD_BUTTION_GROUP4_ACK			(0x36)

#define		BLE_DATA_CMD_WINDOW_GROUP1_UPLOAD		(0x40)
#define		BLE_DATA_CMD_WINDOW_GROUP1_ACK			(0x40+BLE_DATA)
#define		BLE_DATA_CMD_WINDOW_GROUP2_UPLOAD		(0x41)
#define		BLE_DATA_CMD_WINDOW_GROUP2_ACK			(0x41+BLE_DATA)
#define		BLE_DATA_CMD_WINDOW_GROUP3_UPLOAD		(0x42)
#define		BLE_DATA_CMD_WINDOW_GROUP3_ACK			(0x42+BLE_DATA)
#define		BLE_DATA_CMD_WINDOW_GROUP4_UPLOAD		(0x43)
#define		BLE_DATA_CMD_WINDOW_GROUP4_ACK			(0x43+BLE_DATA)


typedef __packed struct{
			   uint8_t	u8StartCode;
			   uint8_t 	u8Len;
				 uint8_t	u8Cmd;
			   uint8_t	u8Data[32];
//					uint8_t	u8Data[16];
			   uint8_t 	u8Checksum;
			  }tsPacketOfTaximeter;

typedef __packed struct{
	uint16_t	u8DataOfAddr1:8;
	uint16_t	u4NumOfKnifeHigh:4;
	uint16_t	u4Addr1:4;

	uint16_t	u8DataOfAddr2:8;
	uint16_t	u4NumOfKnifeLow:4;
	uint16_t	u4Addr2:4;
	
	uint16_t	u8DataOfAddr3:8;
	uint16_t	u4NumOfMainAxisHigh:4;
	uint16_t	u4Addr3:4;
	
	uint16_t	u8DataOfAddr4:8;
	uint16_t	u4NumOfMainAxisLow:4;
	uint16_t	u4Addr4:4;
	
	uint16_t	u8DataOfAddr5:8;
	uint16_t	u4DigitalLED5:4;
	uint16_t	u4Addr5:4;
	
	uint16_t	u8DataOfAddr6:8;
	uint16_t	u4DigitalLED6:4;
	uint16_t	u4Addr6:4;
	
	
	uint16_t	u8DataOfAddr7:8;
	uint16_t	u4DigitalLED7:4;
	uint16_t	u4Addr7:4;
	
	uint16_t	u8DataOfAddr8:8;
	uint16_t	u4DigitalLED8:4;
	uint16_t	u4Addr8:4;
	
	

}tsStrPLC_Data;
				

extern uint8_t u8CommuniData[];
//extern volatile uint32_t *pCommuniData;
extern uint32_t (*pCommuniData)[128];

extern tsPacketOfTaximeter sPacketOfBLE;

extern tsPacketOfTaximeter sPacketOfBLE_Send;

extern tsStrPLC_Data sStrPLC_Data;

int32_t BLE_RecCabData(tsPacketOfTaximeter *psPacketOfBLE_Data, tRingBufObject *psUserRxRingBuf);

void FillPacketOfBLE_Data( uint32_t u32InputCmd );

void BLE_DataProcess( uint32_t u32TimeSteer );
				
void FillPacketOfKeyData( uint8_t *u32KeyInput ,uint32_t data_len,uint8_t keycmd);

#endif
