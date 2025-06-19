#include "../data_threads.h"

void *initDataIntakeThread(void* args){
    int *mockBuffer = (int *)args;
    const int buffer_size = 10;
    for(int i = 0; i < buffer_size; i++){
        printf("%d\n",mockBuffer[i]);
    }

    return NULL;
}

