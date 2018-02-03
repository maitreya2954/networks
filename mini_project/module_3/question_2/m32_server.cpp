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
  
  	
	int client_fd[2];
	int i;
	

	for(i=1;i<=2;i++)
	{
		struct sockaddr_in client_addr;

  		socklen_t client_size=sizeof client_addr;
  		
		client_fd[i]=accept(sockfd,(struct sockaddr*)&client_addr, &client_size);

		if(client_fd[i]!=-1)
			cout<<"connection established with client"<<i<<endl;		

	}

  	cout << "Accepted incoming connection" << endl;
 
  	char buf[50];
  
  	temp=recv(client_fd[1],buf,sizeof buf,0);		//receiving message from client1
  	cout<< "Received data from client1=" << buf << endl;
  
 

 
 	temp=send(client_fd[2],buf,sizeof buf,0);		//sending message to client2
  	cout << "Sent " << temp << " bytes" << endl;




	char buf2[500];

  
  	temp=recv(client_fd[2],buf2,sizeof buf2,0);
  	cout<< "Received data from client2=" << buf2 << endl;


  	temp=send(client_fd[1],buf2,sizeof buf2,0);
  	cout << "Sent " << temp << " bytes" << endl;
	

	int num;

	
	for(num=0;num<32768;num++)
	{ 

		int arr_in[6][6],arr_out[6][6];

  
 		recv(client_fd[1],arr_in,sizeof(int)*6*6,0);	//receiving adjecency matrix from client1

        	cout << "Received data from client1:"<<endl;
        
		for(i=0;i<6;i++)
	 	{
	            	for(int j=0;j<6;j++) 
			{
	                	cout<<arr_in[i][j]<< "  ";
	            	}
			cout<<endl;
	        }

	        cout<<endl<<endl;
	       
		cout<<"sending..... "<<num+1<<"th data to client2"<<endl;


        	memcpy(arr_out,arr_in,sizeof(int)*6*6);		//sending adjecency matrix to client2
  
      		if (send(client_fd[2],arr_out,sizeof(int)*6*6,0)<0)
        		cerr << "Error: cannot send modified data";
  
      		
		memset(arr_out,0x0,sizeof(int)*6*6);

		
		char buf1[500];

		recv(client_fd[2],buf1,sizeof(buf1),0);		//receiving acknoledgement from client2

		send(client_fd[1],buf1,strlen(buf1)+1,0);	//sending acknoledgement to client1




	}


  	close(client_fd[1]);
  	close(client_fd[2]);
   
  	close(sockfd);

  	return 0;
}
