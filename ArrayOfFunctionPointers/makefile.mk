CC      = gcc
CFLAGS  = -g
RM      = rm -f


default: all

all: ArrayOfFuncPtrs

Hello: arrayoffuncpointers.c
    $(CC) $(CFLAGS) -o Hello arrayoffuncpointers.c

clean veryclean:
    $(RM) ArrayOfFuncPtrs