#ifndef CAPAGLADIADOR_H
#define CAPAGLADIADOR_H
#include <QWidget>
#include "dibujar.h"
#include "gladiador.h"

class CapaGladiador;

class CapaGladiador : public QWidget
{
    Q_OBJECT

public:
    CapaGladiador(Dibujar *dibujar, QWidget *parent);
    bool gladiador=false;
protected:
    void paintEvent(QPaintEvent *event) override;
private:
    Dibujar *Dibu;
    Gladiador *selec;
public slots:
    void recibirGladidor();
};
#endif // CAPAGLADIADOR_H
