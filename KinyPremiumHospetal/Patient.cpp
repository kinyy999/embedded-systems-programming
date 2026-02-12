#include <iostream>
using namespace std;

#include <cstring>
#include "Patient.h"

Patient::Patient(const char* name, int birthYear, const char* gender)
    : Person(name), birthYear(0), gender(nullptr)
{
    setBirthYear(birthYear);
    setGender(gender);
}

Patient::Patient(const Patient& other)
    : Person(other), birthYear(other.birthYear), gender(nullptr)
{
    setGender(other.gender);
}

Patient& Patient::operator=(const Patient& other)
{
    if (this == &other) return *this;

    Person::operator=(other);
    birthYear = other.birthYear;
    setGender(other.gender);
    return *this;
}

Patient::~Patient()
{
    delete[] gender;
}

bool Patient::setBirthYear(int year)
{
    if (year < 1900 || year > 2100)
        return false;
    birthYear = year;
    return true;
}

bool Patient::setGender(const char* g)
{
    if (!g) return false;

    delete[] gender;
    gender = new char[strlen(g) + 1];
    strcpy(gender, g);
    return true;
}

void Patient::toOs(ostream& os) const
{
    os << "Patient | Name: " << getName()
       << " | BirthYear: " << birthYear
       << " | Gender: " << (gender ? gender : "");
}
