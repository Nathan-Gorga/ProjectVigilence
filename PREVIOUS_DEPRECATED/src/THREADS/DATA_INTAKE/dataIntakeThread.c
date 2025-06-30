#include "../data_threads.h"
#include "../../DATA_STRUCTURES/data_structures.h"
#include "../../DATA_STRUCTURES/INTAKE_THREAD_BUFFER/intake_ring_buffer.h"
#include "mockSignal.h"

void * launchDataIntakeThread(void* args){
    
    printf(YELLOW""TAB"Launching Data Intake Thread...\n"RESET);
    
    Node * head = (Node *)args;

    #ifdef ASSERT_MODE

    assert(head != NULL);

    #endif
    PRINTF_DEBUG
    return dataIntakeThread(head);
}

void * dataIntakeThread(Node* head){
        //INIT INTERNAL RING BUFFER
        Ring_Buffer * internalRingBuffer = initRingBuffer(INTERNAL_RING_BUFFER_SIZE);
        
        if(internalRingBuffer == NULL){
            perror(RED"ERROR : unable to create internal ring buffer\n"RESET);
            return NULL;
        }
        
        PRINTF_DEBUG

        {// SEND READY SIGNAL TO MASTER
            pthread_mutex_lock(&lock);
    
            ready_count++;
    
            pthread_cond_signal(&cond);
            printf(YELLOW""TAB"Data Intake Thread Ready!\n"RESET);
    
            pthread_mutex_unlock(&lock);
        }
    
        PRINTF_DEBUG

        const size_t size = (int)(SAMPLING_FREQ * SIGNAL_DURATION);


        float *signal_channels[NUM_CHANNELS];
        for(int i = 0; i < NUM_CHANNELS; i++){
            signal_channels[i] = (float*)calloc(size, sizeof(float));
        }


        PRINTF_DEBUG

        //RECEIVE DATA FROM OPENBCI
        for(int i = 0; i < NUM_CHANNELS; i++){
            mockSignal(signal_channels[i], size, (float)(i+1), (float)(i+1)*10);
        }


       
        PRINTF_DEBUG

        float * signal = (float*)calloc(size * NUM_CHANNELS, sizeof(float));

        for(int i = 0; i < size; i++){
            for(int j = 0; j < NUM_CHANNELS; j++){
                signal[(i * NUM_CHANNELS) + j] = signal_channels[j][i];

            }
        }

        for(int i = 0; i < NUM_CHANNELS; i++){
            free(signal_channels[i]);
        }
        PRINTF_DEBUG

        Node * event_node = initNode();

        createEventNode(event_node, signal, size * NUM_CHANNELS);

        PRINTF_DEBUG
        //ADD NODE TO THE LIST
        addNodeToList(head, event_node);

        PRINTF_DEBUG
        
            //if there is data add it to internal ring
        
        //SHIFT FROM BASELINE?
    
            // if yes : add to eventRingBuffer
    
            // if no : WAS SENDING EVENT ?
    
                // if yes : CLOSE NODE AND ADD IT TO THE LIST then add to internal buffer
                
                // if no : add to internal buffer
    
        //INTERUPT : TERMINATE THREAD
        
        free(signal);
        freeRingBuffer(internalRingBuffer);
        PRINTF_DEBUG
        return NULL;
}