#include <iostream> 
using namespace std;

#include <cstring>

#include "Survivor_Classes_Header.h"

const char* Survivor::getName() const
{
    return name;
}

void Survivor::setName(const char* newName)
{
    delete[]name;
    name = new char[strlen(newName) +1];
    strcpy(name, newName);
}

/*
void Survivor::InitSurvivor(const char* newName, int newAge ,eStatus newStatus)
{
    strncpy(name, newName, 19);
    name[19] = '\0';
    age = newAge;
    status = newStatus;
}

Survivor::Survivor(const Survivor& other) 
{
    setName(other.name);
    age = other.age;
    status =other.status;  
}
*/
Survivor::Survivor(const char* name, int age, eStatus status): name(nullptr)
{
   setName(name);
   this->age = age ;
   this->status = status;
}


Survivor::~Survivor()
{
    delete[]name;
}

const char* Survivor:: StatusToString(eStatus status) const
{
    switch (status)
    {
    case  Survivor::married:
        return "married";
        break;
    case  Survivor::single:
        return "single";
        break;
    case  Survivor::relationshipe:
        return "in relationship";
        break;
    default:
        return nullptr;
        break;
        
    }
    
}

void Survivor::PrintSurvivor() const
{
    cout << "Name: " << name << "\n";
    cout << "Age : " << age  << "\n";
    cout << "Status : " << StatusToString(status)  << "\n";
}


/// @tribe methods ////////////////////////////////////



/*
void Tribe:: InitTribe(const char* TribeName, int curMaxSurvivors )
{
    strcpy(tribeName ,TribeName ) ;
    cout << "*** " << tribeName << " *** " << TribeName << " ***" <<endl;
     

    maxSurvivors = curMaxSurvivors ;
    survivor_Num = 0;
    survivors = new Survivor*[maxSurvivors];
    
    for (int i = 0; i < maxSurvivors; i++)
    {
        survivors[i] =nullptr;
    }
}
*/
void Tribe::setTribeName(const char* newTribeName)
{
    delete[]tribeName;
    tribeName = new char[strlen(newTribeName)+1];
    strcpy(tribeName, newTribeName);
}

const char* Tribe:: getTribeName() const
{
    return tribeName;
}

Tribe::Tribe(const char* tribename, int MaxSurvivors) : tribeName(nullptr)
{
    setTribeName(tribename);
    cout << "*** " << tribeName << " *** "  <<endl;
    maxSurvivors = MaxSurvivors ;
    survivor_Num = 0;

    survivors = new Survivor*[maxSurvivors];
    for (int i = 0; i < maxSurvivors; i++)
    {
        survivors[i] =nullptr;
    }

}


void Tribe:: AddSurvivorToTribe(const char* curSurvivorName, int CurSurvivorsAge ,Survivor::eStatus status)
 {
    if (survivor_Num == maxSurvivors)
    {
        cout << tribeName << "is full you can't add more:(" << endl;
        return;
    }
    
    survivors[survivor_Num] = new Survivor(curSurvivorName, CurSurvivorsAge ,status);
    //survivors[survivor_Num] -> InitSurvivor;
    survivor_Num++;
    return;
 }

 void Tribe:: KillSurvivors(const char* name) 
 {
    int index = -1;
    for (int i = 0; i < survivor_Num; i++)
    {       
        if (strcmp(survivors[i]->getName() ,name) == 0)
        {
            index = i;
            break;
        }
     }   
        if (index == -1)
        {
            cout << "didin't found:)"<< endl;
            return ;
        
        }
    delete survivors[index];
    survivors[index] = survivors[--survivor_Num];

    survivors[survivor_Num] = nullptr;  
 }

 void Tribe::Print() const
{
    cout << "\nTribe: " << tribeName << endl;
    cout << "Survivors left: " << survivor_Num << "/" << maxSurvivors << endl;

    for (int i = 0; i < survivor_Num; i++)
        survivors[i]->PrintSurvivor();
}

Tribe::~Tribe()
{
    for (int i = 0; i < survivor_Num; i++)
        delete survivors[i];

    delete[] survivors;

}