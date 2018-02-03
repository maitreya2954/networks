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
#include<wait.h>


void error(char *msg)
{
perror(msg);
exit(0);
}

int main(int argc,char *argv[])
{
int i,sockfd,portno,n,k=0;
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
printf("ready to play\n\n");

int x;

while(k==0)
{
srand(time(0));
x=(rand()%100000)+1;

//printf("random x is %d\n",x);
int temp,s=0,f,sum;
sum=x;

while(sum>10)
{
f=0;
s=0;
while(sum>10)
{
temp=sum%10;
sum=sum/10;
s=temp+s;
f++;
}
s=sum+s;
sum=s;
}

int y=sum;
int z=y*9;

s=0;
sum=z;
while(sum>10)
{
f=0;
s=0;
while(sum>10)
{
temp=sum%10;
sum=sum/10;
s=temp+s;
f++;
}
s=sum+s;
sum=s;

}

int z1=sum;
//printf("\n initial z1 is %d",z1);

int ret;

//printf("no");
while(1)
{
bzero(buffer,256);
bzero(b,256);
n=read(sockfd,buffer,sizeof buffer);
int n1=read(sockfd,b,sizeof b);

if(n>0 && n1>0)
{

if((ret=strncmp("add",buffer,n-2))==0)
{
printf("\nadding %s",b);
i=atoi(b);
z1=z1+i;
}

else if((ret=strncmp("subtract",buffer,n-2))==0)
{
printf("subtracting %s",b);
i=atoi(b);
z1=z1-i;
}

else if((ret=strncmp("multiply",buffer,n-2))==0)
{
printf("multiplying %s",b);
i=atoi(b);
z1=z1*i;
}

else if((ret=strncmp("divide",buffer,n-2))==0)
{
printf("dividing with %s",b);
i=atoi(b);
z1=z1/i;
}

else if((ret=strncmp("i wish to finish game",buffer,n-2))==0)
{
i=atoi(b);
int integer=i;

break;
}

else if((ret=strncmp("end",buffer,n-2))==0)
{
k=1;
break;
}
}

else if(n==0)
break;

}

if(k==0)
{
if(z1==i)
{
printf("\nguess is right\nsend this message to c2\n");
bzero(buffer,256);
fgets(buffer,255,stdin);
write(sockfd,buffer,strlen(buffer));

}
else
{
printf("guess is wrong,value of z1 is %d\nsend this message to c2\n",z1);
bzero(buffer,256);
fgets(buffer,255,stdin);
write(sockfd,buffer,strlen(buffer));
}
}
}
close(sockfd);
return 0;
}
