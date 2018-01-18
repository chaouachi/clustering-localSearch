#ifndef LOCALSEARCH_H
#define LOCALSEARCH_H

#include "optimizer.h"

class LocalSearch : public Optimizer
{
public:
    LocalSearch(DataSet &d);
    ~LocalSearch(){}
    bool optimize();
};

#endif // LOCALSEARCH_H
