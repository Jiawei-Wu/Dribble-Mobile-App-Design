#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>
#include <unistd.h>

#define MAXLINE 4096 /*max text line length*/
#define SERV_PORT 23575 /*port*/
#define LISTENQ 8 /*maximum number of client connections */

void udpclient(){
 int listenfd, connfd, n;
 int pre_num = 0;
 int result = 0;
 int dataX[pre_num];
 socklen_t clilen;
 char buf[MAXLINE];
 struct sockaddr_in cliaddr, servaddr;

 //creation of the socket
 listenfd = socket (AF_INET, SOCK_STREAM, 0);

 //preparation of the socket address
 servaddr.sin_family = AF_INET;
 servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
 servaddr.sin_port = htons(SERV_PORT);
 addr_len = sizeof their_addr;
 addrlen = sizeof servaddr
 bind (listenfd, (struct sockaddr *) &servaddr, sizeof(servaddr));

 printf("%s\n","Server running...waiting for connections.");

 for ( ; ; ) {

   recvfrom(sockfd, (char *)& pre_num, sizeof pre_num , 0,(struct sockaddr_in *)&cliaddr, &addr_len);
 
   printf("%s\n","String received from and resent to the client:");

   puts(buf);

   printf("aaa");
   
   sendto(sockfd, (char *)& result, sizeof result , 0,(struct sockaddr_in *) &servaddr, &addrlen);

 if (n < 0) {
  perror("Read error");
  exit(1);
 }

}


void tcpserver(){

 int listenfd, connfd, n;
 socklen_t clilen;
 char buf[MAXLINE];
 struct sockaddr_in cliaddr, servaddr;

 //creation of the socket
 listenfd = socket (AF_INET, SOCK_STREAM, 0);

 //preparation of the socket address
 servaddr.sin_family = AF_INET;
 servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
 servaddr.sin_port = htons(SERV_PORT);

 bind (listenfd, (struct sockaddr *) &servaddr, sizeof(servaddr));

 listen (listenfd, LISTENQ);

 printf("%s\n","Server running...waiting for connections.");

 for ( ; ; ) {

  clilen = sizeof(cliaddr);
  connfd = accept (listenfd, (struct sockaddr *) &cliaddr, &clilen);
  printf("%s\n","Received request...");
  n=recv(connfd, buf, MAXLINE,0);
  //while ( (n = recv(connfd, buf, MAXLINE,0)) > 0)  {
   printf("%s\n","String received from and resent to the client:");
   //int i=0;
   //while(buf[i]){
   //putchar(buf[i++]);}
   puts(buf);
   //}
   //send(connfd, buf, n, 0);
  //}
   printf("aaa");
 if (n < 0) {
  perror("Read error");
  exit(1);
 }
 close(connfd);











}









int main (int argc, char **argv)
{


 }
 //close listening socket
 close (listenfd);
}
