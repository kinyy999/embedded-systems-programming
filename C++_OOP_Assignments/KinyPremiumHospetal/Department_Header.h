#ifndef DEPARTMENT_HEADER_H
#define DEPARTMENT_HEADER_H

#include <iostream>
using namespace std;

class Employee;

class Department
{
private:
    Employee** staff;
    int phisicalNumOfStaff, logicalNumOfStaff;

    char* departmentName;

    int Department_ID;
    static int departmentGenerator;

public:
    Department(const char* departmentName);
    Department(const Department& other) = delete;
    Department& operator=(const Department& other) = delete;
    ~Department();

    friend ostream& operator<<(ostream& os, const Department& d);

    void setDepartmentName(const char* newDepartmentName);
    const char* getDepartmentName() const;
    const int getDepartment_ID() const;

    bool EmployeeExist(const Employee& e) const;
    bool assignEmployee(Employee& e);
};

#endif
