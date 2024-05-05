#include <iostream>
#include <fstream>
#include <cereal/archives/binary.hpp>
#include "./database/database.h"
#include "user.h"
#include "server.h"

using namespace std;

int main(){
    cout << "Hello world\n";
    database* db = database::getInstance();

    server myserv = server();
    // myserv.createUser("abdullahk","dummy");

    // myserv.login("abdullahk","dummy");
    // myserv.createAccount("abdullahk","main","debit",0.0);
    // myserv.createAccount("abdullahk","secondary","credit",200.0);
    // string firstAcc = myserv.getUserAccounts("abdullahk")[0];
    // cout << firstAcc << endl;
    // myserv.Deposit(firstAcc,100.0,"salary");
    // myserv.Withdraw(firstAcc,50.0,"food");

    return 0;
}

