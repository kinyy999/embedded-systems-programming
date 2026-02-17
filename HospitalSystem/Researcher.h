#ifndef _RESEARCHER_H_
#define _RESEARCHER_H_

#include <list>
#include <string>
#include "Employee.h"
#include "Article.h"

class Researcher : virtual public Employee
{
private:
    list<Article> articles;

public:
    Researcher(const string& name, int maxArticles = 2);  
    Researcher(const Researcher& other) = default;
    Researcher& operator=(const Researcher& other) = default;
    virtual ~Researcher() = default;

    int getNumOfArticles() const { return (int)articles.size(); }

    bool addArticle(const Article& a);
    Researcher& operator+=(const Article& a);

    const Article& getArticle(int index) const;

    virtual Employee* clone() const override { return new Researcher(*this); }
    virtual void toOs(ostream& os) const override;
};

#endif
