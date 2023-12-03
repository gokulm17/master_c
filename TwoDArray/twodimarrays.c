#include "main.h"
#include <stdio.h>

#ifndef 2D_ARRAYS
void passpointer(uint8 *ptr);

void passpointer(uint8 *ptr)
{
  printf("Pointer base addr: 0x%x\n" ,ptr);
  printf("Pointer: 0x%x Val:%d\n", ptr,*(ptr));
  printf("Pointer: 0x%x Val:%d\n", ptr+1,*(ptr+1));
  printf("Pointer: 0x%x Val:%d\n", ptr+2,*(ptr+2));
  printf("Pointer: 0x%x Val:%d\n", ptr+3,*(ptr+3));
  printf("Pointer: 0x%x Val:%d\n", ptr+4,*(ptr+4));
  printf("Pointer: 0x%x Val:%d\n", ptr+5,*(ptr+5));
      
}

/*a 2D array is arranged as single dimensional array and indexed as 2D with roas and cols*/

void main()
{
  uint8 array[3][2] = {{1,2},{3,4},{5,6}};
  passpointer(&array);
}
#endif
