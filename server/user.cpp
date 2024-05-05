#include "user.h"

user::user(string userName, string password):userName(userName),password(password)
{
    
}

void user::addInfo(string fullName, string nationalID, string nationality, string martialStatus, string phoneNo, time_t DOB)
{
    this->fullName = fullName;
    this->nationalID = nationalID;
    this->nationality = nationality;
    this->martialStatus = martialStatus;
    this->phoneNo = phoneNo;
    this->DOB = DOB;
    this->accounts = vector<string>();
}

string user::get_userName()
{
    return userName;
}

user::~user()
{
}