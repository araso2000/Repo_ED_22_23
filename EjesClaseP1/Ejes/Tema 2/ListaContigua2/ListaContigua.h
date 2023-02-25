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

int get(int pos, ListaContigua* lista);

void modificar(int pos, int num, ListaContigua* lista);

void ampliarReducir(int nuevoTam, ListaContigua* lista);

void insertarFinal(int num, ListaContigua* lista);

void eliminarFinal(ListaContigua* lista);

void insertar(int num, int pos, ListaContigua *lista);

void eliminar(int pos, ListaContigua *lista);

void concatenar(ListaContigua *lista1, ListaContigua *lista2);

int buscar(int elem, ListaContigua *lista);