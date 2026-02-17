#include <iostream> 
using namespace std;
#include "Survivor_Game_Header.h"

void InitSurvivor(Survivor& s)
{
    cout << "Enter name: ";
    cin >> s.name;         
    cout << "Enter age: ";
    cin >> s.age;
}


void PrintSurvivor(const Survivor& s)
{
    cout << "Name: " << s.name << "\n";
    cout << "Age : " << s.age  << "\n";
}


void InitTribe(Tribe& t, int max)
{
    t.maxSurvivors = max;
    t.survivor_num = 0;

    t.survivors = new Survivor*[max];

    for (int i = 0; i < max; i++)
        t.survivors[i] = nullptr;
}

void AddSurvivorToTribe(Tribe& t)
{
    if (t.survivor_num == t.maxSurvivors)
    {
        return;
    }
    
    t.survivors[t.survivor_num] = new Survivor[MAXSIZE];
    InitSurvivor(*t.survivors[t.survivor_num]);
    t.survivor_num++;
}

void PrintTribe(Tribe& t)
{
    cout << "the Tribe Survivors are =>";

    for (int i = 0; i < t.survivor_num; i++)
    {
        PrintSurvivor(*t.survivors[i]);
    }
    
}

void FreeTribe(Tribe& t)
{
    for (int i = 0; i < t.survivor_num; i++)
        delete t.survivors[i];

    delete[] t.survivors;
}

