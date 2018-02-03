#include <iostream>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>

using namespace std;

int num;
int adj[6][6],a[20];
int sockfd;
int k=0;

void binary(int );

void binary(int num)
{
    	int rem;

    	if (num <= 1)
    	{
        	//cout << num;
		a[k++]=num;	        
		return;
    	}

    	rem = num % 2;

//	cout << rem <<"   ";

	a[k++]=rem;
		
	
    	binary(num / 2);
}



int main(int argc,char* argv[])
{
 
	if(argc != 3)
    	{
      		cerr << "Usage syntax: ./client <ip_address> <port_no>" << endl;
      		return 0;
    	}
  //	int sockfd;
  	struct sockaddr_in my_addr;

  	sockfd=socket(PF_INET,SOCK_STREAM,0);

  	my_addr.sin_family=AF_INET;
  	my_addr.sin_port=htons(atoi(argv[2]));
  	my_addr.sin_addr.s_addr=inet_addr(argv[1]);
  	memset(my_addr.sin_zero, '\0', sizeof my_addr.sin_zero);

  	int temp=connect(sockfd,(struct sockaddr*)&my_addr, sizeof my_addr);

  	if(temp==0)
    		cout << "Connection established with server" << endl;
  	
	else
    	{
      		cout << "Could not establish connection!" << endl;
      		return -1;
    	}

  	char buf[500];
  	cout << "Enter the message to client2:" << endl; //sendind cliam to client_2
  	cin.getline(buf,500);
  

	temp=send(sockfd,buf,strlen(buf)+1,0);

  	char rec_data[500];

  	recv(sockfd,rec_data,sizeof rec_data,0);
  	cout << "message from client2:" << rec_data << endl;	//reply from client_2


	int i,j,l;



	for(i=0;i<=32767;i++)
	{
		k=0;
		l=0;

		for(j=0;j<15;j++)
			a[j]=0;


		binary(i);
		

	
		for(j=5;j>=0;j--)
			for(k=5;k>=0;k--)
				adj[j][k]=0;


		
		
		for(j=4;j>=0;j--)
		{
			for(k=j+1;k<6;k++)
			{
				if(j!=k)
				{
					adj[j][k]=a[l];	
				//	cout<<"a[l] is:::"<<a[l]<<endl;

				//	cout<<"adj["<<j<<"]["<<k<<"] is:::"<<adj[j][k]<<endl;
				
					adj[k][j]=adj[j][k];
					l++;
				}
			}
		}

		cout<<"matrix no:::"<<i+1<<endl;

		for(j=0;j<6;j++)
		{
			for(k=0;k<6;k++)
			{
				cout<< adj[j][k]<<"  ";
			}
		
			cout<<endl;

		}


		cout<<endl;


	  	int temp1=send(sockfd,adj,sizeof(int)*6*6,0);
  
		if(temp1==-1)
			cout<<"\ncannot send data\n";
	
		int flag=0;
	
	
		char buf1[50]="perfect, not convinced. send next graph";
		char buf2[50];	
		char buf3[50]="claim is false, something went wrong";


		int temp=recv(sockfd,buf2,sizeof(buf2),0);

		cout<<"client 2 says:"<<buf2<<endl;	

		
	}

	

  	close(sockfd);
  	return 0;
}

