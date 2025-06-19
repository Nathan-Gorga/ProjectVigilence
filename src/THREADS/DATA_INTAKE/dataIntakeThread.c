#include "../data_threads.h"
#include "../../DATA_STRUCTURES/data_structures.h"

void *launchDataIntakeThread(void* args){
    
    printf("Data Intake Thread Launched\n");

    Ring_Buffer * eventRingBuffer = (Ring_Buffer*)args;

    printf("%d\n", eventRingBuffer->head);    

    return NULL;
}

