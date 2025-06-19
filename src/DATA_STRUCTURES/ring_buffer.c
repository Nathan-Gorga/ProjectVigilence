#include "data_structures.h"

Ring_Buffer * initRingBuffer(const size_t buffer_size){

    
    // TODO : calloc instead to prevent undefined behaiviorif index out of bounds
    Ring_Buffer * temp_buffer = (Ring_Buffer*)malloc(sizeof(Ring_Buffer));

    temp_buffer->buffer = (float*)malloc(buffer_size * sizeof(float));

    temp_buffer->head = 0;
    temp_buffer->tail = 0;

    return temp_buffer;    
}

void addChannelPointToRingBuffer(Ring_Buffer * ring_buffer, const float data, const size_t size){ 

    // TODO : signal an error if overwrite occurs
    
    ring_buffer->buffer[ring_buffer->head] = data;

    ring_buffer->head++;

    // modulo operator is relatively expensive compared to this
    if(ring_buffer->head >= size) ring_buffer->head = 0;
    
}


void addDataPointToRingBuffer(Ring_Buffer * ring_buffer, const float channel_data[NUM_CHANNELS], const size_t size){

    for(int i = 0; i < NUM_CHANNELS; i++){
        addChannelPointToRingBuffer(ring_buffer, channel_data[i], size);
    }
}

// TODO : add getDataPoint function

// TODO : add getChannelPoint function

void freeRingBuffer(Ring_Buffer * ring_buffer){
    free(ring_buffer->buffer);
    free(ring_buffer);
}


