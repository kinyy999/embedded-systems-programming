#ifndef _DOCTOR_H_
#define _DOCTOR_H_

#include "Employee.h"

class Department;

class Doctor : virtual public Employee
{
private:
    char* specialization;
    

public:
    Doctor(const char* name, const char* specialization);
    Doctor(const Doctor& other);
    Doctor& operator=(const Doctor& other);
    virtual ~Doctor();

    const char* getSpecialization() const { return specialization; }
    bool setSpecialization(const char* spec);

    virtual Employee* clone() const override { return new Doctor(*this); } 
    virtual void toOs(ostream& os) const override;
};

#endif
