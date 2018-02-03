#include <bits/stdc++.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <time.h>
#include <arpa/inet.h>
using namespace std;


int main()
{
	int option;
	int no_of_clients;
	int no_of_multicasting_clients;
	int to_send_clients[100];
	char sendBuff[1025];
	char send_flag[100];
	send_flag[0]='l';
    int numrv;
	//creating socket
	int server_socket;
	server_socket=socket(PF_INET,SOCK_STREAM,0);

	struct sockaddr_in server_addr;
	server_addr.sin_family=AF_INET;
	server_addr.sin_port=htons(9002);
	server_addr.sin_addr.s_addr=inet_addr("192.168.43.29");//INADDR_ANY;
	memset(server_addr.sin_zero, '\0', sizeof server_addr.sin_zero);
	int bind_variable=bind(server_socket,(struct sockaddr*)&server_addr,sizeof(server_addr));
	if(bind_variable==0)
	{
		cout<<"\n====binding sucesful====\n";
	}
	else
	{
		cout<<"\nXXXXXXXXXXXbinding failedXXXXXXXXXXX\n";
	}
	cout<<"\n======MENU==========\n";
	cout<<"\n1.unicatsing \n2.broadcasting \n3.multicasting\n";
	cin>>option;
	switch(option)
	{
		case 1:no_of_clients=1;
				no_of_multicasting_clients=1;
			break;
		case 2:cout<<"\nEnter the no_of_clients:";
			   cin>>no_of_clients;
			   no_of_multicasting_clients=no_of_clients;
			   for(int i=1;i<=no_of_multicasting_clients;i++)
			   {
			   	to_send_clients[i]=i;
			   }
			   break;
	    case 3:cout<<"\nEnter the no_of_clients:";
			   cin>>no_of_clients;
			   cout<<"\nEnter the no_of_multicasting of clients";
			   cin>>no_of_multicasting_clients;
			   for(int i=1;i<=no_of_multicasting_clients;i++)
			   {

			   	cin>>to_send_clients[i];
			   }
	}
	listen(server_socket,5);
	int client_socket[no_of_clients];
	for(int i=1;i<=no_of_clients;i++)
	{
			client_socket[i]=accept(server_socket,NULL,NULL);
				if(client_socket[i]>0)
				{
					cout<<"\n======connection accepted==========\n";
				}
				else
				{
					cout<<"\nXXXXXXXconnection failureXXXXXXX\n";
				}
	}
	for(int i=1;i<=no_of_clients;i++)
	{
		int flag=0;
		for(int k=1;k<=no_of_multicasting_clients;k++)
			{
				if(to_send_clients[k]==i)
				{
					flag=1;
					break;
				}
			}
		if(flag==1||no_of_clients==1)
		{
			int server_send_variable=send(client_socket[i],send_flag,sizeof(send_flag),0);
				if(server_send_variable!=0)
				{
					cout<<"\n====flag sent sucessfully======\n";
				}
				else
					cout<<"\nXXXXXXflag sending failedXXXXXXXXX\n";		
			
			
				/* Open the file that we wish to transfer */
				FILE *fp=fopen("server1.cpp","rb");
				if(fp==NULL)
				{
					cout<<"\nXXXXXFILE OPEN ERRORXXXXXX\n";
					return 1;
				}
				/* Read data from file and send it */
				while(1)
				{
					unsigned char buff[256]={0};
					int nread =fread(buff,1,256,fp);
					cout<<"\nBYTES READ:"<<nread;
					if(nread>0)
					{
						cout<<"\n=====SENDING========\n";
						write(client_socket[i],buff,nread);
					}
					if(nread<256)
					{
						if(feof(fp))
							cout<<"\n=====END OF FILE======\n";
						if(ferror(fp))
							cout<<"\nXXXXXXERROE READING\n";
						break;
					}
				}
				close(client_socket[i]);
			
		}
	}

	
	close(server_socket);
	return 0;
}
