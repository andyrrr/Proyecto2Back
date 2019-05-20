#include "listagladiadores.h"

NodoGladiador::NodoGladiador(Gladiador *dato):Dato(dato), Sig(nullptr){

}
void NodoGladiador::setDato(Gladiador *dato) {
    Dato=dato;
}
void NodoGladiador::setSig(NodoGladiador *sig) {
    Sig=sig;
}
Gladiador *NodoGladiador::getDato() const{
    return Dato;
}
NodoGladiador *NodoGladiador::getSig() const{
    return Sig;
}
NodoGladiador::~NodoGladiador() {

}

ListaGladiador::ListaGladiador() {
    Inicio= nullptr;
    Fin= nullptr;
}


bool ListaGladiador::estaVacia() {
    return this->getInicio()== nullptr;
}


void ListaGladiador::eliminar(Gladiador *gladiador){
    NodoGladiador *actual = this->getInicio();
    if (this->getInicio()->getDato()==gladiador){
        this->setInicio(Inicio->getSig());
    }else {
        while(actual->getSig()!=nullptr){
             if(actual->getSig()->getDato() == gladiador){
                if(actual->getSig()->getSig()==nullptr){
                    actual->setSig(nullptr);
                    break;
                }else{
                    actual->setSig(actual->getSig()->getSig());
                }
            }
            actual = actual->getSig();
        }
    }
}


void ListaGladiador::agregar(Gladiador *dato) {
    NodoGladiador *actual= this->getInicio();
    if (estaVacia()){
        actual = new NodoGladiador(dato);
        this->setInicio(actual);
        this->setFin(actual);
    } else {
        actual = new NodoGladiador(dato);
        actual->setSig(Inicio);
        this->setInicio(actual);

    }
}


NodoGladiador *ListaGladiador::retornar(int i) {
    int lugar=0;
    NodoGladiador *actual = this->getInicio();
    while (lugar<i){
        actual = actual->getSig();
        lugar++;
    }
    return actual;
}


string ListaGladiador::toString() {
    string ListaFinal="[";
    NodoGladiador *actual = this->getInicio();
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



int ListaGladiador::tamano() {
    if (estaVacia()){
        return  0;
    } else {
        int tam = 1;
        NodoGladiador *actual = this->getInicio();
        while (actual->getSig() != nullptr) {
            actual = actual->getSig();
            tam++;
        }
        return tam;
    }
}


void ListaGladiador::limpiar() {

    this->setInicio(nullptr);
    this->setFin(nullptr);
}

NodoGladiador *ListaGladiador::getInicio() {
    return Inicio;
}


void ListaGladiador::setInicio(NodoGladiador *inicio) {
    Inicio = inicio;
}


NodoGladiador *ListaGladiador::getFin(){
    return Fin;
}


void ListaGladiador::setFin(NodoGladiador *fin) {
    Fin = fin;
}

ListaGladiador::~ListaGladiador() {

}
