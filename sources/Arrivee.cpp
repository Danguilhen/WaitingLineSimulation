#include "../headers/Arrivee.hpp"
#include "../headers/Client.hpp"
#include "../headers/Poisson.hpp"
#include <vector>
#include "../headers/Caissier.hpp"

Arrivee::Arrivee(float tempsMoyenEntreArrivees, vector<Caissier> _caissiers, float heure) {
    _tempsEntreArrivees = (new Poisson)->genererTemps(tempsMoyenEntreArrivees) + heure;
}

void Arrivee::traiter() {
    if (premierCaissierLibre() != NULL)
    {
        premierCaissierLibre().servir(new Client());
    }
    else
    {
        _file.ajouter(new Client());
    }
}