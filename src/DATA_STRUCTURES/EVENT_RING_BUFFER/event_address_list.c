#include "event_ring_buffer.h"


Node * initNode(void){
    Node * temp_node = (Node*)malloc(sizeof(Node));

    assert(temp_node != NULL);

    temp_node->start = -1;

    temp_node->stop = -1;

    temp_node->next = NULL;

    return temp_node;
}


// TODO : send error message if overwrite in buffer
void putBufferInRingBuffer(float * buffer, const int sizeBuffer){
    assert(buffer != NULL);

    bool needsLoop = false; 
    if(event_ring_buffer->head + sizeBuffer >= EVENT_RING_BUFFER_SIZE){
        needsLoop = true;
    }

    if(!needsLoop){
        memcpy(event_ring_buffer->buffer + event_ring_buffer->head, buffer, sizeBuffer * sizeof(float));
        event_ring_buffer->head += sizeBuffer;
        return;
    }

    const int sizeFirstMemCPY = EVENT_RING_BUFFER_SIZE - event_ring_buffer->head;
    const int sizeSecondMemCPY = sizeBuffer - sizeFirstMemCPY;

    memcpy(event_ring_buffer->buffer + event_ring_buffer->head, buffer, sizeFirstMemCPY * sizeof(float));
    memcpy(event_ring_buffer->buffer, buffer + sizeFirstMemCPY, sizeSecondMemCPY * sizeof(float));

    event_ring_buffer->head = sizeSecondMemCPY;
}


//internal buffer needs to be a linear buffer
void createEventNode(Node * event_node, float * internal_buffer, const int sizeInternalBuffer){
    
    assert(event_node != NULL);

    assert(internal_buffer != NULL);

    event_node->start = event_ring_buffer->head;

    putBufferInRingBuffer(internal_buffer, sizeInternalBuffer);

    event_node->stop = event_ring_buffer->head;
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
    assert(node != NULL);
    free(node);
}
