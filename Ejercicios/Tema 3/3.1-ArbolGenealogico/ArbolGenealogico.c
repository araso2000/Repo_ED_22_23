#include <stdlib.h>
#include <assert.h>
#include <stdio.h>
#include <string.h>

#include "ArbolGenealogico.h"

//Métodos "privados"

int numHijosDirectos(Nodo *nodo){
    assert(nodo != NULL);

    Nodo *temp = nodo->primerHijo;;
    int contador = 0;

    while(temp != NULL){
        contador++;
        temp = temp->hermanoDerecho;
    }

    return(contador);
}

Nodo* getHijoDirecto(Nodo *nodo, int num){
    int numeroHijos = numHijosDirectos(nodo);
    assert(nodo != NULL);
    assert(num >= 0);
    assert(numeroHijos > 0);

    Nodo *temp = nodo->primerHijo;;

    for(int ii=0; ii<num; ii++){
        temp = temp->hermanoDerecho;
    }

    return(temp);
}

Nodo* buscarRecursivo(Nodo *nodo, char *nombre){
    assert(nombre != NULL);

    if(nodo == NULL || strcmp(nodo->nombre,nombre) == 0){
        return(nodo);
    }

    Nodo *temp;
    temp = buscarRecursivo(nodo->primerHijo, nombre);

    if(temp != NULL){
        return(temp);
    }

    Nodo *hermano = nodo->hermanoDerecho;
    while(hermano != NULL){
        temp = buscarRecursivo(hermano,nombre);

        if(temp != NULL){
            return(temp);
        }

        hermano = hermano->hermanoDerecho;
    }

    return NULL;
}

void imprimirRecursivo(Nodo *nodo, int numTabulaciones){
    assert(nodo != NULL);
    assert(numTabulaciones >= 0);

    for (int ii=0; ii<numTabulaciones; ii++){
        printf("\t");
    }

	printf("%s\n", nodo->nombre);

    for(int ii=0; ii<numHijosDirectos(nodo); ii++){
        imprimirRecursivo((getHijoDirecto(nodo, ii)), numTabulaciones+1);
    }
}

void eliminarRecursivo(Nodo *nodo){
    assert(nodo != NULL);

    Nodo *temp;

    for(int ii=0; ii<numHijosDirectos(nodo)-1; ii++){
        temp = getHijoDirecto(nodo,ii);

        if(ii == 0){
            temp->padre->primerHijo = NULL;
        }else{
            getHijoDirecto(nodo, ii - 1)->hermanoDerecho = NULL;
        } 

        eliminarRecursivo(temp);
    }

    free(nodo);
}

//Método "públicos"

ArbolGenealogico* constructor(char *nombre){
    ArbolGenealogico *arbol = (ArbolGenealogico*)malloc(sizeof(ArbolGenealogico));
    arbol->tam = 1;

    Nodo *raiz = (Nodo*)malloc(sizeof(Nodo));
    strcpy(raiz->nombre,nombre);
    raiz->padre = NULL;
    raiz->primerHijo = NULL;
    raiz->hermanoDerecho = NULL;

    arbol->raiz = raiz;

    return(arbol);
}

void insertar(ArbolGenealogico *arbol, char *nombre, char *padre){
    assert(padre != NULL);
    Nodo *nodoPadre = buscarRecursivo(arbol->raiz,padre);
    assert(nodoPadre != NULL);
    assert(nombre != NULL);
    
    Nodo *nuevo = (Nodo*)malloc(sizeof(Nodo));
    strcpy(nuevo->nombre,nombre);
    nuevo->padre = nodoPadre;
    nuevo->hermanoDerecho = NULL;
    nuevo->primerHijo = NULL;

    int numHijos = numHijosDirectos(nodoPadre);

    if(numHijos == 0){
        nodoPadre->primerHijo = nuevo;
    }else{
        getHijoDirecto(nodoPadre,numHijos-1)->hermanoDerecho = nuevo;
    }
}

void imprimirArbol(ArbolGenealogico *arbol){
    assert(arbol != NULL && arbol->tam >= 0);
	assert(arbol->tam > 0 && arbol->raiz != NULL);
    imprimirRecursivo(arbol->raiz,0);
}

void eliminarArbol(ArbolGenealogico *arbol){
    assert(arbol != NULL && arbol->tam >= 0);
	assert(arbol->tam > 0 && arbol->raiz != NULL);
	eliminarRecursivo(arbol->raiz);
}