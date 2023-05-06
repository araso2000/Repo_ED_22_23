#pragma once
#include "ListaDobleEnlazada.h"

typedef struct Aeropuerto{ //Nodo
    char nombre[20];
    struct ListaDobleEnlazada *salientes;
    struct ListaDobleEnlazada *entrantes;
}Aeropuerto;

typedef struct Ruta{ //Arco
    char aeropuerto[20];
    int km;
    char empresa[20];
}Ruta;
