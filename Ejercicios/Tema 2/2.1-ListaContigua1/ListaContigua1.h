#pragma once

#include <stdbool.h>
#include <stdlib.h>

#define INCREMENTO = 5;

typedef struct{
    int n;
    int capacidad;
    int *array;
}ListaContigua;

ListaContigua* constructor();

void destructor(ListaContigua* lista);

bool listaLlena(ListaContigua* lista);

int get(int pos, ListaContigua* lista);

void modificar(int pos, int num, ListaContigua* lista);

void ampliarReducir(int nuevoTam, ListaContigua* lista);

void insertarFinal(int num, ListaContigua* lista);

void eliminarFinal(ListaContigua* lista);
