#include "../headers/Poisson.h"
#include <random>
#include <ctime>

int Poisson::fact(int nbr)
{
    // Factorielle de 1 vaut aussi 1
    if (nbr == 0 || nbr == 1)
    {
        return 1;
    }
    return (nbr * fact(nbr - 1));
}

float Poisson::genererTemps(float lambda)
{
    float d, x;
    int k, r;
    srand((unsigned int)time(NULL));
    std::poisson_distribution<int> distribution(lambda);
    std::default_random_engine generator;
    k = distribution.operator()(generator);
    x = exp(-lambda);
    r = fact(k);
    d = pow(lambda, k) / (float)r;
    return (d * x);
}