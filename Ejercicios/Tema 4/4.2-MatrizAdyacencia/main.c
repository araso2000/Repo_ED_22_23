#include "stdio.h"
#include "Matriz.h"

void main () {

	// Creamos el grafo vacio y lo imprimimos
	Matriz *grafo = construirMatriz();
	imprimir(grafo);
	printf("\n");

	// Insertamos los nodos
	insertarNodo(grafo, 'A');
	insertarNodo(grafo, 'B');
	insertarNodo(grafo, 'C');
	insertarNodo(grafo, 'D');
	insertarNodo(grafo, 'E');
	imprimir(grafo);

	// Insertamos arcos
	insertarArco(grafo, 'A', 'A');
	insertarArco(grafo, 'A', 'C');
	insertarArco(grafo, 'A', 'E');
	insertarArco(grafo, 'B', 'B');
	insertarArco(grafo, 'B', 'D');
	insertarArco(grafo, 'C', 'A');
	insertarArco(grafo, 'C', 'C');
	insertarArco(grafo, 'C', 'E');
	insertarArco(grafo, 'D', 'B');
	insertarArco(grafo, 'D', 'D');
	insertarArco(grafo, 'E', 'A');
	insertarArco(grafo, 'E', 'C');
	insertarArco(grafo, 'E', 'E');
	imprimir(grafo);

	// Borramos nodos
	borrarNodo(grafo, 'B'); imprimir(grafo);
	borrarNodo(grafo, 'A'); imprimir(grafo);
	borrarNodo(grafo, 'E'); imprimir(grafo);

	// Insertamos nuevos nodos
	insertarNodo(grafo, 'H');
	insertarNodo(grafo, 'G');
	insertarNodo(grafo, 'F');
	insertarNodo(grafo, 'E');
	imprimir(grafo);

	// Borramos los arcos que quedan en el grafo
	borrarArco(grafo, 'C', 'C');
	borrarArco(grafo, 'D', 'D');
	imprimir(grafo);

	// Insertamos varios arcos para formar el grafo del enunciado
	insertarArco(grafo, 'C', 'D');
	insertarArco(grafo, 'D', 'C');
	insertarArco(grafo, 'D', 'G');
	insertarArco(grafo, 'G', 'D');
	insertarArco(grafo, 'G', 'H');
	insertarArco(grafo, 'C', 'E');
	insertarArco(grafo, 'E', 'C');
	insertarArco(grafo, 'C', 'F');
	insertarArco(grafo, 'F', 'C');
	insertarArco(grafo, 'F', 'G');
	insertarArco(grafo, 'G', 'F');
	imprimir(grafo);

	destruirMatriz(grafo);	
}
