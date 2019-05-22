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

void NodoMatriz::setGladiadores(ListaGladiador *gladiadores){
    listaGladiadores=gladiadores;
}

void NodoMatriz::setContorno(QColor color){
    contorno.setColor(color);
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

void NodoMatriz::lleganFlechas(int daño){
    cout<<"Gladiadores atacados"<<endl;
    cout<<this->toSting()<<"Ataca----------------------------"<<endl;
    for (int i=0;i<listaGladiadores->tamano();i++){
        Gladiador *glaTemp;
        glaTemp = listaGladiadores->retornar(i)->getDato();
        if (glaTemp->getActual()==this){
            cout<<glaTemp->toString()<<endl;
            glaTemp->setResistencia(daño);
            cout<<"-----------------------------"<<endl;
            if (glaTemp->getResistencia()<=0){
                cout<<"Se elimina el gladiador"<<endl;
                glaTemp->QuitarActual();
                listaGladiadores->eliminar(glaTemp);
            }
        }
    }
}
