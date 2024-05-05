#include "database.h"



database* database::instancePtr = nullptr;

// get singleton class instance
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

// these overloaded functions will store the appropriate object in corresponding path
// and appropriate name.

void database::store(user *obj)
{
    string curDir = dirPath + "users/";
    string filePath = curDir + obj->userName+".json";

    ofstream oFile(filePath);
    cereal::JSONOutputArchive OArchive(oFile);

    user temp = *obj;
    OArchive(temp);

}

void database::store(transactions *obj)
{
    string curDir = dirPath + "transactions/";
    string filePath = curDir + obj->TransactionID +".json";

    ofstream oFile(filePath);
    cereal::JSONOutputArchive OArchive(oFile);

    transactions temp = *obj;
    OArchive(temp);

}

void database::store(account *obj)
{
    string curDir = dirPath + "accounts/";
    string filePath = curDir + obj->AccountID +".json";

    ofstream oFile(filePath);
    cereal::JSONOutputArchive OArchive(oFile);

    account temp = *obj;
    OArchive(temp);

}

// function that returns user obj read from file

user database::loadUser(string usrName)
{
    string curDir = dirPath + "users/";
    string filePath = curDir + usrName+".json";

    ifstream iFile(filePath);

    if (iFile.fail()) {
    throw -1;
    }

    cereal::JSONInputArchive IArchive(iFile);

    user obj;

    IArchive(obj);

    return obj;

}

account database::loadAccount(string accName)
{
    string curDir = dirPath + "accounts/";
    string filePath = curDir + accName+".json";

    ifstream iFile(filePath);

    if (iFile.fail()) {
        throw -1;
    }

    cereal::JSONInputArchive IArchive(iFile);

    account obj;

    IArchive(obj);

    return obj;

}

transactions database::loadTransaction(string transName)
{
    string curDir = dirPath + "accounts/";
    string filePath = curDir + transName+".json";

    ifstream iFile(filePath);

    if (iFile.fail()) {
        throw -1;
    }

    cereal::JSONInputArchive IArchive(iFile);

    transactions obj;

    IArchive(obj);

    return obj;

}