#include "Client.hpp"
#include "FileAttente.hpp"
#include "Poisson.hpp"
#include "Banque.hpp"
#include <iostream>
#include <vector>
using namespace std;

class Caissier
{
public:
    Caissier(int tempsMoyenService, FileAttente *file, Banque *banque);
    float tempsMoyenService();
    int nbClients();
    float tauxOccupation();
    void devientLibre();
    bool estLibre();
    void servir(Client client);

private:
    Poisson _poisson;
    float _tempsMoyenService;
    int _nbClients;
    bool _estLibre;
    Banque &_banque;
    FileAttente *_file;
    vector<float> _tempsService;
};