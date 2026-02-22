#ifndef HOSPITAL_HEADER_H
#define HOSPITAL_HEADER_H

#include <iostream>
#include <list>
#include <string>
using namespace std;

class Employee;
class Department;
class Patient;
class VisitCard;

class Hospital
{
private:
    list<Department*> allDepartments;
    list<Employee*>   allEmployees;
    list<Patient*>    allPatients;
    list<VisitCard*>  allVisits;

    string hospitalName;

    // NEW: Hospital-managed IDs (stable and independent of temporaries in main)
    int nextEmployeeId;
    int nextDepartmentId;

public:
    Hospital(const char* hospitalName);

    Hospital(const Hospital& other) = delete;
    Hospital& operator=(const Hospital& other) = delete;

    ~Hospital();

    friend ostream& operator<<(ostream& os, const Hospital& h);

    void setHospitalName(const char* newHospitalName);
    const char* getHospitalName() const { return hospitalName.c_str(); }

    bool DepartmentExist(const Department& d) const;
    bool addDepartment(Department& d);

    bool EmployeeExist(const Employee& e) const;
    bool addEmployee(const Employee& e);

    bool assignEmployeeToDepartment(int employeeId, const char* departmentName);

    const int getPhisicalNumOfDepartments() const { return (int)allDepartments.size(); }
    const int getlogicalNumOfDepartments() const  { return (int)allDepartments.size(); }

    const int getphisicalNumOfEmployees() const { return (int)allEmployees.size(); }
    const int getlogicalNumOfEmployees() const  { return (int)allEmployees.size(); }

    bool openVisit(const char* patientName, int birthYear, const char* gender,
                   const char* arrivalDate, const char* purpose,
                   const char* departmentName, int caregiverEmployeeId);

    int getlogicalNumOfVisits() const { return (int)allVisits.size(); }
    VisitCard* getVisit(int index) const;

    Department* getAllDepartments(int index) const;
    Employee* getAllEmployees(int index) const;

private:
    Department* findDepartmentByName(const char* departmentName) const;
    Employee* findEmployeeById(int employeeId) const;
};

#endif