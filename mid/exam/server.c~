#include <stdio.h>
#include <sys/sendfile.h>
#include <sys/stat.h> 
#include <fcntl.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>
#include <errno.h>



int main(int argc, char **argv)
{

  int sockfd,new_skt_fd[100],portno,l,z,nread;
  char buffer[256],serv_msg[50];;

  struct sockaddr_in serv_addr,cli_addr;
  
  int n,i=0,count,temp,j; 

  char buffer1[256],buffer2[256];
  fd_set master, read_fds;

	if(argc != 3)
	{
		//printf("Usage syntax: ./server <port_no>");
		return 0;
	}
		
	
	sockfd = socket(PF_INET, SOCK_STREAM, 0);
	
	if(sockfd == -1)
	{
	        perror("The following error occurred");	
		return -1;
	}
	else
		printf("Socket successfully created.");
 	
 	bzero((char*)&serv_addr,sizeof(serv_addr));
	serv_addr.sin_family = AF_INET;
	serv_addr.sin_port = htons(atoi(argv[1]));
	serv_addr.sin_addr.s_addr = INADDR_ANY;
	//memset(serv_addr.sin_zero,0,sizeof(serv_addr.sin_zero));	
	
	
	
	//Bindig the Socket to a port
	temp = bind(sockfd, (struct sockaddr *)&serv_addr, sizeof(struct sockaddr));

	if(temp == -1)
	{
		perror("error occurred");	
		
	}
	else
		printf("Server started running at %s : %s",inet_ntoa(serv_addr.sin_addr),argv[1]);

	temp = listen(sockfd, 10);

	if(temp == -1)
	{
		perror("error occurred");	
		
	}
	int m_sock = 0;
	FD_ZERO(&master);
	FD_ZERO(&read_fds);
	int num = atoi(argv[2]);
	

                socklen_t clilen = sizeof(struct sockaddr);
		for(count=1;count<=num;count++)
			{

				if((new_skt_fd[i] = accept(sockfd,(struct sockaddr *)&cli_addr, &clilen))<0)
					{
						perror("connection couldn't established");
					}
				else
					{
						FD_SET(new_skt_fd[i], &master);

						if (new_skt_fd[i] > m_sock) 
							{
							m_sock = new_skt_fd[i];
							printf("accepted %d\n",i);
					}
				i++;	
			}

}


	       struct timeval tv;
	       tv.tv_sec = 1;//2;
	       tv.tv_usec = 1000000;
	
		int b_sent;
	//char receivedBuff[100];


		FILE *fp1 = fopen("clients12.txt","a");
		        if(fp1==NULL)
			   	{ 
				perror("fopen error");   
				}   
			
		FILE *fp2 = fopen("clients23.txt","a");
			if(fp2==NULL)
				{
				perror("fopen error");   
				}   
		
		
		
	while(1)
		{
 			printf("enter 1 to continue chat");
			scanf("%d",&z);
				if(z==0)
				break;		
	
			read_fds = master;
	int numFds = select(m_sock+1, &read_fds, NULL, NULL, &tv);	
		
	if(numFds == -1)
		{
			perror("Select() ");	
			return -1;
		}
			else if(numFds > 0)
		{
				for(i=0;i<num;i++)
					{
		
					if(FD_ISSET(new_skt_fd[i], &read_fds))
					{

						printf("enter 1 for client 1&2 and enter 2 for client 2&3 : ");
						scanf("%d",&l);

				if(i==0 && l==1)
					{
				
					bzero(buffer1,256);			
	
					temp = read(new_skt_fd[i],buffer1,255);
	
						if(temp == -1)
							{
							printf("Data could not be received :");
							perror("read");	
						}
							else if(temp == 0)
						{
							printf("Connection closed by remote machine.");
							break;
						}
										
			fprintf(fp1,"%s",buffer1);
					//fclose(fp1);
	   
			//		fwrite(buffer1, 1,temp,fp1);
			b_sent = write(new_skt_fd[1], buffer1, strlen(buffer1)+1);
			
			if(b_sent == -1)
                 		{
			        perror("send ");
				return-1;				
						
				}
						}
			  
			  else if(i==1 && l==1)
		
				{
					bzero(buffer1,256);			
			
						temp = read(new_skt_fd[i],buffer1,255);
	
						if(temp == -1)
		 					{
							printf("Data could not be received :");
							perror("read");	
						}
						else if(temp == 0)
							{
								printf("Connection closed by remote machine.");
								break;
							}
								
				


   		fprintf(fp1,"%s",buffer1);				
		b_sent = write(new_skt_fd[0], buffer1, strlen(buffer1)+1);
		
		if(b_sent == -1)
          		{
 			        perror("send ");
				return-1;				
					
			}
		}
				
	else if(i==1 && l==2)
	  {
	     bzero(buffer2,256);			
	     temp = read(new_skt_fd[i],buffer2,255);
		if(temp == -1)
			{
				printf("Data could not be received :");
				perror("read");	
			}
   		else if(temp == 0)
 				{
					printf("Connection closed by remote machine.");
					break;
				}
								
				
				//fwrite(buffer2, 1,temp,fp2);
		fprintf(fp2,"%s",buffer2);				
		b_sent = write(new_skt_fd[2], buffer2, strlen(buffer2)+1);
		
			if(b_sent == -1)
                   		{
				        perror("send ");
					return-1;				
				
				}		
		}
	
			else if(i==2 && l==2)
			{
			bzero(buffer2,256);			

			temp = read(new_skt_fd[i],buffer2,255);

					if(temp == -1)
					{
						printf("Data could not be received :");
						perror("read");	
					}
					else if(temp == 0)
						{
							printf("Connection closed by remote machine.");
							break;
						}
								
				
				//fwrite(buffer2, 1,temp,fp2);
		fprintf(fp2,"%s",buffer2);				
		b_sent = write(new_skt_fd[1], buffer2, strlen(buffer2)+1);
		
			if(b_sent == -1)
					{
					        perror("send ");
						return-1;				
				
					}		
				}
	
				}
			}
			
		
		}
		
	}
	

	fclose(fp1);
        fclose(fp2);

      FILE *fp3 = fopen("clients12.txt","r");
               if(fp3==NULL)
                   {
                     error("File opern error");   
                    }   
FILE *fp4 = fopen("clients23.txt","r");
              if(fp4==NULL)
                 {
                   error("File opern error");   
                   }   

      while(1)
         {
            bzero(buffer,256);
            nread = fread(buffer,1,256,fp3);

            if(nread > 0) 
               {
                  write(new_skt_fd[3], buffer, nread);
                   }
                  if (nread < 256)
                    {
                     if (feof(fp3))
                       printf("End of file\n");
                         if (ferror(fp3)) 
                            printf("Error reading\n"); 
                             break;
                    } 
  }

            while(1)
             {
                bzero(buffer,256);
                nread = fread(buffer,1,256,fp4);

           if(nread > 0)
             {
                write(new_skt_fd[3], buffer, nread);
             }
           if (nread < 256)
              
              {
              
               if (feof(fp4))
              
                {
                  printf("End of file\n");
                   }
                   if (ferror(fp4))
                      {
                        printf("Error reading\n");
                           }
        break;
                }
}

 	close(sockfd);

         	for(i=0;i<num;i++)
	            {
		    close(new_skt_fd[i]);
	            }

return 0;
}
