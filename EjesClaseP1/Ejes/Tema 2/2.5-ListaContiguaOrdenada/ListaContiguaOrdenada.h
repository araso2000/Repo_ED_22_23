#pragma once

#include <stdbool.h>

typedef struct{
    int n;
    int capacidad;
    int *array;
}ListaContiguaOrdenada;

ListaContiguaOrdenada* constructor();

bool isOrdenada(ListaContiguaOrdenada *lista);

int busquedaBinaria(ListaContiguaOrdenada *lista, int elem, int posIni, int tam);

int buscarOrdenada(ListaContiguaOrdenada *lista, int elem);

void insertarOrdenada(ListaContiguaOrdenada *lista, int elem);

void eliminarOrdenada(ListaContiguaOrdenada *lista, int elem);

int getValor(ListaContiguaOrdenada *lista, int pos);

void insertar(ListaContiguaOrdenada *lista, int pos, int elem);

bool listaLlena(ListaContiguaOrdenada *lista);

void eliminar(ListaContiguaOrdenada *lista, int pos);

void ampliarReducir(ListaContiguaOrdenada *lista, int nuevoTam);