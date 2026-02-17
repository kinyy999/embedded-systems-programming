#include "Article.h"
#include <iostream>
using namespace std;

Article::Article(const string& t, const string& j, int y)
    : title(t), journal(j), year(y)
{
}

Article::Article(const Article& other)
    : title(other.title), journal(other.journal), year(other.year)
{
}

Article& Article::operator=(const Article& other)
{
    if (this == &other) return *this;
    title = other.title;
    journal = other.journal;
    year = other.year;
    return *this;
}

Article::~Article() = default;

void Article::toOs(ostream& os) const
{
    os << "Article: " << title
       << " | Journal: " << journal
       << " | Year: " << year;
}

ostream& operator<<(ostream& os, const Article& a)
{
    a.toOs(os);
    return os;
}
