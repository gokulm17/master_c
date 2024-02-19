#include <stdio.h>
#include "../datatypes.h"

#ifndef CAN_MESSAGE_FRAMEFORMAT

#define DOMINANT	LOGICAL_1
#define RECESSIVE	LOGICAL_0

#define LOGICAL_1	(1u)
#define LOGICAL_0	(0u)

typedef struct{
	uint8 sof:1;
	uint16 id:11;
	uint8 rtr:1;
	uint8 control_ide:1;
	uint8 control_r0:1;
	uint8 control_dlc:1;
	uint8 data[8];
	uint16 crc:15;
	uint8 crc_delim:1;
	uint8 ack:1;
	uint8 ack_delim:1;
	uint8 eof:7;
}CAN_Frame_FormatStd_t;

CAN_Frame_FormatStd_t CAN_Frame_FormatStd_s;
uint8 CAN_Linear_arr[sizeof(CAN_Frame_FormatStd_s)];

void makeFrameFormat(){
	CAN_Frame_FormatStd_s.sof = DOMINANT;
	CAN_Frame_FormatStd_s.id = 0xEF5; /*Corresponds to 3829d*/
	CAN_Frame_FormatStd_s.rtr = RECESSIVE;
	CAN_Frame_FormatStd_s.control_ide = DOMINANT;
	CAN_Frame_FormatStd_s.control_r0 = DOMINANT;
	CAN_Frame_FormatStd_s.control_dlc = 0x08;
	memset((void*)(&CAN_Frame_FormatStd_s.data),0xAA,sizeof(CAN_Frame_FormatStd_s.data));
	CAN_Frame_FormatStd_s.crc = 0x33;
	CAN_Frame_FormatStd_s.crc_delim = RECESSIVE;
	CAN_Frame_FormatStd_s.ack = DOMINANT;
	CAN_Frame_FormatStd_s.ack_delim = RECESSIVE;
	CAN_Frame_FormatStd_s.eof = 0x55;
	
	printf("Size of CAN Frame: %d ", sizeof(CAN_Frame_FormatStd_s));
	memcpy((void*)CAN_Linear_arr,(const void*) &CAN_Frame_FormatStd_s, sizeof(CAN_Frame_FormatStd_s));
}

void printFrametoConsole(){
	int itr;
	for(itr = 0; itr < sizeof(CAN_Linear_arr); itr++){
		printf("\nIdx: %d Data: %d", itr, CAN_Linear_arr[itr]);
	}
}

void main(){
	makeFrameFormat();
	printFrametoConsole();
}

#endif
