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
	int buflen;
	int *buffer = NULL;

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

	buflen = fbvar.yres * fbfix.line_length;

	buffer = mmap(NULL,
	   buflen,
	   PROT_READ|PROT_WRITE,
	   MAP_SHARED,
	   fd,
	   0);

	if (buffer == MAP_FAILED) {
		printf("mmap failed\n");
		close(fd);
		return(-1);
	}

	for(i=0; i< fbvar.yres; i++){
		for(j=0; j< (fbfix.line_length / 4); j++){
			pixel_val = ((j/2) << 8) + (unsigned int) (0.9 * i) ;
			buffer[i * (fbfix.line_length / 4) + j] = pixel_val;
		}
	}

   if (buffer && buffer != MAP_FAILED)
	  munmap(buffer, buflen);

   if (fd >= 0)
	  close(fd);

	return(0);
}
