#include "../headers/Arrivee.h"
#include "../headers/Client.h"
#include "../headers/Poisson.h"
#include <vector>
#include "../headers/Caissier.h"

Arrivee::Arrivee(float heure, Banque *banque)
{
<<<<<<< HEAD
    _heure = Poisson().genererTemps(_banque->tpsEntreArrivees()) + heure;
    _banque = banque;
    == == == =
                 _heure = Poisson().genererTemps(tempsMoyenEntreArrivees) + heure;
    _banque = banque;
}

Banque *Arrivee::banque()
{
    return _banque;
>>>>>>> 4e3bc2718119edb05a413cf1465027532bbdef8f
}

void Arrivee::traiter()
{
<<<<<<< HEAD
    if (_banque->heure() < _banque->dureePrevue())
    {
        _banque->getEvenements().push_back(Arrivee(_heure, _banque));
        == == == =
                     if (heure < dureePrevue) // dureePrevue à définir
        {
            _banque->getEvenements()->push_back(Arrivee(tempsMoyenEntreArrivees, heure, this)); // tempsMoyenEntreArriveesà définir !
>>>>>>> 4e3bc2718119edb05a413cf1465027532bbdef8f
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