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

  if(argc != 1)

    {

      cerr << "Usage syntax: ./client <ip_address> <port_no>" << endl;

      return 0;

    }

  int sockfd,temp;

char buf[100],rec_data[100];


  struct sockaddr_in my_addr;

  sockfd=socket(AF_INET,SOCK_STREAM,0);

  my_addr.sin_family=AF_INET;

  my_addr.sin_port=htons(3600);

  my_addr.sin_addr.s_addr=inet_addr("0.0.0.0");

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

  memset(buf,0,sizeof buf);	

  memset(rec_data,0,sizeof rec_data);

  int pid=fork();

  if(pid==0)

  {

while(buf[0]!='b')

{
  cout << "Enter the message to server:" << endl;

  cin.getline(buf,100); 

  temp = send(sockfd,buf,strlen(buf)+1,0);

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

  temp=recv(sockfd,rec_data,sizeof rec_data,0);

  cout << "Received data from server:" << rec_data << endl;

  cout << "Received " << temp << " bytes" << endl;

}

}

cout<<"end"<<endl;

close(sockfd);

return 0;

}
