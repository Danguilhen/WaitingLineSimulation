#pragma once 
#include "Banque.hpp"
#include "Client.hpp"
#include "FileAttente.hpp"
#include "Poisson.hpp"
#include <iostream>
#include <vector>

using namespace std;

class Caissier
{
public:
    Caissier(float tempsMoyenService, Banque *banque);
    float tempsMoyenService();
    int nbClients();
    float tauxOccupation();
    void devientLibre();
    bool estLibre();
    void servir(Client client);

private:
    Poisson _poisson;
    float _tempsMoyenService;
    int _nbClients;
    bool _estLibre;
    Banque *_banque;
    vector<float> _tempsService;
};