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
	struct socketaddr_in client;
	client.sin_family=AF_INET;
	client.sin_addr=INADDR_ANY;

	struct socketaddr_in server;
	server.sin_family=AF_INET;
	server.sin_addr=INADDR_ANY;
	server.sin_port=htons(23575);
	char buffer[255];
	int c;
	memset(&server,0,sizeof(server));

	int socketid = socket(AF_INET, SOCK_STREAM, 0);
	if (socketid==-1)
		{
		printf("Error in creating socket");
		}
	
	int socketbin=bind(socketid, (struct sockaddr *)&server, sizeof(server));
	if (socketbin==-1)
		{
		printf("Error in binding socket");
		}
	c = sizeof(struct socketaddr_in);
	int newsockfd = accept(socketid, (struct sockaddr *)&client, (socklen_t*)&c);
        if (newsockfd < 0) 
              {
	 error("ERROR on accept");
               }
	bzero(buffer,255);
        recv(newsockfd,buffer,255,0);
        printf("Here is the message: %s\n",buffer);
}

