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
#include <algorithm>
#include <pthread.h>

int sockfd,rnd,ack[3];
using namespace std;

int single(int a,int b)
{
	//cout<<"single a&b"<<a<<","<<b<<"\t";
	if((a==0&&b==0)||(a==1&&b==1) )
	{	//cout<<"= 0"<<"\n";
		return 0;
	}
	else if((a==1&&b==0)||(a==0&&b==1))
	{	
		//cout<<"= 1"<<"\n";
		return 1;
	}

}


void *delay(void *ppp)

{

cout<<"delay";

	usleep(5000100);
		
	send(sockfd,ack,3*sizeof(ack),0);
	cout<<"sended";
	pthread_exit(0);
}
int c=0;
pthread_t tid[1000];
int count_frames=0;
int main(int argc,char* argv[])
{

	if(argc != 3)
    {
    	cerr << "Usage syntax: ./client <ip_address> <port_no>" << endl;
      	return 0;
    }
  	
	char buf[10000];
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
	
	int crcarray2[1000] ;
	int crcarrayReceived[1000] ;
	ack[1]=1;
	
for(int s=1;s<=2;s++)	 	

{    	

ack[0]=2;

rnd=2;

while(ack[0]==2 || rnd!=1)

{
	cout<<s<<endl;	
	
	int te=recv(sockfd,(int *)crcarrayReceived, sizeof(crcarrayReceived), 0);
	
	cout<<"recv"<<te<<"bytes"<<endl;
	
	int p;
	
		
	for (int i = 1 ; i <=522 ; ++i) 

		crcarray2[i]=crcarrayReceived[i];
	    
	cout<<"ack or nack"<<crcarray2[521]<<"recv crc_sq"<<crcarray2[522]<<endl;
		
	//crc check


if(crcarray2[521]!=3)

{

int crcarraye[1000];

	int A[10],B[10],C[10];
		
	 	 B[1]=1;
	 	 B[2]=0;
	 	 B[3]=0;
	 	 B[4]=0;
	 	 B[5]=0;
	 	 B[6]=0;
	 	 B[7]=1;
	 	 B[8]=1;
	 	 B[9]=1;
	 	

	cout<<endl;
				
				int sum;
	 
	 			sum=0;
	
				for(int e=1;e<=512;e++)	

					sum=sum+crcarray2[e];
	
	
while(sum>0)	

{	
	
	
	int q=1,k=1,ctr=1,clt=1;
	
	for(int j=1;j<=520;j++)	

	{	
			
		if(crcarray2[j]==1 && k==1)

		{	k++;

				  int p;
		 			
		 		int y=1;

				for ( int p = j; p < j+9; p++ )

		 		{
		 		 		  	
		 		    C[y]=single(crcarray2[p],B[y]);

		 		    y++;  
		 		}	

				y=1;
		
				for(int d=0;d<9;d++)

					crcarray2[d+clt]=C[d+1]; //updating 
						
				 sum=0;

				for(int e=1;e<=512;e++)	

					sum=sum+crcarray2[e];
				
		}
		
		clt++;
		
	}

}
	
	cout<<"check crc"<<endl;		

	int f=0,r[8];

	for(int h=1;h<=520;h++)

	{

		if(crcarray2[h]==1)

			f++;
	}		
	
	ack[1]=crcarray2[522];	
		
	if(f==0)

	{
	
		ack[0]=1;		//ack
	
		cout<<"no error"<<endl;
		
		count_frames++;

	}

	else

	{

		ack[0]=2;		//nack

		cout<<"there is an error"<<endl;

	}

	srand(time(0));

	rnd=rand()%3+1;		/*if rnd=1 then it represents ack or nack
	
					  if rnd=2 then it represents dack or dnack
					  
					  if rnd=3 then it represents ack_drop or nack_drop*/	

	rnd=1;
	
	cout<<"rnd"<<rnd<<endl;
	
		if(ack[0]==1)
		
			ack[1]=1-ack[1];		

	ack[2]=rnd;
		
	if(rnd==1)
	
	{
		
		cout<<"ack"<<ack[0]<<ack[1]<<ack[2]<<endl;
	
		send(sockfd,ack,3*sizeof(ack),0);
		
	}
	
	else if(rnd==2)
	
	{
		c++;
		
		pthread_create(&tid[c],NULL,delay,NULL);
		
		pthread_join(tid[c],NULL);
	
	}
	
	
	else if(rnd==3)
	
	{
	
		send(sockfd,ack,3*sizeof(ack),0);
	
	}
	

	cout<<endl;

}

else if(crcarray2[521]==3)


	cout<<"frame drop\n";

}

}

cout<<"no.of successful frames"<<count_frames<<endl;	

  	close(sockfd);

  	return 0;
 }	
