#pragma once

#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#define INCREMENTO = 5;

typedef struct{
    int n;
    int capacidad;
    int *array;
}ListaContigua;

ListaContigua* constructor();

void destructor(ListaContigua* lista);

bool listaLlena(ListaContigua* lista);

int get(ListaContigua* lista, int pos);

void modificar(ListaContigua* lista, int pos, int num);

void ampliarReducir(ListaContigua* lista, int nuevoTam);

void insertarFinal(ListaContigua* lista, int num);

void eliminarFinal(ListaContigua* lista);

void insertar(ListaContigua *lista, int num, int pos);

void eliminar(ListaContigua *lista, int pos);

void concatenar(ListaContigua *lista1, ListaContigua *lista2);

int buscar(ListaContigua *lista, int elem);