#include <iostream>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>
#include <time.h>
#include<vector>
#include <stdlib.h>

using namespace std;

int main(int argc,char* argv[])
{
	if(argc !=2)
    {
    	cerr << "Usage syntax: ./server <port_no>" << endl;
      	return 0;
    }
  	int sockfd,temp,i;
	int client_fd[100];
  	struct sockaddr_in my_addr;

  	sockfd=socket(PF_INET,SOCK_STREAM,0);  //Creating the socket

  	my_addr.sin_family=AF_INET;
  	my_addr.sin_port=htons(atoi(argv[1]));
  	my_addr.sin_addr.s_addr=INADDR_ANY;
  	memset(my_addr.sin_zero, '\0', sizeof my_addr.sin_zero);

  	temp=bind(sockfd, (struct sockaddr *)&my_addr, (sizeof my_addr)); //Binding the socket to the address

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
	char serv_msg[50][50];

  	for (i=0;i<2;i++) 
	{
  	struct sockaddr_in client_addr;
	socklen_t client_size=sizeof client_addr;
	client_fd[i]=accept(sockfd,(struct sockaddr*)&client_addr, &client_size);

	cout << "Accepted incoming connection "<<i<< endl;
	time_t now=time(0);
	strcpy(serv_msg[i],ctime(&now));
	}
		
	for(i=0;i<2;i++)
	{		
  		temp=send(client_fd[i],serv_msg[i],sizeof serv_msg[i],0);
  		close(client_fd[i]);
  	} 
  	close(sockfd);

  	return 0;
}
