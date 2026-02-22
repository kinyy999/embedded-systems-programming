#include <iostream>
using namespace std;

#include "DoctorResearcher.h"
#include "Department.h"

DoctorResearcher::DoctorResearcher(const string& name, const string& specialization, int maxArticles)
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
    if (this == &other)
        return *this;

    Employee::operator=(other);
    Doctor::operator=(other);
    Researcher::operator=(other);

    return *this;
}

void DoctorResearcher::toOs(ostream& os) const
{
    os << "DoctorResearcher | ";

    Employee::toOs(os);

    const string spec = getSpecialization();
    os << " | Specialization: " << (spec.empty() ? "" : spec);

    if (getDepartment() != nullptr)
        os << " | Department: " << getDepartment()->getDepartmentName();

    const int n = getNumOfArticles();
    os << " | Articles: " << n;

    if (n > 0)
    {
        os << " [";
        for (int i = 0; i < n; i++)
        {
            os << getArticle(i);
            if (i != n - 1)
                os << " ; ";
        }
        os << " ]";
    }
}