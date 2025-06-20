#include "../data_threads.h"
#include "../../DATA_STRUCTURES/data_structures.h"
#include "../../DATA_STRUCTURES/INTAKE_THREAD_BUFFER/intake_ring_buffer.h"

void *launchDataIntakeThread(void* args){
    
    printf(YELLOW""TAB"Launching Data Intake Thread...\n"RESET);
    
    Node * head = (Node *)args;

    assert(head != NULL);

    //INIT INTERNAL RING BUFFER
    Ring_Buffer * internalRingBuffer = initRingBuffer(INTERNAL_RING_BUFFER_SIZE);
    
    if(internalRingBuffer == NULL){
        perror(RED"ERROR : unable to create internal ring buffer\n"RESET);
        return NULL;
    }
    
    {// SEND READY SIGNAL TO MASTER
        pthread_mutex_lock(&lock);

        ready_count++;

        pthread_cond_signal(&cond);
        printf(YELLOW""TAB"Data Intake Thread Ready!\n"RESET);

        pthread_mutex_unlock(&lock);
    }

    //SEND START STREAM SIGNAL TO OPENBCI


    //RECEIVE DATA FROM OPENBCI

        //if there is data add it to internal ring

    //SHIFT FROM BASELINE?

        // if yes : add to eventRingBuffer

        // if no : WAS SENDING EVENT ?

            // if yes : CLOSE NODE AND ADD IT TO THE LIST then add to internal buffer
            
            // if no : add to internal buffer

    //INTERUPT : TERMINATE THREAD

    return NULL;
}

