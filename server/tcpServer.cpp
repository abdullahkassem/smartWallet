#include "tcpServer.h"


/// @brief constructor that get creates a local server socket and mark it for listening
/// @param port 
tcpServer::tcpServer(int port):portNum(port)
{
    serverSocket = socket(AF_INET, SOCK_STREAM, 0); 
    if (serverSocket == -1) { 
        printf("socket creation failed...\n"); 
        exit(0); 
    } 
    else
        printf("Socket successfully created..\n"); 

    
    bzero(&servaddr, sizeof(servaddr)); 
   
    // assigning server IP, PORT 
    servaddr.sin_family = AF_INET; 
    servaddr.sin_addr.s_addr = htonl(INADDR_ANY); 
    servaddr.sin_port = htons(port); 

    // Binding newly created socket to given IP and verification 
    if ((bind(serverSocket, (sockaddr*)&servaddr, sizeof(servaddr))) != 0) { 
        printf("socket bind failed...\n"); 
        exit(0); 
    } 
    else
        printf("Socket successfully binded..\n"); 

    // mark server for listening
    if ((listen(serverSocket, 10)) != 0) { 
        printf("Listen failed...\n"); 
        exit(0); 
    } 
    else
        printf("Server listening..\n"); 
}

/// @brief A blocking loop that keeps accesspting new connections and create a thread for each new connection
void tcpServer::accecptLoop(const function<void(int)> threadHandler){
    while(true){
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
            thread newThread(threadHandler,clientSocket);
            newThread.join();
        }
    }
}

tcpServer::~tcpServer()
{
    close(serverSocket); 
}

string tcpServer::buildResponse(string body)
{
        std::string htmlFile = body;
        std::ostringstream ss;
        ss << "HTTP/1.1 200 OK\nContent-Type: text/html\nContent-Length: " << htmlFile.size() << "\n" <<
         "Access-Control-Allow-Origin: *"<<"\n\n"
           << htmlFile;

        std::cout << "responce built:\n" << ss.str()<<std::endl;

        return ss.str();
}

void customThreadHandler(int x){

}

int main(){

    tcpServer serv(8080);
    serv.accecptLoop(customThreadHandler);

    return 0;
}