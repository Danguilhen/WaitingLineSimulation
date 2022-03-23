#include "../headers/Evenement.h"
#include <iostream>
using namespace std;

/*Evenement::Evenement()
{
}*/
float Evenement::heure()
{
    return _heure;
}

void Evenement::traiter(){
    cout << "Je traite dans evenement" << endl;
}
