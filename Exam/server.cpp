#include <iostream>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>
#include <string>
#include<signal.h>

using namespace std;

int main(int argc,char* argv[])
{
	if(argc !=2)
	{
		cerr << "Usage syntax: ./server <port_no>" << endl;
		return 0;
	}
	int sockfd;
	struct sockaddr_in my_addr;
	
	sockfd=socket(PF_INET,SOCK_STREAM,0);  //Creating the socket
	
	my_addr.sin_family=AF_INET;
	my_addr.sin_port=htons(atoi(argv[1]));
	my_addr.sin_addr.s_addr=inet_addr("0.0.0.0");
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
	
	struct sockaddr_in client_addr;
	socklen_t client_size=sizeof client_addr;
	int client_fd=accept(sockfd,(struct sockaddr*)&client_addr, &client_size);
	
	cout << "Accepted incoming connection" << endl;
	
	
	
	/*Main program starts here*/
	
	
	
	char sen[1000];
	char rec[1000];
	
	while(1)
	{
		bzero(sen,sizeof(sen));  //same as memset
		bzero(rec,sizeof(rec));
		
		pid_t id=fork();
		
		if(id<0)
		{
			cerr<<"Failed\n"<<endl;
			return 0;
		}
		else if(id==0)
		{
			temp=recv(client_fd,rec,sizeof rec,0);
			
			cout<<"\tClient::::"<<rec<<endl;
			
			if(strncmp("exit",rec,4)==0)
			{
				cout<<"Server exit.\n";
				kill(0,SIGKILL);
			}		
		}
		else
		{
			cin.getline(sen,1000);
			
			temp=send(client_fd,sen,sizeof sen,0);
			
			if(strncmp("exit",sen,4)==0)
			{
				cout<<"Server exit.\n";
				kill(0,SIGKILL);
			}
		}
	}
	
	close(client_fd);
	close(sockfd);
	
	return 0;
}
