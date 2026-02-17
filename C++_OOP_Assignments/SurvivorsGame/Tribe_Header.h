#ifndef TRIBE_HEADER_H
#define TRIBE_HEADER_H

#include <iostream> 
using namespace std;

#include "Survivor_Header.h"

class Tribe
{

    private:
        Survivor** survivors;
        char* tribeName;
        int maxSurvivors ;
        int survivor_Num = 0 ;
        Bandana theTribesBandana;
    public:
        Tribe(const Bandana& bandana, const char* tribename, int curMaxSurvivors);
        Tribe(const Tribe& other) = delete;
        ~Tribe();
        const char* getTribeName() const;
        void setTribeName(const char* newTribeName);
        void AddSurvivorToTribe(const char* curSurvivorName, int CurSurvivorsAge ,Survivor::eStatus status);
        void KillSurvivors(const char* name);
        void Print() const;
        friend ostream& operator<<(ostream& os , const Tribe& t);
        const Bandana& getBandana() const { return theTribesBandana; }
        //void Free(); 
        //void InitTribe(const char* TribeName, int MaxSurvivors );      
};





#endif