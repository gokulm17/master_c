#include <stdio.h>
#include "../datatypes.h"

#ifndef FUNC_PTRS_AS_PARAM

//Job status
#define JOB_OK  0
#define JOB_NOT_OK  1
#define JOB_PENDING 2

//Job type
#define READ    0
#define WRITE   1
#define ERASE   2

void takeActionBasedUponCallbackFunction(void (*callbackFunct)(uint8*, uint8*));
void ReportJobStatus(uint8 jobType, uint8 jobResult);

// put the entire function pointer declaration in the parameter
void takeActionBasedUponCallbackFunction(void (*callbackFunct)(uint8*, uint8*)){
    uint8 jobType =0,jobResult = 0;
    jobType = READ;
    jobResult = JOB_PENDING;
    (*callbackFunct)(jobType, jobResult);
}

void ReportJobStatus(uint8 jobType, uint8 jobResult){
    printf("Inside func: \nJob type: %d\n", jobType);
    printf("Job result: %d", jobResult);
}

void main(){
    uint8 jobType =0,jobResult = 0;
    /*You cannot pass function pointer arguments, but you can process the parameters inside the */
    takeActionBasedUponCallbackFunction(ReportJobStatus);
    
}
#endif
