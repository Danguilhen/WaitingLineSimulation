#include "../headers/Arrivee.hpp"
#include "../headers/Client.hpp"
#include "../headers/Poisson.hpp"
#include <vector>
#include "../headers/Caissier.hpp"

Arrivee::Arrivee(float tempsMoyenEntreArrivees, float heure, Banque *banque) {
    _heure = Poisson().genererTemps(tempsMoyenEntreArrivees) + heure;
    _banque = banque;
}

void Arrivee::traiter() {
    if (_banque->premierCaissierLibre() != NULL)
    {
        _banque->premierCaissierLibre().servir(Client(_heure));
    }
    else
    {
        _banque->getFile()->ajouter(Client(_heure));
    }
}