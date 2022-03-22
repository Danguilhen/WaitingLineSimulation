#ifndef EVENEMENT
#define EVENEMENT

class Evenement
{
public:
    Evenement();
    float heure();
    virtual void traiter();

protected:
    float _heure;
};

#endif