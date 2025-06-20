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

        //SEND START STREAM SIGNAL TO OPENBCI
        const size_t size = (int)(SAMPLING_FREQ * SIGNAL_DURATION);

        float * signal_channel1 = (float*)calloc(size, sizeof(float));
        float * signal_channel2 = (float*)calloc(size, sizeof(float));
    
        PRINTF_DEBUG

        //RECEIVE DATA FROM OPENBCI
        mockSignal(signal_channel1, size, 1, 10);    
        mockSignal(signal_channel2, size, 1.5, 15);    

        PRINTF_DEBUG

        float * signal = (float*)calloc(size * NUM_CHANNELS, sizeof(float));

        for(int i = 0; i < size; i++){
            for(int j = 0; j < NUM_CHANNELS; j++){
                signal[(j * NUM_CHANNELS) + i] = j == 0 ? signal_channel1[i] : signal_channel2[i];
            }
        }

        PRINTF_DEBUG

        Node * event_node = initNode();

        createEventNode(event_node, signal, size * NUM_CHANNELS);

        PRINTF_DEBUG
        //ADD NODE TO THE LIST
        addNodeToList(head, event_node);

        PRINTF_DEBUG

        printf(YELLOW""TAB);
        printNodeList(head);
        printf(RESET);
        
            //if there is data add it to internal ring
        
        //SHIFT FROM BASELINE?
    
            // if yes : add to eventRingBuffer
    
            // if no : WAS SENDING EVENT ?
    
                // if yes : CLOSE NODE AND ADD IT TO THE LIST then add to internal buffer
                
                // if no : add to internal buffer
    
        //INTERUPT : TERMINATE THREAD
        
        free(signal);
        return NULL;
}