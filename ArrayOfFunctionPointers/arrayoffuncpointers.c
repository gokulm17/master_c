#include <stdio.h>
#include "../datatypes.h"

#ifndef ARRAY_OF_FUNC_POINTERS

#define ADD	0
#define SUB	1
#define MUL	2
#define DIV	3

uint8 add(uint8, uint8);
uint8 sub(uint8, uint8);
uint8 mul(uint8, uint8);
uint8 div(uint8, uint8);

uint8 add(uint8 arg1, uint8 arg2){
	return (arg1 + arg2);
}

uint8 sub(uint8 arg1, uint8 arg2){
	return (arg1 - arg2);
}

uint8 mul(uint8 arg1, uint8 arg2){
	return (arg1 * arg2);
}

uint8 div(uint8 arg1, uint8 arg2){
	return (arg1 / arg2);
}

/*Cannot initialize function pointers*/
/* try using void types and for void arguments*/

uint8 (*arrofFunctions[])(uint8, uint8) = {add, sub, mul, div};

void main()
{	
	printf("Add value: %d\n", (*arrofFunctions[ADD])(10,2));
	printf("Sub value: %d\n", (*arrofFunctions[SUB])(10,2));
	printf("Mul value: %d\n", (*arrofFunctions[MUL])(10,2));
	printf("Div value: %d\n", (*arrofFunctions[DIV])(10,2));
}
#endif
