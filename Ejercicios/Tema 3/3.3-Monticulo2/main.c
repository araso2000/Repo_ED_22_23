#include "stdio.h"
#include "Monticulo.h"
#include "stdlib.h"
#include "time.h"
#include "Interfaz.h"


void main () {

	ListaContigua* monticulo = constructor();

	// Creamos la lista de inserciones
	int inserciones[] = {2, 3, 4, 7, 5, 6};

	// Vamos insertando e imprimiendo
	for (int i=0; i<6; i++) {
		printf("Insercion de %d:\n", inserciones[i]);
		insertarMonticulo(monticulo, inserciones[i]);
		imprimirArbol(monticulo);
	}

	// Imprimimos y borramos la raiz
	printf("Sacamos raiz: %d\n", getRaiz(monticulo));
	borrar(monticulo);
	imprimirArbol(monticulo);

	// Imprimimos y borramos la raiz
	printf("Sacamos raiz: %d\n", getRaiz(monticulo));
	borrar(monticulo);
	imprimirArbol(monticulo);

	// Creamos una lista con 20 elementos, cada uno aleatoriamente del 50 al 100
	srand((unsigned int)time(NULL));
	ListaContigua* lista = constructor();
	for (int i=0; i<20; i++) {
		int numero = rand()%51 + 50;
		insertarFinal(lista, numero); // Insertamos al final para que sea mas eficiente (no hay que correr los numeros posteriores porque no hay)
	}
	printf("Lista a ordenar: ");
	imprimirListaContigua(lista);

	// Ordenamos la lista y la imprimimos
	ordenarPorMonticulo(lista);
	printf("Lista ordenada: ");
	imprimirListaContigua(lista);

	// Destruimos todo
	destructor(monticulo);
	destructor(lista);	
}

