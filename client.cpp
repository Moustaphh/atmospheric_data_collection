#include "client.h"

// char* server_ip="51.68.93.173";

//std::string buff=" data....data....data";

std::string get_tcp( std::string data ){
//	char* server_ip="192.168.0.18";
	int n = data.length();
 	char buffer[9200];
    // declaring character array
    	char char_buff[n + 1];
    	int valread;

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
    {   
    printf("Socket successfully created..\n");
    bzero(&servaddr, sizeof(servaddr));
 
    // assign IP, PORT
    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = inet_addr("51.68.93.173");
    servaddr.sin_port = htons(PORT);
    }

    // connect the client socket to server socket
    if (connfd=connect(sockfd, (struct sockaddr*)&servaddr, sizeof(servaddr))
        != 0) {
        printf("connection with the server failed...\n");
        exit(0);
    }
    else
        printf("connected to the server..\n");
	//bzero(char_buff, sizeof(char_buff));

	write(sockfd, char_buff, sizeof(char_buff));
   	valread = read(sockfd, buffer, 9200);
	std::string ret=std::string(buffer);
	//std::cout<<"\n received buffer : \n "<<buffer;
 
	bzero(char_buff, sizeof(char_buff));
	bzero(buffer,sizeof(buffer));
        close(sockfd);

    return ret;
}


std::string clean_buff(std::string b )
{
	std::string cleaned;
	unsigned int len=b.length();
	if (len>10 && b[len-2]!='}' && b[len-1]!=']' && b[len] != '}' )
	{
	for(int i=len-10;i<len-3;i++)
	{
		if (b[i]=='}' && b[i+1]==']' && b[i+2]=='}')
		{
			cleaned=b.substr(0,i+3);
			return cleaned;
		}
	}

	}
	else
       	{ 
	return b;
	}


}

