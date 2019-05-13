#include "listaflechas.h"

NodoFlecha::NodoFlecha(Flecha *dato):Dato(dato), Sig(nullptr){

}
void NodoFlecha::setDato(Flecha *dato) {
    Dato=dato;
}
void NodoFlecha::setSig(NodoFlecha *sig) {
    Sig=sig;
}
Flecha *NodoFlecha::getDato() const{
    return Dato;
}
NodoFlecha *NodoFlecha::getSig() const{
    return Sig;
}
NodoFlecha::~NodoFlecha() {

}

ListaFlecha::ListaFlecha() {
    Inicio= nullptr;
    Fin= nullptr;
}


bool ListaFlecha::estaVacia() {
    return this->getInicio()== nullptr;
}


void ListaFlecha::agregar(Flecha *dato) {
    NodoFlecha *actual= this->getInicio();
    if (estaVacia()){
        actual = new NodoFlecha(dato);
        this->setInicio(actual);
        this->setFin(actual);
    } else {
        actual = new NodoFlecha(dato);
        actual->setSig(Inicio);
        this->setInicio(actual);

    }
}


NodoFlecha *ListaFlecha::retornar(int i) {
    int lugar=0;
    NodoFlecha *actual = this->getInicio();
    while (lugar<i){
        actual = actual->getSig();
        lugar++;
    }
    return actual;
}


string ListaFlecha::toString() {
    string ListaFinal="[";
    NodoFlecha *actual = this->getInicio();
    if (estaVacia()){
        return "";
    } else {
        while(actual != nullptr){
            if (actual==Inicio){
                ListaFinal= ListaFinal+actual->getDato()->toString();
            }else{
                ListaFinal= ListaFinal+", "+actual->getDato()->toString();
            }
            actual=actual->getSig();
        }
    }
    ListaFinal=ListaFinal+"]";
    return ListaFinal;
}



int ListaFlecha::tamano() {
    if (estaVacia()){
        return  0;
    } else {
        int tam = 1;
        NodoFlecha *actual = this->getInicio();
        while (actual->getSig() != nullptr) {
            actual = actual->getSig();
            tam++;
        }
        return tam;
    }
}


void ListaFlecha::limpiar() {

    this->setInicio(nullptr);
    this->setFin(nullptr);
}

NodoFlecha *ListaFlecha::getInicio() {
    return Inicio;
}


void ListaFlecha::setInicio(NodoFlecha *inicio) {
    Inicio = inicio;
}


NodoFlecha *ListaFlecha::getFin(){
    return Fin;
}


void ListaFlecha::setFin(NodoFlecha *fin) {
    Fin = fin;
}

ListaFlecha::~ListaFlecha() {

}
