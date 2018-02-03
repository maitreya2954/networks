#include <iostream>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>
#include<unistd.h>
#include <cstdlib> 
#include <ctime>

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

  int i;

  struct sockaddr_in client_addr[10];
  socklen_t client_size[10];
  int client_fd[10];
      for(i=1;i<=4;i++)
         {
                 client_size[i]=sizeof client_addr[i];
                 client_fd[i]=accept(sockfd,(struct sockaddr*)&client_addr[i], &client_size[i]);

  cout << "Accepted incoming connection" << endl;
}


 
 int arr[100],k;
 
 srand((unsigned)time(0)); 
     
    for(int i=0; i<100; i++)
    { 
        arr[i] = (rand()%100)+1; 
         
        
    } 
            cout<<endl;
 
 int randnumber = (rand()%100)+1;
 
 int a[100],b[100],c[100],d[100],p=0,q=0,r=0,s=0;
 
      int key;
      key=arr[randnumber];
  
      k=htonl(key);


    for(i=0;i<25;i++)
      { 
        a[p]=arr[i]; 
        p++;
      }

    for(i=25;i<50;i++)
       { 
          b[q]=arr[i];
          q++;
       }

 for(i=50;i<75;i++)
      {
          c[r]=arr[i];
          r++;
      }

   for(i=75;i<100;i++)
     {
          d[s]=arr[i];
          s++;
     }

  send(client_fd[1],&a,25*sizeof(int),0);
  send(client_fd[2],&b,25*sizeof(int),0);
  send(client_fd[3],&c,25*sizeof(int),0);
  send(client_fd[4],&d,25*sizeof(int),0);
 
    for(i=1;i<=4;i++)
     {
           send(client_fd[i],&k,sizeof(int),0);

     }
char buffer1[100],buffer2[100],buffer3[100],buffer4[100];


   recv(client_fd[1],buffer1,sizeof buffer1,0);
   recv(client_fd[2],buffer2,sizeof buffer2,0);
   recv(client_fd[3],buffer3,sizeof buffer3,0);
   recv(client_fd[4],buffer4,sizeof buffer4,0);
 
  strcmp(buffer1,"yes");
 
 //comparison of each buffer sent by clients
 if((!strcmp(buffer1,"yes"))||(!strcmp(buffer2,"yes"))||(!strcmp(buffer3,"yes"))||(!strcmp(buffer4,"yes")))
       {
        cout<<"yes"<<endl<<endl; 
       }
else
      {
         cout<<"no"<<endl<<endl;
      }
  for(i=1;i<=4;i++)
     
    {
      close(client_fd[i]);
           }
  close(sockfd);

  return 0;
}
