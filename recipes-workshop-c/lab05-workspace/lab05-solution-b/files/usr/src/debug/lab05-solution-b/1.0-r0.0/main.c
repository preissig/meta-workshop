/*
 * main.c
 *
 *  Created on: Aug 14, 2012
 *      Author: user
 */


#include <stdio.h>
#include <unistd.h>
#include <signal.h>

int quit = 0;

void signalHandler(int signal)
{
	quit = 1;
}

int main(int argc, char **argv)
{
	FILE *pFile = NULL;
	int toggle = 0;

	signal(SIGINT, signalHandler);

	pFile = fopen("/sys/class/leds/evmsk:green:heartbeat/trigger", "w");
	fwrite("none", 1, sizeof("none"), pFile);
	fclose(pFile);

	pFile = fopen("/sys/class/leds/evmsk:green:heartbeat/brightness", "w");
	fprintf(pFile, "%d", toggle);
	fflush(pFile);
	sleep(1);

	while(quit == 0){
		toggle ^= 1;
		fprintf(pFile, "%d", toggle);
		fflush(pFile);
		sleep(1);
	}

	fprintf(pFile, "0");
	fclose(pFile);

	return 0;
}
