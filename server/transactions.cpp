#include "transactions.h"


transactions::transactions(/* args */)
{
    
}

transactions::transactions( string TransactionID, string TransType, string timeStamp,
    double ammount,string src_acc,string dest_acc,string details):TransactionID(TransactionID),TransType(TransType),
    timeStamp(timeStamp),ammount(ammount),src_acc(src_acc),dest_acc(dest_acc),details(details)
    {}

transactions::transactions( string TransactionID, string TransType,
    double ammount,string src_acc,string dest_acc,string details):TransactionID(TransactionID),TransType(TransType),
    timeStamp(timeStamp),ammount(ammount),src_acc(src_acc),dest_acc(dest_acc),details(details)
    {
        //get current time stamp
        std::time_t now = std::time(nullptr);
        char buffer[80];
        std::strftime(buffer, sizeof(buffer), "%c", std::localtime(&now));
        timeStamp = buffer;
    }
transactions::~transactions()
{
}
