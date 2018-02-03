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
#include <stdint.h>
#include <cstdlib> 
#include <ctime> 


	int ack[3],count11=0;
using namespace std;

int single(int a,int b)
{
	
	if((a==0&&b==0)||(a==1&&b==1) )
	{
		return 0;
	}
	else if((a==1&&b==0)||(a==0&&b==1))
	{
		return 1;
	}

}
  	int sockfd;

	int client_fd[100];

	fd_set rfds,master;

	int retval;

	int mod[540];

int main(int argc,char* argv[])

{
	if(argc !=2)
	{
	    	cerr << "Usage syntax: ./server <port_no>" << endl;
	      	return 0;
	}
  	  	
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
  	int ccc=0;
	  	struct sockaddr_in client_addr;
		socklen_t client_size=sizeof client_addr;
		client_fd[0]=accept(sockfd,(struct sockaddr*)&client_addr, &client_size);

FD_SET(client_fd[0],&master);

	cout << "Accepted incoming connection:" <<endl;
	
	
	int crcarray1[1000];
	int crcarray2[1000];
	int crcarraye[1000];
	int A[10],B[10],C[10];
	
	
	 srand((unsigned)time(0)); 
	 
	
	 	 B[1]=1;
	 	 B[2]=0;
	 	 B[3]=0;
	 	 B[4]=0;
	 	 B[5]=0;
	 	 B[6]=0;
	 	 B[7]=1;
	 	 B[8]=1;
	 	 B[9]=1;

crcarray1[522]=0;

mod[522]=0;	 	

int drop_ack_nack=0,nack=0,frame_drop=0,dealy_ack_nack=0,cuo=0;

for(int s=1;s<=100;s++)	 	

{    	
cout<<"frame"<<endl;

cout<<s<<endl;	
		
    	int i,k;
  	 
    	for(i=1; i<=512; i++)
    	{ 
    		
    	    		crcarray1[i] = (rand()%2);     	     
    	   		    	   		
    	   		crcarray2[i] = crcarray1[i]; //duplicate crcarray
    	   				
	}
	
	for(i=513;i<=520;i++)
	{
		crcarray1[i] = 0; 
		crcarray2[i] = crcarray1[i]; 
	}
	
	cout<<endl;
	int sum;
	 sum=0;
				for(int e=1;e<=520;e++)	
				{
					sum=sum+crcarray2[e];
				}
	
	
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
	
	int f=1,r[8];
	
	for(int h=513;h<=520;h++)
	
	{
		r[f]=crcarray2[h];
	
		f++;
	
	}	
	
	int w=1;
	
	for(int u=513;u<=520;u++)
	
	{
	
		crcarray1[u]=r[w];
	
		w++;
	
	}

		for(int sh=1;sh<=520;sh++)
		
			mod[sh]=crcarray1[sh];

           

ack[0]=2;

retval=1;

while(ack[0]==2 || retval==0 || ack[2]==3)

{
cuo++;

		for(int sh=1;sh<=520;sh++)
		
			crcarray1[sh]=mod[sh];
		
	srand(time(0));

	int rnd=(rand()%3)+1; 		/*rnd=1-->ack
	
					  rnd=2-->nack
					  
					  rnd=3-->frame_drop*/
	/*if(cuo==1)
	rnd=2;
	else
	rnd=1;
	*/
	//rnd=1;
	cout<<"rnd"<<rnd<<endl;
	
	
	if(rnd==2)

	{

		int p;	

		//10 bits error

		for(int i=1; i<=10; i++)

	    	{ 

	    	   	 p = (rand()%520)+1;     	     
    	  	
    	  	
			crcarray1[p]=1-crcarray1[p];//fliping the bits
			
		}
	
	}
	
	if(rnd==3)
	
		frame_drop++;
	
	crcarray1[521]=rnd;

int te=send(client_fd[0],crcarray1, sizeof(crcarray1),0);
 		 	  
 		 	  cout<<"send"<<te<<"bytes"<<endl;
	struct timeval tv;

           FD_ZERO(&rfds);

           FD_SET(0, &rfds);

           tv.tv_sec = 5;

           tv.tv_usec = 0;

	 		 rfds=master;

 retval = select(client_fd[0]+1, &rfds, NULL, NULL, &tv);

if(FD_ISSET(client_fd[0],&rfds))
	
	{

		int retvala=0;

		retvala=recv(client_fd[0],ack,3*sizeof(int),0);
		
		cout<<"received"<<retvala<<endl;
		
		cout<<"ack"<<ack[0]<<ack[1]<<ack[2]<<endl;
	
		if(ack[2]==2)
		
			dealy_ack_nack++;
	
		if(ack[2]==3)

		{
				
			cout<<"ack or nack drop\n";

			drop_ack_nack++;
			
		}	

		else if(ack[2]!=3)

		{

			crcarray1[522]=ack[1];

			mod[522]=ack[1];

        		   if (retvala)

				{

              				printf("Data is available now.\n");

					if(ack[0]==2)
					{
						cout<<"nack\n";
						nack++;
					}	
					else 
					{
						ccc++;
						
						cout<<ccc<<"frame sent successfully\n";
						
					}		
				}		

         	}
         			
     }		
      
if(retval==0)
			
	{
	
			count11++;
		
			cout<<"time is out\n";	
	
			cout<<"count"<<count11<<endl;
			
							
	}
	
}

}	  	

	cout<<"no.of nacks"<<nack<<endl;

	cout<<"no.of frame drops"<<frame_drop<<endl;

	cout<<"no.of delayed acks or nacks"<<dealy_ack_nack<<endl;
	
	cout<<"no.of ack or nack drops"<<drop_ack_nack<<endl;

  	cout<<"no.of frames send successfully"<<ccc<<endl;

 	close(client_fd[0]); 	
 	
  	close(sockfd);

  	return 0;
}
