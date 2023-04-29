#pragma once

#include <stdbool.h>
#include <stdio.h>

typedef struct{
    int matricula;
    char nombre[10];
    bool ocupado;
}Estudiante;

typedef struct{
    Estudiante *estudiantes;
    int capacidad;
    int n;
}HashSinColision;

HashSinColision* constructor(int capacidad);

int obtenerPosicionIdeal(HashSinColision *tabla, int matricula);

bool existe(HashSinColision *tabla, int matricula);

char* getEstudiante(HashSinColision *tabla, int matricula);

void insertar(HashSinColision *tabla, int matricula, char nombre[]);

void eliminar(HashSinColision *tabla, int matricula);

void imprimir(HashSinColision *tabla);

void destructor(HashSinColision *tabla);