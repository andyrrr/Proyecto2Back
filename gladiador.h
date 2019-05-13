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
    NodoMatriz* getActual();
    bool SalioNodo();
    string Nombre="";
    int CorX;
    int CorY;
    ListaNodoMatriz *camino;
    void QuitarActual1();
    string toString();
private:
    NodoMatriz *Actual;
};

#endif // GLADIADOR_H
