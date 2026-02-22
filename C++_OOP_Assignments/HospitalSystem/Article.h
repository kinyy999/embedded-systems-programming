#ifndef _ARTICLE_H_
#define _ARTICLE_H_

#include <iostream>
using namespace std;

class Article
{
private:
    string title;
    string journal;
    int year;

public:
    Article(const string& title = "", const string& journal = "", int year = 0);

    Article(const Article& other) = default;
    Article& operator=(const Article& other) = default;
    ~Article() = default;

    const string& getTitle() const   { return title; }
    const string& getJournal() const { return journal; }
    int getYear() const              { return year; }

    void toOs(ostream& os) const;
    friend ostream& operator<<(ostream& os, const Article& a);
};

#endif