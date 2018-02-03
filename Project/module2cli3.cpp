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
	int d[100],c[1000],b[1000],j,count=0;
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
					//cout<<1<<' '<<i<<' '<<c[i]<<' ';
					//cout<<b[i]<<endl;
					c[i]=0;
					carry=0;
				}
				else if(c[i]+b[i]+carry==1)
				{
				//cout<<2<<' '<<i<<' '<<c[i]<<' ';
				//cout<<b[i]<<endl;
					c[i]=1;
					carry=0;
				}
				else if(c[i]+b[i]+carry==2)
				{
					//cout<<2<<' '<<i<<' '<<c[i]<<' ';
					//cout<<b[i]<<endl;
					c[i]=0;
					carry=1;
				}
				else
				{
					//cout<<4<<' '<<i<<' '<<c[i]<<' ';
					//cout<<b[i]<<endl;
					c[i]=1;
					carry=1;
				}
				cout<<i<<' '<<c[i]<<' '<<carry<<endl;
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
					cout<<t<<' '<<c[t]<<' '<<carry<<endl;
				}
			}
			
		}
		for(i=1;i<=4;i++)
		{
			cout<<c[i]<<' ';
			if(c[i]==1)
			count++;
		}
		cout<<endl;
		if(count==4)
		cout<<"error unnoticed/there is no error"<<endl;
		else
		cout<<"there is error"<<endl;
			
	return 0;
}
		
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
	{
    		cout << "Connection established with server" << endl;
	}
  	else
    	{
    		cout << "Could not establish connection!" << endl;
      		return -1;
    	}
    
    
    	int integer3,integer4,ar[1000],i,k,j=1,count=0,c,carry=0;
	int array[1000],a[1000],b[1000];
	k=16/4;
	//for(int h=1;h<=100;h++)
	//{
		for(i=1; i<=16+k; i++)
   		{
     			recv(sockfd,&integer3,sizeof (int),0);
     			array[i]=integer3;
     			cout<<array[i]<<' ';
   		}
   		cout<<endl;
   		/*for(int h=1; h<=k; h++)
   		{
     			recv(sockfd,&integer4,sizeof (int),0);
     			a[h]=integer4;
     			cout<<a[h]<<' ';
   		}*/
   		cout<<endl;
   		add(array,k+1);
		
		close(sockfd);
		return 0;
	}
			
		
		
		
