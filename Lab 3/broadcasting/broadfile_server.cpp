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
	if(argc !=2)
    {
    	cerr << "Usage syntax: ./server <port_no>" << endl;
      	return 0;
    }
  	int sockfd,temp,i;
  	char buf[10000],integer[100];
	char sendbuff[10000];
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
  	for (i=0;i<3;i++) 
	{
  	struct sockaddr_in client_addr;
  	socklen_t client_size=sizeof client_addr;
  	client_fd[i]=accept(sockfd,(struct sockaddr*)&client_addr, &client_size);

  	cout << "Accepted incoming connection:" <<i<<endl;
	}
	
	for (i=0;i<3;i++) 
	{
	 FILE *fr;
	fr = fopen("1.png","rb");
	while(1)
				{
					
						unsigned char buff[256]={0};
						int nread =fread(buff,1,256,fr);
						cout<<"\nBYTES READ:"<<nread;
						if(nread>0)
						{
							cout<<"\n=====SENDING========\n";
							write(client_fd[i],buff,nread);
						}
						if(nread<256)
						{
							if(feof(fr))
							{
							cout<<"\n=====END OF FILE======\n";
							close(client_fd[i]);
							}
							if(ferror(fr))
							{
							cout<<"\nXXXXXXERROE READING\n";
							}
						break;
					}
				
				}
  	
  	} 
  	close(sockfd);

  return 0;
}
