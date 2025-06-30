#include "../data_threads.h"
#include "../../DATA_STRUCTURES/data_structures.h"


void *launchDataProcessingThread(void* args){
    PRINTF_DEBUG
    printf(BLUE""TAB"Launching Data Processing Thread...\n"RESET);
    PRINTF_DEBUG
    Node * head = (Node*)args;
    PRINTF_DEBUG
    return dataProcessingThread(head);
}

void * dataProcessingThread(Node * head){

    #ifdef ASSERT_MODE
    
    assert(head != NULL);
    
    #endif
    
    //INIT ALGOS 
    PRINTF_DEBUG
    
    {// SEND READY SIGNAL TO MASTER
        pthread_mutex_lock(&lock);
    
        ready_count++;
    
        pthread_cond_signal(&cond);
        printf(BLUE""TAB"Data Processing Thread Ready!\n"RESET);
    
        pthread_mutex_unlock(&lock);
    }
    
    PRINTF_DEBUG
    
    

    int * indexes = (int*)malloc(NUM_CHANNELS * sizeof(int));
    PRINTF_DEBUG
    int ret = 1;
  
    do{

        ret = takeEventFromRingBuffer(head, indexes);


    }while(ret == 1);
    PRINTF_DEBUG

    PRINTF_DEBUG


    
    const int start = indexes[0];
    const int stop = indexes[1];
    
    PRINTF_DEBUG

    free(indexes);

    const bool it_is_a_loop = start > stop;
    
    const size_t firstSize = (EVENT_RING_BUFFER_SIZE - start);

    const size_t size = it_is_a_loop ? firstSize + stop : stop - start;
    PRINTF_DEBUG
    
    float * eventSignal = (float*)calloc(size, sizeof(float));
    PRINTF_DEBUG

    if(it_is_a_loop){

        for(int i = 0; i < firstSize; i++){
            eventSignal[i] = event_ring_buffer->buffer[start + i];
        }

        for(int i = 0; i < stop; i++){
            eventSignal[firstSize + i] = event_ring_buffer->buffer[i];
        }

    } else {


        for(int i = 0; i < size; i++){
            eventSignal[i] = event_ring_buffer->buffer[start + i];
        }
    }
    PRINTF_DEBUG

    

    const int channelSize = size / NUM_CHANNELS;

    float *signal_channels[NUM_CHANNELS];
    for(int i = 0; i < NUM_CHANNELS; i++){
        signal_channels[i] = (float*)calloc(size, sizeof(float));
    }
    
 
    for(int i = 0; i < NUM_CHANNELS; i++){
        for(int j = 0; j < channelSize; j++){
            signal_channels[i][j] = eventSignal[j * NUM_CHANNELS + i];
        }
    }

    PRINTF_DEBUG
    
    free(eventSignal);

    // for(int i = 0; i < NUM_CHANNELS; i++){
    //     for(int j = 0; j < channelSize; j++){
    //         printf(""TAB"Channel %d : %f\n", i, signal_channels[i][j]);
    //     }
    // }
    PRINTF_DEBUG
    
    for(int i = 0; i < NUM_CHANNELS; i++){
        free(signal_channels[i]);
    }


    //TODO : apply algo


    //IS THERE A NODE IN THE LIST?
    
        // if no : wait for it
    
        // if yes : take the address in from the first node
    
        // ARE WE IN CALIBRATION MODE ?
    
            // if yes : apply calibration algo
    
                // save data for later use
    
            // if no : apply algo
    
    
        // according to the type of detections, trigger relevant responses
    
        // remove Node from list
    
        //INTERUPT : TERMINATE THREAD
    
    return NULL;
}