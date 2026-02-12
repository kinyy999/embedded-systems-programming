#ifndef _VISIT_CARD_H_
#define _VISIT_CARD_H_

#include <iostream>
using namespace std;

class Patient;
class Department;
class Employee;

class VisitCard
{
private:
    Patient*    patient;      
    Department* department;    
    Employee*   caregiver;    

    char* arrivalDate;         
    char* purpose;            

    void setStr(char*& dest, const char* src);

public:
    VisitCard(Patient* p, Department* dep, const char* arrivalDate, const char* purpose);

    VisitCard(const VisitCard& other) = delete;
    VisitCard& operator=(const VisitCard& other) = delete;

    ~VisitCard();

    Patient* getPatient() const { return patient; }
    Department* getDepartment() const { return department; }
    Employee* getCaregiver() const { return caregiver; }

    const char* getArrivalDate() const { return arrivalDate; }
    const char* getPurpose() const { return purpose; }

    void setCaregiver(Employee* e) { caregiver = e; }

    void toOs(ostream& os) const;
    friend ostream& operator<<(ostream& os, const VisitCard& v);
};

#endif

