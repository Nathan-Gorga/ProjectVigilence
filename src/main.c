#include "definitions.h"
#include "THREADS/data_threads.h"

int main(void){
    
    printf("Hello, World!\n");

    //// comments in capital letters refer to particular stages in the architecture diagram

    //INIT BOARD


    //INIT UART


    //INIT BUFFERS


    //HEARTBEAT TO OPENBCI


    //LAUNCH DATA INTAKE THREAD
    pthread_t dataIntakeThread;
    
    pthread_create(&dataIntakeThread, NULL, initDataIntakeThread, (void*)"this is cool");
    
    //LAUNCH DATA PROCESSING THREAD
    pthread_t dataProcessingThread;

    pthread_create(&dataProcessingThread, NULL, initDataProcessingThread, (void*)"love this");


    //WAIT FOR DATA PROCESSING TO RESPOND
    pthread_join(dataProcessingThread, NULL);

    //send ACK signal once the thread responds

    //WAIT FOR DATA INTAKE TO RESPOND
    pthread_join(dataIntakeThread, NULL);


    //send ACK signal once the thread responds

    //TERMINATE MASTER THREAD
    printf("Mission successful!\n");
    return 0;
}

