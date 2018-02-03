#include <iostream>
#include <vector>
#include <sys/sendfile.h>
#include <sys/stat.h> 
#include <fcntl.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>
#include <errno.h>
#include <cstdio>



using namespace std;


int main(int argc, char **argv)
{

int sockfd,newsocketfd[100],portno,f=0;
char buffer[256],serv_msg[50];;
struct sockaddr_in serv_addr,cli_addr;
int n,i=0,count,temp,j;
fd_set master, read_fds;

	if(argc != 3)
	{
		cout<<"Usage syntax: ./server <port_no>"<<endl;
		return 0;
	}
	
	
	
	sockfd = socket(PF_INET, SOCK_STREAM, 0);
	
	if(sockfd == -1)
	{
		perror("The following error occurred");	
		return -1;
	}
	else
		cout<<"Socket successfully created."<<endl;


	
	
	bzero((char*)&serv_addr,sizeof(serv_addr));
	serv_addr.sin_family = AF_INET;
	serv_addr.sin_port = htons(atoi(argv[1]));
	serv_addr.sin_addr.s_addr = INADDR_ANY;
	//memset(serv_addr.sin_zero,0,sizeof(serv_addr.sin_zero));	
	
	
	
	//Bindig the Socket to a port
	temp = bind(sockfd, (struct sockaddr *)&serv_addr, sizeof(struct sockaddr));

	if(temp == -1)
	{
		perror("The following error occurred");	
		
	}
	else
		cout << "Server started running at "<< inet_ntoa(serv_addr.sin_addr)  << ":" << argv[1] << endl;



	//Listen to the port
	temp = listen(sockfd, 10);

	if(temp == -1)
	{
		perror("The following error occurred");	
		
	}


	int maxsock = 0;
	
	
	FD_ZERO(&master);
	FD_ZERO(&read_fds);
	

	int num = atoi(argv[2]);
	

socklen_t clilen = sizeof(struct sockaddr);
for(count=1;count<=num;count++)
{

if((newsocketfd[i] = accept(sockfd,(struct sockaddr *)&cli_addr, &clilen))<0)
{
perror("connection couldn't established");
}
else
{
FD_SET(newsocketfd[i], &master);

if (newsocketfd[i] > maxsock) 
maxsock = newsocketfd[i];

printf("accepted %d\n",i);
}
i++;
}




	struct timeval tv;
	
	tv.tv_sec = 0;//2;
	tv.tv_usec = 1000000;
	
	int bytesSent;
	//char receivedBuff[100];
	
	
	while(f==0)
	{
		read_fds = master;
		
		int numFds = select(maxsock+1, &read_fds, NULL, NULL, &tv);	
	
		if(numFds == -1)
		{
			perror("Select() ");	
			return -1;
		}
		else if(numFds > 0)
		{
		for(i=0;i<num;i++)
		{
			if(FD_ISSET(newsocketfd[i], &read_fds))
			{

				j=i;
				

				bzero(buffer,256);			

				temp = read(newsocketfd[i],buffer,255);

				if(temp == -1)
				{
					cout<<"Data could not be received :"<<endl;
					perror("read");	
				}
				else if(temp == 0)
				{
					cout<<"Connection closed by remote machine."<<endl;
					f=1;
					break;
				}
				

				for(int k=0;k<num;k++)
				{	
				cout<<j;	
				if(k!=j )
				{
				bytesSent = write(newsocketfd[k], buffer, strlen(buffer)+1);
		
				if(bytesSent == -1)
				{
			        perror("send ");
				return-1;		
				}
				else if(bytesSent ==0)
				break;
				}
				}

			}
			}
			
		
		}
		
			//else if(numFds==0)
			//break;	
		}
	

	
	close(sockfd);
	for(i=0;i<num;i++)
	{
		close(newsocketfd[i]);
	}

	return 0;
}
