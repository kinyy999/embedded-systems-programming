
#include <cstring>

#include <iostream>
using namespace std;

#include "Person.h"

Person::Person(const string& name) : name(name)
{
}

Person::Person(const Person& other) : name(other.name)
{
}

Person::~Person()
{
}

ostream& operator<<(ostream& os ,const Person& p)
{
    p.toOs(os);
    return os;

} 