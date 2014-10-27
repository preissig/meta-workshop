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
    int fd;

    fd = open("/dev/ttyO0", O_RDWR);

    write( fd, "Hello world!\n\0", sizeof("Hello world!\n\0"));

    close(fd);

    return 0;

}
