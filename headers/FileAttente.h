#ifndef FILE
#define FILE

#include <vector>
#include "Client.h"

class FileAttente
{
public:
    FileAttente();

    float tempsEntreArrivees();
    float longueurMoyenne();
    int longueurMax();
    float tempsMoyenAttente();
    void ajouter(Client c);
    bool estVide();
    Client retirer();

private:
    int _nbClients;
    int _longueurMax;
    double _longueurMoyenne;
    double _tempsMoyenAttente;
    std::vector<Client> _file;
};

#endif