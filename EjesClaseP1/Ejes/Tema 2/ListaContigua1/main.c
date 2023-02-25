#include <stdbool.h>
#include <stdlib.h>
#include "stdio.h"
#include "ListaContigua1.h"
#include "Interfaz.h"

int main() {

	// Creamos una ListaContigua que nos servirá para las pruebas
	ListaContigua *lista = constructor();

	printf("Nueva ListaContigua creada:\n");
	imprimirListaContigua(lista);

	printf("Rellenando ListaContigua:\n");
	for (int i = 0; i <= 11; i++) {
		insertarFinal(i, lista); // Introducimos el nuevo elemento
		imprimirListaContigua(lista);
	}
	printf("Elemento0=%d|Elemento11=%d\n", get(0, lista), get(11, lista));

	printf("Cambio elemento 4 por 50. Nueva ListaContigua:\n");
	modificar(4, 50, lista);
	imprimirListaContigua(lista);

	// Borramos los ultimos cuatro elementos
	for (int i = 0; i < 4; i++) {
		printf("Borramos el ultimo elemento. Nueva ListaContigua:\n");
		eliminarFinal(lista);
		imprimirListaContigua(lista);
	}

	// Insertamos 100, 101, 102 y 103 al final
	for (int i = 100; i <= 103; i++) {
		printf("Insertamos %d al final. Nueva ListaContigua:\n", i);
		insertarFinal(i, lista);
		imprimirListaContigua(lista);
	}

	// Destruimos la lista para liberar su memoria
	destructor(lista);
}
