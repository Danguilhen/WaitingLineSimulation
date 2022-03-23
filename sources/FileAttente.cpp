#include "../headers/FileAttente.h"
#include "../headers/Client.h"

using namespace std;

FileAttente::FileAttente()
{
    _longueurMax = 0;
    _nbClients = 0;
}

int FileAttente::longueurMax()
{
    return _longueurMax;
}

float FileAttente::longueurMoyenne()
{
    return _longueurMoyenne; // TODO
}

float FileAttente::tempsMoyenAttente()
{
    return(1.5);
    // TODO
}

void FileAttente::ajouter(Client client)
{
    _file.push_back(client);
    if ((int)_file.size() > _longueurMax)
    {
        _longueurMax = (int) _file.size();
    }
}

bool FileAttente::estVide()
{
    return _file.empty();
}

Client FileAttente::retirer()
{
    Client client = _file.front();
    _file.erase(_file.begin());
    return client;
}
