#include <iostream>

#include <sys/types.h>

#include <sys/socket.h>

#include <netinet/in.h>

#include <arpa/inet.h>

#include <unistd.h>

#include <string.h>

#include <stdlib.h>

#include <stdio.h>

using namespace std;

int main(int argc,char* argv[])

{

  if(argc !=2)

    {

      cerr << "Usage syntax: ./server <port_no>" << endl;

      return 0;

    }

  int sockfd;

  struct sockaddr_in my_addr;

  sockfd=socket(AF_INET,SOCK_STREAM,0);  //Creating the socket

  my_addr.sin_family=AF_INET;

  my_addr.sin_port=htons(atoi(argv[1]));

  my_addr.sin_addr.s_addr=INADDR_ANY;

  memset(my_addr.sin_zero, '\0', sizeof my_addr.sin_zero);

  int temp=bind(sockfd, (struct sockaddr *)&my_addr, (sizeof my_addr)); //Binding the socket to the address

  if(temp==0)

    cout << "Server started running at "<< inet_ntoa(my_addr.sin_addr)  << ":" << argv[1] << endl;

  else

    {

      cout << "Failed to bind socket" << endl;

      return -1;

    }

  listen(sockfd,10);		//listening to the port

struct sockaddr_in client_addr;

int client_fd,array[100],count=0;

char buf[100],rec_data[100];

  socklen_t client_size = sizeof client_addr;

do

{

  int client_fd = accept(sockfd,(struct sockaddr*)&client_addr, &client_size); //accepting incoming connections

  cout<<inet_ntoa(client_addr.sin_addr)<<endl;

  cout << "Accepted incoming connections" << endl;

  cout<<"client:"<<client_fd<<endl;

  array[count++]=client_fd;

}while(count<2);

	memset(buf,0,sizeof buf);	

	memset(rec_data,0,sizeof rec_data);

cout<<"count:"<<count<<endl;

count=2;

int cc=0,k,j,clients;

int tt[5];

while(cc!=9)

{

cout<<"which client do u want to send message or enter '9' to close the chat or enter 8 to continue or else 2 to send i value\n";

cin>>cc;

if(cc==9)

 {
		rec_data[0]='b';

		for(j=0;j<count;j++)
	{
	
		temp = send(array[j],rec_data,strlen(rec_data)+1,0);		//send data to client
	}

 }

else if(cc!=2)

	{

	for(k=0;k<2;k++)

	{
		if(cc==k)

		temp = recv(array[k],rec_data,sizeof rec_data,0);		//receiving data from client

	}

	for(j=0;j<2;j++)

	{

		if(j!=cc)

		temp = send(array[j],rec_data,sizeof rec_data,0);		//send data to client

	}


	}

else if(cc==2)
	
	{

		temp = recv(array[1],tt,5*sizeof(int),0);		//receiving data from client

		temp = send(array[0],tt,5*sizeof(tt),0);		//send data to client	}	

	}

}

cout<<"ended"<<endl;

  close(client_fd);
  
  close(sockfd);

return 0;

}
