#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>
#include <arpa/inet.h>
int main(int argc, char* argv[])
{
 int MAXLINE;
 MAXLINE=0;
 char sendline[MAXLINE];
 FILE *fp = fopen("job.txt","r");
	if(fp == NULL){
		exit(0);
	}

  	while(!feof(fp))
    {  
       fscanf(fp,"%s\n\n",&sendline[MAXLINE++]);
       printf("%s\n",sendline);
		MAXLINE++;
    }
 //printf("%s\n",sendline);
fclose(fp);
}
