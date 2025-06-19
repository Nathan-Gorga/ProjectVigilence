#include "event_ring_buffer.h"


Node * initNode(void){
    Node * temp_node = (Node*)malloc(sizeof(Node));

    temp_node->event_start = NULL;

    temp_node->event_stop = NULL;

    temp_node->next = NULL;

    return temp_node;
}
 
// TODO : only access buffer via node list
Node * startEventInBuffer(Ring_Buffer * event_buffer, const size_t size, const float channel_data[NUM_CHANNELS]){
    
    Node * event_node = initNode();

    addDataPointToRingBuffer(event_buffer, channel_data, size);

    event_node->event_start = &event_buffer->buffer[(event_buffer->head - NUM_CHANNELS) % size];

    return event_node;
}

// TODO : only access buffer via node list

void stopEventInBuffer(Ring_Buffer * event_buffer, Node * event_node, const size_t size, const float channel_data[NUM_CHANNELS]){

    addDataPointToRingBuffer(event_buffer, channel_data, size);

    event_node->event_stop = &event_buffer->buffer[(event_buffer->head - 1) % size];
} 

void addNodeToList(Node * head, Node * node){
    assert(head != NULL);

    Node * curr = head->next;

    while(curr != NULL){
        curr = curr->next;
    }

    curr->next = node;
}


void popNodeFromList(Node * head){
    assert(head != NULL);

    if(head->next == NULL) return;
    
    Node * temp = head->next->next;

    freeNode(head->next);

    head->next = temp;
}

void freeNode(Node * node){
    free(node);
}
