#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <stdlib.h>
#define LEN 10
int num = 0;
int or_port = 21000;
int and_port = 22000;


void deal_and(char * recv,char* send){
    char number1[LEN+1];	
    char number2[LEN+1];	
    char *p = recv;

    number1[LEN]='\0';
    number2[LEN]='\0';

    for(int i=0;i<LEN;i++)
    {
        number1[i]='0';
        number2[i]='1';
    }

    char*p1,*p2;
    p1 = strchr(recv,' ');
    int length = p1-recv-1;
    memcpy(number1+LEN-length,recv,length);
    length = strlen(p1+1);
    memcpy(number2+LEN-length,p1+1,length);

    for(int i=0;i<LEN;i++)
    {
        if(number1[i]=='1'&&number2[i]=='1')
            number1[i]='1';
        else
            number1[i]='0';
    }
    strcpy(send,number1);
}

void connect_edge()
{
   
    int sockfd;
    struct sockaddr_in servaddr;

    sockfd = socket(PF_INET, SOCK_DGRAM, 0);

    bzero(&servaddr, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
    servaddr.sin_port = htons(and_port);

    bind(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr));

    int n;
    char recvline[24];
    char sendline[11];

    printf("The Server AND start receiving lines from the edge server for OR computation.The computation results are:\n");

    while(1){
        recvfrom(sockfd, recvline, 24, 0, NULL, NULL);

        deal_and(recvline,sendline);    

        sendto(sockfd, sendline, strlen(sendline), 0, (struct sockaddr *)&servaddr, sizeof(servaddr));

        recvfrom(sockfd, recvline, 100, 0, NULL, NULL);
        printf("%s\n", recvline);
		num++;
    }

    close(sockfd);
    printf("The Server AND has successfully received %d lines from the edge server and finished all OR computations.\n");
    printf("The Server AND has successfully finished sending all computation results to the edge server\n");	
}

int main(int argc, char **argv)
{
    connect_edge();

    return 1;
}
