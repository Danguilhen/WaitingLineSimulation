#ifndef BANQUE
#define BANQUE

#include <iostream>
#include <vector>
#include "Evenement.h"
#include "FileAttente.h"
#include "SED.h"
#include "Caissier.h"

class FileAttente;
class Caissier;
class Banque : public SED
{
public:
    Banque(float dureePrevue, vector<float> tpsService, float tempsMoyenEntreArrivees);

    int nbCaissiers();
    int nbClients();
    Caissier *premierCaissierLibre();
    float dureePrevue();
    float dureeReel();
    FileAttente *getFile();
    vector<Evenement*>& getEvenements();
    Caissier *getCaissier(int i);
    float tpsEntreArrivees();

private:
    float _tpsEntreArrivees;
    FileAttente _file;
    float _dureePrevue;
    vector<Caissier> _caissiers;
};

#endif