#ifndef _DOCTOR_H_
#define _DOCTOR_H_

#include "Employee.h"

class Department;

class Doctor : virtual public Employee
{
private:
    string specialization;
    

public:
    Doctor(const string& name, const string& specialization);
    Doctor(const Doctor& other);

    virtual ~Doctor();

    const string& getSpecialization() const { return specialization; }
    
    virtual Employee* clone() const override { return new Doctor(*this); } 
    virtual void toOs(ostream& os) const override;
};

#endif
