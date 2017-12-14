#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <netdb.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <sys/wait.h>



struct socketaddr_in{
	short sin_family;
	unsigned short sin_port;
	unsigned long sin_addr;
};

int main(int argc, char *argv[])
{

// start the TCP connection//

	struct socketaddr_in client;
	client.sin_family=AF_INET;
	client.sin_addr=INADDR_ANY;

	struct socketaddr_in server;
	server.sin_family=AF_INET;
	server.sin_addr=INADDR_ANY;
	server.sin_port=htons(23575);

	int socketid = socket(AF_INET, SOCK_STREAM, 0);
	if (socketid==-1)
		{
		printf("Error in creating socket");
		}
	memset(&server,0,sizeof(server));
	printf("hello world");
	int socketbin=bind(socketid, (struct sockaddr *)&server, sizeof(server));
	if (socketbin==-1)
		{
		printf("Error in binding socket");
		}
	int socketlisten=listen(socketid,5);
	c = sizeof(struct socketaddr_in);
        int newsockfd = accept(socketid, (struct sockaddr *)&client, &sizeof(struct socketaddr_in)&c);
        if (newsockfd < 0) 
              {
	 error("ERROR on accept");
               }
        bzero(buffer,255);
        n = recv(newsockfd,buffer,255,0);
        if (n < 0) 

        {error("ERROR reading from socket");
	}


        printf("Here is the message: %s\n",buffer);

        n = printf(newsockfd,"I got your message",18);
        if (n < 0) 
	{
              error("ERROR writing to socket");
	}
	close(socketid);
        return 0; 
}



  


/*	while(1)
	{
	int messagelength=100;
	char message[messagelength+1];
	int index=0;
	int limit=messagelength;
	int socketacp=accept(socketid,(struct socket_addr *)&client,&sizeof(client));
	if (socketacp==-1)
		{
		printf("Error in Accepting");
		}	
	int socketrec=recv(socketid,void[],3,0);
	if (socketrec==-1)
		{
		printf("Error in receiving");
		}
	else ((int socketrec=recv(socketid,&message[index],messagelength,0))>=0)
		{
		index=index+1;
		limit=limit-1;
		printf("%s\n",message);
		}	
	int socketsen=send(socketid,job.txt,sizeof(job.txt),0);
	if (socketsen==-1)
		{
		printf("Error in sending");
		}
        close(socketid);
}





struct sockaddr {
    unsigned short    sa_family;    // address family, AF_xxx
    char              sa_data[14];  // 14 bytes of protocol address
};

*/





