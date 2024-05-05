#include "transactions.h"


transactions::transactions(/* args */)
{
    
}

transactions::transactions( string TransactionID, string TransType, string timeStamp,
    double ammount,string src_acc,string dest_acc,string details):TransactionID(TransactionID),TransType(TransType),
    timeStamp(timeStamp),ammount(ammount),src_acc(src_acc),dest_acc(dest_acc),details(details)
    {}

transactions::~transactions()
{
}
