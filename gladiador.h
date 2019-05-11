#ifndef GLADIADOR_H
#define GLADIADOR_H
#include "listanodos.h"
#include "torre.h"

#include <string>

using namespace std;


class Gladiador
{
public:
    Gladiador(int corX, int corY);
    string getNombre();
    void setNombre(string nombre);
    void setCorde();
    void setActual(NodoMatriz *actual);
    bool SalioNodo();
    void setAtacadoPor(Torre *torre);
    string Nombre="";
    int CorX;
    int CorY;
    ListaNodoMatriz *camino;
    NodoMatriz *Actual;
    Torre *atacadoPor;

};

#endif // GLADIADOR_H
