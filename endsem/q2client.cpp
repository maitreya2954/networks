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
int count11=0;
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
        int ccc=0; 
  	
	int client_fd[100];
	fd_set rfds,master;
	int retval;
	int mod1[540],mod2[540],mod3[540],mod4[540],mod5[540],mod6[540],mod7[540],mod8[540],mod9[540],mod10[540];
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
	int crcarray1[1000];
	int crcarray2[1000];
	int crcarraye[1000];
	int crcarray3[1000];
	int crcarray4[1000];
	int crcarrayf[1000];
	int crcarray5[1000];
	int crcarray6[1000];
	int crcarrayh[1000];
	int crcarray7[1000];
	int crcarray8[1000];
	int crcarray9[1000];
	int crcarray10[1000];
	int crcarray11[1000];
	int crcarray12[1000];
	int crcarray13[1000];
	int crcarray14[1000];
	int crcarray15[1000];
	int crcarray16[1000];
	int crcarray17[1000];
	int crcarray18[1000];
	int crcarray19[1000];
	int crcarray20[1000];
	int A[10],B[10],C[10];
	 srand((unsigned)time(0)); 
	 	 B[1]=1;
	 	 B[2]=0;
	 	 B[3]=0;
	 	 B[4]=1;
	 	 B[5]=1;

crcarray1[522]=0;
crcarray3[522]=1;
crcarray5[522]=2;
crcarray7[522]=3;
crcarray9[522]=4;
crcarray11[522]=5;
crcarray13[522]=6;
crcarray15[522]=7;
crcarray17[522]=8;
crcarray19[522]=9;
mod1[522]=0;	 	
mod2[522]=1;
mod3[522]=2;
mod4[522]=3;	 	
mod5[522]=4;
mod6[522]=5;
mod7[522]=6;	 	
mod8[522]=7;
mod9[522]=8;
mod10[522]=9;
int drop_ack_nack=0,nack=0,frame_drop1=0,frame_drop2=0,frame_drop3=0,frame_drop4=0,frame_drop5=0,frame_drop6=0,frame_drop7=0,frame_drop8=0,frame_drop9=0,frame_drop10=0,dealy_ack_nack=0,cuo=0;
	
for(int s=1;s<=5;s++)
//int s=0;	 	
//while(s<=20)
{    	
cout<<"frame"<<endl;
cout<<s<<endl;	
//1st frame
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
			mod1[sh]=crcarray1[sh];
				srand(time(0));
	int rnd1=(rand()%3)+1; 		/*rnd=1-->ack
					  rnd=2-->nack
					  rnd=3-->frame_drop*/
	/*if(cuo==1)				  
	rnd1=3;
	else
	rnd1=1;
	*/
	//rnd1=1;
	cout<<"rnd1:"<<rnd1<<endl;    //frame1
	if(rnd1==2)
	{
		int p;	
		//10 bits error
		for(int i=1; i<=10; i++)
	    	{ 
	    	   	 p = (rand()%520)+1;     	     
			crcarray1[p]=1-crcarray1[p];//fliping the bits
		}
	}
	if(rnd1==3)
		frame_drop1++;
	crcarray1[521]=rnd1;
	int te;
te=send(client_fd[0],crcarray1, sizeof(crcarray1),0);
 		 	  cout<<"send "<<te<<"bytes:"<<crcarray1[522]<<endl;
			
//2nd frame   
	for(i=1; i<=512; i++)
    	{ 
    	    		crcarray3[i] = (rand()%2);     	     
    	   		crcarray4[i] = crcarray3[i]; //duplicate crcarray
	}
	for(i=513;i<=520;i++)
	{
		crcarray3[i] = 0; 
		crcarray4[i] = crcarray3[i]; 
	}
	cout<<endl;
	 sum=0;
				for(int e=1;e<=520;e++)	
				{
					sum=sum+crcarray4[e];
				}
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
	f=1;
	for(int h=513;h<=520;h++)
	{
		r[f]=crcarray4[h];
		f++;
	}	
	w=1;
	for(int u=513;u<=520;u++)
	{
		crcarray3[u]=r[w];
		w++;
	}
		for(int sh=1;sh<=520;sh++)
			mod2[sh]=crcarray3[sh];
			int rnd2=(rand()%3)+1; 		/*rnd=1-->ack
					  rnd=2-->nack
					  rnd=3-->frame_drop*/
	//if(cuo==1)				  
	//rnd2=3;
	//else
	//rnd2=1;
	
	cout<<"rnd2:"<<rnd2<<endl;    //frame2
	if(rnd2==2)
	{
		int p;	
		//10 bits error
		for(int i=1; i<=10; i++)
	    	{ 
	    	   	 p = (rand()%520)+1;     	     
			crcarray3[p]=1-crcarray3[p];//fliping the bits
		}
	}
	if(rnd2==3)
		frame_drop2++;
	crcarray3[521]=rnd2;
	te=send(client_fd[0],crcarray3, sizeof(crcarray1),0);
 		 	  cout<<"send2 "<<te<<"bytes:"<<crcarray3[522]<<endl;
//3rd frame
	for(i=1; i<=512; i++)
    	{ 
    	    		crcarray5[i] = (rand()%2);     	     
    	   		crcarray6[i] = crcarray5[i]; //duplicate crcarray
	}
	for(i=513;i<=520;i++)
	{
		crcarray5[i] = 0; 
		crcarray6[i] = crcarray5[i]; 
	}
	cout<<endl;
	 sum=0;
				for(int e=1;e<=520;e++)	
				{
					sum=sum+crcarray6[e];
				}
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
	f=1;
	for(int h=513;h<=520;h++)
	{
		r[f]=crcarray6[h];
		f++;
	}	
	w=1;
	for(int u=513;u<=520;u++)
	{
		crcarray5[u]=r[w];
		w++;
	}
		for(int sh=1;sh<=520;sh++)
			mod3[sh]=crcarray5[sh];
			int rnd3=(rand()%3)+1; 		/*rnd=1-->ack
					  rnd=2-->nack
					  rnd=3-->frame_drop*/
	//if(cuo==1)				  
	//rnd3=1;
	//else
	//rnd3=1;
	cout<<"rnd3:"<<rnd3<<endl;   
	if(rnd3==2)                  //frame3
	{
		int p;	
		//10 bits error
		for(int i=1; i<=10; i++)
	    	{ 
	    	   	 p = (rand()%520)+1;     	     
			crcarray5[p]=1-crcarray5[p];//fliping the bits
		}
	}
	if(rnd3==3)
		frame_drop3++;
	crcarray5[521]=rnd3;
	te=send(client_fd[0],crcarray5, sizeof(crcarray1),0);
 		 	  cout<<"send3 "<<te<<"bytes:"<<crcarray5[522]<<endl;

			//4th frame
    	
    	for(i=1; i<=512; i++)
    	{ 
    	    		crcarray7[i] = (rand()%2);     	     
    	   		crcarray8[i] = crcarray7[i]; //duplicate crcarray
	}
	for(i=513;i<=520;i++)
	{
		crcarray7[i] = 0; 
		crcarray8[i] = crcarray7[i]; 
	}
	cout<<endl;
	
	 sum=0;
				for(int e=1;e<=520;e++)	
				{
					sum=sum+crcarray8[e];
				}
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
	f=1;
	for(int h=513;h<=520;h++)
	{
		r[f]=crcarray8[h];
		f++;
	}	
	w=1;
	for(int u=513;u<=520;u++)
	{
		crcarray7[u]=r[w];
		w++;
	}
		for(int sh=1;sh<=520;sh++)
			mod4[sh]=crcarray7[sh];
			int rnd4=( rand()%3)+1;
	cout<<"rnd4:"<<rnd4<<endl;
	
	
	if(rnd4==2)                             //frame4
 	{
		int p;	
		//10 bits error
		for(int i=1; i<=10; i++)
	    	{ 
	    	   	 p = (rand()%520)+1;     	     
			crcarray7[p]=1-crcarray7[p];//fliping the bits
		}
	}
	if(rnd4==3)
		frame_drop4++;
	crcarray7[521]=rnd4;
	te=send(client_fd[0],crcarray7, sizeof(crcarray1),0);
 		 	  cout<<"send "<<te<<"bytes:"<<crcarray7[522]<<endl;

//5th frame   
	for(i=1; i<=512; i++)
    	{ 
    	    		crcarray9[i] = (rand()%2);     	     
    	   		crcarray10[i] = crcarray9[i]; //duplicate crcarray
	}
	for(i=513;i<=520;i++)
	{
		crcarray9[i] = 0; 
		crcarray10[i] = crcarray9[i]; 
	}
	cout<<endl;
	 sum=0;
				for(int e=1;e<=520;e++)	
				{
					sum=sum+crcarray10[e];
				}
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
	f=1;
	for(int h=513;h<=520;h++)
	{
		r[f]=crcarray10[h];
		f++;
	}	
	w=1;
	for(int u=513;u<=520;u++)
	{
		crcarray9[u]=r[w];
		w++;
	}
		for(int sh=1;sh<=520;sh++)
			mod5[sh]=crcarray9[sh];
			int rnd5=(rand()%3)+1; 		/*rnd=1-->ack
					  rnd=2-->nack
					  rnd=3-->frame_drop*/
	//if(cuo==1)				  
	//rnd2=3;
	//else
	//rnd2=1;
	
	cout<<"rnd5:"<<rnd5<<endl;     //frame5
	if(rnd5==2)
	{
		int p;	
		//10 bits error
		for(int i=1; i<=10; i++)
	    	{ 
	    	   	 p = (rand()%520)+1;     	     
			crcarray9[p]=1-crcarray9[p];//fliping the bits
		}
	}
	if(rnd5==3)
		frame_drop5++;
	crcarray9[521]=rnd5;
	te=send(client_fd[0],crcarray9, sizeof(crcarray1),0);
 		 	  cout<<"send2 "<<te<<"bytes:"<<crcarray9[522]<<endl;

	
//6th frame
	for(i=1; i<=512; i++)
    	{ 
    	    		crcarray11[i] = (rand()%2);     	     
    	   		crcarray12[i] = crcarray11[i]; //duplicate crcarray
	}
	for(i=513;i<=520;i++)
	{
		crcarray11[i] = 0; 
		crcarray12[i] = crcarray11[i]; 
	}
	cout<<endl;
	 sum=0;
				for(int e=1;e<=520;e++)	
				{
					sum=sum+crcarray12[e];
				}
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
	f=1;
	for(int h=513;h<=520;h++)
	{
		r[f]=crcarray12[h];
		f++;
	}	
	w=1;
	for(int u=513;u<=520;u++)
	{
		crcarray11[u]=r[w];
		w++;
	}
		for(int sh=1;sh<=520;sh++)
			mod6[sh]=crcarray11[sh];
			int rnd6=(rand()%3)+1; 		/*rnd=1-->ack
					  rnd=2-->nack
					  rnd=3-->frame_drop*/
	//if(cuo==1)				  
	//rnd3=1;
	//else
	//rnd3=1;
	cout<<"rnd6:"<<rnd6<<endl;
	if(rnd6==2)                   //frame6
	{
		int p;	
		//10 bits error
		for(int i=1; i<=10; i++)
	    	{ 
	    	   	 p = (rand()%520)+1;     	     
			crcarray11[p]=1-crcarray11[p];//fliping the bits
		}
	}
	if(rnd6==3)
		frame_drop6++;
	crcarray11[521]=rnd6;
	te=send(client_fd[0],crcarray11, sizeof(crcarray1),0);
 		 	  cout<<"send3 "<<te<<"bytes:"<<crcarray11[522]<<endl;

	
//7th frame
    	
    	for(i=1; i<=512; i++)
    	{ 
    	    		crcarray13[i] = (rand()%2);     	     
    	   		crcarray14[i] = crcarray13[i]; //duplicate crcarray
	}
	for(i=513;i<=520;i++)
	{
		crcarray13[i] = 0; 
		crcarray14[i] = crcarray13[i]; 
	}
	cout<<endl;

	 sum=0;
				for(int e=1;e<=520;e++)	
				{
					sum=sum+crcarray14[e];
				}
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
	f=1;
	for(int h=513;h<=520;h++)
	{
		r[f]=crcarray14[h];
		f++;
	}	
	w=1;
	for(int u=513;u<=520;u++)
	{
		crcarray13[u]=r[w];
		w++;
	}
		for(int sh=1;sh<=520;sh++)
			mod7[sh]=crcarray13[sh];
			int rnd7=( rand()%3)+1;
		                           //frame7
 	cout<<"rnd7:"<<rnd7<<endl;
 	if(rnd7==2)  
 	{
		int p;	
		//10 bits error
		for(int i=1; i<=10; i++)
	    	{ 
	    	   	 p = (rand()%520)+1;     	     
			crcarray13[p]=1-crcarray13[p];//fliping the bits
		}
	}
	if(rnd7==3)
		frame_drop7++;
	crcarray13[521]=rnd7;
	te=send(client_fd[0],crcarray13, sizeof(crcarray1),0);
 		 	  cout<<"send "<<te<<"bytes:"<<crcarray13[522]<<endl;

	
//8th frame   
	for(i=1; i<=512; i++)
    	{ 
    	    		crcarray15[i] = (rand()%2);     	     
    	   		crcarray16[i] = crcarray15[i]; //duplicate crcarray
	}
	for(i=513;i<=520;i++)
	{
		crcarray15[i] = 0; 
		crcarray16[i] = crcarray15[i]; 
	}
	cout<<endl;
	 sum=0;
				for(int e=1;e<=520;e++)	
				{
					sum=sum+crcarray16[e];
				}
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
	f=1;
	for(int h=513;h<=520;h++)
	{
		r[f]=crcarray16[h];
		f++;
	}	
	w=1;
	for(int u=513;u<=520;u++)
	{
		crcarray15[u]=r[w];
		w++;
	}
		for(int sh=1;sh<=520;sh++)
			mod8[sh]=crcarray15[sh];
			int rnd8=(rand()%3)+1; 		/*rnd=1-->ack
					  rnd=2-->nack
					  rnd=3-->frame_drop*/
	//if(cuo==1)				  
	//rnd2=3;
	//else
	//rnd2=1;
	
	cout<<"rnd8:"<<rnd8<<endl;     //frame8
	if(rnd8==2)
	{
		int p;	
		//10 bits error
		for(int i=1; i<=10; i++)
	    	{ 
	    	   	 p = (rand()%520)+1;     	     
			crcarray15[p]=1-crcarray15[p];//fliping the bits
		}
	}
	if(rnd8==3)
		frame_drop8++;
	crcarray15[521]=rnd8;
	te=send(client_fd[0],crcarray15, sizeof(crcarray1),0);
 		 	  cout<<"send2 "<<te<<"bytes:"<<crcarray15[522]<<endl;

//9th frame
	for(i=1; i<=512; i++)
    	{ 
    	    		crcarray17[i] = (rand()%2);     	     
    	   		crcarray18[i] = crcarray17[i]; //duplicate crcarray
	}
	for(i=513;i<=520;i++)
	{
		crcarray17[i] = 0; 
		crcarray18[i] = crcarray17[i]; 
	}
	cout<<endl;
	 sum=0;
				for(int e=1;e<=520;e++)	
				{
					sum=sum+crcarray18[e];
				}
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
	f=1;
	for(int h=513;h<=520;h++)
	{
		r[f]=crcarray18[h];
		f++;
	}	
	w=1;
	for(int u=513;u<=520;u++)
	{
		crcarray17[u]=r[w];
		w++;
	}
		for(int sh=1;sh<=520;sh++)
			mod9[sh]=crcarray17[sh];
			int rnd9=(rand()%3)+1; 		/*rnd=1-->ack
					  rnd=2-->nack
					  rnd=3-->frame_drop*/
	//if(cuo==1)				  
	//rnd3=1;
	//else
	//rnd3=1;
	cout<<"rnd9:"<<rnd9<<endl;
	if(rnd9==2)                   //frame9
	{
		int p;	
		//10 bits error
		for(int i=1; i<=10; i++)
	    	{ 
	    	   	 p = (rand()%520)+1;     	     
			crcarray17[p]=1-crcarray17[p];//fliping the bits
		}
	}
	if(rnd9==3)
		frame_drop9++;
	crcarray17[521]=rnd9;
te=send(client_fd[0],crcarray17, sizeof(crcarray1),0);
 		 	  cout<<"send3 "<<te<<"bytes:"<<crcarray17[522]<<endl;

	
			//10th frame
	for(i=1; i<=512; i++)
    	{ 
    	    		crcarray19[i] = (rand()%2);     	     
    	   		crcarray20[i] = crcarray19[i]; //duplicate crcarray
	}
	for(i=513;i<=520;i++)
	{
		crcarray19[i] = 0; 
		crcarray20[i] = crcarray19[i]; 
	}
	cout<<endl;
	 sum=0;
				for(int e=1;e<=520;e++)	
				{
					sum=sum+crcarray20[e];
				}
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
	f=1;
	for(int h=513;h<=520;h++)
	{
		r[f]=crcarray20[h];
		f++;
	}	
	w=1;
	for(int u=513;u<=520;u++)
	{
		crcarray19[u]=r[w];
		w++;
	}
		for(int sh=1;sh<=520;sh++)
			mod10[sh]=crcarray19[sh];
			int rnd10=(rand()%3)+1;                   //frame10
        cout<<"rnd10:"<<rnd10<<endl;
        if(rnd10==2)                  
	{
		int p;	
		//10 bits error
		for(int i=1; i<=10; i++)
	    	{ 
	    	   	 p = (rand()%520)+1;     	     
			crcarray19[p]=1-crcarray19[p];//fliping the bits
		}
	}
	if(rnd10==3)
		frame_drop10++;
	crcarray19[521]=rnd10;
	te=send(client_fd[0],crcarray19, sizeof(crcarray1),0);
 		 	  cout<<"send3 "<<te<<"bytes:"<<crcarray19[522]<<endl;
	
ack[0]=2;
ack[2]=3;
retval=1;

while( rnd1!=1 || retval==0 || ack[2]==3)
{
cuo++;
		for(int sh=1;sh<=520;sh++)
			crcarray1[sh]=mod1[sh];
		for(int sh=1;sh<=520;sh++)
			crcarray3[sh]=mod2[sh];
		for(int sh=1;sh<=520;sh++)
			crcarray5[sh]=mod3[sh];
		for(int sh=1;sh<=520;sh++)
			crcarray7[sh]=mod4[sh];
		for(int sh=1;sh<=520;sh++)
			crcarray9[sh]=mod5[sh];
		for(int sh=1;sh<=520;sh++)
			crcarray11[sh]=mod6[sh];
	 	for(int sh=1;sh<=520;sh++)
			crcarray13[sh]=mod7[sh];
		for(int sh=1;sh<=520;sh++)
			crcarray15[sh]=mod8[sh];
		for(int sh=1;sh<=520;sh++)
			crcarray17[sh]=mod9[sh];
		for(int sh=1;sh<=520;sh++)
			crcarray19[sh]=mod10[sh];

	
	
	
	
        



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
		cout<<"ack"<<ack[0]<<ack[1]<<ack[2]<<ack[3]<<ack[4]<<ack[5]<<ack[6]<<ack[7]<<ack[8]<<ack[9]<<endl;
			
		if(ack[9]==2)
			dealy_ack_nack++;
		/*if(ack[2]==3)
		{
			cout<<"ack or nack drop\n";
			drop_ack_nack++;
			/*if(ack[1]!=crcarray1[522])
			{
			crcarray1[522]=ack[1];
			crcarray3[522]=(ack[1]+1)%5;
			crcarray5[522]=(ack[1]+2)%5;
			mod1[522]=ack[1];
			mod2[522]=(ack[1]+1)%5;
			mod3[522]=(ack[1]+2)%5;
			}
		}*/	
		if(ack[9]!=3)
		{
			crcarray1[522]=ack[1];
			crcarray3[522]=(ack[1]+1)%5;
			crcarray5[522]=(ack[1]+2)%5;
			crcarray7[522]=(ack[1]+3)%5;
			crcarray9[522]=(ack[1]+4)%5;
			crcarray11[522]=(ack[1]+5)%5;
			crcarray13[522]=(ack[1]+6)%5;
			crcarray15[522]=(ack[1]+7)%5;
			crcarray17[522]=(ack[1]+8)%5;
			crcarray19[522]=(ack[1]+9)%5;
			mod1[522]=ack[1];
			mod2[522]=(ack[1]+1)%5;
			mod3[522]=(ack[1]+2)%5;
			mod4[522]=(ack[1]+3)%5;
			mod5[522]=(ack[1]+4)%5;
			mod6[522]=(ack[1]+5)%5;
			mod7[522]=(ack[1]+6)%5;
			mod8[522]=(ack[1]+7)%5;
			mod9[522]=(ack[1]+8)%5;
			mod10[522]=(ack[1]+9)%5;
        		   if (retvala)
				{
              				printf("Data is available now.\n");
					if(ack[10]==2)
					{
						if(rnd9==1 && rnd10==1)
							{
								ccc=ccc+2;
								cout<<ccc<<"all frames sent successfully\n";
							}
						else if(rnd9==1)
							{
								ccc=ccc+1;
								cout<<ccc<<"all frames sent successfully\n";		
							}		
					}
					else 
					{
						
						//s=s+3;
						ccc=ccc+3;
						cout<<ccc<<"all frames sent successfully\n";
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
	
	cout<<"no.of frame drops"<<frame_drop1+frame_drop2+frame_drop3+frame_drop4+frame_drop5+frame_drop6+frame_drop7+frame_drop8+frame_drop9+frame_drop10<<endl;
	
	cout<<"no.of ack or nack drops"<<drop_ack_nack<<endl;
  	
 	close(client_fd[0]); 	
  	close(sockfd);
  	return 0;
}


