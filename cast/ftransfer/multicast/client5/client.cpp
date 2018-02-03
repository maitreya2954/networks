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
  if(argc != 3)
    {
      cerr << "Usage syntax: ./client <ip_address> <port_no>" << endl;
      return 0;
    }
 	int sockfd;
	
  struct sockaddr_in my_addr;
 char recvbuff[1000];
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
  	char f[100];
  	recv(sockfd, f, sizeof f,0);
  	cout<<f[0]<<endl;
  	if(f[0]=='s')
  	{
  		cout<<"open"<<endl;
  		FILE *yfile;
	        yfile=fopen("2.pdf","wb");	
	        while(1)
	        {
		        recv(sockfd, recvbuff, sizeof recvbuff,0);
    	                if(!strcmp(recvbuff,"xyz"))
    		                break;

 	 	        fwrite(recvbuff,sizeof recvbuff,1,yfile);
   		        memset(recvbuff,0,sizeof recvbuff);	
	        }
	 }
  close(sockfd);
  return 0;
}
