#include "stdio.h"
#include "ArbolGenealogico.h"

void main () {

	char antepasadoMasLejano[20];
	printf("Introduce tu antepasado mas lejano: ");
	scanf("%s", antepasadoMasLejano);
	ArbolGenealogico *arbol = constructor(antepasadoMasLejano);

	int opcion;
	do {
				
		char nuevoNombre[20]; // Nuevo nombre que pedimos al usuario para insertar un nuevo nombre
		char nombrePadre[20]; // Nuevo padre que pedimos al usuario para insertar un nuevo nombre
		
		printf("0. Salir\n");
		printf("1. Insertar nuevo nombre\n");
		printf("2. Mostrar arbol genealogico\n");
		printf("Introduce opcion: ");
		scanf("%d", &opcion);

		switch (opcion) {
		case (0): // Terminar programa
			break;
		case (1):
			printf("Escriba el nuevo nombre: ");
			scanf("%s", nuevoNombre);
			printf("Escriba el nombre de su padre: ");
			scanf("%s", nombrePadre);
			insertar(arbol, nuevoNombre, nombrePadre);
			break;
		case (2):
			imprimirArbol(arbol);
			break;
		default:
			printf("Opcion incorrecta\n");
			break;
		}
	} while (opcion != 0);
	
}
