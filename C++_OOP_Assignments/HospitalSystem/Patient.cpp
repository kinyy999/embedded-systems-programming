#include <iostream>
using namespace std;

#include "Patient.h"

Patient::Patient(const string& name, int birthYear, const string& gender)
    : Person(name), birthYear(birthYear), gender(gender)
{
}

Patient::Patient(const Patient& other)
    : Person(other), birthYear(other.birthYear), gender(other.gender)
{
}

Patient::~Patient()
{
}

void Patient::toOs(ostream& os) const
{
    os << "Patient | Name: " << getName()
       << " | BirthYear: " << birthYear
       << " | Gender: " << gender;
}
