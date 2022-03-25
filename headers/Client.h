#pragma once

class Client
{
public:
    Client(float heureArrivee);
    float heureArrivee();
    ~Client();

private:
    float _heureArrivee;
};