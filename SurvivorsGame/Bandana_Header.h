#ifndef BANDANA_HEADER_H
#define BANDANA_HEADER_H


class Bandana
{
private:
    static constexpr int MAX_COLOR_LEN = 20;
    int bandanaLength ;
    char bandanaColor[MAX_COLOR_LEN];
    
public:
    Bandana( int bandanaLength,const  char* bandanaColor);
    friend ostream& operator<<(ostream& os ,const Bandana& b);
    void print() const;
};



#endif