#include "ListaDobleEnlazada.h"
#include "Aeropuerto.h"

#include <stdlib.h>
#include <assert.h>
#include <stdio.h>
#include <string.h>

ListaDobleEnlazada* constructorEnlazadas(){
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

void setValor(ListaDobleEnlazada *lista, int posicion, Ruta nuevoNum){
    assert(lista != NULL);
    assert(lista->tamActual > 0);
    assert(posicion >= 0);
    assert(posicion <= lista->tamActual - 1);

    getNodo(lista,posicion)->elemento = nuevoNum;
}

Ruta getValor(ListaDobleEnlazada *lista, int posicion){
    assert(lista != NULL);
    assert(lista->tamActual > 0);
    assert(posicion >= 0);
    assert(posicion <= lista->tamActual - 1);

    Nodo *resultado = getNodo(lista, posicion);

    return(resultado->elemento);
}

void insertarEnlazada(ListaDobleEnlazada *lista, int posicion, Ruta numero){
    assert(lista != NULL && lista->tamActual >= 0);
    assert(posicion <= lista->tamActual && posicion >= 0);
    
    Nodo *nuevo = (Nodo*)malloc(sizeof(Nodo));
    nuevo->elemento = numero;

    if(lista->tamActual == 0){ //Si la lista está vacia
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

void eliminarEnlazada(ListaDobleEnlazada *lista, int posicion){
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

        if(posicion == 0){ //Si borramos la cabeza de la lista
            lista->primerNodo = siguiente;
        }  
    }              

    lista->tamActual--;
    lista->lastNodo = NULL;
    lista->posLastNodo = -1;

    free(actual);
}

void destructorEnlazada(ListaDobleEnlazada *lista){
    assert(lista != NULL && lista->tamActual >= 0);

    while(lista->tamActual > 0) {
        eliminarEnlazada(lista,0);
    }
    free(lista);
}

void concatenarEnlazada(ListaDobleEnlazada *lista1, ListaDobleEnlazada *lista2){
    assert(lista1 != NULL);
	assert(lista1->tamActual >= 0);
    assert(lista2 != NULL);
	assert(lista2->tamActual >= 0);

    for(int ii = 0 ; ii < lista2->tamActual ; ii++){
        insertarEnlazada(lista1,lista1->tamActual,getValor(lista2,ii));
    }
}

int buscar(ListaDobleEnlazada *lista, Ruta elemento){
    assert(lista != NULL);
	assert(lista->tamActual >= 0);

    int posicion = -1;

    for(int ii = 0 ; ii < lista->tamActual ; ii++){
        if(strcmp(getValor(lista,ii).aeropuerto, elemento.aeropuerto) == 0){
            posicion = ii;
            break;
        }
    }

    return(posicion);
}