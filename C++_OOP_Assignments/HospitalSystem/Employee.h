#ifndef _EMPLOYEE_H_
#define _EMPLOYEE_H_

#include <iostream>
using namespace std;

#include "Person.h"

class Department;

class Employee : public Person
{
protected:
    static int nextSerial;
    int serialNumber;
    Department* department;

public:
    Employee(const string& name);
    Employee(const Employee& other);
    Employee& operator=(const Employee& other);
    virtual ~Employee() = default;

    int getSerialNumber() const { return serialNumber; }

    void setSerialNumber(int newSerial) { serialNumber = newSerial; }

    Department* getDepartment() const { return department; }
    void setDepartment(Department* dep) { department = dep; }

    virtual Employee* clone() const = 0;
    virtual void toOs(ostream& os) const override;
};

#endif