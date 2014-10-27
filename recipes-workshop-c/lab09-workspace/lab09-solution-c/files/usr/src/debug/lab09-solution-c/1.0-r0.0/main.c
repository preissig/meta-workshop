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

// Workaround: FBIO_WAITFORVSYNC has not yet been added to <linux/fb.h>
#define FBIO_WAITFORVSYNC _IOW('F', 0x20, u_int32_t)

int quit = 0;

int main(int argc, char **argv)
{
	int fd = -1;
	struct fb_var_screeninfo fbvar;
	struct fb_fix_screeninfo fbfix;
	unsigned int pixel_val;
	unsigned int i, j;
	int buflen;
	int *buffer = NULL;
	int pingPong = 0;
	int redVal = 0;
	int increment = 5;

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

	if(fbvar.yres_virtual < 2 * fbvar.yres)
	{
		printf("Framebuffer virtual memory is too small for double buffering\n");
		close(fd);
		return(-1);
	}

	buffer = mmap(NULL,
	   2*buflen,
	   PROT_READ|PROT_WRITE,
	   MAP_SHARED,
	   fd,
	   0);

	if (buffer == MAP_FAILED) {
		printf("mmap failed\n");
		close(fd);
		return(-1);
	}

	while(quit == 0)
	{
		redVal += increment;
		if(redVal > 0xFF)
		{
			redVal = 0xFF;
			increment = -5;
		}
		if(redVal < 0 )
		{
			redVal = 0;
			increment = 5;
		}

		for(i=0; i< fbvar.yres; i++){
			for(j=0; j< (fbfix.line_length / 4); j++){
				pixel_val = ((j/2) << 8) + (unsigned int) (0.9 * i) ;
				pixel_val += redVal << 16;
				buffer[i * (fbfix.line_length / 4) + j + pingPong * (buflen / 4)] = pixel_val;
			}
		}

		fbvar.yoffset = pingPong * fbvar.yres;
		ioctl(fd, FBIOPAN_DISPLAY, &fbvar);

		// FBIOPAN_DISPLAY is a latched operation, so wait for vsync after
		ioctl(fd, FBIO_WAITFORVSYNC, NULL);

		pingPong ^= 1;
	}

   if (buffer && buffer != MAP_FAILED)
	  munmap(buffer, buflen);

   if (fd >= 0)
	  close(fd);

	return(0);
}
