
#include <string.h>

#include "stdint.h"
#include "bluetooth.h"
#include "ringbuf.h"




tsPacketOfTaximeter sPacketOfBLE;

tsPacketOfTaximeter sPacketOfBLE_Send;

uint8_t u8CommuniData[18] = {0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
														 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
														 0x00, 0x00};
//volatile uint32_t *pCommuniData;
uint32_t (*pCommuniData)[128];

void KeyStatusClear(void)
{	
		uint32_t i,j;
	
		for( i = 0; i < 8; i++ )
		{
				 for( j = 0; j < 8; j++ )
				 {
							if( key[i][j].ispressed == 1 )
							{
									key[i][j].pressstate =0;
							}
				 }// End for
		}
}
			
uint32_t SendCabData(uint8_t u8InputBuf[], tsPacketOfTaximeter *psPacketOfTaximeter)
{
		 uint32_t u32PacketLen, u32CheckSum = 0, i;

		 // ��ʽ����ʼ��	������		������		������		У����
		 // u32PacketLen��������У������ֽ���
		 u32PacketLen = psPacketOfTaximeter->u8Len;
		 // copy��������ʼ�뵽���������һ���ֽڣ���u32PacketLen + 1���ֽ�
		 memcpy( u8InputBuf, (uint8_t *)psPacketOfTaximeter, u32PacketLen + 1 );
		 
		 u8InputBuf[u32PacketLen + 1] = psPacketOfTaximeter->u8Checksum;
// 		 // ����У���
// 		 for( i = 0; i < u32PacketLen; i++ )
// 		 {
// 					u32CheckSum += u8InputBuf[i+1];
// 		 }
	
		 return u32PacketLen + 2;
	
}


int32_t BLE_RecCabData(tsPacketOfTaximeter *psPacketOfBLE_Data, tRingBufObject *psUserRxRingBuf)
{
		uint32_t u32RxLen, u32PacketLen, u32CheckSum = 0, i;
		uint8_t *pu8Tmp, u8Temp;
	
		u32RxLen = RingBufUsed(psUserRxRingBuf);
	
// 		if (sUsart3_entity.u8RxFlag == 1)
		if( u32RxLen > 1 )
		{
				// ���յ���������2bytes����
				
				// Ԥ��ȡ�������ݣ��ж��Ƿ�Ϊ���ݰ�ͷTAXIMETER_STX
				u8Temp = RingBufProbe(psUserRxRingBuf, 0);
				if( u8Temp == BLE_DATA_STX )
				{
						// �����ݰ�ͷ��������ŵĵڶ��ֽ��ǰ�������
						u32PacketLen = RingBufProbe(psUserRxRingBuf, 1);
					
						// ����������ĺϷ��ԣ������ܳ�����������ĳ���
						if( u32PacketLen > (32+2) )
						{
								// �쳣��ն����Σ����������������ֽ�
								RingBufReadOne(psUserRxRingBuf);
								RingBufReadOne(psUserRxRingBuf);
								return -1;
						}
						
						if( u32RxLen >= (u32PacketLen + 2) )
						{
								// ������ʾ���յ�һ����������
							
								pu8Tmp = (uint8_t *)psPacketOfBLE_Data;
								
								for( i = 0; i < (u32PacketLen + 1); i++ )
								{
										 // ���δӶ����ж������ݣ����������һ������ У���
										 // ��Ϊ����������32���ֽڽṹ����data��ĳ���ʱ��
										 // u32PacketLen.u8Checksum��ֵ��û����ȷ����ֵ����Ҫ�ֶ���ֵ��
										 pu8Tmp[i] = RingBufReadOne(psUserRxRingBuf);
										
										 // У��Ͳ��������ݰ�ͷ���ʴӵڶ����ֽڳ����뿪ʼ
										 if( i > 0 )
										 {
												 u32CheckSum += pu8Tmp[i];
										 }
								}// End for
								// �ֶ���ֵ��pu8Tmp[u32PacketLen + 1]Ϊ�յ����ݰ������һ��ֵ��
								psPacketOfBLE_Data->u8Checksum = RingBufReadOne(psUserRxRingBuf);
								
								if( psPacketOfBLE_Data->u8Checksum == (u32CheckSum & 0xff) )
								{
										// ���ش�������
//										sUsart3_entity.u16RxTotalNum = 0;										
										return 0;
								}
								// �����������ð����ݣ����ڼ�����������
								// У��������Ԥʾ�бȽ����ص�ͨ�Ŵ��󣬴�ʱ���FIFO
//								RingBufFlush(&sUsart3_UserRxRingBuf);
								RingBufFlush(psUserRxRingBuf);
								
						}// End if( u32RxLen >= (u32PacketLen + 2) )
						
						// ��������ȴ����ڼ�����������
				}
				else
				{
						// �������ݰ�ͷ���ն�һ�Σ�������������
						RingBufReadOne(psUserRxRingBuf);
				}


			}// End if( u32RxLen > 1 )
			
			// ������δ�յ���Ч����
			return -1;
}



void FillPacketOfBLE_Data( uint32_t u32InputCmd )
{
		uint32_t u32PacketLen, u32CheckSum = 0, i;
		uint16_t *pu16Tmp;
		int32_t	 i32TmpLowSpeedTime;
	
		sPacketOfBLE_Send.u8StartCode = BLE_DATA_STX;
	
		switch(u32InputCmd)
		{
				case BLE_DATA_CMD_DIR_UPLOAD:
						sPacketOfBLE_Send.u8Cmd = BLE_DATA_CMD_DIR_UPLOAD - BLE_DATA;
						sPacketOfBLE_Send.u8Len = 0x03;
						sPacketOfBLE_Send.u8Data[0] = 0x00;
				break;
				case BLE_DATA_CMD_DIR_ACK:
						sPacketOfBLE_Send.u8Cmd = BLE_DATA_CMD_DIR_ACK;
						sPacketOfBLE_Send.u8Len = 0x03;
						sPacketOfBLE_Send.u8Data[0] = 0x00;
				break;
				case BLE_DATA_CMD_VACANCY_UPLOAD:
						sPacketOfBLE_Send.u8Cmd = BLE_DATA_CMD_VACANCY_UPLOAD - BLE_DATA;
						sPacketOfBLE_Send.u8Len = 0x03;
						sPacketOfBLE_Send.u8Data[0] = 0x00;
				break;
				case BLE_DATA_CMD_VACANCY_ACK:
						sPacketOfBLE_Send.u8Cmd = BLE_DATA_CMD_VACANCY_ACK;
						sPacketOfBLE_Send.u8Len = 0x03;
						sPacketOfBLE_Send.u8Data[0] = 0x00;
				break;
				case BLE_DATA_CMD_BUTTION_OK_UPLOAD:
						sPacketOfBLE_Send.u8Cmd = BLE_DATA_CMD_BUTTION_OK_UPLOAD - BLE_DATA;
						sPacketOfBLE_Send.u8Len = 0x08;						
						sPacketOfBLE_Send.u8Data[0] = 0x14;				// ��
						sPacketOfBLE_Send.u8Data[1] = 0x03;				// ��
						sPacketOfBLE_Send.u8Data[2] = 0x10;				// ��
						sPacketOfBLE_Send.u8Data[3] = 0x12;				// ʱ
						sPacketOfBLE_Send.u8Data[4] = 0x12;				// ��
						sPacketOfBLE_Send.u8Data[5] = 0x00;				// ��
				break;
				case BLE_DATA_CMD_BUTTION_OK_ACK:
						sPacketOfBLE_Send.u8Cmd = BLE_DATA_CMD_BUTTION_OK_ACK;
						sPacketOfBLE_Send.u8Len = 0x03;
						sPacketOfBLE_Send.u8Data[0] = 0x00;
				break;
				
				case BLE_DATA_CMD_BUTTION_GROUP1_UPLOAD:
						sPacketOfBLE_Send.u8Cmd = BLE_DATA_CMD_BUTTION_GROUP1_UPLOAD - BLE_DATA;
				break;
				case BLE_DATA_CMD_BUTTION_GROUP1_ACK:
						// ƴ��1����
						sPacketOfBLE_Send.u8Cmd = BLE_DATA_CMD_BUTTION_GROUP1_ACK;
						sPacketOfBLE_Send.u8Len = 0x03;
						sPacketOfBLE_Send.u8Data[0] = 0x00;
				break;
				default:
				break;
		}
		
		u32PacketLen = sPacketOfBLE_Send.u8Len;
		
		// ����У���
		for( i = 0; i < u32PacketLen; i++ )
		{
				u32CheckSum += ((uint8_t *)&sPacketOfBLE_Send)[i+1];
		}
		
		sPacketOfBLE_Send.u8Checksum = u32CheckSum & 0xff;
}



tsStrPLC_Data sStrPLC_Data;


void BLE_DataProcess( uint32_t u32TimeSteer )
{
	uint32_t u32Cmd = 0, u32Tmp = 0, u32TimeSpan;
	static uint32_t su32Num = 0, su32LastTimeTick = 0;
	
//	uint32_t keyinput[16]={1};
	uint32_t data_len = 18;		// 16;
	int32_t parseok = 0;
	
	
	if( BLE_RecCabData( &sPacketOfBLE, &sUsart2_UserRxRingBuf ) == 0 )
	{
			// �յ���Ч����
			switch( sPacketOfBLE.u8Cmd )
			{
					case BLE_DATA_CMD_DIR_UPLOAD:
					break;
					case BLE_DATA_CMD_DIR_ACK:
							// �յ�PLC����
//							FillPacketOfBLE_Data(BLE_DATA_CMD_DIR_ACK);
							__disable_irq();
							memcpy( (uint8_t *)&sStrPLC_Data, (uint8_t *)sPacketOfBLE.u8Data, 32);
							__enable_irq();
							
					break;
					case BLE_DATA_CMD_VACANCY_UPLOAD:
					break;
					case BLE_DATA_CMD_VACANCY_ACK:
							// ���յ���λ
					break;
					case BLE_DATA_CMD_BUTTION_OK_UPLOAD:
					break;
					case BLE_DATA_CMD_BUTTION_OK_ACK:
						
					
							FillPacketOfBLE_Data(BLE_DATA_CMD_BUTTION_OK_ACK);
	 
					break;

					case BLE_DATA_CMD_BUTTION_GROUP1_UPLOAD:
					break;
					case BLE_DATA_CMD_BUTTION_GROUP1_ACK:
							FillPacketOfBLE_Data(BLE_DATA_CMD_BUTTION_GROUP1_ACK);
					break;
					case BLE_DATA_CMD_BUTTION_GROUP3_UPLOAD:
					break;
					case BLE_DATA_CMD_BUTTION_GROUP3_ACK:
							FillPacketOfBLE_Data(BLE_DATA_CMD_BUTTION_GROUP3_ACK);
					break;
					case BLE_DATA_CMD_BUTTION_GROUP4_UPLOAD:
					break;
					case BLE_DATA_CMD_BUTTION_GROUP4_ACK:
							FillPacketOfBLE_Data(BLE_DATA_CMD_BUTTION_GROUP4_ACK);
					break;
					
					case BLE_DATA_CMD_WINDOW_GROUP1_UPLOAD:
					break;
					case BLE_DATA_CMD_WINDOW_GROUP1_ACK:
							// ������
							FillPacketOfBLE_Data(BLE_DATA_CMD_WINDOW_GROUP1_ACK);
	 
							SendCabData( u8Usart2_SendBuff, &sPacketOfBLE_Send);
							Usart2_Send(u8Usart2_SendBuff, sPacketOfBLE_Send.u8Len + 2 );
					break;
					case BLE_DATA_CMD_WINDOW_GROUP2_UPLOAD:
					break;
					case BLE_DATA_CMD_WINDOW_GROUP2_ACK:
							// ������
							FillPacketOfBLE_Data(BLE_DATA_CMD_WINDOW_GROUP2_ACK);
	 
							SendCabData( u8Usart2_SendBuff, &sPacketOfBLE_Send);
							Usart2_Send(u8Usart2_SendBuff, sPacketOfBLE_Send.u8Len + 2 );
					break;

					default:
					break;
			}
	}
	else
	{
			if( u32TimeSteer >= su32LastTimeTick)
			{
					u32TimeSpan = u32TimeSteer - su32LastTimeTick;
			}
			else
			{
					u32Tmp = 0xffffffff - su32LastTimeTick;
					u32Tmp = u32Tmp + 1;
					u32TimeSpan = u32Tmp + u32TimeSteer;
			}
			
			if( u32TimeSpan >= 10 )
			{
					su32LastTimeTick = u32TimeSteer;
				
					// ÿ��20ms
//					u32Cmd = BLE_DATA_CMD_DIR_ACK + su32Num;
//					su32Num++;
//					su32Num = su32Num & 0x03;
				u32Cmd=BLE_DATA_CMD_DIR_ACK;
				
				
				
			}
			switch( u32Cmd )
			{
					case BLE_DATA_CMD_DIR_UPLOAD:
					break;
					case BLE_DATA_CMD_DIR_ACK:
							CON_485 = 0;
//							FillPacketOfBLE_Data(BLE_DATA_CMD_DIR_ACK);
							u8CommuniData[16] = GPIOE->IDR & 0xff;
							FillPacketOfKeyData( u8CommuniData ,data_len,u32Cmd);
					
//							parseok=BLE_RecCabData( &sPacketOfBLE, &sUsart2_UserRxRingBuf );
							
					
							SendCabData( u8Usart2_SendBuff, &sPacketOfBLE_Send);
							Usart2_Send(u8Usart2_SendBuff, sPacketOfBLE_Send.u8Len + 2 );
						
							KeyStatusClear();
//							CON_485 = 1;
					break;
					case BLE_DATA_CMD_VACANCY_ACK:
							CON_485 = 0;
							FillPacketOfBLE_Data(BLE_DATA_CMD_VACANCY_ACK);
							SendCabData( u8Usart2_SendBuff, &sPacketOfBLE_Send);
							Usart2_BlockSend(u8Usart2_SendBuff, sPacketOfBLE_Send.u8Len + 2 );
							CON_485 = 1;
					break;
					case BLE_DATA_CMD_BUTTION_OK_ACK:
							CON_485 = 0;
							FillPacketOfBLE_Data(BLE_DATA_CMD_BUTTION_OK_ACK);
							SendCabData( u8Usart2_SendBuff, &sPacketOfBLE_Send);
							Usart2_BlockSend(u8Usart2_SendBuff, sPacketOfBLE_Send.u8Len + 2 );
							CON_485 = 1;
					break;
					case BLE_DATA_CMD_BUTTION_GROUP1_ACK:
							CON_485 = 0;
							FillPacketOfBLE_Data(BLE_DATA_CMD_BUTTION_GROUP1_ACK);
							SendCabData( u8Usart2_SendBuff, &sPacketOfBLE_Send);
							Usart2_BlockSend(u8Usart2_SendBuff, sPacketOfBLE_Send.u8Len + 2 );
							CON_485 = 1;
					break;
					default:
					break;
			}		
	}
}




void FillPacketOfKeyData( uint8_t *u32KeyInput ,uint32_t data_len,uint8_t keycmd)
{
	uint32_t u32PacketLen, u32CheckSum = 0, i;
	uint8_t *packetofkeydata=sPacketOfBLE_Send.u8Data;
	uint32_t packetofkeydata_len=data_len+4;
//	uint32_t packetofkeydata[packetofkeydata_len];
	
	sPacketOfBLE_Send.u8StartCode = BLE_DATA_STX;	
	
	sPacketOfBLE_Send.u8Len=data_len+2;
	sPacketOfBLE_Send.u8Cmd=keycmd;
	
	for(i=0;i<data_len;i++)
		*(packetofkeydata+i)= (uint8_t)u32KeyInput[i];
	
		// ����У���
		for( i = 0; i < sPacketOfBLE_Send.u8Len; i++ )
		{
				u32CheckSum += ((uint8_t *)&sPacketOfBLE_Send)[i+1];
		}
		
		sPacketOfBLE_Send.u8Checksum = u32CheckSum & 0xff;	
	
}









