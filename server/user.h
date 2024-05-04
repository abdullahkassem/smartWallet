#ifndef USER_H
#define USER_H

#include <string>
#include <ctime>
using namespace std;

class user
{
private:
    string userName;
    string password;
    string fullName;
    string nationalID;
    string nationality;
    string martialStatus;
    string phoneNo;
    time_t DOB;
    string* accounts;
public:
    user(string userName, string password);
    void addInfo(string fullName, string nationalID, string nationality, string martialStatus,string phoneNo,time_t DOB);
    ~user();
};




#endif