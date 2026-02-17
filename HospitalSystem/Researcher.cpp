#include <iostream>
using namespace std;

#include "Researcher.h"

Researcher::Researcher(const string& name, int maxArticles)
    : Employee(name)
{
}

bool Researcher::addArticle(const Article& a)
{
    articles.push_back(a);
    return true;
}

Researcher& Researcher::operator+=(const Article& a)
{
    articles.push_back(a);
    return *this;
}

const Article& Researcher::getArticle(int index) const
{
    auto it = articles.begin();
    std::advance(it, index);
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

