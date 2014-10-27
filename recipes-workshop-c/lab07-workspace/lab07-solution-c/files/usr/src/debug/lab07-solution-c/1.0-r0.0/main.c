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

	printf("Entering thread #%d\n", envPtr->id);
	while(!envPtr->quit)
	{
		sem_wait( envPtr->mySemPtr);
		sleep(1);   // slow it down a bit
		printf("Inside while loop of thread #%d\n", envPtr->id);
		sem_post( envPtr->partnerSemPtr);
	}
	printf("Exiting thread #%d\n", envPtr->id);

	return (void *)envPtr->id;
}


/******************************************************************************
 * main
 ******************************************************************************/
int main(int argc, char *argv[])
{
    int             status    = 0;
    pthread_t       thread1, thread2;
    void 			*thread1Return, *thread2Return;

    /* Initialize Semaphores */
    printf("Initializing Semaphores\n");

    thread1_env.mySemPtr = malloc( sizeof(sem_t));
    thread2_env.mySemPtr = malloc( sizeof(sem_t));

    sem_init(thread1_env.mySemPtr, 0, 0);
    sem_init(thread2_env.mySemPtr, 0, 0);

    thread1_env.partnerSemPtr = thread2_env.mySemPtr;
    thread2_env.partnerSemPtr = thread1_env.mySemPtr;

    /* Create a thread for audio */
    printf( "Creating thread 1\n" );

    if( launch_pthread( &thread1, REALTIME,
                        99,
                        thread_fxn,
                        (void *) &thread1_env )
	    != thread_SUCCESS )
    {
        printf( "Failed to create thread 1\n" );
        status = -1;
        thread1_env.quit = 1;
        thread2_env.quit = 1;
    }

    printf( "Creating thread 2\n" );

    if( status == 0)
    	if( launch_pthread( &thread2,
                        REALTIME,
                        98,
                        thread_fxn,
                        (void *) &thread2_env )
        != thread_SUCCESS )
    {
        printf( "Failed to create thread 2\n" );
        status = -1;
        thread1_env.quit = 1;
        thread2_env.quit = 1;
    }


    printf( "\nAll application threads started\n" );

    printf( "Sending trigger sem_post to thread 1\n");
    sem_post(thread1_env.mySemPtr);


    sleep(10);
    thread1_env.quit = 1;
    thread2_env.quit = 1;


    /* Wait until threads terminate */
    pthread_join( thread1, &thread1Return );
    pthread_join( thread2, &thread2Return );

    printf("Exited thread #%d\n", (int) thread1Return);
    printf("Exited thread #%d\n", (int) thread2Return);

    exit( status );
}

