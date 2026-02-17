#ifndef SURVIVOR_GAME_HEADER_H
#define SURVIVOR_GAME_HEADER_H

#include <iostream> 
using namespace std;
const int MAXSIZE = 20 ;

class Survivor
{

public:
    enum eStatus{single ,married,relationshipe};
      
    //void InitSurvivor(const char* newName, int newAge ,eStatus status);
private:
    char* name;
    int age; 
    eStatus status; 
public: 
    void PrintSurvivor() const;
    const char* StatusToString(eStatus status) const;
    void setName(const char* newName);
    const char* getName()const;
    
    Survivor(const char* name, int age, eStatus status);
    Survivor(const Survivor& other) = delete;
    ~Survivor();
};



class Tribe
{

    private:
        Survivor** survivors;
        char* tribeName;
        int maxSurvivors = MAXSIZE;
        int survivor_Num = 0 ;
    public:
        Tribe(const char* tribename, int curMaxSurvivors);
        Tribe(const Tribe& other) = delete;
        ~Tribe();
        const char* getTribeName() const;
        void setTribeName(const char* newTribeName);
        void AddSurvivorToTribe(const char* curSurvivorName, int CurSurvivorsAge ,Survivor::eStatus status);
        void KillSurvivors(const char* name);
        void Print() const;
        //void Free(); 
        //void InitTribe(const char* TribeName, int MaxSurvivors );      
};

#endif