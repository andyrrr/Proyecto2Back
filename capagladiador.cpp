#include "capagladiador.h"
#include <QPainter>

CapaGladiador::CapaGladiador(Dibujar *dibujar, QWidget *parent):
    QWidget (parent), Dibu(dibujar)
{
    repaint();
}

void CapaGladiador::paintEvent(QPaintEvent *event){
    QPainter painter;
    painter.begin(this);
    Dibu->PintarFondo(&painter, 160,591,QBrush(Qt::white));
    if (gladiador){
        Dibu->PintarGladiadores(&painter,100,100);
    }
}

void CapaGladiador::recibirGladidor(){
    gladiador=true;
    repaint();
}
