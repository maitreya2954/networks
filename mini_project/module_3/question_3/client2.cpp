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

  int sockfd,temp;

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

rec_data[0]='c';

//while(1)

//{

  memset(buf,0,sizeof buf);	

  memset(rec_data,0,sizeof rec_data);

  cout << "Enter the string to c1:" << endl;

  cin.getline(buf,100); 

  temp = send(sockfd,buf,strlen(buf)+1,0);

  if(temp==-1)

    cout << "Error:not sent" << endl;

  else

    cout << "Sent " << temp << " bytes" << endl;


	char u[20],v[20],w[20];
	
	memset(u,0,sizeof u);

	memset(v,0,sizeof v);

	memset(w,0,sizeof w);

   temp=recv(sockfd,u,sizeof u,0);

  cout << "Received data from server:" << u << endl;

  cout << "Received " << temp << " bytes" << endl;


   temp=recv(sockfd,v,sizeof v,0);

  cout << "Received data from server:" << v << endl;

  cout << "Received " << temp << " bytes" << endl;


   temp=recv(sockfd,w,sizeof w,0);

  cout << "Received data from server:" << w << endl;

  cout << "Received " << temp << " bytes" << endl;

  int num1_a=0,num1_b=0,num2_a=0,num2_b=0,num3_a=0,num3_b=0,i,j,k,tt[5];


	for(i=0;i<sizeof u;i++)
		
		if(u[i]=='a')

			num1_a++;

	
	for(i=0;i<sizeof v;i++)

		{

			if(v[i]=='a')

				num2_a++;

			else if(v[i]=='b')

				num2_b++;

		}

	for(i=0;i<sizeof w;i++)
	{
		if(w[i]=='b')

			num3_b++;

		if(w[i]=='a')

			num3_a++;

	}	
	int counta2=0,countb2=0,t_num2_a=0,t_num2_b=0,l,flag=0;

	for(i=1;i<100;i++)

		{

			k=0;

			t_num2_a=num2_a*i;

			t_num2_b=num2_b*i;
/*
			for(j=0;j<t_num2_a;j++)

				v[k++]='a';	
			
			for(j=0;j<t_num2_b;j++)

				v[k++]='b';	
*/
			counta2=num1_a+t_num2_a+num3_a;

			countb2=t_num2_b+num3_b;

			if((num1_a+num2_a+num3_a)!=0 && (num2_b+num3_b)!=0)

			{

			if(counta2!=countb2 || counta2>(num1_a+num2_a+num3_a) || countb2>(num2_b+num3_b))

				break;		

			}

			else if((num1_a+num2_a+num3_a)==0)

			{
			
			if(countb2>(num2_b+num3_b))

				break;		

			}

			else if((num2_b+num3_b)==0)

			{			

			if(counta2!=2 && counta2!=3 && counta2!=5 && counta2!=7)

			{

				if((counta2%2)==0 || (counta2%3)==0 || (counta2%5)==0 ||(counta2%7)==0)

					break;		

			}

			}

		}

tt[0]=i;

	temp=send(sockfd,tt,5*sizeof(tt),0);

        cout<<"send i:"<<tt[0]<<endl;

cout<<"ended"<<endl;

close(sockfd);

return 0;

}
