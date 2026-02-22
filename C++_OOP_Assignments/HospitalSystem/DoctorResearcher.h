#ifndef _DOCTOR_RESEARCHER_H_
#define _DOCTOR_RESEARCHER_H_

#include "Doctor.h"
#include "Researcher.h"

class DoctorResearcher : public Doctor, public Researcher
{
public:
    DoctorResearcher(const string& name, const string& specialization, int maxArticles = 2);

    DoctorResearcher(const DoctorResearcher& other);
    DoctorResearcher& operator=(const DoctorResearcher& other);
    virtual ~DoctorResearcher() = default;

    virtual Employee* clone() const override { return new DoctorResearcher(*this); }
    virtual void toOs(ostream& os) const override;
};

#endif
