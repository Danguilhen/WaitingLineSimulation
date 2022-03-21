#include "../headers/FinService.hpp"
#include "../headers/Poisson.hpp"

FinService::FinService(Caissier *caissier)
{
    _caissier = caissier;
    _heure = (new Poisson)->genererTemps(caissier->tempsMoyenService());
}

void FinService::traiter()
{
    _caissier->estLibre();
}