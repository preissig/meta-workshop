/*
 * thread.h
 *
 *  Created on: Jun 20, 2012
 *      Author: user
 */

#ifndef THREAD_H_
#define THREAD_H_

#include <pthread.h>

#define thread_SUCCESS  0
#define thread_FAILURE -1

// for boolean
#define REALTIME   1
#define TIMESLICE  0

int launch_pthread( pthread_t *hThread_byref, int type, int priority, void *(*thread_fxn)(void *env), void *env );



#endif /* THREAD_H_ */
