#include "capatorres.h"
#include <QPainter>
#include "qdebug.h"

CapaTorres::CapaTorres(Dibujar *dibujar, QWidget *parent, ListaTorre *general):
    QWidget (parent), Dibu(dibujar), General(general)
{
    tipos= new ListaTorre();
    tipoSelec=nullptr;
    genTorres();
    Dibu->setTorres(General);
    repaint();
}

void CapaTorres::paintEvent(QPaintEvent *event){
    QPainter painter;
    painter.begin(this);
    Dibu->PintarFondo(&painter, 161,511,QBrush(Qt::white));

    for (int i=0;i<tipos->tamano();i++){
        Torre *temp=tipos->retornar(i)->getDato();
        int x= temp->CorX;
        int y= temp->CorY;
        Dibu->PintarTorres(&painter,x,y,tipos->retornar(i)->getDato()->contorno,tipos->retornar(i)->getDato()->Tipo);

    }
    Dibu->PintarInfor(&painter);
}
void CapaTorres::mousePressEvent(QMouseEvent *event){
    Torre *temp;
    for (int i=0;i<tipos->tamano();i++){
        temp= tipos->retornar(i)->getDato();
        int tipoX=temp->CorX;
        int tipoY=temp->CorY;
        if(event->x()<tipoX+40 && event->x()>tipoX && event->y()<tipoY+40 && event->y()>tipoY){
            tipoSelec= temp;
            tipoSelec->setContorno(Qt::red);
            emit(SeleccionoTipo());
            repaint();
            }
        }
}

void CapaTorres::genTorres(){
    for (int i=0; i<3;i++){
        Torre *p = new Torre(60,i*100+100,i+1);
        tipos->agregar(p);
    }
}


