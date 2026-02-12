#include "VisitCard.h"
#include <cstring>

#include "Patient.h"
#include "Department_Header.h"
#include "Employee.h"

void VisitCard::setStr(char*& dest, const char* src)
{
    if (!src) src = "";
    delete[] dest;
    dest = new char[strlen(src) + 1];
    strcpy(dest, src);
}

VisitCard::VisitCard(Patient* p, Department* dep, const char* aDate, const char* purp)
    : patient(p),
      department(dep),
      caregiver(nullptr),
      arrivalDate(nullptr),
      purpose(nullptr)
{
    setStr(arrivalDate, aDate);
    setStr(purpose, purp);
}

VisitCard::~VisitCard()
{
    delete[] arrivalDate;
    delete[] purpose;
}

void VisitCard::toOs(ostream& os) const
{
    os << "VisitCard\n";
    os << "Patient: " << *patient << "\n";
    os << "ArrivalDate: " << (arrivalDate ? arrivalDate : "") << "\n";
    os << "Purpose: " << (purpose ? purpose : "") << "\n";
    os << "Department: " << (department ? department->getDepartmentName() : "None") << "\n";

    os << "Caregiver: ";
    if (caregiver)
        os << *caregiver << "\n";
    else
        os << "None\n";
}

ostream& operator<<(ostream& os, const VisitCard& v)
{
    v.toOs(os);
    return os;
}
