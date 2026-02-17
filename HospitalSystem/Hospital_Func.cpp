#include <iostream>
using namespace std;

#include <cstring>
#include "Hospital_Header.h"
#include "Department_Header.h"
#include "Employee.h"
#include "Patient.h"
#include "VisitCard.h"

Hospital::Hospital(const char* hName)
    : allDepartments(nullptr),
      allEmployees(nullptr),
      hospitalName(nullptr)
{
    setHospitalName(hName);

    logicalNumOfDepartments = 0;
    phisicalNumOfDepartments = 2;
    allDepartments = new Department*[phisicalNumOfDepartments];

    logicalNumOfEmployees = 0;
    phisicalNumOfEmployees = 2;
    allEmployees = new Employee*[phisicalNumOfEmployees];

    logicalNumOfPatients = 0;
    phisicalNumOfPatients = 2;
    allPatients = new Patient*[phisicalNumOfPatients];

    logicalNumOfVisits = 0;
    phisicalNumOfVisits = 2;
    allVisits = new VisitCard*[phisicalNumOfVisits];

}

bool Hospital::DepartmentExist(const Department& d) const
{
    for (int i = 0; i < logicalNumOfDepartments; i++)
        if (strcmp(allDepartments[i]->getDepartmentName(), d.getDepartmentName()) == 0)
            return true;
    return false;
}

bool Hospital::addDepartment(Department& d)
{
    if (DepartmentExist(d))
        return false;

    if (logicalNumOfDepartments == phisicalNumOfDepartments)
    {
        phisicalNumOfDepartments *= 2;
        Department** temp = new Department*[phisicalNumOfDepartments];
        for (int i = 0; i < logicalNumOfDepartments; i++)
            temp[i] = allDepartments[i];

        delete[] allDepartments;
        allDepartments = temp;
    }

    allDepartments[logicalNumOfDepartments++] = new Department(d.getDepartmentName());
    return true;
}

bool Hospital::EmployeeExist(const Employee& e) const
{
    for (int i = 0; i < logicalNumOfEmployees; i++)
        if (allEmployees[i]->getSerialNumber() == e.getSerialNumber())
            return true;
    return false;
}

bool Hospital::addEmployee(const Employee& e)
{
    if (EmployeeExist(e))
        return false;

    if (logicalNumOfEmployees == phisicalNumOfEmployees)
    {
        phisicalNumOfEmployees *= 2;
        Employee** temp = new Employee*[phisicalNumOfEmployees];
        for (int i = 0; i < logicalNumOfEmployees; i++)
            temp[i] = allEmployees[i];

        delete[] allEmployees;
        allEmployees = temp;
    }

    allEmployees[logicalNumOfEmployees++] = e.clone(); 
    return true;
}

bool Hospital::assignEmployeeToDepartment(int employeeId, const char* departmentName)
{
    if (!departmentName) return false;

    Department* dep = nullptr;
    for (int i = 0; i < logicalNumOfDepartments; i++)
        if (strcmp(allDepartments[i]->getDepartmentName(), departmentName) == 0)
        { dep = allDepartments[i]; break; }

    if (!dep) return false;

    Employee* emp = nullptr;
    for (int j = 0; j < logicalNumOfEmployees; j++)
        if (allEmployees[j]->getSerialNumber() == employeeId)
        { emp = allEmployees[j]; break; }

    if (!emp) return false;

    return dep->assignEmployee(*emp);
}

bool Hospital::openVisit(const char* patientName,int birthYear,const char* gender,
                         const char* arrivalDate,const char* purpose,const char* departmentName,int caregiverEmployeeId)
{
    Department* dep = nullptr;
    for (int i = 0; i < logicalNumOfDepartments; i++)
    {
        if (strcmp(allDepartments[i]->getDepartmentName(), departmentName) == 0)
        {
            dep = allDepartments[i];
            break;
        }
    }
    if (!dep) return false;

    Employee* caregiver = nullptr;
    for (int i = 0; i < logicalNumOfEmployees; i++)
    {
        if (allEmployees[i]->getSerialNumber() == caregiverEmployeeId)
        {
            caregiver = allEmployees[i];
            break;
        }
    }
    if (!caregiver) return false;

    if (logicalNumOfPatients == phisicalNumOfPatients)
    {
        phisicalNumOfPatients *= 2;
        Patient** temp = new Patient*[phisicalNumOfPatients];
        for (int i = 0; i < logicalNumOfPatients; i++)
            temp[i] = allPatients[i];
        delete[] allPatients;
        allPatients = temp;
    }

    Patient* p = new Patient(patientName, birthYear, gender);
    allPatients[logicalNumOfPatients++] = p;

    if (logicalNumOfVisits == phisicalNumOfVisits)
    {
        phisicalNumOfVisits *= 2;
        VisitCard** temp = new VisitCard*[phisicalNumOfVisits];
        for (int i = 0; i < logicalNumOfVisits; i++)
            temp[i] = allVisits[i];
        delete[] allVisits;
        allVisits = temp;
    }

    VisitCard* v = new VisitCard(p, dep, arrivalDate, purpose);
    v->setCaregiver(caregiver);
    allVisits[logicalNumOfVisits++] = v;

    return true;
}


const int Hospital::getPhisicalNumOfDepartments() const { return phisicalNumOfDepartments; }
const int Hospital::getlogicalNumOfDepartments() const { return logicalNumOfDepartments; }
const int Hospital::getphisicalNumOfEmployees() const { return phisicalNumOfEmployees; }
const int Hospital::getlogicalNumOfEmployees() const { return logicalNumOfEmployees; }

const char* Hospital::getHospitalName() const { return hospitalName; }

void Hospital::setHospitalName(const char* newName)
{
    if (!newName) return;

    delete[] hospitalName;
    hospitalName = new char[strlen(newName) + 1];
    strcpy(hospitalName, newName);
}

Department* Hospital::getAllDepartments(int number) const { return allDepartments[number]; }
Employee* Hospital::getAllEmployees(int number) const { return allEmployees[number]; }

ostream& operator<<(ostream& os, const Hospital& h)
{
    os << "THE HOSPITAL NAME : "
       << (h.getHospitalName() ? h.getHospitalName() : "")
       << "\n";

    os << "Amount of Department in the hospital is  : "
       << h.getlogicalNumOfDepartments()
       << "\n";

    os << "the Departments:\n";

    for (int i = 0; i < h.getlogicalNumOfDepartments(); i++)
    {
        Department* dep = h.getAllDepartments(i);

        os << "Department_ID : "
           << dep->getDepartment_ID();

        os << "   DepartmentName : "
           << dep->getDepartmentName()
           << "\n";
    }

    os << "\nStaff:\n";

    for (int i = 0; i < h.getlogicalNumOfEmployees(); i++)
    {
        os << *h.getAllEmployees(i) << "\n";
    }

    os << "\nVisits:\n";
    for (int i = 0; i < h.getlogicalNumOfVisits(); i++)
        os << *h.getVisit(i) << "\n";

    return os;
}

Hospital::~Hospital()
{
    for (int i = 0; i < logicalNumOfDepartments; i++)
        delete allDepartments[i];

    for (int i = 0; i < logicalNumOfEmployees; i++)
        delete allEmployees[i];

    for (int i = 0; i < logicalNumOfVisits; i++)
        delete allVisits[i];
    

    for (int i = 0; i < logicalNumOfPatients; i++)
        delete allPatients[i];

    delete[] allDepartments;
    delete[] allEmployees;
    delete[] hospitalName;
    delete[] allVisits;
    delete[] allPatients;

}


