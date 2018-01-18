#ifndef DATASET_H
#define DATASET_H

#include <vector>

#include "observation.h"

class DataSet
{
public:
    DataSet();
    void load(string filename);
    int dimension();
    Observation * operator [](unsigned int pos);
    void operator =(DataSet &);
    unsigned int size();
private:
    vector<Observation *> data;
    int dim;
};

#endif // DATASET_H
