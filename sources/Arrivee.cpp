#include "../headers/Arrivee.h"
#include "../headers/Client.h"
#include "../headers/Poisson.h"
#include <vector>
#include "../headers/Caissier.h"

Arrivee::Arrivee(float heure, Banque *banque)
{
    _heure = Poisson().genererTemps(_banque->tpsEntreArrivees()) + heure;
    _banque = banque;
}

void Arrivee::traiter()
{
    if (_banque->heure() < _banque->dureePrevue())
    {
        _banque->getEvenements().push_back(Arrivee(_heure, _banque));
    }
    if (_banque->premierCaissierLibre() != NULL) // Must be modify
    {
        _banque->premierCaissierLibre()->servir(Client(_heure));
    }
    else
    {
        _banque->getFile()->ajouter(Client(_heure));
    }
}