#include <iostream>
using namespace std;

#include <cstring>
#include "Patient.h"

Patient::Patient(const string& name, int birthYear, const string& genderIs)
    : Person(name), birthYear(0), gender(genderIs)
{
    setBirthYear(birthYear);
}

Patient::Patient(const Patient& other)
    : Person(other), birthYear(other.birthYear), gender(other.gender)
{
}

bool Patient::setBirthYear(int year)
{
    if (year < 1900 || year > 2100)
        return false;
    birthYear = year;
    return true;
}


Patient::~Patient()
{
}



void Patient::toOs(ostream& os) const
{
    os << "Patient | Name: " << getName()
       << " | BirthYear: " << getBirthYear();
       const string gen = getGender();
       os << " | Gender: " << (!gen.empty() ? gender : "");
}
    
