#include <iostream>
#include <fstream>
#include <cereal/archives/binary.hpp>
#include "./database/database.h"
#include "user.h"
#include "server.h"
#include "tcpServer.h"

using namespace std;



int main(){
    // cout << "Hello world\n";

    int portNum = 8081;
    server myserv = server();


   // to populate database, for demo purpose
    if(false){
        myserv.createUser("abdullahk","MyPass");
        myserv.createAccount("abdullahk","main","debit",0.0);
        myserv.createAccount("abdullahk","secondary","credit",0);
        string firstAcc = myserv.getUserAccounts("abdullahk")[0];
        myserv.Deposit(firstAcc,1000.0,"salary");
        myserv.Withdraw(firstAcc,50.0,"food");
    }
    

    tcpServer serv(&myserv,portNum);
    cout << "server started at http://localhost:"<<portNum<<endl;

    serv.acceptLoop();



    return 0;
}

