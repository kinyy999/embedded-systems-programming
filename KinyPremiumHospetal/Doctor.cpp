#include <cstring>
#include <iostream>
using namespace std;

#include "Doctor_Header.h"
#include "Department_Header.h"   

Doctor::Doctor(const char* name, const char* spec)
    : Employee(name), specialization(nullptr)
{
    setSpecialization(spec);
}

Doctor::Doctor(const Doctor& other)
    : Employee(other), specialization(nullptr)
{
    setSpecialization(other.specialization);
}

Doctor& Doctor::operator=(const Doctor& other)
{
    if (this == &other) return *this;

    Employee::operator=(other);
    setSpecialization(other.specialization);
    department = nullptr;
    return *this;
}

Doctor::~Doctor()
{
    delete[] specialization;
}

bool Doctor::setSpecialization(const char* spec)
{
    if (!spec) return false;

    delete[] specialization;
    specialization = new char[strlen(spec) + 1];
    strcpy(specialization, spec);
    return true;
}

void Doctor::toOs(ostream& os) const
{
    os << "Doctor | ";
    Employee::toOs(os);
    os << " | Specialization: " << (specialization ? specialization : "");

    if (getDepartment())
        os << " | Department: " << getDepartment()->getDepartmentName();
}












