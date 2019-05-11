#include "flecha.h"
#include <string>

using namespace std;

Flecha::Flecha(int corxi,int coryi,int corxf,int coryf):
    CorXIni(corxi),CorYIni(coryi),CorXFin(corxf),CorYFin(coryf)
{


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

void Flecha::setCorde(){
    int x=0;
    int y=0;
    if(CorXIni>CorXFin){
        x=-2;
    } else if (CorXIni<CorXFin){
        x=2;
    }
    if(CorYIni>CorYFin){
        y=-2;
    } else if(CorYIni<CorYFin) {
        y=2;
    }
    CorXCambio=CorXCambio+x;
    CorYCambio=CorYCambio+y;

    if (CorXCambio==CorXFin && CorYCambio==CorYFin){
        CorXCambio=CorXIni;
        CorYCambio=CorYIni;
    }
}

string Flecha::toString(){
    return "(I:"+to_string(CorXIni)+","+to_string(CorYIni)+","
                            +" F:"+to_string(CorXFin)+","+to_string(CorYFin)+")";

}
