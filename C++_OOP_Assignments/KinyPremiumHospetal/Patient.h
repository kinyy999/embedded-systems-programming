#ifndef _PATIENT_H_
#define _PATIENT_H_

#include "Person.h"
#include <iostream>
using namespace std;

class Patient : public Person
{
private:
    int   birthYear;
    char* gender;     

public:
    Patient(const char* name, int birthYear, const char* gender);
    Patient(const Patient& other);
    Patient& operator=(const Patient& other);
    virtual ~Patient();

    int getBirthYear() const { return birthYear; }
    const char* getGender() const { return gender; }

    bool setBirthYear(int year);
    bool setGender(const char* g);

    virtual void toOs(ostream& os) const override;
};

#endif
