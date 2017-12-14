
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
int main(int argc,char *argv[])
{
char buffer[1024];
FILE *file = fopen("job.txt","r");
int numbers =0;
while(fscanf(buffer,sizeof(buffer),file)!=NULL){
numbers++;
}
printf("the file is %s\n",buffer);
printf("%d\n",numbers);
fclose(file);
}
//int index=0;
//char nums[numbers];
//FILE *file_again=fopen("job.txt","r");
//while(fgets(buffer,sizeof(buffer),file_again)!=NULL){
//nums[index++]=atoi(buffer);
//}

//printf("the sum lines is %d\n",index);

//fclose(file_again);

