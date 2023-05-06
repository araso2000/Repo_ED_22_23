#pragma once

#define _CRT_SECURE_NO_WARNINGS

#include <stdbool.h>

#include "Aeropuerto.h"
#include "ListaContigua.h"
#include "ListaDobleEnlazada.h"

bool existeAeropuerto(ListaContigua *grafo, char *nombre);

ListaDobleEnlazada* getDestinos(ListaContigua *grafo, char *origen);

ListaDobleEnlazada* getOrigenes(ListaContigua *grafo, char *destino);

bool existeRuta(ListaContigua *grafo, char *origen, char *destino);

void imprimirGrafo(ListaContigua *grafo);

void insertarAeropuerto(ListaContigua *grafo, char *nombre);

void insertarRuta(ListaContigua *grafo, char *origen, char *destino, int distancia, char *empresa);

void eliminarRuta(ListaContigua *grafo, char *origen, char *destino);

void eliminarAeropuerto(ListaContigua *grafo, char *nombre);