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
void lrc(int msg[1000],int m,int client_fd);
using namespace std;
 int point; 
 int a;
int count_lrc=0;
int main(int argc,char* argv[])
{
	if(argc !=2)
    {
    	cerr << "Usage syntax: ./server <port_no>" << endl;
      	return 0;
    }
  	int sockfd,temp,i=0,res,l,bin[10000],rem,ctr=1;
  
  	char buffer[50],integer[100];
	char sendbuff[10000];
	
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
  	for ( ; ; ) 
	{
  	struct sockaddr_in client_addr;
  	socklen_t client_size=sizeof client_addr;
  	int client_fd=accept(sockfd,(struct sockaddr*)&client_addr, &client_size);

  	cout << "Accepted incoming connection" << endl;
	FILE *fp;
	fp = fopen("client.c","rb");
	do
				{
					unsigned char buffer[40]={0};
					int read =fread(buffer,1,40,fp);
					 
	cout<<read<<endl;
	if(read>0)
	{
	{
         printf("%d ",buffer[i]);
         point=buffer[i];
        do {
		rem = point%2;
		point = point/2;
		bin[ctr]=rem;
		ctr++;
	    }while(point!= 0);
        		  
        	  i++;
        	  
        	 }while(i<40);
         
        	 cout<<endl;
        	 for(l=0;l<ctr;l++)
        	 {
        	 cout<<bin[l];
        		 }
        	
		lrc(bin,ctr,client_fd);
        	 
        		 i=0;
        		  ctr=1;
			
	}
		if(read<40)
		{
			if(feof(fp))
				cout<<"\n####################\n";
			if(ferror(fp))
				cout<<"\nXXXXXXXX-----ERR----XXXXXXXXXXXXXX\n";
			}
		}while(1);
  	close(client_fd);
  	} 
  	close(sockfd);

  return 0;
}

void lrc(int msg[2222],int n,int client_fd)
{
	int i,lrc_par[2222];
	int sum[2222]={0};
	
	for(i=0;i<n;i++)
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
	
	for(i=1;i<=4;i++)
	{
		if(sum[i]%2==0)
		{
			lrc_par[i]=0;
		}
		else
		{
			lrc_par[i]=1;
		}
	}
	
	int s,message[1000];
	
	for(i=0;i<n;i++)
	{
		message[i]=msg[i];
	}
	
	for(s=0;s<4;s++)
	{
		message[n+s]=lrc_par[s];
	}
	
	write(client_fd,&n,sizeof(int));
	int M=n+4;
	//send(client_fd,&mod_m,sizeof(int),0);
	time_t timer;
	srand((unsigned) time(&timer));
	int err=rand()%2;
	if(err=1)
	{
	for(i=0;i<4;i++)
	{
			a=rand()%n+1;
			//cout<<x<<endl;
			if(message[a]==0)
			{
				message[a]=1;
			}
			else
			{
				message[a]=0;
			}
			
	}
	}
	
	
		send(client_fd,&message,1000*sizeof(int),0);
	int k;	
	recv(client_fd,&k,sizeof(int),0);
	if(k==1)
	{
		cout<<"\nNO ERR \n";
	}
	else
	{
		cout<<"\n ERR\n";
		
	}
}
