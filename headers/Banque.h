#pragma once

#include "Arrivee.h"
#include "Evenement.h"
#include "FileAttente.h"
#include "SED.h"
#include "Caissier.h"
#include <iostream>

class FileAttente;
class Caissier;
class Banque : public SED
{
public:
    Banque(float dureePrevue, std::vector<float> tpsService, float tempsMoyenEntreArrivees);

    int nbCaissiers();
    int nbClients();
    Caissier *premierCaissierLibre();
    float dureePrevue();
    float dureeReel();
    FileAttente *getFile();
    std::vector<Evenement *> &getEvenements();
    Caissier *getCaissier(int i);
    float tpsEntreArrivees();

private:
    float _tpsEntreArrivees;
    FileAttente *_file;
    float _dureePrevue;
    std::vector<Caissier *> _caissiers;
};