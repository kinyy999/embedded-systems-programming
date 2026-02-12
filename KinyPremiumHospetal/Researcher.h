#ifndef _RESEARCHER_H_
#define _RESEARCHER_H_

#include "Employee.h"
#include "Article.h"

class Researcher : virtual public Employee
{
private:
    Article** articles;
    int numOfArticles;
    int maxArticles;

    void resize(int newMax);

public:
    Researcher(const char* name, int maxArticles = 2);
    Researcher(const Researcher& other);
    Researcher& operator=(const Researcher& other);
    virtual ~Researcher();

    int getNumOfArticles() const { return numOfArticles; }
    int getMaxArticles() const   { return maxArticles; }

    bool addArticle(const Article& a);          
    Researcher& operator+=(const Article& a);   
    Article* getArticle(int index) const { return articles[index]; }


    virtual Employee* clone() const override { return new Researcher(*this); }
    virtual void toOs(ostream& os) const override;
};

#endif
