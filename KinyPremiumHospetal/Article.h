#ifndef _ARTICLE_H_
#define _ARTICLE_H_

#include <iostream>
using namespace std;

class Article
{
private:
    char* title;
    char* journal;
    int   year;

    void setStr(char*& dest, const char* src);

public:
    Article(const char* title = "", const char* journal = "", int year = 0);
    Article(const Article& other);
    Article& operator=(const Article& other);
    ~Article();

    const char* getTitle() const   { return title; }
    const char* getJournal() const { return journal; }
    int getYear() const            { return year; }

    void toOs(ostream& os) const;
    friend ostream& operator<<(ostream& os, const Article& a);
};

#endif
