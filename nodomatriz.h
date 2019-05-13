#ifndef NODOMATRIZ_H
#define NODOMATRIZ_H
#include <QPen>
#include "torre.h"
#include "listatorres.h"


class ListaGladiador;
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
    ListaGladiador *listaGladiadores;
    void lleganFlechas();
    //void setAtacadoPor(Torre *torre);
    //Torre* getAtacadoPor();
    void quitarAtacadoPor();

private:
    //Torre *atacadoPor;
};

#endif // NODOMATRIZ_H
