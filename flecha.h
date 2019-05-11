#ifndef FLECHA_H
#define FLECHA_H
#include <string>

using namespace std;
class Flecha
{
public:
    Flecha(int corxi,int coryi,int corxf,int coryf);
    int CorXIni;
    int CorYIni;
    int CorXFin;
    int CorYFin;
    int CorXCambio;
    int CorYCambio;
    void setCorXIni(int corx);
    void setCorYIni(int cory);
    void setCorXFin(int corx);
    void setCorYFin(int cory);
    void setCorde();
    void setCorXCambio(int x);
    void setCorYCambio(int y);
    string toString();
};

#endif // FLECHA_H
