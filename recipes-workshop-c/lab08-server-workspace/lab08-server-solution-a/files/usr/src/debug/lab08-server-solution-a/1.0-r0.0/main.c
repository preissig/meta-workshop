  #include <sys/types.h>
  #include <sys/socket.h>
  #include <netinet/in.h>
  #include <arpa/inet.h>
  #include <stdio.h>
  #include <stdlib.h>
  #include <string.h>
  #include <unistd.h>
  #include <signal.h>
 
  /* Make global so they can be cleaned up by signal handler */
  int SocketFD = -1;
  int ConnectFD = -1;

  /* Callback called when SIGINT is sent to the process (Ctrl-C) */
  void signal_handler(int sig)
  {
    printf( "Ctrl-C pressed, cleaning up and exiting..\n" );
    if(ConnectFD != -1)
	close(ConnectFD);
    if(SocketFD != -1)
	close(SocketFD);	
    exit(EXIT_SUCCESS);
  }


  int main(void)
  {
    char buff = 0x00;
    struct sockaddr_in stSockAddr;
    int numreadbytes = 0;
 
    /* Set the signal callback for Ctrl-C */
    signal( SIGINT, signal_handler );


    SocketFD = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP);

    if(-1 == SocketFD)
    {
      perror("can not create socket");
      exit(EXIT_FAILURE);
    }
 
    memset(&stSockAddr, 0, sizeof(stSockAddr));
 
    stSockAddr.sin_family = AF_INET;
    stSockAddr.sin_port = htons(1100);
    stSockAddr.sin_addr.s_addr = htonl(INADDR_ANY);
  
    if(-1 == bind(SocketFD,(struct sockaddr *)&stSockAddr, sizeof(stSockAddr)))
    {
      perror("error bind failed");
      close(SocketFD);
      exit(EXIT_FAILURE);
    }
 
    if(-1 == listen(SocketFD, 10))
    {
      perror("error listen failed");
      close(SocketFD);
      exit(EXIT_FAILURE);
    }
 
    while(1)
    {
      ConnectFD = accept(SocketFD, NULL, NULL);
 
      if(0 > ConnectFD)
      {
        perror("error accept failed");
        close(SocketFD);
        exit(EXIT_FAILURE);
      }
 
      while(1)
      {
	// read a byte, write a byte
        numreadbytes = read(ConnectFD,&buff,1);
	if(numreadbytes == 0) break;  // connection closed
	write(STDOUT_FILENO,&buff,1);
      }

      if (-1 == shutdown(ConnectFD, SHUT_RDWR))
      {
        perror("can not shutdown socket");
        close(ConnectFD);
        exit(EXIT_FAILURE);
      }
      close(ConnectFD);
      printf("Connection closed\n");
    }
  }
