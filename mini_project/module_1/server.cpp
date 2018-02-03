#include <iostream>

#include <sys/types.h>

#include <sys/socket.h>

#include <netinet/in.h>

#include <arpa/inet.h>

#include <unistd.h>

#include <string.h>

#include <time.h>

#include <stdlib.h>

#include <cstdlib>

#include <errno.h>

#include <stdio.h>

#include <fstream>

using namespace std;

int main(int argc,char* argv[])

{

  if(argc !=1)

    {

      cerr << "Usage syntax: ./server <port_no>" << endl;

      return 0;

    }

int num_port=8,temp;

int port[10]={3100,3200,3300,3400,3500,3600,3700,3800};

int sockfd[20];

struct sockaddr_in my_addr[20];

for(int i=0;i<num_port;i++)

  {
	
	sockfd[i]=socket(PF_INET,SOCK_STREAM,0);  //Creating the socket

	my_addr[i].sin_family=AF_INET;

	my_addr[i].sin_port=htons(port[i]);

	my_addr[i].sin_addr.s_addr=INADDR_ANY;

	memset(my_addr[i].sin_zero, 0, sizeof my_addr[i].sin_zero);

	temp=bind(sockfd[i], (struct sockaddr *)&my_addr[i], (sizeof my_addr[i])); //Binding the socket to the address

	if(temp==0)

		cout << "Server started running at "<< inet_ntoa(my_addr[i].sin_addr)  << ":" << port[i] << endl;

	else

		{

		      cout << "Failed to bind socket" << endl;
 
		     return -1;
  
		}

	listen(sockfd[i],10); //listening through specific sockfd

  }


  struct sockaddr_in client_addr;

  int client_fd,clientfd_7,clientfd_t,clientfd_8,num;
  
  char buf[100],rec_data[100];

  int array[100],port_t[100],count=0,t_port;
  
  socklen_t client_size=sizeof client_addr;


  for(num=0;num<6;num++)

	{

		cout<<"Enter port number to client "<<num+1<<" to connect"<<endl;

		cin>>t_port;

		port_t[num]=t_port+1;

		client_fd=accept(sockfd[t_port],(struct sockaddr*)&client_addr,&client_size);

		cout << "Accepted incoming connection" << endl;

	        cout<<"client:"<<client_fd<<endl;

		array[num]=client_fd;

	}
		
			  client_fd=accept(sockfd[4],(struct sockaddr*)&client_addr, &client_size);

			  cout<<inet_ntoa(client_addr.sin_addr);

			  cout << "Accepted incoming connection" << endl;

			  cout<<"client:"<<client_fd<<endl;

			  port_t[num]=5;			

			  array[num++]=client_fd;


      			  client_fd=accept(sockfd[7],(struct sockaddr*)&client_addr, &client_size);

  			  cout<<inet_ntoa(client_addr.sin_addr);

  			  cout << "Accepted incoming connection" << endl;

  			  cout<<"client:"<<client_fd<<endl;
				
			  port_t[num]=8;

			  array[num]=client_fd;

	int t,te[5],i,ver[5],array1[50];
 	
	char ack[50];

	srand(time(0));		
	
	te[0]=rand()%8;

	while(te[0]==6)

	  {

		srand(time(0));

		te[0]=rand()%8;		

	  }
		

    	cout<<"random number: "<<te[0]<<endl;
te[0]=7;
	t=te[0];

	temp=send(array[6],te,5*sizeof(te),0);


ofstream outfile("text_file.txt",ios::trunc);

if(t!=7)

  {

	strcpy(ack,"chat soon");

	int tt[5];

	srand(time(0));

	tt[0]=rand()%15+1;

	cout<<"sended number: "<<tt[0]<<endl;

     for(i=0;i<7;i++)

       {

	  if(i==t)

		{

			temp=send(array[i],tt,5*sizeof(tt),0);

			if(port_t[t]==2)	

			  {

				temp=recv(array[t],ver,5*sizeof(int),0);

				cout<<"factorial of "<<tt[0]<<" is: "<<ver[0]<<endl;

			  }


			if(port_t[t]==1)


			  {

				temp=recv(array[t],array1,50*sizeof(int),0);

				cout<<"fibonacci series of "<<tt[0]<<" is : ";

				for(int g=0;g<tt[0];g++)

					cout<<array1[g]<<"\t";

			  }


			else if(port_t[t]==3 || port_t[t]==4)		

			  {

				temp=recv(array[t],rec_data,sizeof rec_data,0);

				cout<<"Received :"<<rec_data<<endl;

			  }

			else if(port_t[t]==5)

				temp=send(array[t],te,5*sizeof(t),0);

		}
		
	  else if(i==6)

		{

			temp=send(array[6],ack,sizeof ack,0);

		}

	}

     
     clientfd_7=accept(sockfd[5],(struct sockaddr*)&client_addr, &client_size);

	cout<<inet_ntoa(client_addr.sin_addr);

  	cout << "Accepted incoming connection" << endl;

  	cout<<"client:"<<clientfd_7<<endl;

     clientfd_t=accept(sockfd[5],(struct sockaddr*)&client_addr, &client_size);

	cout<<inet_ntoa(client_addr.sin_addr);

  	cout << "Accepted incoming connection" << endl;

  	cout<<"client:"<<clientfd_t<<endl;

     int var=0;

     while(var!=9)

	{

	  cout<<"Enter the client number which client want to send else '9' to exit"<<endl;

	  cin>>var;

	  if(var==7)
	
            {

			temp = recv(clientfd_7,rec_data,sizeof rec_data,0);		//receiving data from client

	 		cout  << "Received data from client=" << rec_data << endl;

			cout << "Received " << temp << " bytes" << endl;

			temp = send(clientfd_t,rec_data,strlen(rec_data)+1,0);		//send data to client

			cout << "sent " << temp << " bytes" << endl;

            }

	  else if(var==t)

            {

			temp = recv(clientfd_t,buf,sizeof buf,0);		//receiving data from client

 			cout  << "Received data from client=" << buf << endl;

			cout << "Received " << temp << " bytes" << endl;
  
			temp = send(clientfd_7,buf,strlen(buf)+1,0);		//send data to client

			cout << "sent " << temp << " bytes" << endl;

	    }

	}

	rec_data[0]='b';

	send(clientfd_7,rec_data,sizeof rec_data,0);

	send(clientfd_t,rec_data,sizeof rec_data,0);

  }
	
else if(t==7)

  {

     strcpy(ack,"chat soon");

     temp=send(array[6],ack,sizeof ack,0);

     temp=send(array[7],ack,sizeof ack,0);

     clientfd_7=accept(sockfd[5],(struct sockaddr*)&client_addr, &client_size);

	cout<<inet_ntoa(client_addr.sin_addr);

  	cout << "Accepted incoming connection" << endl;

  	cout<<"client:"<<clientfd_7<<endl;

     clientfd_8=accept(sockfd[5],(struct sockaddr*)&client_addr, &client_size);

	cout<<inet_ntoa(client_addr.sin_addr);

  	cout << "Accepted incoming connection" << endl;

  	cout<<"client:"<<clientfd_8<<endl;

     int var=0;

     while(var!=9)

	{

	  cout<<"Enter the client number which client want to send else '9' to exit"<<endl;

	  cin>>var;

	  if(var==7)
	
            {

			temp = recv(clientfd_7,rec_data,sizeof rec_data,0);		//receiving data from client

	 		cout  << "Received data from client=" << rec_data << endl;

			cout << "Received " << temp << " bytes" << endl;

			outfile<<rec_data<<endl;

			temp = send(clientfd_8,rec_data,strlen(rec_data)+1,0);		//send data to client

			cout << "sent " << temp << " bytes" << endl;

            }

	  else if(var==8)

            {

			temp = recv(clientfd_8,buf,sizeof buf,0);		//receiving data from client

 			cout  << "Received data from client=" << buf << endl;

			cout << "Received " << temp << " bytes" << endl;

			outfile<<buf<<endl;

			temp = send(clientfd_7,buf,strlen(buf)+1,0);		//send data to client

			cout << "sent " << temp << " bytes" << endl;

	    }

	}

	outfile.close();

	rec_data[0]='b';

	send(clientfd_7,rec_data,sizeof rec_data,0);

	send(clientfd_8,rec_data,sizeof rec_data,0);

	
	clientfd_7=accept(sockfd[6],(struct sockaddr*)&client_addr, &client_size);

	cout<<inet_ntoa(client_addr.sin_addr);

  	cout << "Accepted incoming connection" << endl;

  	cout<<"client:"<<clientfd_7<<endl;

	clientfd_8=accept(sockfd[6],(struct sockaddr*)&client_addr, &client_size);

	cout<<inet_ntoa(client_addr.sin_addr);

  	cout << "Accepted incoming connection" << endl;

  	cout<<"client:"<<clientfd_8<<endl;


  }

    if(t==7)
      
     {

	char buffer[256];

        FILE *fp = fopen("text_file.txt","rt");

        if(fp==NULL)

        	{

            		cout<<"File open error";

            		return 1;   

        	}   


        while(1)

	  {

            unsigned char buff[256]={0};

            int nread = fread(buff,1,256,fp);

            cout<<"Bytes read"<< nread;        


          if(nread > 0)

            {

                cout<<"Sending \n";

                int tee1=write(clientfd_7, buff, nread);

		cout<<"send1:"<<tee1<<"bytes\n";

		int tee2=write(clientfd_8, buff, nread);		

		cout<<"send1:"<<tee2<<"bytes\n";

            }

           if (nread < 256)

            {

                if (feof(fp))

                    cout<<"End of file\n";

                if (ferror(fp))

                    cout<<"Error reading\n";

                break;

            }

	}

   }


	

for(int j=0;j<num;j++)

  close(array[j]);

for(int j=0;j<num_port;j++)

  close(sockfd[j]);

  close(clientfd_7);

	if(t!=7)

		close(clientfd_t);

	else if(t==7)

		close(clientfd_8);

return 0;

}
