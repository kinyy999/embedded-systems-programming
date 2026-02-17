#pragma warning(disable: 4996)
#include <iostream> 
using namespace std;
#include <string>
#include <cstring>

#include "Bandana_Header.h"

Bandana::Bandana(int bandanaLength,const char* bandanaColor) 
{
    this->bandanaLength = bandanaLength;
    strcpy(this->bandanaColor, bandanaColor);
}
ostream& operator<<(ostream& os ,const Bandana& b)
{
    os << "Bandana's color is " << b.bandanaColor << ", " << b.bandanaLength << "cm.";
    return os;
}


void Bandana::print() const
{
	cout << "Bandana's color is " << bandanaColor << ", " << bandanaLength << "cm.";
}