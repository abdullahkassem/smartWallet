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
    friend class server;

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
        Data(CEREAL_NVP(userName), CEREAL_NVP(password), CEREAL_NVP(fullName),CEREAL_NVP( nationalID), CEREAL_NVP(nationality), CEREAL_NVP(martialStatus), CEREAL_NVP(phoneNo),CEREAL_NVP( DOB),CEREAL_NVP(accounts) );
    }

    user(){};
    user(string userName, string password);
    void addInfo(string fullName, string nationalID, string nationality, string martialStatus,string phoneNo,time_t DOB);
    string get_userName();
    ~user();

public:
    
};




#endif