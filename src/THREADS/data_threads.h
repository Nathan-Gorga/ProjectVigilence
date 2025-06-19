#ifndef DATA_THREADS_H
#define DATA_THREADS_H

#include "../definitions.h"

#define TAB "|\t"

extern pthread_mutex_t lock;

extern pthread_cond_t cond;

extern int ready_count;

extern const int THREADS_TO_WAIT;

void *launchDataIntakeThread(void*);

void *launchDataProcessingThread(void*);




#endif

