#include "dibujar.h"

#include <QPainter>
#include <QPaintEvent>
#include <QWidget>
#include <string>
#include <iostream>

using namespace std;


Dibujar::Dibujar()
{
    Torres=nullptr;
    contorno.setColor(Qt::black);
    contorno.setWidth(4);
    textFont.setPixelSize(2);
    mostrar=nullptr;
}


void Dibujar::setTorres(ListaTorre *torres){
    Torres=torres;
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

void Dibujar::PintarInfor(QPainter *painter){
    int tipo1=0;
    int tipo2=0;
    int tipo3=0;
    for (int i=0;i<Torres->tamano();i++){
        Torre *temp=Torres->retornar(i)->getDato();
        if (temp->CorX==-1 && temp->CorY==-1){
            if (temp->Tipo==1){
                tipo1++;
            } else if (temp->Tipo==2) {
               tipo2++;
            } else {
               tipo3++;
            }
        }
    }
    painter->setPen(QPen(Qt::black));
    painter->drawText(QRect(0,75,160,20),Qt::AlignCenter,"Flechas Sencillas:");
    painter->drawText(QRect(0,145,160,20),Qt::AlignCenter,to_string(tipo1).c_str());
    painter->drawText(QRect(0,175,160,20),Qt::AlignCenter,"Flechas con Fuego");
    painter->drawText(QRect(0,245,160,20),Qt::AlignCenter,to_string(tipo2).c_str());
    painter->drawText(QRect(0,275,160,20),Qt::AlignCenter,"Flechas Explosivas:");
    painter->drawText(QRect(0,345,160,20),Qt::AlignCenter,to_string(tipo3).c_str());


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

void Dibujar::PintarGladiadores(QPainter *painter, Gladiador *gladiador){
    contorno.setWidth(2);
    textPen.setWidth(2);
    if (gladiador!=nullptr) {
        mostrar=gladiador;
    } else if(mostrar!=nullptr && mostrar->Resistencia<=0){
        mostrar=nullptr;
    }
    if (mostrar!=nullptr){
        painter->setBrush(QBrush(QColor(234,176,89)));
        painter->drawRect(60,20,40,60);

        painter->drawText(QRect(0,90,160,20),Qt::AlignCenter,"Nombre:");
        painter->drawText(QRect(0,110,160,20),Qt::AlignCenter,mostrar->getNombre().c_str());

        painter->drawText(QRect(0,140,160,20),Qt::AlignCenter,"Resistencia:");
        painter->drawText(QRect(0,160,160,20),Qt::AlignCenter,to_string(mostrar->getResistencia()).c_str());
    }
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
    painter->setBrush(QBrush(QColor(247, 37, 91)));
    painter->drawEllipse(xc+20,yc+20,4,4);
}

void Dibujar::PintarFlechas2(QPainter *painter, int xi, int yi,int xf, int yf){
    QPen con;
    con.setWidth(2);
    painter->setPen(con);
    painter->setBrush(QBrush(QColor(247, 37, 191)));
    painter->drawLine(xi,yi,xf,yf);
}
