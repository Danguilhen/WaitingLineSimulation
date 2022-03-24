//#ifndef SERVICE
//#define
#pragma once

#include "Evenement.h"
#include "Caissier.h"

class FinService : public Evenement
{
public:
    FinService(Caissier *caissier);
    void traiter();

private:
    Caissier *_caissier;
};

//#endif