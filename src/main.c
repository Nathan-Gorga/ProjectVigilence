#include "definitions.h"
#include "THREADS/data_threads.h"
#include "DATA_STRUCTURES/EVENT_RING_BUFFER/event_ring_buffer.h"
#include "DATA_STRUCTURES/INTAKE_THREAD_BUFFER/intake_ring_buffer.h"


pthread_mutex_t lock = PTHREAD_MUTEX_INITIALIZER;

pthread_cond_t cond = PTHREAD_COND_INITIALIZER;

int ready_count = 0;

const int THREADS_TO_WAIT = 2;

Ring_Buffer * event_ring_buffer;


int main(void){
    
    printf(GREEN"Master Thread Launched\n"RESET);

    //INIT BOARD


    //INIT UART


    //INIT BUFFERS

    //defined in data_structures.h
    event_ring_buffer = initEventRingBuffer();
    if(event_ring_buffer == NULL){
        perror(RED"ERROR : unable to create event ring buffer\n"RESET);
        return 1;
    }


    Node * head = initNode();
    if(head == NULL){
        perror(RED"ERROR : unable to create event address list\n"RESET);
        return 1;
    }

    //HEARTBEAT TO OPENBCI


    //LAUNCH DATA PROCESSING THREAD
    PRINTF_DEBUG
    pthread_t dataProcessingThread;
    
    if(pthread_create(&dataProcessingThread, NULL, launchDataProcessingThread, head) != 0){
        perror(RED"ERROR : unable to create data processing thread\n"RESET);
        return 1;
    }
    PRINTF_DEBUG
    
    //LAUNCH DATA INTAKE THREAD
    pthread_t dataIntakeThread;
    
    if(pthread_create(&dataIntakeThread, NULL, launchDataIntakeThread, head) != 0){
        perror(RED"ERROR : unable to create data intake thread\n"RESET);
        return 1;
    }
    PRINTF_DEBUG
    
    {//wait for threads to each signal they are ready
        pthread_mutex_lock(&lock);
        while (ready_count < THREADS_TO_WAIT) {
            pthread_cond_wait(&cond, &lock);
        }
        printf(GREEN"All threads launched successfully\n"RESET);
        pthread_mutex_unlock(&lock);

        pthread_mutex_destroy(&lock);
        pthread_cond_destroy(&cond);
        
    }
    PRINTF_DEBUG

    //WAIT FOR DATA PROCESSING TO RESPOND
    pthread_join(dataProcessingThread, NULL);
    PRINTF_DEBUG

    //send ACK signal once the thread responds

    //WAIT FOR DATA INTAKE TO RESPOND
    pthread_join(dataIntakeThread, NULL);

    //send ACK signal once the thread responds

    PRINTF_DEBUG

    //TERMINATE MASTER THREAD
    freeList(head);
    freeRingBuffer(event_ring_buffer);
    printf(GREEN"NO SEGFAULTS ?!\n"RESET);

    return 0;
}

