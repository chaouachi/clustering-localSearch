#include "cluster.h"

Cluster::Cluster(){}

Cluster::~Cluster(){}

void Cluster::setClsNo(int n)
{
    clsno = n;
}

int Cluster::getClsNo()
{
    return clsno;
}

void Cluster::display()
{
    cout<<"Cluster "<<clsno<<endl;
    for(list<Observation *>::iterator it=observations.begin();
        it!=observations.end();it++)
        (*it)->display();
    cout<<"Value = "<<value()<<endl;
    cout<<"----------------"<<endl;
}

