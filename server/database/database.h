#ifndef DATABASE_H
#define DATABASE_H

#include <cereal/archives/binary.hpp>
#include <cereal/types/string.hpp>
#include <cereal/types/vector.hpp>
#include <cereal/archives/json.hpp>

#include <filesystem>
#include <fstream>
#include <string>
#include <iostream>
#include "../user.h"
#include "../account.h"
#include "../transactions.h"
// #include "../server.h"

// #include <boost/filesystem.hpp>


using namespace std;

class user;
class account;
class transactions;

class database // singleton class
{
private:
    friend class server;

    string dirPath;
    static database* instancePtr; 
    database(){dirPath = "./database/";};

    void store(user* obj);
    void store(account* obj);
    void store(transactions* obj);
    
    user loadUser(string userID);
    account loadAccount(string accName);
    transactions loadTransaction(string transName);
    
public:
    database(const database& obj) = delete; // deleting copy constructor
    static database* getInstance();

    void viewPath();

    

};



#endif

