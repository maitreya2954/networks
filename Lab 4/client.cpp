#include <iostream>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>
#include <signal.h>

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
	
	
	
	
	/*Main program starts here*/
	
	char sen[1000];
	char rec[1000];
	int received;
	
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
			
			cin.getline(sen,1000);
			
			temp=send(sockfd,sen,sizeof sen,0);
			
			if(temp==-1)
				cout<<"Error:: Msg not sent";
			
			if(strncmp("exit",sen,4)==0)
			{
				cout<<"Server exit.\n";
				kill(0,SIGKILL);
			}
		}
		else
		{
			received=recv(sockfd,rec,sizeof rec,0);
			
			if(received==-1)
			{
				cout<<"Failed"<<endl;
				return -1;
			}
			else
			{
				cout<<"\tServer"<<rec<<endl;
				
				if(strncmp("exit",rec,4)==0)
				{
					cout<<"Server exit.\n";
					kill(0,SIGKILL);
				}
			}
		}
	}
	close(sockfd);
	return 0; 
}
