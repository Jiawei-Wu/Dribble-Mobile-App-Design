#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>
#include <arpa/inet.h>
#define SERV_PORT 23575 /*port*/
int main(int argc, char *argv[])
{
int sock, length, n;
struct sockaddr_in server, from;
struct hostent *hp;
char buffer[256];

//if (argc != 3)
//{
//printf("Usage: server port\n");
//exit(1);
//}

sock= socket(AF_INET, SOCK_DGRAM, 0);

//if (sock h_addr, (char *)&server.sin_addr,hp->h_length);
//server.sin_port = htons(23575);



memset(&server, 0, sizeof(server));
 server.sin_family = AF_INET;
 //servaddr.sin_addr.s_addr= inet_addr(argv[1]);
 server.sin_addr.s_addr = htonl(INADDR_ANY);
 server.sin_port =  htons(SERV_PORT); //convert to big-endian order


strcpy(buffer, "Hello");

   /* Send the message in buf to the server */
   if (sendto(sock, buffer, (strlen(buffer)+1), 0,
                 (struct sockaddr *)&server, sizeof(server)) < 0)
   {
       printf("error");
       exit(2);
   }

   /* Deallocate the socket */

}


/*
length=sizeof(struct sockaddr_in);



bzero(buffer,256);
fgets(buffer,255,stdin);
n=sendto(sock,buffer,strlen(buffer),0,&server,length);
if (n < 0)
{
error("Sendto");
}
n = recvfrom(sock,buffer,256,0,&from, &length);
if (n < 0)
{
error("recvfrom");
}
write(1,"Got an ack: ",12);
write(1,buffer,n);
}

void error(char *msg)
{
perror(msg);
exit(0);
}

*/
