#include "torre.h"
#include "gladiador.h"
#include "iostream"

using namespace std;

Torre::Torre(int corx, int cory,int tipo):CorX(corx),CorY(cory),Tipo(tipo)
{
    Target= nullptr;
    contorno.setWidth(2);
    contorno.setColor(Qt::black);
    colocada =false;


    flecha1 = new Flecha(CorX,CorY,CorX,CorY);
}

void Torre::setContorno(QColor color){
    contorno.setColor(color);
}

string Torre::getNombre() {
    return Nombre;
}

void Torre::setNombre(string nombre){
    Nombre=nombre;
}

void Torre::setTarget(Gladiador *target){
    Target = target;
    Target->setAtacadoPor(this);
    cout<<"Target: "<<Target->getNombre()<<"--------------------"<<endl;
    cout<<CorX<<","<<CorY<<endl;
    flecha1->setCorXIni(CorX+20);
    flecha1->setCorYIni(CorY+20);
    setCordFlecha(Target->CorX,Target->CorY);
    }

void Torre::setCordFlecha(int x, int y){
    flecha1->setCorXFin(x);
    flecha1->setCorYFin(y);
    cout<<"Se cambio la direccion de la flecha"<<endl;
    cout<<flecha1->toString()<<endl;

}
