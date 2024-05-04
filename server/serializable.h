#ifndef SERIALIZABLE_H
#define SERIALIZABLE_H

#include <string>
#include <boost/archive/text_oarchive.hpp>
#include <boost/archive/text_iarchive.hpp>

using namespace std;

class serializable
{
private:
    friend class boost::serialization::access;
    string test1 = "hello";
    string test2 = "world";
    /* data */
public:
    ~serializable();
    template<class Archive>
    void serialize(Archive & ar, const unsigned int version)
    {
        ar & test1;
        ar & test2;
        
    }
    
};



#endif