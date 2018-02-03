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

using namespace std;
int add(int array[100],int k)
{
	int carry=0,i;
	int d[100],c[1000],b[1000],j;
	d[1]=0;
	d[2]=0;
	d[3]=0;
	d[4]=1;
		for(i=1;i<=4;i++)
		{
			c[i]=array[i];
			//cout<<a[i]<<' ';
		}
		cout<<endl;
		for(j=1;j<k;j++)
		{
			for(i=1;i<=4;i++)
			{
				b[i]=array[i+j*4];
				cout<<b[i]<<' ';
				//cout<<c[i]<<' ';
			}
			cout<<endl;
			carry=0;
			for(i=4;i>=1;i--)
			{
				if(c[i]+b[i]+carry==0)
				{
					cout<<1<<' '<<i<<' '<<c[i]<<' ';
					cout<<b[i]<<endl;
					c[i]=0;
					carry=0;
				}
				else if(c[i]+b[i]+carry==1)
				{
				cout<<2<<' '<<i<<' '<<c[i]<<' ';
				cout<<b[i]<<endl;
					c[i]=1;
					carry=0;
				}
				else if(c[i]+b[i]+carry==2)
				{
					cout<<2<<' '<<i<<' '<<c[i]<<' ';
					cout<<b[i]<<endl;
					c[i]=0;
					carry=1;
				}
				else
				{
					cout<<4<<' '<<i<<' '<<c[i]<<' ';
					cout<<b[i]<<endl;
					c[i]=1;
					carry=1;
				}
				//cout<<i<<' '<<c[i]<<' '<<carry<<endl;
			}
			if(carry==1)
			{
				carry=0;
				for(int t=4;t>=1;t--)
				{
					if(c[t]+d[t]+carry==0)
					{
						//cout<<1<<' '<<i<<' '<<c[i]<<' ';
						//cout<<b[i]<<endl;
						c[t]=0;
						carry=0;
					}
					else if(c[t]+d[t]+carry==1)
					{
					//cout<<1<<' '<<i<<' '<<a[i]<<' ';
					//cout<<b[i]<<endl;
						c[t]=1;
						carry=0;
					}
					else if(c[t]+d[t]+carry==2)
					{
						//cout<<2<<' '<<i<<' '<<c[i]<<' ';
						//cout<<b[i]<<endl;
						c[t]=0;
						carry=1;
					}
					else
					{
						//cout<<3<<' '<<i<<' '<<a[i]<<' ';
						//cout<<b[i]<<endl;
						c[t]=1;
						carry=1;
					}
					//cout<<t<<' '<<c[t]<<' '<<carry<<endl;
				}
			}
			
		}
		for(i=1;i<=4;i++)
		{
			cout<<c[i]<<' ';
			if(c[i]==1)
			{
				c[i]=0;
				cout<<c[i]<<endl;
			}
			else
			{
				c[i]=1;
				cout<<c[i]<<endl;
			}
		}
		cout<<endl;
		int t=1;
		for(i=17;i<=20;i++)
		{
			array[i]=c[t];
			t++;	
		}	
	return 0;
}
			
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
	int i,j=1,k,count=0;
	k=16/4;
	int array[1000],a[1000],b[1000],e[1000],carry=0,integer1;
	//for(int h=1;h<=100;h++)
	//{
		for(i=1;i<=16;i++)
		{
			array[i]=rand()%2;
			///a[i]=array[i];
			cout<<array[i]<<' ';
		}
		cout<<endl;
		add(array,k);
		
		for(i=1;i<=20;i++)
		cout<<array[i];
		cout<<endl;
		
		for(i=1;i<=4;i++)
		{
			e[i]=1+rand()%(16+k);
			cout<<e[i]<<" ";
			if(array[e[i]]==1)
			array[e[i]]=0;
			else
			array[e[i]]=1;
		}	
		for(i=1;i<=16+k;i++)
		{
			cout<<array[i]<<' ';
		}
		for(int t=1; t<=16+k; t++)
   		{
        		int integer1=array[t];
        		send(client_fd,&integer1,sizeof (int),0);
		}
	
		close(client_fd);
		close(sockfd);
	
	return 0;
}
	
			
				
		
	
	
			
