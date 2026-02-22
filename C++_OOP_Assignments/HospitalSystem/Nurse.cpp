#include <iostream>
using namespace std;

#include "Nurse.h"

Nurse::Nurse(const string& name, int experienceYears)
    : Employee(name), experienceYears(experienceYears)
{
}

Nurse::Nurse(const Nurse& other)
    : Employee(other), experienceYears(other.experienceYears)
{
}

void Nurse::toOs(ostream& os) const
{
    os << "Nurse | ";
    Employee::toOs(os);
    os << " | Experience: " << experienceYears;
}
