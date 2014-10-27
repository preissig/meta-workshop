/*
 * main.c
 *
 *  Created on: Aug 20, 2012
 *      Author: user
 */

#include <sys/types.h>
#include <sys/ioctl.h>
#include <sys/mman.h>

#include <linux/fb.h>
#include <unistd.h>
#include <fcntl.h>

#include <stdio.h>

int main(int argc, char **argv)
{
	int fd = -1;
	struct fb_var_screeninfo fbvar;
	struct fb_fix_screeninfo fbfix;
	unsigned int pixel_val;
	unsigned int i, j;

	fd = open("/sys/class/graphics/fb0/blank", O_RDWR);
	write(fd, "0", sizeof("0"));
	close(fd);




	exit(0);
}
