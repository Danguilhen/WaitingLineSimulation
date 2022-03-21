#include "../headers/Arrivee.hpp"
#include "../headers/Client.hpp"
#include "../headers/Poisson.hpp"
#include <vector>
#include "../headers/Caissier.hpp"

Arrivee::Arrivee(float tempsMoyenEntreArrivees, float heure, Banque *banque) {
    _heure = Poisson().genererTemps(tempsMoyenEntreArrivees) + heure;
    _banque = *banque;
}

Banque Arrivee::banque(){
    return _banque;
}

void Arrivee::traiter() {

    if (_banque.premierCaissierLibre() != NULL) //Must be modify 
    {
        _banque.premierCaissierLibre().servir(Client(_heure));
    }
    else
    {
        _banque.getFile()->ajouter(Client(_heure));
    }
}