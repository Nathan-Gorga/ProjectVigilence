#include "mockSignal.h"

void mockSignal(double * signal, const size_t size){
    
    double t;

    for (int i = 0; i < size; i++) {
        t = i / SAMPLING_FREQ;
        double sine_value = SIGNAL_AMPLITUDE * sin(2 * PI * SIGNAL_FREQUENCY * t);
        signal[i] = sine_value;
    }

}