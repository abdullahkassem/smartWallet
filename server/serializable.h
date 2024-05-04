#ifndef SERIALIZABLE_H
#define SERIALIZABLE_H

#include <string>
using namespace std;

class serializable
{
private:
    /* data */
public:
    ~serializable();
    virtual void serialize(string fileName) ;
    virtual void deserialize(string fileName) = 0;
};



#endif