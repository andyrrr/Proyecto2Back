#include "workercaminar.h"
#include <unistd.h>



WorkerCaminar::WorkerCaminar(QObject *parent): QThread(parent)
{
    end=false;
}

void WorkerCaminar::terminar(bool cambio){

    end=cambio;
}

void WorkerCaminar::run(){
    int segundos=0;
    while (end==false){
        usleep(200000);
        segundos++;
        emit progreso();
    }
}
