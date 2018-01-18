#include "average.h"

Average::Average(unsigned int sz)
{
    coord.resize(sz);
    for(unsigned int i=0;i<sz;i++)
        coord[i] = 0.;
    nobs = 0.;
}

void Average::operator +=(Observation &autre)
{
    if(autre.size() != coord.size()){
        cerr<<"ARGUMENT SIZE DIFFER"<<endl;
        return;
    }
    for(unsigned int i=0;i<coord.size();i++)
        coord[i] = nobs*coord[i]+autre[i];//somme
    nobs+=1.;
    for(unsigned int i=0;i<coord.size();i++)
        coord[i] /= nobs;//moyenne
}

void Average::operator +=(Observation *autre)
{
    if(autre->size() != coord.size()){
        cerr<<"ARGUMENT SIZE DIFFER"<<endl;
        return;
    }
    for(unsigned int i=0;i<coord.size();i++)
        coord[i] = nobs*coord[i]+(*autre)[i];//somme
    nobs+=1.;
    for(unsigned int i=0;i<coord.size();i++)
        coord[i] /= nobs;//moyenne
}

void Average::operator -=(Observation &autre)
{
    if(nobs<EPS){
        return;
    }
    if(autre.size() != coord.size()){
        cerr<<"ARGUMENT SIZE DIFFER"<<endl;
        return;
    }
    for(unsigned int i=0;i<coord.size();i++)
        coord[i] = nobs*coord[i]-autre[i];//somme
    nobs-=1.;
    if(nobs > 1+EPS)
        for(unsigned int i=0;i<coord.size();i++)
            coord[i] /= nobs;//moyenne
}

void Average::operator -=(Observation *autre)
{
    if(nobs<EPS){
        return;
    }
    if(autre->size() != coord.size()){
        cerr<<"ARGUMENT SIZE DIFFER"<<endl;
        return;
    }
    for(unsigned int i=0;i<coord.size();i++)
        coord[i] = nobs*coord[i]-(*autre)[i];//somme
    nobs-=1.;
    if(nobs > 1+EPS)
        for(unsigned int i=0;i<coord.size();i++)
            coord[i] /= nobs;//moyenne
}

double Average::distance2(Observation &autre)
{
    if(autre.size() != coord.size()){
        cerr<<"ARG SIZE DIFFER"<<endl;
        return -1.;
    }
    double d2 = 0.;
    for(unsigned int i=0;i<coord.size();i++){
        double dtmp=(coord[i]-autre[i]);
        d2 += dtmp*dtmp;
    }
    return d2;
}

double Average::distance2(Observation *autre)
{
    if(autre->size() != coord.size()) {
        cerr<<"ARG SIZE DIFFER"<<endl;
        return -1.;
    }
    double d2 = 0.;
    for(unsigned int i=0;i<coord.size();i++) {
        double dtmp=(coord[i]-(*autre)[i]);
        d2 += dtmp*dtmp;
    }
    return d2;
}
