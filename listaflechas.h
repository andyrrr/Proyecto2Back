#ifndef LISTAFLECHAS_H
#define LISTAFLECHAS_H
#include "flecha.h"
#include <string>

using namespace std;
class NodoFlecha{
public:
    NodoFlecha(Flecha *Dato);

     void setDato(Flecha *);
     void setSig(NodoFlecha *);
     Flecha *getDato() const;
     NodoFlecha  *getSig() const;
     ~NodoFlecha();
private:
    Flecha *Dato;
    NodoFlecha *Sig;
};
class ListaFlecha {
public:
    ListaFlecha();
    bool estaVacia();
    void agregar(Flecha * Flecha);
    NodoFlecha *retornar(int);
    int tamano();
    string toString();
    void limpiar();
    ~ListaFlecha();
    NodoFlecha *getInicio();
    void setInicio(NodoFlecha *inicio);
    NodoFlecha *getFin();
    void setFin(NodoFlecha *fin);
    NodoFlecha *Inicio;
    NodoFlecha *Fin;
};

#endif // LISTAFLECHAS_H
