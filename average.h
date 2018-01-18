#ifndef AVERAGE_H
#define AVERAGE_H

#include "observation.h"

class Average : public Observation
{
public:
    Average(unsigned int sz);
    void operator +=(Observation &);
    void operator +=(Observation *);
    void operator -=(Observation &);
    void operator -=(Observation *);
    double distance2(Observation &);
    double distance2(Observation *);
private:
    double nobs;
};

#endif // AVERAGE_H
