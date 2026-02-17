#include <iostream> 
using namespace std;

#include "Survivor_Classes_Header.h"

void FillTribe(Tribe& tribe)
{
    char name[555];
    int age;
    int status ;
    char choice = 'y';

    while (choice == 'y' || choice == 'Y')
    {
        cout << "Enter survivor name and age: "<<endl;
        cin >> name >> age;

        cout << "Enter survivor status : (it should be [0 = single, 1 =  married, 2 = relationshipe])"<<endl;
        cin >> status;

        tribe.AddSurvivorToTribe(name, age , (Survivor::eStatus)status);

        cout << "Do you want to continue? (y/n): "<<endl;
        cin >> choice;
    }
}


int main()
{
    int size, size2, i=0;
    
    cout << "how many Survivor you want" << endl;
    cin >> size;
    
    if (size <0)
    {
       return 0;
    }
    size2 = size;
   
    
    char name1[20];
    cout << "choose your first tribe name?"<< endl;
    cin >> name1 ;
    // Tribe kinyTribe1;
    //kinyTribe1.InitTribe( name1, size);
  
    Tribe kinyTribe1( name1, size);
    cout << " Input Tribe " << kinyTribe1.getTribeName() <<" survivors" << endl;
    FillTribe(kinyTribe1);

cout <<"**************************************************"<<endl;
   
    char name2[20];
    cout << "choose your second tribe name?"<< endl;
    cin >> name2;
    //Tribe kinyTribe2;
    //kinyTribe2.InitTribe( "t2", size);
    Tribe kinyTribe2( name2, size2);
    cout << " Input Tribe " << kinyTribe2.getTribeName() <<" survivors" << endl;
    FillTribe(kinyTribe2);

   cout <<"************************************************"<<endl;  

    /* Print before kill */
    cout << "\n=== Tribes before kill ===\n";
    kinyTribe1.Print();
    kinyTribe2.Print();

    char killedname[20];
    /* Kill one survivor from each tribe */
    cout << "\nEnter name to kill from Tribe1: "<<endl;
    cin >> killedname;
    kinyTribe1.KillSurvivors(killedname);

    cout << "Enter name to kill from Tribe2: "<<endl;
    cin >> killedname;
    kinyTribe2.KillSurvivors(killedname);

    /* Print after kill */
    cout << "\n=== Tribes after kill ===\n";
    kinyTribe1.Print();
    kinyTribe2.Print();

    /* Free memory
    kinyTribe1.Free();
    kinyTribe2.Free();
 */
    return 0;
}
    