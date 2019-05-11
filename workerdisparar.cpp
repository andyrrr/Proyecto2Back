#include "workerdisparar.h"
#include <unistd.h>


WorkerDisparar::WorkerDisparar(QObject *parent): QThread(parent)
{
    end=false;
}

void WorkerDisparar::terminar(bool cambio){

    end=cambio;
}

void WorkerDisparar::run(){
    int segundos=0;
    while (end==false){
        usleep(25000);
        segundos++;
        emit progreso();
    }
}
