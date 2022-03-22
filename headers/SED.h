#ifndef SED_
#define SED_

#include "Evenement.h"
#include <vector>
using namespace std;

class SED
{
public:
    void ajouter(Evenement evenement);
    void lancer();
    float heure();

protected:
    float _dureeReel;
    float _heure;
    vector<Evenement> _evenements;
};

#endif