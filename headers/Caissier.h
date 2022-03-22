#ifndef CAISSIER
#define CAISSIER

#include "Banque.h"
#include "Client.h"
#include "FileAttente.h"
#include "Poisson.h"
#include <iostream>
#include <vector>
using namespace std;

class Banque;

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

#endif