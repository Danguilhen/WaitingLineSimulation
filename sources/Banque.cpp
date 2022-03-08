#include "../headers/Banque.hpp"
using namespace std;

Banque::Banque(float dureePrevue) {
    _dureePrevue = dureePrevue;
}

int Banque::nbCaissiers() {
    return _caissiers.size();
}

int Banque::nbClients() {
    int nbClients = 0;
    for(auto caissier = begin(_caissiers); caissier != end(_caissiers); ++caissier) {
        nbClients += (*caissier).nbClients();
    }
    return nbClients;
}

Caissier Banque::premierCaissierLibre() {
    int index = 0;
    while(index < _caissiers.size()) {
        if(_caissiers.at(index).estLibre()) {
            return _caissiers.at(index);
        }
        index++;
    }
    return NULL;
}

float Banque::dureePrevue() {
    return _dureePrevue;
}

float dureeReel() {
    // TODO
}