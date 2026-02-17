#ifndef _PERSON_H_
#define _PERSON_H_
#include <iostream>
using namespace std;

class Person
{
protected:
    string name;

public:
    Person(const string& name);
    Person(const Person& other);
    
    virtual ~Person();

    const string& getName() const       { return name; }
    

    virtual void toOs(ostream& os) const = 0;
    friend ostream& operator<<(ostream& os ,const Person& p);
};

#endif