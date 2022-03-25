#pragma once

#include "Banque.h"
#include "Client.h"
#include "FileAttente.h"
#include "Poisson.h"
#include <iostream>
#include <vector>

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
    void servir(Client *client);

private:
    Poisson *_generateur;
    int _nbClients;
    bool _estLibre;
    Banque *_banque;
    std::vector<float> _tempsService;
};