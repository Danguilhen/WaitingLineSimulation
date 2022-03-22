#include "../headers/Client.h"

Client::Client(float heureArrivee)
{
    _heureArrivee = heureArrivee;
}

float Client::heureArrivee()
{
    return _heureArrivee;
}