#ifndef FILE
#define FILE

#include <algorithm>
#include "Banque.h"
#include <vector>
#include "Client.h"

using namespace std;

class Banque;
class FileAttente
{
public:
    FileAttente(Banque *banque);
    float tempsEntreArrivees();
    float longueurMoyenne();
    int longueurMax();
    float tempsMoyenAttente();
    void ajouter(Client* c);
    bool estVide();
    Client* retirer();

private:
    int _nbClients;
    int _longueurMax;
    double _longueurMoyenne;
    std::vector<Client*> _file;
    std::vector<float> tempsAttente;
    Banque *_banque;
};

#endif