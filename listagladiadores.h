#ifndef LISTAGLADIADORES_H
#define LISTAGLADIADORES_H
#include "gladiador.h"
#include <string>

using namespace std;
class NodoGladiador{
public:
    NodoGladiador(Gladiador *Dato);

     void setDato(Gladiador *);
     void setSig(NodoGladiador *);
     Gladiador *getDato() const;
     NodoGladiador  *getSig() const;
     ~NodoGladiador();
private:
    Gladiador *Dato;
    NodoGladiador *Sig;
};
class ListaGladiador {
public:
    ListaGladiador();
    bool estaVacia();
    void agregar(Gladiador * gladiador);
    NodoGladiador *retornar(int);
    int tamano();
    string toString();
    void limpiar();
    ~ListaGladiador();
    NodoGladiador *getInicio();
    void setInicio(NodoGladiador *inicio);
    NodoGladiador *getFin();
    void setFin(NodoGladiador *fin);
    NodoGladiador *Inicio;
    NodoGladiador *Fin;

    void eliminar(Gladiador *gladiador);
};

#endif // LISTAGLADIADORES_H
