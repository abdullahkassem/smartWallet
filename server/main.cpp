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

    myserv.login("abdullahk","dummy");
    // myserv.createAccount("abdullahk","debit",0.0);

    return 0;
}

