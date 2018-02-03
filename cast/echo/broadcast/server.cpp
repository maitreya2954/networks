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

  listen(sockfd,10);
  
  struct sockaddr_in client_addr;
  socklen_t client_size=sizeof client_addr;
  int client_fd[10];
  int i;
  char buf[50];
	  cout << "Enter the message to client:" << endl;
                fgets(buf,100,stdin);
  for(i=0;i<3;i++)
  {
  client_fd[i]=accept(sockfd,(struct sockaddr*)&client_addr, &client_size);

  cout << "Accepted incoming connection" << endl;
  
	  
	  temp=send(client_fd[i],buf,strlen( buf)+1,0);
	  if(temp==-1)
    cout << "Error:not sent" << endl;
  else
    cout << "Sent " << temp << " bytes" << endl;

	  temp=recv(client_fd[i],buf,sizeof buf,0);
	  cout /*<< "Bytes received=" << temp << endl*/ << "Received data from client" << i<<"=  "<<buf << endl;
	  
	  //time_t now=time(0);
	  //char serv_msg[50];
	  //strcpy(serv_msg,ctime(&now));
	  //cout << "Current Server Time:" << serv_msg << endl;
	  
	  
	  cout << "Sent " << temp << " bytes" << endl;
	  close(client_fd[i]);
  }
  
  
  close(sockfd);

  return 0;
}
