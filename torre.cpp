#include "torre.h"
#include "gladiador.h"
#include "iostream"
#include "nodomatriz.h"

using namespace std;

Torre::Torre(int corx, int cory,int tipo):CorX(corx),CorY(cory),Tipo(tipo)
{
    Target= nullptr;
    contorno.setWidth(2);
    contorno.setColor(Qt::black);
    colocada =false;

    flecha1 = new Flecha(CorX,CorY,CorX,CorY);
}
void Torre::quitarTarget(){
    Target=nullptr;
}

void Torre::setContorno(QColor color){
    contorno.setColor(color);
}

string Torre::getNombre() {
    return Nombre + " ("+to_string(CorX)+","+to_string(CorY)+")";
}

void Torre::setNombre(string nombre){
    Nombre=nombre;
}

NodoMatriz* Torre::getTarget(){
    return Target;
}

void Torre::setTarget(NodoMatriz *nodo){
    cout<<"A la torre"<<CorX<<","<<CorY<<endl;
    cout<<"Se le asigna"<<nodo->toSting()<<endl;
    cout<<nodo->CorX<<" a "<<CorX<<endl;
    cout<<nodo->CorY<<" a "<<CorY<<endl;
    if (nodo->CorX==CorX && CorY==nodo->CorY){
        cout<<"Mismo nodo***************************************"<<endl;
    }
    else if(flecha1->getAsignable()==false){
        cout<<flecha1->toString()<<endl;
        cout<<"Flecha ocupada------------------------------------"<<endl;
    }else{
    Target = nodo;
    //cout<<"Target: "<<Target->toSting()<<"--------------------"<<endl;
    //cout<<CorX<<","<<CorY<<endl;
    flecha1->setCorXIni(CorX+20);
    flecha1->setCorYIni(CorY+20);
    flecha1->setCorXFin(Target->CorX+20);
    flecha1->setCorYFin(Target->CorY+20);
    flecha1->setAsignable1(false);
    cout<<flecha1->toString()<<endl;
    cout<<"Se cambio la direccion de la flecha"<<endl;
    }
}
