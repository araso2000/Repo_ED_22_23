#include "ListaContiguaOrdenada.h"
#include "Interfaz.h"

#include <stdbool.h>
#include <stdlib.h>
#include <assert.h>
#include <stdio.h>
#include <time.h>

int main(){
    ListaContiguaOrdenada* lista = constructor();

	// Opción del menú que introduce el usuario por teclado
	int teclaPulsada;

	// Inicializamos el generador de numeros aleatorios
	srand(time(NULL));

	do {
		int numeroAInsertar; // Numero aleatorio a insertar
		int numeroABuscar; // Numero a buscar
		int numeroAEliminar; // Numero a eliminar
		int posicion; // Posicion ideal del numero a buscar

		// Mostrar el menú
		printf("0. Salir\n");
		printf("1. Insertar un numero aleatorio entre 50 y 100\n");
		printf("2. Buscar un numero\n");
		printf("3. Eliminar un numero\n");
		printf("4. Imprimir la lista\n");
		printf("Introduzca opcion: ");

		// Recogemos la opción		
		scanf("%d", &teclaPulsada);

		switch (teclaPulsada) {
		case (0) :
			break;
		case (1) :
			numeroAInsertar = 50 + rand() % 51;
			insertarOrdenada(lista, numeroAInsertar);
			printf("Numero %d insertado correctamente\n", numeroAInsertar);
			break;
		case (2) :
			printf("Introduzca un numero a buscar: ");
			scanf("%d", &numeroABuscar);
			posicion = buscarOrdenada(lista, numeroABuscar);
			if (posicion == -1) printf("Elemento no encontrado\n");
			else printf("Elemento encontrado en la posicion %d\n", posicion);
			break;
		case (3) :
			printf("Introduzca un numero a eliminar (tiene que existir en la lista): ");
			scanf("%d", &numeroAEliminar);
			eliminarOrdenada(lista, numeroAEliminar);
			printf("Elemento %d eliminado correctamente\n", numeroAEliminar);
			break;
		case (4) :
			imprimirListaContigua(lista);
			break;
		default:
			printf("Opcion incorrecta\n");
		}
	} while (teclaPulsada != 0);

}