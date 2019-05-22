#include "gladiador.h"
#include "listanodos.h"
#include <iostream>


using namespace std;

Gladiador::Gladiador(int corx, int cory)
{
    CorXIni=corx;
    CorXFin=corx;
    CorXCambio=corx;

    CorYIni=cory;
    CorYFin=cory;
    CorYCambio=cory;
    Actual=nullptr;
    llegaX=false;
    llegaY=false;
    Camino = new ListaNodoMatriz();
    LlegaFinal=false;
    ContNodo=0;
    Resistencia=0;

    cromosome[6] = {};
}


Gladiador::Gladiador(int id,int corx, int cory)
{
    ID= id;
    CorXIni=corx;
    CorXFin=corx;
    CorXCambio=corx;

    CorYIni=cory;
    CorYFin=cory;
    CorYCambio=cory;
    Actual=nullptr;
    llegaX=false;
    llegaY=false;
    Camino = new ListaNodoMatriz();
    LlegaFinal=false;
    ContNodo=0;
    Resistencia=0;

    cromosome[8] = {};
}


int Gladiador::getID() const
{
    return ID;
}

void Gladiador::setID(int value)
{
    ID = value;
}

int Gladiador::getCromo(){
    return *this->cromosome;
}
void Gladiador::printCromo(){
    for (int var = 0; var < 9; ++var) {
        cout<<cromosome[var]<<endl;
    }
}


void Gladiador::setCromosome(int* cromo){
    for (int var = 0; var < 9; ++var) {
        this->cromosome[var] = cromo[var];
    }
}
void Gladiador::setActual(NodoMatriz *actual){
    Actual=actual;
}

void Gladiador::setCorIni(int corx, int cory){
    CorXIni=corx;
    CorYIni=cory;
}
void Gladiador::setCorFin(NodoMatriz *nodo){
    CorXFin=nodo->CorX+20;
    CorYFin=nodo->CorY+20;
}
void Gladiador::setCorCambio(int corx, int cory){
    CorXCambio=corx;
    CorYCambio=cory;
}

void Gladiador::QuitarActual(){
    Actual=nullptr;

}

string Gladiador::getNombre(){
    return Nombre;
}
NodoMatriz* Gladiador::getActual(){
    return Actual;
}
int Gladiador::getCorXIni(){
    return CorXIni;
}
int Gladiador::getCorYIni(){
    return CorYIni;
}
int Gladiador::getCorXFin(){
    return CorXFin;
}
int Gladiador::getCorYFin(){
    return CorYFin;
}
int Gladiador::getCorXCambio(){
    return CorXCambio;
}
int Gladiador::getCorYCambio(){
    return CorYCambio;
}
bool Gladiador::getLlegaNodo(){
    return LlegaNodo;
}
bool Gladiador::getLlegaFinal(){
    return LlegaFinal;
}

int Gladiador::getResistencia(){
    return Resistencia;
}

void Gladiador::setResistencia(int daño){
    Resistencia=Resistencia-daño;
}

void Gladiador::SalioNodo(){
    if (Actual!=nullptr){
    int nodoX=Actual->CorX;
    int nodoY=Actual->CorY;
    if(!(CorXCambio<nodoX+40 && CorXCambio>nodoX && CorYCambio<nodoY+40 && CorYCambio>nodoY)){
        //Actual->setContorno(Qt::black);
        QuitarActual();
    }
    }
}
ListaNodoMatriz* Gladiador::getCamino(){
    return Camino;
}
void Gladiador::setNombre(string nombre){
    Nombre=nombre;
}
void Gladiador::buscarCamino(NodoMatriz *matriz[12][12]){
    cout<<"entra"<<endl;
    NodoMatriz *inicio;
    NodoMatriz *actual;
    NodoMatriz *final;
    inicio= matriz[0][0];
    final= matriz[11][11];
    int col=0;
    int fil=0;
    actual=inicio;
    Camino->agregar(actual);
    while (actual!=final){
        int caso=0;
        caso=rand()%3;
        if (caso==0){
            if ((col+1)<12 && matriz[col+1][fil]->free){
                col=col+1;
                actual=matriz[col][fil];
                Camino->agregar(actual);
            }

        }else if (caso==1 ){
            if ((fil+1)<12 && matriz[col][fil+1]->free){
                fil=fil+1;
                actual=matriz[col][fil];
                Camino->agregar(actual);
            }

        }else if (caso ==2){
            if((col+1)<12 && (fil+1)<12 && matriz[col+1][fil+1]->free){
                col=col+1;
                fil=fil+1;
                actual=matriz[col][fil];
                Camino->agregar(actual);
            }
        }

    }
    cout<<Camino->toString()<<endl;
}


void Gladiador::setCorde(){
    int x=0;
    int y=0;


    if(CorXCambio>CorXFin){
        x=-2;
    } else if (CorXCambio<CorXFin){
        x=2;

    }
    if(CorYCambio>CorYFin){
        y=-2;
    } else if(CorYCambio<CorYFin) {
        y=2;
    }
    if (!LlegaFinal){
        CorXCambio=CorXCambio+x;
        CorYCambio=CorYCambio+y;
    }
    if ((CorXIni>=CorXFin && CorXCambio<=CorXFin)
            || (CorXIni<=CorXFin && CorXCambio>=CorXFin)){
        llegaX=true;
    }
    if ((CorYIni>=CorYFin && CorYCambio<=CorYFin)
            || (CorYIni<=CorYFin && CorYCambio>=CorYFin)){
        llegaY=true;
    }


    if (llegaX && llegaY && !LlegaFinal){
        if(ContNodo<Camino->tamano()-1){
            ContNodo++;
            setCorFin(Camino->retornar(ContNodo)->getDato());
            llegaX=false;
            llegaY=false;
        }else{
            cout<<getNombre()<<" llegó"<<endl;
            cout<<ContNodo<<endl;
            LlegaFinal=true;
        }
    }
}

string Gladiador::toString(){
    return this->getNombre()+" (X:"+to_string(CorXCambio)+", Y:"+to_string(CorYCambio)+")";
}
