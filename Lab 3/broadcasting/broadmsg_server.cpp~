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

using namespace std;

int main(int argc,char* argv[])
{
	if(argc !=2)
    {
    	cerr << "Usage syntax: ./server <port_no>" << endl;
      	return 0;
    }
  	int sockfd,i;
	int client_fd[100];
  	struct sockaddr_in my_addr;

  	sockfd=socket(PF_INET,SOCK_STREAM,0);  //Creating the socket

  	my_addr.sin_family=AF_INET;
  	my_addr.sin_port=htons(atoi(argv[1]));
  	my_addr.sin_addr.s_addr=INADDR_ANY;
  	memset(my_addr.sin_zero, '\0', sizeof my_addr.sin_zero);

  	int temp=bind(sockfd, (struct sockaddr *)&my_addr, (sizeof my_addr)); //Binding the socket to the address

  	if(temp==0)
    {
		cout << "Server started running at "<< inet_ntoa(my_addr.sin_addr)  << ":" << argv[1] << endl;
    }  
	else
    {
    	cout << "Failed to bind socket" << endl;
      	return -1;
    }

  	listen(sockfd,10);
  	for (i=0;i<3;i++) 
	{
  	struct sockaddr_in client_addr;
	socklen_t client_size=sizeof client_addr;
	client_fd[i]=accept(sockfd,(struct sockaddr*)&client_addr, &client_size);

	cout << "Accepted incoming connection:" <<i<<endl;
	}
	char buf[10000];
   	cout << "Enter the message to client:" << endl;
  	fgets(buf, 10000, stdin);
	
	for (i=0;i<3;i++) 
	{
	temp=send(client_fd[i],buf,strlen(buf)+1,0);
  	if(temp==-1)
    	{
    	cout << "Error:not sent" << endl;
    	}
  	char rec_data[10000];
 
    	temp=recv(client_fd[i],rec_data,sizeof rec_data,0);
   		if(temp!=-1)
		{
   			cout<<"echoed from "<<i<<":"<<rec_data<<endl;
  		}
		else 
   		{
			cout<<"error in echoing\n";
		}
  	close(client_fd[i]);
  	} 
  	close(sockfd);

  	return 0;
}
