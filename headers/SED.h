#ifndef SED_
#define SED_
using namespace std;


#include "Evenement.h"


class SED
{
public:
    void ajouter(Evenement* evenement);
    void lancer();
    float heure();

protected:
    float _dureeReel;
    float _heure;
    vector<Evenement*> _evenements;
};

#endif