#ifndef UART_H
#define UART_H

#include "../definitions.h"

#define UART_BAUD_RATE 115200

//for this test, two way communication is not needed

#define UART_TX 1
#define UART_RX 0

int UART_fd[2];

int initUART(void);

void closeUART(void);

int sendUART(const byte const * data, const size_t size);

int getUART(const byte * data, const size_t size);

#endif



