#include "../data_threads.h"


int randomStartEvent(const int max){
    return rand() % max;
}

void * launchFakeOpenBCI(void * arg){
    printf(MAGENTA""TAB"Launching Fake OpenBCI...\n"RESET);
    return fakeOpenBCI();
}

void * fakeOpenBCI(void){
    
    printf(MAGENTA""TAB"Launched Fake openBCI successfully!\n"RESET);

    #define SIGNAL_BUF_SIZE 20
    
<<<<<<< HEAD
    float signalBuffer[SIGNAL_BUF_SIZE] = {0.0f};
=======
    float signalBuffer[ten_sec_data] = {0.0f};
>>>>>>> f05b5bc (improved the fakeOpenBCI loop)
    int count = 200;

    //TODO : wait for data intake signal to start


    while(count--){//TODO : add a better stop condition

<<<<<<< HEAD
        const int startEvent = randomStartEvent(SIGNAL_BUF_SIZE)+1;
=======
        const int startEvent = randomStartEvent(ten_sec_data);
>>>>>>> f05b5bc (improved the fakeOpenBCI loop)

        PRINTF_DEBUG
        sendUART(signalBuffer, startEvent);//FIXME : if no read is performed on the pipe, the thread freezes, handle this
        PRINTF_DEBUG

        const size_t size = mockEvent(signalBuffer);

        PRINTF_DEBUG
        sendUART(signalBuffer, size);//FIXME : if no read is performed on the pipe, the thread freezes, handle this
        PRINTF_DEBUG

        for(int i = 0; i < size; i++){
            signalBuffer[i] = 0.0f;
        }

        usleep(50);//115 200 baudrate
    }

    return NULL;
}