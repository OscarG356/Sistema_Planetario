#include "cuerpograph.h"

cuerpograph::cuerpograph(float x, float y, float vx, float vy, float m, float r, int _color): escala(0.05)
{
    esf = new Cuerpo(x,y,vx,vy,m,r);
    Color = _color;
}

QRectF cuerpograph::boundingRect() const
{
    return QRectF(-1*escala*esf->getRadio(),-1*escala*esf->getRadio(),2*escala*esf->getRadio(),2*escala*esf->getRadio());
}

void cuerpograph::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    if (Color==1)
        painter->setBrush(Qt::red);
    painter->drawEllipse(boundingRect());
    if(Color==2)
        painter->setBrush(Qt::blue);
    if(Color==3)
        painter->setBrush(Qt::yellow);
    if(Color==4)
        painter->setBrush(Qt::gray);
    if(Color==5)
        painter->setBrush(Qt::green);
    if(Color==6)
        painter->setBrush(Qt::black);


    painter->drawEllipse(boundingRect());
}

void cuerpograph::setEscala(float s)
{
    escala = s;
}

void cuerpograph::actualizar(float dt)
{
    esf->actualizar(dt);
    setPos(esf->getPx()*escala,esf->getPy()*escala);
}

Cuerpo *cuerpograph::getEsf()
{
    return esf;
}
