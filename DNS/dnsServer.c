#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>
#include <sys/socket.h>

# define PORT 2954



int main(int argc, char const *argv[])
{
	system("clear");
	//Declaring the socket descriptor , address strutures and buffers
	int sock;
	struct sockaddr_in servaddr, clientaddr;
	char buffer[1024];
	socklen_t addr_size;


	int opt=1;

	//Assigning the protocols, ports and address to the serveraddress structure
	if ((sock=socket(PF_INET, SOCK_DGRAM, 0)) == 0)
	{
	    perror("socket failed");
	    exit(EXIT_FAILURE);
	}
	if (setsockopt(sock, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT,&opt, sizeof(opt)))
	{
	    perror("setsockopt");
	    exit(EXIT_FAILURE);
	}
	servaddr.sin_family = AF_INET;
	servaddr.sin_port = htons(PORT);
	servaddr.sin_addr.s_addr=inet_addr("127.0.0.1");
	memset(servaddr.sin_zero, '\0', sizeof servaddr.sin_zero);  //setting all files to zeros
	 //The server binds with ipaddress and port with socket
	if (bind(sock, (struct sockaddr *) &servaddr, sizeof(servaddr))<0)
    {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }
	addr_size = sizeof(clientaddr);
	while(1)
	{
		//Waits and Receives request from the Client
		recvfrom(sock, buffer, 1024, 0, (struct sockaddr *) &clientaddr, &addr_size);
		system("clear");
		printf("\n*** Received Information: %s\n", buffer);
		FILE *fp;
		char * line;
		size_t len;
		int found_flag=0;
		fp=fopen("dnslist.dns","r+");//Opening the dns record list in the server
		while (getline(&line, &len, fp)>0)//reading line by line and checking for the requested hostname
		{
			char * dup = strdup(line);
			char * dom_name = strtok(dup, " ");
			if (strcmp(dom_name,buffer)==0)//is true if the hostname is found in dns list
			{
				char new_buffer[1024];
				strcpy(new_buffer, line);
				printf("\n*** Sending Information: %s\n", new_buffer);
				sendto(sock, new_buffer, 1024, 0, (struct sockaddr *) &clientaddr, addr_size);//Sends the dns record to client
				found_flag=1;
				break;
			}
		}
		if(found_flag==0)//Is true if the server is unable to find the record
		{
			strcpy(buffer, "404 Not Found");
			sendto(sock, buffer, 1024, 0, (struct sockaddr *) &clientaddr, addr_size);//Sends the error message "404 Not Found"
		}
		printf("*** Connection Closed...\n");
	}
	return 0;
}

