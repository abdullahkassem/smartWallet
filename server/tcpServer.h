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
#include <mutex>
#include <regex>

#include <iostream>
#include "EdUrlParser.h"

#include "server.h"

using namespace std;

#define BUFFER_SIZE 4096

class tcpServer
{
private:
    int portNum;
    int serverSocket;
    struct sockaddr_in servaddr; 
    void defaultThreadHandler(int x);
    void handleIncRequest(int clientSocket,char *request);
    database* db;
    server* myserv;

public:
    // tcpServer(/* args */);
    tcpServer(server* myserv,int port);
    // void acceptLoop(const function<void(int)> threadHandler);
    void acceptLoop();
    thread readCin();
    ~tcpServer();
    vector<query_kv_t> parseQuery(string q);

    string buildResponse(string body);

    
};

#endif