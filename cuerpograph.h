#ifndef CUERPOGRAPH_H
#define CUERPOGRAPH_H

#include<QPainter>
#include <QGraphicsItem>
#include <QGraphicsScene>
#include "cuerpo.h"

class cuerpograph: public QGraphicsItem
{
public:
    cuerpograph(float x, float y, float vx, float vy, float m, float r, int _color);
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    void setEscala(float s);
    void actualizar(float dt);
    Cuerpo *getEsf();

private:
    Cuerpo *esf;
    float escala;
    int Color;

};


#endif // CUERPOGRAPH_H
