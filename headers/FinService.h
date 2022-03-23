#ifndef SERVICE
#define SERVICE

#include "Evenement.h"
#include "Caissier.h"
class FinService : public Evenement
{
public:
    FinService(Caissier *caissier);
    virtual void traiter() final;

private:
    Caissier *_caissier;
};

#endif