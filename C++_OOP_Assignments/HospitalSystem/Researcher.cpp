#include <iostream>
using namespace std;

#include "Researcher.h"

Researcher::Researcher(const string& name, int maxArticles)
    : Employee(name), maxArticles(maxArticles)
{
}

bool Researcher::addArticle(const Article& a)
{
    // enforce the limit
    if ((int)articles.size() >= maxArticles)
        return false;

    articles.push_back(a);
    return true;
}

Researcher& Researcher::operator+=(const Article& a)
{
    addArticle(a);   
    return *this;
}

const Article& Researcher::getArticle(int index) const
{
    if (index < 0 || index >= (int)articles.size())
        throw out_of_range("Researcher::getArticle - index out of range");

    auto it = articles.begin();
    advance(it, index);
    return *it;
}

void Researcher::toOs(ostream& os) const
{
    os << "Researcher | ";
    Employee::toOs(os);
    os << " | Articles: " << articles.size();

    if (!articles.empty())
    {
        os << " [";
        bool first = true;

        for (const Article& a : articles)
        {
            if (!first) os << " ; ";
            os << a;
            first = false;
        }

        os << " ]";
    }
}

