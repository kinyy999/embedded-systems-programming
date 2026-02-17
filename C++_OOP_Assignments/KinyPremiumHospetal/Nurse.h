#ifndef _NURSE_H_
#define _NURSE_H_

#include "Employee.h"

class Department;

class Nurse : public Employee
{
private:
    int         yearsOfExperience;


public:
    Nurse(const char* name, int yearsOfExperience);
    Nurse(const Nurse& other);
    Nurse& operator=(const Nurse& other);
    virtual ~Nurse() = default;

    int getYearsOfExperience() const { return yearsOfExperience; }
    bool setYearsOfExperience(int years);

    virtual Employee* clone() const override { return new Nurse(*this); } 
    virtual void toOs(ostream& os) const override;
};

#endif