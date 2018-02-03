#include <iostream>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>

using namespace std;




int q[100],front=-1,rear=-1,a[100][100],vis[100]; 

int t[100][100];	
int count=0;		
int parent[100],source[100],f_tri=0,e_tri=0,a2[100][100],f[20];


int delete1(); 
void add(int item); 
void bfs(int s,int n); 
int chk(int n);


int main(int argc,char* argv[])
{
  	if(argc != 3)
    	{
      		cerr << "Usage syntax: ./client <ip_address> <port_no>" << endl;
      		return 0;
    	}
  	int sockfd;
  	struct sockaddr_in my_addr;

  	sockfd=socket(PF_INET,SOCK_STREAM,0);

  	my_addr.sin_family=AF_INET;
  	my_addr.sin_port=htons(atoi(argv[2]));
  	my_addr.sin_addr.s_addr=inet_addr(argv[1]);
  	memset(my_addr.sin_zero, '\0', sizeof my_addr.sin_zero);

  	int temp=connect(sockfd,(struct sockaddr*)&my_addr, sizeof my_addr);

  	if(temp==0)
    		cout << "Connection established with server" << endl;
  	
	else
    	{
      		cout << "Could not establish connection!" << endl;
      		return -1;
    	}

  	char rec_data[500];

  	recv(sockfd,rec_data,sizeof rec_data,0);
  	cout << "message from client1:" << rec_data << endl;


 	char buf[500];
  	cout << "Enter the message to client1:" << endl;
  	cin.getline(buf,500);
  

	temp=send(sockfd,buf,strlen(buf)+1,0);

  	if(temp==-1)
    		cout << "Error:not sent" << endl;
  
	else
    		cout << "Sent " << temp << " bytes" << endl;




	int arr_in[6][6],num,fed;
	for(num=0;num<32768;num++)
	{ 

	
		
  
 		recv(sockfd,arr_in,sizeof(int)*6*6,0);	//receiving adjecency matrix from client1

        	cout << "Received data "<<num+1<<" from client1:"<<endl;
        
		for(int i=0;i<6;i++)
	 	{
	            	for(int j=0;j<6;j++) 
			{
				a[i+1][j+1]=arr_in[i][j];
		
	                	cout<<a[i+1][j+1]<< "  ";
	            	}
			cout<<endl;
	        }

	        cout<<endl<<endl;



//	        cout<<"before chk"<<endl<<endl;

		fed=chk(6);	  

//	        cout<<"after chk"<<endl<<endl;

		char buf1[500];


		if((fed==1 || fed==2) && num<32767)	//if ch==1 3 friends if ch==2 there are 3 enemies
		{

			strcpy(buf1,"perfect, not convinced. send next graph");	
		//	cout<<buf1<<endl;		
			temp=send(sockfd,buf1,strlen(buf1)+1,0);
		}

		else if((fed==1 || fed==2) && num==32767)	//if ch==1 3 friends if ch==2 there are 3 enemies
		{
			strcpy(buf1,"i'm convienced... wledone c1");	
		//	cout<<buf1<<endl;		
			temp=send(sockfd,buf1,strlen(buf1)+1,0);
		}

		
		else if (fed==0)
			cout<<endl<<"claim is false, something went wrong"<<endl;

	}



	close(sockfd);
  	return 0;
}






int chk(int n) 
{ 
	int i,s,ch,j,k; 



	for(k=1;k<=n;k++)
	{

		for(i=1;i<=n;i++)	//for every source vertex making visit array to 0 
			vis[i]=0; 
	
	
//		cout<<"SOURCE VERTEX IS:"<<k<<endl; 
	
			
		for(i=1;i<=n;i++) 	//for every source vertex making parent array to 0
		{
			parent[i]=0;		
			for(j=1;j<=6;j++)	
			{
				t[i][j]=0;
				a2[i][j]=0;
			}
		}


		count=0;
		rear=-1;
		front=-1;

		bfs(k,n); 
		
//		cout<<endl;

	
		for(i=1;i<=n;i++)
		{
			s=source[i];
			for(j=1;j<=n;j++)
			{
				int cnt1=0,cnt2=0;		
		
				if(a[i][j]!=t[i][j])	//if tree matrix differ from adjecency matrix then there is a non_tree edge in graph
				{
					int i1,j1;
					i1=i;	//i1 and j1 is non_tree edge
					j1=j;
					while(i1!=s)	
					{
						i1=parent[i1];
						cnt1=cnt1+1;		//cnt1 is length of i1 from source vertex
			
						//cout<<"loop1.1"<<endl;
					}
	
					while(j1!=s)	
					{
						j1=parent[j1];
						cnt2=cnt2+1;		//cnt2 is length of j1 from source vertex

						//cout<<"loop1.2"<<endl;
					}

					if(cnt1==1 && cnt2==1)			//if cnt1==cnt2 then there are odd_cycle in the graph
					{
						f_tri=1;
						break;
					}

				
				}
			}
		}

//		cout<<endl;
	}
	int check=0;

	if(f_tri==1)
	{
		cout<<endl<<"there exists atleast 3 mutual friends"<<endl;
		return 1;
	}

	else
	{

		
		for(i=1;i<=n;i++)
		{
			for(j=1;j<=n;j++)
			{
				if(a[i][j]==1)
				{
					a[i][j]=0;
				}
				else if(i==j)
					a2[i][j]=0;
					
				else
				{
					a2[i][j]=1;
				}			
			}
		}

		for(i=1;i<=n;i++)
			for(j=1;j<=n;j++)
				a[i][j]=a2[i][j];



		for(k=1;k<=n;k++)
		{
	
			for(i=1;i<=n;i++)	//for every source vertex making visit array to 0 
				vis[i]=0; 
		
		
			//cout<<"SOURCE VERTEX IS:"<<k<<endl; 
		
				
			for(i=1;i<=n;i++) 	//for every source vertex making parent array to 0
			{
				parent[i]=0;		
				source[i]=0;
			}		
		
			count=0;
			rear=-1;
			front=-1;

			bfs(k,n); 


	//		cout<<endl;
	
			
			for(i=1;i<=n;i++)
			{
				s=source[i];
				for(j=1;j<=n;j++)
				{
					int cnt1=0,cnt2=0;		
			
				if(a[i][j]!=t[i][j])//if tree matrix differ from adjecency matrix then there is a non_tree edge in graph
					{
						int i1,j1;
						i1=i;	//i1 and j1 are non_tree edges
						j1=j;
						while(i1!=s)	
						{
							i1=parent[i1];
							cnt1=cnt1+1;		//cnt1 is length of i1 from source vertex

							//cout<<"loop2.1"<<endl;
						}
		
						while(j1!=s)	
						{
							j1=parent[j1];
							cnt2=cnt2+1;		//cnt2 is length of j1 from source vertex

							//cout<<"loop2.2"<<endl;
						}

						if(cnt1==1 && cnt2==1)		//if cnt1=cnt2=1 then there is triangle  in the graph
							e_tri=1;
					}
				}
			}
	
					
	//		cout<<endl;
		}

		
	}
		

	if(e_tri==1)
	{
		cout<<endl<<"there exists atleast 3 mutual enemies"<<endl;		
		return 2;
	}	

	return 0;

}	


	
//**************BFS(breadth-first search) code**************// 
void bfs(int s,int n) 
{ 
	int p,i; 

	add(s); 

	vis[s]=1; 


	p=delete1(); 

//	if(p!=0) 
//		cout<<"component "<<++count<<" is:"<<p; 

	
	while(p!=0) 
	{ 
		for(i=1;i<=n;i++) 
		{
			
			if( (a[p][i]!=0) && (vis[i]==0) ) 
			{ 
				add(i); 
				vis[i]=1;
				t[p][i]=1;
				parent[i]=p;
				source[i]=s;
			}

			t[i][p]=t[p][i]; 
		}

		p=delete1(); 

//		if(p!=0) 
//			cout<<"  "<<p; 
	} 

//	cout<<endl;

	for(i=1;i<=n;i++) 
		if(vis[i]==0) 
			bfs(i,n); 

			
}

void add(int item) 
{ 
	if(rear==99) 
		cout<<"QUEUE FULL"; 
	
	else 
	{ 
		if(rear==-1) 
		{ 
			q[++rear]=item; 
			front++; 
		} 
		else 
			q[++rear]=item; 
	} 
} 

int delete1() 
{ 

	int k; 

	if((front>rear)||(front==-1)) 
		return(0); 

	else 
	{ 
		k=q[front++]; 
			return(k); 
	} 
} 



