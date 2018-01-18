#ifndef CLUSTER_H
#define CLUSTER_H

#include <list>

#include "observation.h"

class Cluster
{
public:
    Cluster();
    virtual ~Cluster() = 0;
    virtual bool add(Observation *) =0;
    virtual bool remove(Observation *) =0;
    virtual double value() =0;
    virtual double impactAdd(Observation *obs) =0;
    virtual double impactRem(Observation *obs) =0;

    void setClsNo(int);
    int getClsNo();
    void display();
protected:
    list<Observation *> observations;
    int clsno;
    unsigned int dim;
};

#endif // CLUSTER_H
