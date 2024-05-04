#ifndef DATABASE_H
#define DATABASE_H

#include <filesystem>
#include <string>
#include <iostream>

// #include <boost/filesystem.hpp>


using namespace std;


class database
{
private:
    string dirPath;
public:
    database();
    database(string dPath);
    ~database();

    void readFile();

};

#endif

