#include <iostream>
using namespace std;


#include "Employee.h"

int Employee::nextSerial = 1;

Employee::Employee(const string& name)
    : Person(name), department(nullptr)
{
    serialNumber = nextSerial++;
}

Employee::Employee(const Employee& other)
    : Person(other), serialNumber(other.serialNumber)
{
}

Employee& Employee::operator=(const Employee& other)
{
    if (this == &other)
        return *this;

    Person::operator=(other);
    serialNumber = other.serialNumber;
    return *this;
}

void Employee::toOs(ostream& os) const
{
    os << "Employee #" << serialNumber << " ";
    os << "Name: " << getName();
}



