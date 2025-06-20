#include "../data_threads.h"
#include "../../DATA_STRUCTURES/data_structures.h"


void *launchDataProcessingThread(void* args){

    printf(BLUE""TAB"Launching Data Processing Thread...\n"RESET);

    Node * head = (Node*)args;
    
    assert(head != NULL);
    
    //INIT ALGOS 
 

    {// SEND READY SIGNAL TO MASTER
        pthread_mutex_lock(&lock);

        ready_count++;

        pthread_cond_signal(&cond);
        printf(BLUE""TAB"Data Processing Thread Ready!\n"RESET);

        pthread_mutex_unlock(&lock);
    }


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
