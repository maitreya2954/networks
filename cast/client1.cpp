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

using namespace std;

int main(int argc,char* argv[])
{
  if(argc != 3)
    {
      cerr << "Usage syntax: ./client <ip_address> <port_no>" << endl;
      return 0;
    }
  int sockfd;
  struct sockaddr_in my_addr;

  sockfd=socket(PF_INET,SOCK_STREAM,0);

  my_addr.sin_family=AF_INET;
  my_addr.sin_port=htons(atoi(argv[2]));
  my_addr.sin_addr.s_addr=inet_addr(argv[1]);
  memset(my_addr.sin_zero, '\0', sizeof my_addr.sin_zero);

  int temp=connect(sockfd,(struct sockaddr*)&my_addr, sizeof my_addr);

  if(temp==0)
    cout << "Connection established with server" << endl;
  else
    {
      cout << "Could not establish connection!" << endl;
      return -1;
    }


  char rec_data[50];

  recv(sockfd,rec_data,sizeof rec_data,0);
  char buffer[500];
  
  recv(sockfd,buffer,sizeof buffer,0);
  cout << "Server  received:" << buffer << endl;
  cout << "Server  received:" << rec_data << endl;
  
  close(sockfd);
  return 0;
}
