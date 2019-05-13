#include "juego.h"
#include <QPainter>
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <cstdlib>

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
    //camp=buscarCamino();
    //for (int i=0;i<listaGladiadores->tamano();i++){
    //    listaGladiadores->retornar(i)->getDato()->setCamino(camp);
    //}
    connect(pro,SIGNAL(progreso()),this,SLOT(recibeCaminar()));
    connect(dis,SIGNAL(progreso()),this,SLOT(recibeDisparo()));
    pro->terminar(false);
    repaint();
    pasas = true;
}

void Juego::generarMatriz(){
    for (int x = 0; x < 10; x++) {
        for (int y=0;y<10;y++) {
            NodoMatriz *p = new NodoMatriz(x*62+30,y*56+30);
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
    /*for(int i=0;i<camp->tamano();i++){
        if (camp->retornar(i)->getSig()!=nullptr){
            int xi=camp->retornar(i)->getDato()->CorX;
            int yi=camp->retornar(i)->getDato()->CorY;
            int xf=camp->retornar(i)->getSig()->getDato()->CorX;
            int yf=camp->retornar(i)->getSig()->getDato()->CorY;
            Dibu->PintarFlechas2(&painter,xi+20,yi+20,xf+20,yf+20);
        }
    }*/
    for (int i=0;i<listaGladiadores->tamano();i++){
        int x=listaGladiadores->retornar(i)->getDato()->getCorXCambio();
        int y=listaGladiadores->retornar(i)->getDato()->getCorYCambio();

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

                }
            }
        }
    }

}


void Juego::estaEnNodo(Gladiador *p){
    int gx=p->getCorXCambio();
    int gy=p->getCorYCambio();
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

ListaNodoMatriz* Juego::buscarCamino(){
    ListaNodoMatriz *camino= new ListaNodoMatriz();
    cout<<"Aloooooo"<<camino->toString()<<endl;
    NodoMatriz *inicio;
    NodoMatriz *actual;
    NodoMatriz *final;
    inicio= matriz[0][0];
    final= matriz[9][9];
    int col=0;
    int fil=0;
    actual=inicio;
    camino->agregar(actual);
    srand(time(NULL));
    while (actual!=final){
        int caso=0;
        caso=rand()%3;
        if (caso==0){
            if ((col+1)<10){
                col=col+1;
                actual=matriz[col][fil];
                camino->agregar(actual);
            }

        }else if (caso==1){
            if ((fil+1)<10){
                fil=fil+1;
                actual=matriz[col][fil];
                camino->agregar(actual);
            }

        }else if (caso ==2){
            if((col+1)<10 && (fil+1)<10){
                col=col+1;
                fil=fil+1;
                actual=matriz[col][fil];
                camino->agregar(actual);
            }
        }

    }
    cout<<camino->toString()<<endl;
    return camino;
}

void Juego::recibeCaminar(){
    for (int i=0;i<listaGladiadores->tamano();i++){
        listaGladiadores->retornar(i)->getDato()->setCorde();
        int cx=listaGladiadores->retornar(i)->getDato()->getCorXCambio();
        int cy=listaGladiadores->retornar(i)->getDato()->getCorYCambio();
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
    srand(time(NULL));
    for (int i=0;i<listaGladiadores->tamano();i++){
        listaGladiadores->retornar(i)->getDato()->buscarCamino(matriz);
    }
    pro->start();
    dis->start();
}
