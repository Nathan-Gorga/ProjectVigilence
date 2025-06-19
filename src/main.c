#include "definitions.h"
#include "THREADS/data_threads.h"
#include "DATA_STRUCTURES/EVENT_RING_BUFFER/event_ring_buffer.h"
#include "DATA_STRUCTURES/INTAKE_THREAD_BUFFER/intake_ring_buffer.h"


pthread_mutex_t lock = PTHREAD_MUTEX_INITIALIZER;

pthread_cond_t cond = PTHREAD_COND_INITIALIZER;

int ready_count = 0;

const int THREADS_TO_WAIT = 2;

int main(void){
    
    printf(GREEN"Master Thread Launched\n"RESET);

    //INIT BOARD


    //INIT UART


    //INIT BUFFERS
    Ring_Buffer * eventRingBuffer = initEventRingBuffer();

    //HEARTBEAT TO OPENBCI


    //LAUNCH DATA PROCESSING THREAD
    pthread_t dataProcessingThread;
    
    if(pthread_create(&dataProcessingThread, NULL, launchDataProcessingThread, eventRingBuffer) != 0){
        perror(RED"ERROR : unable to create data processing thread\n"RESET);
        return 1;
    }
    
    //LAUNCH DATA INTAKE THREAD
    pthread_t dataIntakeThread;
    
    if(pthread_create(&dataIntakeThread, NULL, launchDataIntakeThread, eventRingBuffer) != 0){
        perror(RED"ERROR : unable to create data intake thread\n"RESET);
        return 1;
    }
    
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

    //WAIT FOR DATA PROCESSING TO RESPOND
    pthread_join(dataProcessingThread, NULL);

    //send ACK signal once the thread responds

    //WAIT FOR DATA INTAKE TO RESPOND
    pthread_join(dataIntakeThread, NULL);

    //send ACK signal once the thread responds


    //TERMINATE MASTER THREAD
    freeRingBuffer(eventRingBuffer);

    printf(GREEN"Mission successful!\n"RESET);

    return 0;
}

