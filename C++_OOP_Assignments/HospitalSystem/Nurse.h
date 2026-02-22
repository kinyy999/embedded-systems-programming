#ifndef _NURSE_H_
#define _NURSE_H_

#include "Employee.h"

class Nurse : public Employee
{
private:
    int experienceYears;

public:
    Nurse(const string& name, int experienceYears);
    Nurse(const Nurse& other);

    virtual ~Nurse() = default;

    int getExperienceYears() const { return experienceYears; }

    virtual Employee* clone() const override { return new Nurse(*this); }
    virtual void toOs(ostream& os) const override;
};

#endif