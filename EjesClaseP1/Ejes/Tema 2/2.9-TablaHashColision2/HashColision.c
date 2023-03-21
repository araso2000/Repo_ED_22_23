#include "HashColision.h"
#include "ListaDobleEnlazada.h"
#include "impresionListasEnlazadas.h"

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
    tabla->estudiantes = (ListaDobleEnlazada**)malloc(sizeof(ListaDobleEnlazada) * capacidad);

    for(int ii=0; ii<capacidad; ii++){
        tabla->estudiantes[ii] = constructorLista();
    }

    return(tabla);
}

int obtenerPosicionIdeal(HashColision *tabla, int matricula, int version){
    assert(tabla != NULL);
	assert(tabla->estudiantes != NULL && tabla->capacidad >= 1 && tabla->n >= 0 && tabla->n <= tabla->capacidad); 
	assert(matricula >= 0);
    assert(version == 0 || version == 1);

    int posiblePos = matricula % tabla->capacidad;

    if(version == 1){
        posiblePos += tabla->capacidad/2;
        posiblePos = matricula % tabla->capacidad;
    }

    return(posiblePos);
}

bool existe(HashColision *tabla, int matricula){
    assert(tabla != NULL);
	assert(tabla->estudiantes != NULL && tabla->capacidad >= 1 && tabla->n >= 0); 
	assert(matricula >= 0);

    if(obtenerPosicionReal(tabla, matricula).numLista == -1){
        return(false);
    }else{
        return(true);
    }
}

char* getEstudiante(HashColision *tabla, int matricula){
    assert(tabla != NULL);
	assert(tabla->estudiantes != NULL && tabla->capacidad >= 1 && tabla->n >= 0); 
	assert(matricula >= 0);
    assert(existe(tabla,matricula));

    return(getValor(tabla->estudiantes[obtenerPosicionReal(tabla,matricula).numLista],obtenerPosicionReal(tabla,matricula).posLista).nombre);
}

void insertar(HashColision *tabla, int matricula, char nombre[]){
    assert(tabla != NULL);
	assert(tabla->estudiantes != NULL && tabla->capacidad >= 1 && tabla->n >= 0 && tabla->n <= tabla->capacidad); 
	assert(matricula >= 0);
    assert(!existe(tabla,matricula));

    Estudiante datosEstudiante;
	datosEstudiante.matricula = matricula;
	strcpy(datosEstudiante.nombre, nombre);

	int posiblePos1 = obtenerPosicionIdeal(tabla, matricula, 0);
	int posiblePos2 = obtenerPosicionIdeal(tabla, matricula, 1);

    if(tabla->estudiantes[posiblePos1]->tamActual <= tabla->estudiantes[posiblePos2]->tamActual){
        insertarLista(tabla->estudiantes[posiblePos1],0,datosEstudiante);
    }else{
        insertarLista(tabla->estudiantes[posiblePos2],0,datosEstudiante);
    }
    tabla->n++;
}

void eliminar(HashColision *tabla, int matricula){
    assert(tabla != NULL);
	assert(tabla->estudiantes != NULL && tabla->capacidad >= 1 && tabla->n >= 0 && tabla->n <= tabla->capacidad); 
	assert(matricula >= 0);
    assert(existe(tabla,matricula));

    PosicionReal posiblePos = obtenerPosicionReal(tabla, matricula);
    
    eliminarLista(tabla->estudiantes[posiblePos.numLista], posiblePos.posLista);
}

void imprimir(HashColision *tabla){
    assert(tabla != NULL);
	assert(tabla->estudiantes != NULL && tabla->capacidad >= 1 && tabla->n >= 0 && tabla->n <= tabla->capacidad); 

    for(int ii=0;ii<tabla->capacidad;ii++){
        printf("Posicion %d: ", ii);
		imprimirLista(tabla->estudiantes[ii]);
    }
}

void destructor(HashColision *tabla){
    assert(tabla != NULL);
	assert(tabla->estudiantes != NULL && tabla->capacidad >= 1 && tabla->n >= 0 && tabla->n <= tabla->capacidad); 

    for(int ii=0; ii<tabla->capacidad; ii++){
        destructorLista(tabla->estudiantes[ii]);
    }
    
    free(tabla->estudiantes);
    free(tabla);
}

PosicionReal obtenerPosicionReal(HashColision *tabla, int matricula){
    assert(tabla != NULL);
	assert(tabla->estudiantes != NULL && tabla->capacidad >= 1 && tabla->n >= 0); 
	assert(matricula >= 0);

    PosicionReal posiblePos;
    posiblePos.numLista = -1;
    posiblePos.posLista = -1;

    Estudiante temp;
    temp.matricula = matricula;

    for(int version=0; version < 2; version++){
        int numLista = obtenerPosicionIdeal(tabla, matricula, version);
        int posLista= buscarLista(tabla->estudiantes[numLista], temp);
        if(posLista != -1){
            posiblePos.numLista = numLista;
            posiblePos.posLista = posLista;
            return(posiblePos);
        }
    }
    return(posiblePos);
}