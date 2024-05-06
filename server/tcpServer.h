#ifndef TCP_SERVER_H
#define TCP_SERVER_H

// while compiling use -lpthread

#include <stdio.h> 
#include <netdb.h> 
#include <netinet/in.h> 
#include <stdlib.h> 
#include <string.h> 
#include <sys/socket.h> 
#include <sys/types.h> 
#include <unistd.h> // read(), write(), close()
#include <cstring>
#include <arpa/inet.h>
#include <thread>
#include <pthread.h>
#include <sstream>
#include <functional>

#include <iostream>
using namespace std;

#define BUFFER_SIZE 4096

class tcpServer
{
private:
    int portNum;
    int serverSocket;
    struct sockaddr_in servaddr; 
public:
    // tcpServer(/* args */);
    tcpServer(int port);
    void accecptLoop(const function<void(int)> threadHandler);
    ~tcpServer();

    string buildResponse(string body);
};


#endif