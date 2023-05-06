#pragma once

#include "Aeropuerto.h"

#include <stdlib.h>

typedef struct Nodo{
    Ruta elemento;
    struct Nodo *siguiente;
    struct Nodo *anterior;
}Nodo;

typedef struct{
    Nodo *primerNodo;
    int tamActual;
    int posLastNodo;
    Nodo *lastNodo;
}ListaDobleEnlazada;

ListaDobleEnlazada* constructorEnlazadas();

Nodo* getNodo(ListaDobleEnlazada *lista, int posicion);

void setValor(ListaDobleEnlazada *lista, int posicion, Ruta nuevoNum);

Ruta getValor(ListaDobleEnlazada *lista, int posicion);

void insertarEnlazada(ListaDobleEnlazada *lista, int posicion, Ruta numero);

void eliminarEnlazada(ListaDobleEnlazada *lista, int posicion);

void destructorEnlazada(ListaDobleEnlazada *lista);

void concatenarEnlazada(ListaDobleEnlazada *lista1, ListaDobleEnlazada *lista2);

int buscar(ListaDobleEnlazada *lista, Ruta elemento);