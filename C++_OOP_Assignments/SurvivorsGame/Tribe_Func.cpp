#include <iostream> 
using namespace std;

#include <cstring>
#include "Tribe_Header.h"



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

Tribe::Tribe(const Bandana& bandana, const char* tribename, int MaxSurvivors) :  theTribesBandana(bandana), tribeName(nullptr)
{
    setTribeName(tribename);
    cout << "*** " << tribeName << " *** "  <<endl;
    maxSurvivors = MaxSurvivors ;
  
    survivors = new Survivor*[maxSurvivors];
    for (int i = 0; i < maxSurvivors; i++)
    {
        survivors[i] =nullptr;
    }
    survivor_Num = 0;
}


void Tribe:: AddSurvivorToTribe(const char* curSurvivorName, int CurSurvivorsAge ,Survivor::eStatus status)
 {
    if (survivor_Num == maxSurvivors)
    {
        cout << tribeName << "is full you can't add more:(" << endl;
        return;
    }
    
    survivors[survivor_Num] = new Survivor(curSurvivorName, CurSurvivorsAge , status ,*this);
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
 ostream& operator<<(ostream& os , const Tribe& t)
{
    os << "\nTribe: " << t.tribeName << endl
    << "Survivors left: " << t.survivor_Num << "/" << t.maxSurvivors << endl;
    
    
    for (int i = 0; i < t.survivor_Num; i++)
        os << *t.survivors[i];
    
    return os;
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