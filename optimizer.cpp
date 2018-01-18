#include "optimizer.h"

Optimizer::Optimizer(){}//les heritiers doivent affecter data

Optimizer::~Optimizer()
{
    for(unsigned int i=0;i<clusters.size();i++)
        delete clusters[i];
}

void Optimizer::display()
{
    double err = 0.;
    for(unsigned int i=0;i<clusters.size();i++) {
        err += clusters[i]->value();
        clusters[i]->display();
    }
    cout<<"ERR TOTALE = "<<err<<endl;
}

double Optimizer::value()
{
    double s=0.;
    for(unsigned int i=0;i<clusters.size();i++){
        s += clusters[i]->value();
    }
    return s;
}

void Optimizer::init(int nc)
{
    for(unsigned int i=0;i<clusters.size();i++)
        delete clusters[i];
    clusters.clear();

    int dim = data.dimension();
    for(int i=0;i<nc;i++)
        clusters.push_back(new MSECluster(dim));
    for(int i=0;i<nc;i++)
        clusters[i]->setClsNo(i);
    randomSolution();
}

void Optimizer::bestBackup()
{
    for(unsigned int i=0;i<data.size();i++)
        data[i]->bestBackup();
}

void Optimizer::bestRestore()
{
    for(unsigned int i=0;i<data.size();i++){
        Observation *obs = data[i];
        int curcls = obs->getClsNo();
        int bestcls = obs->getBestCls();
        if(curcls != bestcls){
            clusters[curcls]->remove(obs);
            clusters[bestcls]->add(obs);
        }
    }
    for(unsigned int i=0;i<data.size();i++)
        if(data[i]->getClsNo() < 0)
            cerr<<"ERROR after bestRestore()"<<endl;

}

void Optimizer::randomSolution()
{
    for(unsigned int i=0;i<data.size();i++){
        if(data[i]->getClsNo() >= 0)
            clusters[data[i]->getClsNo()]->remove(data[i]);
        clusters[random(clusters.size())]->add(data[i]);
    }
}

double Optimizer::impactMove(Observation *obs, int new_cls)
{
    if(!obs) cerr<<"ERROR obs=0"<<endl;
    if(new_cls <0 || new_cls>=(int)clusters.size())
        cerr<<"ERROR new_cls = "<<new_cls<<endl;
    int old_cls = obs->getClsNo();
    if(old_cls <0 || old_cls>=(int)clusters.size())
        cerr<<"ERROR old_cls = "<<old_cls<<endl;
    if(old_cls == new_cls)
        return 0.;
    else
        return clusters[old_cls]->impactRem(obs)+clusters[new_cls]->impactAdd(obs);
}
