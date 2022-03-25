#pragma once

#include <iostream>
#include <math.h>
#include <random>
class Poisson
{
public:
    Poisson(float lambda);
    float genererTemps();
    int fact(int nbr);

private:
    float _lambda;
};