#include <iostream>

#include <sys/types.h>

#include <sys/socket.h>

#include <netinet/in.h>

#include <arpa/inet.h>

#include <string.h>

#include <stdlib.h>

#include<unistd.h>


using namespace std;

int main(int argc,char* argv[])

{

  if(argc != 3)

    {

      cerr << "Usage syntax: ./client <ip_address> <port_no>" << endl;

      return 0;

    }

  int sockfd1;

  struct sockaddr_in my_addr1;

  sockfd1=socket(PF_INET,SOCK_STREAM,0);

  my_addr1.sin_family=AF_INET;

  my_addr1.sin_port=htons(atoi(argv[2]));

  my_addr1.sin_addr.s_addr=inet_addr(argv[1]);

  memset(my_addr1.sin_zero, '\0', sizeof my_addr1.sin_zero);

  int temp=connect(sockfd1,(struct sockaddr*)&my_addr1, sizeof my_addr1);

  if(temp==0)

    cout << "Connection established with server" << endl;

  else

    {

      cout << "Could not establish connection!" << endl;

      return -1;

    }


  int buf[5],array[5],sum=1,i;

  char rec_data[50],buff[50];

  temp=recv(sockfd1,buf,5*sizeof(int),0);

	for(i=1;i<=buf[0];i++)

			sum=sum*i;

	array[0]=sum;

	temp=send(sockfd1,array,5*sizeof(array),0);

  int sockfd2;

  struct sockaddr_in my_addr2;

  sockfd2=socket(PF_INET,SOCK_STREAM,0);

  my_addr2.sin_family=AF_INET;

  my_addr2.sin_port=htons(3600);

  my_addr2.sin_addr.s_addr=inet_addr("0.0.0.0");

  memset(my_addr2.sin_zero, '\0', sizeof my_addr2.sin_zero);

  temp=connect(sockfd2,(struct sockaddr*)&my_addr2, sizeof my_addr2);

  if(temp==0)

    cout << "Connection established with server" << endl;

  else

    {

      cout << "Could not establish connection!" << endl;

      return -1;

    }


int pid=fork();

  if(pid==0)

    {

      while(buff[0]!='b')

	{

	  cout << "Enter the message:" << endl;

	  cin.getline(buff,100); 

	  temp = send(sockfd2,buff,strlen(buff)+1,0);

	  if(temp==-1)

	    cout << "Error:not sent" << endl;

	  else

	    cout << "Sent " << temp << " bytes" << endl;
	}

    }

  else if(pid>0)

    {

      while(rec_data[0]!='b')

	{

	  temp=recv(sockfd2,rec_data,sizeof rec_data,0);

	  cout << "Received data from server:" << rec_data << endl;

	  cout << "Received " << temp << " bytes" << endl;

	}

    }

    		close(sockfd1);

		close(sockfd2);

  		return 0;

}
