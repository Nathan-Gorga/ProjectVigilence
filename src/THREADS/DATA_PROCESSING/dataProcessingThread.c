#include "../data_threads.h"
#include "../../DATA_STRUCTURES/data_structures.h"


void *launchDataProcessingThread(void* args){

    printf("Launching Data Processing Thread...\n");

    Ring_Buffer * eventRingBuffer = (Ring_Buffer*)args;

    printf("%d\n",eventRingBuffer->tail);   
 

    {// sending ready signal to master thread
        pthread_mutex_lock(&lock);

        ready_count++;

        pthread_cond_signal(&cond);
        printf("Data Processing Thread Ready!\n");

        pthread_mutex_unlock(&lock);
    }


    return NULL;
}
