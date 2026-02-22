#ifndef _VISIT_CARD_H_
#define _VISIT_CARD_H_

#pragma once
#include <iostream>
#include <string>

using namespace std;

class Patient;
class Department;
class Employee;

class VisitCard
{
private:
    Patient* patient;
    Department* department;
    Employee* caregiver;

    string arrivalDate;
    string purpose;

public:
    VisitCard(Patient* patient,
              Department* department,
              Employee* caregiver,
              const string& arrivalDate,
              const string& purpose);

    ~VisitCard() = default;

    Patient* getPatient() const;
    Department* getDepartment() const;
    Employee* getCaregiver() const;

    const string& getArrivalDate() const;
    const string& getPurpose() const;

    void toOs(ostream& os) const;

    friend ostream& operator<<(ostream& os, const VisitCard& visit);
};

#endif

