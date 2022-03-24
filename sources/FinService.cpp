#include "../headers/FinService.h"
#include <iostream>
using namespace std;

FinService::FinService(Caissier *caissier)
{
    _caissier = caissier;
    _heure = (new Poisson())->genererTemps(caissier->tempsMoyenService());
}

void FinService::traiter()
{
    cout << "Je traite dans fin de service" << endl;
    _caissier->estLibre();
}