#include "../headers/Poisson.h"
#include <ctime>

/**
 * @brief Construction d'un nouveau Poisson:: Poisson object
 *
 * @param lambda
 */
Poisson::Poisson(float lambda)
{
    int seed = 0;
    std::srand(seed ? seed : std::time(0));
    _lambda = lambda;
}

/**
 * @brief Calcule de factorielle de @param nbr
 *
 * @param nbr
 * @return int
 */
int Poisson::fact(int nbr)
{
    // Factorielle de 1 vaut aussi 1
    if (nbr == 0 || nbr == 1)
    {
        return 1;
    }
    return (nbr * fact(nbr - 1));
}

/**
 * @brief Génère une valeur aléatoire suivant une loi de Poisson
 *
 * @return float
 */
float Poisson::genererTemps()
{
    return -log(((double)rand() / RAND_MAX)) * _lambda;
}