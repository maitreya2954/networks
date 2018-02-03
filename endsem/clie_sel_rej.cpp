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
int cuu=0;
int sockfd,rnd,rnd4,ack[3];
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
	ack[0]=1;
	ack[2]=2;
crcarray2[522]=0;
crcarray4[522]=1;
crcarray6[522]=2;

	int frame_drop=0,nack=0,drop_ack_nack=0,delay_ack_nack=0;

int te=1;
	
//for(int s=1;s<=11;s++)	 	
while(te>0)
{    	

	//ack[0]=2;

	ref_a[0]=0;
	
	ref_a[1]=0;
	
	ref_a[2]=0;


//while((ack[0]==2 || rnd!=1) && te!=0)

//{

	//cout<<s<<endl;	

	//if(ref_a[0]==2)
		
	//{
			te=recv(sockfd,(int *)crcarrayReceived, sizeof(crcarrayReceived), 0);
	
		cout<<"recv1"<<te<<"bytes"<<endl;
		
				
		for (int i = 1 ; i <=522 ; ++i) 

			crcarray2[i]=crcarrayReceived[i];
	    
		cout<<"ack or nack1"<<crcarray2[521]<<"recv crc_sq"<<crcarray2[522]<<endl;

	//}
	if((ack[2]==2 && ack[0]==1) || ack[2]!=2)
	{
	
	//if(ack[1]==crcarray2[522] && crcarray4[522]==(ack[1]+1)%5)
	
	{
	
		te=recv(sockfd,(int *)crcarrayReceived1, sizeof(crcarrayReceived), 0);
	
		cout<<"recv2"<<te<<"bytes"<<endl;

		for (int i = 1 ; i <=522 ; ++i) 

			crcarray4[i]=crcarrayReceived1[i];
	    
		cout<<"ack or nack2"<<crcarray4[521]<<"recv crc_sq"<<crcarray4[522]<<endl;

	}

	//if(ack[1]==crcarray2[522] && crcarray4[522]==(ack[1]+1)%5 && crcarray6[522]==(ack[1]+2)%5)
	
	{
	
		te=recv(sockfd,(int *)crcarrayReceived2, sizeof(crcarrayReceived), 0);
	
		cout<<"recv3"<<te<<"bytes"<<endl;

		for (int i = 1 ; i <=522 ; ++i) 

			crcarray6[i]=crcarrayReceived2[i];
	    
		cout<<"ack or nack3"<<crcarray6[521]<<"recv crc_sq"<<crcarray6[522]<<endl;

	}	

	int p;
			
	//crc check


//if((crcarray2[521]!=3 && crcarray2[522]==ack[1])|| rnd==3)

//{

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
	 
//crc check for 1st frame	

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
	
	cout<<"check crc1"<<endl;		

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
	
		cout<<"no error"<<endl;
		
		count_frames++;

	}

	else

	{

		ref_a[0]=2;		//nack

		reff[0]=crcarray2[522];

		cout<<"there is an error"<<endl;

	}

}

else if(crcarray2[521]==3)
{
	cout<<"frame 1 droped";
	frame_drop++;
	ref_a[0]=2;
}	

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
	
	cout<<"check crc2"<<endl;		

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
	
		cout<<"no error"<<endl;
		
		count_frames++;

	}

	else

	{

		ref_a[1]=2;		//nack

		reff[1]=crcarray4[522];

		cout<<"there is an error"<<endl;

	}

}

else if(crcarray4[521]==3)
{
	cout<<"frame 2 droped";
	frame_drop++;
	ref_a[1]=2;
}
	
if(crcarray6[521]!=3 && crcarray6[522]==((ack[1]+2)%5))

{

if(ref_a[0]==1)

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
	
	cout<<"check crc"<<endl;		

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
	
		cout<<"no error"<<endl;
		
		count_frames++;

	}

	else

	{

		ref_a[2]=2;		//nack

		reff[2]=crcarray6[522];

		cout<<"there is an error"<<endl;

	}
	
}

}

else if(crcarray6[521]==3)

{

		cout<<"frame 3 droped\n";
		ref_a[2]=2;
		frame_drop++;
}
}
if((ref_a[0]==1 && ref_a[1]==1 && ref_a[2]==1)||rnd==3)
	
{
		
	ack[0]=1;
	
	ack[1]=(crcarray6[522]+1)%5;
	
	srand(time(0));

	rnd=rand()%3+1;			/*if rnd=1 then it represents ack or nack
	
					  if rnd=2 then it represents dack or dnack
					  
					  if rnd=3 then it represents ack_drop or nack_drop*/	
cuu++;
	/*if(cuu==1 || cuu==4)
	rnd=2;	
	else
	rnd=1;*/
	cout<<"rnd"<<rnd<<endl;
	
		if(rnd==3)
			count_frames+=3;
		
		if(ack[0]==2)
		
			nack++;
			
			if(rnd==3)
			
				drop_ack_nack++;
			
			if(rnd==2)
				
				delay_ack_nack++;
		

	ack[2]=rnd;
		
	if(rnd==1)
	
	{
	
		cout<<"ack"<<ack[0]<<ack[1]<<ack[2]<<endl;
	
		int tt=send(sockfd,ack,3*sizeof(int),0);
		
		cout<<"sent"<<tt<<"bytes"<<endl;
	}
	
	else if(rnd==2)
	
	{
		c++;
		
		pthread_create(&tid[c],NULL,delay,NULL);
		
		pthread_join(tid[c],NULL);
	
	}
	
	crcarray2[522]=ack[1];
	crcarray4[522]=(ack[1]+1)%5;
	crcarray6[522]=(ack[1]+2)%5;
	/*else if(rnd==3)
	
	{
	
		cout<<"ack"<<ack[0]<<ack[1]<<ack[2]<<endl;
	
		int tt=send(sockfd,ack,3*sizeof(int),0);
		
		cout<<"sent"<<tt<<"bytes"<<endl;	

	}*/

}	

else if(ref_a[0]==2 || ref_a[1]==2 || ref_a[2]==2)
	
	{
		
			ack[0]=2;
			
				srand(time(0));

				rnd4=rand()%3+1;			/*if rnd=1 then it represents ack or nack
	
									  if rnd=2 then it represents dack or dnack
					  
								  	  if rnd=3 then it represents ack_drop or nack_drop*/	
cuu++;
				/*if(cuu==1 || cuu==4)
				rnd4=2;	
				else
				rnd4=1;*/
				cout<<"rnd"<<rnd4<<endl;
	
			if(rnd4!=3)
			{	
			if(ref_a[0]==2)
			
				ack[1]=crcarray2[522];
			
			else if(ref_a[1]==2)
			
				ack[1]=crcarray4[522];
			
			else if(ref_a[2]==2)
			
				ack[1]=crcarray6[522];
			
				
				if(ack[0]==2)
		
					nack++;
			}
					if(rnd4==3)
			
						drop_ack_nack++;
			
					if(rnd4==2)
						{
						delay_ack_nack++;
						count_frames-=3;
						}

				ack[2]=rnd4;
		
				if(rnd4==1)
	
				{
	
					cout<<"ack"<<ack[0]<<ack[1]<<ack[2]<<endl;
	
					int tt=send(sockfd,ack,3*sizeof(int),0);
		
					cout<<"sent"<<tt<<"bytes"<<endl;
				}
	
				else if(rnd4==2)
	
				{
					c++;
		
					pthread_create(&tid[c],NULL,delay,NULL);
		
					pthread_join(tid[c],NULL);
	
				}
	
				/*else if(rnd==3)
	
				{
	
					cout<<"ack"<<ack[0]<<ack[1]<<ack[2]<<endl;
	
					int tt=send(sockfd,ack,3*sizeof(int),0);
		
					cout<<"sent"<<tt<<"bytes"<<endl;	

				}*/

				te=1;
				
				int crcarray22[1000];

	while(((ack[0]==2 || rnd==3) && te!=0) && rnd4==1)

	{

		//cuo++;
	
	te=recv(sockfd,(int *)crcarrayReceived, sizeof(crcarrayReceived), 0);
	
	cout<<"recvi"<<te<<"bytes"<<endl;
	
	int p;
	
		
	for (int i = 1 ; i <=522 ; ++i) 

		crcarray22[i]=crcarrayReceived[i];
	    
	cout<<"ack or nack"<<crcarray22[521]<<"recv crc_sq"<<crcarray22[522]<<endl;
		
	//crc check

	if((crcarray22[521]!=3 && crcarray22[522]==ack[1])|| rnd==3)

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

		if(rnd!=3)

		{				
				int sum;
	 
	 			sum=0;
	
				for(int e=1;e<=512;e++)	

					sum=sum+crcarray22[e];
	
	
			while(sum>0)	

			{	
	
			int q=1,k=1,ctr=1,clt=1;
	
			for(int j=1;j<=520;j++)	

			{	
			
				if(crcarray22[j]==1 && k==1)

				{	k++;

					  int p;
		 			
			 		int y=1;

					for ( int p = j; p < j+9; p++ )

			 		{
		 		 		  	
			 		    C[y]=single(crcarray22[p],B[y]);

			 		    y++;  
			 		}	

					y=1;
		
					for(int d=0;d<9;d++)

					crcarray22[d+clt]=C[d+1]; //updating 
						
					 sum=0;

					for(int e=1;e<=512;e++)	

					sum=sum+crcarray22[e];
				
				}
		
				clt++;
		
			}

			}
	
			cout<<"check crc"<<endl;		

			int f=0,r[8];

			for(int h=1;h<=520;h++)

			{

				if(crcarray22[h]==1)

					f++;
			}		
	
			ack[1]=crcarray22[522];	
		
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
			
		}
		
		srand(time(0));

		rnd=rand()%3+1;			/*if rnd=1 then it represents ack or nack
	
						  if rnd=2 then it represents dack or dnack
					  
						  if rnd=3 then it represents ack_drop or nack_drop*/	

		//rnd=1;
		cout<<"rnd"<<rnd<<"ack[1]:"<<ack[1]<<endl;
	
			if(ack[0]==1)
	
				{	
					
	crcarray2[522]=ack[1];
	crcarray4[522]=(ack[1]+1)%5;
	crcarray6[522]=(ack[1]+2)%5;
	
				if(ack[1]==crcarray2[522])
				{
				cout<<"a";
				if(ref_a[1]==1)
				
					ack[1]=(ack[1]+2)%5;		
				else
				
					ack[1]=(ack[1]+1)%5;
				}

				
				else if(ack[1]==crcarray4[522])
				{cout<<"b";
				if(ref_a[2]==1)
				
					ack[1]=(ack[1]+2)%5;		
				else
				
					ack[1]=(ack[1]+1)%5;
				}
				
				
				else if(ack[1]==crcarray6[522])
				{
				cout<<"c";
					ack[1]=(ack[1]+1)%5;
				}
cout<<"ack1:"<<ack[1]<<endl;
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
	
	
		/*else if(rnd==3)
			//frame drop
		{
	
			cout<<"ack"<<ack[0]<<ack[1]<<ack[2]<<endl;
	
			int tt=send(sockfd,ack,3*sizeof(int),0);
		
			cout<<"sent3"<<tt<<"bytes"<<endl;	

		}*/
	

		cout<<endl;

	}

	else if(crcarray2[521]==3)

	{

		cout<<"frame drop\n";

		frame_drop++;
	}

	}
			
	}
	
	else
	{
	
		srand(time(0));

		rnd=rand()%3+1;			/*if rnd=1 then it represents ack or nack
	
						  if rnd=2 then it represents dack or dnack
					  
						  if rnd=3 then it represents ack_drop or nack_drop*/

		//rnd=1;
		cout<<"rnd"<<rnd<<"ack[1]:"<<ack[1]<<endl;
		
			
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
	
	}	
	cout<<endl;

//}

}

cout<<"no.of nacks"<<nack<<endl;

cout<<"no.of frame_drops"<<frame_drop<<endl;

cout<<"no.of dealyed acks or nacks"<<delay_ack_nack<<endl;

cout<<"no.of ack or nack drops"<<drop_ack_nack<<endl;

cout<<"no.of successful frames"<<count_frames+(3*delay_ack_nack)<<endl;	

  	close(sockfd);

  	return 0;
}	
