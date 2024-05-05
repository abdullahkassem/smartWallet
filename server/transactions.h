#ifndef TRANSACTIONS_H
#define TRANSACTIONS_H

#include <string>
#include <ctime>
#include <iostream>
using namespace std;

class transactions
{
private:
    string TransactionID;
    string TransType;
    time_t timeStamp;
    double ammount;
    string src_acc;
    string dest_acc;
    string details;
    
public:
    transactions();
    ~transactions();
};


#endif