#include <iostream>
using namespace std;

#include "Researcher.h"

Researcher::Researcher(const char* name, int maxA)
    : Employee(name),
      articles(nullptr),
      numOfArticles(0),
      maxArticles(maxA)
{
    if (maxArticles < 1) maxArticles = 1;
    articles = new Article*[maxArticles];
    for (int i = 0; i < maxArticles; i++)
        articles[i] = nullptr;
}

void Researcher::resize(int newMax)
{
    if (newMax <= maxArticles) return;

    Article** temp = new Article*[newMax];
    for (int i = 0; i < newMax; i++) temp[i] = nullptr;

    for (int i = 0; i < numOfArticles; i++)
        temp[i] = articles[i];

    delete[] articles;
    articles = temp;
    maxArticles = newMax;
}

Researcher::Researcher(const Researcher& other)
    : Employee(other),
      articles(nullptr),
      numOfArticles(other.numOfArticles),
      maxArticles(other.maxArticles)
{
    articles = new Article*[maxArticles];
    for (int i = 0; i < maxArticles; i++) articles[i] = nullptr;

    for (int i = 0; i < numOfArticles; i++)
        articles[i] = new Article(*other.articles[i]);
}

Researcher& Researcher::operator=(const Researcher& other)
{
    if (this == &other) return *this;

    Employee::operator=(other);

    for (int i = 0; i < numOfArticles; i++)
        delete articles[i];
    delete[] articles;

    numOfArticles = other.numOfArticles;
    maxArticles = other.maxArticles;

    articles = new Article*[maxArticles];
    for (int i = 0; i < maxArticles; i++) articles[i] = nullptr;

    for (int i = 0; i < numOfArticles; i++)
        articles[i] = new Article(*other.articles[i]);

    return *this;
}

Researcher::~Researcher()
{
    for (int i = 0; i < numOfArticles; i++)
        delete articles[i];
    delete[] articles;
}

bool Researcher::addArticle(const Article& a)
{
    if (numOfArticles == maxArticles)
        resize(maxArticles * 2);

    articles[numOfArticles++] = new Article(a);
    return true;
}

Researcher& Researcher::operator+=(const Article& a)
{
    addArticle(a);
    return *this;
}

void Researcher::toOs(ostream& os) const
{
    os << "Researcher | ";
    Employee::toOs(os);
    os << " | Articles: " << numOfArticles<<endl;

    if (numOfArticles > 0)
    {
        os << " [";
        for (int i = 0; i < numOfArticles; i++)
        {
            os << *articles[i];
            if (i != numOfArticles - 1) os << " ; ";
        }
        os << " ]";
    }
}
