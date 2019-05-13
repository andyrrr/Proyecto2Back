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

    void setNombre(string nombre);
    void setCorde();
    void setCorIni(int corx, int cory);
    void setCorFin(NodoMatriz *nodo);
    void setCorCambio(int corx, int cory);
    void setActual(NodoMatriz *actual);
    //void setCamino1(ListaNodoMatriz *camino);

    string getNombre();
    NodoMatriz* getActual();
    int getCorXIni();
    int getCorYIni();
    int getCorXFin();
    int getCorYFin();
    int getCorXCambio();
    int getCorYCambio();
    bool getLlegaNodo();
    bool getLlegaFinal();
    ListaNodoMatriz * getCamino();
    void buscarCamino(NodoMatriz *matriz[10][10]);
    NodoMatriz *matriz[10][10];

    bool SalioNodo();
    void QuitarActual1();
    string toString();
    int ContNodo;
private:
    ListaNodoMatriz *Camino;
    NodoMatriz *Actual;
    string Nombre="";
    int CorXIni;
    int CorYIni;
    int CorXFin;
    int CorYFin;
    int CorXCambio;
    int CorYCambio;
    bool LlegaNodo;
    bool LlegaFinal;
    bool llegaX;
    bool llegaY;
};


#endif // GLADIADOR_H
