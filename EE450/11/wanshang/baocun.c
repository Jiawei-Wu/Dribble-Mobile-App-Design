#include<stdio.h>
#include<string.h>

int main()
{
int MAXLINE=1024;
int k;
int i;
char sendline[MAXLINE];
int counter=0;
     FILE *fp = NULL;
	fp = fopen("job.txt","r");
	if(fp == NULL){
		exit(0);
	}

  	while(!feof(fp))
    {  
       counter=fread(sendline,1024,1,fp);
    }
            printf("%s\n",sendline);

    fclose(fp);





