#pragma once

#include <stdbool.h>
#include <stdio.h>
#include "ListaDobleEnlazada.h"

typedef struct{
    struct ListaDobleEnlazada** estudiantes;
    int capacidad;
    int n;
}HashColision;

typedef struct{
    int numLista;
    int posLista;
}PosicionReal;

HashColision* constructor(int capacidad);

int obtenerPosicionIdeal(HashColision *tabla, int matricula, int version);

bool existe(HashColision *tabla, int matricula);

char* getEstudiante(HashColision *tabla, int matricula);

void insertar(HashColision *tabla, int matricula, char nombre[]);

void eliminar(HashColision *tabla, int matricula);

void imprimir(HashColision *tabla);

void destructor(HashColision *tabla);

PosicionReal obtenerPosicionReal(HashColision *tabla, int matricula);