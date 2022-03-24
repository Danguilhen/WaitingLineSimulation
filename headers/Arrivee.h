// //#ifndef ARRIVEE
// //#define
#pragma once

#include "Evenement.h"
#include "Banque.h"
#include <iostream>
class Banque;
class Arrivee : public Evenement
{
public:
    Arrivee(float heure, Banque *banque);
    void traiter();

private:
    Banque *_banque;
};

// //#endif