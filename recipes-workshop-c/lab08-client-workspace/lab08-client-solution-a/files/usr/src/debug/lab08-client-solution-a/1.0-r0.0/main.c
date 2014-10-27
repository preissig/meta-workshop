/*
 * main.c
 *
 *  Created on: Aug 15, 2012
 *      Author: user
 */

  #include <sys/types.h>
  #include <sys/socket.h>
  #include <netinet/in.h>
  #include <arpa/inet.h>
  #include <stdio.h>
  #include <stdlib.h>
  #include <string.h>
  #include <unistd.h>

  int main(void)
  {
    struct sockaddr_in stSockAddr;
    int Res;
    int SocketFD = -1;

    SocketFD = socket(AF_INET, SOCK_STREAM, 0);

    if (-1 == SocketFD)
    {
      perror("cannot create socket");
      exit(-1);
    }

    memset(&stSockAddr, 0, sizeof(stSockAddr));

    stSockAddr.sin_family = AF_INET;
    stSockAddr.sin_addr.s_addr = inet_addr("192.168.1.1");
    stSockAddr.sin_port = htons(1100);

    if (-1 == connect(SocketFD, (struct sockaddr *)&stSockAddr, sizeof(stSockAddr)))
    {
      perror("connect failed");
      close(SocketFD);
      exit(-1);

    }

    /* perform read write operations ... */
    write(SocketFD, "Hello world of Ethernet!\n", sizeof("Hello world of Ethernet!\n"));

    shutdown(SocketFD, SHUT_RDWR);

    close(SocketFD);
    return 0;
  }
