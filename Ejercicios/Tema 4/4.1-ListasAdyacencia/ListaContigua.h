#pragma once
#include "Aeropuerto.h"

#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#define INCREMENTO = 5;

typedef struct{
    int n;
    int capacidad;
    struct Aeropuerto *array;
}ListaContigua;

ListaContigua* constructor();

void destructor(ListaContigua* lista);

bool listaLlena(ListaContigua* lista);

Aeropuerto get(int pos, ListaContigua* lista);

void modificar(int pos, Aeropuerto num, ListaContigua* lista);

void ampliarReducir(int nuevoTam, ListaContigua* lista);

void insertarFinal(Aeropuerto num, ListaContigua* lista);

void eliminarFinal(ListaContigua* lista);

void insertar(Aeropuerto num, int pos, ListaContigua *lista);

void eliminar(int pos, ListaContigua *lista);

void concatenar(ListaContigua *lista1, ListaContigua *lista2);

int buscarContigua(Aeropuerto elem, ListaContigua *lista);