#include <iostream>
using namespace std;

#include "DoctorResearcher.h"
#include "Department_Header.h"


DoctorResearcher::DoctorResearcher(const char* name, const char* specialization, int maxArticles)
    : Employee(name),               
      Doctor(name, specialization), 
      Researcher(name, maxArticles) 
{
}

DoctorResearcher::DoctorResearcher(const DoctorResearcher& other)
    : Employee(other),
      Doctor(other),
      Researcher(other)
{
}

DoctorResearcher& DoctorResearcher::operator=(const DoctorResearcher& other)
{
    if (this == &other) return *this;

    Employee::operator=(other);
    Doctor::operator=(other);
    Researcher::operator=(other);

    return *this;
}

void DoctorResearcher::toOs(ostream& os) const
{
    os << "DoctorResearcher | ";

    Employee::toOs(os);

    os << " | Specialization: " << (getSpecialization() ? getSpecialization() : "");

    if (getDepartment())
        os << " | Department: " << getDepartment()->getDepartmentName();

    os << " | Articles: " << getNumOfArticles()<<endl;
    if (getNumOfArticles() > 0)
    {
        os << " [";
        for (int i = 0; i < getNumOfArticles(); i++)
        {
            os << *getArticle(i);
           if (i != getNumOfArticles() - 1)
                os << " ; ";
        }
        os << " ]";
    }

}
