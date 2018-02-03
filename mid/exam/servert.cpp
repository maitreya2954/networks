#include <iostream>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <thread>
#include <unistd.h>
#include <fstream>
int thread_fib(); 
int thread_fac();
int thread_prime();
int thread_perfect();
int thread_rand(int i);

int result1,result2;
int check_prime(int);
int perfect_square(int);

using namespace std;

int main(int argc,char* argv[])
{
  	int sockfd[100];
  	int temp[100];
   	int i=1;
   	thread t1(thread_fib); 
 	thread t2(thread_fac);
  	thread t3(thread_prime);
  	thread t4(thread_perfect);
  	thread t5(thread_rand,i);
  	t1.join();
  	t2.join();
  	t3.join();
  	t4.join();
  	t5.join();

  return 0;
}

int thread_fib()
{
	int sockfd;
  	struct sockaddr_in my_addr;
	int i;
	int fib[100];
  	sockfd=socket(PF_INET,SOCK_STREAM,0);  //Creating the socket

  	my_addr.sin_family=AF_INET;
  	my_addr.sin_port=htons(atoi("3100"));
  	my_addr.sin_addr.s_addr=INADDR_ANY;
  	memset(my_addr.sin_zero, '\0', sizeof my_addr.sin_zero);

  	int temp=bind(sockfd, (struct sockaddr *)&my_addr, (sizeof my_addr)); //Binding the socket to the address

  	if(temp==0)
  	  cout << "\nServer started running at "<< inet_ntoa(my_addr.sin_addr)  << ":" <<" 3100 "<< endl;
  	else
  	{
   	   	cout << "\nFailed to bind socket" << endl;
      	return -1;
    }
    
    listen(sockfd,10);
	int client_fd;
	struct sockaddr_in client_addr;
  	socklen_t client_size=sizeof client_addr;
	
  	client_fd=accept(sockfd,(struct sockaddr*)&client_addr, &client_size);
	cout << "\nAccepted incoming connection 3100" << endl;
	
	int n;
 	temp=recv(client_fd,&n,sizeof(int),0);
    fib[0]=0;
    fib[1]=1;
    
    for(i = 2; i <= n; i++)
	{
    	fib[i]=fib[i-1]+fib[i-2];
	}

 	for(i = 0; i <= n; i++)
 	{
        cout<<fib[i]<<endl; 
	}

	int k;
	for(i=0;i<=n;i++)
	{	
		k=fib[i];
		temp = send(client_fd,&k,sizeof(int),0);
	}
 	close(client_fd);

}




int thread_fac()
{
	int sockfd;
  	struct sockaddr_in my_addr;

  	sockfd=socket(PF_INET,SOCK_STREAM,0);  //Creating the socket

  	my_addr.sin_family=AF_INET;
  	my_addr.sin_port=htons(atoi("3200"));
  	my_addr.sin_addr.s_addr=INADDR_ANY;
  	memset(my_addr.sin_zero, '\0', sizeof my_addr.sin_zero);

  	int temp=bind(sockfd, (struct sockaddr *)&my_addr, (sizeof my_addr)); //Binding the socket to the address

  	if(temp==0)
  	  cout << "\nServer started running at "<< inet_ntoa(my_addr.sin_addr)  << " :" <<" 3200"<< endl;
  	else
  	{
   	   	cout << "\nFailed to bind socket" << endl;
      	return -1;
    }
    
    listen(sockfd,10);
	int client_fd;
	struct sockaddr_in client_addr;
  	socklen_t client_size=sizeof client_addr;
	
  	client_fd=accept(sockfd,(struct sockaddr*)&client_addr, &client_size);
	cout << "Accepted incoming connection 3200 " << endl;
	int factorial=1;
	int n;
	temp=recv(client_fd,&n,sizeof(int),0);
	int i,j,p;
	for(i=1;i<=n;++i)
    {
            factorial=factorial*i;              // factorial = factorial*i;
    }
    printf("\nFactorial of %d = %d", n, factorial);

	temp=send(client_fd,&factorial,sizeof(int),0);
 	close(client_fd);

}

 
int thread_prime()
{
	int sockfd;
  	struct sockaddr_in my_addr;

  	sockfd=socket(PF_INET,SOCK_STREAM,0);  //Creating the socket

  	my_addr.sin_family=AF_INET;
  	my_addr.sin_port=htons(atoi("3300"));
  	my_addr.sin_addr.s_addr=INADDR_ANY;
  	memset(my_addr.sin_zero, '\0', sizeof my_addr.sin_zero);

  	int temp=bind(sockfd, (struct sockaddr *)&my_addr, (sizeof my_addr)); //Binding the socket to the address

  	if(temp==0)
  	  cout << "\nServer started running at "<< inet_ntoa(my_addr.sin_addr)  << ":" <<" 3300"<< endl;
  	else
  	{
   	   	cout << "Failed to bind socket" << endl;
      	return -1;
    }
    
    listen(sockfd,10);
	int client_fd;
	struct sockaddr_in client_addr;
  	socklen_t client_size=sizeof client_addr;
	
  	client_fd=accept(sockfd,(struct sockaddr*)&client_addr, &client_size);
	cout << "\nAccepted incoming connection 3300" << endl;
	
  	int number,k;
  	recv(client_fd,&number,sizeof(int),0);
  	cout<<"\nnumber received is "<<number;
  	result1 = check_prime(number); // prime function..
  	if(result1==1)
	{
		cout<<"\nThe number is prime"<<endl;
	
	}

	else
	{
	 	cout<<"\nThe number is not prime"<<endl;
	}

	send(client_fd,&result1,sizeof(int),0);
	close(client_fd);
}

int thread_perfect()
{
	int sockfd;
  	struct sockaddr_in my_addr;

  	sockfd=socket(PF_INET,SOCK_STREAM,0);  //Creating the socket

  	my_addr.sin_family=AF_INET;
  	my_addr.sin_port=htons(atoi("3400"));
  	my_addr.sin_addr.s_addr=INADDR_ANY;
  	memset(my_addr.sin_zero, '\0', sizeof my_addr.sin_zero);

  	int temp=bind(sockfd, (struct sockaddr *)&my_addr, (sizeof my_addr)); //Binding the socket to the address

  	if(temp==0)
  	  cout << "\nServer started running at "<< inet_ntoa(my_addr.sin_addr)  << ":" << " 3400" << endl;
  	else
  	{
   	   	cout << "\nFailed to bind socket" << endl;
      	return -1;
    }
    
    listen(sockfd,10);
	int client_fd;
	struct sockaddr_in client_addr;
  	socklen_t client_size=sizeof client_addr;
	
  	client_fd=accept(sockfd,(struct sockaddr*)&client_addr, &client_size);
	cout << "\nAccepted incoming connection 3400" << endl;
	
	int num;
 	recv(client_fd,&num,sizeof(int),0);
  	cout<<"\nnumber received is "<<num;
  	result2 = perfect_square(num);
     if (result2==1)
   	 {
     	cout<<"\nperferct square"<<endl;
   	 }
     else
     {
         cout<<"\nnot perfect square"<<endl;
     }
	send(client_fd,&result2,sizeof(int),0);
	close(client_fd);
 
}

int thread_rand(int y)
{
	int client_fd[100];	
			
    			
	int sockfd1;
  	struct sockaddr_in my_addr1;

  	sockfd1=socket(PF_INET,SOCK_STREAM,0);  //Creating the socket

  	my_addr1.sin_family=AF_INET;
  	my_addr1.sin_port=htons(atoi("3800"));
  	my_addr1.sin_addr.s_addr=INADDR_ANY;
  	memset(my_addr1.sin_zero, '\0', sizeof my_addr1.sin_zero);

  	int temp1=bind(sockfd1, (struct sockaddr *)&my_addr1, (sizeof my_addr1)); //Binding the socket to the address

  	if(temp1==0)
  	  cout << "\nServer started running at "<< inet_ntoa(my_addr1.sin_addr)  << ":" << " 3800 " << endl;
  	else
  	{
   	   	cout << "\nFailed to bind socket" << endl;
      	return -1;
    }
    listen(sockfd1,10);
	struct sockaddr_in client_addr1;
  	socklen_t client_size1=sizeof client_addr1;
  	int i;
  	for(i=1;i<=6;i++)
  	{
  		client_fd[i]=accept(sockfd1,(struct sockaddr*)&client_addr1, &client_size1);
		cout << "\nAccepted incoming connection" << endl;
	}
	client_fd[8]=accept(sockfd1,(struct sockaddr*)&client_addr1, &client_size1);
	cout << "\nAccepted incoming connection" << endl;
	int sockfd2;
  	struct sockaddr_in my_addr2;

  	sockfd2=socket(PF_INET,SOCK_STREAM,0);  //Creating the socket

  	my_addr2.sin_family=AF_INET;
  	my_addr2.sin_port=htons(atoi("3500"));
  	my_addr2.sin_addr.s_addr=INADDR_ANY;
  	memset(my_addr2.sin_zero, '\0', sizeof my_addr2.sin_zero);
    
  	int temp2=bind(sockfd2, (struct sockaddr *)&my_addr2, (sizeof my_addr2)); //Binding the socket to the address
    
  	if(temp2==0)
  	  cout << "\nServer started running at "<< inet_ntoa(my_addr2.sin_addr)  << ":" << " 3500 " << endl;
  	else
  	{
   	   	cout << "\nFailed to bind socket" << endl;
      	return -1;
    }
    listen(sockfd2,10);
	struct sockaddr_in client_addr2;
  	socklen_t client_size2=sizeof client_addr2;
  	client_fd[7]=accept(sockfd2,(struct sockaddr*)&client_addr2, &client_size2);
	cout << "\nAccepted incoming connection" << endl;
	int random,ch;

 	time_t timer;
	srand((unsigned) time(&timer));
	while(ch)
	{

  		random=rand()%8;

  			if(random+1 == 7)

		{
   			ch=1;
		}

 			else
		{
			ch=0;
		}

	}
 	//recv(client_fd[7],&x,sizeof(int),0);
 	cout<<"Value of random is "<<random<<endl;
 	int start=1;
 	send(client_fd[random+1],&start,sizeof(int),0);
 	send(client_fd[7],&start,sizeof(int),0);
 	
 	
 	/*close(client_fd[7]);
 	close(client_fd[x]);*/
 	
    int sockfd3;
	struct sockaddr_in my_addr3;
	sockfd3=socket(PF_INET,SOCK_STREAM,0);  //Creating the socket

  	my_addr3.sin_family=AF_INET;
  	my_addr3.sin_port=htons(atoi("3600"));
  	my_addr3.sin_addr.s_addr=INADDR_ANY;
  	memset(my_addr3.sin_zero, '\0', sizeof my_addr3.sin_zero);
	
  	int temp3=bind(sockfd3, (struct sockaddr *)&my_addr3, (sizeof my_addr3)); //Binding the socket to the address

  	if(temp3==0)
  	  cout << "\nServer started running at "<< inet_ntoa(my_addr3.sin_addr)  << ":" << " 3600 " << endl;
  	else
  	{
   	   	cout << "\nFailed to bind socket" << endl;
      	return -1;
    }
    
    listen(sockfd3,10);
    y=sockfd3;
	struct sockaddr_in client_addr3;
  	socklen_t client_size3=sizeof client_addr3;
  	client_fd[7]=accept(sockfd3,(struct sockaddr*)&client_addr3,&client_size3);
  	cout << "\nAccepted incoming connection" << endl;
  	listen(y,10);
  	client_fd[random+1]=accept(sockfd3,(struct sockaddr*)&client_addr3,&client_size3);
	cout << "\nAccepted incoming connection" << endl;
 	char rec_msg[100];
 	char buf[100];
 	int x1=client_fd[7];
 	int x2=client_fd[random+1];
 	ofstream infile("chat.txt");
 	while(1)
 	{
 		
		recv(x1,rec_msg,sizeof rec_msg,0);
		infile<<"\nclient 7 : "<<rec_msg<<endl;
		send(x2,rec_msg,sizeof rec_msg,0);
		recv(x2,buf,sizeof buf,0);
		infile<<"\nclient random : "<<buf<<endl;
		send(x1,buf,sizeof buf,0);
		if(!strcmp(buf,"bye"))
			break;
	}
	infile.close();
	int s=1;
	send(client_fd[7],&s,sizeof(int),0);
 	send(client_fd[random+1],&s,sizeof(int),0);	
	
	int sockfd4;
  	struct sockaddr_in my_addr4;

  	sockfd4=socket(PF_INET,SOCK_STREAM,0);  //Creating the socket

  	my_addr4.sin_family=AF_INET;
  	my_addr4.sin_port=htons(atoi("3700"));
  	my_addr4.sin_addr.s_addr=INADDR_ANY;
  	memset(my_addr4.sin_zero, '\0', sizeof my_addr4.sin_zero);
    
  	int temp4=bind(sockfd4, (struct sockaddr *)&my_addr4, (sizeof my_addr4)); //Binding the socket to the address
    
  	if(temp4==0)
  	  cout << "\nServer started running at "<< inet_ntoa(my_addr4.sin_addr)  << ":" << " 3700 " << endl;
  	else
  	{
   	   	cout << "\nFailed to bind socket" << endl;
      	return -1;
    }
    
   
    listen(sockfd4,10);
	struct sockaddr_in client_addr4;
  	socklen_t client_size4=sizeof client_addr4;
	FILE *fr1;
	fr1= fopen("chat.txt","rt");
	client_fd[7]=accept(sockfd4,(struct sockaddr*)&client_addr4, &client_size4);
	cout << "\nAccepted incoming connection 7" << endl;
	client_fd[random+1]=accept(sockfd4,(struct sockaddr*)&client_addr4, &client_size4);
	cout << "\nAccepted incoming connection x" << endl;
	char sendbuff[100];
	FILE *fp1;
	fp1 = fopen("chat.txt","rb");
	while(1)
	{
		unsigned char buff[256]={0};
		int nread =fread(buff,1,256,fp1);
		cout<<"\nBYTES READ:"<<nread;
		if(nread>0)
		{
			cout<<"\n=====SENDING========\n";
			write(client_fd[7],buff,nread);
			//write(client_fd[x],buff,nread);
		}
		if(nread<256)
		{
			if(feof(fp1))
				cout<<"\n=====END OF FILE======\n";
			if(ferror(fp1))
				cout<<"\nXXXXXXERROE READING\n";
			break;
		}
	}	
	fclose(fp1);
	FILE *fp;
	fp = fopen("chat.txt","rb");
	
	while(1)
	{
		unsigned char buff[256]={0};
		int nread =fread(buff,1,256,fp);
		cout<<"\nBYTES READ:"<<nread;
		if(nread>0)
		{
			cout<<"\n=====SENDING========\n";
			//write(client_fd[7],buff,nread);
			write(client_fd[random+1],buff,nread);
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
		
	fclose(fp);

	for(i=1;i<=8;i++)	
	{
	close(client_fd[i]);
	}

	
	
}

int check_prime(int a)
{
   int c;
 
   for ( c = 2 ; c <= a - 1 ; c++ )
   { 
      if ( a%c == 0 )
     return 0;
   }
   if ( c == a )
      return 1;
}


int perfect_square(int n)
{
    int sqr=1;
    int counter=1;
    for(int i=1; sqr>=n; i++)
    {
        sqr = i*i;
        counter++;
    }
    if(sqr==n)
    {
        return 1;
    }
    else
    {
        return 2;
    }
}








/*  g++ -std=c++11 -o ser -pthread servert.cpp  */














