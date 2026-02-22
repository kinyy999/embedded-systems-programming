#include <iostream>
#include <limits>
using namespace std;

#include "Hospital.h"
#include "Department.h"
#include "Doctor.h"
#include "Nurse.h"
#include "Researcher.h"
#include "DoctorResearcher.h"
#include "Article.h"

// ---------- helpers ----------
static void clearInput()
{
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

static void readLine(const char* msg, string& out)
{
    cout << msg;
    getline(cin, out);
}

static int readInt(const char* msg)
{
    int x;
    while (true)
    {
        cout << msg;
        if (cin >> x)
        {
            clearInput();
            return x;
        }
        clearInput();
        cout << "Invalid number, try again.\n";
    }
}

static void printEmployeesShort(const Hospital& h)
{
    cout << "\n--- Employees in Hospital ---\n";
    int n = h.getlogicalNumOfEmployees();
    for (int i = 0; i < n; i++)
    {
        Employee* e = h.getAllEmployees(i);
        if (e)
            cout << "ID=" << e->getSerialNumber() << " | " << *e << "\n";
    }
    cout << "----------------------------\n\n";
}

static void printDepartmentsShort(const Hospital& h)
{
    cout << "\n--- Departments in Hospital ---\n";
    int n = h.getlogicalNumOfDepartments();
    for (int i = 0; i < n; i++)
    {
        Department* d = h.getAllDepartments(i);
        if (d)
            cout << "Name=\"" << d->getDepartmentName() << "\" | ID=" << d->getDepartment_ID() << "\n";
    }
    cout << "------------------------------\n\n";
}

static bool askBackToMenu()
{
    cout << "\n---------------------------------\n";
    int back = readInt("Back to menu? (1 = Yes, 0 = Exit): ");
    if (back == 0)
    {
        cout << "👋 Thank you for using KinyPremium Hospital System.\n";
        return false;
    }
    return true;
}

// ---------- menu actions ----------
static void menuAddDepartment(Hospital& h)
{
    string depName;
    readLine("Enter department name: ", depName);

    Department d(depName.c_str());
    if (h.addDepartment(d))
        cout << "✅ Department added successfully.\n";
    else
        cout << "❌ Department already exists.\n";
}

static void menuAddDoctor(Hospital& h)
{
    string name, spec;
    readLine("Doctor name: ", name);
    readLine("Specialization: ", spec);

    Doctor d(name, spec);
    if (h.addEmployee(d))
        cout << "✅ Doctor added successfully.\n";
    else
        cout << "❌ Failed to add doctor.\n";
}

static void menuAddNurse(Hospital& h)
{
    string name;
    readLine("Nurse name: ", name);

    int exp = readInt("Experience years: ");
    Nurse n(name, exp);

    if (h.addEmployee(n))
        cout << "✅ Nurse added successfully.\n";
    else
        cout << "❌ Failed to add nurse.\n";
}

static void menuAddResearcher(Hospital& h)
{
    string name;
    readLine("Researcher name: ", name);

    int maxA = readInt("Max articles: ");
    Researcher r(name, maxA);

    int howMany = readInt("How many articles to add now? ");
    for (int i = 0; i < howMany; i++)
    {
        string title, journal;
        int year;

        cout << "Article #" << (i + 1) << ":\n";
        readLine("  Title: ", title);
        readLine("  Journal: ", journal);
        year = readInt("  Year: ");

        if (!r.addArticle(Article(title, journal, year)))
        {
            cout << "  ⚠️ Max articles reached, stopped adding.\n";
            break;
        }
    }

    if (h.addEmployee(r))
        cout << "✅ Researcher added successfully.\n";
    else
        cout << "❌ Failed to add researcher.\n";
}

static void menuAddDoctorResearcher(Hospital& h)
{
    string name, spec;
    readLine("DoctorResearcher name: ", name);
    readLine("Specialization: ", spec);

    int maxA = readInt("Max articles: ");
    DoctorResearcher dr(name, spec, maxA);

    int howMany = readInt("How many articles to add now? ");
    for (int i = 0; i < howMany; i++)
    {
        string title, journal;
        int year;

        cout << "Article #" << (i + 1) << ":\n";
        readLine("  Title: ", title);
        readLine("  Journal: ", journal);
        year = readInt("  Year: ");

        if (!dr.addArticle(Article(title, journal, year)))
        {
            cout << "  ⚠️ Max articles reached, stopped adding.\n";
            break;
        }
    }

    if (h.addEmployee(dr))
        cout << "✅ DoctorResearcher added successfully.\n";
    else
        cout << "❌ Failed to add DoctorResearcher.\n";
}

static void menuAssignEmployeeToDepartment(Hospital& h)
{
    printEmployeesShort(h);
    printDepartmentsShort(h);

    int empId = readInt("Enter employee ID to assign: ");
    string depName;
    readLine("Enter department name: ", depName);

    if (h.assignEmployeeToDepartment(empId, depName.c_str()))
        cout << "✅ Employee assigned to department.\n";
    else
        cout << "❌ Assignment failed (check ID/name, or already assigned).\n";
}

static void menuOpenVisit(Hospital& h)
{
    printDepartmentsShort(h);
    printEmployeesShort(h);

    string pName, gender, arrival, purpose, depName;
    readLine("Patient name: ", pName);
    int birth = readInt("Birth year: ");
    readLine("Gender: ", gender);
    readLine("Arrival date (e.g. 12/02/2026): ", arrival);
    readLine("Purpose: ", purpose);
    readLine("Department name: ", depName);
    int caregiverId = readInt("Caregiver employee ID: ");

    if (h.openVisit(pName.c_str(), birth, gender.c_str(),
                    arrival.c_str(), purpose.c_str(),
                    depName.c_str(), caregiverId))
        cout << "✅ Visit opened successfully.\n";
    else
        cout << "❌ Visit NOT opened (bad dept / caregiver / etc.).\n";
}

static void menuPrintHospital(const Hospital& h)
{
    cout << "\n================ HOSPITAL FULL PRINT ================\n";
    cout << h;
    cout << "=====================================================\n\n";
}

static void menuAddArticleToResearcher(Hospital& h)
{
    printEmployeesShort(h);

    int empId = readInt("Enter Researcher/DoctorResearcher ID: ");

    Employee* found = nullptr;
    int n = h.getlogicalNumOfEmployees();
    for (int i = 0; i < n; i++)
    {
        Employee* e = h.getAllEmployees(i);
        if (e && e->getSerialNumber() == empId)
        {
            found = e;
            break;
        }
    }

    if (!found)
    {
        cout << "❌ Employee not found.\n";
        return;
    }

    Researcher* r = dynamic_cast<Researcher*>(found);
    if (!r)
    {
        cout << "❌ This employee is not a Researcher type.\n";
        return;
    }

    string title, journal;
    int year;

    cout << "\n--- Add New Article ---\n";
    readLine("Title: ", title);
    readLine("Journal: ", journal);
    year = readInt("Year: ");

    if (r->addArticle(Article(title, journal, year)))
        cout << "✨ Article added successfully!\n";
    else
        cout << "⚠️ Cannot add article (max reached).\n";
}

int main()
{
    cout << "********************** KinyPremium Hospital System  *****************\n";
    string hospitalName;
    readLine("Enter hospital name: ", hospitalName);

    Hospital h(hospitalName.c_str());

    while (true)
    {
        cout << "\nMenu:\n";
        cout << " 1) Add Department\n";
        cout << " 2) Add Doctor\n";
        cout << " 3) Add Nurse\n";
        cout << " 4) Add Researcher\n";
        cout << " 5) Add DoctorResearcher\n";
        cout << " 6) Assign Employee to Department\n";
        cout << " 7) Open Visit\n";
        cout << " 8) Print Hospital (full)\n";
        cout << " 9) List Employees (short)\n";
        cout << "10) List Departments (short)\n";
        cout << "11) Add Article to Researcher\n";
        cout << " 0) Exit\n";

        int choice = readInt("Choose: ");

        switch (choice)
        {
        case 1:  menuAddDepartment(h); break;
        case 2:  menuAddDoctor(h); break;
        case 3:  menuAddNurse(h); break;
        case 4:  menuAddResearcher(h); break;
        case 5:  menuAddDoctorResearcher(h); break;
        case 6:  menuAssignEmployeeToDepartment(h); break;
        case 7:  menuOpenVisit(h); break;
        case 8:  menuPrintHospital(h); break;
        case 9:  printEmployeesShort(h); break;
        case 10: printDepartmentsShort(h); break;
        case 11: menuAddArticleToResearcher(h); break;
        case 0:
            cout << "👋 Bye!\n";
            return 0;
        default:
            cout << "❌ Invalid option.\n";
            break;
        }

        if (!askBackToMenu())
            break;
    }

    return 0;
}