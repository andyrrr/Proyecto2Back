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

    ui->setupUi(this);
    Iteracion();

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
    srand(time(0));
    for (int x=0;x<5;x++){
            for (int y=0;y<5;y++){
                //Gladiador *nuevo = new Gladiador((x*30)-4*30,(y*30)-3*30);
                int r= rand()%20;
                Gladiador *nuevo = new Gladiador(0,0);
                string nombre = "Gladiador"+to_string(x)+to_string(y);
                cout<<nombre<<" :"<<" con resistencia: "<<r<<endl;
                nuevo->Resistencia=r;
                nuevo->setNombre(nombre);
                cout<<nuevo->toString()<<endl;
                cout<<""<<nuevo->getResistencia()<<endl;
                cout<<"-----------------------------"<<endl;


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
    torres->repaint();
}

void Inicio::Iteracion(){
    cont=0;
    cout<<"LLEGA A ITERACION------------------------------------------------------"<<endl;
    if (Juego1!=nullptr){

        Juego1->close();
        torres->close();
        gladiador->close();

    }
    listaTorres = new ListaTorre();
    listaGladiadores = new ListaGladiador();

    getTorres();
    getGladiadores();
    Juego1 = new Juego(&dibuJuego,this, listaTorres, listaGladiadores);
    torres = new CapaTorres(&dibuTorres,this, listaTorres);
    gladiador = new CapaGladiador(&dibuGla,this);


    ui->LayoutJuego->addWidget(Juego1,0,Qt::Alignment());
    ui->LayoutTorres->addWidget(torres,0,Qt::Alignment());
    ui->LayoutGladiadores->addWidget(gladiador,0,Qt::Alignment());



    connect(Juego1,SIGNAL(ponerTorre()),this,SLOT(revisar()));
    connect(torres,SIGNAL(SeleccionoTipo()),Juego1,SLOT(mostrarNodos()));
    connect(Juego1,SIGNAL(mostrarGladiador(Gladiador*)),gladiador,SLOT(recibirGladidor(Gladiador*)));
    connect(Juego1,SIGNAL(terminaIteracion()),this,SLOT(Iteracion()));

}

Inicio::~Inicio()
{
    delete ui;
}

void Inicio::on_BttnIniciar_clicked()
{
    Juego1->iniciarJuego();
}
