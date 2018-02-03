#include <stdio.h>
#include <sys/socket.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#define PORT 2127


int getit(int socket,char buffer[])
{
	char * dup =strdup(buffer);
	char * p= strtok(dup," ");
	if (strcmp(p,"GET")==0)
	{
		p = strtok(NULL, " ");
		if (strcmp(p,"/")==0)//True if it is a request for index.html and this block of the code sends
		{					 //sends the HTTP response message for index.html which is present working directory
			char httpindex[1024]="HTTP/1.1 200 OK\r\nDate: Mon, 27 Jul 2009 12:28:53 GMT\r\nServer: Apache/2.2.14 (Win32)\r\nLast-Modified: Wed, 22 Jul 2009 19:15:56 GMT\r\nContent-Length: 8000\r\nContent-Type: */*\r\nConnection: Closed\r\n\r\n";
			FILE *fp;
			char * line= NULL;
			size_t len=0;
			printf("*** Sending index.html ... \n");
			fp=fopen("index.html","r+");
			printf("%s\n", httpindex);

			//Sending of the response starts here
	        send(socket, httpindex, strlen(httpindex), 0);
			while ((getline(&line, &len, fp)) != -1) {
	        	printf("%s", line);
	        	send(socket, line, strlen(line), 0);
	        }
	        fclose(fp);
	        return 0;	
		}
		else//if the client request anything apart from index.html is sent by this else block
		{
			printf("*** Sending ...\n");
			char httpindex[1024]="HTTP/1.1 200 OK\r\nDate: Mon, 27 Jul 2009 12:28:53 GMT\r\nServer: Apache/2.2.14 (Win32)\r\nLast-Modified: Wed, 22 Jul 2009 19:15:56 GMT\r\nContent-Length: 15000\r\nContent-Type: */*\r\nConnection: Closed\r\n\r\n";
			FILE *fp;
			char * line= NULL;
			size_t len=0;
			char filepath[250]=".";
			strcat(filepath,p);
			fp=fopen(filepath,"r+");
			if(fp==NULL)//file pointer will be NULL only if there is no such file existing in server
			{			//so a ERROR Message is returned
				char http[200]="HTTP/1.1 404 Not Found\r\nConnection: Closed\r\n\r\n<html><head><title>Not Found</title></head><body><h1>404: Not Found</h1></body></html>";
				printf("%s\n", http);
				send(socket, http, strlen(http), 0);
				return 0;
			}
			//Sending of the response starts here
			printf("%s\n", httpindex);
	        send(socket, httpindex, strlen(httpindex), 0);
			while ((getline(&line, &len, fp)) != -1) {
	        	send(socket, line, strlen(line), 0);
	        	printf("%s", line);
	        }
	        fclose(fp);
	        return 0;		
		}
		
	}
	return 1;
}

int main(int argc, char const *argv[])
{
	pid_t pid=fork();
	if (pid==0)
	{
		sleep(1);
		int server_fd, new_socket, valread;
	    struct sockaddr_in address;
	    int opt = 1;
	    int addrlen = sizeof(address);
	    char buffer[1024] = {0}; 
	    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0)
	    {
	        perror("socket failed");
	        exit(EXIT_FAILURE);
	    }
	    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt)))
	    {
	        perror("setsockopt");
	        exit(EXIT_FAILURE);
	    }
	    address.sin_family = AF_INET;
	    address.sin_addr.s_addr = inet_addr("127.0.0.1");
	    address.sin_port = htons( PORT );
	    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address))<0)
	    {
	        perror("bind failed");
	        exit(EXIT_FAILURE);
	    }
	    if (listen(server_fd, 3) < 0)
	    {
	        perror("listen");
	        exit(EXIT_FAILURE);
	    }
	    for ( ; ; )
	    {
		    if ((new_socket = accept(server_fd, (struct sockaddr *)&address, 
		                       (socklen_t*)&addrlen))<0)
		    {
		        perror("accept");
		        exit(EXIT_FAILURE);
		    }
		    valread = read( new_socket , buffer, 1024);
		    printf("%s\n", buffer);
		    if (getit(new_socket, buffer))
		    {
		    	printf("Sending Failed\n");
		    }
		    else
		    {
		    	printf("**************************Sending Successfull************************\n");
		    }
	    }
	    return 0;
	}
	else if(pid>0)
       	return 0;
}
