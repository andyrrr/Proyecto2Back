#ifndef TORRE_H
#define TORRE_H
#include <string>
#include <QPen>
#include "flecha.h"


using namespace std;

class Gladiador;
class Torre
{
public:
    Torre(int corx, int cory, int tipo);
    string getNombre();
    void setNombre(string nombre);
    void setContorno(QColor color);
    void setTarget(Gladiador *target);
    void setCordFlecha(int x, int y);
    int CorX;
    int CorY;
    QPen contorno;
    bool colocada;
    int Tipo;

    Flecha *flecha1;
    Gladiador *Target;

private:
    string Nombre="";

};

#endif // TORRE_H
