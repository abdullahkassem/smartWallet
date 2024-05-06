#include "tcpServer.h"

std::mutex mtx; // Mutex to protect the shared variable (exitFlag)
bool exitFlag = false;

/// @brief constructor that get creates a local server socket and mark it for listening
/// @param port 
tcpServer::tcpServer(server* myserv,int port):portNum(port),myserv(myserv)
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

std::string get_first_line(const std::string& inputString) {
  // Find the position of the newline character
  size_t newlinePos = inputString.find('\n');

  // If newline is found, return everything before it (excluding the newline)
  if (newlinePos != std::string::npos) {
    return inputString.substr(0, newlinePos);
  }

  // If no newline is found, return the entire string
  return inputString;
}

vector<query_kv_t> tcpServer::parseQuery(string q){
    string urlStr = "http://www.google.co.kr:8080/testurl/depth1/depth2/depth3" + q.substr(4);
    EdUrlParser* url = EdUrlParser::parseUrl(urlStr);
    
    // parse query string as key-value hash map
	vector<query_kv_t> kvs;
	int num = EdUrlParser::parseKeyValueList(&kvs, url->query);
	
    return kvs;

}

/*  List of API we need to create

    // myserv.createUser("abdo","p@ss");
    // myserv.login("abdullahk","dummy");
    // myserv.createAccount("abdullahk","main","debit",0.0);
    // myserv.createAccount("abdullahk","secondary","credit",200.0);
    // string firstAcc = myserv.getUserAccounts("abdullahk")[0];
    // cout << firstAcc << endl;
    // myserv.Deposit(firstAcc,100.0,"salary");
    // myserv.Withdraw(firstAcc,50.0,"food");
*/

void tcpServer::handleIncRequest(int clientSocket,char* request){
    /* Example:     GET /?funcType=login&userName=asdsd&password=asdasd HTTP/1.1    */
    string reqStr(request);
    string firstHeader = get_first_line(reqStr);

    if(firstHeader.size() == 0)
        return;
    
    std::size_t pos = firstHeader.find("HTTP/1.1");

    if (pos != std::string::npos) {
        firstHeader.erase(pos-1); // Erase everything from the position of "HTML"
    }
    // cout << "firstHeader is " <<firstHeader<<endl;
    

    vector<query_kv_t> queriesTemp = parseQuery(firstHeader);
    unordered_map<string,string> map;
    for(int i=0;i<queriesTemp.size();i++) {
		map[queriesTemp[i].key] = queriesTemp[i].val;        
	}
    string reqType = map["funcType"];

    string response="temp";

    if(reqType == "login"){
        bool logged = myserv->login(map["userName"],map["password"]);
        if(logged){
            response = "login true";
        }else{
            response = "login false";
        }

    }else if(reqType ==""){

    }else if(reqType ==""){
        
    }else if(reqType ==""){
        
    }else if(reqType ==""){
        
    }else if(reqType ==""){
        
    }else if(reqType ==""){
        
    }else{
         
        response = "Default Response";
    }
    string FinalResponse = buildResponse(response);


    int bytes_sent = send(clientSocket, FinalResponse.c_str(), FinalResponse.length(), 0);
        if(bytes_sent == -1)
            cerr << "Sending failed\n";

}

void tcpServer::defaultThreadHandler(int clientSocket){
    // cout << "THREAD CREATED\n";
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

        // we need to handle request here!!
        handleIncRequest(clientSocket,buff);

        

    }
}



bool readStringAndCheckForExit() {
    std::string input;
    while (true) {
        std::getline(std::cin, input);
        cout << "input is " << input <<endl;
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
thread tcpServer::readCin(){
    
    std::thread myThread(readStringAndCheckForExit);
    myThread.join();
    this->~tcpServer();
    return myThread;

}