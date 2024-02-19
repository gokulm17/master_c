#include <stdio.h>
#include "../datatypes.h"

#ifndef ACCESSING_OUT_OF_BOUNDS

#define SIZE 10
uint8 array[SIZE];
void main()
{	
	/*fill the array*/
	memset((void*)&array,(int)0x55,sizeof(array));
	uint8 idx_11 = array[10];
	uint8 idx_ptr = (uint8)*((array)+10);
	/*try to access the variables with local var and pointer*/
	printf("Index 11 as value: %d\n",idx_11);
	printf("Index 11 as pointer: %d\n\n",idx_ptr);
	*(&array[0]+10) = 0xAA;
	/*try to access the variable with index and also with pointer*/
	printf("Index 11 as value: %d\n",array[10]);
	printf("Index 11 as pointer: %u",*((array)+10));
}
#endif
