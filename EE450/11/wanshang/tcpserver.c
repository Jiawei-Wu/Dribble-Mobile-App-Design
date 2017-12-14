
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <sys/wait.h>
#include <signal.h>
#define MAXLINE 4096 /*max text line length*/
#define HOST "localhost"
#define TCPPORT "23575"  // the port users will be connecting to
#define UDPPORTAND "21575"  // the port users will be connecting to
#define UDPPORTOR "22575"  // the port users will be connecting to
#define BACKLOG 10   // how many pending connections queue will hold

int main(int argc, char *argv[])
{
    char buf[MAXLINE];
    int sockfd, new_fd, n;  // listen on sock_fd, new connection on new_fd
    struct addrinfo hints, *servinfo, *p;
    struct sockaddr_storage their_addr; // connector's address information
    socklen_t sin_size;

    int rv;
    int sockrec;
    memset(&hints, 0, sizeof hints);
    hints.ai_family = AF_INET;
    hints.ai_socktype = SOCK_STREAM;
    hints.ai_flags = AI_PASSIVE; // use my IP
    if ((rv = getaddrinfo(HOST, TCPPORT, &hints, &servinfo)) != 0) {
        fprintf(stderr, "getaddrinfo: %s\n", gai_strerror(rv));
        return 1;
    }
    for(p = servinfo; p != NULL; p = p->ai_next) {
        if ((sockfd = socket(p->ai_family, p->ai_socktype,
                p->ai_protocol)) == -1) {
            perror("server: socket");
            continue;
        }
        if (bind(sockfd, p->ai_addr, p->ai_addrlen) == -1) {
            close(sockfd);
            perror("server: bind");
            continue;
        }
        break;
    }
//    freeaddrinfo(servinfo); // all done with this structure
    if (p == NULL)  {
        fprintf(stderr, "server: failed to bind\n");
        exit(1);
    }
    if (listen(sockfd, BACKLOG) == -1) {
        perror("listen");
        exit(1);
    }
    printf("server: waiting for connections...\n");
    while(1) {  // main accept() loop
        sin_size = sizeof their_addr;
        new_fd = accept(sockfd, (struct sockaddr *)&their_addr, &sin_size);
        if (new_fd == -1) {
            perror("accept");
            continue;
        }
        printf("%s\n","Received message...");
        if (sockrec=recv(new_fd, buf, MAXLINE,0)==-1){
        perror("recieve");
            continue;
        }
       
        printf("%s",buf);
     


    int sockfda;
    struct addrinfo hintsa, *servinfoa, *pa;
    int rva;
    int numbytesa;
    memset(&hintsa, 0, sizeof hintsa);
    hintsa.ai_family = AF_UNSPEC;
    hintsa.ai_socktype = SOCK_DGRAM;
    if ((rva = getaddrinfo(HOST, UDPPORTAND, &hintsa, &servinfoa)) != 0) {
        fprintf(stderr, "getaddrinfo: %s\n", gai_strerror(rva));
        return 1;
    }
    printf("11");
    // loop through all the results and make a socket
    for(pa = servinfoa; pa != NULL; pa = pa->ai_next) {
        if ((sockfda = socket(pa->ai_family, pa->ai_socktype,
                pa->ai_protocol)) == -1) {
            perror("talker: socket");
            continue;
        }
        break;
    }
    if (pa == NULL) {
        fprintf(stderr, "talker: failed to create socket\n");
        return 2;
    }
    if ((numbytesa = sendto(sockfda, buf, strlen(buf), 0,
             pa->ai_addr, pa->ai_addrlen)) == -1) {
        perror("talker: sendto");
        exit(1);
    }
    freeaddrinfo(servinfoa);
    printf("talker: sent %d bytes to %s\n", numbytesa, argv[1]);
    close(sockfda);

    int sockfdaa;
    struct addrinfo hintsaa, *servinfoaa, *paa;
    int rvaa;
    int numbytesaa;
    memset(&hintsaa, 0, sizeof hintsaa);
    hintsaa.ai_family = AF_UNSPEC;
    hintsaa.ai_socktype = SOCK_DGRAM;
    if ((rvaa = getaddrinfo(HOST, UDPPORTOR, &hintsaa, &servinfoaa)) != 0) {
        fprintf(stderr, "getaddrinfo: %s\n", gai_strerror(rvaa));
        return 1;
    }
    printf("11");
    // loop through all the results and make a socket
    for(paa = servinfoaa; paa != NULL; paa = paa->ai_next) {
        if ((sockfdaa = socket(paa->ai_family, paa->ai_socktype,
                paa->ai_protocol)) == -1) {
            perror("talker: socket");
            continue;
        }
        break;
    }
    if (paa == NULL) {
        fprintf(stderr, "talker: failed to create socket\n");
        return 2;
    }
    if ((numbytesaa = sendto(sockfdaa, buf, strlen(buf), 0,
             paa->ai_addr, paa->ai_addrlen)) == -1) {
        perror("talker: sendto");
        exit(1);
    }
    freeaddrinfo(servinfoaa);
    printf("talker: sent %d bytes to %s\n", numbytesaa, argv[1]);
    close(sockfdaa);

    return 0;
  }
}
