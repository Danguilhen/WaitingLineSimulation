//#ifndef SED_
//#define
#pragma once

#include <vector>
#include "Evenement.h"

class SED
{
public:
    void ajouter(Evenement *evenement);
    void lancer();
    float heure();

protected:
    float _dureeReel;
    float _heure;
    std::vector<Evenement *> _evenements;
};

//#endif