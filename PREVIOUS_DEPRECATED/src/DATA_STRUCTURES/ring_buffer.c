#include "data_structures.h"

Ring_Buffer * initRingBuffer(const size_t buffer_size){

    Ring_Buffer * temp_buffer = (Ring_Buffer*)calloc(buffer_size, sizeof(Ring_Buffer));

    if(temp_buffer == NULL) return NULL;

    temp_buffer->buffer = (float*)malloc(buffer_size * sizeof(float));

    if(temp_buffer->buffer == NULL){
        free(temp_buffer); 
        return NULL;
    }
    temp_buffer->head = 0;
    temp_buffer->tail = 0;

    return temp_buffer;    
}


void addChannelPointToRingBuffer(Ring_Buffer * ring_buffer, const float data, const size_t size){ 

    #ifdef ASSERT_MODE

    assert(ring_buffer != NULL);

    assert(ring_buffer->buffer != NULL);

    assert(size != 0);
    
    #endif
    
    ring_buffer->buffer[ring_buffer->head] = data;

    ring_buffer->head++;

    // modulo operator is relatively expensive compared to this
    if(ring_buffer->head >= size) ring_buffer->head = 0;
    
}


void addDataPointToRingBuffer(Ring_Buffer * internal_ring_buffer, const float channel_data[NUM_CHANNELS], const size_t size){

    #ifdef ASSERT_MODE
    
    assert(internal_ring_buffer != NULL);

    assert(internal_ring_buffer->buffer != NULL);

    assert(internal_ring_buffer->buffer != event_ring_buffer->buffer); 

    assert(channel_data != NULL);

    assert(size != 0);

    #endif

    
    for(int i = 0; i < NUM_CHANNELS; i++){
        addChannelPointToRingBuffer(internal_ring_buffer, channel_data[i], size);
    }
}



int takeEventFromRingBuffer(Node * head, int * indexes){


    #ifdef ASSERT_MODE

    assert(head != NULL);

    #endif
    PRINTF_DEBUG

    if(head->next == NULL) return 1;//buffer empty
    PRINTF_DEBUG


    Node *eventNode = head->next;
    PRINTF_DEBUG
    
    indexes[0] = eventNode->start;
    indexes[1] = eventNode->stop;
    PRINTF_DEBUG

    popNodeFromList(head);
    PRINTF_DEBUG
    return 0; //proper execution
}



void freeRingBuffer(Ring_Buffer * ring_buffer){

    #ifdef ASSERT_MODE

    assert(ring_buffer != NULL);
    
    assert(ring_buffer->buffer != NULL);

    #endif

    free(ring_buffer->buffer);
    free(ring_buffer);
}


