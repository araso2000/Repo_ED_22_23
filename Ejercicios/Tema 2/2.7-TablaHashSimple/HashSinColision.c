#include "HashSinColision.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

HashSinColision* constructor(int capacidad){
    assert(capacidad >= 1);

    HashSinColision *tabla = (HashSinColision*)malloc(sizeof(HashSinColision));
    tabla->n = 0;
    tabla->capacidad = capacidad;
    tabla->estudiantes = (Estudiante*)malloc(sizeof(Estudiante) * capacidad);

    for(int ii=0; ii<capacidad; ii++){
        tabla->estudiantes[ii].ocupado = false;
    }

    return(tabla);
}

int obtenerPosicionIdeal(HashSinColision *tabla, int matricula){
    assert(tabla != NULL);
	assert(tabla->estudiantes != NULL && tabla->capacidad >= 1 && tabla->n >= 0 && tabla->n <= tabla->capacidad); 
	assert(matricula >= 0);

    return(matricula % tabla->capacidad);
}

bool existe(HashSinColision *tabla, int matricula){
    assert(tabla != NULL);
	assert(tabla->estudiantes != NULL && tabla->capacidad >= 1 && tabla->n >= 0 && tabla->n <= tabla->capacidad); 
	assert(matricula >= 0);

    int posiblePos = obtenerPosicionIdeal(tabla, matricula);

    if(tabla->estudiantes[posiblePos].ocupado && tabla->estudiantes[posiblePos].matricula == matricula){
        return(true);
    }else{
        return(false);
    }
}

char* getEstudiante(HashSinColision *tabla, int matricula){
    assert(tabla != NULL);
	assert(tabla->estudiantes != NULL && tabla->capacidad >= 1 && tabla->n >= 0 && tabla->n <= tabla->capacidad); 
	assert(matricula >= 0);
    assert(existe(tabla,matricula));

    return(tabla->estudiantes[obtenerPosicionIdeal(tabla,matricula)].nombre);
}

void insertar(HashSinColision *tabla, int matricula, char nombre[]){
    assert(tabla != NULL);
	assert(tabla->estudiantes != NULL && tabla->capacidad >= 1 && tabla->n >= 0 && tabla->n <= tabla->capacidad); 
	assert(matricula >= 0);
    assert(tabla->n < tabla->capacidad);

    int posiblePos = obtenerPosicionIdeal(tabla, matricula);

    assert(!tabla->estudiantes[posiblePos].ocupado);

    strcpy(tabla->estudiantes[posiblePos].nombre,nombre);
    tabla->estudiantes[posiblePos].matricula = matricula;
    tabla->estudiantes[posiblePos].ocupado = true;

    tabla->n++;
}

void eliminar(HashSinColision *tabla, int matricula){
    assert(tabla != NULL);
	assert(tabla->estudiantes != NULL && tabla->capacidad >= 1 && tabla->n >= 0 && tabla->n <= tabla->capacidad); 
	assert(matricula >= 0);
    assert(existe(tabla,matricula));

    int posiblePos = obtenerPosicionIdeal(tabla, matricula);
    tabla->estudiantes[posiblePos].ocupado = false;

    tabla->n--;
}

void imprimir(HashSinColision *tabla){
    assert(tabla != NULL);
	assert(tabla->estudiantes != NULL && tabla->capacidad >= 1 && tabla->n >= 0 && tabla->n <= tabla->capacidad); 

    for(int ii=0;ii<tabla->capacidad;ii++){
        Estudiante temp = tabla->estudiantes[ii];
        printf("Posicion: %d | Ocupado: %d | Clave: %d | Valor: %s\n", ii, temp.ocupado, temp.matricula, temp.nombre);
    }
}

void destructor(HashSinColision *tabla){
    assert(tabla != NULL);
	assert(tabla->estudiantes != NULL && tabla->capacidad >= 1 && tabla->n >= 0 && tabla->n <= tabla->capacidad); 

    free(tabla->estudiantes);
    free(tabla);
}