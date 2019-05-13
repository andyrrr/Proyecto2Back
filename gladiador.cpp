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
}
/*
void Gladiador::setCamino1(ListaNodoMatriz *camino){
    ContNodo=0;
    Camino=camino;
    setCorFin(Camino->retornar(ContNodo)->getDato());

}
*/

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


bool Gladiador::SalioNodo(){
    int nodoX=Actual->CorX;
    int nodoY=Actual->CorY;
    if(!(CorXCambio<nodoX+40 && CorXCambio>nodoX && CorYCambio<nodoY+40 && CorYCambio>nodoY)){
        Actual->setContorno(Qt::black);
        QuitarActual1();
        return true;
    }
    return false;
}
void Gladiador::setNombre(string nombre){
    Nombre=nombre;
}
void Gladiador::buscarCamino(NodoMatriz *matriz[10][10]){
    cout<<"entra"<<endl;
    NodoMatriz *inicio;
    NodoMatriz *actual;
    NodoMatriz *final;
    inicio= matriz[0][0];
    final= matriz[9][9];
    int col=0;
    int fil=0;
    actual=inicio;
    Camino->agregar(actual);
    while (actual!=final){
        int caso=0;
        caso=rand()%3;
        if (caso==0){
            if ((col+1)<10 && matriz[col+1][fil]->free){
                col=col+1;
                actual=matriz[col][fil];
                Camino->agregar(actual);
            }

        }else if (caso==1 ){
            if ((fil+1)<10 && matriz[col][fil+1]->free){
                fil=fil+1;
                actual=matriz[col][fil];
                Camino->agregar(actual);
            }

        }else if (caso ==2){
            if((col+1)<10 && (fil+1)<10 && matriz[col+1][fil+1]->free){
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
            cout<<"Alo desde:  "<<getNombre()<<endl;
            cout<<ContNodo<<endl;
            //NodoMatriz *temp;
            //temp= new NodoMatriz(Camino->retornar(ContNodo)->getDato()->CorX+40,
                       //Camino->retornar(ContNodo)->getDato()->CorY+40);
            //setCorFin(temp);
            LlegaFinal=true;
        }
    }
}

string Gladiador::toString(){
    return this->getNombre()+" (X:"+to_string(CorXCambio)+", Y:"+to_string(CorYCambio);
}
