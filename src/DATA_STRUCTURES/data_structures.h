#ifndef DATA_STRUCTURES_H
#define DATA_STRUCTURES_H

#include "../definitions.h"
#include "EVENT_RING_BUFFER/event_ring_buffer.h"
#include "node.h"
#include "ringbuffer.h"


void addDataPointToRingBuffer(Ring_Buffer * ring_buffer, const float channel_data[NUM_CHANNELS], const size_t size);

void freeRingBuffer(Ring_Buffer * ring_buffer);

Node * initNode(void);

void freeNode(Node * node);

void freeList(Node * head);

int takeEventFromRingBuffer(Node * head, int * indexes);

#endif
