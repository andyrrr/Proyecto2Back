#include "nodomatriz.h"
#include "listagladiadores.h"
#include <iostream>

using namespace std;


NodoMatriz::NodoMatriz(int corx,int cory): CorX(corx),CorY(cory)
{
    contorno.setColor(Qt::black);
    free=true;
    puesta=nullptr;
    listaVigilantes= new ListaTorre();
    listaGladiadores = new ListaGladiador();
    //atacadoPor=nullptr;

}

void NodoMatriz::setContorno(QColor color){
    contorno.setColor(color);
}/*
void NodoMatriz::setAtacadoPor(Torre *torre){
    atacadoPor=torre;
}

Torre* NodoMatriz::getAtacadoPor(){
    return atacadoPor;
}*/

void NodoMatriz::quitarAtacadoPor(){
    for (int i=0 ;i<listaVigilantes->tamano();i++){
        Torre *temp;
        temp= listaVigilantes->retornar(i)->getDato();
        if (temp->getTarget()==this){
            temp->quitarTarget();
        }
    }
    //atacadoPor->quitarTarget();
    //atacadoPor=nullptr;
}

void NodoMatriz::setTorre(Torre *torre){
    puesta=torre;
    puesta->colocada=true;
    puesta->CorX=CorX;
    puesta->CorY=CorY;
}

void NodoMatriz::setVigilante(Torre *vig){
    listaVigilantes->agregar(vig);
    this->setContorno(Qt::cyan);
}

string NodoMatriz::toSting(){
    string nombre="Nodo ("+to_string(CorX)+","+to_string(CorY)+")";
    return nombre;
}

void NodoMatriz::lleganFlechas(){
    cout<<"Gladiadores atacados"<<endl;
    for (int i=0;i<listaGladiadores->tamano();i++){
        Gladiador *glaTemp;
        glaTemp = listaGladiadores->retornar(i)->getDato();
        cout<<glaTemp->toString()<<endl;
    }
}
