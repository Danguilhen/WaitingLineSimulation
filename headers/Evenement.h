#ifndef EVENEMENT
#define EVENEMENT

class Evenement
{
public:
    //Evenement();
    float heure();
    virtual void traiter() = 0;

protected:
    float _heure;
};

#endif