#include "data_structures.h"

Ring_Buffer * initRingBuffer(const size_t buffer_size){

    Ring_Buffer * temp_buffer = (Ring_Buffer*)malloc(sizeof(Ring_Buffer));

    temp_buffer->buffer = (float*)malloc(buffer_size * sizeof(float));

    temp_buffer->head = 0;
    temp_buffer->tail = 0;

    return temp_buffer;    
}

void freeRingBuffer(Ring_Buffer * ring_buffer){
    free(ring_buffer->buffer);
    free(ring_buffer);
}


