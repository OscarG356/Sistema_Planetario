#ifndef CUERPO_H
#define CUERPO_H


class Cuerpo
{
private:
    float Px; //Posiciones
    float Py;
    float Vx; //Velocidades
    float Vy;
    float Radio;
    float Masa;
    float Ax; //Aceleraciones
    float Ay;
    float Gravity;
    float Range; //Distancia

public:
 Cuerpo(float _px, float _py, float _vx, float _vy, float mass, float _radio);

 float getPx() const;
 float getPy() const;
 float getMasa() const;
 float getRadio() const;

 void acelerar(float _px2, float _py2, float _mass2);
 void actualizar(float dt);

};

#endif // CUERPO_H
