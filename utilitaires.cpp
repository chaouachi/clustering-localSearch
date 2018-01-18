#include "include.h"

double unif01()
{
    return (double)rand()/double(RAND_MAX);
}

int random(int max)
{
    return rand()%max;
}
