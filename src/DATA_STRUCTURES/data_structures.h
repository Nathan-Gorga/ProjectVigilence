#ifndef DATA_STRUCTURES_H
#define DATA_STRUCTURES_H

#include "../definitions.h"

#define NUM_CHANNELS 2
#define TIME_STORED_IN_RING_BUFFER 60 //seconds
#define SAMPLING_FREQ 200


//RING BUFFER 
#define EVENT_RING_BUFFER_SIZE TIME_STORED_IN_RING_BUFFER * SAMPLING_FREQ * NUM_CHANNELS

typedef struct ring_buffer{
    float * ring_buffer;
    unsigned int head;
    unsigned int tail;
} Ring_Buffer;

Ring_Buffer * initRingBuffer(void);



//EVENT ADDRESS LIST (IN RING BUFFER)



#endif
