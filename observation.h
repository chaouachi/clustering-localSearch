#ifndef OBSERVATION_H
#define OBSERVATION_H

#include "include.h"

#include <vector>

class Observation
{
public:
    Observation();
    Observation(vector<double> v);//constructeur
    Observation(unsigned int sz);//constructeur d'observation vide de taille sz

    void display();
    double getCoord(unsigned int pos);
    double operator [](unsigned int pos);

    void add(Observation & autre);
    void operator +=(Observation &autre);
    void operator +=(Observation *autre);

    void operator /=(double v);
    void operator =(Observation &autre);

    unsigned int size();
    void setClsNo(int);
    int getClsNo();
    void bestBackup();
    int getBestCls();
    double distance(Observation &autre);
    double distance(Observation *autre);
protected:
    vector<double> coord;
    int cls_no;
    int best_cls;
};

#endif // OBSERVATION_H
