#ifndef DEFINITION_H
#define DEFINITION_H

#include <stdlib.h>
#include <stdio.h>
#include <threads.h>
#include <string.h>
#include <unistd.h>
#include <assert.h>
#include <stdbool.h>
#include <pthread.h>
#include <time.h>

#define NUM_CHANNELS 2
#define SAMPLING_FREQ 200

#define byte char


//TEXT COLOR
#define RESET  "\x1B[0m"
#define RED  "\x1B[31m"
#define GREEN  "\x1B[32m"
#define YELLOW  "\x1B[33m"
#define BLUE  "\x1B[34m"
#define MAGENTA  "\x1B[35m"
#define CYAN  "\x1B[36m"
#define WHITE  "\x1B[37m"



//// UNCOMMENT TO ENABLE
// #define DEBUG_MODE
#define ASSERT_MODE





#ifdef DEBUG_MODE
     #define PRINTF_DEBUG do{ printf( MAGENTA "DEBUG : %s:%d : %s\n" RESET , __FILE__ , __LINE__ , __func__ );  fflush( stdout ); }while(0); 
#else
     #define PRINTF_DEBUG
#endif

#define DEBUG_MODE
#endif

