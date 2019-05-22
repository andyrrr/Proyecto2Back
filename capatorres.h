#ifndef CAPATORRES_H
#define CAPATORRES_H

#include <QWidget>
#include "dibujar.h"
#include "listatorres.h"

#include <QMouseEvent>

class CapaTorres;

class CapaTorres : public QWidget
{
    Q_OBJECT
public:
    CapaTorres(Dibujar *dibujar, QWidget *parent, ListaTorre *general);
    void genTorres();
    ListaTorre *tipos;
    ListaTorre *General;
    void mousePressEvent(QMouseEvent *event) override;
    Torre *tipoSelec;
protected:
    void paintEvent(QPaintEvent *event) override;
private:
    Dibujar *Dibu;
signals:
    void SeleccionoTipo();
};

#endif // CAPATORRES_H
