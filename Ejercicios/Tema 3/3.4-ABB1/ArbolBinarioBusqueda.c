#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include <string.h>

#include "ArbolBinarioBusqueda.h"

//Métodos "privados"
ArbolBinarioBusqueda* constructor(){
    ArbolBinarioBusqueda *arbol = (ArbolBinarioBusqueda*)malloc(sizeof(ArbolBinarioBusqueda));
    arbol->n = 0;
    arbol->raiz = NULL;

    return(arbol);
}

Nodo* buscarRecursivo(Nodo *raiz, int elemento){
    assert(raiz != NULL);

    if(raiz->elemento == elemento){ //Si el elemento buscado es la raiz
        return(raiz);
    }else if(elemento < raiz->elemento){ //Si el elemento buscado es menor que la raiz
        if(raiz->hijoIzquierdo == NULL){ //Si no tiene hizo izquierdo (menor) devolvemos el padre
            return(raiz);
        }else{ //Si no seguimos buscando por el subarbol izquierdo
            return(buscarRecursivo(raiz->hijoIzquierdo, elemento));
        }
    }else{ //Si el elemento buscado es mayor que la raiz
        if(raiz->hijoDerecho == NULL){ //Si no tiene hizo derecho (mayor) devolvemos el padre
            return(raiz);
        }else{ //Si no seguimos buscando por el subarbol derecho
            return(buscarRecursivo(raiz->hijoDerecho, elemento));
        }
    }
}

void destructorRecursivo(ArbolBinarioBusqueda *arbol, Nodo *raiz){
    assert(arbol != NULL && arbol->n >= 0); // Árbol tiene sentido
	assert(raiz != NULL);

    if(raiz->hijoDerecho != NULL){ //Si existe el hijo derecho
        destructorRecursivo(arbol,raiz->hijoDerecho); //Recursivamente borramos el subarbol derecho
    }
    if(raiz->hijoIzquierdo != NULL){ //Si existe el hijo izquierdo
        destructorRecursivo(arbol,raiz->hijoIzquierdo); //Recursivamente borramos el subarbol izquierdo
    }

    Nodo *padre = raiz->padre;

    if(padre != NULL){ //Si la raiz tiene padre
        if(padre->hijoIzquierdo == raiz){ //Si la raiz es el hijo derecho de su padre, le quitamos la referencia
            padre->hijoIzquierdo = NULL;
        }
        if(padre->hijoDerecho == raiz){ //Si es el hijo izquierdo haremos lo mismo
            padre->hijoDerecho = NULL;
        }
    }else{ //Si no tiene padre pues borramos la raiz del arbol
        arbol->raiz = NULL;
    }

    free(raiz);
    arbol->n--;
}

void imprimirRecursivo(Nodo *raiz, int numTabulaciones, int orientacion){
    assert(raiz != NULL);
	assert(numTabulaciones >= 0);
	assert(orientacion == 1 || orientacion == -1 || orientacion == 0);

    for(int ii=0; ii<numTabulaciones; ii++){
        printf("\t");
    }
    printf("%d",raiz->elemento);

    if(orientacion == -1){
        printf("(izq)");
    }
    if(orientacion == 1){
        printf("(der)");
    }
    printf("\n");

    if (raiz->hijoIzquierdo != NULL){ //Si tiene hijo izquiedo
        imprimirRecursivo(raiz->hijoIzquierdo, numTabulaciones + 1, -1);
    }
	if (raiz->hijoDerecho != NULL){ //Si tiene hijo derecho
        imprimirRecursivo(raiz->hijoDerecho, numTabulaciones + 1, 1);
    }
}

//Métodos "públicos"
bool buscarElemento(ArbolBinarioBusqueda *arbol, int elemento){
    assert(arbol != NULL && arbol->n >= 0); // Árbol tiene sentido
    if(arbol->n == 0){ //Si el arbol está vacío obviamente no hay nada que buscar
        return(false);
    }else{
        Nodo *temporal = buscarRecursivo(arbol->raiz,elemento);
        if(temporal->elemento == elemento){
            return(true);
        }else{
            return(false);
        }
    }
}

void insertarElemento(ArbolBinarioBusqueda *arbol, int elemento){
    assert(arbol != NULL && arbol->n >= 0); // Árbol tiene sentido
	assert(!buscarElemento(arbol, elemento)); // El nuevo elemento no estaba ya en el árbol

    //Creamos el nodo
    Nodo *nuevoNodo = (Nodo*)malloc(sizeof(Nodo));
    nuevoNodo->elemento = elemento;
    nuevoNodo->padre = NULL;
    nuevoNodo->hijoDerecho = NULL;
    nuevoNodo->hijoIzquierdo = NULL;

    //Si arbol vacio será nuestra nueva raiz
    if(arbol->n == 0){
        arbol->raiz = nuevoNodo;
    }else{ //Si el arbol no está vacio
        Nodo *posiblePadre = buscarRecursivo(arbol->raiz,elemento);

        if(elemento < posiblePadre->elemento){ //Si es menor que su padre será su nuevo hijo izquierdo
            posiblePadre->hijoIzquierdo = nuevoNodo;
        }else{ //Si es mayor será entonces su hijo derecho
            posiblePadre->hijoDerecho = nuevoNodo;
        }

        nuevoNodo->padre = posiblePadre; //El nuevo nodo tendrá nuevo padre
    }

    arbol->n++;
}

void imprimir(ArbolBinarioBusqueda *arbol){
    assert(arbol != NULL && arbol->n >= 0); // Árbol tiene sentido

    if(arbol->n > 0){ //Si el arbol no está vacio
        imprimirRecursivo(arbol->raiz, 0, 0);
    }else{
        printf("Arbol vacio\n");
    }
}

void destructorArbol(ArbolBinarioBusqueda *arbol){
    assert(arbol != NULL && arbol->n >= 0); // Árbol tiene sentido
	if (arbol->n > 0){
        destructorRecursivo(arbol, arbol->raiz);
    }
	free(arbol);
}