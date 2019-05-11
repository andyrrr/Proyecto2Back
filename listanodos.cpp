#include "listanodos.h"
#include "nodomatriz.h"

NodoNodoMatriz::NodoNodoMatriz(NodoMatriz *dato):Dato(dato), Sig(nullptr){

}
void NodoNodoMatriz::setDato(NodoMatriz *dato) {
    Dato=dato;
}
void NodoNodoMatriz::setSig(NodoNodoMatriz *sig) {
    Sig=sig;
}
NodoMatriz *NodoNodoMatriz::getDato() const{
    return Dato;
}
NodoNodoMatriz *NodoNodoMatriz::getSig() const{
    return Sig;
}
NodoNodoMatriz::~NodoNodoMatriz() {

}

ListaNodoMatriz::ListaNodoMatriz() {
    Inicio= nullptr;
    Fin= nullptr;
}


bool ListaNodoMatriz::estaVacia() {
    return this->getInicio()== nullptr;
}


void ListaNodoMatriz::agregar(NodoMatriz *dato) {
    NodoNodoMatriz *actual= this->getInicio();
    if (estaVacia()){
        actual = new NodoNodoMatriz(dato);
        this->setInicio(actual);
        this->setFin(actual);
    } else {
        actual = new NodoNodoMatriz(dato);
        actual->setSig(Inicio);
        this->setInicio(actual);

    }
}


NodoNodoMatriz *ListaNodoMatriz::retornar(int i) {
    int lugar=0;
    NodoNodoMatriz *actual = this->getInicio();
    while (lugar<i){
        actual = actual->getSig();
        lugar++;
    }
    return actual;
}


string ListaNodoMatriz::toString() {
    string ListaFinal="[";
    NodoNodoMatriz *actual = this->getInicio();
    if (estaVacia()){
        return "";
    } else {
        while(actual != nullptr){
            if (actual==Inicio){
                ListaFinal = to_string(5);
                ListaFinal= ListaFinal + "("+to_string(actual->getDato()->CorX)+","+to_string(actual->getDato()->CorY)+")";
            }else{
                ListaFinal= ListaFinal+", "+ "("+to_string(actual->getDato()->CorX)+","+to_string(actual->getDato()->CorY)+")";
            }
            actual=actual->getSig();
        }
    }
    ListaFinal=ListaFinal+"]";
    return ListaFinal;
}



int ListaNodoMatriz::tamano() {
    if (estaVacia()){
        return  0;
    } else {
        int tam = 1;
        NodoNodoMatriz *actual = this->getInicio();
        while (actual->getSig() != nullptr) {
            actual = actual->getSig();
            tam++;
        }
        return tam;
    }
}


void ListaNodoMatriz::limpiar() {

    this->setInicio(nullptr);
    this->setFin(nullptr);
}

NodoNodoMatriz *ListaNodoMatriz::getInicio() {
    return Inicio;
}


void ListaNodoMatriz::setInicio(NodoNodoMatriz *inicio) {
    Inicio = inicio;
}


NodoNodoMatriz *ListaNodoMatriz::getFin(){
    return Fin;
}


void ListaNodoMatriz::setFin(NodoNodoMatriz *fin) {
    Fin = fin;
}

ListaNodoMatriz::~ListaNodoMatriz() {

}
