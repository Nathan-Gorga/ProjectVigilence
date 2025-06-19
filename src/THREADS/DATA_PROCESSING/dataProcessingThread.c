#include "../data_threads.h"
#include "../../DATA_STRUCTURES/data_structures.h"


void *launchDataProcessingThread(void* args){

    printf(BLUE""TAB"Launching Data Processing Thread...\n"RESET);

    Ring_Buffer * eventRingBuffer = (Ring_Buffer*)args;

    printf(BLUE""TAB"%d\n"RESET,eventRingBuffer->tail);   
 

    {// sending ready signal to master thread
        pthread_mutex_lock(&lock);

        ready_count++;

        pthread_cond_signal(&cond);
        printf(BLUE""TAB"Data Processing Thread Ready!\n"RESET);

        pthread_mutex_unlock(&lock);
    }


    return NULL;
}
