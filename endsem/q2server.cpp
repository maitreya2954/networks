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
	usleep(5000010);
	send(sockfd,ack,3*sizeof(int),0);
	cout<<"sended";
	pthread_exit(0);
}
int c=0,ref=0;
pthread_t tid[1000];
int count_frames=0;
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
	
	int crcarray2[1000] ;
	int crcarrayReceived[1000] ;
	int crcarray4[1000];
	int crcarrayReceived1[1000];
	int crcarray6[1000];
	int crcarrayReceived2[1000];
	int crcarrayReceived3[1000];
	int crcarrayReceived4[1000];
	int crcarrayReceived5[1000];
	int crcarrayReceived6[1000];
	int crcarrayReceived7[1000];
	int crcarrayReceived8[1000];
	int crcarrayReceived9[1000];
	int reff[100],ref_a[100];
	int crcarray8[1000];
	int crcarray10[1000];
	int crcarray12[1000];
	int crcarray14[1000];
	int crcarray16[1000];
	int crcarray18[1000];
	int crcarray20[1000];
	
	
	
	
	ack[1]=0;

	int frame_drop1=0,frame_drop2=0,frame_drop3=0,frame_drop4=0,frame_drop5=0,frame_drop6=0,frame_drop7=0,frame_drop8=0,frame_drop9=0,frame_drop10=0,nack=0,drop_ack_nack=0,delay_ack_nack=0;
int s=0;

//while(s!=10)	 	
{    	
//cout<<s<<endl;	
ack[0]=2;
	ref_a[0]=3;
	ref_a[1]=3;
	ref_a[2]=3;
int te=1;
while(te>0)
{
ref_a[0]=3;
	ref_a[1]=3;
	ref_a[2]=3;

//cuo++;
	
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
	int sum; 	
cout<<endl;


	te=recv(sockfd,(int *)crcarrayReceived, sizeof(crcarrayReceived), 0);
	cout<<"recv"<<te<<"bytes"<<endl;
	int p;
	for (int i = 1 ; i <=522 ; ++i) 
		crcarray2[i]=crcarrayReceived[i];
	cout<<"ack or nack"<<crcarray2[521]<<"recv crc_sq"<<crcarray2[522]<<endl;
	
	


if(crcarray2[522]==ack[1])
{
if(crcarray2[521]!=3 && crcarray2[522]==ack[1])
{
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
	//cout<<"check crc1"<<endl;		
	int f=0,r[8];
	for(int h=1;h<=520;h++)
	{
		if(crcarray2[h]==1)
			f++;
	}		
	//ack[1]=crcarray2[522];	
	if(f==0)
	{
		ref_a[0]=1;		//ack
		cout<<"no error:"<<crcarray2[522]<<endl;
		count_frames++;
	}
	else
	{
		ref_a[0]=2;		//nack
		reff[0]=crcarray2[522];
		cout<<"there is an error:"<<crcarray2[522]<<endl;
	}
}
}
else if(crcarray2[521]==3)
{
	cout<<"frame 1 droped";
//	frame_drop1;
}
if(crcarray2[521]==3)
		frame_drop1++;
int client_fd[100];		
te=send(client_fd[0],crcarray2, sizeof(crcarray2),0);
 		 	  cout<<"send "<<te<<"bytes:"<<crcarray2[522]<<endl;		

	te=recv(sockfd,(int *)crcarrayReceived1, sizeof(crcarrayReceived), 0);
		cout<<"recv2"<<te<<"bytes"<<endl;
		for (int i = 1 ; i <=522 ; ++i) 
			crcarray4[i]=crcarrayReceived1[i];
			cout<<"ack or nack2"<<crcarray4[521]<<"recv crc_sq"<<crcarray4[522]<<endl;


if(ref_a[0]==1)
{
if(crcarray4[521]!=3 && crcarray4[522]==((ack[1]+1)%5))
{
//crc check for 2nd frame	
	 			sum=0;
				for(int e=1;e<=512;e++)	
					sum=sum+crcarray4[e];
	while(sum>0)	
	{	
		int q=1,k=1,ctr=1,clt=1;
		for(int j=1;j<=520;j++)	
		{	
			if(crcarray4[j]==1 && k==1)
			{	k++;
				  int p;
		 		int y=1;
				for ( int p = j; p < j+9; p++ )
		 		{
		 		    C[y]=single(crcarray4[p],B[y]);
		 		    y++;  
		 		}	
				y=1;
				for(int d=0;d<9;d++)
					crcarray4[d+clt]=C[d+1]; //updating 
				 sum=0;
				for(int e=1;e<=512;e++)	
					sum=sum+crcarray4[e];
			}
			clt++;
		}
	}
	//cout<<"check crc2"<<endl;		
	int f=0;
	for(int h=1;h<=520;h++)
	{
		if(crcarray4[h]==1)
			f++;
	}		
	//ack[1]=crcarray4[522];	
	if(f==0)
	{
		ref_a[1]=1;		//ack
		cout<<"no error:"<<crcarray4[522]<<endl;
		count_frames++;
	}
	else
	{
		ref_a[1]=2;		//nack
		reff[1]=crcarray4[522];
		cout<<"there is an error"<<crcarray4[522]<<endl;
	}
}
}
else if(crcarray4[521]==3)
{
	cout<<"frame 2 droped";
//	frame_drop2++;
}	

if(crcarray4[521]==3)
		frame_drop2++;

te=send(client_fd[0],crcarray4, sizeof(crcarray4),0);
 		 	  cout<<"send "<<te<<"bytes:"<<crcarray4[522]<<endl;

	te=recv(sockfd,(int *)crcarrayReceived2, sizeof(crcarrayReceived), 0);
		cout<<"recv3"<<te<<"bytes"<<endl;
			for (int i = 1 ; i <=522 ; ++i) 
			crcarray6[i]=crcarrayReceived2[i];
		cout<<"ack or nack3"<<crcarray6[521]<<"recv crc_sq"<<crcarray6[522]<<endl;
		
		
	if(ref_a[1]==1)
{	
if(crcarray6[521]!=3 && crcarray6[522]==((ack[1]+2)%5))
{
//crc check for 3rd frame	
	 			sum=0;
				for(int e=1;e<=512;e++)	
					sum=sum+crcarray6[e];
	while(sum>0)	
	{	
		int q=1,k=1,ctr=1,clt=1;
		for(int j=1;j<=520;j++)	
		{	
			if(crcarray6[j]==1 && k==1)
			{	k++;
				  int p;
		 		int y=1;
				for ( int p = j; p < j+9; p++ )
		 		{
		 		    C[y]=single(crcarray6[p],B[y]);
		 		    y++;  
		 		}	
				y=1;
				for(int d=0;d<9;d++)
					crcarray6[d+clt]=C[d+1]; //updating 
				 sum=0;
				for(int e=1;e<=512;e++)	
					sum=sum+crcarray6[e];
			}
			clt++;
		}
	}
	//cout<<"check crc"<<endl;		
	int f=0;
	for(int h=1;h<=520;h++)
	{
		if(crcarray6[h]==1)
			f++;
	}		
	//ack[1]=crcarray2[522];	
	if(f==0)
	{
		ref_a[2]=1;		//ack
		cout<<"no error:"<<crcarray6[522]<<endl;
		count_frames++;
	}
	else
	{
		ref_a[2]=2;		//nack
		reff[2]=crcarray6[522];
		cout<<"there is an error"<<crcarray6[522]<<endl;
	}
}
}
else if(crcarray6[521]==3)
{
		cout<<"frame 3 droped\n";
		//frame_drop3++;
}


	
	
	if(crcarray6[521]==3)
		frame_drop3++;	
		te=send(client_fd[0],crcarray6, sizeof(crcarray6),0);
 		 	  cout<<"send "<<te<<"bytes:"<<crcarray6[522]<<endl;
		
		te=recv(sockfd,(int *)crcarrayReceived3, sizeof(crcarrayReceived3), 0);
	cout<<"recv"<<te<<"bytes"<<endl;
	
	for (int i = 1 ; i <=522 ; ++i) 
		crcarray6[i]=crcarrayReceived3[i];
	cout<<"ack or nack"<<crcarray6[521]<<"recv crc_sq"<<crcarray8[522]<<endl;
	
	te=send(client_fd[0],crcarray6, sizeof(crcarray6),0);
 		 	  cout<<"send "<<te<<"bytes:"<<crcarray6[522]<<endl;
	
	if(ref_a[1]==1)
{	
if(crcarray8[521]!=3 && crcarray8[522]==((ack[1]+2)%5))
{
//crc check for 4th frame	
	 			sum=0;
				for(int e=1;e<=512;e++)	
					sum=sum+crcarray8[e];
	while(sum>0)	
	{	
		int q=1,k=1,ctr=1,clt=1;
		for(int j=1;j<=520;j++)	
		{	
			if(crcarray8[j]==1 && k==1)
			{	k++;
				  int p;
		 		int y=1;
				for ( int p = j; p < j+9; p++ )
		 		{
		 		    C[y]=single(crcarray8[p],B[y]);
		 		    y++;  
		 		}	
				y=1;
				for(int d=0;d<9;d++)
					crcarray8[d+clt]=C[d+1]; //updating 
				 sum=0;
				for(int e=1;e<=512;e++)	
					sum=sum+crcarray8[e];
			}
			clt++;
		}
	}
	//cout<<"check crc"<<endl;		
	int f=0;
	for(int h=1;h<=520;h++)
	{
		if(crcarray8[h]==1)
			f++;
	}		
	//ack[1]=crcarray2[522];	
	if(f==0)
	{
		ref_a[2]=1;		//ack
		cout<<"no error:"<<crcarray8[522]<<endl;
		count_frames++;
	}
	else
	{
		ref_a[2]=2;		//nack
		reff[2]=crcarray8[522];
		cout<<"there is an error"<<crcarray8[522]<<endl;
	}
}
}
else if(crcarray8[521]==4)
{
		cout<<"frame 4 droped\n";
		//frame_drop3++;
}


	
	
	if(crcarray8[521]==4)
		frame_drop4++;	
		
te=send(client_fd[0],crcarray8, sizeof(crcarray8),0);
 		 	  cout<<"send "<<te<<"bytes:"<<crcarray8[522]<<endl;


	te=recv(sockfd,(int *)crcarrayReceived4, sizeof(crcarrayReceived4), 0);
		cout<<"recv2"<<te<<"bytes"<<endl;
		for (int i = 1 ; i <=522 ; ++i) 
			crcarray10[i]=crcarrayReceived4[i];
			cout<<"ack or nack2"<<crcarray10[521]<<"recv crc_sq"<<crcarray10[522]<<endl;



	
	if(ref_a[1]==1)
{	
if(crcarray10[521]!=3 && crcarray10[522]==((ack[1]+2)%5))
{
//crc check for 5th frame	
	 			sum=0;
				for(int e=1;e<=512;e++)	
					sum=sum+crcarray10[e];
	while(sum>0)	
	{	
		int q=1,k=1,ctr=1,clt=1;
		for(int j=1;j<=520;j++)	
		{	
			if(crcarray10[j]==1 && k==1)
			{	k++;
				  int p;
		 		int y=1;
				for ( int p = j; p < j+9; p++ )
		 		{
		 		    C[y]=single(crcarray10[p],B[y]);
		 		    y++;  
		 		}	
				y=1;
				for(int d=0;d<9;d++)
					crcarray10[d+clt]=C[d+1]; //updating 
				 sum=0;
				for(int e=1;e<=512;e++)	
					sum=sum+crcarray10[e];
			}
			clt++;
		}
	}
	//cout<<"check crc"<<endl;		
	int f=0;
	for(int h=1;h<=520;h++)
	{
		if(crcarray10[h]==1)
			f++;
	}		
	//ack[1]=crcarray2[522];	
	if(f==0)
	{
		ref_a[2]=1;		//ack
		cout<<"no error:"<<crcarray10[522]<<endl;
		count_frames++;
	}
	else
	{
		ref_a[2]=2;		//nack
		reff[2]=crcarray10[522];
		cout<<"there is an error"<<crcarray10[522]<<endl;
	}
}
}
else if(crcarray10[521]==5)
{
		cout<<"frame 5 droped\n";
	
}

	
	
	if(crcarray10[521]==5)
		frame_drop5++;	

te=send(client_fd[0],crcarray10, sizeof(crcarray10),0);
 		 	  cout<<"send "<<te<<"bytes:"<<crcarray10[522]<<endl;

	te=recv(sockfd,(int *)crcarrayReceived5, sizeof(crcarrayReceived5), 0);
		cout<<"recv3"<<te<<"bytes"<<endl;
			for (int i = 1 ; i <=522 ; ++i) 
			crcarray12[i]=crcarrayReceived5[i];
		cout<<"ack or nack3"<<crcarray12[521]<<"recv crc_sq"<<crcarray12[522]<<endl;

	if(ref_a[1]==1)
{	
if(crcarray12[521]!=3 && crcarray12[522]==((ack[1]+2)%5))
{
//crc check for 6th frame	
	 			sum=0;
				for(int e=1;e<=512;e++)	
					sum=sum+crcarray12[e];
	while(sum>0)	
	{	
		int q=1,k=1,ctr=1,clt=1;
		for(int j=1;j<=520;j++)	
		{	
			if(crcarray12[j]==1 && k==1)
			{	k++;
				  int p;
		 		int y=1;
				for ( int p = j; p < j+9; p++ )
		 		{
		 		    C[y]=single(crcarray12[p],B[y]);
		 		    y++;  
		 		}	
				y=1;
				for(int d=0;d<9;d++)
					crcarray12[d+clt]=C[d+1]; //updating 
				 sum=0;
				for(int e=1;e<=512;e++)	
					sum=sum+crcarray12[e];
			}
			clt++;
		}
	}
	//cout<<"check crc"<<endl;		
	int f=0;
	for(int h=1;h<=520;h++)
	{
		if(crcarray12[h]==1)
			f++;
	}		
	//ack[1]=crcarray2[522];	
	if(f==0)
	{
		ref_a[2]=1;		//ack
		cout<<"no error:"<<crcarray12[522]<<endl;
		count_frames++;
	}
	else
	{
		ref_a[2]=2;		//nack
		reff[2]=crcarray12[522];
		cout<<"there is an error"<<crcarray12[522]<<endl;

	}	
}
}
else if(crcarray12[521]==6)
{
		cout<<"frame 6 droped\n";
	
}

	
	
	if(crcarray12[521]==6)
		frame_drop6++;	


		
		
		te=recv(sockfd,(int *)crcarrayReceived6, sizeof(crcarrayReceived6), 0);
	cout<<"recv"<<te<<"bytes"<<endl;

	for (int i = 1 ; i <=522 ; ++i) 
		crcarray12[i]=crcarrayReceived6[i];
	cout<<"ack or nack"<<crcarray14[521]<<"recv crc_sq"<<crcarray14[522]<<endl;
	
	te=send(client_fd[0],crcarray12, sizeof(crcarray12),0);
 		 	  cout<<"send "<<te<<"bytes:"<<crcarray12[522]<<endl;
	
		if(ref_a[1]==1)
{	
if(crcarray14[521]!=3 && crcarray14[522]==((ack[1]+2)%5))
{
//crc check for 7th frame	
	 			sum=0;
				for(int e=1;e<=512;e++)	
					sum=sum+crcarray14[e];
	while(sum>0)	
	{	
		int q=1,k=1,ctr=1,clt=1;
		for(int j=1;j<=520;j++)	
		{	
			if(crcarray14[j]==1 && k==1)
			{	k++;
				  int p;
		 		int y=1;
				for ( int p = j; p < j+9; p++ )
		 		{
		 		    C[y]=single(crcarray14[p],B[y]);
		 		    y++;  
		 		}	
				y=1;
				for(int d=0;d<9;d++)
					crcarray14[d+clt]=C[d+1]; //updating 
				 sum=0;
				for(int e=1;e<=512;e++)	
					sum=sum+crcarray14[e];
			}
			clt++;
		}
	}
	//cout<<"check crc"<<endl;		
	int f=0;
	for(int h=1;h<=520;h++)
	{
		if(crcarray14[h]==1)
			f++;
	}		
	//ack[1]=crcarray2[522];	
	if(f==0)
	{
		ref_a[2]=1;		//ack
		cout<<"no error:"<<crcarray14[522]<<endl;
		count_frames++;
	}
	else
	{
		ref_a[2]=2;		//nack
		reff[2]=crcarray14[522];
		cout<<"there is an error"<<crcarray14[522]<<endl;
	}
}
}
else if(crcarray14[521]==7)
{
		cout<<"frame 7 droped\n";
	
}

	
	
	if(crcarray14[521]==7)
		frame_drop7++;	

te=send(client_fd[0],crcarray14, sizeof(crcarray14),0);
 		 	  cout<<"send "<<te<<"bytes:"<<crcarray14[522]<<endl;


	te=recv(sockfd,(int *)crcarrayReceived7, sizeof(crcarrayReceived7), 0);
		cout<<"recv2"<<te<<"bytes"<<endl;
		for (int i = 1 ; i <=522 ; ++i) 
			crcarray16[i]=crcarrayReceived7[i];
			cout<<"ack or nack2"<<crcarray16[521]<<"recv crc_sq"<<crcarray16[522]<<endl;

if(ref_a[1]==1)
{	
if(crcarray16[521]!=3 && crcarray16[522]==((ack[1]+2)%5))
{
//crc check for 8th frame	
	 			sum=0;
				for(int e=1;e<=512;e++)	
					sum=sum+crcarray16[e];
	while(sum>0)	
	{	
		int q=1,k=1,ctr=1,clt=1;
		for(int j=1;j<=520;j++)	
		{	
			if(crcarray16[j]==1 && k==1)
			{	k++;
				  int p;
		 		int y=1;
				for ( int p = j; p < j+9; p++ )
		 		{
		 		    C[y]=single(crcarray16[p],B[y]);
		 		    y++;  
		 		}	
				y=1;
				for(int d=0;d<9;d++)
					crcarray16[d+clt]=C[d+1]; //updating 
				 sum=0;
				for(int e=1;e<=512;e++)	
					sum=sum+crcarray16[e];
			}
			clt++;
		}
	}
	//cout<<"check crc"<<endl;		
	int f=0;
	for(int h=1;h<=520;h++)
	{
		if(crcarray16[h]==1)
			f++;
	}		
	//ack[1]=crcarray2[522];	
	if(f==0)
	{
		ref_a[2]=1;		//ack
		cout<<"no error:"<<crcarray16[522]<<endl;
		count_frames++;
	}
	else
	{
		ref_a[2]=2;		//nack
		reff[2]=crcarray16[522];
		cout<<"there is an error"<<crcarray16[522]<<endl;
	}

}
}
else if(crcarray16[521]==8)
{
		cout<<"frame 8 droped\n";
	
}

	
	
	if(crcarray14[521]==8)
		frame_drop8++;	




te=recv(sockfd,(int *)crcarrayReceived8, sizeof(crcarrayReceived8), 0);
		cout<<"recv3"<<te<<"bytes"<<endl;
			for (int i = 1 ; i <=522 ; ++i) 
			crcarray18[i]=crcarrayReceived8[i];
		cout<<"ack or nack3"<<crcarray12[521]<<"recv crc_sq"<<crcarray18[522]<<endl;
te=send(client_fd[0],crcarray16, sizeof(crcarray16),0);
 		 	  cout<<"send "<<te<<"bytes:"<<crcarray16[522]<<endl;

if(ref_a[1]==1)
{	
if(crcarray18[521]!=3 && crcarray18[522]==((ack[1]+2)%5))
{
//crc check for 9th frame	
	 			sum=0;
				for(int e=1;e<=512;e++)	
					sum=sum+crcarray18[e];
	while(sum>0)	
	{	
		int q=1,k=1,ctr=1,clt=1;
		for(int j=1;j<=520;j++)	
		{	
			if(crcarray18[j]==1 && k==1)
			{	k++;
				  int p;
		 		int y=1;
				for ( int p = j; p < j+9; p++ )
		 		{
		 		    C[y]=single(crcarray18[p],B[y]);
		 		    y++;  
		 		}	
				y=1;
				for(int d=0;d<9;d++)
					crcarray18[d+clt]=C[d+1]; //updating 
				 sum=0;
				for(int e=1;e<=512;e++)	
					sum=sum+crcarray18[e];
			}
			clt++;
		}
	}
	//cout<<"check crc"<<endl;		
	int f=0;
	for(int h=1;h<=520;h++)
	{
		if(crcarray18[h]==1)
			f++;
	}		
	//ack[1]=crcarray2[522];	
	if(f==0)
	{
		ref_a[2]=1;		//ack
		cout<<"no error:"<<crcarray18[522]<<endl;
		count_frames++;
	}
	else
	{
		ref_a[2]=2;		//nack
		reff[2]=crcarray18[522];
		cout<<"there is an error"<<crcarray18[522]<<endl;
	}
}
}
else if(crcarray18[521]==9)
{
		cout<<"frame 9 droped\n";
	
}

	
	
	if(crcarray18[521]==9)
		frame_drop9++;	



te=recv(sockfd,(int *)crcarrayReceived9, sizeof(crcarrayReceived9), 0);
		cout<<"recv3"<<te<<"bytes"<<endl;
			for (int i = 1 ; i <=522 ; ++i) 
			crcarray20[i]=crcarrayReceived9[i];
		cout<<"ack or nack3"<<crcarray20[521]<<"recv crc_sq"<<crcarray20[522]<<endl;


te=send(client_fd[0],crcarray18, sizeof(crcarray18),0);
 		 	  cout<<"send "<<te<<"bytes:"<<crcarray18[522]<<endl;


if(ref_a[1]==1)
{	
if(crcarray20[521]!=3 && crcarray20[522]==((ack[1]+2)%5))
{
//crc check for 10th frame	
	 			sum=0;
				for(int e=1;e<=512;e++)	
					sum=sum+crcarray20[e];
	while(sum>0)	
	{	
		int q=1,k=1,ctr=1,clt=1;
		for(int j=1;j<=520;j++)	
		{	
			if(crcarray20[j]==1 && k==1)
			{	k++;
				  int p;
		 		int y=1;
				for ( int p = j; p < j+9; p++ )
		 		{
		 		    C[y]=single(crcarray20[p],B[y]);
		 		    y++;  
		 		}	
				y=1;
				for(int d=0;d<9;d++)
					crcarray20[d+clt]=C[d+1]; //updating 
				 sum=0;
				for(int e=1;e<=512;e++)	
					sum=sum+crcarray20[e];
			}
			clt++;
		}
	}
	//cout<<"check crc"<<endl;		
	int f=0;
	for(int h=1;h<=520;h++)
	{
		if(crcarray20[h]==1)
			f++;
	}		
	//ack[1]=crcarray2[522];	
	if(f==0)
	{
		ref_a[2]=1;		//ack
		cout<<"no error:"<<crcarray20[522]<<endl;
		count_frames++;
	}
	else
	{
		ref_a[2]=2;		//nack
		reff[2]=crcarray20[522];
		cout<<"there is an error"<<crcarray20[522]<<endl;
	}
}
}
else if(crcarray20[521]==10)
{
		cout<<"frame 10 droped\n";
	
}

	
	
	if(crcarray20[521]==10)
		frame_drop10++;	

te=send(client_fd[0],crcarray20, sizeof(crcarray20),0);
 		 	  cout<<"send "<<te<<"bytes:"<<crcarray20[522]<<endl;







if(crcarray2[521]!=3 && crcarray4[521]!=3 && crcarray6[521]!=3 && crcarray8[521]!=3 && crcarray10[521]!=3 && crcarray12[521]!=3 && crcarray14[521]!=3 && crcarray16[521]!=3 && crcarray18[521]!=3 && crcarray20[521]!=3)
{

cout<<"d"<<endl;
cout<<ref_a[0]<<ref_a[1]<<ref_a[2]<<endl;
	srand(time(0));
	rnd=rand()%2+1;			/*if rnd=1 then it represents ack or nack
					  if rnd=2 then it represents dack or dnack
					  if rnd=3 then it represents ack_drop or nack_drop*/	
	//rnd=3;
	cout<<"rnd"<<rnd<<endl;

		if(ref_a[0]==1 && ref_a[1]==1 && ref_a[2]==1)
			{
			cout<<"d0"<<endl;
				ack[0]=1;
				ack[1]=(crcarray6[522]+1)%5;
			}
		else if(ref_a[0]==2)
			{
			cout<<"da"<<endl;
				ack[0]=2;
				ack[1]=crcarray2[522];
			}
		else if(ref_a[1]==2)
			{
			cout<<"db"<<endl;
				ack[0]=2;
				ack[1]=crcarray4[522];
			}
		else if(ref_a[2]==2 )
			{
			cout<<"dc"<<endl;
				ack[0]=2;
				ack[1]=crcarray6[522];
			}
		
		if(ack[0]==2)
			nack++;
			if(rnd==3)
				drop_ack_nack++;
			if(rnd==2)
				delay_ack_nack++;
	ack[2]=rnd;
	if(rnd==1)
	//successful ack and nack
	{
		cout<<"ack"<<ack[0]<<ack[1]<<ack[2]<<endl;
		int tt=send(sockfd,ack,3*sizeof(int),0);
		cout<<"sent1"<<tt<<"bytes"<<endl;
	}
	else if(rnd==2)
	//delayed nack and ack
	{
		//c++;
		pthread_create(&tid[0],NULL,delay,NULL);
		pthread_join(tid[0],NULL);
	}
	/*else if(rnd==3)
	//frame drop
	{
		cout<<"ack"<<ack[0]<<ack[1]<<ack[2]<<endl;
		int tt=send(sockfd,ack,3*sizeof(int),0);
		cout<<"sent3"<<tt<<"bytes"<<endl;	
	}*/
}	
		
			
else if(crcarray2[521]==3 || ref_a[0]==2)
{
cout<<"a"<<endl;
	srand(time(0));
	rnd=rand()%2+1;			/*if rnd=1 then it represents ack or nack
					  if rnd=2 then it represents dack or dnack
					  if rnd=3 then it represents ack_drop or nack_drop	*/
	cout<<"rnd"<<rnd<<endl;
	//rnd=2;
			ack[0]=2;
			ack[1]=crcarray2[522];
		
		if(ack[0]==2)
			nack++;
			if(rnd==3)
				drop_ack_nack++;
			if(rnd==2)
				delay_ack_nack++;
	ack[2]=rnd;
	if(rnd==1)
	//successful ack and nack
	{
		cout<<"ack"<<ack[0]<<ack[1]<<ack[2]<<endl;
		int tt=send(sockfd,ack,3*sizeof(int),0);
		cout<<"sent1"<<tt<<"bytes"<<endl;
	}
	else if(rnd==2)
	//delayed nack and ack
	{
		//c++;
		pthread_create(&tid[0],NULL,delay,NULL);
		pthread_join(tid[0],NULL);
	}
	/*else if(rnd==3)
	//frame drop
	{
		cout<<"ack"<<ack[0]<<ack[1]<<ack[2]<<endl;
		int tt=send(sockfd,ack,3*sizeof(int),0);
		cout<<"sent3"<<tt<<"bytes"<<endl;	
	}*/
}

else if(crcarray4[521]==3 || ref_a[1]==2)
{
cout<<"b"<<endl;
	srand(time(0));
	rnd=rand()%2+1;			/*if rnd=1 then it represents ack or nack
					  if rnd=2 then it represents dack or dnack
					  if rnd=3 then it represents ack_drop or nack_drop	*/
	cout<<"rnd"<<rnd<<endl;
	//rnd=2;
		
		if(ref_a[0]==2)
			{
				ack[0]=2;
				ack[1]=crcarray2[522];
			}
		else
			{
				ack[0]=2;
				ack[1]=crcarray4[522];
			}
			
		if(ack[0]==2)
			nack++;
			if(rnd==3)
				drop_ack_nack++;
			if(rnd==2)
				delay_ack_nack++;
	ack[2]=rnd;
	if(rnd==1)
	//successful ack and nack
	{
		cout<<"ack"<<ack[0]<<ack[1]<<ack[2]<<endl;
		int tt=send(sockfd,ack,3*sizeof(int),0);
		cout<<"sent1"<<tt<<"bytes"<<endl;
	}
	else if(rnd==2)
	//delayed nack and ack
	{
		//c++;
		pthread_create(&tid[0],NULL,delay,NULL);
		pthread_join(tid[0],NULL);
	}
	/*else if(rnd==3)
	//frame drop
	{
		cout<<"ack"<<ack[0]<<ack[1]<<ack[2]<<endl;
		int tt=send(sockfd,ack,3*sizeof(int),0);
		cout<<"sent3"<<tt<<"bytes"<<endl;	
	}*/
}
else if(crcarray6[521]==3 || ref_a[2]==2)
{
cout<<"c"<<endl;
	srand(time(0));
	rnd=rand()%2+1;			/*if rnd=1 then it represents ack or nack
					  if rnd=2 then it represents dack or dnack
					  if rnd=3 then it represents ack_drop or nack_drop	*/
	cout<<"rnd"<<rnd<<endl;
	//rnd=2;
		
		if(ref_a[1]==2)
			{
				ack[0]=2;
				ack[1]=crcarray4[522];
			}
		else
			{
				ack[0]=2;
				ack[1]=crcarray6[522];
			}
			
		if(ack[0]==2)
			nack++;
			if(rnd==3)
				drop_ack_nack++;
			if(rnd==2)
				delay_ack_nack++;
	ack[2]=rnd;
	if(rnd==1)
	//successful ack and nack
	{
		cout<<"ack"<<ack[0]<<ack[1]<<ack[2]<<endl;
		int tt=send(sockfd,ack,3*sizeof(int),0);
		cout<<"sent1"<<tt<<"bytes"<<endl;
	}
	else if(rnd==2)
	//delayed nack and ack
	{
		//c++;
		pthread_create(&tid[0],NULL,delay,NULL);
		pthread_join(tid[0],NULL);
	}
	/*else if(rnd==3)
	//frame drop
	{
		cout<<"ack"<<ack[0]<<ack[1]<<ack[2]<<endl;
		int tt=send(sockfd,ack,3*sizeof(int),0);
		cout<<"sent3"<<tt<<"bytes"<<endl;	
	}*/

}

	cout<<"\n\n";
  	close(sockfd);
  	return 0;

}
