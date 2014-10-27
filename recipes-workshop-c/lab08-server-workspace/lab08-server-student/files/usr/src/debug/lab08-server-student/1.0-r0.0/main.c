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

  }
