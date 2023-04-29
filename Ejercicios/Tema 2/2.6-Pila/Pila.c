#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

#include "Pila.h"

Pila* constructor(){
    Pila *pila = (Pila*)malloc(sizeof(Pila));
    pila->primerNodo = NULL;
    pila->tamActual = 0;

    return(pila);
}

void push(Pila *pila, int elem){
    assert(pila != NULL);

    Nodo *nuevo = (Nodo*)malloc(sizeof(Nodo));
    nuevo->elemento = elem;

    nuevo->siguiente = pila->primerNodo;
    pila->primerNodo = nuevo;

    pila->tamActual = pila->tamActual + 1;
}

Nodo* pop(Pila *pila){
    assert(pila != NULL);
    assert(!isVacia(pila));

    Nodo *temp;
    temp = pila->primerNodo;

    pila->primerNodo = temp->siguiente;

    pila->tamActual = pila->tamActual - 1;

    return temp;
}

Nodo* verCima(Pila *pila){
    assert(pila != NULL);
    assert(!isVacia(pila));

    return(pila->primerNodo);
}

bool isVacia(Pila *pila){
    assert(pila != NULL);
    if(pila->tamActual == 0){
        return(true);
    }else{
        return(false);
    }
}

void imprimir(Pila *pila){
    assert(pila != NULL);
    assert(!isVacia(pila));
    printf("Tam Lista: %d -> ",pila->tamActual);
    
    if(pila->tamActual == 0){
        
        printf("Lista vacia");
   
    }else{
        Nodo *actual = pila->primerNodo;
        for(int ii=0 ; ii < pila->tamActual ; ii++){
            
            printf("%d",actual->elemento);

            actual = actual->siguiente;
            
            if(ii != pila->tamActual-1){
                printf(", ");
            }
        }
    }
    printf("\n");
}

void destruirPila(Pila *pila){
    assert(pila != NULL);
    assert(!isVacia(pila));

    Nodo *actual = pila->primerNodo;
    while(actual != NULL) {
        Nodo *siguiente = actual->siguiente;
        free(actual);
        actual = siguiente;
    }
    free(pila);
}