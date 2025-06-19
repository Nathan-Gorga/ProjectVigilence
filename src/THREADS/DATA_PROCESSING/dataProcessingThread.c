#include "../data_threads.h"
#include "../../DATA_STRUCTURES/data_structures.h"


void *launchDataProcessingThread(void* args){

    printf("Data Processing Thread Launched\n");
 
    Ring_Buffer * eventRingBuffer = (Ring_Buffer*)args;

    printf("%d\n",eventRingBuffer->tail);   
    return NULL;
}
