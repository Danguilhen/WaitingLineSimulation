#include "../headers/Caissier.h"
#include "../headers/FinService.h"
#include <numeric>

Caissier::Caissier(float tempsMoyenService, Banque *banque)
{
    _poisson = Poisson();
    _banque = banque;
    _tempsMoyenService = tempsMoyenService;
    _nbClients = 0;
    _estLibre = true;
}

int Caissier::nbClients()
{
    return _nbClients;
}

float Caissier::tempsMoyenService()
{
    return std::accumulate(_tempsService.begin(), _tempsService.end(), decltype(_tempsService)::value_type(0)) / _tempsService.size();
}

float Caissier::tauxOccupation()
{
    return std::accumulate(_tempsService.begin(), _tempsService.end(), decltype(_tempsService)::value_type(0)) /
           _banque->dureeReel();
}

void Caissier::devientLibre()
{
    if (_banque->getFile()->estVide()) // file d'attente est vide TODO
    {
        _estLibre = true;
    }
    else
    {
        servir(_banque->getFile()->retirer());
    }
}

bool Caissier::estLibre()
{
    return _estLibre;
}

void Caissier::servir(Client *client)
{
    delete client;
    float heure = _poisson.genererTemps(_tempsMoyenService);
    _tempsService.push_back(heure);
    _nbClients += 1;
    _estLibre = false;
    FinService *finService = new FinService(this, heure);
    _banque->getEvenements()
        .push_back(finService);
}