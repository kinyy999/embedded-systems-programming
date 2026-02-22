#include <iostream>
using namespace std;

#include "Doctor.h"
#include "Department.h"

Doctor::Doctor(const string& name, const string& spec)
    : Employee(name), specialization(spec)
{
}

Doctor::Doctor(const Doctor& other)
    : Employee(other), specialization(other.specialization)
{
}

void Doctor::toOs(ostream& os) const
{
    os << "Doctor | ";
    Employee::toOs(os);

    const string spec = getSpecialization();
    os << " | Specialization: " << (!spec.empty() ? spec : "");

    if (getDepartment() != nullptr)
        os << " | Department: " << getDepartment()->getDepartmentName();
}









