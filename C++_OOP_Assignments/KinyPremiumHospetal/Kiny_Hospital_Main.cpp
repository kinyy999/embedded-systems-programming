#include <iostream>
using namespace std;

#include "Hospital_Header.h"
#include "Department_Header.h"
#include "Doctor_Header.h"          
#include "Nurse_Header.h"
#include "Researcher.h"
#include "DoctorResearcher.h"

int main()
{
    Hospital h("KinyPremium");

    Department icu("ICU");
    h.addDepartment(icu);

    Department dep("Intensive care");
    h.addDepartment(dep);

    Doctor d("Kinan", "Cardio");
    Nurse  n("Rana", 5);

    h.addEmployee(d);
    h.addEmployee(n);

    h.assignEmployeeToDepartment(1, "ICU"); 

    Researcher r1("Dana", 2);
    Article a1("Paper1", "IEEE", 2024);
    Article a2("Paper22", "IEEE", 2025);
    r1 += a1;
    r1 += a2;
    h.addEmployee(r1);

    DoctorResearcher dr("Maya", "Neuro", 2);
    dr += Article("BrainPaper", "Nature", 2025);
    dr += Article("BrainPaper", "Theoretic physics", 2015);

    h.addEmployee(dr);
    h.assignEmployeeToDepartment(dr.getSerialNumber(), "Intensive care");

    h.openVisit("Ali", 1999, "Male", "12/02/2026", "Pain", "ICU", dr.getSerialNumber());


    cout << h;
    return 0;
}








    //
   
   
   // Doctor doc("kinan abusalh" ,"kalb mfto7");
  

   // h1.addDoctor(doc);
   // h1.addDoctor(doc5);
   // h1.addDoctor(doc2);
   
   // h1.assignDoctorToDepartment(doc2, " Intensive care ");
    //h1.assignDoctorToDepartment(doc5, " sharameet");
   
  
    /* 
    for (int i = 0; i < h1.getlogicalNumOfDoctors(); i++)
    {
         cout << h1.getAllDoctors(i)->getDoctorName() << "\n";
       
    }
    
   
   
    Department dep(" Intensive care ");
    //cout << dep;
    
    Doctor d1("kinan abusalh" ,"kalb mfto7", dep);
    cout << d1;
    cout <<"**********************************\n";
    cout <<dep;
    Doctor d2("ram abusalh" ,"kd7 tez") ;
    dep.AddDoctor(d2);
    cout <<"**********************************\n";
    cout <<dep  ;
    cout << d2<<"\n" ;
    */