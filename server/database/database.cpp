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

    cout << "file will be stored at "<< filePath << endl;


    ofstream oFile(filePath);
    cereal::JSONOutputArchive OArchive(oFile);

    string s1 = obj->userName;
    string s2 = obj->password;
    string s3 = obj-> fullName;
    string s4 = obj-> nationalID;
    string s5 = obj-> nationality;
    string s6 = obj-> martialStatus;
    string s7 = obj-> phoneNo;
    time_t s8 = obj-> DOB;
    vector<string> s9 = obj-> accounts;

    OArchive(s1,s2,s3,s4,s5,s6,s7,s8,s9);

}

user* database::loadUser(string usrName)
{
    string curDir = dirPath + "users/";
    string filePath = curDir + usrName+".json";

    cout << "file will be loaded from "<< filePath << endl;

    ifstream iFile(filePath);

    if (iFile.fail()) {
    std::cerr << "Error opening file!" << std::endl;
    // Handle the error (e.g., exit the program, prompt for a new filename)
    // throw;
    }

    cereal::JSONInputArchive IArchive(iFile);

    string s1 ;
    string s2 ;
    string s3 ;
    string s4 ;
    string s5 ;
    string s6 ;
    string s7 ;
    time_t s8 ;
    vector<string> s9;

    IArchive(s1);
    // IArchive(s2);

    user* obj = new user(s1,s2);

    return obj;

}