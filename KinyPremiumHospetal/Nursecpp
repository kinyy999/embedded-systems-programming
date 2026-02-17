
#include "Department_Header.h"
#include <iostream>
using namespace std;

#include "Nurse_Header.h"

Nurse::Nurse(const char* name, int yearsOfExperience)
    : Employee(name), yearsOfExperience(yearsOfExperience)
{
    if (this->yearsOfExperience < 0)
        this->yearsOfExperience = 0;
}

Nurse::Nurse(const Nurse& other)
    : Employee(other), yearsOfExperience(other.yearsOfExperience)
{
}

Nurse& Nurse::operator=(const Nurse& other)
{
    if (this == &other)
        return *this;

    Employee::operator=(other); 
    yearsOfExperience = other.yearsOfExperience;
      
    return *this;
}

bool Nurse::setYearsOfExperience(int years)
{
    if (years < 0)
        return false;
    yearsOfExperience = years;
    return true;
}

void Nurse::toOs(ostream& os) const
{
    os << "Nurse | ";
    Employee::toOs(os);
    os << " | Experience: " << yearsOfExperience;

    if (department)
        os << " | Department: " << getDepartment()->getDepartmentName();
}
