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
 int decimal; 
 int x;
int count_lrc=0;
int main(int argc,char* argv[])
{
	if(argc !=2)
    {
    	cerr << "Usage syntax: ./server <port_no>" << endl;
      	return 0;
    }
  	int sockfd,temp,i=0,res,loop;
  	 int remainder,count=1;
  	char buf[50],integer[100];
	char sendbuff[10000];
	int binary[10000];
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
	fp = fopen("servert.cpp","rb");
	while(1)
				{
					unsigned char buff[5]={0};
					int nread =fread(buff,1,5,fp);
					 
					cout<<"\nBYTES READ:"<<nread<<endl;
					if(nread>0)
					{
					while(i<5)
					 {
        				 printf("%d ",buff[i]);
        				 decimal=buff[i];
        				while(decimal!= 0) {
						remainder = decimal%2;
						decimal = decimal/2;
						binary[count]=remainder;
						count++;
					    }
        				  i++;
        				 }
        				 cout<<endl;
        				 for(loop=0;loop<count;loop++)
        				 {
        				 cout<<binary[loop];
        				 }
        				 int i,parity[1000];
					 int sum[1000]={0};
					 int m,msg[1000];
	
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
	
	int y,send_msg[1000];
	for(i=1;i<=m;i++)
	{
		send_msg[i]=msg[i];
	}
	
	for(y=1;y<=4;y++)
	{
		send_msg[m+y]=parity[y];
	}
	
	send(client_fd,&m,sizeof(int),0);
	int mod_m=m+4;
	for(i=1;i<=4;i++)
	{
			x=rand()%m+1;
			//cout<<x<<endl;
			if(send_msg[x]==0)
			{
				send_msg[x]=1;
			}
			else
			{
				send_msg[x]=0;
			}
			
	}
	int s;
		send(client_fd,&send_msg,1000*sizeof(int),0);
	int t;	
	recv(client_fd,&t,sizeof(int),0);
	if(t==1)
	{
		//cout<<"\nno error in lrc\n";
	}
	else
	{
		//cout<<"\nerror in lrc\n";
		count_lrc++;
	}
        				
        				 i=0;
        				 count=1;
						cout<<"\n=====SENDING========\n";
						
					}
					if(nread<5)
					{
						if(feof(fp))
							cout<<"\n=====END OF FILE======\n";
						if(ferror(fp))
							cout<<"\nXXXXXXERROE READING\n";
						break;
					}
				}
  	close(client_fd);
  	} 
  	close(sockfd);

  return 0;
}


