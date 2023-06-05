#pragma once

#include <stdlib.h>

typedef struct Nodo{
    char nombre[20];
    struct Nodo *padre;
    struct Nodo *primerHijo;
    struct Nodo *hermanoDerecho;
}Nodo;

typedef struct ArbolGenealogico{
    Nodo *raiz;
    int tam;
}ArbolGenealogico;

//Métodos "privados"

int numHijosDirectos(Nodo *nodo);

Nodo* getHijoDirecto(Nodo *nodo, int num);

Nodo* buscarRecursivo(Nodo *nodo, char *nombre);

void imprimirRecursivo(Nodo *nodo, int numTabulaciones);

void eliminarRecursivo(Nodo *nodo);

//Método "públicos"

ArbolGenealogico* constructor(char *nombre);

void insertar(ArbolGenealogico *arbol, char *nombre, char *padre);

void imprimirArbol(ArbolGenealogico *arbol);

void eliminarArbol(ArbolGenealogico *arbol);