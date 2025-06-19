#include "intake_ring_buffer.h"

Ring_Buffer * initIntakeRingBuffer(void){
    return initRingBuffer(INTERNAL_RING_BUFFER_SIZE);
}
