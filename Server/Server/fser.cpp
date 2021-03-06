#include <iostream>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>
#include<fstream>

using namespace std;

int main(int argc,char* argv[])
{
  if(argc !=3)
    {
      cerr << "Usage syntax: ./server <port_no> <file to transfer>" << endl;
      return 0;
    }
  int sockfd;
  char buf[50],integer[100];
  struct sockaddr_in my_addr;

  sockfd=socket(PF_INET,SOCK_STREAM,0);  //Creating the socket

  my_addr.sin_family=AF_INET;
  my_addr.sin_port=htons(atoi(argv[1]));
  my_addr.sin_addr.s_addr=INADDR_ANY;
  memset(my_addr.sin_zero, '\0', sizeof my_addr.sin_zero);

  int temp=bind(sockfd, (struct sockaddr *)&my_addr, (sizeof my_addr)); //Binding the socket to the address

  if(temp==0)
    cout << "Server started running at "<< inet_ntoa(my_addr.sin_addr)  << ":" << argv[1] << endl;
  else
    {
      cout << "Failed to bind socket" << endl;
      return -1;
    }

  listen(sockfd,10);
  //for ( ; ; ) 
  {
 	 struct sockaddr_in client_addr;
 	 socklen_t client_size=sizeof client_addr;
 	 int client_fd=accept(sockfd,(struct sockaddr*)&client_addr, &client_size);
	
	 cout << "Accepted incoming connection" << endl;
	 char recvbuff[10000];

	FILE *yfile;
	yfile=fopen(argv[2],"wb");	
	 while(1)
	 {
		recv(client_fd, recvbuff, sizeof recvbuff,0);
    	if(!strcmp(recvbuff,"xyz"))
    		break;

 	 	fwrite(recvbuff,sizeof recvbuff,1,yfile);
   		memset(recvbuff,0,sizeof recvbuff);	
	 }
 	 close(client_fd);
  } 
  close(sockfd);

  return 0;
}




