#include "user.h"

user::user(string userName, string password):userName(userName),password(password)
{
    
}

string user::get_userName()
{
    return userName;
}

user::~user()
{
}