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

	
	int32_t vrcarray[1000];
	int32_t vrcarray1[1000];
	int vrcparity[100];
	int tem[1000];
	
	 srand((unsigned)time(0)); 
	 
for(int s=1;s<=100;s++)
{	
	cout<<s<<endl;	
	 
    	//generating 512 random integers
    	int i;
    	for(i=1; i<=512; i++)
    	{ 
    	    vrcarray[i] = (rand()%2);     	     
		tem[i]=vrcarray[i];    	   
	}
		
	//VRC error detection
	for(i=1;i<=512;i++)
	{			
		
		if(i%32==0)
		{	
				int sum=0;
			
				for(int l=0;l<32;l++)
				{
					sum=vrcarray[i-l]+sum;
				}
				if(sum%2==0)
				{	
					vrcparity[i/32]=0;
				}
				else if(sum%2==1)
				{
					vrcparity[i/32]=1;
				}	
		}	
			
	}
	
	
	int p;	
	//10 bits error
	for(i=1; i<=10; i++)
	//for(int i=1; i<=20; i++)
    	{ 
    	    p = (rand()%512)+1;     	     
    	    cout <<"p="<<p<< endl;
		vrcarray[p]=1-vrcarray[p];//fliping the bits
	}
		
		
		
			
		send(client_fd[0], vrcarray, sizeof(vrcarray),0);
  	  
  	  	send(client_fd[0],vrcparity, sizeof(vrcparity),0);
  	  	
	//lrc 

	int i1,ctr=0,k;
	int j=1;
	k=512/32;
	int array[1111],a[1111],b[1111];
	srand(time(0));
	
			for(i1=1;i1<=512;i1++)
				{
					array[i1]=tem[i1];
				}
				cout<<endl;
				int l=1;
			
			for(i1=1;i1<=16;i1++)
				{
					for(j=0;j<16;j++)
						{
							if(array[i1+j*32]==1)
							ctr++;
		
						}
						if(ctr%2==0)
						a[i1]=0;
						else
						a[i1]=1;
						l++;
						ctr=0;
				}
	int y=1;
	
	for(i1=513;i1<=512+16;i1++)
	{
		array[i1]=a[y];
		y++;
	}
	
	cout<<endl;

	srand(time(0));
	//10bits flip error
		for(i=1;i<=10;i++)
		//for(int i=1; i<=20; i++)
			{
				b[i]=1+rand()%(512+16);
				if(array[b[i]]==1)
				array[b[i]]=0;
				else
				array[b[i]]=1;
			}		
		        	send(client_fd[0],array,sizeof (array),0);
			
	//crc-8

		
	int crcarray1[1000];
	int crcarray2[1000];
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
	 	
    	
	cout<<s<<endl;	
		
  	
  	 
    	for(i=1; i<=512; i++)
    	{ 
    		
    	    		crcarray1[i] = tem[i];     	     
    	   		    	   		
    	   		crcarray2[i] = crcarray1[i]; //duplicate crcarray
    	   				
	}
	//appending 0's
	for(i=513;i<=520;i++)
	{
		crcarray1[i] = 0; 
		crcarray2[i] = crcarray1[i]; 
	}
	
	cout<<endl;
	 // crc8 
	int sum;
	 sum=0;
				for(int e=1;e<=512;e++)	
				{
					sum=sum+crcarray2[e];
				}
				cout<<"sum1="<<sum<<"\n";
	
	
while(sum>0)	
{	
	
	
	int q=1,k=1,ctr=1,clt=1;
	
	for(int j=1;j<=520;j++)	
	{	
	
		
		
		if(crcarray2[j]==1 && k==1)
		{	k++;
		 
		 		int y=1;
				for ( p = j; p < j+9; p++ )
		 		{
		 
		 		  	
		 		    C[y]=single(crcarray2[p],B[y]);
		 		    y++;  
		 		}	
				y=1;
		
				for(int d=0;d<9;d++)
				{	
					crcarray2[d+clt]=C[d+1]; //updating 
				}
				
				 sum=0;
				for(int e=1;e<=512;e++)	
				{
					sum=sum+crcarray2[e];
				}
				
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
	
	//cout<<"apending"<<"\n";
	int w=1;
	for(int u=513;u<=520;u++)
	{
		crcarray1[u]=r[w];
		w++;
	}
	
	
		//if u comment this error making code u will receive a no error message
	//int p;	
	//10 bits error
	for( i=1; i<=10; i++)
	//for(int i=1; i<=20; i++)
    	{ 
    	   	 p = (rand()%520)+1;     	     
    	  	
		
		cout<<"crcarray1["<<p<<"]="<<crcarray1[p]<<endl;
		
		crcarray1[p]=1-crcarray1[p];//fliping the bits
		
		cout<<"crcarray1["<<p<<"]="<<crcarray1[p]<<endl;
	}
	

			
		
		int te=send(client_fd[0],crcarray1, sizeof(crcarray1),0);
 		 	  
 		 	  cout<<"send"<<te<<"bytes"<<endl;

	//crc-12

		cout<<s<<"crc-12"<<endl;	
	 
	 	
  	
  	 int B1[20];
    	for(i=1; i<=512; i++)
    	{ 
    		
    	    		crcarray1[i] = tem[i];     	     
    	   		    	   		
    	   		crcarray2[i] = crcarray1[i]; //duplicate crcarray
    	   				
	}
	//appending 0's
	for(i=513;i<=524;i++)
	{
		crcarray1[i] = 0; 
		crcarray2[i] = crcarray1[i]; 
	}
	
	 sum=0;
				for(int e=1;e<=512;e++)	
				{
					sum=sum+crcarray1[e];
				}
	
	
while(sum>0)	
{	
	
	
	int q=1,k=1,ctr=1,clt=1;
	
		
	for(int j=1;j<=524;j++)	
	{
		{
		 	 B1[1]=1;
		 	 B1[2]=1;
		 	 B1[3]=0;
		 	 B1[4]=0;
		 	 B1[5]=0;
		 	 B1[6]=0;
		 	 B1[7]=0;
		 	 B1[8]=0;
		 	 B1[9]=0;
		 	 B1[10]=1;
		 	 B1[11]=1;
		 	 B1[12]=0;
		 	 B1[13]=1;
		 }
			
		if(crcarray2[j]==1 && k==1)
		{	k++;
		 
		 		int y=1;
				for (p = j; p < j+13; p++ )
		 		{
		 
		 		  	
		 		    C[y]=single(crcarray2[p],B1[y]);
		 		    y++;  
		 		}	
				y=1;
		
				for(int d=0;d<13;d++)
				{	
					crcarray2[d+clt]=C[d+1]; //updating 
				}
				
				 sum=0;
				for(int e=1;e<=512;e++)	
				{
					sum=sum+crcarray2[e];
				}
					cout<<"sum2="<<sum<<"\n";
				
		}
		
		clt++;
							
		
	}

}
	
	//cout<<"reminder"<<endl;		
	f=1;
	for(int h=513;h<=524;h++)
	{
		
			r[f]=crcarray2[h];
			f++;
		
	}	
	
	//cout<<"apending"<<"\n";
	 w=1;
	for(int u=513;u<=524;u++)
	{
		crcarray1[u]=r[w];
		w++;
	}
	
	
	//if u comment this error making code u will receive a no error message
	//int p;	
	//10 bits error
	for(int t=1; t<=10; t++)
	//for(int t=1; t<=20; t++)
    	{ 
    	   	 p = (rand()%524)+1;     	     
    	  	
		
		crcarray1[p]=1-crcarray1[p];//fliping the bits
		
	}
		cout<<"before sending"<<endl;

			
		
	int te4=send(client_fd[0],crcarray1, sizeof(crcarray1),0);
 		 	  
 		 	  cout<<"send:"<<te4<<"bytes"<<endl;
  	  
  

int sockfd,newsockfd,portno,clilen,len9,cin9,carry9,p9,loop9=0;
int buffer9[600],s9[50],b9[600];
int msg9[600],flip9[100];
int n9,i9=0,temp9,j9,k9,l9;

printf("\n");
i9=0;j9=0,p9=0;
printf("loop start %d",loop9);
bzero(buffer9,600);
bzero(b9,600);
bzero(msg9,600);
bzero(s9,50);
bzero(flip9,100);
srand(time(0)+loop9);

for(i9=0;i9<512;i9++)
{
msg9[i9]=tem[i9];
b9[i9]=msg9[i9];
if(i9<32)
{
s9[i9]=msg9[i9];
}
}


for(p9=0;p9<15;p9++)
{
carry9=1;
k9=p9*32;
l9=k9+31;
len9=31;
temp9=l9+32;

while(carry9!=0)
{
cin9=0;
for(j9=0;j9<32;j9++)
{
if(s9[len9]==1 && b9[temp9]==1 && cin9==1)
{
s9[len9]=1;
cin9=1;
}
else if(s9[len9]==1 && b9[temp9]==1 && cin9==0)
{
s9[len9]=0;
cin9=1;
}

else if(s9[len9]==1 && b9[temp9]==0 && cin9==1)
{
s9[len9]=0;
cin9=1;
}

else if(s9[len9]==0 && b9[temp9]==1 && cin9==1)
{
s9[len9]=0;
cin9=1;
}

else if(s9[len9]==1 && b9[temp9]==0 && cin9==0)
{
s9[len9]=1;
cin9=0;
}

else if(s9[len9]==0 && b9[temp9]==1 && cin9==0)
{
s9[len9]=1;
cin9=0;
}

else if(s9[len9]==0 && b9[temp9]==0 && cin9==0)
{
s9[len9]=0;
cin9=0;
}
else if(s9[len9]==0 && b9[temp9]==0 && cin9==1)
{
s9[len9]=1;
cin9=0;
}
len9--;
temp9--;
}
carry9=cin9;
if(carry9==1)
{
len9=31;
temp9=31;
for(i9=0;i9<31;i9++)
{
b9[i9]=0;
}
b9[temp9]=1;
}
}

}

j9=0;
//printf("\n\n");
for(i9=0;i9<544;i9++)
{
if(i9<512)
{
buffer9[i9]=msg9[i9];
}
else
{
if(s9[j9]==1)
buffer9[i9]=0;
else
buffer9[i9]=1;

j9++;
}
}

srand(time(0)+loop9);

for(i9=0;i9<10;i9++)
{
flip9[i9]=(rand()%544)+0;
}

for(i9=0;i9<544;i9++)
{
for(j9=0;j9<10;j9++)
{
if(i9==flip9[j9])
buffer9[i9]=1-buffer9[i9];
}
}

n9=write(client_fd[0],buffer9,sizeof buffer9);

printf("\nsent");

loop9++;


 } 	


  	
 		close(client_fd[0]); 	
 	
  	close(sockfd);

  	return 0;
}
