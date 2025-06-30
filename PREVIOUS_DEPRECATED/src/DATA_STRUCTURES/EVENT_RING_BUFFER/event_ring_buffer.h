#ifndef EVENT_RING_BUFFER_H
#define EVENT_RING_BUFFER_H


#include "../../definitions.h"
#include "../node.h"
#include "../ringbuffer.h"

#define TIME_STORED_IN_EVENT_RING_BUFFER 60
#define EVENT_RING_BUFFER_SIZE TIME_STORED_IN_EVENT_RING_BUFFER * SAMPLING_FREQ * NUM_CHANNELS


Ring_Buffer * initEventRingBuffer(void);

Node * initNode(void);

void putBufferInRingBuffer(float * buffer, const int sizeBuffer);

void createEventNode(Node * event_node, float * internal_buffer, const int sizeInternalBuffer);

void addNodeToList(Node * head, Node * node);

void popNodeFromList(Node * head);

void freeNode(Node * node);

void printNodeList(Node * head);

#endif
