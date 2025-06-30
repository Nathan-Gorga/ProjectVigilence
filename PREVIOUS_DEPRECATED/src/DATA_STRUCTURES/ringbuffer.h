#ifndef DATA_STRUCTURES_RINGBUFFER_H
#define DATA_STRUCTURES_RINGBUFFER_H
#include "../definitions.h"


//RING BUFFER 
typedef struct ring_buffer{
    float * buffer;
    unsigned int head; //head is the the write index
    unsigned int tail; //tail is the start point of the first node in the list
} Ring_Buffer;

extern Ring_Buffer * event_ring_buffer;

Ring_Buffer * initRingBuffer(const size_t buffer_size);


#endif
