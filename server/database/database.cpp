#include "database.h"

database::database()
{
    dirPath = "./database/";    

    // dirPath = __FILE__;
    // cout <<"path is "<< dirPath << endl;
}


database::database(string dPath): dirPath(dPath)
{
}

database::~database()
{
    
}
