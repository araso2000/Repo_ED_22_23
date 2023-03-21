#pragma once

#include <stdbool.h>

typedef struct{
    int elemento;
    struct Nodo *siguiente;
}Nodo;

typedef struct{
    Nodo *primerNodo;
    int tamActual;
}Pila;

Pila* constructor();

void push(Pila *pila, int elem);

Nodo* pop(Pila *pila);

Nodo* verCima(Pila *pila);

bool isVacia(Pila *pila);

void imprimir(Pila *pila);

void destruirPila(Pila *pila);