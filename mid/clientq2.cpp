#include <iostream>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
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

 	 int buffer[100],i,tmp,k,s;;
 	 char out[10];
	
	
	strcpy(out,"no");
  
   tmp=recv(sockfd,&buffer,25*sizeof(int),0);
   
   recv(sockfd,&s,sizeof(int),0);

	k=ntohl(s);
	
	for(i=0;i<tmp-1;i++)
		{
			if(buffer[i]==k)
			{
				strcpy(out,"yes");
			break;
		}
	}
	
	send(sockfd,out,strlen(out)+1,0);	
	
	cout<<out;

  close(sockfd);
  return 0;
}
