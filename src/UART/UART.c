#include "UART.h"

int initUART(void){
    return pipe(UART_fd);
}


void closeUART(void){
    close(UART_fd[UART_RX]);
    close(UART_fd[UART_TX]);
}



int sendByteUART(const byte data){
    return write(UART_fd[UART_TX], data, sizeof(byte));
}

int getByteUART(const byte * data, const size_t size){
    return read(UART_fd[UART_RX], data, sizeof(byte) * size);
}

