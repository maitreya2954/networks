#include <iostream>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>
#include<fstream>

using namespace std;

int main(int argc,char* argv[])
{
  if(argc !=2)
    {
      cerr << "Usage syntax: ./server <port_no>" << endl;
      return 0;
    }
  int sockfd;
  char buf[50],integer[100];
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
        int client_fd[10];
  listen(sockfd,10);
  int m;
  int multi[10];
  cout<<"Enter no.of connections\n";
  cin>>m;
  for(int i=0;i<m;i++)
  {
        cin>>multi[i];
  }
  struct sockaddr_in client_addr;
 	 socklen_t client_size=sizeof client_addr;
  for(int i=0;i<6;i++)
  {
 	 
 	 client_fd[i]=accept(sockfd,(struct sockaddr*)&client_addr, &client_size);
	
	 cout << "Accepted incoming connection" << endl;
 }
	
  	 char sendbuff[1000];
  	 char f[10];
  	 f[0]='s';
	 for(int i=0;i<6;i++)
        {
         for(int j=0;j<6;j++)
        {
        if(i==multi[j])
        {
	 
	
         send(client_fd[i], f,sizeof f,0);
	 FILE *myfile;
  	myfile=fopen("1.pdf","rb");
	while(!feof(myfile))
	{
	 //cout<<"/";
	  fread(sendbuff,sizeof sendbuff,1,myfile);
	  send(client_fd[i], sendbuff,sizeof sendbuff,0);
	}
	send(client_fd[i],"xyz", 4, 0); 
  
        }
       
        
        }
         close(client_fd[i]);
        }
        
  close(sockfd);

  return 0;
}




