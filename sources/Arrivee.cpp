#include "../headers/Arrivee.hpp"
#include "../headers/Client.hpp"
#include "../headers/Poisson.hpp"
#include "../headers/Caissier.hpp"
#include "../headers/Banque.hpp"
#include <vector>


Arrivee::Arrivee(float tempsMoyenEntreArrivees, float heure, Banque *banque)
{
    _heure = Poisson().genererTemps(tempsMoyenEntreArrivees) + heure;
    _banque = banque;
}

Banque* Arrivee::banque()
{
    return _banque;
}

void Arrivee::traiter()
{
    if (heure < dureePrevue) //dureePrevue à définir
    {
        _banque->getEvenements()->push_back(Arrivee(tempsMoyenEntreArrivees, heure, this)); //tempsMoyenEntreArriveesà définir !
    }
    if (_banque->premierCaissierLibre() != NULL) // Must be modify
    {
        _banque->premierCaissierLibre()->servir(Client(_heure));
    }
    else
    {
        _banque.getFile()->ajouter(Client(_heure));
    }
}