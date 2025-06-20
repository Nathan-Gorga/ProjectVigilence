#ifndef MOCK_SIGNAL_H
#define MOCK_SIGNAL_H

#include "../../definitions.h"
#include <math.h>

#define PI 3.14159265358979323846
#define SIGNAL_FREQUENCY 10
#define SIGNAL_DURATION 1
#define SIGNAL_AMPLITUDE 1


void mockSignal(float * signal, const size_t size, const float amplitude, const float frequency);


#endif
