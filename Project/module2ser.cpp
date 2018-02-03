#include <iostream>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include <cstdlib>
using namespace std;

int main(int argc,char* argv[])
{
	if(argc !=2)
    {
    	cerr << "Usage syntax: ./server <port_no>" << endl;
      	return 0;
    }
  	int sockfd;
  	char buf[50];
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
  	struct sockaddr_in client_addr;
	socklen_t client_size=sizeof client_addr;
	int client_fd=accept(sockfd,(struct sockaddr*)&client_addr, &client_size);
        //int client_fd2=accept(sockfd,(struct sockaddr*)&client_addr, &client_size);

	cout << "Accepted incoming connection" << endl;
	int i,j=1,rownum,ctr=0;
	rownum=512/32;
	int array[1111],a[1111],b[1111];
		srand(time(0));
		for(int h=1;h<=100;h++)
			{
				for(i=1;i<=512;i++)
					{
						array[i]=rand()%2;
						a[i]=array[i];
						cout<<array[i]<<' ';
					}
			cout<<endl;
	
		for(i=1;i<=512;i++)
			{
				if(array[i]==1)
				ctr++;
				if(i==j*16)
					{
			
					if(ctr%2==0)
					a[j]=0;
					else
					a[j]=1;
					j++;
					ctr=0;
			
					}
			}
			int l=1;
		
			for(i=513;i<=512+rownum;i++)
				{
					array[i]=a[l];
					l++;
				}
				cout<<endl;
	
			for(i=1;i<=512+rownum;i++)
				{
				cout<<array[i]<<' ';
				}
				cout<<endl;
		
		srand(time(0));
	
					for(i=1;i<=10;i++)
				{
					b[i]=1+rand()%(512+rownum);
					cout<<b[i]<<" ";
					if(array[b[i]]==1)
					array[b[i]]=0;
					else
					array[b[i]]=1;
				}
			//for(i=1;i<=512+rownum;i++)
			//	{
			//	cout<<array[i]<<' ';
			//	}
					for(int t=1; t<=512+rownum; t++)
			   			{
				        		int integer1=array[t];
				        		send(client_fd,&integer1,sizeof (int),0);
 						}
				}	
	close(client_fd);
	close(sockfd);
		
	return 0;
}
		
	
	
