#include "juego.h"
#include <QPainter>
#include <iostream>

using namespace std;
Juego::Juego(Dibujar *dibujar, QWidget *parent, ListaTorre *torres, ListaGladiador *gladiadores):
    QWidget (parent), listaGladiadores(gladiadores), listaTorres(torres), Dibu(dibujar)
{

    listaFlechas = new ListaFlecha();
    for (int i=0;i<torres->tamano();i++){
        listaFlechas->agregar(torres->retornar(i)->getDato()->flecha1);
    }
    TipoSeSelecciono=false;
    nodoSelec=nullptr;
    generarMatriz();
    connect(pro,SIGNAL(progreso()),this,SLOT(recibeCaminar()));
    connect(dis,SIGNAL(progreso()),this,SLOT(recibeDisparo()));
    pro->terminar(false);
    repaint();
    pasas = true;
}

void Juego::generarMatriz(){
    for (int x = 0; x < 10; x++) {
        for (int y=0;y<10;y++) {
            NodoMatriz *p = new NodoMatriz(x*62+30,y*55+30);
            matriz[x][y]= p;
        }
    }
}
void Juego::mousePressEvent(QMouseEvent *event){
    for (int fila=0;fila<10;fila++){
            for (int col = 0; col < 10; col++) {
                int nodoX=matriz[col][fila]->CorX;
                int nodoY=matriz[col][fila]->CorY;
                if(event->x()<nodoX+40 && event->x()>nodoX && event->y()<nodoY+40 && event->y()>nodoY){
                    nodoSelec= matriz[col][fila];
                    nodoSelec->setContorno(Qt::red);
                    ColActual=col;
                    FilActual=fila;
                    emit(ponerT());

                    TipoSeSelecciono=false;
                    repaint();
                }
            }
        }
}

void Juego::paintEvent(QPaintEvent *event){
    QPainter painter;
    painter.begin(this);
    Dibu->PintarFondo(&painter, 661, 591, QBrush(Qt::green));
    TipoSeSelecciono=true;
    if (TipoSeSelecciono){
        for (int fil=0; fil<10;fil++){
            for (int col=0;col<10;col++){
                int x= matriz[col][fil]->CorX;
                int y= matriz[col][fil]->CorY;
                Dibu->PintarMatriz(&painter,x,y,matriz[col][fil]->contorno);
            }
        }
    }
    for (int i=0;i<listaGladiadores->tamano();i++){
        int x=listaGladiadores->retornar(i)->getDato()->CorX;
        int y=listaGladiadores->retornar(i)->getDato()->CorY;
        Dibu->PintarGladiadores(&painter,x,y);
    }


    for (int i=0;i<listaTorres->tamano();i++){
        Torre *temp;
        temp=listaTorres->retornar(i)->getDato();
        int x=listaTorres->retornar(i)->getDato()->CorX;
        int y=listaTorres->retornar(i)->getDato()->CorY;

        Dibu->PintarTorres(&painter,x,y,listaTorres->retornar(i)->getDato()->contorno,listaTorres->retornar(i)->getDato()->Tipo);
    }
    for (int i=0;i<listaFlechas->tamano();i++){
        Flecha *temp;
        temp = listaFlechas->retornar(i)->getDato();
        if (temp->getAsignable()==false){
            Dibu->PintarFlechas(&painter,temp->getCorXCambio(),temp->getCorYCambio());
            Dibu->PintarFlechas2(&painter,temp->getCorXIni(),temp->getCorYIni(),temp->getCorXFin(),temp->getCorYFin());
        }
    }
}


void Juego::generarAdyacentes(){
    int alcance =0;
    if(nodoSelec->puesta->Tipo==1){
        alcance=1;
    }else{
        alcance=2;
    }
    for(int y = -alcance; y<alcance+1;y++){
        for (int x = -alcance;x<alcance+1;x++){
            if (ColActual+x<10 && ColActual+x>-1 && FilActual+y<10 && FilActual+y>-1){
                if (x==0 && y==0){
                    cout<<"Mismo nodo"<<endl;
                }else{
                    matriz[ColActual+x][FilActual+y]->setVigilante(matriz[ColActual][FilActual]->puesta);
                    cout<<matriz[ColActual][FilActual]->puesta->getNombre()<<endl;
                    int xi=matriz[ColActual][FilActual]->puesta->CorX+20;
                    int yi=matriz[ColActual][FilActual]->puesta->CorY+20;
                    int xf=matriz[ColActual+x][FilActual+y]->CorX+20;
                    int yf=matriz[ColActual+x][FilActual+y]->CorY+20;
                    if((x==-1 && y==-1)||(x==0 && y==-1)||(x==1 && y==-1)
                        ||(x==-1 && y==0)||(x==1 && y==0)
                            ||(x==-1 && y==1)||(x==0 && y==1)||(x==1 && y==1)){
                        cout<<"se mamut"<<endl;
                    }else{
                        Flecha *f = new  Flecha(xi,yi,xf,yf);
                        f->setAsignable1(false);
                        listaFlechas->agregar(f);
                    }
                }
            }
        }
    }

}


void Juego::estaEnNodo(Gladiador *p){
    int gx=p->CorX;
    int gy=p->CorY;
    for (int fila=0;fila<10;fila++){
        for (int col = 0; col < 10; col++) {
            NodoMatriz *NodoTemporal;
            NodoTemporal=matriz[col][fila];
            int nodoX=NodoTemporal->CorX;
            int nodoY=NodoTemporal->CorY;
            if (p->getActual()!=nullptr){
                p->SalioNodo();
            }

            if(gx<nodoX+40 && gx>nodoX && gy<nodoY+40 && gy>nodoY){
                //Se le asigna un nodo a una torre
               for (int i=0;i<NodoTemporal->listaVigilantes->tamano();i++){
                       Torre *Torretemp;
                       Torretemp = matriz[col][fila]->listaVigilantes->retornar(i)->getDato();
                       if (Torretemp->getTarget()==nullptr){
                           Torretemp->setTarget(NodoTemporal);
                       }
                    }

                if (p->getActual()==nullptr){
                    p->setActual(matriz[col][fila]);
                }
                matriz[col][fila]->setContorno(Qt::yellow);
            }
        }
    }
}

void Juego::recibeCaminar(){
    for (int i=0;i<listaGladiadores->tamano();i++){
        listaGladiadores->retornar(i)->getDato()->setCorde();
        int cx=listaGladiadores->retornar(i)->getDato()->CorX;
        int cy=listaGladiadores->retornar(i)->getDato()->CorY;
        //verificar nodo salir
        estaEnNodo(listaGladiadores->retornar(i)->getDato());
        repaint();
        if(cx>800 || cy>650){
            pro->terminar(true);
        }
    }
}

void Juego::mostrarNodos(){
    TipoSeSelecciono = true;
}
void Juego::recibeDisparo(){
    for (int i=0;i<listaFlechas->tamano();i++){
        Flecha *temp;
        temp = listaFlechas->retornar(i)->getDato();
        temp->setCorde();
    }
    repaint();
}

void Juego::iniciarJuego(){
    //pro->start();
    dis->start();
}
