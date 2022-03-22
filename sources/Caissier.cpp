#include "../headers/Caissier.h"
#include "../headers/FinService.h"
#include <numeric>
using namespace std;

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
    return accumulate(_tempsService.begin(), _tempsService.end(), 0) / _tempsService.size();
}

float Caissier::tauxOccupation()
{
    return accumulate(_tempsService.begin(), _tempsService.end(), 0) / _banque->dureeReel();
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

void Caissier::servir(Client client)
{
    delete &client;
    _tempsService.push_back(_poisson.genererTemps(_tempsMoyenService));
    _nbClients += 1;
    _estLibre = false;
    _banque->getEvenements().push_back(FinService(this)); // TODO ajouter au bon endroit dans la file d'événement
}