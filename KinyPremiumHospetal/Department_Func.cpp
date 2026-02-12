#include <iostream>
using namespace std;

#include <cstring>
#include "Department_Header.h"
#include "Employee.h"

int Department::departmentGenerator = 10;

Department::Department(const char* depName)
    : staff(nullptr),
      phisicalNumOfStaff(2),
      logicalNumOfStaff(0),
      departmentName(nullptr),
      Department_ID(departmentGenerator++)
{
    setDepartmentName(depName);
    staff = new Employee*[phisicalNumOfStaff];
}

bool Department::EmployeeExist(const Employee& e) const
{
    for (int i = 0; i < logicalNumOfStaff; i++)
        if (staff[i]->getSerialNumber() == e.getSerialNumber())
            return true;
    return false;
}

bool Department::assignEmployee(Employee& e)
{
    if (EmployeeExist(e))
        return false;

    if (logicalNumOfStaff == phisicalNumOfStaff)
    {
        phisicalNumOfStaff *= 2;
        Employee** temp = new Employee*[phisicalNumOfStaff];
        for (int i = 0; i < logicalNumOfStaff; i++)
            temp[i] = staff[i];

        delete[] staff;
        staff = temp;
    }

    staff[logicalNumOfStaff++] = &e;
    e.setDepartment(this);
    return true;
}

const char* Department::getDepartmentName() const
{
    return departmentName;
}

void Department::setDepartmentName(const char* newName)
{
    if (!newName) return;

    delete[] departmentName;
    departmentName = new char[strlen(newName) + 1];
    strcpy(departmentName, newName);
}

const int Department::getDepartment_ID() const
{
    return Department_ID;
}

ostream& operator<<(ostream& os, const Department& d)
{
    os << "Department_ID : " << d.getDepartment_ID()
       << "   DepartmentName : " << d.getDepartmentName() << "\n";

    for (int i = 0; i < d.logicalNumOfStaff; i++)
        os << *d.staff[i] << "\n";

    return os;
}

Department::~Department()
{
    delete[] staff;
    delete[] departmentName;
}
