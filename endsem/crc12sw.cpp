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




int main(int argc,char* argv[])
{
	if(argc !=2)
	{
	    	cerr << "Usage syntax: ./server <port_no>" << endl;
	      	return 0;
	}
  	
  	int sockfd;
	int client_fd[100];
  	
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
		client_fd[0]=accept(sockfd,(struct sockaddr*)&client_addr, &client_size);

	cout << "Accepted incoming connection:" <<endl;
	
	
	int crcarray1[1000];
	int crcarray2[1000];
	int crcarraye[1000];
	int A[20],B[20],C[20];
	

	int s=1; 	
for( s=1;s<=100;s++)	 	
{    	
	cout<<s<<endl;	
	 
	 	
	 srand((unsigned)time(NULL)); 
	 
	 	 B[1]=1;
	 	 B[2]=1;
	 	 B[3]=0;
	 	 B[4]=0;
	 	 B[5]=0;
	 	 B[6]=0;
	 	 B[7]=0;
	 	 B[8]=0;
	 	 B[9]=0;
	 	 B[10]=1;
	 	 B[11]=1;
	 	 B[12]=0;
	 	 B[13]=1;
	 	
    	//generating 512 random integers
   	int i,k;
    	cout<<"random 512bit"<<endl;
  	
  	 
    	for(i=1; i<=512; i++)
    	{ 
    		
    	    		crcarray1[i] = (rand()%2);     	     
    	   		    	   		
    	   		crcarray2[i] = crcarray1[i]; //duplicate crcarray
    	   		// cout<<"crcarray2["<<i<<"]="<<crcarray2[i]<<endl;
    	   				
	}
	//appending 0's
	for(i=513;i<=524;i++)
	{
		crcarray1[i] = 0; 
		crcarray2[i] = crcarray1[i]; 
	}
	
	//cout<<endl;
	 // crc8 
	int sum;
	 sum=0;
				for(int e=1;e<=512;e++)	
				{
					sum=sum+crcarray1[e];
				}
//				cout<<"sum1="<<sum<<"\n";
	
	
while(sum>0)	
{	
	//cout<<"im in while"<<endl;
	
	
	int q=1,k=1,ctr=1,clt=1;
	
	for(int j=1;j<=524;j++)	
	{	
	
		
		
		if(crcarray2[j]==1 && k==1)
		{	k++;
			//cout<<"im in 1st for j="<<j<<"\n";
				  int p;
		 			
		 		//cout<<"result of xor"<<"\n";	
		 
		 		int y=1;
				for ( int p = j; p < j+13; p++ )
		 		{
		 
		 		  	//cout<<"crcarray2["<<p<<"]="<<crcarray2[p]<<"\t";
		 		  	//cout<<"B["<<y<<"]="<<B[y]<<"\t";
		 		  	
		 		    C[y]=single(crcarray2[p],B[y]);
		 		   //cout<<"C`["<<y<<"]="<<C[y]<<"\n";
		 		    y++;  
		 		}	
				//cout<<endl;
				y=1;
		
				for(int d=0;d<13;d++)
				{	
					//cout<<"C["<<d<<"]="<<C[d+1]<<"\t";
					//cout<<"crcarray2["<<d+clt<<"]="<<crcarray2[d+clt]<<"\t";
					crcarray2[d+clt]=C[d+1]; //updating 
					//cout<<"crcarray2`["<<d+clt<<"]="<<crcarray2[d+clt]<<"\n";
				}
				//j=0;		
				//cout<<endl;	
				
				 sum=0;
				for(int e=1;e<=512;e++)	
				{
					sum=sum+crcarray2[e];
				}
//					cout<<"sum2="<<sum<<"\n";
				
		}
		
		clt++;
		//cout<<"im sum"<<j<<endl;
							
		
	}

}
	
	//cout<<"reminder"<<endl;		
	int f=1,r[8];
	for(int h=513;h<=524;h++)
	{
		
			r[f]=crcarray2[h];
	//		cout<<"r["<<f<<"]="<<r[f]<<"\n";
			f++;
		
	}	
	
	//cout<<"apending"<<"\n";
	int w=1;
	for(int u=513;u<=524;u++)
	{
		crcarray1[u]=r[w];
		//cout<<"r["<<w<<"]="<<r[w]<<endl;
		w++;
	}
	
	
	//if u comment this error making code u will receive a no error message
	int p;	
	//10 bits error
	for(int t=1; t<=10; t++)
	//for(int t=1; t<=20; t++)
    	{ 
    	   	 p = (rand()%524)+1;     	     
    	  	
    	  	//cout <<"p="<<p<< endl;
		
	//	cout<<"crcarray1["<<p<<"]="<<crcarray1[p]<<endl;
		
		crcarray1[p]=1-crcarray1[p];//fliping the bits
		
	//	cout<<"crcarray1["<<p<<"]="<<crcarray1[p]<<endl;
	}
	

			
		
	int te=send(client_fd[0],(int *)crcarray1, sizeof(crcarray1),0);
 		 	  
 		 	//  cout<<"send:"<<te<<"bytes"<<endl;
  	  
  	  	
  	  	/*for(int v=1;v<=100;v++)
  	  	{
  	  		crcarray1[v] = 0;     	     
    	   		    	   		
    	   		crcarray2[v] = 0;
  	  		
  	  	}*/
  	  	
  	  	
//  cout<<endl;	  	
 	  	
 } 	  	
  	  	
 		close(client_fd[0]); 	
 	
  	close(sockfd);

  	return 0;
}
