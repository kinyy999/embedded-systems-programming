#ifndef HOSPITAL_HEADER_H
#define HOSPITAL_HEADER_H

#include <iostream>
using namespace std;

class Employee;
class Department;
class Patient;
class VisitCard;
class Employee;


class Hospital
{
private:
    Department** allDepartments;
    int phisicalNumOfDepartments, logicalNumOfDepartments;

    Employee** allEmployees;
    int phisicalNumOfEmployees, logicalNumOfEmployees;

    char* hospitalName;

    Patient** allPatients;
    int phisicalNumOfPatients, logicalNumOfPatients;

    VisitCard** allVisits;
    int phisicalNumOfVisits, logicalNumOfVisits;

public:
    Hospital(const char* hospitalName);

    Hospital(const Hospital& other) = delete;
    Hospital& operator=(const Hospital& other) = delete;

    ~Hospital();

    friend ostream& operator<<(ostream& os, const Hospital& h);

    void setHospitalName(const char* newHospitalName);
    const char* getHospitalName() const;

    bool DepartmentExist(const Department& d) const;
    bool addDepartment(Department& d);

    bool EmployeeExist(const Employee& e) const;
    bool addEmployee(const Employee& e); 

    bool assignEmployeeToDepartment(int employeeId, const char* departmentName);

    const int getPhisicalNumOfDepartments() const;
    const int getlogicalNumOfDepartments() const;

    const int getphisicalNumOfEmployees() const;
    const int getlogicalNumOfEmployees() const;

    

    bool openVisit(const char* patientName, int birthYear, const char* gender, const char* arrivalDate,
               const char* purpose, const char* departmentName, int caregiverEmployeeId);
    
    int getlogicalNumOfVisits() const { return logicalNumOfVisits; }
    VisitCard* getVisit(int index) const { return allVisits[index]; }



    Department* getAllDepartments(int number) const;
    Employee* getAllEmployees(int number) const;
};

#endif
