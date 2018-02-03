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
  if(argc !=2)
    {
      cerr << "Usage syntax: ./server <port_no>" << endl;
      return 0;
    }
  int sockfd;
  struct sockaddr_in my_addr;

  sockfd=socket(PF_INET,SOCK_STREAM,0);  //Creating the socket

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
int i;
  listen(sockfd,10);
  struct sockaddr_in client_addr;
  socklen_t client_size=sizeof client_addr;
  int client_fd[10];
   char serv_msg[100];
    time_t now;
  for(i=1;i<=3;i++)
  {
  
   client_fd[i]=accept(sockfd,(struct sockaddr*)&client_addr, &client_size);

  cout << "Accepted incoming connection" << endl;
      now =time(0);
	 
	  strcpy(serv_msg,ctime(&now));
	   cout << "Current Server Time:" << serv_msg<< endl;
  
  
	  cout << "Current Server Time:" << serv_msg<< endl;
	  temp=send(client_fd[i],serv_msg,sizeof serv_msg,0);
	  cout << "Sent " << temp << " bytes" << endl;
  
  
  }
    for(i=1;i<=3;i++)
    
  temp=send(client_fd[i],"xyz",3,0);
  for(i=1;i<=3;i++)
  close(client_fd[i]);
  close(sockfd);
  

  return 0;
}
