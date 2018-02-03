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
    
    
    	int bin1,bin2,ar[1000],i,rownum,j=1,ctr;

	int array[1000],a[1000];

	rownum=512/32;

	for(int h=1;h<=100;h++)

	{
		for(i=1; i<=512+rownum; i++)
   		{
     			recv(sockfd,&bin1,sizeof (int),0);
     			array[i]=bin1;
     			cout<<array[i]<<' ';
   		}
   		cout<<endl;
   		
   		cout<<endl;
   		int p;
		
		for(p=1;p<=512;p++)
		
		{
			if(array[p]==1)
			ctr++;
			if(p==j*16)
			{
				//i++;
			
				if(ctr%2==0)
		{
				ar[j]=0;
}		
				else
		{
				ar[j]=1;
				j++;
		
			}
		}
}		
		//for(int f=1;f<=rownum;f++)
		//cout<<ar[f]<<' ';
		//cout<<endl;
		
		int y=1,parity=513;
		
		for(int r=1;r<=rownum;r++)
		{
			if(a[parity]==ar[r])
			y++;
			else 
			parity++;
		}
		
		if(y==rownum)
		cout<<"there is no error"<<endl;
		
		else
		cout<<"there is error"<<endl;
	}
	close(sockfd);
}	


