#include "stdio.h"
#include "Monticulo.h"


int main () {

	ListaContigua* monticulo = constructor();

	// Creamos la lista de inserciones
	int inserciones[] = {3, 4, 6, 7, 5, 2};

	// Vamos insertando e imprimiendo
	for (int i=0; i<6; i++) {
		printf("Insercion de %d:\n", inserciones[i]);
		insertarMonticulo(monticulo, inserciones[i]);
		imprimirArbol(monticulo);
	}

	destructor(monticulo);	
}