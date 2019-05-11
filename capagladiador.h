#ifndef CAPAGLADIADOR_H
#define CAPAGLADIADOR_H
#include <QWidget>
#include "dibujar.h"

class CapaGladiador;

class CapaGladiador : public QWidget
{
    Q_OBJECT

public:
    CapaGladiador(Dibujar *dibujar, QWidget *parent);
protected:
    void paintEvent(QPaintEvent *event) override;
private:
    Dibujar *Dibu;
};
#endif // CAPAGLADIADOR_H
