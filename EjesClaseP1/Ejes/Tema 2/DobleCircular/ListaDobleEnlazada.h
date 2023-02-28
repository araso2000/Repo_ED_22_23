#pragma once

#include <stdlib.h>

typedef struct Nodo{
    int elemento;
    struct Nodo *siguiente;
    struct Nodo *anterior;
}Nodo;

typedef struct{
    Nodo *primerNodo;
    int tamActual;
    int posLastNodo;
    Nodo *lastNodo;
}ListaDobleEnlazada;

ListaDobleEnlazada* constructor();

Nodo* getNodo(ListaDobleEnlazada *lista, int posicion);

void setValor(Nodo *nodo, int numero);

int getValor(Nodo *nodo);

void insertar(ListaDobleEnlazada *lista, int posicion, int numero);

void eliminar(ListaDobleEnlazada *lista, int posicion);

void destructor(ListaDobleEnlazada *lista);

void concatenar(ListaDobleEnlazada *lista1, ListaDobleEnlazada *lista2);

int buscar(ListaDobleEnlazada *lista, int elemento);