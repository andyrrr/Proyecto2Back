#ifndef FLECHA_H
#define FLECHA_H
#include <string>

using namespace std;
class Torre;
class Flecha
{
public:
    Flecha(Torre *padre,int corxi,int coryi,int corxf,int coryf);

    void setCorXIni(int corx);
    void setCorYIni(int cory);
    void setCorXFin(int corx);
    void setCorYFin(int cory);
    void setCorde();
    void setCorXCambio(int x);
    void setCorYCambio(int y);
    int getCorXIni();
    int getCorYIni();
    int getCorXFin();
    int getCorYFin();
    int getCorXCambio();
    int getCorYCambio();
    void setllegaX(bool llegax);
    void setllegaY(bool llegay);
    void setAsignable(bool asignable);
    string toString();

    bool getllegaX();
    bool getllegaY();
    bool getAsignable();

    int getDaño();
    void setDaño(int daño);
protected:
    int CorXIni;
    int CorYIni;
    int CorXFin;
    int CorYFin;
    int CorXCambio;
    int CorYCambio;
    bool llegaX;
    bool llegaY;
    bool Asignable;
    int Daño;
    Torre *Padre;

};

#endif // FLECHA_H
