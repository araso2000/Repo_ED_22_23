#include "HashColision.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

HashColision* constructor(int capacidad){
    assert(capacidad >= 1);

    HashColision *tabla = (HashColision*)malloc(sizeof(HashColision));
    tabla->n = 0;
    tabla->capacidad = capacidad;
    tabla->estudiantes = (Estudiante*)malloc(sizeof(Estudiante) * capacidad);

    for(int ii=0; ii<capacidad; ii++){
        tabla->estudiantes[ii].ocupado = false;
        tabla->estudiantes[ii].borrado = false;
    }

    return(tabla);
}

int obtenerPosicionIdeal(HashColision *tabla, int matricula){
    assert(tabla != NULL);
	assert(tabla->estudiantes != NULL && tabla->capacidad >= 1 && tabla->n >= 0 && tabla->n <= tabla->capacidad); 
	assert(matricula >= 0);

    return(matricula % tabla->capacidad);
}

bool existe(HashColision *tabla, int matricula){
    assert(tabla != NULL);
	assert(tabla->estudiantes != NULL && tabla->capacidad >= 1 && tabla->n >= 0 && tabla->n <= tabla->capacidad); 
	assert(matricula >= 0);

    if(obtenerPosicionReal(tabla, matricula) == -1){
        return(false);
    }else{
        return(true);
    }
}

char* getEstudiante(HashColision *tabla, int matricula){
    assert(tabla != NULL);
	assert(tabla->estudiantes != NULL && tabla->capacidad >= 1 && tabla->n >= 0 && tabla->n <= tabla->capacidad); 
	assert(matricula >= 0);
    assert(existe(tabla,matricula));

    return(tabla->estudiantes[obtenerPosicionIdeal(tabla,matricula)].nombre);
}

void insertar(HashColision *tabla, int matricula, char nombre[]){
    assert(tabla != NULL);
	assert(tabla->estudiantes != NULL && tabla->capacidad >= 1 && tabla->n >= 0 && tabla->n <= tabla->capacidad); 
	assert(matricula >= 0);
    assert(tabla->n < tabla->capacidad);

    int posiblePos = obtenerPosicionIdeal(tabla, matricula);

    while(tabla->estudiantes[posiblePos].ocupado){
        posiblePos = (posiblePos + 1) % tabla->capacidad;
    }

    strcpy(tabla->estudiantes[posiblePos].nombre,nombre);
    tabla->estudiantes[posiblePos].matricula = matricula;
    tabla->estudiantes[posiblePos].ocupado = true;

    tabla->n++;
}

void eliminar(HashColision *tabla, int matricula){
    assert(tabla != NULL);
	assert(tabla->estudiantes != NULL && tabla->capacidad >= 1 && tabla->n >= 0 && tabla->n <= tabla->capacidad); 
	assert(matricula >= 0);
    assert(existe(tabla,matricula));

    int posiblePos = obtenerPosicionReal(tabla, matricula);
    
    tabla->estudiantes[posiblePos].ocupado = false;
    tabla->estudiantes[posiblePos].borrado = true;

    tabla->n--;
}

void imprimir(HashColision *tabla){
    assert(tabla != NULL);
	assert(tabla->estudiantes != NULL && tabla->capacidad >= 1 && tabla->n >= 0 && tabla->n <= tabla->capacidad); 

    for(int ii=0;ii<tabla->capacidad;ii++){
        Estudiante temp = tabla->estudiantes[ii];
        printf("Posicion: %d | Ocupado: %d | Borrado: %d | Clave: %d | Valor: %s\n", ii, temp.ocupado, temp.borrado, temp.matricula, temp.nombre);
    }
}

void destructor(HashColision *tabla){
    assert(tabla != NULL);
	assert(tabla->estudiantes != NULL && tabla->capacidad >= 1 && tabla->n >= 0 && tabla->n <= tabla->capacidad); 

    free(tabla->estudiantes);
    free(tabla);
}

int obtenerPosicionReal(HashColision *tabla, int matricula){
    assert(tabla != NULL);
	assert(tabla->estudiantes != NULL && tabla->capacidad >= 1 && tabla->n >= 0 && tabla->n <= tabla->capacidad); 
	assert(matricula >= 0);

    int posiblePos = obtenerPosicionIdeal(tabla,matricula);

    for(int ii=0; ii<tabla->capacidad; ii++){
        Estudiante temp = tabla->estudiantes[posiblePos];

        if(temp.ocupado && temp.matricula == matricula){
            return(posiblePos);
        }
        if(!temp.ocupado && !temp.borrado){
            return(-1);
        }
        posiblePos = (posiblePos + 1) % tabla->capacidad;
    }
    return(-1);
}