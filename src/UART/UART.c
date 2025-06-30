#include "UART.h"

int initUART(void){
    return pipe(UART_fd);
}


void closeUART(void){
    close(UART_fd[UART_RX]);
    close(UART_fd[UART_TX]);
}


int sendUART(const byte const * data, const size_t size){

    #ifdef ASSERT_MODE

    assert(data != NULL);

    assert(size > 0);

    #endif

    return write(UART_fd[UART_TX], data, sizeof(byte) * size);
}

int getUART(const byte * data, const size_t size){
    
    #ifdef ASSERT_MODE

    assert(size > 0);

    #endif

    return read(UART_fd[UART_RX], data, sizeof(byte) * size);
}

