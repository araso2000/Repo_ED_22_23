#pragma once

#include <stdbool.h>
#include <stdio.h>

typedef struct{
    int matricula;
    char nombre[10];
    bool ocupado;
    bool borrado;
}Estudiante;

typedef struct{
    Estudiante *estudiantes;
    int capacidad;
    int n;
}HashColision;

HashColision* constructor(int capacidad);

int obtenerPosicionIdeal(HashColision *tabla, int matricula);

bool existe(HashColision *tabla, int matricula);

char* getEstudiante(HashColision *tabla, int matricula);

void insertar(HashColision *tabla, int matricula, char nombre[]);

void eliminar(HashColision *tabla, int matricula);

void imprimir(HashColision *tabla);

void destructor(HashColision *tabla);

int obtenerPosicionReal(HashColision *tabla, int matricula);