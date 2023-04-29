#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include <string.h>

#include "ListaContigua.h"
#include "Monticulo.h"

void imprimirRecursivo(ListaContigua *arbol, int raiz, int numTabulaciones){
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
    imprimirRecursivo(arbol,1,0);
}

bool esMonticulo(ListaContigua *arbol, int raiz){
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

void insertarMonticulo(ListaContigua *lista, int clave){
    insertarFinal(lista, clave);    

	// Vamos intercambiando con su padre hasta que sea mayor que su padre o hasta que lleguemos a la raiz (posicion 1)
	int posicion = lista->n;

	if(posicion > 1){
        while (posicion > 1 && get(lista, posicion-1) < get(lista, abs((posicion/2) - 1))) {
            int padre = get(lista, posicion/2-1);
        
		    modificar(lista, posicion/2-1, get(lista, posicion-1));
		    modificar(lista, posicion-1, padre);
		
		    posicion = posicion/2;
	    }
    }

	assert(esMonticulo(lista, 1));
}