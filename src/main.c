#include "definitions.h"
#include "THREADS/data_threads.h"
#include "DATA_STRUCTURES/data_structures.h"

int main(void){
    
    printf("Master Thread Launched\n");

    //// comments in capital letters refer to particular stages in the architecture diagram

    //INIT BOARD


    //INIT UART


    //INIT BUFFERS
    Ring_Buffer * eventRingBuffer = initEventRingBuffer();

    //HEARTBEAT TO OPENBCI


    //LAUNCH DATA INTAKE THREAD
    pthread_t dataIntakeThread;
    
    pthread_create(&dataIntakeThread, NULL, launchDataIntakeThread, eventRingBuffer);
    
    //LAUNCH DATA PROCESSING THREAD
    pthread_t dataProcessingThread;

    pthread_create(&dataProcessingThread, NULL, launchDataProcessingThread, eventRingBuffer);


    //WAIT FOR DATA PROCESSING TO RESPOND
    pthread_join(dataProcessingThread, NULL);

    //send ACK signal once the thread responds

    //WAIT FOR DATA INTAKE TO RESPOND
    pthread_join(dataIntakeThread, NULL);


    //send ACK signal once the thread responds

    //TERMINATE MASTER THREAD
    freeRingBuffer(eventRingBuffer);

    printf("Mission successful!\n");

    return 0;
}

