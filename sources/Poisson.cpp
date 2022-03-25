#include "../headers/Poisson.h"
#include <ctime>

Poisson::Poisson(float lambda)
{
    int seed = 0;
    std::srand(seed ? seed : std::time(0));
    _lambda = lambda;
}

int Poisson::fact(int nbr)
{
    // Factorielle de 1 vaut aussi 1
    if (nbr == 0 || nbr == 1)
    {
        return 1;
    }
    return (nbr * fact(nbr - 1));
}

float Poisson::genererTemps()
{
    return -log(((double)rand() / RAND_MAX)) * _lambda;
}