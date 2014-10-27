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
#include <termios.h>

// Simple function to configure a serial port to 1152008N1
void configure_serial(int fd)
{
    struct termios terminal_setting;

	tcgetattr(fd, &terminal_setting);

	// Set baud rate
	// Most drivers ignore output baud rate and use input for both
    cfsetispeed(&terminal_setting, B115200);
    cfsetospeed(&terminal_setting, B115200);

    // clear number of bits field
    terminal_setting.c_cflag &= ~CSIZE;
    // set 8 bits
    terminal_setting.c_cflag |= CS8;

    // clear parity bit in flag (no parity)
    terminal_setting.c_cflag &= ~PARENB;

    // clear the CSTOPB flag in the mask
    // CSTOPB = 1 : 2 stop bits
    // CSTOPB = 0 : 1 stop bit
    terminal_setting.c_cflag &= ~CSTOPB;

    // send changes to terminal settings structure to kernel
    // TCSANOW flag forces immediate change
    tcsetattr(fd, TCSANOW, &terminal_setting);
}

int main( int argc, char **argv )
{
	char hello[40] = "Hello world!\n\0";
    int fd, i,j=0;

    fd = open("/dev/ttyO0", O_RDWR);

    configure_serial(fd);

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
