#ifndef SURVIVOR_HEADER_H
#define SURVIVOR_HEADER_H

#include <iostream> 
using namespace std;

#include "Bandana_Header.h"
class Tribe;

class Survivor
{

public:
    enum eStatus{single ,married,relationshipe};
      
    //void InitSurvivor(const char* newName, int newAge ,eStatus status);
private:
    char* name;
    int age; 
    eStatus status;
    Bandana survivorBandana; 
    const Tribe* theTribe;
    int serialNumber;
	static int numberGenerator ;
public: 
    void PrintSurvivor() const;
    friend ostream& operator<<(ostream& os ,const Survivor& s);
    const char* StatusToString(eStatus status) const;
    void setName(const char* newName);
    const char* getName()const;
    
    Survivor(const char* name, int age, eStatus status, const Tribe& theTribe);
    Survivor(const Survivor& other) = delete;
    ~Survivor();
};

#endif