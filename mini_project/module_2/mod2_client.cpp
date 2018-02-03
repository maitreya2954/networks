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
	
	int array[1000] ;
	int arrayReceived[1000] ;
	int parity1[100];
	int parity2[100];
	
	int countv=0,countl=0,countch=0,countc8=0,countc12=0;
for(int s=1;s<=100;s++)
{	
	//vrc
	cout<<s<<endl;	
	
	recv(sockfd, arrayReceived, sizeof(arrayReceived), 0);
	
	int p;
	recv(sockfd,parity1,sizeof(parity1),0 );
		
	
	for (int i = 1 ; i <=16 ; ++i) 
	{
		parity1[i];
	    
	}

	
		
	//VRC error detection
	for(int i=1;i<=512;i++)
	{			

		
		if(i%32==0)
		{	
				int sum=0;
			
				for(int l=0;l<32;l++)
				{
					sum=arrayReceived[i-l]+sum;
				}
				if(sum%2==0)
				{	
					parity2[i/32]=0;
				}
				else if(sum%2==1)
				{
					parity2[i/32]=1;
				}	
		}	
			
	}	
	int w=0;
	for(int i=1;i<=16;i++)
	{
		if(parity1[i]!=parity2[i])
		{
			w++;
		}	
	}
	
	if(w==0)
	{
		cout<<"no error"<<"\n";
		
	}
	else
	{
		countv++;//cout<<"error in message"<<"\n";
	}
	
	//lrc

		cout<<s<<"\n";   
    
    	int count,loop,binary1,binary2,ar[1111],i,k,j,ctr=0;
	
	int array[1111],a[1111];
	
	k=512/32;

	
     		recv(sockfd,array,sizeof (array),0);
     		
   	

   	cout<<endl;
   	
   	int l=1;
   	
   	for(p=1;p<=16;p++)
	{
			for(j=0;j<16;j++)
			{
				if(array[p+j*32]==1)
				ctr++;
				
			}
		
			if(ctr%2==0)
			ar[i]=0;
		
			else
			ar[i]=1;
			
	
	}
   	
	int y=1,par=513;

	
	for(int r=1;r<=16;r++)
	
			{
				if(array[par]==ar[r])
					y++;
				else 
					par++;
			}

	if(y==k)
		cout<<"there is no error"<<endl;
	else
		countl++;//cout<<"there is error"<<endl;

 
	//crc-8

	int crcarray2[1000] ;
	int crcarrayReceived[1000] ;
		 	
    	
	cout<<s<<"crc-8"<<endl;	
	
	int te1=recv(sockfd,crcarrayReceived, sizeof(crcarrayReceived), 0);
	
	cout<<"recv"<<te1<<"bytes"<<endl;
	
	
		
	for (int i = 1 ; i <=520 ; ++i) 
	{
		crcarray2[i]=crcarrayReceived[i];
	    
	}
	
	
	//crc check
		
	int crcarraye[1000];
	int A[20],B[20],C[20];
		
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
	 // crc8 
	
				
				int sum;
	 			sum=0;
				for(int e=1;e<=512;e++)	
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
				for (p = j; p < j+9; p++ )
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
	
	cout<<"check crc"<<endl;		
	int f=0,r[8];
	for(int h=1;h<=520;h++)
	{
		if(crcarray2[h]==1)
		{
			f++;
		}
	}	
	
	
	
	if(f==0)
	{
		cout<<"no error"<<endl;
	}
	else
	{
		countc8++;//cout<<"there is an error"<<endl;
	}
	cout<<endl;

	//crc-12
	int crcarrayReceived1[1000] ;
	 	
  	
	cout<<s<<"crc-12"<<endl;	
	
	int te3=recv(sockfd,crcarrayReceived1, sizeof(crcarrayReceived1), 0);
	
	cout<<"recv:"<<te3<<"bytes"<<"\n";
	
	
		
	for (int i = 1 ; i <=524 ; ++i) 
	{
		crcarray2[i]=crcarrayReceived1[i];
	   cout<<"array1["<<i<<"]="<<crcarrayReceived1[i]<<endl;	
	    
	}
	
	
		
	 
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
				
	 			sum=0;
				for(int e=1;e<=524;e++)	
				{
					sum=sum+crcarray2[e];
				}
				cout<<"sum1="<<sum<<"\n";
	
	
while(sum>0)	
{	
	
	
	int q=1,k=1,ctr=1,clt=1;
	
	for(int j=1;j<=524;j++)	
	{	
	
		
		
		if(crcarray2[j]==1 && k==1)
		{	k++;
				  int p;
		 			
		 
		 		int y=1;
				for ( int p = j; p < j+13; p++ )
		 		{
		 
		 		  	
		 		    C[y]=single(crcarray2[p],B[y]);
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
				
		}
		
		clt++;
							
		
	}

}
	
	f=0;
	for(int h=1;h<=524;h++)
	{
		if(crcarray2[h]==1)
		{
			f++;
		}
	}	
	
	
	
	if(f==0)
	{
		cout<<"no error"<<endl;
	}
	else
	{
		countc12++;//cout<<"there is an error"<<endl;
	}
	int v;
	
	
	cout<<endl;


int buffer9[600],s9[50],b9[600];

bzero(buffer9,600);
bzero(b9,600);
bzero(s9,50);
int p9=0,i9=0,j9=0,k9=0,l9=0,len9=0,carry9=0,temp9=0,n9,cin9;
n9=read(sockfd,buffer9,sizeof buffer9);




for(i9=0;i9<544;i9++)
{
b9[i9]=buffer9[i9];
if(i9<32)
s9[i9]=buffer9[i9];
}

for(p9=0;p9<16;p9++)
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

for(i9=0;i9<32;i9++)
{
if(s9[i9]!=1)
{
//cout<<"\nerror in data s["<<i9<<"]  count is "<<countch++<<endl;
countch++;
break;
}
}


}
cout<<"no.of times error detect are:\n";
 cout<<"count vrc:"<<countv<<endl;
cout<<"count lrc:"<<countl<<endl;
cout<<"count check_sum"<<countch<<endl;
cout<<"count crc8:"<<countc8<<endl;
cout<<"count crc12:"<<countc12<<endl;
  	close(sockfd);
  	return 0;
}
