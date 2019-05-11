#ifndef LISTANodoMatriz_H
#define LISTANodoMatriz_H
#include <string>
#include "nodomatriz.h"

using namespace std;
class NodoNodoMatriz{
public:
    NodoNodoMatriz(NodoMatriz *Dato);

     void setDato(NodoMatriz *);
     void setSig(NodoNodoMatriz *);
     NodoMatriz *getDato() const;
     NodoNodoMatriz  *getSig() const;
     ~NodoNodoMatriz();
private:
    NodoMatriz *Dato;
    NodoNodoMatriz *Sig;
};
class ListaNodoMatriz {
public:
    ListaNodoMatriz();
    bool estaVacia();
    void agregar(NodoMatriz * NodoMatriz);
    NodoNodoMatriz *retornar(int);
    int tamano();
    string toString();
    void limpiar();
    ~ListaNodoMatriz();
    NodoNodoMatriz *getInicio();
    void setInicio(NodoNodoMatriz *inicio);
    NodoNodoMatriz *getFin();
    void setFin(NodoNodoMatriz *fin);
    NodoNodoMatriz *Inicio;
    NodoNodoMatriz *Fin;
};

#endif // LISTANodoMatriz_H
