#include <iostream> 
using namespace std;

#include "Survivor_Game_Header.h"


int main()
{
    int size , i=0;
    
    cout << "how many Survivor you want" << endl;
    cin >> size;
    
    Survivor** KinyTribe1 = new Survivor*[size]; 
    Survivor** KinyTribe2 = new Survivor*[size]; 

    for (int i = 0; i < size; i++)
    {
        
        KinyTribe1[i]= nullptr;
        KinyTribe2[i]= nullptr;
    }
    
    cout << "insert survivor for KinyTribe1" << endl;
    while (i<size)
    {
        KinyTribe1[i] = new Survivor;
        InitSurvivor(*KinyTribe1[i]); 

        i ++;
        


        cout<< "do you want to continue y/n"<< endl;
        char choise;
        cin >> choise;
        if (choise == 'n')
        {
           break;
        }
        
    }

        cout << "insert survivor for KinyTribe2" << endl;
    while (i<size)
    {
        KinyTribe2[i] = new Survivor;
        InitSurvivor(*KinyTribe2[i]); 

        i ++;
        
        cout<< "do you want to continue y/n"<< endl;
        char choise;
        cin >> choise;
        if (choise =='n')
        {
           break;
        }
        
    }

    for (int i = 0; i < sizeof(KinyTribe1); i++)
    {
        if (KinyTribe1[i] != nullptr)
        {
            PrintSurvivor( *KinyTribe1[i]);
        }
       
    }

        for (int i = 0; i < sizeof(KinyTribe1); i++)
    {
        if (KinyTribe2[i] != nullptr)
        {
            PrintSurvivor( *KinyTribe2[i]);
        }
       
    }

    for (int i = 0; i < size; i++)
    {
        delete KinyTribe2[i];
        delete KinyTribe2[i];
    }
        
    delete[] KinyTribe1;
    delete[] KinyTribe2;

    
    Tribe KinyTribe3, KinyTribe4;
    int size2;

    cout << "Enter number of survivors per tribe: "<< endl;
    cin >> size2;

    InitTribe(KinyTribe3 ,size2);
    InitTribe(KinyTribe4, size2);

    cout << "tribe 3 Survivers=>"<< endl;
    while (KinyTribe3.survivor_num < KinyTribe3.maxSurvivors)
    {
        AddSurvivorToTribe(KinyTribe3);

        
        cout<< "do you want to continue y/n"<< endl;
        char choise;
        cin >> choise;
        if (choise =='n')
        {
           break;
        }

    }

     cout << "tribe 4 Survivers=>"<< endl;
    while (KinyTribe4.survivor_num < KinyTribe4.maxSurvivors)
    {
        AddSurvivorToTribe(KinyTribe4);

        
        cout<< "do you want to continue y/n"<< endl;
        char choise;
        cin >> choise;
        if (choise =='n')
        {
           break;
        }

    }


    cout << "tribe3 "<< endl;
    PrintTribe(KinyTribe3);

    cout << "tribe4 "<< endl;
    PrintTribe(KinyTribe4);
    
/*
    InitSurvivor(s);
    
*/
    return 0;
}
