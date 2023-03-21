#pragma once

#include <stdlib.h>

typedef struct Nodo{
    int elemento;
    struct Nodo *siguiente;
}Nodo;

typedef struct{
    Nodo *primerNodo;
    int tamActual;
}ListaEnlazada;

Nodo* getNodo(ListaEnlazada *lista, int posicion);

ListaEnlazada* constructor();

void setValor(Nodo *nodo, int numero);

int getValor(Nodo *nodo);

void insertar(ListaEnlazada *lista, int posicion, int numero);

void eliminar(ListaEnlazada *lista, int posicion);

void destructor(ListaEnlazada *lista);