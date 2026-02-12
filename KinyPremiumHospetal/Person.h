#ifndef _PERSON_H_
#define _PERSON_H_
#include <iostream>
using namespace std;

class Person
{
protected:
    char* name;

public:
    Person(const char* name);
    Person(const Person& other);
    Person& operator=(const Person& other);
    virtual ~Person();

    const char* getName() const       { return name; }
    bool        setName(const char* name);

    virtual void toOs(ostream& os) const = 0;
    friend ostream& operator<<(ostream& os ,const Person& p);
};

#endif