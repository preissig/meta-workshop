/*
 * main.c
 *
 *  Created on: Aug 15, 2012
 *      Author: user
 */


#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>

int main( int argc, char **argv )
{
	char hello[40] = "Hello world!\n\0";
    int fd, i,j=0;

    fd = open("/dev/ttyO0", O_RDWR);

    write( fd, hello, sizeof(hello));

    while(1){
    	for(i=0;i<100000000;i++); // slight delay
    	j++;
    	snprintf(hello, 40, "Hello world, again!!! (%d)\n\0", j);
    	write( fd, hello, sizeof(hello));
    }
    // never reaches this point
    close(fd);

    return 0;

}
