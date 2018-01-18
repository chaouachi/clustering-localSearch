#ifndef CLUSTERINGPROBLEM_H
#define CLUSTERINGPROBLEM_H

#include "include.h"
#include "observation.h"
#include "dataset.h"

//ici, ajouter d'autres au besoin
#include "msecluster.h"

class Optimizer
{
public:
    Optimizer();
    virtual ~Optimizer() =0;
    void display();
    virtual bool optimize() = 0;
    double value();
    void init(int);
    void bestBackup();
    void bestRestore();
    void randomSolution();
    double impactMove(Observation *obs, int new_cls);
protected:
    vector<Cluster *> clusters;
    DataSet data;
};

#endif // CLUSTERINGPROBLEM_H
