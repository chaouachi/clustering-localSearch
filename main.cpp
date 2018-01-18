#include <iostream>

//classe qui contient les donnees
#include "dataset.h"

//une classe de base qui contient une observation (vecteur de données)
#include "observation.h"
//une observation spéciale qui contient la moyenne d'un certain nombre d'observations
#include "average.h"

//Classe de base qui définit un cluster devrait devenir virtuelle et avoir des descendants
#include "cluster.h"

//Un exemple d'optimiseur qui hérite de Optimizer
#include "localsearch.h"

int main()
{
    srand(269785263);
    DataSet data;
    data.load("test");
    Optimizer *opt = new LocalSearch(data);
    opt->init(3);//nombre de clusters
    opt->optimize();
    opt->display();
    opt->bestBackup();
    delete opt;
    return 0;
}
