#ifndef ARRIVEE
#define ARRIVEE

#include "Evenement.h"
#include "Banque.h"

class Arrivee : public Evenement
{
public:
    Arrivee(float heure, Banque *banque);
    void traiter();

private:
    Banque *_banque;
};

#endif