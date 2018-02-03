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






int main(int argc,char* argv[])
{
	if(argc != 3)
    {
    	cerr << "Usage syntax: ./client <ip_address> <port_no>" << endl;
      	return 0;
    }
  	int sockfd;
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
int s;
 
	
	int crcarray2[1000] ;
	int crcarrayReceived[1000] ;
	
for(s=1;s<=100;s++)	 	
{   	
	cout<<s<<endl;	
	
	int te=recv(sockfd,(int *)crcarrayReceived, sizeof(crcarrayReceived), 0);
	
	cout<<"recv:"<<te<<"bytes"<<"\n";
	
	int p;
	
		
	for (int i = 1 ; i <=524 ; ++i) 
	{
		crcarray2[i]=crcarrayReceived[i];
	  //  cout<<"array1["<<i<<"]="<<crcarray2[i]<<endl;
	    
	}
	
	
	//crc check
		
	int crcarraye[1000];
	int A[20],B[20],C[20];
		
	 
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
	 	

	cout<<endl;
	 // crc8 
	/*for(int i=1;i<=524;i++)
	{
		cout<<"crcarray2["<<i<<"]="<<crcarray2[i]<<"\n";
	}*/
				
				int sum;
	 			sum=0;
				for(int e=1;e<=524;e++)	
				{
					sum=sum+crcarray2[e];
				}
				cout<<"sum1="<<sum<<"\n";
	
	
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
		 		  	//cout<<"B["<<y<<"]="<<B[y]<<"\n";
		 		  	
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
				//cout<<"sum2="<<sum<<"\n";
				
		}
		
		clt++;
		//cout<<"im sum"<<j<<endl;
							
		
	}

}
	
	//cout<<"check crc"<<endl;		
	int f=0,r[8];
	for(int h=1;h<=524;h++)
	{
		if(crcarray2[h]==1)
		{
			f++;
		}
	}	
	//cout<<"crcarray2"<<"\n";
	/*for(int i=1;i<=524;i++)
	{
		//cout<<"crcarray2["<<i<<"]="<<crcarray2[i]<<"\n";
	}*/
	
	
	
	if(f==0)
	{
		cout<<"no error"<<endl;
	}
	else
	{
		cout<<"there is an error"<<endl;
	}
	int v;
	/*for(v=1;v<=524;v++)
	{
			
		 crcarray2[v]=0;
		 crcarrayReceived[v]=0;
	
	}*/
	
	
	cout<<endl;
}	
  	close(sockfd);
  	return 0;
 }	
