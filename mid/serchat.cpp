#include <iostream>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>

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
	int client_fd[100];
	  	
  	struct sockaddr_in client_addr;
  	
	socklen_t client_size=sizeof client_addr;

	int i;
	

 	for(i=1;i<=4;i++)

{

  		client_fd[i]=accept(sockfd,(struct sockaddr*)&client_addr, &client_size);
		cout << "Accepted incoming connection" << endl;
 
}
	
	char buf[50],buf1[50],buf2[50];
	
	while(1)

{

  
 		recv(client_fd[1],buf,sizeof buf,0);  // receiving from client 1.
		send(client_fd[2],buf,sizeof buf,0);  // sending to client 2.  
		
		recv(client_fd[2],buf1,sizeof buf1,0); // receiving from client2.
		send(client_fd[1],buf1,sizeof buf1,0); // sending to client 1.
		
		recv(client_fd[2],buf2,sizeof buf2,0); // receiving from client2.
		
		send(client_fd[3],buf2,sizeof buf2,0); // sending to client 3
	
	
 
}
 

for(i=1;i<=3;i++)
{

  		close(client_fd[i]);
 } 		
          close(sockfd);

  return 0;
}
