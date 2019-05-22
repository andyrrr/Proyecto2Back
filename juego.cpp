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
    connect(pro,SIGNAL(progreso()),this,SLOT(recibeCaminar()));
    connect(dis,SIGNAL(progreso()),this,SLOT(recibeDisparo()));


    pro->terminar(false);
    repaint();
    pasas = true;
/*
    cout<<"-----------------------------------------------------------------------------------------------"<<endl;
    cout<<"Gladiadores--------------------------------------------------------------"<<endl;
    cout<<listaGladiadores->toString()<<endl;
    cout<<"torres--------------------------------------------------------------"<<endl;
    cout<<listaTorres->toString()<<endl;
    cout<<"flecchas--------------------------------------------------------------"<<endl;
    cout<<listaFlechas->toString()<<endl;
*/
}

void Juego::generarMatriz(){
    for (int x = 0; x < 12; x++) {
        for (int y=0;y< 12;y++) {
            NodoMatriz *p = new NodoMatriz(x*52+30,y*46+30);
            p->setGladiadores(listaGladiadores);
            matriz[x][y]= p;
        }
    }
}
void Juego::mousePressEvent(QMouseEvent *event){
    for (int fila=0;fila<12;fila++){
            for (int col = 0; col < 12; col++) {
                int nodoX=matriz[col][fila]->CorX;
                int nodoY=matriz[col][fila]->CorY;
                if(event->x()<nodoX+40 && event->x()>nodoX && event->y()<nodoY+40 && event->y()>nodoY){
                    nodoSelec= matriz[col][fila];
                    nodoSelec->setContorno(Qt::red);
                    ColActual=col;
                    FilActual=fila;
                    emit(ponerTorre());

                    TipoSeSelecciono=false;
                    repaint();

                }
            }
        }
    for (int i=0;i<listaGladiadores->tamano();i++){
        Gladiador *temp=listaGladiadores->retornar(i)->getDato();
        int glaX= temp->getCorXCambio();
        int glaY= temp->getCorYCambio();
        if(event->x()<glaX+20 && event->x()>glaX && event->y()<glaY+20 && event->y()>glaY){
            cout<<"Se presionó el gladiador: "<<temp->getNombre()<<endl;
            emit (mostrarGladiador(temp));
            break;
        }
    }
}

void Juego::paintEvent(QPaintEvent *event){
    QPainter painter;
    painter.begin(this);
    Dibu->PintarFondo(&painter, 661, 591, QBrush(Qt::green));
    //TipoSeSelecciono=true;
    if (TipoSeSelecciono){
        for (int fil=0; fil<12;fil++){
            for (int col=0;col<12;col++){
                int x= matriz[col][fil]->CorX;
                int y= matriz[col][fil]->CorY;
                Dibu->PintarMatriz(&painter,x,y,matriz[col][fil]->contorno);
            }
        }
    }/*
    for(int i=0;i<camp->tamano();i++){
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
            //Dibu->PintarFlechas2(&painter,temp->getCorXIni(),temp->getCorYIni(),temp->getCorXFin(),temp->getCorYFin());
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
            if (ColActual+x<12 && ColActual+x>-1 && FilActual+y<12 && FilActual+y>-1){
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
    for (int fila=0;fila<12;fila++){
        for (int col = 0; col < 12; col++) {
            NodoMatriz *NodoTemporal;
            NodoTemporal=matriz[col][fila];
            int nodoX=NodoTemporal->CorX;
            int nodoY=NodoTemporal->CorY;
            p->SalioNodo();
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
                //matriz[col][fila]->setContorno(Qt::yellow);
            }
        }
    }
}


void Juego::recibeCaminar(){
    for (int i=0;i<listaGladiadores->tamano();i++){
        Gladiador *temp=listaGladiadores->retornar(i)->getDato();
        temp->setCorde();
        estaEnNodo(temp);

        if (Mejor1 == nullptr || temp->getResistencia()>Mejor1->getResistencia()){
            Mejor1=temp;
            cout<<"Mejor 1: "<<Mejor1->getID()<<endl;
            cout<<"----------------------------------------------------------------------------------------------"<<endl;
        }
        if (Mejor2 == nullptr || (temp->getResistencia()>Mejor2->getResistencia() && temp!=Mejor1)){
            Mejor2=temp;

            cout<<"Mejor 2: "<<Mejor2->getID()<<endl;

            cout<<"----------------------------------------------------------------------------------------------"<<endl;
        }

        Gladiador *temp2=nullptr;
        emit (mostrarGladiador(temp2));
        repaint();
    }

    if(listaGladiadores->tamano()==0 || GladiadoresLlegan()){
        pro->terminar(true);
        pro->quit();
        dis->quit();
        emit(terminaIteracion());
    }
}

bool Juego::GladiadoresLlegan(){
    for (int i=0;i<listaGladiadores->tamano();i++){
        Gladiador *temp= listaGladiadores->retornar(i)->getDato();
        if(temp->ContNodo!=temp->getCamino()->tamano() && !(temp->getLlegaFinal())){
            return false;
        }
    }
    return true;
}
void Juego::mostrarNodos(){
    TipoSeSelecciono = true;
    repaint();
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
    //for (int i=0;i<listaGladiadores->tamano();i++){
    //    listaGladiadores->retornar(i)->getDato()->buscarCamino(matriz);
    //}
    Pair src = make_pair(0, 0);
    Pair dest = make_pair(11, 11);

    AStar *a = new AStar();
    for (int fil=0; fil<12;fil++){
        for (int col=0;col<12;col++){
            NodoMatriz *temp = matriz[fil][col];
            if (!(temp->free)){
                a->blockCell(grid,fil,col);
            }
        }
    }
    a->aStarSearch(grid,src,dest);
    a->finalPath->printNodes();
    ListaNodoMatriz *camino = new ListaNodoMatriz();
    for (int i=0;i<a->finalPath->size;i++){
        int col=a->finalPath->getNode(i)->x_coord;
        int fil=a->finalPath->getNode(i)->y_coord;
        NodoMatriz *temp=matriz[col][fil];
        camino->agregar(temp);
    }
    cout<<camino->toString()<<endl;
    for (int i=0;i<listaGladiadores->tamano();i++){
        listaGladiadores->retornar(i)->getDato()->Camino=camino;
    }
    pro->start();
    dis->start();
}
