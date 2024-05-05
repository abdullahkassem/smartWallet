#include <iostream>
#include <fstream>
#include <cereal/archives/binary.hpp>
#include "./database/database.h"
#include "user.h"

using namespace std;

int main(){
    database* db = database::getInstance();
    db->viewPath();

    user u1 = user("abdullah","pass");
    db->store(&u1);
    user* test = db->loadUser("abdullah");
    cout << "read this user name"<<test->get_userName()<<endl;

    return 0;
}

