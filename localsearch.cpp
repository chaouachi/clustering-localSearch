#include "localsearch.h"

LocalSearch::LocalSearch(DataSet &d)
{
    data = d;
}

bool LocalSearch::optimize()
{
    randomSolution();
    double best_value = value();
    bestBackup();
    bool succes = false;
    bool improved = true;
    while(improved){
       improved = false;
       for(unsigned int i=0;i<data.size();i++) {
           Observation *o = data[i];
           int old_cls = o->getClsNo();
           double old_sce = value();
           double impact_rem = clusters[old_cls]->impactRem(o);
           for(int k=0;k<(int)clusters.size();k++) {
               double delta = impact_rem + clusters[k]->impactAdd(o);
               if(k != old_cls && delta  < -EPS){
                   improved = true;
                   succes = true;
                   clusters[old_cls]->remove(o);
                   clusters[k]->add(o);
                   old_cls = k;
                   impact_rem = clusters[old_cls]->impactRem(o);
                   double new_sce = value();
                   old_sce = new_sce;
               }
           }
       }
       if(improved){
           double val = value();
           if(val<best_value-EPS){
               best_value = val;
               bestBackup();
           }
           cout<<"Solution improved to "<<value()<<endl;
       }
    }
    return succes;
}


