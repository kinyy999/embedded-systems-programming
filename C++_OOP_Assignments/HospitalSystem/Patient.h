#ifndef _PATIENT_H_
#define _PATIENT_H_

#include "Person.h"
#include <iostream>
using namespace std;

class Patient : public Person
{
private:
    int   birthYear;
    string gender;     

public:
    Patient(const string& name, int birthYear, const string& genderIs);
    Patient(const Patient& other);
    virtual ~Patient();

    int getBirthYear() const { return birthYear; }
    const string& getGender() const { return gender; }

    bool setBirthYear(int year);


    virtual void toOs(ostream& os) const override;
};

#endif
