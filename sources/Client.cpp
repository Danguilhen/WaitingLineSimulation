#include "../headers/Client.hpp"

Client::Client(float heureArrivee) {
    _heureArrivee = heureArrivee;
}

float Client::heureArrivee() {
    return _heureArrivee;
}