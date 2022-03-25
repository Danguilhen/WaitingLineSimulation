#pragma once

class Evenement
{
public:
    float heure();
    virtual void traiter() = 0;

protected:
    float _heure;
};