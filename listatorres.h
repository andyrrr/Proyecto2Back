#ifndef LISTATORRES_H
#define LISTATORRES_H

#include "torre.h"
#include <string>

using namespace std;
class NodoTorre{
public:
    NodoTorre(Torre *Dato);

     void setDato(Torre *);
     void setSig(NodoTorre *);
     Torre *getDato() const;
     NodoTorre  *getSig() const;
     ~NodoTorre();
private:
    Torre *Dato;
    NodoTorre *Sig;
};
class ListaTorre {
public:
    ListaTorre();
    bool estaVacia();
    void agregar(Torre * torre);
    NodoTorre *retornar(int);
    int tamano();
    string toString();
    void limpiar();
    ~ListaTorre();
    NodoTorre *getInicio();
    void setInicio(NodoTorre *inicio);
    NodoTorre *getFin();
    void setFin(NodoTorre *fin);
    NodoTorre *Inicio;
    NodoTorre *Fin;
};

#endif // LISTATORRES_H
