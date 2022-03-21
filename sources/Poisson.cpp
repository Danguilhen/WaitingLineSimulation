#include "Poisson.hpp"

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

    k = rand() % 10;
    x = exp(-lambda);
    r = fact(k);
    d = pow(lambda, k) / (float)r;
    return (d * x);
}