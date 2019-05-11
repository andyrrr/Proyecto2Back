#ifndef INICIO_H
#define INICIO_H

#include <QMainWindow>
#include "dibujar.h"
#include "listagladiadores.h"
#include "listatorres.h"

#include "juego.h"
#include "capagladiador.h"
#include "capatorres.h"
#include <QMouseEvent>

namespace Ui {
class Inicio;
}

class Inicio : public QMainWindow
{
    Q_OBJECT

public:
    explicit Inicio(QWidget *parent = nullptr);
    void getTorres();
    void getGladiadores();
    void postTorres();
    void postGladiadores();
    void postIniciar();

    ListaGladiador *listaGladiadores;
    ListaTorre *listaTorres;

    Juego *Juego1;
    CapaTorres *torres;
    CapaGladiador *gladiador;
    int cont=0;

    Torre * tomarUnaTorre(int tipo);
    ~Inicio();

private slots:
    void on_BttnIniciar_clicked();
    void revisar();

private:
    Ui::Inicio *ui;
    Dibujar dibu;
};

#endif // INICIO_H
