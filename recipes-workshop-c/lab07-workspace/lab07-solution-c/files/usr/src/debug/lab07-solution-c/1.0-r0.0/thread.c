/*
 * thread.c
 *
 *  Created on: Jun 20, 2012
 *      Author: user
 */

#include <stdio.h>                              //  Always include this header
#include <stdlib.h>                             //  Always include this header

#include <pthread.h>                            // posix thread definitions
#include "thread.h"                             // header file for this module

/**************************************************************************
 *  launch_pthread
 *  --------------
 *  Launches a linux posix thread
 *
 *  INPUTS
 *  int type -- REALTIME or TIMESLICE as defined in thread.h
 *  int priority -- priority if a REALTIME thread, ignored if TIMESLICE
 *              thread. "niceness" set to default 0 for TIMESLICE
 *  (void *)(*thread_fnx)(void *env) -- pointer to the function which
 *              will be associated to the newly created thread
 *  void *env -- pointer to the environment struct which will be passed
 *              to the function "thread_fnx" upon calling
 *
 *  OUTPUTS
 *  pthread_t *hThread_byref -- pthread handle passed by reference
 *             Can be NULL on calling, will point to the handle of the
 *             newly created thread upon return
 *
 *  int (return) -- thread_SUCCESS or thread_FAUILURE as defined in
 *             thread.h
 **************************************************************************/

int launch_pthread( pthread_t *hThread_byref,
                    int type,
                    int priority,
                    void *(*thread_fxn)(void *env),
                    void *env )
{
    pthread_attr_t  threadAttrs;
    struct sched_param threadParams;
    int status = thread_SUCCESS;

    /* Initialize thread attributes structures */
    if( pthread_attr_init( &threadAttrs ) )
    {
        printf( "threadAttrs initialization failed\n" );
        status = thread_FAILURE;
    }


    /* This library defaults to inherited scheduling characteristics!   */
    /* If you don't set the inheritance, no changes will take place!    */

    if( status == thread_SUCCESS)
    	if( pthread_attr_setinheritsched( &threadAttrs, PTHREAD_EXPLICIT_SCHED ) )
    {
        printf( "threadAttrs set scheduler inheritance failed\n" );
        status = thread_FAILURE;
    }


    /* Setthread scheduling policy to real-time or time-slice           */
    /* SCHED_RR available only to threads running as superuser          */
    if( status == thread_SUCCESS)
    	if(type == REALTIME)
    {
        if( pthread_attr_setschedpolicy( &threadAttrs, SCHED_RR ) )
        {
            printf( "pthread_attr_setschedpolicy failed\n" );
            status = thread_FAILURE;
        }
    }
    else
    {
        if( pthread_attr_setschedpolicy( &threadAttrs, SCHED_OTHER ) )
        {
            printf( "pthread_attr_setschedpolicy failed\n" );
            status = thread_FAILURE;
        }
    }


    /* Set thread priority */
    if( status == thread_SUCCESS)
    	threadParams.sched_priority = priority;

    if( status == thread_SUCCESS)
    	if( pthread_attr_setschedparam( &threadAttrs, &threadParams ) )
    {
        printf( "pthread_attr_setschedparam failed\n" );
        status = thread_FAILURE;
    }


    /*  Create the thread  */

    if( status == thread_SUCCESS)
    	if ( pthread_create(hThread_byref, &threadAttrs, thread_fxn, env ) )
    {
        printf( "Failed to create thread\n" );
        status = thread_FAILURE;
    }

    return status;

}


