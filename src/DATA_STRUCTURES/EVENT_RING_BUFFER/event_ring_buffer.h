#ifndef EVENT_RING_BUFFER_H
#define EVENT_RING_BUFFER_H


#include "../../definitions.h"
#include "../data_structures.h"

#define TIME_STORED_IN_EVENT_RING_BUFFER 60 //seconds
#define EVENT_RING_BUFFER_SIZE TIME_STORED_IN_EVENT_RING_BUFFER * SAMPLING_FREQ * NUM_CHANNELS


Ring_Buffer * initEventRingBuffer(void);

Node * initNode(void);

Node * startEventInBuffer(Ring_Buffer * event_buffer, const size_t size, const float channel_data[NUM_CHANNELS]);

void stopEventInBuffer(Ring_Buffer * event_buffer, Node * event_node, const size_t size, const float channel_data[NUM_CHANNELS]);

void freeNode(Node * node);

#endif
