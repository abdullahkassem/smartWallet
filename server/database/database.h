#ifndef DATABASE_H
#define DATABASE_H

#include <filesystem>
#include <string>
#include <iostream>
#include "../user.h"
#include "../account.h"
#include "../transactions.h"

// #include <boost/filesystem.hpp>


using namespace std;


class database // singleton class
{
private:
    string dirPath;
    static database* instancePtr; 
    database(){dirPath = "./database/";  };
    
public:
    database(const database& obj) = delete; // deleting copy constructor
    static database* getInstance();
    void viewPath();

    void store(user* obj);
    void store(account* obj);
    void store(transactions* obj);
    
    user* load(string userID);

};


database* database::instancePtr = nullptr;


database* database::getInstance(){
    if (instancePtr == NULL) 
    {
        instancePtr = new database(); 
        return instancePtr; 
    }
    else
    {
        return instancePtr;
    }
}

void database::viewPath()
{
    cout << "database path is "<<dirPath << endl;
}



#endif

