#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>
#include <sys/socket.h>

# define PORT 2954

int print_dnslist(char buffer[], int found)
{
	char * dup = strdup(buffer);
	char * p = strtok(dup, " ");//tokenize the buffer with respect to "<space>"
	if(strcmp(p,"404")==0)
	{
		printf("***\nERROR: Hostname not found\n***\n");
		return -1;
	}
	if (found==0)//if the dns record is not found in the local dns list and Error messages are not inserted
	{
		FILE *clientlist;
		clientlist=fopen("clientlist.dns","a");
		fprintf(clientlist, "%s", buffer);
		fclose(clientlist);
	}
	printf("Ip Addresses for %s are\n", p);
	p = strtok(NULL, ",");//tokenize the buffer with respect to ","
	int i=1;
	while(p!=NULL)
	{
		printf("%d. %s\n", i, p);
		p=strtok(NULL, ",");
		i++;
	}
	
	return 0;
}
int main(int argc, char const *argv[])
{
	system("clear");
	if(argc!=3)//Exits if the # of arguments are not equal to 3
	{
		printf("\n\nUsage: ./Client 127.0.0.1 [hostname without 'www.']\n");
		exit(1);
	}
	int sock,nBytes;
	struct sockaddr_in servaddr;
	char buffer[1024];
	socklen_t addr_size;
	//Creating a socket and assigning the protocols and port numbers
	sock=socket(PF_INET, SOCK_DGRAM, 0);
	servaddr.sin_family = AF_INET;
	servaddr.sin_port = htons(PORT);
	addr_size = sizeof servaddr;
	//Opening the dns list in local machine
	FILE *clientlist;
	clientlist=fopen("clientlist.dns","r+");
	char * line=NULL;
	size_t len=0;
	int found=0;

	//reading the local host's dns file line by line
	while((getline(&line, &len, clientlist))!=-1)
	{
		char * dup = strdup(line);
		char * p = strtok(dup," ");//tokenizing the line with respect to white space
		if (strcmp(argv[2], p)==0)//if the domain name given in command arguement found in file "clientlist" 
		{
			found=1;//make found flag = 1 
			printf("Found in local host...\n\n");
			strcpy(buffer,line);
			break;
		}
	}
	fclose(clientlist);
	//Searching in local machine's dns list is completed

	if (!found)// Is true only if the domain name is not found in local host dns list
	{
		printf("Not found in local host...\nQuerying DNS Server with IP Address %s ...\n",argv[1]);
		servaddr.sin_addr.s_addr=inet_addr(argv[1]);//specify the server address
		strcpy(buffer, argv[2]);//put domain name given in argument to buffer
	    nBytes = strlen(buffer) + 1;
	    printf("*** Sending Information: %s\n", buffer);
	    sendto(sock, buffer, nBytes, 0, (struct sockaddr *) &servaddr, addr_size); //Sending Information
	    nBytes = recvfrom(sock, buffer, 1024, 0, (struct sockaddr *) &servaddr, &addr_size);//Receiving Information
	    printf("\n*** Received Information: %s\n", buffer);
	}  
	print_dnslist(buffer, found);//Print the received buffer in readeable manner and found is also passed to prevent
								 //insertion of Error messages like "404 Not Found" into the local dns list

	return 0;
}