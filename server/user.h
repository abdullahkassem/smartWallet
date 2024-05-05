#ifndef USER_H
#define USER_H

#include <string>
#include <ctime>
#include <vector>
#include "./database/database.h"
using namespace std;

class database;

class user
{
private:
    friend database;

    string userName;
    string password;
    string fullName;
    string nationalID;
    string nationality;
    string martialStatus;
    string phoneNo;
    time_t DOB;
    vector<string> accounts;
public:
    user(){};
    user(string userName, string password);
    void addInfo(string fullName, string nationalID, string nationality, string martialStatus,string phoneNo,time_t DOB);
    string get_userName();
    ~user();
};




#endif