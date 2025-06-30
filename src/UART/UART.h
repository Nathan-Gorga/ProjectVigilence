#ifndef UART_H
#define UART_H

#include "../definitions.h"

#define UART_BAUD_RATE 115200

//for this test, two way communication is not needed

#define UART_TX 1
#define UART_RX 0

int UART_fd[2];

void initUART(void);

void closeUART(void);

int sendByteUART(const byte data);

int getByteUART(byte * data, const size_t size);

#endif



