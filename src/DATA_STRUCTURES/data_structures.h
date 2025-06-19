#ifndef DATA_STRUCTURES_H
#define DATA_STRUCTURES_H

#include "../definitions.h"

#define NUM_CHANNELS 2
#define SAMPLING_FREQ 200


//RING BUFFER 
typedef struct ring_buffer{
    float * buffer;
    unsigned int head;
    unsigned int tail;
} Ring_Buffer;

Ring_Buffer * initRingBuffer(const size_t buffer_size);

void addDataPointToRingBuffer(Ring_Buffer * ring_buffer, const float channel_data[NUM_CHANNELS], const size_t size);

void freeRingBuffer(Ring_Buffer * ring_buffer);


//EVENT ADDRESS LIST (IN RING BUFFER)
typedef struct address_node{
    float * event_start;
    float * event_stop;
    struct address_node * next;
}Node;


Node * initNode(void);

void freeNode(Node * node);

#endif
