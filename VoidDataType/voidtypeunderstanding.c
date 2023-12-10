#include <stdio.h>
#include "../datatypes.h"

#ifndef VOID_DATA_TYPE
uint16 voidfunction_enter(void *argument);
void main()
{
	printf("Value: %d",voidfunction_enter(133));
}

uint16 voidfunction_enter(void *argument){
	return (uint16)argument;
}

#endif
