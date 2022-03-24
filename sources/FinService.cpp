#include "../headers/FinService.h"
#include <iostream>

FinService::FinService(Caissier *caissier, float heure)
{
    _caissier = caissier;
    _heure = heure;
}

void FinService::traiter()
{
    _caissier->devientLibre();
}