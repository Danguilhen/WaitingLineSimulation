#include "../headers/FinService.h"
#include "../headers/Poisson.h"
#include "../headers/Caissier.h"

FinService::FinService(Caissier *caissier)
{
    _caissier = caissier;
    _heure = (new Poisson())->genererTemps(caissier->tempsMoyenService());
}

void FinService::traiter()
{
    _caissier->estLibre();
}