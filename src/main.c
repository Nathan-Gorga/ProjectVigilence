#include "definitions.h"
#include "THREADS/data_threads.h"

int main(void){
    
    printf("Hello, World!\n");

    //// comments in capital letters refer to particular stages in the architecture diagram

    //INIT BOARD


    //INIT UART


    //INIT BUFFERS

    const int buffer_size = 10;
    int * mockBuffer = (int*)malloc(sizeof(int) * buffer_size);

    for(int i = 0; i < buffer_size; i++){
        mockBuffer[i] = i;
    }

    //HEARTBEAT TO OPENBCI


    //LAUNCH DATA INTAKE THREAD
    pthread_t dataIntakeThread;
    
    pthread_create(&dataIntakeThread, NULL, initDataIntakeThread, (void*)mockBuffer);
    
    //LAUNCH DATA PROCESSING THREAD
    pthread_t dataProcessingThread;

    pthread_create(&dataProcessingThread, NULL, initDataProcessingThread, (void*)"test");


    //WAIT FOR DATA PROCESSING TO RESPOND
    pthread_join(dataProcessingThread, NULL);

    //send ACK signal once the thread responds

    //WAIT FOR DATA INTAKE TO RESPOND
    pthread_join(dataIntakeThread, NULL);


    //send ACK signal once the thread responds

    //TERMINATE MASTER THREAD
    printf("Mission successful!\n");

    free(mockBuffer);
    return 0;
}

