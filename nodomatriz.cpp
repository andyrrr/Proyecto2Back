#include "nodomatriz.h"
#include <QtDebug>


NodoMatriz::NodoMatriz(int corx,int cory): CorX(corx),CorY(cory)
{
    contorno.setColor(Qt::black);
    free=true;
    puesta=nullptr;
    listaVigilantes= new ListaTorre();

}

void NodoMatriz::setContorno(QColor color){
    contorno.setColor(color);
}

void NodoMatriz::setTorre(Torre *torre){
    puesta=torre;
    puesta->colocada=true;
    puesta->CorX=CorX;
    puesta->CorY=CorY;

    qDebug()<<"coorde puesta"<<puesta->CorX<<puesta->CorY;
}

void NodoMatriz::setVigilante(Torre *vig){
    listaVigilantes->agregar(vig);
    qDebug()<<listaVigilantes->tamano();
    this->setContorno(Qt::cyan);
}

string NodoMatriz::toSting(){
    string nombre="Nodo ("+to_string(CorX)+","+to_string(CorY)+")";
    return nombre;
}
