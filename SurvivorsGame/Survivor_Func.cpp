#include <iostream> 
using namespace std;

#include <cstring>
#include "Survivor_Header.h"
#include "Tribe_Header.h"

int Survivor::numberGenerator = 1000;

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


Survivor::Survivor(const char* name, int age, eStatus status, const Tribe& theTribe) : name(nullptr), theTribe(&theTribe), survivorBandana(theTribe.getBandana())
{
   serialNumber = ++numberGenerator;
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
ostream& operator<<(ostream& os ,const Survivor& s)
{
    os  << "Name: " << s.name << "\n"
    << "Age : " << s.age  << "\n"
    << "serialNumber : " << s.serialNumber  << "\n"
    << "Status : " << s.StatusToString(s.status)  << "\n"
    << s.survivorBandana<< endl;
    return os;
}


void Survivor::PrintSurvivor() const
{
    cout << "Name: " << name << "\n";
    cout << "Age : " << age  << "\n";
    cout << "serialNumber : " << serialNumber  << "\n";
    cout << "Status : " << StatusToString(status)  << "\n";
    survivorBandana.print();
    cout << endl;
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