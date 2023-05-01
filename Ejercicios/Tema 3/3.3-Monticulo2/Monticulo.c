#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include <string.h>

#include "ListaContigua.h"
#include "Monticulo.h"

void imprimirRecursivo(ListaContigua *arbol, int raiz, int numTabulaciones){
    assert(arbol != NULL && arbol->n >= 0 && arbol->capacidad >= arbol->n); // lista contigua coherente
    assert(raiz >= 1);
    assert(numTabulaciones >= 0);

    assert(arbol != NULL);
    assert(arbol->array != NULL && arbol->n > 0);

    if(raiz <= arbol->n){
        for(int ii=0; ii<numTabulaciones; ii++){
            printf("\t");
        }
        printf("%d\n", get(arbol, raiz - 1));
    }

    imprimirRecursivo(arbol, raiz * 2, numTabulaciones + 1);
	imprimirRecursivo(arbol, raiz * 2 + 1, numTabulaciones + 1);
}

void imprimirArbol(ListaContigua *arbol){
    assert(arbol != NULL && arbol->n >= 0 && arbol->capacidad >= arbol->n); // lista contigua coherente

    imprimirRecursivo(arbol,1,0);
}

bool esMonticulo(ListaContigua *arbol, int raiz){
    assert(arbol != NULL && arbol->n >= 0 && arbol->capacidad >= arbol->n); // lista contigua coherente
    assert(raiz >= 1);

    if(raiz > arbol->n){
        return(true); //Si el nodo raiz es más grande que la posicion máxima de la lista, el subarbol estará vacío, asi que sí será un monticulo
    }

    int padre = get(arbol,raiz - 1);

    //Hijo izquierdo
    if(raiz*2 <= arbol->n){ //Los izquierdos son como una sucesión par
        if(!esMonticulo(arbol,raiz*2)){ //Llamada recursiva con el hijo izquierdo. Si no es monticulo, el arbol NO es monticulo
            return(false);
        }
        if(padre > get(arbol, raiz * 2 - 1)){ //Si el hijo izquierdo es menor que el padre, NO es monticulo
            return(false);
        }
    }

    //Hijo derecho
    if (raiz * 2 + 1 <= arbol->n) {
		if (!esMonticulo(arbol, raiz * 2 + 1)){ //Los derechos son como una sucesión impar
             return(false);
        }
		if (padre > get(arbol, raiz * 2 + 1 - 1)){
            return(false);
        }
	}

	return (true);
}

void insertarMonticulo(ListaContigua *arbol, int clave){
    assert(arbol != NULL && arbol->n >= 0 && arbol->capacidad >= arbol->n); // lista contigua coherente

    insertarFinal(arbol, clave);    

	// Vamos intercambiando con su padre hasta que sea mayor que su padre o hasta que lleguemos a la raiz (posicion 1)
	int posicion = arbol->n;

	if(posicion > 1){
        while (posicion > 1 && get(arbol, posicion-1) < get(arbol, abs((posicion/2) - 1))) {
            int padre = get(arbol, posicion/2-1);
        
		    modificar(arbol, posicion/2-1, get(arbol, posicion-1));
		    modificar(arbol, posicion-1, padre);
		
		    posicion = posicion/2;
	    }
    }

	assert(esMonticulo(arbol, 1));
}

void reestructurar(ListaContigua *arbol){
    assert(arbol != NULL && arbol->n >= 0 && arbol->capacidad >= arbol->n); // lista contigua coherente
    assert(arbol->n >= 2);
    assert(esMonticulo(arbol,2));
    if(arbol->n >= 3){
        assert(esMonticulo(arbol,3));
    }

    bool esMonticulo = false;
    int posicionPadre = 1;

    while(!esMonticulo){
        int valorHijoMenor = 0; 
		int posicionHijoMenor = 0;

        int valorPadre = get(arbol, posicionPadre - 1);

        if(posicionPadre * 2 + 1 > arbol->n){ //Sacamos la posicion del hijo menor
            posicionHijoMenor = posicionPadre * 2; 
        }else{
            int valorHijoIzquierdo = arbol->array[posicionPadre * 2 - 1];
            int valorHijoDerecho = arbol->array[posicionPadre * 2 + 1 - 1];

            if(valorHijoIzquierdo < valorHijoDerecho){
                posicionHijoMenor = posicionPadre * 2;
            }else{
                posicionHijoMenor = posicionPadre * 2 + 1;
            }
        }

        if(valorPadre > valorHijoMenor){
            modificar(arbol, posicionPadre - 1, valorHijoMenor);
            modificar(arbol, posicionHijoMenor - 1, valorPadre);

            posicionPadre = posicionHijoMenor;

            if(posicionPadre * 2 > arbol->n){
                esMonticulo = true;
            }
        }else{
            esMonticulo = true;
        }
    }
}

void borrar(ListaContigua *arbol){
    assert(arbol != NULL && arbol->n >= 0 && arbol->capacidad >= arbol->n); // lista contigua coherente
    assert(arbol->n > 0); //Monticulo NO vacio

    modificar(arbol,0,arbol->array[arbol->n-1]);
    eliminarFinal(arbol);

    if(arbol->n >= 2){
        reestructurar(arbol);
    }
}

int getRaiz(ListaContigua *arbol){
    assert(arbol != NULL && arbol->n >= 0 && arbol->capacidad >= arbol->n); // lista contigua coherente
    assert(arbol->n > 0); //Monticulo NO vacio

    return(arbol->array[0]);
}

void ordenarPorMonticulo(ListaContigua *arbol){
    assert(arbol != NULL && arbol->n >= 0 && arbol->capacidad >= arbol->n); // lista contigua coherente

    ListaContigua *temporal = constructor();

    for(int ii=0; ii<arbol->n; ii++){
        insertarMonticulo(temporal,arbol->array[ii]);
    }

    for(int ii=0; ii<arbol->n; ii++){
        modificar(arbol,ii,getRaiz(temporal));
        borrar(temporal);
    }

    destructor(temporal);
}