#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<netdb.h>
#include<time.h>
#include<unistd.h>
#include<string.h>
#include<arpa/inet.h>


void error(char *msg)
{
perror(msg);
exit(0);
}

int z1=9;
int main(int argc,char *argv[])
{
int sockfd,portno,n,ret,n1,i,temp;
char buffer[256];
char b[256];
struct sockaddr_in serv_addr;
struct hostent *server;

if(argc<3)
{
fprintf(stderr,"usage %s hostname port\n",argv[0]);
exit(0);
}

portno=atoi(argv[2]);

sockfd=socket(AF_INET,SOCK_STREAM,0);

if(sockfd<0)
{
error("ERROR opening socket");
}

server =gethostbyname(argv[1]);
if(server==NULL)
{
fprintf(stderr,"ERROR,no such host\n");
exit(0);
}

bzero((char*)&serv_addr,sizeof(serv_addr));

serv_addr.sin_family =AF_INET;
bcopy((char*)server->h_addr,(char*)&serv_addr.sin_addr.s_addr,server->h_length);
serv_addr.sin_port=htons(portno);

if(connect(sockfd,(struct sockaddr*)&serv_addr,sizeof(serv_addr))<0)
{
error("ERROR connecting");
}
printf("connection established\n");
printf("\nenter end to exit\n");
printf("give instructions\n");

int pid=fork();

if(pid==0)
{
while(1)
{
bzero(buffer,256);
if((n=read(sockfd,buffer,sizeof buffer))>0)
{
printf("c1:%s",buffer);
if((ret=strncmp("guess is right",buffer,14))==0)
{
printf("\nenter end to exit\n");
bzero(buffer,256);
fgets(buffer,255,stdin);
n=write(sockfd,buffer,strlen(buffer));
}
else if((ret=strncmp("guess is wrong",buffer,14))==0)
{
printf("\nenter end to exit\n");
}
}
else if(n==0)
break;
}
}
else if(pid>0)
{
while(1)
{
bzero(buffer,256);
fgets(buffer,255,stdin);
n=write(sockfd,buffer,strlen(buffer));
if((ret=strncmp("i wish to finish game",buffer,21))==0)
{
printf("enter the guess value %d to c1\n",z1);
temp=1;
}
if((ret=strncmp("end",buffer,3))!=0 && temp==1)
{
z1=9;
}
bzero(b,256);
fgets(b,255,stdin);
n1=write(sockfd,b,strlen(b));

if(n>0 && n1>0)
{
if((ret=strncmp("add",buffer,n-2))==0)
{
i=atoi(b);
z1=z1+i;
}

else if((ret=strncmp("subtract",buffer,n-2))==0)
{
i=atoi(b);
z1=z1-i;
}

else if((ret=strncmp("multiply",buffer,n-2))==0)
{
i=atoi(b);
z1=z1*i;
}

else if((ret=strncmp("divide",buffer,n-2))==0)
{
i=atoi(b);
z1=z1/i;
}

}
if(n<0)
{
error("ERROR writing from socket");
}
else if(n==0)
break;

}
}

close(sockfd);
return 0;
}
