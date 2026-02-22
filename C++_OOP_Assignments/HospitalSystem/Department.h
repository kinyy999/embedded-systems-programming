#ifndef DEPARTMENT_HEADER_H
#define DEPARTMENT_HEADER_H

#include <iostream>
#include <list>
#include <string>
using namespace std;

class Employee;

class Department
{
private:
    list<Employee*> staff;      
    string departmentName;     
    int Department_ID;

    static int departmentGenerator;

public:
    Department(const char* departmentName);
    Department(const Department& other) = delete;
    Department& operator=(const Department& other) = delete;
    ~Department() = default;

    friend ostream& operator<<(ostream& os, const Department& d);

    void setDepartmentName(const char* newDepartmentName);
    const char* getDepartmentName() const { return departmentName.c_str(); }

    int getDepartment_ID() const { return Department_ID; }

    // NEW: used by Hospital to assign stable IDs
    void setDepartmentID(int newId) { Department_ID = newId; }

    bool EmployeeExist(const Employee& e) const;
    bool assignEmployee(Employee& e);

    int getLogicalNumOfStaff() const { return (int)staff.size(); }
    Employee* getStaffAt(int index) const;
};

#endif