#ifndef DIBUJAR_H
#define DIBUJAR_H

#include <QWidget>
#include <QBrush>
#include <QFont>
#include <QPen>
#include "listagladiadores.h"
#include "listatorres.h"

class Dibujar
{
public:
    Dibujar();

     void PintarFondo(QPainter *painter, int weight, int height, QBrush color);
     void PintarGladiadores(QPainter *painter, int x, int y);
     void PintarTorres(QPainter *painter, int x, int y, QPen contorno,int tipo);
     void PintarMatriz(QPainter *painter, int x, int y, QPen contorno);
     void PintarFlechas2(QPainter *painter, int xi, int yi, int xf, int yf);
     void PintarGladiadores(QPainter *painter, Gladiador *gladiador);
     void PintarFlechas(QPainter *painter, int x, int y);
     void PintarInfor(QPainter *painter);
     void setTorres(ListaTorre *torres);
private:
     QPen contorno;
     QPen textPen;
     QFont textFont;
     Gladiador *mostrar;
     ListaTorre *Torres;

};

#endif // DIBUJAR_H
