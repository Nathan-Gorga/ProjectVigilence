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

    const int ten_sec_data = 10 * SAMPLING_FREQ;
    
    float signalBuffer[ten_sec_data] = {0.0f};
    int count = 20;
    while(count--){//TODO : add a better stop condition
        printf(MAGENTA""TAB"%d\n",count);
        const int startEvent = randomStartEvent(ten_sec_data);
        sendUART(signalBuffer, startEvent);//FIXME : if no read is performed on the pipe, the thread freezes, handle this

        const size_t size = mockEvent(signalBuffer);
        PRINTF_DEBUG
        sendUART(signalBuffer, size);//FIXME : if no read is performed on the pipe, the thread freezes, handle this
        PRINTF_DEBUG
        for(int i = 0; i < size; i++){
            signalBuffer[i] = 0.0f;
        }
        
    }//TODO : the loop may be going toO fast for the intake thread, so add delays that mimic the baudrate

    return NULL;
}