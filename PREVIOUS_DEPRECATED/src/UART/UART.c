#include "UART.h"

int UART_fd[2];

int initUART(void){
    return pipe(UART_fd);
}


void closeUART(void){
    close(UART_fd[UART_RX]);
    close(UART_fd[UART_TX]);
}


int sendUART(const float * data, const size_t size){

    #ifdef ASSERT_MODE

    assert(data != NULL);

    assert(size > 0);

    #endif

    return write(UART_fd[UART_TX], data, sizeof(float) * size);
}

int getUART(float * data, const size_t size){
    
    #ifdef ASSERT_MODE

    assert(size > 0);

    #endif

    return read(UART_fd[UART_RX], data, sizeof(float) * size);
}

