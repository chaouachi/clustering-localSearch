#include "dataset.h"

DataSet::DataSet()
{
    dim = 0;
    data.clear();
}

void DataSet::load(string filename)
{
    for(unsigned int i=0;i<data.size();i++)
        delete data[i];
    data.clear();

    dim = 4;
    Observation *o = 0;
    vector<double> v(dim);

    //observation 1
    v[0] = 10.;
    v[1] = 8.;
    v[2] = 7.;
    v[3] = 14.;
    o = new Observation(v);
    //o est un pointeur sur un objet Observation
    data.push_back(o);
    //observation 2
    v[0] = 13.;
    v[1] = 12.;
    v[2] = 4.;
    v[3] = 7.;
    o = new Observation(v);
    data.push_back(o);
    //observation 3
    v[0] = 8.;
    v[1] = 10.;
    v[2] = 6.;
    v[3] = 12.;
    o = new Observation(v);
    data.push_back(o);
    //observation 4
    v[0] = 20.;
    v[1] = 14.;
    v[2] = 12.;
    v[3] = 18.;
    o = new Observation(v);
    data.push_back(o);
    //observation 5
    v[0] = 13.;
    v[1] = 7.;
    v[2] = 18.;
    v[3] = 24.;
    o = new Observation(v);
    data.push_back(o);
    //observation 6
    v[0] = 22.;
    v[1] = 13.;
    v[2] = 6.;
    v[3] = 10.;
    o = new Observation(v);
    data.push_back(o);
    //observation 7
    v[0] = 42.;
    v[1] = 7.;
    v[2] = 14.;
    v[3] = 16.;
    o = new Observation(v);
    data.push_back(o);
    //observation 8
    v[0] = 8.;
    v[1] = 15.;
    v[2] = 16.;
    v[3] = 1.;
    o = new Observation(v);
    data.push_back(o);
    //observation 9
    v[0] = 18.;
    v[1] = 5.;
    v[2] = 12.;
    v[3] = 11.;
    o = new Observation(v);
    data.push_back(o);
    //observation 10
    v[0] = 5.;
    v[1] = 13.;
    v[2] = 26.;
    v[3] = 8.;
    o = new Observation(v);
    data.push_back(o);
    //observation 11
    v[0] = 11.;
    v[1] = 19.;
    v[2] = 26.;
    v[3] = 4.;
    o = new Observation(v);
    data.push_back(o);
    //observation 12
    v[0] = 21.;
    v[1] = 1.;
    v[2] = 10.;
    v[3] = 21.;
    o = new Observation(v);
    data.push_back(o);
}

int DataSet::dimension()
{
    return dim;
}

unsigned int DataSet::size()
{
    return data.size();
}

Observation *DataSet::operator [](unsigned int pos)
{
    if(pos >= data.size()){
        cerr<<"INVALID ARGUMENT"<<endl;
        return 0;
    }
    return data[pos];
}

void DataSet::operator =(DataSet &other)
{
    dim = other.dimension();
    data.clear();
    for(unsigned int i=0;i<other.size();i++)
        data.push_back(other[i]);
}
