//#ifndef FILE
//#define
#pragma once

//#include <algorithm>
#include "Banque.h"
#include <vector>
#include "Client.h"

class Banque;
class FileAttente
{
public:
    FileAttente(Banque *banque);
    float tempsEntreArrivees();
    float longueurMoyenne();
    int longueurMax();
    float tempsMoyenAttente();
    void ajouter(Client *c);
    bool estVide();
    Client *retirer();

private:
    int _nbClients;
    float _ancienneHeure;
    float _aire;
    int _longueurMax;
    std::vector<Client *> _file;
    std::vector<float> _tempsAttente;
    Banque *_banque;
};

//#endif