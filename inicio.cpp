#include "inicio.h"
#include "ui_inicio.h"
#include "juego.h"
#include "capagladiador.h"
#include "capatorres.h"
#include "listagladiadores.h"
#include "listatorres.h"
#include "torre.h"
#include "gladiador.h"
#include <iostream>

using namespace std;

Inicio::Inicio(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Inicio)
{
    listaTorres = new ListaTorre();
    listaGladiadores = new ListaGladiador();

    getTorres();
    getGladiadores();

    ui->setupUi(this);
    Juego1 = new Juego(&dibu,this, listaTorres, listaGladiadores);
    ui->LayoutJuego->addWidget(Juego1,0,Qt::Alignment());

    torres = new CapaTorres(&dibu,this);
    ui->LayoutTorres->addWidget(torres,0,Qt::Alignment());

    gladiador = new CapaGladiador(&dibu,this);
    ui->LayoutGladiadores->addWidget(gladiador,0,Qt::Alignment());

    connect(Juego1,SIGNAL(ponerT()),this,SLOT(revisar()));
    connect(torres,SIGNAL(SeleccionoTipo()),Juego1,SLOT(mostrarNodos()));


}

void Inicio::getTorres(){
    int cont=0;
    for (int i=0;i<6;i++){
        if(cont==3){
            cont=0;
        }
        cont++;
        Torre *nueva = new Torre(-1,-1,cont);
        nueva->setNombre("Torre"+to_string(i));
        listaTorres->agregar(nueva);
    }
}

void Inicio::getGladiadores(){
    for (int x=0;x<5;x++){
            for (int y=0;y<5;y++){
                Gladiador *nuevo = new Gladiador((x*30)-4*30,(y*30)-3*30);
                string nombre = "Gladiador"+to_string(x)+to_string(y);
                nuevo->setNombre(nombre);
                listaGladiadores->agregar(nuevo);
                //cout<<(x*30)-4*30<<","<<(y*30)-3*30<<endl;
            }
        }
    }

Torre * Inicio::tomarUnaTorre(int tipo){
    for (int i=0;i<Juego1->listaTorres->tamano();i++){
        if(Juego1->listaTorres->retornar(i)->getDato()->Tipo==tipo && Juego1->listaTorres->retornar(i)->getDato()->colocada==false){
            cout<<Juego1->listaTorres->retornar(i)->getDato()->getNombre()<<endl;
            return Juego1->listaTorres->retornar(i)->getDato();
        }
    }
    return nullptr;
}

void Inicio::revisar(){
    if (torres->tipoSelec!=nullptr && Juego1->nodoSelec->free && cont<listaTorres->tamano()){
        if (tomarUnaTorre(torres->tipoSelec->Tipo)!=nullptr){
            Juego1->nodoSelec->setTorre(tomarUnaTorre(torres->tipoSelec->Tipo));
            Juego1->nodoSelec->free=false;
            cont++;
            Juego1->generarAdyacentes();
            torres->tipoSelec=nullptr;
            Juego1->nodoSelec=nullptr;
        }
    }
}

Inicio::~Inicio()
{
    delete ui;
}

void Inicio::on_BttnIniciar_clicked()
{
    Juego1->iniciarJuego();
}
