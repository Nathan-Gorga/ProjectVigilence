#include "../data_threads.h"
#include "../../DATA_STRUCTURES/data_structures.h"

void *launchDataIntakeThread(void* args){
    
    printf(YELLOW""TAB"Launching Data Intake Thread...\n"RESET);

    Ring_Buffer * eventRingBuffer = (Ring_Buffer*)args;
    
    printf(YELLOW""TAB"%d\n"RESET, eventRingBuffer->head);    


    {// sending ready signal to master thread
        pthread_mutex_lock(&lock);

        ready_count++;

        pthread_cond_signal(&cond);
        printf(YELLOW""TAB"Data Intake Thread Ready!\n"RESET);

        pthread_mutex_unlock(&lock);
    }



    return NULL;
}

