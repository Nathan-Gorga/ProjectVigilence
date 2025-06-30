#ifndef UART_H
#define UART_H

#include "../definitions.h"

#define UART_BAUD_RATE 115200

//for this test, two way communication is not needed

#define UART_TX 1
#define UART_RX 0


extern int UART_fd[2];

int initUART(void);

void closeUART(void);

int sendUART(const float * data, const size_t size);

int getUART(float * data, const size_t size);

#endif



