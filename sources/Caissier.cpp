#include "../headers/Caissier.hpp"
#include <numeric>
using namespace std;

Caissier::Caissier(int tempsTravail) {
    _tempsTravail = tempsTravail;
    _nbClients = 0;
    _estLibre = true;
}

int Caissier::nbClients() {
    return _nbClients;
}

float Caissier::tempsMoyenService() {
    return accumulate(_tempsService.begin(), _tempsService.end(), 0) / _tempsService.size();
}

float Caissier::tauxOccupation() {
    return accumulate(_tempsService.begin(), _tempsService.end(), 0) / _tempsTravail;   
}

bool Caissier::estLibre() {
    return _estLibre;
}

void Caissier::servir(Client client) {
    _tempsService.push_back(2.0); // TODO choose random value (loi de poisson)
    _nbClients += 1;
    _estLibre = true;
}

void Caissier::attendre() {
    _estLibre = true;   // TODO il y a débat ici
}