#include "ListaEnlazada.h"
#include <stdlib.h>
#include <assert.h>
#include <stdio.h>

Nodo* getNodo(ListaEnlazada *lista, int posicion){
    assert(lista != NULL);
    assert(posicion >= 0 && posicion <= lista->tamActual);

    if(posicion == 0){
        return(lista->primerNodo);
    }else{
        Nodo *actual = lista->primerNodo;

        for(int ii=0;ii<posicion;ii++){
            actual = actual->siguiente;
        }        

        return(actual);
    }
}

ListaEnlazada* constructor(){
    ListaEnlazada *lista = (ListaEnlazada*)malloc(sizeof(ListaEnlazada));
    lista->primerNodo = NULL;
    lista->tamActual = 0;

    return(lista);
}

void setValor(Nodo *nodo, int numero){
    assert(nodo != NULL);

    nodo->elemento = numero;
}

int getValor(Nodo *nodo){
    assert(nodo != NULL);

    return(nodo->elemento);
}

void insertar(ListaEnlazada *lista, int posicion, int numero){
    assert(lista != NULL);
    assert(posicion <= lista->tamActual);
    
    Nodo *nuevo = (Nodo*)malloc(sizeof(Nodo));
    nuevo->elemento = numero;

    if(posicion == 0){
        nuevo->siguiente = lista->primerNodo;
        lista->primerNodo = nuevo;
    }else{
        Nodo *anterior = getNodo(lista, posicion-1);
        nuevo->siguiente = anterior->siguiente;   
        anterior->siguiente = nuevo;
    }
    lista->tamActual++;
}

void eliminar(ListaEnlazada *lista, int posicion){
    assert(lista != NULL);
    assert(posicion <= lista->tamActual);

    Nodo *actual = getNodo(lista, posicion);

    if(posicion == 0){
        lista->primerNodo = actual->siguiente;
    }else{
        Nodo *anteriorActual = getNodo(lista, posicion-1);

        anteriorActual->siguiente=actual->siguiente;
    }
    
    lista->tamActual--;

    free(actual);
}

void destructor(ListaEnlazada *lista){
    assert(lista != NULL);

    Nodo *actual = lista->primerNodo;
    while(actual != NULL) {
        Nodo *siguiente = actual->siguiente;
        free(actual);
        actual = siguiente;
    }
    free(lista);
}