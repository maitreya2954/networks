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

void lrc(int msg[1000],int n,int sockfd,int parity[1000],int l);
int main(int argc,char* argv[])
{
	
	if(argc != 3)
    {
    	cerr << "Usage syntax: ./client <ip_address> <port_no>" << endl;
      	return 0;
    }
 	int sockfd;
	int b_recv=0;
	
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
	
    int message[222222];

	
	while(1)
	{
		
		int n,i,s,msg[2222];
		
		read(sockfd,&n,sizeof(int));
		
		int M=n+4,message[2222];
		
		recv(sockfd,&message,2222*sizeof(int),0);
		for(i=1;i<=M;i++)
		{
		cout<<message[i];
		}
		int parity[2222];
		int l=1;
		for(i=n;i<M;i++)
		{
	   		parity[l]=message[i];
	   		l++;
		}
	  	lrc(message,n,sockfd,parity,l);
	}
	
  	close(sockfd);
  	return 0;
}

void lrc(int msg[2222],int n,int sockfd,int recv_parity[2222],int l)
{
	int i,parity[2222];
	int sum[2222]={0};
	
	for(i=1;i<=n;i++)
  	{
  		if(i%4==0)
  		{
  			sum[3]=sum[3]+msg[i];
  		}
  		
  		
  		if(i%4==1)
  		{		
  			sum[0]=sum[0]+msg[i];
  		}
  		if(i%4==2)
  		{
  			sum[1]=sum[1]+msg[i];
  		}
  		if(i%4==3)
  		{
  			sum[2]=sum[2]+msg[i];
  		}
  		
	}
	
	for(i=0;i<4;i++)
	{
		if(sum[i]%2==0)
		{
			parity[i]=0;
		}
		else
		{
			parity[i]=1;
		}
	}
	int ctr=0;
	
	for(i=1;i<l;i++)
	{
		if(recv_parity[i]==parity[i])
		{
			ctr++;
		}
	}
	int s;
	if(ctr==l-1)
	{
		s=1;
		send(sockfd,&s,sizeof(int),0);
	}
	else
	{
		s=0;
		send(sockfd,&s,sizeof(int),0);
	}
}
