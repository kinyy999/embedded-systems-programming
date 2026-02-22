#include <iostream>
using namespace std;

#include <cstring>
#include <iterator>

#include "Hospital.h"
#include "Department.h"
#include "Employee.h"
#include "Patient.h"
#include "VisitCard.h"

Hospital::Hospital(const char* hName)
    : allDepartments(), allEmployees(), allPatients(), allVisits(),
      hospitalName(hName ? hName : ""),
      nextEmployeeId(1),
      nextDepartmentId(11)
{
}

Hospital::~Hospital()
{
    for (Department* d : allDepartments) delete d;
    for (Employee* e : allEmployees) delete e;
    for (Patient* p : allPatients) delete p;
    for (VisitCard* v : allVisits) delete v;
}

void Hospital::setHospitalName(const char* newHospitalName)
{
    hospitalName = (newHospitalName ? newHospitalName : "");
}

bool Hospital::DepartmentExist(const Department& d) const
{
    for (Department* ptr : allDepartments)
    {
        if (ptr && strcmp(ptr->getDepartmentName(), d.getDepartmentName()) == 0)
            return true;
    }
    return false;
}

bool Hospital::addDepartment(Department& d)
{
    if (DepartmentExist(d))
        return false;

    Department* newDep = new Department(d.getDepartmentName());

    newDep->setDepartmentID(nextDepartmentId++);

    allDepartments.push_back(newDep);
    return true;
}

bool Hospital::EmployeeExist(const Employee& e) const
{
    for (Employee* ptr : allEmployees)
    {
        if (ptr && ptr->getSerialNumber() == e.getSerialNumber())
            return true;
    }
    return false;
}

bool Hospital::addEmployee(const Employee& e)
{
    Employee* newEmp = e.clone();

    newEmp->setSerialNumber(nextEmployeeId++);

    allEmployees.push_back(newEmp);
    return true;
}

Department* Hospital::findDepartmentByName(const char* depName) const
{
    if (!depName) return nullptr;

    for (Department* d : allDepartments)
    {
        if (d && strcmp(d->getDepartmentName(), depName) == 0)
            return d;
    }
    return nullptr;
}

Employee* Hospital::findEmployeeById(int employeeId) const
{
    for (Employee* e : allEmployees)
    {
        if (e && e->getSerialNumber() == employeeId)
            return e;
    }
    return nullptr;
}

bool Hospital::assignEmployeeToDepartment(int employeeId, const char* departmentName)
{
    Department* dep = findDepartmentByName(departmentName);
    Employee* emp = findEmployeeById(employeeId);

    if (!dep || !emp)
        return false;

    if (!dep->assignEmployee(*emp))
        return false;

    emp->setDepartment(dep);
    return true;
}

bool Hospital::openVisit(const char* patientName, int birthYear, const char* gender,
                         const char* arrivalDate, const char* purpose,
                         const char* departmentName, int caregiverEmployeeId)
{
    Department* dep = findDepartmentByName(departmentName);
    Employee* caregiver = findEmployeeById(caregiverEmployeeId);

    if (!dep || !caregiver)
        return false;

    Patient* newPatient = new Patient(patientName ? patientName : "",
                                      birthYear,
                                      gender ? gender : "");
    allPatients.push_back(newPatient);

    VisitCard* visit = new VisitCard(newPatient,
                                     dep,
                                     caregiver,
                                     arrivalDate ? string(arrivalDate) : string(""),
                                     purpose ? string(purpose) : string(""));
    allVisits.push_back(visit);

    return true;
}

VisitCard* Hospital::getVisit(int index) const
{
    if (index < 0 || index >= (int)allVisits.size())
        return nullptr;

    auto it = allVisits.begin();
    advance(it, index);
    return *it;
}

Department* Hospital::getAllDepartments(int index) const
{
    if (index < 0 || index >= (int)allDepartments.size())
        return nullptr;

    auto it = allDepartments.begin();
    advance(it, index);
    return *it;
}

Employee* Hospital::getAllEmployees(int index) const
{
    if (index < 0 || index >= (int)allEmployees.size())
        return nullptr;

    auto it = allEmployees.begin();
    advance(it, index);
    return *it;
}

ostream& operator<<(ostream& os, const Hospital& h)
{
    os << "THE HOSPITAL NAME : " << h.getHospitalName() << "\n";
    os << "Amount of Department in the hospital is  : " << h.getlogicalNumOfDepartments() << "\n";
    os << "the Departments:\n";

    for (int i = 0; i < h.getlogicalNumOfDepartments(); i++)
        os << *(h.getAllDepartments(i));

    os << "\nStaff:\n";
    for (int i = 0; i < h.getlogicalNumOfEmployees(); i++)
        os << *(h.getAllEmployees(i)) << "\n";

    os << "\nVisits:\n";
    for (int i = 0; i < h.getlogicalNumOfVisits(); i++)
        os << *(h.getVisit(i)) << "\n";

    return os;
}