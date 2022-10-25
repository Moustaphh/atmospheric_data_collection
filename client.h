#ifndef CLIENT_H
#define CLIENT_H

#include <iostream>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <unistd.h>
#include <string>

#define PORT 8080

std::string get_tcp(std::string);
std::string clean_buff(std::string);

#endif /*END OF CLIENT_H*/
