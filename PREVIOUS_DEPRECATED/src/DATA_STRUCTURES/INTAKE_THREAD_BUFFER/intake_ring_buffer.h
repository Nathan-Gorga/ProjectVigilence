#ifndef INTAKE_RING_BUFFER_H
#define INTAKE_RING_BUFFER_H

#include "../../definitions.h"
#include "../data_structures.h"

#define TIME_STORED_IN_INTAKE_RING_BUFFER 10 //seconds
#define INTERNAL_RING_BUFFER_SIZE TIME_STORED_IN_INTAKE_RING_BUFFER * SAMPLING_FREQ * NUM_CHANNELS


Ring_Buffer * initIntakeRingBuffer(void);

#endif
