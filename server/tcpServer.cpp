#include "tcpServer.h"

std::mutex mtx; // Mutex to protect the shared variable (exitFlag)
bool exitFlag = false;

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
void tcpServer::acceptLoop(const function<void(int)> threadHandler){
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

/// @brief A blocking loop that keeps accepting new connections and create a thread for each new connection
void tcpServer::acceptLoop(){
    while(true){
        mtx.lock();
        bool curExitFlag = exitFlag;
        mtx.unlock();

        if(curExitFlag){
            cout << "will stop listening to new connections\n";
            return;
        }
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
            thread newThread([this, clientSocket] {
                this->defaultThreadHandler(clientSocket);
            });
            
            newThread.join();
        }
    }
}

tcpServer::~tcpServer()
{
    cout << "deconstructor called \n";
    close(serverSocket); 
}

string tcpServer::buildResponse(string body)
{
        std::string htmlFile = body;
        std::ostringstream ss;
        ss << "HTTP/1.1 200 OK\nContent-Type: text/html\nContent-Length: " << htmlFile.size() << "\n" <<
         "Access-Control-Allow-Origin: *"<<"\n\n"
           << htmlFile;

        // std::cout << "responce built:\n" << ss.str()<<std::endl;

        return ss.str();
}

void tcpServer::defaultThreadHandler(int clientSocket){
    cout << "THREAD CREATED\n";
    while(true){

        mtx.lock();
        bool curExitFlag = exitFlag;
        mtx.unlock();

        if(curExitFlag){
            cout << "thread will now exit\n";
            return;
        }
        
        char buff[BUFFER_SIZE]; 
        bzero(buff, BUFFER_SIZE); 
        recv(clientSocket, buff, sizeof(buff),0);
        // printf("Recieved: %s\n", buff); 

        string response = buildResponse("hello world");

        // cout << "response will be: " << response <<endl;

        int bytes_sent = send(clientSocket, response.c_str(), response.length(), 0);
        if(bytes_sent == -1)
            cerr << "Sending failed\n";

    }
}



bool readStringAndCheckForExit() {
    std::string input;
    while (true) {
        std::getline(std::cin, input);
        // cout << "input is " << input <<endl;
        mtx.lock();
        exitFlag = (input == "exit");
        mtx.unlock();
        if (exitFlag) {
            break;
        }
    }
    return true;
}

/// @brief creates a new thread that reads the cin and checks if exit is written, if so it calls the class deconstructor
void tcpServer::readCin(){
    
    std::thread myThread(readStringAndCheckForExit);
    myThread.detach();
    this->~tcpServer();

}