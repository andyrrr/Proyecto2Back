#include "json_m.h"
#include <iostream>
#include <fstream>


using namespace std;
json_m::json_m()
{

}
json GenerarJson_lista(ListaGladiador lista){
    json j1;
    j1["POST"]="BEST";
    for (int i = 0; i < 2; ++i) {
        j1["ID"+i] = lista.retornar(i)->getDato()->getID();
    }
    return j1;

}

ListaGladiador json_m::generarlista(json j1){
    ListaGladiador ls;

    for (int i = 0; i <25 ; ++i) {
        int arr[9];

        for (int j = 0; j < 9; ++j) {
            arr[j]=j1["ID"+to_string(i)][j];

        }

        cout<<"Haciendo Gladiador "+to_string(arr[0])<<endl;
        Gladiador *gl = new Gladiador(arr[0],0,0);
        gl->setCromosome(arr);
        gl->setResistencia(-arr[8]);
        cout<<gl->getResistencia()<<endl;
        ls.agregar(gl);
    }
    return ls;
}

json json_m::string_json(string s){
    json j1;
    j1 = json::parse(s);
    return j1;

}
string json_m::json_string(json j1){
    string s;
    s = j1.dump();
    return s;
}
