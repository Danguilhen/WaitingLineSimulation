#ifndef ARRIVEE
#define ARRIVEE

#include "Evenement.h"
#include "Banque.h"

class Arrivee : public Evenement
{
public:
    Arrivee(float heure, Banque *banque);
    virtual void traiter() final;

private:
    Banque *_banque;
};

#endif