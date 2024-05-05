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
    string AccountID;
    double balance;
    string accType;
    friend class cereal::access;
    
    template <class Archive>
    void serialize(Archive& Data) {
        Data( AccountID,
                balance,
                accType );
    }


public:
    account(/* args */);
    ~account();
};





#endif