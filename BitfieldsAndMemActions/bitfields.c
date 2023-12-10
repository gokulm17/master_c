#include <stdio.h>
#include "../datatypes.h"

#ifndef BIT_FIELDS
typedef struct{
	uint8 bit1:1;
	uint8 bit2:1;
	uint8 bit3:1;
	uint8 bit4:1;
	uint8 bit5:1;
	uint8 bit6:1;
	uint8 bit7:1;
	uint8 bit8:1;
	}bits_t;

typedef union{
	bits_t bits_reg;
	uint8 byte;
	}byte_t;

void main(){
    byte_t byte_s;
    memset((void*)&byte_s, 1, sizeof(byte_t)); //try to memset for a value 1
    printf("Value: %d\n",byte_s.byte);
    byte_s.byte = 0xFF; //set all the bits to 1
    byte_s.bits_reg.bit3 = 0; //set the third bit to 0
    printf("Value: %d\n",byte_s.byte);
    
}

#endif
