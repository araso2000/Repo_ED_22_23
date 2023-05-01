#pragma once

#include <stdbool.h>

typedef struct Nodo{
    int elemento;
    struct Nodo *padre;
    struct Nodo *hijoIzquierdo;
    struct Nodo *hijoDerecho;
}Nodo;

typedef struct ArbolBinarioBusqueda{
    Nodo *raiz;
    int n;
    int orientacion;
}ArbolBinarioBusqueda;

//Métodos "públicos"
ArbolBinarioBusqueda* constructor();

Nodo* buscarRecursivo(Nodo *raiz, int elemento);

void destructorRecursivo(ArbolBinarioBusqueda *arbol, Nodo *raiz);

void imprimirRecursivo(Nodo *raiz, int numTabulaciones, int orientacion);

//Métodos "privados"
bool buscarElemento(ArbolBinarioBusqueda *arbol, int elemento);

void insertarElemento(ArbolBinarioBusqueda *arbol, int elemento);

void imprimir(ArbolBinarioBusqueda *arbol);

void destructorArbol(ArbolBinarioBusqueda *arbol);

//ABB_2
Nodo* maximo(Nodo *raiz);

Nodo* minimo(Nodo *raiz);

void eliminarRecursivo(ArbolBinarioBusqueda *arbol, Nodo *nodo);

void eliminarElemento(ArbolBinarioBusqueda *arbol, int elemento);