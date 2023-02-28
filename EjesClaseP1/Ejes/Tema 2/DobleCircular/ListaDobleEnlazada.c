#include "ListaDobleEnlazada.h"
#include <stdlib.h>
#include <assert.h>
#include <stdio.h>

ListaDobleEnlazada* constructor(){
    ListaDobleEnlazada *lista = (ListaDobleEnlazada*)malloc(sizeof(ListaDobleEnlazada));
    lista->primerNodo = NULL;
    lista->tamActual = 0;
    lista->posLastNodo = -1;
    lista->lastNodo = NULL;

    return(lista);
}

Nodo* getNodo(ListaDobleEnlazada *lista, int posicion){
    assert(lista != NULL);
    assert(posicion >= 0 && posicion <= lista->tamActual);

    Nodo *devolver;

    if(posicion == 0){
        devolver = lista->primerNodo;

    }else if(posicion == lista->posLastNodo - 1){
       devolver = lista->lastNodo->anterior; 

    }else if(posicion == lista->posLastNodo + 1){
        devolver = lista->lastNodo->siguiente; 

    }else{

        Nodo *actual = lista->primerNodo;
        
        if(posicion < (lista->tamActual - posicion)){
            for(int ii=0;ii<posicion;ii++){
                actual = actual->siguiente;
            } 
        }else{
             for(int ii=0;ii<(lista->tamActual - posicion);ii++){
                actual = actual->anterior;
            }   
        }
        
        devolver = actual;
    }
    lista->lastNodo = devolver;
    lista->posLastNodo = posicion;

    return(devolver);
}

void setValor(Nodo *nodo, int numero){
    assert(nodo != NULL);

    nodo->elemento = numero;
}

int getValor(Nodo *nodo){
    assert(nodo != NULL);

    return(nodo->elemento);
}

void insertar(ListaDobleEnlazada *lista, int posicion, int numero){
    assert(lista != NULL && lista->tamActual >= 0);
    assert(posicion <= lista->tamActual && posicion >= 0);
    
    Nodo *nuevo = (Nodo*)malloc(sizeof(Nodo));
    nuevo->elemento = numero;

    if(lista->tamActual == 0){
            nuevo->siguiente = nuevo;
            nuevo->anterior = nuevo;
    }else{
         if(posicion == 0){ //Si es al principio
            nuevo->siguiente = lista->primerNodo;
            nuevo->anterior = lista->primerNodo->anterior;
            lista->primerNodo->anterior->siguiente = nuevo;
            lista->primerNodo->anterior = nuevo;
    
            lista->primerNodo = nuevo;

        }else if(posicion == lista->tamActual){ //Si es al final
            Nodo *ultimo = getNodo(lista,posicion);

            ultimo->siguiente = nuevo;
            nuevo->anterior = ultimo;
            nuevo->siguiente = lista->primerNodo;
            lista->primerNodo->anterior = nuevo;

        }else{ //Si es en medio
            Nodo *actual = getNodo(lista,posicion);

            actual->anterior->siguiente = nuevo;
            nuevo->anterior = actual->anterior;
            actual->anterior = nuevo;
            nuevo->siguiente = actual;
        }
    }
    lista->tamActual++;
    lista->lastNodo = nuevo;
    lista->posLastNodo = posicion;
}

void eliminar(ListaDobleEnlazada *lista, int posicion){
    assert(lista != NULL);
    assert(posicion <= lista->tamActual);
    assert(lista->tamActual > 0);

    Nodo *actual = getNodo(lista, posicion);

    if(lista->tamActual == 1){ //Si la lista solo tiene un solo elemento
        lista->primerNodo = NULL;
    }else{ //Si tiene más de uno
        if(posicion == 0){ //Si es el primer nodo
            Nodo *anterior = lista->primerNodo->anterior;
            Nodo *siguiente = lista->primerNodo->siguiente;

            anterior->siguiente = siguiente;
            siguiente->anterior=anterior;

            lista->primerNodo = siguiente;
        
        }else if(posicion == lista->tamActual){ //Si es el ultimo nodo
            lista->primerNodo->anterior = actual->anterior;
            actual->anterior->siguiente = lista->primerNodo;

        }else{ //Si es un nodo del medio
            Nodo *anterior = actual->anterior;
            Nodo *siguiente = actual->siguiente;

            anterior->siguiente = siguiente;
            siguiente->anterior = anterior;
        }
    }
    lista->tamActual--;
    lista->lastNodo = NULL;
    lista->posLastNodo = -1;

    free(actual);
}

void destructor(ListaDobleEnlazada *lista){
    assert(lista != NULL);

    Nodo *actual = lista->primerNodo;
    while(actual != NULL) {
        Nodo *siguiente = actual->siguiente;
        free(actual);
        actual = siguiente;
    }
    free(lista);
}

void concatenar(ListaDobleEnlazada *lista1, ListaDobleEnlazada *lista2){
    assert(lista1 != NULL);
	assert(lista1->tamActual >= 0);
    assert(lista2 != NULL);
	assert(lista2->tamActual >= 0);

    for(int ii = 0 ; ii < lista2->tamActual ; ii++){
        insertar(lista1,lista1->tamActual,getValor(getNodo(lista2,ii)));
    }
}

int buscar(ListaDobleEnlazada *lista, int elemento){
    assert(lista != NULL);
	assert(lista->tamActual >= 0);

    int posicion = -1;

    for(int ii = 0 ; ii < lista->tamActual ; ii++){
        if(getValor(getNodo(lista,ii)) == elemento){
            posicion = ii;
            break;
        }
    }

    return(posicion);
}