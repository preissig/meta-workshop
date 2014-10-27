/*
 * main.c
 *
 *  Created on: Aug 15, 2012
 *      Author: user
 */


/* Standard Linux headers */
#include <stdio.h>                              //  Always include this header
#include <stdlib.h>                             //  Always include this header
#include <signal.h>                             //  Defines signal-handling functions
#include <unistd.h>                             //  Defines sleep function

#include <pthread.h>                            // Posix thread types
#include <semaphore.h>							// Semaphores for Posix threads

/* Application headers */
#include "thread.h"

/* Global thread environments */
typedef struct thread_env
{
    int quit;                    // Thread will run as long as quit = 0
    int id;
    sem_t *mySemPtr;
    sem_t *partnerSemPtr;
} thread_env;

thread_env thread1_env = {0, 1, NULL, NULL};
thread_env thread2_env = {0, 2, NULL, NULL};

/* Thread Function */
void *thread_fxn( void *envByRef )
{
	thread_env *envPtr = envByRef;

}


/******************************************************************************
 * main
 ******************************************************************************/
int main(int argc, char *argv[])
{
    int             status    = 0;
    pthread_t       thread1, thread2;
    void 			*thread1Return, *thread2Return;



    exit( status );
}

