/*
** client.c -- a stream socket client demo
*/
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
#define PORT "23575" // the port client will be connecting to 
#define HOST "localhost"
#define MAXDATASIZE 100 // max number of bytes we can get at once 
int main(int argc, char *argv[])
{
    int MAXLINE=0;
    int counter=0;
    char sendline[MAXLINE];
    int sockfd, numbytes;  
    char buf[MAXDATASIZE];
    struct addrinfo hints, *servinfo, *p;
    int rv;
    char s[INET6_ADDRSTRLEN];
    memset(&hints, 0, sizeof hints);
    hints.ai_family = AF_INET;
    hints.ai_socktype = SOCK_STREAM;
    if ((rv = getaddrinfo(HOST, PORT, &hints, &servinfo)) != 0) {
        fprintf(stderr, "getaddrinfo: %s\n", gai_strerror(rv));
        return 1;
    }
    // loop through all the results and connect to the first we can
    for(p = servinfo; p != NULL; p = p->ai_next) {
        if ((sockfd = socket(p->ai_family, p->ai_socktype,
                p->ai_protocol)) == -1) {
            perror("client: socket");
            continue;
        }
        if (connect(sockfd, p->ai_addr, p->ai_addrlen) == -1) {
            close(sockfd);
            perror("client: connect");
            continue;
        }
        break;
    }
    if (p == NULL) {
        fprintf(stderr, "client: failed to connect\n");
        return 2;
    }
    //printf("The client is up and running. \n");
     int c;
     FILE *fp = NULL;
	fp = fopen("job.txt","r");
	if(fp == NULL){
		exit(0);
	}

  	while(!feof(fp))
    {  
       fscanf(fp,"%s\n\n",&sendline[MAXLINE++]);
       printf("%s\n",sendline);
       MAXLINE=0;
    }
    fclose(fp);

//    FILE *fpa;

//    char ch;

//    int line=0;
//    fpa=fopen("job.txt","r");
//    while(!feof(fpa))
//    {
//    if((ch=fgetc(fp))=='\n') line++;
//    }
    //if(lc != '\n'); line++;

    //if(ch[line]=='\0'){
    //line=line-1;
    //}
//    printf("sum to %d lines.\n",line);
//    fclose(fp);    


    send(sockfd, sendline, strlen(sendline), 0);
    //printf("The client has successfully finished sending %s lines to the edge server.\n",MAXLINE);
    if ((numbytes = recv(sockfd, buf, MAXDATASIZE-1, 0)) == -1) {
        perror("recv");
        exit(1);
    }
    //printf("The client has successfully finished receiving all computation results from the edge server.\n");
    buf[numbytes] = '\0';
    //printf("The final compution result are '%s'\n",buf);
    close(sockfd);
    return 0;
}
