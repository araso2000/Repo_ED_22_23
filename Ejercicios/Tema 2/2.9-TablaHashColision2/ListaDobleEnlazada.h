#pragma once

#include <stdlib.h>
#include "HashColision.h"

typedef struct{
    int matricula;
    char nombre[10];
}Estudiante;

typedef struct Nodo{
    Estudiante elemento;
    struct Nodo *siguiente;
    struct Nodo *anterior;
}Nodo;

typedef struct ListaDobleEnlazada{
    Nodo *primerNodo;
    int tamActual;
    int posLastNodo;
    Nodo *lastNodo;
}ListaDobleEnlazada;

ListaDobleEnlazada* constructorLista();

Nodo* getNodo(ListaDobleEnlazada *lista, int posicion);

void setValor(ListaDobleEnlazada *lista, int posicion, Estudiante student);

Estudiante getValor(ListaDobleEnlazada *lista, int posicion);

void insertarLista(ListaDobleEnlazada *lista, int posicion, Estudiante student);

void eliminarLista(ListaDobleEnlazada *lista, int posicion);

void destructorLista(ListaDobleEnlazada *lista);

void concatenar(ListaDobleEnlazada *lista1, ListaDobleEnlazada *lista2);

int buscarLista(ListaDobleEnlazada *lista, Estudiante student);