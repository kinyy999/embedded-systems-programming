#include <iostream> 
using namespace std;

const int MAXSIZE = 20 ;

struct Survivor
{
    char name[20];
    int age;
};

struct Tribe
{
    int maxSurvivors = MAXSIZE;
    Survivor** survivors;
    int survivor_num = 0 ;

};


void InitSurvivor(Survivor& s);



void PrintSurvivor(const Survivor& s);


void InitTribe(Tribe& t, int max);


void AddSurvivorToTribe(Tribe& t);


void PrintTribe(Tribe& t);


void FreeTribe(Tribe& t);

