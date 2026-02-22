#include <iostream>
using namespace std;

#include "Employee.h"

int Employee::nextSerial = 1;

Employee::Employee(const string& name)
    : Person(name), serialNumber(nextSerial++), department(nullptr)
{
}

Employee::Employee(const Employee& other)
    : Person(other), serialNumber(nextSerial++), department(other.department)
{
}

Employee& Employee::operator=(const Employee& other)
{
    if (this == &other)
        return *this;

    Person::operator=(other);      
    department = other.department; 
    return *this;
}

void Employee::toOs(ostream& os) const
{
    os << "Employee #" << serialNumber << " Name: " << getName();
}


