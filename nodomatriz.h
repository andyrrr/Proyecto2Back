#ifndef NODOMATRIZ_H
#define NODOMATRIZ_H
#include <QPen>
#include "torre.h"
#include "listatorres.h"


class NodoMatriz
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
    ListaTorre *listaVigilantes;
};

#endif // NODOMATRIZ_H
