#include "observation.h"

Observation::Observation(){}

Observation::Observation(vector<double> v)
{
    coord = v;
    cls_no = -1;
}

Observation::Observation(unsigned int sz)
{
    coord.resize(sz);
    for(unsigned int i=0;i<sz;i++)
        coord[i] = 0.;
    cls_no = -1;
}

void Observation::display()
{
    for(unsigned int i=0;i<coord.size();i++)
        cout<<coord[i]<<" ";
    cout<<"cls = "<<cls_no<<endl;
}

double Observation::getCoord(unsigned int pos)
{
    if(pos >= coord.size()){
        cerr<<"INVALID ARGUMENT"<<endl;
        exit (1);
    }
    return coord[pos];
}

double Observation::distance(Observation &autre)
{
    if(autre.size() != coord.size()){
        cerr<<"ERROR : ARG SIZE DIFFER"<<endl;
        exit(1);
    }
    double d = 0.;
    for(unsigned int i=0;i<coord.size();i++){
        double dif = (coord[i] - autre[i]);
        d+= dif*dif;
    }
    return sqrt(d);
}

double Observation::distance(Observation *autre)
{
    if(autre->size() != coord.size()){
        cerr<<"ERROR : ARG SIZE DIFFER"<<endl;
        exit(1);
    }
    double d = 0.;
    for(unsigned int i=0;i<coord.size();i++){
        double dif = (coord[i] - (*autre)[i]);
        d+= dif*dif;
    }
    return sqrt(d);
}

double Observation::operator [](unsigned int pos)
{
    if(pos >= coord.size()){
        cerr<<"INVALID ARGUMENT"<<endl;
        exit (1);
    }
    return coord[pos];
}

void Observation::add(Observation &autre)
{
    if(autre.size() != coord.size()){
        cerr<<"ERROR : ARG SIZE DIFFER"<<endl;
        exit(1);
    }
    for(unsigned int i=0;i<coord.size();i++)
        coord[i] += autre.getCoord(i);
}

void Observation::operator +=(Observation &autre)
{
    if(autre.size() != coord.size()){
        cerr<<"ERROR : ARG SIZE DIFFER"<<endl;
        exit(1);
    }
    for(unsigned int i=0;i<coord.size();i++)
        coord[i] += autre[i];
}

void Observation::operator +=(Observation *autre)
{
    if(autre->size() != coord.size()){
        cerr<<"ERROR : ARG SIZE DIFFER"<<endl;
        exit(1);
    }
    for(unsigned int i=0;i<coord.size();i++)
        coord[i] += (*autre)[i];
}

void Observation::operator /=(double v)
{
    if(fabs(v) < EPS) {
        cerr<<"ERROR : DIVISION BY 0!!!"<<endl;
        exit(1);
    }
    for(unsigned int i=0;i<coord.size();i++)
        coord[i] /= v;
}

void Observation::operator =(Observation &autre)
{
    if(autre.size() != coord.size()){
        cerr<<"ERROR : ARG SIZE DIFFER"<<endl;
        exit(1);
    }
    for(unsigned int i=0;i<coord.size();i++)
        coord[i] = autre.getCoord(i);
}

unsigned int Observation::size()
{
    return coord.size();
}

int Observation::getClsNo()
{
    return cls_no;
}

void Observation::setClsNo(int n)
{
    cls_no = n;
}

void Observation::bestBackup()
{
    best_cls = cls_no;
}

int Observation::getBestCls()
{
    return best_cls;
}
