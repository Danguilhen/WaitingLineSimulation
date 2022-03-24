#include "../headers/Arrivee.h"
#include "../headers/Banque.h"

Arrivee::Arrivee(float heure, Banque *banque)
{
    _heure = heure;
    _banque = banque;
}

void Arrivee::traiter()
{
    if (_banque->heure() < _banque->dureePrevue())
    {
        float heure = Poisson().genererTemps(_banque->tpsEntreArrivees()) + _heure;
        std::cout << heure - _heure << std::endl;
        _banque->setHeure(heure);
        Arrivee *arrivee = new Arrivee(heure, _banque);
        _banque->getEvenements().push_back(arrivee);
    }
    if (_banque->premierCaissierLibre() != NULL) // Must be modify
    {
        _banque->premierCaissierLibre()->servir(new Client(_heure));
    }
    else
    {
        _banque->getFile()->ajouter(new Client(_heure));
    }
}