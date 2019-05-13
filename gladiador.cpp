#include "gladiador.h"
#include "listanodos.h"
#include <iostream>


using namespace std;

Gladiador::Gladiador(int corx, int cory)
{
    CorX=corx;
    CorY=cory;
    Actual=nullptr;
}

void Gladiador::setActual(NodoMatriz *actual){
    Actual=actual;
    //cout<<"Estoy en "<<Actual->toSting()<<endl;;
}

void Gladiador::QuitarActual1(){
    Actual->quitarAtacadoPor();
    Actual=nullptr;

}

string Gladiador::getNombre(){
    return Nombre;
}

NodoMatriz* Gladiador::getActual(){
    return Actual;
}
bool Gladiador::SalioNodo(){
    int nodoX=Actual->CorX;
    int nodoY=Actual->CorY;
    if(!(CorX<nodoX+40 && CorX>nodoX && CorY<nodoY+40 && CorY>nodoY)){
        Actual->setContorno(Qt::black);
        QuitarActual1();
        return true;
    }
    return false;
}
void Gladiador::setNombre(string nombre){
    Nombre=nombre;
}

void Gladiador::setCorde(){
    CorX=CorX+2;
    CorY=CorY+2;
}

string Gladiador::toString(){
    return this->getNombre()+" (X:"+to_string(CorX)+", Y:"+to_string(CorY);
}
