#include "msecluster.h"

MSECluster::MSECluster(unsigned int sz)
{
    mu = new Average(sz);
    dim = sz;
}


bool MSECluster::add(Observation *obs)
{
    if(obs->getClsNo() >=0) {
        cerr<<"ERROR : trying to assign an observation that is already affected."<<endl;
        return false;
    }
    list<Observation *>::iterator it;
    for(it = observations.begin();it!=observations.end();it++)
        if(*it == obs) {
            cerr<<"Cluster::add failed : Observation already here!"<<endl;
            return false;
        }
    observations.push_back(obs);
    obs->setClsNo(clsno);
    (*mu)+=obs;
    return true;
}

bool MSECluster::remove(Observation *obs)
{
    if(obs->getClsNo() != clsno) return false;
    list<Observation *>::iterator it;
    for(it = observations.begin();it!=observations.end();it++)
        if(*it == obs) {
            observations.erase(it);
            obs->setClsNo(-1);
            (*mu)-=obs;
            return true;
        }
    return false;
}

double MSECluster::value()
{
    double s = 0.;
    list<Observation *>::iterator it;
    for(it=observations.begin();it!=observations.end();it++)
            s += mu->distance2(*it);
    
    
    
    
    return s;
}

double MSECluster::impactAdd(Observation *obs)
{
    list<Observation *>::iterator it;
    for(it=observations.begin();it!=observations.end();it++)
        if(*it == obs)
            return 0.;
    Average *a = new Average(mu->size());
    (*a) = (*mu);
    (*a) += obs;
    double s = 0.;
    for(it=observations.begin();it!=observations.end();it++)
        s += a->distance2(*it);
    s+=a->distance2(obs);
    delete a;
    return s-value();
}

double MSECluster::impactRem(Observation *obs)
{
    bool was_here = false;
    list<Observation *>::iterator it;
    for(it=observations.begin();it!=observations.end();it++)
        if(*it == obs)
            was_here = true;
    if(!was_here) return 0.;
    Average *a = new Average(mu->size());
    (*a) = (*mu);
    (*a) -= obs;
    double s = 0.;
    for(it=observations.begin();it!=observations.end();it++)
        if(*it != obs)
            s += a->distance2(*it);
    delete a;
    return s-value();
}
