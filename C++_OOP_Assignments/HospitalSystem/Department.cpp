#include <iostream>
using namespace std;

#include "Department.h"
#include "Employee.h"
#include <iterator>

int Department::departmentGenerator = 10;

Department::Department(const char* depName)
    : staff(),
      departmentName(depName ? depName : "")
{
    Department_ID = ++departmentGenerator;
}

void Department::setDepartmentName(const char* newDepartmentName)
{
    departmentName = (newDepartmentName ? newDepartmentName : "");
}

bool Department::EmployeeExist(const Employee& e) const
{
    for (Employee* ptr : staff)
    {
        if (ptr != nullptr && ptr->getSerialNumber() == e.getSerialNumber())
            return true;
    }
    return false;
}

bool Department::assignEmployee(Employee& e)
{
    if (EmployeeExist(e))
        return false;

    staff.push_back(&e);
    return true;
}

Employee* Department::getStaffAt(int index) const
{
    if (index < 0 || index >= (int)staff.size())
        return nullptr;

    auto it = staff.begin();
    advance(it, index);
    return *it;
}

ostream& operator<<(ostream& os, const Department& d)
{
    os << "Department_ID : " << d.getDepartment_ID()
       << "   DepartmentName : " << d.getDepartmentName()
       << "\n";
    return os;
}