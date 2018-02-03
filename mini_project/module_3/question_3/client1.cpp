#include <iostream>

#include <sys/types.h>

#include <sys/socket.h>

#include <netinet/in.h>

#include <arpa/inet.h>

#include <string.h>

#include <stdlib.h>

#include <unistd.h>

#include <stdio.h>

using namespace std;

int main(int argc,char* argv[])

{

  if(argc != 3)

    {

      cerr << "Usage syntax: ./client <ip_address> <port_no>" << endl;

      return 0;

    }

  int sockfd,temp,tt[5];

char buf[100],rec_data[100];


  struct sockaddr_in my_addr;

  sockfd=socket(AF_INET,SOCK_STREAM,0);

  my_addr.sin_family=AF_INET;

  my_addr.sin_port=htons(atoi(argv[2]));

  my_addr.sin_addr.s_addr=inet_addr(argv[1]);

  memset(my_addr.sin_zero, '\0', sizeof my_addr.sin_zero);

  temp=connect(sockfd,(struct sockaddr*)&my_addr, sizeof my_addr);

  if(temp==0)

    cout << "Connection established with server" << endl;

  else

    {

      cout << "Could not establish connection!" << endl;

      return -1;

    }

  int choice;

  char u[20],w[20],v[20];

  memset(buf,0,sizeof buf);	

  memset(rec_data,0,sizeof rec_data);

rec_data[0]='c';


  memset(buf,0,sizeof buf);	

  memset(rec_data,0,sizeof rec_data);

  memset(buf,0,sizeof buf);	

  memset(rec_data,0,sizeof rec_data);

  temp=recv(sockfd,rec_data,sizeof rec_data,0);

  cout << "Received data from server:" << rec_data << endl;

  cout << "Received " << temp << " bytes" << endl;



	int counta=0,countb=0,i,j,k;

for(i=0;i<strlen(rec_data)+1;i++)

{

if(rec_data[i]=='a')

counta++;

else if(rec_data[i]=='b')

countb++;

}
if(countb!=0){  // when a^nb^n is regular
cout<<"a--------"<<counta<<endl;

cout<<"b--------"<<countb<<endl;

char a[20],b[20];

j=0;

k=0;

memset(a,0,sizeof a);

memset(b,0,sizeof b);


for(i=0;i<strlen(rec_data)+1;i++)

{

if(rec_data[i]=='a')

	a[j++]=rec_data[i];

else if(rec_data[i]=='b')

	b[k++]=rec_data[i];


}

cout<<"Aarray----"<<a<<endl;

cout<<"Barray----"<<b<<endl;

//spliting

//char u[20],w[20],v[20];

	memset(u,0,sizeof u);

	memset(v,0,sizeof v);

	memset(w,0,sizeof w);
	

int num1_a=0,num1_b=0,num2_a=0,num2_b=0,num3_a=0,num3_b=0;

cout<<"Enter no.of a's in 'u' respectively"<<endl;

cin>>num1_a;

cout<<"Enter no.of a's and b's in 'v' respectively"<<endl;

cin>>num2_a;

cin>>num2_b;

cout<<"Enter no.of b's in 'w' respectively"<<endl;

cin>>num3_b;

k=0;

for(i=0;i<num1_a;i++)

	u[i]=a[i];

for(j=i;j<num2_a+i;j++)

	v[k++]=a[j];

for(i=0;i<num2_b;i++)

	v[k++]=b[i];

k=0;

for(j=i;j<num3_b+i;j++)

	w[k++]=b[j];


temp = send(sockfd,u,sizeof u,0);
	
	temp = send(sockfd,v,sizeof v,0);
		
	temp = send(sockfd,w,sizeof w,0);
	
	
	temp=recv(sockfd,tt,5*sizeof(int),0);

	cout<<"recv i value:"<<tt[0]<<endl;

int counta2=0,countb2=0,t_num2_a=0,t_num2_b=0;

			k=0;

			t_num2_a=num2_a*tt[0];

			t_num2_b=num2_b*tt[0];

			for(j=0;j<num2_a;j++)

				v[k++]='a';	
			
			for(j=0;j<num2_b;j++)

				v[k++]='b';	

			counta2=num1_a+t_num2_a;

			countb2=t_num2_b+num3_b;

			if(countb!=0 && counta!=0)
			{

			if(counta2!=countb2 || counta2>(num1_a+num2_a) || countb2>(num2_b+num3_b))

				cout<<"yes,i'm convienced in 1"<<endl;

			}

			else if(counta==0)

			{

			if(countb2>(num2_b+num3_b))

				cout<<"yes,i'm convienced in 2"<<endl;

			}

			else if(countb==0)

			{

			if(counta2!=2 && counta2!=3 && counta2!=5 && counta2!=7)

			{			

				if((counta2%2)==0 || (counta2%3)==0 || (counta2%5)==0 ||(counta2%7)==0)

					cout<<"yes,i'm convienced in 3"<<endl;

			}

			}		

	
}

else if(countb==0)
{// when a^p is regular
cout<<"a--------"<<counta<<endl;


char a[20];

j=0;

k=0;

memset(a,0,sizeof a);



for(i=0;i<strlen(rec_data)+1;i++)

{

if(rec_data[i]=='a')

	a[j++]=rec_data[i];



}

cout<<"Aarray----"<<a<<endl;


//spliting



	memset(u,0,sizeof u);

	memset(v,0,sizeof v);

	memset(w,0,sizeof w);
	

int num1_a=0,num2_a=0,num3_a=0,l;

cout<<"Enter no.of a's in 'u' respectively"<<endl;

cin>>num1_a;

cout<<"Enter no.of a's in 'v' respectively"<<endl;

cin>>num2_a;


cout<<"Enter no.of a's in 'w' respectively"<<endl;

cin>>num3_a;


int var=0;

for(i=0;i<num1_a;i++)

	u[i]=a[var++];

for(j=0;j<num2_a;j++)

	v[j]=a[var++];

int s;
for(s=0;s<num3_a;s++)

	w[s]=a[var++];



	temp = send(sockfd,u,sizeof u,0);
	
	temp = send(sockfd,v,sizeof v,0);
		
	temp = send(sockfd,w,sizeof w,0);
	
	
	temp=recv(sockfd,tt,5*sizeof(int),0);

	cout<<"recv i value:"<<tt[0]<<endl;

int counta2=0,countb2=0,t_num2_a=0,t_num2_b=0;

			k=0;

			t_num2_a=num2_a*tt[0];

			counta2=num1_a+t_num2_a+num3_a;

			if(counta2!=2 && counta2!=3 && counta2!=5 && counta2!=7)

			{

				if((counta2%2)==0 || (counta2%3)==0 || (counta2%5)==0 ||(counta2%7)==0)

					cout<<"yes,i'm convienced"<<endl;

			}

}
cout<<"ended"<<endl;

close(sockfd);

return 0;

}
