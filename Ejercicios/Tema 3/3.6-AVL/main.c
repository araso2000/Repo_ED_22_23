#include "stdio.h"
#include "AVL.h"

void main () {	

	// Probamos la rotación simple a la izquierda
	printf("Probamos la rotacion simple a la izquierda\n");
	AVL *arbolPruebaRotacionSimpleIzquierda = construirAVL(); // Arbol AVL para probar la rotación
	int insercionesPruebaRotacionSimpleIzquierda[] = { 1, 2, 3, 4, 5, 6 }; // Inserciones que haremos
	for (int i=0; i<6; i++) {
		printf("Insercion de %d:\n", insercionesPruebaRotacionSimpleIzquierda[i]);
		insertar(arbolPruebaRotacionSimpleIzquierda, insercionesPruebaRotacionSimpleIzquierda[i]);
		imprimir(arbolPruebaRotacionSimpleIzquierda);
	}
	destruirAVL(arbolPruebaRotacionSimpleIzquierda);


	// Probamos la rotación simple a la derecha
	printf("\nProbamos la rotacion simple a la derecha\n");
	AVL *arbolPruebaRotacionSimpleDerecha = construirAVL(); // Arbol AVL para probar la rotación
	int insercionesPruebaRotacionSimpleDerecha[] = {6, 5, 4, 3, 2, 1 }; // Inserciones que haremos
	for (int i = 0; i<6; i++) {
		printf("Insercion de %d:\n", insercionesPruebaRotacionSimpleDerecha[i]);
		insertar(arbolPruebaRotacionSimpleDerecha, insercionesPruebaRotacionSimpleDerecha[i]);
		imprimir(arbolPruebaRotacionSimpleDerecha);
	}
	destruirAVL(arbolPruebaRotacionSimpleDerecha);


	// Probamos la rotación compuesta derecha-izquierda 
	printf("\nProbamos la rotacion compuesta derecha-izquierda\n");
	AVL *arbolPruebaRotacionCompuestaDerechaIzquierda = construirAVL(); // Arbol AVL para probar la rotación
	int insercionesPruebaRotacionCompuestaDerechaIzquierda[] = {2, 5, 3, 9, 8, 1, 10, 4, 6, 7}; // Inserciones que haremos
	for (int i = 0; i<10; i++) {
		printf("Insercion de %d:\n", insercionesPruebaRotacionCompuestaDerechaIzquierda[i]);
		insertar(arbolPruebaRotacionCompuestaDerechaIzquierda, insercionesPruebaRotacionCompuestaDerechaIzquierda[i]);
		imprimir(arbolPruebaRotacionCompuestaDerechaIzquierda);
	}
	destruirAVL(arbolPruebaRotacionCompuestaDerechaIzquierda);

	// Probamos la rotación compuesta izquierda-derecha
	printf("\nProbamos la rotacion compuesta izquierda-derecha\n");
	AVL *arbolPruebaRotacionCompuestaIzquierdaDerecha = construirAVL(); // Arbol AVL para probar la rotación
	int insercionesPruebaRotacionCompuestaIzquierdaDerecha[] = {9, 6, 8, 2, 3, 10, 5, 7, 1, 4}; // Inserciones que haremos
	for (int i = 0; i<10; i++) {
		printf("Insercion de %d:\n", insercionesPruebaRotacionCompuestaIzquierdaDerecha[i]);
		insertar(arbolPruebaRotacionCompuestaIzquierdaDerecha, insercionesPruebaRotacionCompuestaIzquierdaDerecha[i]);
		imprimir(arbolPruebaRotacionCompuestaIzquierdaDerecha);
	}
	destruirAVL(arbolPruebaRotacionCompuestaIzquierdaDerecha);
}
