#ifndef MSECLUSTER_H
#define MSECLUSTER_H

#include <cluster.h>
#include "average.h"

class MSECluster : public Cluster
{
public:
    MSECluster(unsigned int);
    bool add(Observation *);
    bool remove(Observation *);
    double value();
    double impactAdd(Observation *obs);
    double impactRem(Observation *obs);
    void setClsNo(int);
    int getClsNo();
    void display();
private:
    Average *mu;
};

#endif // MSECLUSTER_H
