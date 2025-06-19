#include "../data_structures.h"

Ring_Buffer * initEventRingBuffer(void){
    return initRingBuffer(EVENT_RING_BUFFER_SIZE);
}
