#include "../headers/Banque.h"
#include "../headers/FileAttente.h"
#include "../headers/Poisson.h"


/**
 * @file sources/Banque.cpp
 * @brief Constructeur de l'objet Banque
 * 
 * @param dureePrevue 
 * @param tpsService 
 * @param tempsMoyenEntreArrivees 
 */
Banque::Banque(float dureePrevue, std::vector<float> tpsService, float tempsMoyenEntreArrivees)
{
    _generateur = new Poisson(tempsMoyenEntreArrivees);
    Caissier *caissier;
    _file = new FileAttente(this);
    float heure = this->tpsEntreArrivees();
    Arrivee *arrivee = new Arrivee(heure, this);
    _evenements.push_back(arrivee);
    for (int i = 0; i < (int)tpsService.size(); i++)
    {
        caissier = new Caissier(tpsService[i], this);
        _caissiers.push_back(caissier);
    }
    _dureePrevue = dureePrevue;
}

/**
 * @file sources/Banque.cpp
 * @brief Getter du nombre de caissiers
 * 
 * @return int 
 */
int Banque::nbCaissiers()
{
    return _caissiers.size();
}

/**
 * @file sources/Banque.cpp
 * @brief Getter du nombre total des clients servis par l'ensemble des caissiers
 * 
 * @return int 
 */
int Banque::nbClients()
{
    int nbClients = 0;
    for (auto caissier = begin(_caissiers); caissier != end(_caissiers); ++caissier)
    {
        nbClients += (*caissier)->nbClients();
    }
    return nbClients;
}

/**
 * @file sources/Banque.cpp
 * @brief Renvoie le premier caissier libre trouvé parmi les caissiers
 * 
 * @return Caissier* 
 * 
 * Parcourt le vecteur contenant les caissiers, vérifie à chaque fois si le caissier est libre et 
 * renvoie le premier caissier libre
 * 
 */
Caissier *Banque::premierCaissierLibre()
{
    size_t index = 0;
    Caissier *caissier;
    while (index < _caissiers.size())
    {
        if (_caissiers.at(index)->estLibre())
        {
            caissier = _caissiers.at(index);
            return caissier;
        }
        index++;
    }
    return NULL;
}

/**
 * @file sources/Banque.cpp
 * @brief Getteur de la durée prévue
 * 
 * @return float 
 */
float Banque::dureePrevue()
{
    return _dureePrevue;
}

/**
 * @file sources/Banque.cpp
 * @brief Getter de l'heure actuelle
 * 
 * @return float 
 */
float Banque::dureeReel()
{
    return _heure;
}

/**
 * @file sources/Banque.cpp
 * @brief Getter de la file d'attente
 * 
 * @return FileAttente* 
 */
FileAttente *Banque::getFile()
{
    return _file;
}

/**
 * @file sources/Banque.cpp
 * @brief Getter des évenements
 * 
 * @return std::vector<Evenement *>& 
 */
std::vector<Evenement *> &Banque::getEvenements()
{
    return _evenements;
}

/**
 * @file sources/Banque.cpp
 * @brief Retourne le caissier à l'index @param i du vecteur contenants tous les caissiers
 * 
 * @param i 
 * @return Caissier* 
 */
Caissier *Banque::getCaissier(int i)
{
    return _caissiers[i];
}

/**
 * @file sources/Banque.cpp
 * @brief Generateur aléatoire du temps entre chaque arrivée
 * 
 * @return float 
 */
float Banque::tpsEntreArrivees()
{
    return _generateur->genererTemps();
}