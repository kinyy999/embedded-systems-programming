#include <cstring>
#include <iostream>
using namespace std;

#include "Doctor_Header.h"
#include "Department_Header.h"   

Doctor::Doctor(const string& name, const string& spec)
    : Employee(name), specialization(spec)
{
}

Doctor::Doctor(const Doctor& other)
    : Employee(other), specialization(other.specialization)
{
}

Doctor::~Doctor()
{
}

void Doctor::toOs(ostream& os) const
{
    os << "Doctor | ";
    Employee::toOs(os);
    const string spec = getSpecialization();
    os << " | Specialization: " << (!spec.empty() ? spec : "");

    if (getDepartment())
        os << " | Department: " << getDepartment()->getDepartmentName();
}












