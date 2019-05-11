#include "listatorres.h"


NodoTorre::NodoTorre(Torre *dato):Dato(dato), Sig(nullptr){

}
void NodoTorre::setDato(Torre *dato) {
    Dato=dato;
}
void NodoTorre::setSig(NodoTorre *sig) {
    Sig=sig;
}
Torre *NodoTorre::getDato() const{
    return Dato;
}
NodoTorre *NodoTorre::getSig() const{
    return Sig;
}
NodoTorre::~NodoTorre() {

}

ListaTorre::ListaTorre() {
    Inicio= nullptr;
    Fin= nullptr;
}


bool ListaTorre::estaVacia() {
    return this->getInicio()== nullptr;
}


void ListaTorre::agregar(Torre *dato) {
    NodoTorre *actual= this->getInicio();
    if (estaVacia()){
        actual = new NodoTorre(dato);
        this->setInicio(actual);
        this->setFin(actual);
    } else {
        actual = new NodoTorre(dato);
        actual->setSig(Inicio);
        this->setInicio(actual);

    }
}


NodoTorre *ListaTorre::retornar(int i) {
    int lugar=0;
    NodoTorre *actual = this->getInicio();
    while (lugar<i){
        actual = actual->getSig();
        lugar++;
    }
    return actual;
}


string ListaTorre::toString() {
    string ListaFinal="[";
    NodoTorre *actual = this->getInicio();
    if (estaVacia()){
        return "";
    } else {
        while(actual != nullptr){
            if (actual==Inicio){
                ListaFinal= ListaFinal+actual->getDato()->getNombre();
            }else{
                ListaFinal= ListaFinal+", "+actual->getDato()->getNombre();
            }
            actual=actual->getSig();
        }
    }
    ListaFinal=ListaFinal+"]";
    return ListaFinal;
}



int ListaTorre::tamano() {
    if (estaVacia()){
        return  0;
    } else {
        int tam = 1;
        NodoTorre *actual = this->getInicio();
        while (actual->getSig() != nullptr) {
            actual = actual->getSig();
            tam++;
        }
        return tam;
    }
}


void ListaTorre::limpiar() {

    this->setInicio(nullptr);
    this->setFin(nullptr);
}

NodoTorre *ListaTorre::getInicio() {
    return Inicio;
}


void ListaTorre::setInicio(NodoTorre *inicio) {
    Inicio = inicio;
}


NodoTorre *ListaTorre::getFin(){
    return Fin;
}


void ListaTorre::setFin(NodoTorre *fin) {
    Fin = fin;
}

ListaTorre::~ListaTorre() {

}
