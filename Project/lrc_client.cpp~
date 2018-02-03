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
    
    
    	int binary1,binary2,ar[1111],i,k,j,ctr;
	
	int array[1111],a[1111];
	k=512/32;

	for(i=1; i<=512+k; i++)
   	{
     		recv(sockfd,&binary1,sizeof (int),0);
     		array[i]=binary1;
     		cout<<array[i]<<' ';
   	}

   	cout<<endl;
   	cout<<endl;
   	int p,l=1;
   	
   	for(p=1;p<=k;p++)
	{
			for(j=0;j<16;j++)
			{
				if(array[p+j*32]==1)
				ctr++;
				
			}
		
			if(ctr%2==0)
			ar[l]=0;
		
			else
			ar[l]=1;
			l++;
	
	}
   	
   //	for(int f=1;f<=k;f++)
//	{
	//cout<<ar[f]<<' ';
//	}
	int y=1,par=513;

	
	for(int r=1;r<=k;r++)
	
			{
				if(array[par]==ar[r])
					y++;
				else 
					par++;
			}

	if(y==k)
	cout<<"there is no error"<<endl;

	else
	cout<<"there is error"<<endl;

		close(sockfd);

}


   	
