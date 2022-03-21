#include "../headers/FileAttente.hpp"
#include "../headers/Client.hpp"

#include <iostream>
using namespace std;

FileAttente::FileAttente() {
    _longueurMax = 0;
    _nbClients = 0;
}

int FileAttente::longueurMax() {
    return _longueurMax;
}

float FileAttente::longueurMoyenne() {
    return _longueurMoyenne; // TODO
}

float FileAttente::tempsMoyenAttente() {
    // TODO
}

void FileAttente::ajouter(Client client) {
    _file.push_back(client);
    if(_file.size() > _longueurMax) {
        _longueurMax = _file.size();
    }
}

bool FileAttente::estVide() {
    _file.empty();
}

Client FileAttente::retirer() {
    Client client = _file.front();
    _file.erase(_file.begin());
    return client;
}
