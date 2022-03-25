#pragma once

#include "Evenement.h"
#include "Caissier.h"

class FinService : public Evenement
{
public:
    FinService(Caissier *caissier, float heure, Client *client);
    void traiter();

private:
    Caissier *_caissier;
    Client *_client;
};