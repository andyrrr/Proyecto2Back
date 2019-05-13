#ifndef TORRE_H
#define TORRE_H
#include <string>
#include <QPen>
#include "flecha.h"

using namespace std;

class NodoMatriz;
class Torre
{
public:
    Torre(int corx, int cory, int tipo);
    string getNombre();
    void setNombre(string nombre);
    void setContorno(QColor color);
    void setTarget(NodoMatriz *nodo);
    NodoMatriz *getTarget();
    void quitarTarget();
    int CorX;
    int CorY;
    QPen contorno;
    bool colocada;
    int Tipo;

    Flecha *flecha1;

private:

    NodoMatriz *Target;
    string Nombre="";

};

#endif // TORRE_H
