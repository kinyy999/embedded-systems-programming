#ifndef _EMPLOYEE_H_
#define _EMPLOYEE_H_

#include "Person.h"

class Department;

class Employee : public Person
{
protected:
    static int nextSerial;
    int serialNumber;
    Department* department;

public:
    Employee(const char* name);
    Employee(const Employee& other);
    Employee& operator=(const Employee& other);
    virtual ~Employee() = default;

    int getSerialNumber() const { return serialNumber; }

    Department* getDepartment() const { return department; }
    void setDepartment(Department* dep) { department = dep; }

    virtual Employee* clone() const = 0;          
    virtual void toOs(ostream& os) const override;
};

#endif
