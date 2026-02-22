#ifndef _PATIENT_H_
#define _PATIENT_H_

#include <iostream>
using namespace std;

#include "Person.h"

class Patient : public Person
{
private:
    int birthYear;
    string gender;

public:
    Patient(const string& name, int birthYear, const string& gender);
    Patient(const Patient& other);

    virtual ~Patient();

    int getBirthYear() const { return birthYear; }
    const string& getGender() const { return gender; }

    virtual void toOs(ostream& os) const override;
};

#endif