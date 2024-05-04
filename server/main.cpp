#include <iostream>
#include <fstream>
#include <cereal/archives/binary.hpp>
#include "./database/database.h"

using namespace std;

int main(){
    database* db = database::getInstance();
    db->viewPath();
    return 0;
}

