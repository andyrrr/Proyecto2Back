#ifndef JSON_M_H
#define JSON_M_H

#include "json.hpp"
#include "listagladiadores.h"
using json = nlohmann::json;

class json_m
{
public:
    json_m();
    json generar_json(ListaGladiador);
    ListaGladiador generarlista(json);
    string json_string(json);
    json string_json(string);
};

#endif // JSON_M_H
