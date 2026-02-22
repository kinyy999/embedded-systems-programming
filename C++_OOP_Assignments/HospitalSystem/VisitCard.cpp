#include "VisitCard.h"
#include "Patient.h"
#include "Department.h"
#include "Employee.h"

#include <iostream>
using namespace std;

VisitCard::VisitCard(Patient* patient,
                     Department* department,
                     Employee* caregiver,
                     const string& arrivalDate,
                     const string& purpose)
    : patient(patient),
      department(department),
      caregiver(caregiver),
      arrivalDate(arrivalDate),
      purpose(purpose)
{
}

Patient* VisitCard::getPatient() const
{
    return patient;
}

Department* VisitCard::getDepartment() const
{
    return department;
}

Employee* VisitCard::getCaregiver() const
{
    return caregiver;
}

const string& VisitCard::getArrivalDate() const
{
    return arrivalDate;
}

const string& VisitCard::getPurpose() const
{
    return purpose;
}

void VisitCard::toOs(ostream& os) const
{
    os << "VisitCard\n";
    os << "Patient: " << *patient << "\n";
    os << "ArrivalDate: " << arrivalDate << "\n";
    os << "Purpose: " << purpose << "\n";
    os << "Department: " << department->getDepartmentName() << "\n";
    os << "Caregiver: " << *caregiver << "\n";
}

ostream& operator<<(ostream& os, const VisitCard& visit)
{
    visit.toOs(os);
    return os;
}