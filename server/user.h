#ifndef USER_H
#define USER_H

#include <string>
#include <ctime>
#include <vector>
#include "./database/database.h"
#include <cereal/access.hpp>

using namespace std;



class user
{
private:
    friend class database;

    string userName;
    string password;
    string fullName;
    string nationalID;
    string nationality;
    string martialStatus;
    string phoneNo;
    string DOB;
    vector<string> accounts;

    friend class cereal::access;
    
    template <class Archive>
    void serialize(Archive& Data) {
        Data(userName, password, fullName, nationalID, nationality, martialStatus, phoneNo, DOB,accounts);
    }

public:
    user(){};
    user(string userName, string password);
    void addInfo(string fullName, string nationalID, string nationality, string martialStatus,string phoneNo,time_t DOB);
    string get_userName();
    ~user();
};




#endif