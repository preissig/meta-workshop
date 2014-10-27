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

	fd = open("/dev/fb0", O_RDWR);
	if (fd < 0) {
		printf("open failed on /dev/fb0\n");
		return(-1);
	}

	ioctl(fd, FBIOGET_VSCREENINFO, &fbvar);
	ioctl(fd, FBIOGET_FSCREENINFO, &fbfix);

	for(i=0; i< fbvar.yres; i++){
		for(j=0; j< (fbfix.line_length / 4); j++){
			pixel_val = ((j/2) << 8) + (unsigned int) (0.9 * i) ;
			write(fd, &pixel_val, sizeof(pixel_val));
		}
	}

   if (fd >= 0)
	  close(fd);

	return(0);
}
