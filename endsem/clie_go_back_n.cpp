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
	int crcarray4[1000];
	int crcarrayReceived1[1000];
	int crcarray6[1000];
	int crcarrayReceived2[1000];
	int reff[100],ref_a[100];
	ack[1]=0;

	int frame_drop1=0,frame_drop2=0,frame_drop3=0,nack=0,drop_ack_nack=0,delay_ack_nack=0;
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
	
	te=recv(sockfd,(int *)crcarrayReceived, sizeof(crcarrayReceived), 0);
	cout<<"recv"<<te<<"bytes"<<endl;
	int p;
	for (int i = 1 ; i <=522 ; ++i) 
		crcarray2[i]=crcarrayReceived[i];
	cout<<"ack or nack"<<crcarray2[521]<<"recv crc_sq"<<crcarray2[522]<<endl;
	te=recv(sockfd,(int *)crcarrayReceived1, sizeof(crcarrayReceived), 0);
		cout<<"recv2"<<te<<"bytes"<<endl;
		for (int i = 1 ; i <=522 ; ++i) 
			crcarray4[i]=crcarrayReceived1[i];
		cout<<"ack or nack2"<<crcarray4[521]<<"recv crc_sq"<<crcarray4[522]<<endl;
	te=recv(sockfd,(int *)crcarrayReceived2, sizeof(crcarrayReceived), 0);
		cout<<"recv3"<<te<<"bytes"<<endl;
		for (int i = 1 ; i <=522 ; ++i) 
			crcarray6[i]=crcarrayReceived2[i];
		cout<<"ack or nack3"<<crcarray6[521]<<"recv crc_sq"<<crcarray6[522]<<endl;
	//crc check
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
else if(crcarray2[521]==3)
{
	cout<<"frame 1 droped";
//	frame_drop1;
}
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
else if(crcarray4[521]==3)
{
	cout<<"frame 2 droped";
//	frame_drop2++;
}	
}

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
else if(crcarray6[521]==3)
{
		cout<<"frame 3 droped\n";
		//frame_drop3++;
}
}
/*if((crcarray2[521]!=3 && crcarray4[521]!=3 && crcarray6[521]!=3) || ref_a[0]==2 || ref_a[1]==2 || ref_a[2]==2)
{
	srand(time(0));
	rnd=rand()%3+1;			/*if rnd=1 then it represents ack or nack
					  if rnd=2 then it represents dack or dnack
					  if rnd=3 then it represents ack_drop or nack_drop	
	cout<<"rnd"<<rnd<<endl;
	//rnd=2;
		if(ref_a[0]==1 && ref_a[1]==1 && ref_a[2]==1)
			{
				ack[0]=1;
				ack[1]=(crcarray6[522]+1)%5;
			}
		else if(ref_a[0]==2)
			{
				ack[0]=2;
				ack[1]=crcarray2[522];
			}
		else if(ref_a[1]==2)
			{
				ack[0]=2;
				ack[1]=crcarray4[522];
			}
		else if(ref_a[0]==2 )
			{
				ack[0]=2;
				ack[1]=crcarray4[522];
			}
		else if(ack[0]==2)
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
	else if(rnd==3)
	//frame drop
	{
		cout<<"ack"<<ack[0]<<ack[1]<<ack[2]<<endl;
		int tt=send(sockfd,ack,3*sizeof(int),0);
		cout<<"sent3"<<tt<<"bytes"<<endl;	
	}
}*/
	if(crcarray2[521]==3)
		frame_drop1++;
	if(crcarray4[521]==3)
		frame_drop2++;
	if(crcarray6[521]==3)
		frame_drop3++;
if(crcarray2[521]!=3 && crcarray4[521]!=3 && crcarray6[521]!=3)
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
}
}
}

cout<<"no.of nacks"<<nack<<endl;
cout<<"no.of frame_drops"<<frame_drop1+frame_drop2+frame_drop3<<endl;
cout<<"no.of dealyed acks or nacks"<<delay_ack_nack<<endl;
cout<<"no.of ack or nack drops"<<drop_ack_nack<<endl;
cout<<"no.of successful frames"<<count_frames<<endl;	
  	close(sockfd);
  	return 0;
}
