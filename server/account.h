#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <string>
#include <cereal/access.hpp>
#include "./database/database.h"

using namespace std;

class account
{
private:
    friend class database;
    friend class server;    

    string AccountID;
    string ownerID;
    string accountName;
    double balance=0;
    string accType;
    vector<string> listOfTrans;

    friend class cereal::access;
    
    template <class Archive>
    void serialize(Archive& Data) {
        Data( CEREAL_NVP(AccountID),
                CEREAL_NVP(accountName),
                CEREAL_NVP(ownerID),
                CEREAL_NVP(balance),
                CEREAL_NVP(accType),
                CEREAL_NVP(listOfTrans) );
    }

    account(/* args */);
    account(string AccountID,string accountName,string ownerID,string accType, double balance);

public:
    
    ~account();
};





#endif