#ifndef JUEGO_H
#define JUEGO_H
#include <QWidget>
#include "dibujar.h"
#include "listagladiadores.h"
#include "listatorres.h"
#include "workercaminar.h"
#include "nodomatriz.h"
#include "listaflechas.h"
#include "workerdisparar.h"

#include <QMouseEvent>

class Juego;

class Juego : public QWidget
{
    Q_OBJECT

public:
    Juego(Dibujar *dibujar, QWidget *parent, ListaTorre *torres, ListaGladiador *gladiadores);

    ListaGladiador *listaGladiadores;
    ListaTorre *listaTorres;
    ListaFlecha *listaFlechas;

    WorkerCaminar *pro = new WorkerCaminar;
    WorkerDisparar *dis = new WorkerDisparar;
    void mousePressEvent(QMouseEvent *event) override;


    void iniciarJuego();
    void generarMatriz();

    NodoMatriz *nodoSelec;
    NodoMatriz *matriz [12][12];

    void generarAdyacentes();
    void estaEnNodo(Gladiador *p);
    int ColActual;
    int FilActual;
    Gladiador *Mejor1=nullptr;
    Gladiador *Mejor2=nullptr;

    ListaNodoMatriz *buscarCamino();

    bool TipoSeSelecciono;
    bool pasas;
    ListaNodoMatriz *camp = new ListaNodoMatriz();
    bool GladiadoresLlegan();

protected:
    void paintEvent(QPaintEvent *event) override;

private:
    Dibujar *Dibu;

signals:
    void ponerTorre();
    void mostrarGladiador();
    void terminaIteracion();
public slots:
    void recibeCaminar();
    void mostrarNodos();
    void recibeDisparo();

};

#endif // JUEGO_H
