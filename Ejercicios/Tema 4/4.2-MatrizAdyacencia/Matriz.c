#include "Matriz.h"
#include "ListaContigua.h"

#include <stdbool.h>
#include <assert.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>

int obtenerIndice(Matriz* grafo, char nombreNodo){
    assert(grafo != NULL && grafo->n >= 0); // El grafo tiene sentido

    //Si el grafo está vacio no hay nada que buscar
    if(grafo->n == 0){
        return -1;
    }
    //Si el caracter nombreNodo no está en la cadena de nombres del grafo
    if(strchr(grafo->nombresNodos, nombreNodo) == NULL){
        return -1;
    }else{ //Si si que está
        return(strchr(grafo->nombresNodos, nombreNodo) - grafo->nombresNodos);
    }
}

bool existeNodo(Matriz* grafo, char nombreNodo){
    assert(grafo != NULL && grafo->n >= 0); // El grafo tiene sentido

    if(obtenerIndice(grafo, nombreNodo) == -1){
        return false;
    }else{
        return true;
    }
}

bool existeArco (Matriz *grafo, char nombreNodoOrigen, char nombreNodoDestino){
    assert(grafo != NULL && grafo->n >= 0); // El grafo tiene sentido
	assert(existeNodo(grafo, nombreNodoOrigen));
	assert(existeNodo(grafo, nombreNodoDestino));

    //Obtenemos variables para procesarlas despues
    int indiceNodoOrigen = obtenerIndice(grafo, nombreNodoOrigen);
    int indiceNodoDestino = obtenerIndice(grafo, nombreNodoDestino);
    ListaContigua *filaMatriz = grafo->matriz[indiceNodoOrigen];

    //Una vez que tenemos la fila de la matriz que corresponde con nuestro nodo y sus posibles arcos
    if(get(indiceNodoDestino, filaMatriz) > 0){
        //Si el valor en la lista contigua de esa fila es mayor que 0 es que hay un arco con peso
        return true;
    }else{
        return false;
    }
}

Matriz *construirMatriz(){
    Matriz *grafo = (Matriz*)malloc(sizeof(Matriz));
    grafo->matriz = NULL;
    grafo->n = 0;
    grafo->nombresNodos = (char*)malloc(sizeof(char));
    grafo->nombresNodos[0] = '\0';

    return grafo;
}

void destruirMatriz(Matriz* grafo){
    assert(grafo != NULL && grafo->n >= 0); // El grafo tiene sentido

    //Como es una matriz, vamos iterando por cada una de las sublistas y llamando al destructor de listas contiguas
    for(int ii=0; ii<grafo->n; ii++){
        destructor(grafo->matriz[ii]);
    }

    free(grafo->matriz);
    free(grafo->nombresNodos);
    free(grafo);
}

void insertarNodo(Matriz *grafo, char nombreNodo){
    assert (grafo != NULL && grafo->n >= 0); // El grafo tiene sentido
	assert (!existeNodo(grafo, nombreNodo));

    //Insertamos primero el nombre (osea la letra del nodo) en la lista de nombres de nodo
    char nuevoNombre[2];
    nuevoNombre[0] = nombreNodo;
    nuevoNombre[1] = '\0';

    //Lo insertamos en el grafo pero antes deberemos realocar espacio para poder almacenarlo
    //Osea conseguimos 2 espacios nuevos, los justos para que entre nuevoNombre
    grafo->nombresNodos = (char*)realloc(grafo->nombresNodos, sizeof(char) * (grafo->n + 2));
    //Concatenamos el nuevoNombre en nombresNodos
    strcat(grafo->nombresNodos, nuevoNombre);

    //Modificaciones de la matriz
    //Añadimos una columna nueva a cada una de las filas (porque nuestro estándar es [fila][columna])
    for(int ii=0; ii<grafo->n; ii++){
        insertarFinal(0,grafo->matriz[ii]);
    }

    grafo->n++;

    //Creamos una nueva fila con el nuevo numero de columnas
    ListaContigua *nuevaFila = constructor();
    //La llenamos de ceros
    for(int ii=0; ii<grafo->n; ii++){
        insertarFinal(0, nuevaFila);
    }

    //Necesitamos ahora hacer crecer a nuestra matriz para acomodar la nueva fila
    grafo->matriz = (ListaContigua*)realloc(grafo->matriz, (grafo->n) * sizeof(ListaContigua));
    //Añadimos la nueva fila
    grafo->matriz[grafo->n-1] = nuevaFila;
}

void insertarArco(Matriz *grafo, char nodoOrigen, char nodoDestino){
    assert(grafo != NULL && grafo->n >= 0); // El grafo tiene sentido
	assert(existeNodo(grafo, nodoOrigen));
	assert(existeNodo(grafo, nodoDestino));
	assert(!existeArco(grafo, nodoOrigen, nodoDestino));

    //Variables cómodas
    int posicionNodoOrigen = obtenerIndice(grafo, nodoOrigen);
	int posicionNodoDestino = obtenerIndice(grafo, nodoDestino);
    //Elegimos la fila correcta
	ListaContigua* fila = grafo->matriz[posicionNodoOrigen];
    //Marcamos como TRUE la columna de esa fila que corresponde con el nodo adyacente
	modificar(fila, posicionNodoDestino, 1);
}

void borrarNodo(Matriz *grafo, char nombreNodo){
    assert(grafo != NULL && grafo->n >= 0); // El grafo tiene sentido
	assert(existeNodo(grafo, nombreNodo));

    int posicionNodo = obtenerIndice(grafo, nombreNodo); // Indice del nodo
    //Enpequeñecemos memoria
    memmove(&grafo->matriz[posicionNodo], grafo->matriz[posicionNodo+1],sizeof(ListaContigua*) * (grafo->n - posicionNodo - 1));

    //Ahora tenemos que borrar la fila que representa ese nodo
    //Primero borramos la fila
    destructor(grafo->matriz[posicionNodo]);
    //Movemos la memoria, eliminando la ultima fila
	memmove(&grafo->matriz[posicionNodo], &grafo->matriz[posicionNodo + 1], sizeof(ListaContigua*) * (grafo->n - posicionNodo - 1));
    //Reasignamos el espacio de la matriz
    grafo->matriz = (ListaContigua*)realloc(grafo->matriz, sizeof(ListaContigua) * grafo->n);

    //Vamos eliminando ahora la columna que corresponde con ese nodo del resto de filas
    for(int ii=0; ii<grafo->n; ii++){
        eliminar(posicionNodo, grafo->matriz[ii]);
    }

    grafo->n--;
}

void borrarArco(Matriz *grafo, char nodoOrigen, char nodoDestino){
    assert(grafo != NULL && grafo->n >= 0); // El grafo tiene sentido
	assert(existeNodo(grafo, nodoOrigen));
	assert(existeNodo(grafo, nodoDestino));
	assert(existeArco(grafo, nodoOrigen, nodoDestino));

    //Borrar un arco es tan sencillo como marcar a 0 las coordenadas correctas de la matriz
    //Variables cómodas
    int posicionNodoOrigen = obtenerIndice(grafo, nodoOrigen);
	int posicionNodoDestino = obtenerIndice(grafo, nodoDestino);
    //Elegimos la fila correcta
	ListaContigua* fila = grafo->matriz[posicionNodoOrigen];
    //Marcamos como FALSE la columna de esa fila que corresponde con el nodo adyacente
	modificar(fila, posicionNodoDestino, 0);
}

void imprimir(Matriz *grafo){
    assert(grafo != NULL && grafo->n >= 0); // El grafo tiene sentido

	// Si el grafo está vacio, imprimimos mensaje informativo
	if (grafo->n == 0) printf("La matriz esta vacia\n");

	// En caso contrario, imprimimos la matriz de adyacencia bien alineada
	else {

		// Imprimimos la primera línea de la matriz, con los nombres de los nodos
		printf("  "); // Imprimimos espacio de la esquina superior izquierda de la matriz	
		for (int i = 0; i < grafo->n; i++) printf("%c ", grafo->nombresNodos[i]); // Imprimimos el nombre de los nodos en las columnas
		printf("\n");

		// Imprimimos las filas
		for (int i = 0; i < grafo->n; i++) {
			char nombreNodoOrigen = grafo->nombresNodos[i];
			printf("%c ", nombreNodoOrigen); // Imprimimos el nombre del nodo de la fila
			for (int j = 0; j < grafo->n; j++) {
				char nombreNodoDestino = grafo->nombresNodos[j];
				printf("%d ", existeArco(grafo, nombreNodoOrigen, nombreNodoDestino));
			}
			printf("\n");
		}
		printf("\n");
	}
}