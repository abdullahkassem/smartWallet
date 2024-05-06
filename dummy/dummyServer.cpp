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


#include <iostream>
using namespace std;

#define PORT 8082
   
// Function designed for chat between client and server. 
void func(int clientSocket) 
{ 
    cout << "Hi thread\n";
    /*char buff[MAX]; 
    int n; 
    // infinite loop for chat 
    for (;;) { 
        bzero(buff, MAX); 
   
        // read the message from client and copy it in buffer 
        read(connfd, buff, sizeof(buff)); 
        // print buffer which contains the client contents 
        printf("From client: %s\t To client : ", buff); 
        bzero(buff, MAX); 
        n = 0; 
        // copy server message in the buffer 
        while ((buff[n++] = getchar()) != '\n') 
            ; 
   
        // and send that buffer to client 
        write(connfd, buff, sizeof(buff)); 
   
        // if msg contains "Exit" then server exit and chat ended. 
        if (strncmp("exit", buff, 4) == 0) { 
            printf("Server Exit...\n"); 
            break; 
        } 
    } */
} 

void printAddr(sockaddr_in address){

  char ip_address[INET6_ADDRSTRLEN];
  inet_ntop(address.sin_family, &address.sin_addr, ip_address, sizeof(ip_address));

  unsigned short port = ntohs(address.sin_port);

  std::cout << "IP Address: " << ip_address;
  std::cout << "Port: " << port << std::endl;
}
   

int main() 
{ 
    int serverSocket;
   
    // socket create and verification 
    serverSocket = socket(AF_INET, SOCK_STREAM, 0); 
    if (serverSocket == -1) { 
        printf("socket creation failed...\n"); 
        exit(0); 
    } 
    else
        printf("Socket successfully created..\n"); 
    
    
    struct sockaddr_in servaddr; 
    bzero(&servaddr, sizeof(servaddr)); 
   
    // assign IP, PORT 
    servaddr.sin_family = AF_INET; 
    servaddr.sin_addr.s_addr = htonl(INADDR_ANY); 
    servaddr.sin_port = htons(PORT); 

   
    // Binding newly created socket to given IP and verification 
    if ((bind(serverSocket, (sockaddr*)&servaddr, sizeof(servaddr))) != 0) { 
        printf("socket bind failed...\n"); 
        exit(0); 
    } 
    else
        printf("Socket successfully binded..\n"); 
   
    
    // mark server socket as listening
    if ((listen(serverSocket, 5)) != 0) { 
        printf("Listen failed...\n"); 
        exit(0); 
    } 
    else
        printf("Server listening..\n"); 


    while (true)
    {
        sockaddr_in clientAddr;
        unsigned int len = sizeof(clientAddr); 
        int clientSocket = accept(serverSocket, (sockaddr*)&clientAddr, &len);
        
        if (clientSocket < 0) { 
        printf("server accept failed...\n"); 
        exit(0); 
        } 
        else{
            // printAddr(clientAddr);
            cout << "will create new thread\n";
            thread newThread(func,clientSocket);
            newThread.join();
        }
    }
    
   
    // close the socket 
    close(serverSocket); 
}