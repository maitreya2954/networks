#include <iostream>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>
#include<stdio.h>
#include<fstream>

using namespace std;

int main(int argc,char* argv[])
{
  if(argc != 4)
    {
      cerr << "Usage syntax: ./client <ip_address> <port_no><file to transfer>" << endl;
      return 0;
    }
 	int sockfd;
	
  struct sockaddr_in my_addr;
  char sendbuff[10000];
  sockfd=socket(PF_INET,SOCK_STREAM,0);

  my_addr.sin_family=AF_INET;
  my_addr.sin_port=htons(atoi(argv[2]));
  my_addr.sin_addr.s_addr=inet_addr(argv[1]);
  memset(my_addr.sin_zero, '\0', sizeof my_addr.sin_zero);

  int temp=connect(sockfd,(struct sockaddr*)&my_addr, sizeof my_addr);

  	if(temp==0)
   		cout << "Connection established with server" << endl;
  	else
  	{
  	 	cout << "Could not establish connection!" << endl;
     	return -1;
  	}
  	FILE *myfile;
  	myfile=fopen(argv[3],"rb");
	while(!feof(myfile))
	{
	  fread(sendbuff,sizeof sendbuff,1,myfile);
	  send(sockfd, sendbuff,sizeof sendbuff,0);
	}
	send(sockfd, "xyz", 3, 0); 
  
  close(sockfd);
  return 0;
}
