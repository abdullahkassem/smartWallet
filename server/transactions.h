#ifndef TRANSACTIONS_H
#define TRANSACTIONS_H

#include <string>
#include <ctime>
#include <iostream>
#include <cereal/access.hpp>
#include "./database/database.h"

using namespace std;

class transactions
{
private:
    friend class database;    
    friend class cereal::access;
    
    string TransactionID;
    string TransType;
    time_t timeStamp;
    double ammount;
    string src_acc;
    string dest_acc;
    string details;

    template <class Archive>
    void serialize(Archive& Data) {
        Data(TransactionID
                ,TransType
                ,timeStamp
                ,ammount
                ,src_acc
                ,dest_acc
                ,details );
    }
    
public:
    transactions();
    ~transactions();
};


#endif