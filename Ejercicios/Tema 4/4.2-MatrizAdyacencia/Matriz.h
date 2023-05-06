#pragma once

#include <stdbool.h>
#include <assert.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>

#include "ListaContigua.h"

typedef struct Matriz{
    ListaContigua **matriz;
    int n;
    char *nombresNodos;
}Matriz;

int obtenerIndice(Matriz* grafo, char nombreNodo);

bool existeNodo(Matriz* grafo, char nombreNodo);

bool existeArco(Matriz *grafo, char nombreNodoOrigen, char nombreNodoDestino);

Matriz *construirMatriz();

void destruirMatriz(Matriz* grafo);

void insertarNodo(Matriz *grafo, char nombreNodo);

void insertarArco(Matriz *grafo, char nodoOrigen, char nodoDestino);

void borrarNodo(Matriz *grafo, char nombreNodo);

void borrarArco(Matriz *grafo, char nodoOrigen, char nodoDestino);

void imprimir(Matriz *grafo);