#include "account.h"

account::account(/* args */)
{
}

account::account(string AccountID,string accountName,string ownerID,string accType, double balance):AccountID(AccountID),accountName(accountName),ownerID(ownerID),accType(accType),balance(balance)
{
    listOfTrans = vector<string>();
}

account::~account()
{
}