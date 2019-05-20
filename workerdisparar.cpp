#include "workerdisparar.h"
#include <unistd.h>
#include <iostream>

using namespace std;


WorkerDisparar::WorkerDisparar(QObject *parent): QThread(parent)
{
    cout<<"Se inicializa el worker para disparar"<<endl;
    end=false;
}

void WorkerDisparar::terminar(bool cambio){

    end=cambio;
}

void WorkerDisparar::run(){
    cout<<"Se inicia el thread dsiparar"<<endl;
    int segundos=0;
    while (end==false){
        //25000
        usleep(12500);
        segundos++;
        emit progreso();
    }
}
