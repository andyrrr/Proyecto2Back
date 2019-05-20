#ifndef NODOMATRIZ_H
#define NODOMATRIZ_H
#include <QPen>
#include "torre.h"
#include "listatorres.h"
#include <QObject>

class ListaGladiador;
class NodoMatriz : public QObject
{
public:
    NodoMatriz(int corx,int cory);
    bool flechas;
    int CorX;
    int CorY;
    QPen contorno;
    string toSting();
    void setContorno(QColor color);
    Torre *puesta;
    bool free;
    void setTorre(Torre *torre);
    void setVigilante(Torre *vigilante);
    void setGladiadores(ListaGladiador *gladiadores);

public slots:
    ListaTorre *listaVigilantes;
    ListaGladiador *listaGladiadores;
    void lleganFlechas(int daño);

};

#endif // NODOMATRIZ_H
