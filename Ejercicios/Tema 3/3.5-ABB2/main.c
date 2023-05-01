#include "stdio.h"
#include "ArbolBinarioBusqueda.h"


void main () {

	ArbolBinarioBusqueda *arbol = constructor();

	// Creamos la lista de inserciones
	int inserciones[] = {5, 1, 6, 3, 7, 2, 4};
	const int n = 7;

	// Insertamos e imprimimos
	for (int i = 0; i < n; i++) insertarElemento(arbol, inserciones[i]);
	printf("Arbol inicial:\n");
	imprimir(arbol);

	printf("Eliminamos 5\n");
	eliminarElemento(arbol, 5);
	imprimir(arbol);

	printf("Eliminamos 6\n");
	eliminarElemento(arbol, 6);
	imprimir(arbol);

	printf("Eliminamos 4\n");
	eliminarElemento(arbol, 4);
	imprimir(arbol);

	printf("Eliminamos 7\n");
	eliminarElemento(arbol, 7);
	imprimir(arbol);

	destructorArbol(arbol);
}
