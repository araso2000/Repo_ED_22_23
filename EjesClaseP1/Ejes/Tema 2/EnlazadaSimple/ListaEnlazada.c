#include "ListaEnlazada.h"
#include <stdlib.h>
#include <assert.h>

Nodo* getNodo(ListaEnlazada *lista, int posicion){
    assert(lista != NULL);
    assert(posicion <= lista->tamActual);

    if(posicion == 0){
        return(lista->primerNodo);
    }else{
        Nodo *siguiente = lista->primerNodo;

        for(int ii=0;ii<posicion-1;ii++){
            siguiente = siguiente->siguiente;
        }        

        return(siguiente);
    }
}

ListaEnlazada* constructor(){
    Nodo *primero;
    primero->elemento = 0;
    primero->siguiente = NULL;

    ListaEnlazada *lista;
    lista->primerNodo = primero;
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

    Nodo *nuevo;
    nuevo->elemento = numero;

    Nodo *anteriorActual = getNodo(lista, posicion-1);
    Nodo *actual = anteriorActual->siguiente;

    lista->tamActual++;

    anteriorActual->siguiente = nuevo;
    nuevo->siguiente = actual;
}

void eliminar(ListaEnlazada *lista, int posicion){
    assert(lista != NULL);
    assert(posicion <= lista->tamActual);

    Nodo *anteriorActual = getNodo(lista, posicion-1);
    Nodo *actual = anteriorActual->siguiente;

    anteriorActual->siguiente=actual->siguiente;

    lista->tamActual--;

    free(actual);
}

void destructor(ListaEnlazada *lista){
    assert(lista != NULL);

    for(int ii=0;ii<lista->tamActual-1;ii++){
        free(lista->primerNodo->siguiente);
    }
    free(lista->primerNodo);
    free(lista);
}