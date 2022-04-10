#pragma once

class Evenement
{
public:
    float heure();
    virtual void traiter() = 0;
    virtual ~Evenement(){};

protected:
    float _heure;
};