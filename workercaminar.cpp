#include "workercaminar.h"
#include <unistd.h>

#include <iostream>

using namespace std;


WorkerCaminar::WorkerCaminar(QObject *parent): QThread(parent)
{
    end=false;
}

void WorkerCaminar::terminar(bool cambio){

    end=cambio;
}

void WorkerCaminar::run(){

    cout<<"Se inicia el thread caminar"<<endl;
    int segundos=0;
    while (end==false){
        //200000
        usleep(100000);
        segundos++;
        emit progreso();
    }
}
