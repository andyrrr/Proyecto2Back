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
    NodoMatriz *matriz [10][10];

    void generarAdyacentes();
    void estaEnNodo(Gladiador *p);
    int ColActual;
    int FilActual;

    bool TipoSeSelecciono;
    bool pasas;

protected:
    void paintEvent(QPaintEvent *event) override;

private:
    Dibujar *Dibu;

signals:
    void ponerT();
public slots:
    void recibeCaminar();
    void mostrarNodos();
    void recibeDisparo();

};

#endif // JUEGO_H
