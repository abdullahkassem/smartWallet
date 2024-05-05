#include "database.h"



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

void database::store(user *obj)
{
    string curDir = dirPath + "users/";
    string filePath = curDir + obj->userName+".json";

    // cout << "file will be stored at "<< filePath << endl;

    ofstream oFile(filePath);
    cereal::JSONOutputArchive OArchive(oFile);

    user temp = *obj;
    OArchive(temp);

}

void database::store(transactions *obj)
{
    string curDir = dirPath + "transactions/";
    string filePath = curDir + obj->TransactionID +".json";

    // cout << "file will be stored at "<< filePath << endl;

    ofstream oFile(filePath);
    cereal::JSONOutputArchive OArchive(oFile);

    transactions temp = *obj;
    OArchive(temp);

}

void database::store(account *obj)
{
    string curDir = dirPath + "accounts/";
    string filePath = curDir + obj->AccountID +".json";

    // cout << "file will be stored at "<< filePath << endl;

    ofstream oFile(filePath);
    cereal::JSONOutputArchive OArchive(oFile);

    account temp = *obj;
    OArchive(temp);

}

user database::loadUser(string usrName)
{
    string curDir = dirPath + "users/";
    string filePath = curDir + usrName+".json";

    // cout << "file will be loaded from "<< filePath << endl;

    ifstream iFile(filePath);

    if (iFile.fail()) {
    std::cerr << "Error opening file!" << std::endl;
    // throw;
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

    // cout << "file will be loaded from "<< filePath << endl;

    ifstream iFile(filePath);

    if (iFile.fail()) {
    std::cerr << "Error opening file!" << std::endl;
    // throw;
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

    // cout << "file will be loaded from "<< filePath << endl;

    ifstream iFile(filePath);

    if (iFile.fail()) {
    std::cerr << "Error opening file!" << std::endl;
    // throw;
    }

    cereal::JSONInputArchive IArchive(iFile);

    transactions obj;

    IArchive(obj);

    return obj;

}