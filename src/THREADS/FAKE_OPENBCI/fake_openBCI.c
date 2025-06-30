#include "../data_threads.h"


int randomStartEvent(const int max){
    return rand() % max;
}

void * launchFakeOpenBCI(void * arg){
    printf(MAGENTA""TAB"Launching Fake OpenBCI...\n"RESET);
    return fakeOpenBCI();
}

void * fakeOpenBCI(void){
    
    const int ten_sec_data = 10 * SAMPLING_FREQ;
    
    float signalBuffer[ten_sec_data] = {0.0f};
    
    while(1){
        const int startEvent = randomStartEvent(ten_sec_data);
        sendUART(signalBuffer, startEvent);

        const size_t size = mockEvent(signalBuffer);
        sendUART(signalBuffer, size);

        for(int i = 0; i < size; i++){
            signalBuffer[i] = 0.0f;
        }
    }

    return NULL;
}