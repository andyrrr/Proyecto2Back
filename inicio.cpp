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
#include "json_m.h"

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
    /*srand(time(0));
    for (int x=0;x<5;x++){
            for (int y=0;y<5;y++){
                Gladiador *nuevo = new Gladiador((x*30)-4*30,(y*30)-3*30);
                int r= rand()%20;
                //Gladiador *nuevo = new Gladiador(0,0);
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
    */

    json_m js;
        string h = "{\"ID10\":[591206,2,3,2,3,8,9,2,5],\"ID11\":[55241,6,6,4,1,7,4,9,5],\"ID14\":[236321,9,8,3,6,8,5,6,7],\"ID15\":[118788,2,2,9,7,4,4,2,5],\"ID12\":[103723,8,1,9,3,6,4,4,6],\"ID13\":[279696,1,1,9,4,3,1,8,4],\"ID18\":[529620,3,3,5,1,7,9,5,5],\"ID19\":[925479,3,3,1,3,1,2,9,4],\"ID16\":[872684,6,7,8,2,9,5,4,6],\"ID17\":[155582,1,1,5,9,2,4,1,3],\"ID0\":[464741,3,5,6,5,1,1,5,3],\"ID2\":[340272,7,8,6,2,3,4,1,4],\"ID1\":[877327,5,8,5,7,8,3,4,7],\"ID4\":[65700,1,1,3,3,8,8,4,4],\"ID21\":[443287,7,9,9,6,3,4,5,6],\"ID3\":[990292,1,6,3,4,7,7,1,4],\"ID22\":[718224,8,1,9,6,9,2,8,7],\"ID6\":[583606,2,4,3,1,8,1,2,3],\"ID5\":[830276,8,6,6,6,1,4,1,5],\"ID20\":[605852,1,6,9,4,9,8,1,6],\"ID8\":[379785,7,2,1,8,7,4,3,5],\"ID7\":[886679,1,6,5,1,8,8,1,5],\"ID23\":[357476,8,3,9,7,9,9,9,7],\"ID9\":[862956,9,1,4,3,5,7,5,6],\"ID24\":[679261,9,9,9,9,9,9,9,9]}"
    ;

        ListaGladiador ls = js.generarlista(js.string_json(h));
        *listaGladiadores = ls;
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
