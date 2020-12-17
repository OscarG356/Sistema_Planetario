#include "cuerpo.h"
#include <math.h>
#include <cmath>

Cuerpo::Cuerpo(float _px, float _py, float _vx, float _vy, float mass, float _radio)
{
    Px = _px;
    Py = _py;
    Vx = _vx;
    Vy = _vy;
    Masa = mass;
    Ax = 0;
    Ay = 0;
    Gravity = 6.67384*(pow(10,-11));
    Radio = _radio;
}

float Cuerpo::getPy() const
{
    return Py;
}

float Cuerpo::getMasa() const
{
    return Masa;
}

float Cuerpo::getRadio() const
{
    return Radio;
}

float Cuerpo::getPx() const
{
    return Px;
}

void Cuerpo::acelerar(float _px2, float _py2, float _mass2)
{
    Range = pow((pow((_px2-Px),2)+pow((_py2-Py),2)) ,1/2);
    Ax = Gravity*_mass2*(_px2-Px)/pow(Range,3);
    Ay = Gravity*_mass2*(_py2-Py)/pow(Range,3);
}

void Cuerpo::actualizar(float dt)
{
    Vx = Vx + (Ax*dt);
    Vy = Vy + (Ay*dt);
    Px = Px + (Vx*dt);
    Py = Py + (Vy*dt);
}
