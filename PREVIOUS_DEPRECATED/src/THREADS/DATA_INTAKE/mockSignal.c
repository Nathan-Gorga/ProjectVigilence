#include "mockSignal.h"

void mockSignal(float * signal, const size_t size, const float amplitude, const float frequency){
    
    float t;

    for (int i = 0; i < size; i++) {
        t = (float)i / SAMPLING_FREQ;
        float sine_value = amplitude * sin(2 * PI * frequency * t);

        signal[i] = sine_value;
        
    }

}



size_t mockEvent(float * signal){
    const float frequency = 6.0f;
    const float amplitude = 1.0f; 
    const size_t size = 50;

    mockSignal(signal, size, amplitude, frequency);
    return size;
}

