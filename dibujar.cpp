#include "dibujar.h"

#include <QPainter>
#include <QPaintEvent>
#include <QWidget>
#include <string>


Dibujar::Dibujar()
{
    contorno.setColor(Qt::black);
    contorno.setWidth(4);
}

void Dibujar::PintarFondo(QPainter *painter, int weight, int height, QBrush color){
    contorno.setWidth(4);
    painter->setPen(contorno);
    painter->setBrush(color);
    painter->drawRect(0,0,weight,height);
}

void Dibujar::PintarTorres(QPainter *painter,int x, int y, QPen cont,int tipo){
    cont.setWidth(2);
    painter->setPen(cont);
    if (tipo==1){
        painter->setBrush(QBrush(QColor(164,32,64)));
    }else if(tipo==2){
        painter->setBrush(QBrush(QColor(164,132,64)));
    }else{
        painter->setBrush(QBrush(QColor(164,32,164)));
    }
    if (x!=-1 && y!=-1){
        painter->drawRect(x,y,40,40);
    }
}

void Dibujar::PintarGladiadores(QPainter *painter, int x, int y){
    contorno.setWidth(2);
    painter->setPen(contorno);
    painter->setBrush(QBrush(Qt::black));
    painter->drawEllipse(x+12,y,2,2);
    painter->drawEllipse(x,y+12,2,2);
    painter->setBrush(QBrush(Qt::blue));
    painter->drawEllipse(x,y,10,10);
}

void Dibujar::PintarMatriz(QPainter *painter, int x, int y, QPen cont){
    cont.setWidth(2);
    painter->setPen(cont);
    painter->setBrush(QBrush(Qt::yellow));
    painter->drawRect(x,y,40,40);

}
void Dibujar::PintarFlechas(QPainter *painter, int xc, int yc){
    QPen con;
    con.setWidth(4);
    con.setColor(QColor(247, 37, 191));
    painter->setPen(con);
    painter->setBrush(QBrush(QColor(247, 37, 191)));
    painter->drawEllipse(xc+20,yc+20,4,4);
}

void Dibujar::PintarFlechas2(QPainter *painter, int xi, int yi,int xf, int yf){
    QPen con;
    con.setWidth(2);
    painter->setPen(con);
    painter->setBrush(QBrush(QColor(247, 37, 191)));
    painter->drawLine(xi,yi,xf,yf);
}
