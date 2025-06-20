#include "mockSignal.h"

void mockSignal(float * signal, const size_t size, const float amplitude, const float frequency){
    
    float t;

    for (int i = 0; i < size; i++) {
        t = i / SAMPLING_FREQ;
        float sine_value = amplitude * sin(2 * PI * frequency * t);
        signal[i] = sine_value;
    }

}