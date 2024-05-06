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
    friend class server;
    friend class cereal::access;

    string TransactionID;
    string TransType;
    string timeStamp;
    double ammount;
    string src_acc;
    string dest_acc;
    string details;

    template <class Archive>
    void serialize(Archive& Data) {
        Data(CEREAL_NVP(TransactionID)
                ,CEREAL_NVP(TransType)
                ,CEREAL_NVP(timeStamp)
                ,CEREAL_NVP(ammount)
                ,CEREAL_NVP(src_acc)
                ,CEREAL_NVP(dest_acc)
                ,CEREAL_NVP(details) );
    }

    transactions();
    transactions( string TransactionID, string TransType, string timeStamp,double ammount,string src_acc,string dest_acc,string details);
    transactions(string TransactionID, string TransType, double ammount, string src_acc, string dest_acc, string details);
public:


    ~transactions();
};


#endif