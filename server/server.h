#ifndef SERVER_H
#define SERVER_H

#include "database/database.h"
#include <boost/uuid/uuid.hpp>
#include <boost/uuid/uuid_generators.hpp>
#include <boost/uuid/uuid_io.hpp>



class server    //facade class?
{
private:
    database* db;
    string generateUniqueID();
    user* getUser(string usrName);
    account *getAccount(string accName);
    transactions *getTransaction(string transName);

    bool makeSingleTrans(string SrcAccountID, string DestAccountID, double amount, string transType, string details);

public:
    server();
    ~server();

    void createUser(string usrName, string Password);
    bool login(string usrName, string Password);
    bool createAccount(string usrName, string accName,string accountType, double startingBal);
    bool transferMoney(string SrcAccountID, string DestAccountID,double amount, string transType,string details);
    vector<string> getUserAccounts(string usrName);
    
    bool Deposit(string SrcAccountID, double amount, string details);
    bool Withdraw(string SrcAccountID, double amount, string details);
};

#endif