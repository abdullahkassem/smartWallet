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
        Data(TransactionID
                ,TransType
                ,timeStamp
                ,ammount
                ,src_acc
                ,dest_acc
                ,details );
    }

    transactions();
    transactions( string TransactionID, string TransType, string timeStamp,double ammount,string src_acc,string dest_acc,string details);
    transactions(string TransactionID, string TransType, double ammount, string src_acc, string dest_acc, string details);
public:


    ~transactions();
};


#endif