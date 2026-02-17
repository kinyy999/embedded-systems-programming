
#include <cstring>

#include <iostream>
using namespace std;

#include "Person.h"

Person::Person(const char* name) : name(nullptr)
{
    setName(name);
}

Person::Person(const Person& other) : name(nullptr)
{
    setName(other.name);
}

Person& Person::operator=(const Person& other)
{
    if (this == &other)
        return *this;

    setName(other.name);
    return *this;
}

Person::~Person()
{
    delete[] name;
}

bool Person::setName(const char* name)
{
    if (!name)
        return false;

    delete[] this->name;
    this->name = new char[strlen(name) + 1];
    strcpy(this->name, name);
    return true;
}

ostream& operator<<(ostream& os ,const Person& p)
{
    p.toOs(os);
    return os;

} 