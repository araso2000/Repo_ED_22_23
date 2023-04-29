#include "stdio.h"
#include "HashColision.h"

int main(){
    int capacidad; // Capacidad de la tabla hash
	int opcion; // Opcion de menu introducida por teclado

	printf("Introduce la capacidad de la tabla: ");
	scanf("%d", &capacidad);

	HashColision* tabla = constructor(capacidad);

	do {
		// Imprimimos el menu y pedimos la opcion
		printf("0. Salir\n");
		printf("1. Imprimir tabla\n");
		printf("2. Comprobar si esta un estudiante\n");
		printf("3. Ver un estudiante\n");
		printf("4. Meter un estudiante\n");
		printf("5. Eliminar un estudiante\n");
		printf("Introduzca opcion: ");
		scanf("%d", &opcion);

		unsigned int clave; // Clave para algunas opciones
		
		// Gestionamos la opcion
		switch (opcion) {
		case 0:
			break;
		case 1:
			imprimir(tabla);
			break;
		case 2:
			// Comprobar si está un estudiante
			printf("Introduzca el numero de matricula del estudiante (mayor o igual que cero): ");
			scanf("%d", &clave);
			if (existe(tabla, clave)) printf("El estudiante SI esta\n");
			else printf("El estudiante NO esta\n");
			break;
		case 3:
			// Ver un estudiante (obtener su nombre)
			printf("Introduzca el numero de matricula del estudiante (mayor o igual que cero): ");
			scanf("%d", &clave);
			char* nombreVer = getEstudiante(tabla, clave);
			printf("El estudiante se llama %s\n", nombreVer);
			free(nombreVer);
			break;
		case 4:
			// Meter un estudiante
			printf("Introduzca el numero de matricula del estudiante (mayor o igual que cero): ");
			scanf("%d", &clave);
			printf("Introduzca el nombre del estudiante (maximo 9 letras): ");
			char nombreIntroducir[10]; // Nombre del estudiante
			scanf("%s", nombreIntroducir);
			insertar(tabla, clave, nombreIntroducir);
			break;
		case 5:
			// Eliminar un estudiante
			printf("Introduzca el numero de matricula del estudiante (mayor o igual que cero): ");
			scanf("%d", &clave);
			eliminar(tabla, clave);
			break;
		default:
			printf("Opcion incorrecta\n");
			break;

		} // Fin switch

	} while (opcion != 0);

	destructor(tabla); // Destruimos la tabla antes de salir
}