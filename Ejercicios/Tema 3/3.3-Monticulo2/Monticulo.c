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
        //Mientras no lleguemos a la raiz y el hijo sea menor que su padre
        while (posicion > 1 && get(arbol, posicion-1) < get(arbol, abs((posicion/2) - 1))) {
            //Obtenemos el padre
            int padre = get(arbol, posicion/2-1);

            //Modificamos el padre por el hijo
		    modificar(arbol, posicion/2-1, get(arbol, posicion-1));
            //Y el hijo por el padre
		    modificar(arbol, posicion-1, padre);

            //Subimos de nivel en el arbol
		    posicion = posicion/2;
	    }
    }

	assert(esMonticulo(arbol, 1));
}

//07.05.2023 - 20.16
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

        //Obtenemos el padre
        int valorPadre = get(arbol, posicionPadre - 1);

        //Si no tiene hijo derecho, ya que nos pasamos de la longitud máxima de la lista contigua
        if(posicionPadre * 2 + 1 > arbol->n){ //Sacamos la posicion del hijo izquierdo
            posicionHijoMenor = posicionPadre * 2; 
        }else{
            //Si si tiene hijo derecho
            //Obtenemos el hijo izquierdo y el hijo derecho
            int valorHijoIzquierdo = arbol->array[posicionPadre * 2 - 1];
            int valorHijoDerecho = arbol->array[posicionPadre * 2 + 1 - 1];

            //Si el izquierdo es menor que el derecho, como debe ser, su hijo menor será el hijo izquierdo
            if(valorHijoIzquierdo < valorHijoDerecho){
                posicionHijoMenor = posicionPadre * 2;
            }else{ //Si no su hijo menor será el derecho
                posicionHijoMenor = posicionPadre * 2 + 1;
            }
        }

        //Si el padre es mayor que el hijo, habrá que reestructurar
        if(valorPadre > valorHijoMenor){
            //Cambiamos el padre por el hijo menor
            modificar(arbol, posicionPadre - 1, valorHijoMenor);
            //Cambiamos el hijo por el padre
            modificar(arbol, posicionHijoMenor - 1, valorPadre);

            //Ahora el padre será el hijo
            posicionPadre = posicionHijoMenor;

            //Si el hijo izquierdo es mayor que la longitud del árbol, será un montículo
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

    //Ponemos a 0 el ultimo nodo del arbol o lista contigua y lo eliminamos
    modificar(arbol,0,arbol->array[arbol->n-1]);
    eliminarFinal(arbol);

    //Si es necesario reestructuramos
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

    //Creamos un monticulo adicional temporal, consume mas memoria pero simplifica el algoritmo
    ListaContigua *temporal = constructor();

    //Vamos introduciendo cada uno de los valores del arbol OFICIAL en el temporal
    for(int ii=0; ii<arbol->n; ii++){
        insertarMonticulo(temporal,arbol->array[ii]);
    }

    //Como el arbol temporal está perfectamente ordenado, y cada vez que se llama a borrar o insertar se reestructura
    //Vamos sacando la raiz de nuestro arbol temporal y la vamos añadiendo en orden a nuestro arbol OFICIAL
    //Y asi nos aseguramos que está ordenado
    for(int ii=0; ii<arbol->n; ii++){
        modificar(arbol,ii,getRaiz(temporal));
        borrar(temporal);
    }

    destructor(temporal);
}