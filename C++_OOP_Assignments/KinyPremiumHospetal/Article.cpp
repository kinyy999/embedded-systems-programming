#include <cstring>
#include "Article.h"

void Article::setStr(char*& dest, const char* src)
{
    if (!src) src = "";
    delete[] dest;
    dest = new char[strlen(src) + 1];
    strcpy(dest, src);
}

Article::Article(const char* t, const char* j, int y)
    : title(nullptr), journal(nullptr), year(y)
{
    setStr(title, t);
    setStr(journal, j);
}

Article::Article(const Article& other)
    : title(nullptr), journal(nullptr), year(other.year)
{
    setStr(title, other.title);
    setStr(journal, other.journal);
}

Article& Article::operator=(const Article& other)
{
    if (this == &other) return *this;
    year = other.year;
    setStr(title, other.title);
    setStr(journal, other.journal);
    return *this;
}

Article::~Article()
{
    delete[] title;
    delete[] journal;
}

void Article::toOs(ostream& os) const
{
    os << "Article: " << (title ? title : "")
       << " | Journal: " << (journal ? journal : "")
       << " | Year: " << year<<endl;
}

ostream& operator<<(ostream& os, const Article& a)
{
    a.toOs(os);
    return os;
}
