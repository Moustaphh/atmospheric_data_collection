#include <arpa/inet.h> // inet_addr()
#include <netdb.h>
#include <stdio.h>
#include <stdlib.h>
#include <strings.h> // bzero()
#include <sys/socket.h>
#include <unistd.h> // read(), write(), close()
#include"intercept.h"


int send_tcp( std::string data ){
	char* server_ip="192.168.0.18";
	int n = data.length();
 
    // declaring character array
    char char_buff[n + 1];
 
    // copying the contents of the
    // string to char array
    strcpy(char_buff, data.c_str());

	int sockfd, connfd;
    	struct sockaddr_in servaddr, cli;
 
    // socket create and verification
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        printf("socket creation failed...\n");
        exit(0);
    }
    else
        printf("Socket successfully created..\n");
    bzero(&servaddr, sizeof(servaddr));
 
    // assign IP, PORT
    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = inet_addr(server_ip);
    servaddr.sin_port = htons(PORT);
 
    // connect the client socket to server socket
    if (connfd=connect(sockfd, (struct sockaddr*)&servaddr, sizeof(servaddr))
        != 0) {
        printf("connection with the server failed...\n");
        exit(0);
    }
    else
        printf("connected to the server..\n");

	write(sockfd, char_buff, sizeof(char_buff));
    bzero(char_buff, sizeof(char_buff));
	close(sockfd);
	// sleep(2);

    return 1;
;}