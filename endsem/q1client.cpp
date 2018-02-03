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
void lrc(int msg[1000],int m,int sockfd,int rec_parity[1000],int l);
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
	
    int lrc_msg[10000];

	
	while(1)
	{
		
		int m,i,s,msg[1000];
		recv(sockfd,&m,sizeof(int),0);
		int mod_m=m+4,lrc_msg[1000];
		recv(sockfd,&lrc_msg,1000*sizeof(int),0);
		int rec_parity[1000];
		int l=1;
		for(i=m+1;i<=mod_m;i++)
		{
	   		rec_parity[l]=lrc_msg[i];
	   		l++;
		}
	  	int parity[1000];
	        int sum[1000]={0};
	
	for(i=1;i<=m;i++)
  	{
  		if(i%4==1)
  		{		
  			sum[1]=sum[1]+msg[i];
  		}
  		if(i%4==2)
  		{
  			sum[2]=sum[2]+msg[i];
  		}
  		if(i%4==3)
  		{
  			sum[3]=sum[3]+msg[i];
  		}
  		if(i%4==0)
  		{
  			sum[4]=sum[4]+msg[i];
  		}
  		
	}
	
	for(i=1;i<=4;i++)
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
	int count=0;
	
	for(i=1;i<l;i++)
	{
		if(rec_parity[i]==parity[i])
		{
			count++;
		}
	}
	int t;
	if(count==l-1)
	{
		t=1;
		//cout<<"\nno error in lrc\n";
		send(sockfd,&t,sizeof(int),0);
	}
	else
	{
		t=0;
		//cout<<"\nerror in lrc\n";
		send(sockfd,&t,sizeof(int),0);
	}
	}
	
  	close(sockfd);
  	return 0;
}


