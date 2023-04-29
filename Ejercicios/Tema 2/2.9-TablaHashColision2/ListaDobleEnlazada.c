#include "ListaDobleEnlazada.h"
#include <stdlib.h>
#include <assert.h>
#include <stdio.h>

ListaDobleEnlazada* constructorLista(){
    ListaDobleEnlazada *lista = (ListaDobleEnlazada*)malloc(sizeof(ListaDobleEnlazada));
    lista->primerNodo = NULL;
    lista->tamActual = 0;
    lista->posLastNodo = -1;
    lista->lastNodo = NULL;

    return(lista);
}

Nodo* getNodo(ListaDobleEnlazada *lista, int posicion){
    assert(lista != NULL);
    assert(lista->tamActual > 0);
    assert(posicion >= 0);
    assert(posicion <= lista->tamActual - 1);

    Nodo *devolver = NULL;

    if(posicion == 0){
        devolver = lista->primerNodo;

    }else if(posicion == lista->posLastNodo - 1){
       devolver = lista->lastNodo->anterior; 

    }else if(posicion == lista->posLastNodo + 1){
        devolver = lista->lastNodo->siguiente; 

    }else if(posicion == lista->posLastNodo){
        devolver = lista->lastNodo;
    }else{
        if(posicion < (lista->tamActual - posicion)){
            devolver = lista->primerNodo;
            for(int ii=0;ii<posicion;ii++){
                devolver = devolver->siguiente;
            } 
        }else{
            devolver = lista->primerNodo->anterior;
             for(int ii=lista->tamActual - 1;ii>posicion;ii--){
                devolver = devolver->anterior;
            }   
        }
    }
    lista->lastNodo = devolver;
    lista->posLastNodo = posicion;

    return(devolver);
}

void setValor(ListaDobleEnlazada *lista, int posicion, Estudiante student){
    assert(lista != NULL);
    assert(lista->tamActual > 0);
    assert(posicion >= 0);
    assert(posicion <= lista->tamActual - 1);

    getNodo(lista,posicion)->elemento = student;
}

Estudiante getValor(ListaDobleEnlazada *lista, int posicion){
    assert(lista != NULL);
    assert(lista->tamActual > 0);
    assert(posicion >= 0);
    assert(posicion <= lista->tamActual - 1);

    Nodo *resultado = getNodo(lista, posicion);

    return(resultado->elemento);
}

void insertarLista(ListaDobleEnlazada *lista, int posicion, Estudiante student){
    assert(lista != NULL && lista->tamActual >= 0);
    assert(posicion <= lista->tamActual && posicion >= 0);
    
    Nodo *nuevo = (Nodo*)malloc(sizeof(Nodo));
    nuevo->elemento = student;

    if(lista->tamActual == 0){
            nuevo->siguiente = nuevo;
            nuevo->anterior = nuevo;
    }else{
        Nodo *nuevoSiguiente;
        if(posicion == lista->tamActual){ //Si es la ultima posicion de la lista
            nuevoSiguiente = lista->primerNodo;
        }else{
            nuevoSiguiente = getNodo(lista,posicion);
        }

        Nodo *nuevoAnterior = nuevoSiguiente->anterior;

        nuevo->anterior = nuevoAnterior;
        nuevo->siguiente = nuevoSiguiente;

        nuevoSiguiente->anterior = nuevo;
        nuevoAnterior->siguiente = nuevo;
    }
    
    if(posicion == 0){//Si lo insertamos al principio
        lista->primerNodo = nuevo;
    }

    lista->tamActual++;
    lista->lastNodo = NULL;
    lista->posLastNodo = -1;
}

void eliminarLista(ListaDobleEnlazada *lista, int posicion){
    assert(lista != NULL);
    assert(lista->tamActual > 0);
    assert(posicion >= 0);
    assert(posicion <= lista->tamActual - 1);

    Nodo *actual = getNodo(lista, posicion);

    if(lista->tamActual == 1){ //Si la lista solo tiene un solo elemento
        lista->primerNodo = NULL;
    }else{ //Si tiene más de uno
        Nodo *anterior = actual->anterior;
        Nodo *siguiente = actual->siguiente;

        anterior->siguiente = siguiente;
        siguiente->anterior = anterior;

        if(posicion == 0){
            lista->primerNodo = siguiente;
        }  
    }              

    lista->tamActual--;
    lista->lastNodo = NULL;
    lista->posLastNodo = -1;

    free(actual);
}

void destructorLista(ListaDobleEnlazada *lista){
    assert(lista != NULL && lista->tamActual >= 0);

    while(lista->tamActual > 0) {
        eliminarLista(lista,0);
    }
    free(lista);
}

void concatenar(ListaDobleEnlazada *lista1, ListaDobleEnlazada *lista2){
    assert(lista1 != NULL);
	assert(lista1->tamActual >= 0);
    assert(lista2 != NULL);
	assert(lista2->tamActual >= 0);

    for(int ii = 0 ; ii < lista2->tamActual ; ii++){
        insertarLista(lista1,lista1->tamActual,getValor(lista2,ii));
    }
}

int buscarLista(ListaDobleEnlazada *lista, Estudiante student){
    assert(lista != NULL);
	assert(lista->tamActual >= 0);

    int posicion = -1;

    for(int ii = 0 ; ii < lista->tamActual ; ii++){
        if(getValor(lista,ii).matricula == student.matricula){
            posicion = ii;
            break;
        }
    }

    return(posicion);
}