#include "flecha.h"
#include <string>
#include <iostream>
#include "torre.h"

using namespace std;



Flecha::Flecha(Torre *padre,int corxi,int coryi,int corxf,int coryf):
    CorXIni(corxi),CorYIni(coryi),CorXFin(corxf),CorYFin(coryf),
    CorXCambio(corxi),CorYCambio(coryi),Padre(padre)
{
    llegaX=false;
    llegaY=false;
    Asignable=true;

}


int Flecha::getDaño(){
    return Daño;
}

void Flecha::setDaño(int daño){
    Daño=daño;
}

int Flecha::getCorXIni(){
    return CorXIni;
}
int Flecha::getCorYIni(){
    return CorYIni;
}
int Flecha::getCorXFin(){
    return CorXFin;
}
int Flecha::getCorYFin(){
    return CorYFin;
}
int Flecha::getCorXCambio(){
    return CorXCambio;
}
int Flecha::getCorYCambio(){
    return CorYCambio;
}
void Flecha::setllegaX(bool llegax){
    llegaX=llegax;
}
void Flecha::setllegaY(bool llegay){
    llegaY=llegay;
}
void Flecha::setAsignable(bool asignable){
    Asignable=asignable;
}
void Flecha::setCorXIni(int corxi){
    CorXCambio=corxi;
    CorXIni=corxi;
}

void Flecha::setCorYIni(int coryi){
    CorYCambio=coryi;
    CorYIni=coryi;
}

void Flecha::setCorXFin(int corxf){
    CorXFin=corxf;
}

void Flecha::setCorYFin(int coryf){
    CorYFin=coryf;
}
void Flecha::setCorXCambio(int x){
    CorXCambio=x;
}
void Flecha::setCorYCambio(int y){
    CorYCambio=y;
}
bool Flecha::getllegaX(){
    return llegaX;
}
bool Flecha::getllegaY(){
    return llegaY;
}
bool Flecha::getAsignable(){
    return Asignable;
}

void Flecha::setCorde(){
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

    CorXCambio=CorXCambio+x;
    CorYCambio=CorYCambio+y;

    if ((CorXIni>=CorXFin && CorXCambio<=CorXFin)
            || (CorXIni<=CorXFin && CorXCambio>=CorXFin)){
        llegaX=true;
    }
    if ((CorYIni>=CorYFin && CorYCambio<=CorYFin)
            || (CorYIni<=CorYFin && CorYCambio>=CorYFin)){
        llegaY=true;
    }

    if (llegaX && llegaY){
        CorXCambio=CorXIni;
        CorYCambio=CorYIni;
        llegaX=false;
        llegaY=false;
        Padre->quitarTarget1();
        Asignable=true;
    }
}


string Flecha::toString(){
    return "(I:"+to_string(CorXIni)+","+to_string(CorYIni)+","
                            +" F:"+to_string(CorXFin)+","+to_string(CorYFin)+")";

}
