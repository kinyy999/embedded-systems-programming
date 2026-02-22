#include "Article.h"
#include <iostream>
using namespace std;

Article::Article(const string& t, const string& j, int y)
    : title(t), journal(j), year(y)
{
}

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
