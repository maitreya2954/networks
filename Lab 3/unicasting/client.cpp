
#include <bits/stdc++.h>
#include <stdio.h>
#include <iostream>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
using namespace std;


int main()
{	
	char recieved_flag[100];
	int bytesReceived = 0;
	//creating socket
	int client_socket;
	client_socket=socket(PF_INET,SOCK_STREAM,0);
	
	//setting up address of the socket
	struct sockaddr_in client_addr;
	client_addr.sin_family=PF_INET;
	client_addr.sin_port=htons(9002);
	client_addr.sin_addr.s_addr=INADDR_ANY;
	memset(client_addr.sin_zero, '\0', sizeof client_addr.sin_zero);

	//connecting 
	int client_connect_vaiable=connect(client_socket,(struct sockaddr*)&client_addr,sizeof(client_addr));
	if(client_connect_vaiable==0)
	{
		cout<<"\n=====connection established=====\n";
	}
	else
	{
		cout<<"\nXXXXXXconnnection failedXXXXXXXX\n";
		return -1;
	}
	//sending data
	
	int temp=0;
	//char client_recieved_Data[256];
	recv(client_socket,recieved_flag,sizeof(recieved_flag),0);
	
if(recieved_flag[0]=='l')
{


	FILE *fp;
	fp=fopen("sample_file.pdf","ab");
	if(NULL==fp)
	{
		cout<<"XXXXXXXXXerror opening new fileXXXXXXXX";
		return 1;
	}

	char recvBuff[256];
	
	while((bytesReceived=read(client_socket,recvBuff,256))>0)
	{
		cout<<"\nbytes recieved"<<bytesReceived<<"\n";
		fwrite(recvBuff,1,bytesReceived,fp);
	}
	if(bytesReceived<0)
	{
		cout<<"\nXXXXXREAD ERRORXXXXXXXXXXXX\n";
	}
	close(client_socket);
}
else
{
	cout<<"\nXXXXXXXXFLAG VALUE =0XXXXXXX\n";
	close(client_socket);
}

	
	return 0;
}
