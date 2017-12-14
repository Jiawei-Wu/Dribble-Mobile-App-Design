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
int total_num = 0;
int data[30000];
	void read_file(){
		FILE *fp = NULL;
		fp = fopen("job.txt","r");
		if(fp == NULL){
			exit(0);
		}
		int ch;
	  	while(!feof(fp))
	    {  
	       fscanf(fp,"%d",&data[total_num]);
			total_num++;
	    }
	    fclose(fp);
	}


//	char buffer[255];
//	char ch;
//	FILE *file;
//	file=fopen("job.txt","r");
//	fscanf(file,"%s\n",ch);

//	while ((ch=fgetc(file)) != EOF){
//		fscanf("%c","%s"ch);
//		}
//	printf("11");

	int main(int argc, char *argv[])
	{
	struct socketaddr_in server;	
	server.sin_family=AF_INET;
	server.sin_addr=INADDR_ANY;
	server.sin_port=htons(23575);


	int socketid = socket(AF_INET,SOCK_STREAM,0);
	if (socketid==-1)
		{
		printf("Error in creating socket");
		}

	int socketcon=connect(socketid, (struct socketaddr_in *)&server, sizeof(server));
	if (socketcon==-1)
	{
	printf("Error in Connection");
	}
	printf("11");
	read_file();
	printf("1");
	int socketsend=send(socketid, (char *)& data, sizeof data, 0);
	if(socketsend<0)
		{
		printf("send failed");
		}
	printf("Data Send\n");
        close(socketid);
	return 0;
}

