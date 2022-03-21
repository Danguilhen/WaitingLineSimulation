#include "../headers/Caissier.hpp"
#include "../headers/FinService.hpp"
#include <numeric>
using namespace std;

Caissier::Caissier(int tempsMoyenService, FileAttente *file, Banque *banque)
{
    _poisson = new Poisson();
    _banque = banque;
    _file = file;
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
    return accumulate(_tempsService.begin(), _tempsService.end(), 0) / _banque.dureeReel();
}

void Caissier::devientLibre()
{
    if (_file.empty()) // file d'attente est vide TODO
    {
        _estLibre = true;
    }
    else
    {
        servir(_file.retirer());
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
    *_evenement.push_back(new FinService(this)); // TODO ajouter au bon endroit dans la file d'événement
}