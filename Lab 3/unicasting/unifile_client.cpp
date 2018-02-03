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
	int bytesreceived=0;
	
  	struct sockaddr_in my_addr;
  	sockfd=socket(PF_INET,SOCK_STREAM,0);

  	my_addr.sin_family=AF_INET;
  	my_addr.sin_port=htons(atoi(argv[2]));
  	my_addr.sin_addr.s_addr=inet_addr(argv[1]);
  	memset(my_addr.sin_zero, '\0', sizeof my_addr.sin_zero);

  	int temp=connect(sockfd,(struct sockaddr*)&my_addr, sizeof my_addr);

  	if(temp==0)
    {
		cout << "Connection established with server" << endl;
  	}
	else
    {
    	cout << "Could not establish connection!" << endl;
      	return -1;
    }
	
    char recvbuff[10000];

	FILE *fw;
	fw = fopen("2.png","wb");
	while((bytesreceived=read(sockfd,recvbuff,256))>0)
	{
		cout<<"\nbytes received"<<bytesreceived<<"\n";
		fwrite(recvbuff,1,bytesreceived,fw);
	}
	if(bytesreceived<0)
	{
		cout<<"\nXXXXXREAD ERRORXXXXXXXXXXXX\n";
	}
  	close(sockfd);
  	return 0;
}
