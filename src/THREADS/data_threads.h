#ifndef DATA_THREADS_H
#define DATA_THREADS_H

#include "../definitions.h"
#include "../DATA_STRUCTURES/node.h"
#include "../UART/UART.h"
#include "../THREADS/DATA_INTAKE/mockSignal.h"


#define TAB "|\t"

extern pthread_mutex_t lock;

extern pthread_cond_t cond;

extern int ready_count;

extern const int THREADS_TO_WAIT;

void *launchDataIntakeThread(void*);

void *launchDataProcessingThread(void*);

void * launchFakeOpenBCI(void * arg);

void * dataIntakeThread(Node* head);

void * dataProcessingThread(Node * head);
#endif

