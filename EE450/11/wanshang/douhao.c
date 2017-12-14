
#include<stdio.h>
#include<string.h>

int main()
{
int MAXLINE=1024;
int k;
char sendline[MAXLINE];
int counter=0;
     FILE *fp = NULL;
	fp = fopen("job.txt","r");

  	while(!feof(fp))
    {  
       counter=fread(sendline,1024,1,fp);
    }
            printf("%s\n",sendline);

    fclose(fp);
    char * pch;
    pch=strtok(sendline,",");
    while (pch!=NULL)
    {
     printf("%s",pch);
     pch = strtok (NULL, ",");
    }
    k=sizeof(sendline);
    printf("%d\n",k);
    return 0;
}














