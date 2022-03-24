#include "../headers/FinService.h"
#include <iostream>

FinService::FinService(Caissier *caissier)
{
    _caissier = caissier;
    _heure = (new Poisson())->genererTemps(caissier->tempsMoyenService());
}

void FinService::traiter()
{
    std::cout << "Je traite dans fin de service" << '\n';
    _caissier->estLibre();
}