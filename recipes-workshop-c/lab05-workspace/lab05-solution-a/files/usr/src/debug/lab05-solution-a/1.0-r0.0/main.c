/*
 * main.c
 *
 *  Created on: Aug 14, 2012
 *      Author: user
 */


#include <stdio.h>
#include <unistd.h>
#include <signal.h>


int main(int argc, char **argv)
{
	FILE *pFile = NULL;

	pFile = fopen("/sys/class/leds/evmsk:green:heartbeat/trigger", "w");
	fwrite("none", 1, sizeof("none"), pFile);
	fclose(pFile);

	pFile = fopen("/sys/class/leds/evmsk:green:heartbeat/brightness", "w");
	fwrite("1", 1, 1, pFile);
	fclose(pFile);

	return 0;
}
