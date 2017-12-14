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
#include <signal.h>
#include <ctype.h> 

#define AWSPORT "25859"   //aws TCP port
#define HOST "localhost"

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
       fscanf(fp,"%s",&data[total_num]);
		total_num++;
    }
    fclose(fp);
}


int main(int argc, char* argv[]){

	//set up TCP --from Beej
	int sockfd = 0;
	struct addrinfo hints, *servinfo, *p;
	int rv;

	memset(&hints, 0, sizeof hints);
	hints.ai_family = AF_INET;
	hints.ai_socktype = SOCK_STREAM;

	if ((rv = getaddrinfo(HOST, AWSPORT, &hints, &servinfo)) != 0) {
		fprintf(stderr, "getaddrinfo: %s\n", gai_strerror(rv));
		return 1;
	}

	// loop through all the results and connect to the first we can----Beej
	for (p = servinfo; p != NULL; p = p->ai_next) {
		if ((sockfd = socket(p->ai_family, p->ai_socktype, p->ai_protocol))
				== -1) {
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
		fprintf(stderr, "client: failed to connect. \n");
		exit(0);
		return 2;
	}
	freeaddrinfo(servinfo); // all done with this structure
	printf("The client is up and running. \n");

	read_file();

	send(sockfd, (char *)& data, sizeof data, 0);

	printf("The client has sent %d numbers to AWS.\n",total_num);

	int result = 0;
	recv(sockfd, (char *)&result, sizeof result, 0);

}
