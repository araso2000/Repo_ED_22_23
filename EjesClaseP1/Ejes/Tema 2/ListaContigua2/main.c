#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "ListaContigua.h"
#include "Interfaz.h"

int main() {
	//Paso 1
	ListaContigua *lista1 = constructor();
	imprimirListaContigua(lista1);

	//Paso 2
	for(int ii=0;ii<11;ii++){
		insertarFinal(ii,lista1);
		imprimirListaContigua(lista1);
	}

	//Paso 3
	insertar(100,0,lista1);
	imprimirListaContigua(lista1);
	insertar(101,0,lista1);
	imprimirListaContigua(lista1);
	insertar(102,0,lista1);
	imprimirListaContigua(lista1);
	insertar(103,0,lista1);
	imprimirListaContigua(lista1);
	insertar(104,0,lista1);
	imprimirListaContigua(lista1);

	//Paso 4
	insertar(200,3,lista1);
	imprimirListaContigua(lista1);

	//Paso 5
	eliminarFinal(lista1);
	imprimirListaContigua(lista1);
	eliminarFinal(lista1);
	imprimirListaContigua(lista1);
	eliminarFinal(lista1);
	imprimirListaContigua(lista1);
	eliminarFinal(lista1);
	imprimirListaContigua(lista1);
	eliminarFinal(lista1);
	imprimirListaContigua(lista1);

	//Paso 6
	eliminar(0,lista1);
	imprimirListaContigua(lista1);
	eliminar(0,lista1);
	imprimirListaContigua(lista1);
	eliminar(0,lista1);
	imprimirListaContigua(lista1);
	eliminar(0,lista1);
	imprimirListaContigua(lista1);
	eliminar(0,lista1);
	imprimirListaContigua(lista1);

	//Paso 7
	int temp = buscar(100,lista1);
	printf("Elemento 100 encontrado en posicion: %d \n",temp);

	//Paso 8
	temp = buscar(2,lista1);
	printf("Elemento 2 encontrado en posicion: %d \n",temp);

	//Paso 9
	temp = buscar(5,lista1);
	printf("Elemento 5 encontrado en posicion: %d \n",temp);

	//Paso 10
	temp = buscar(20,lista1);
	printf("Elemento 20 encontrado en posicion: %d \n",temp);

	//Paso 11
	ListaContigua *lista2 = constructor();

	insertarFinal(500,lista2);
	insertarFinal(501,lista2);
	insertarFinal(502,lista2);
	insertarFinal(503,lista2);
	insertarFinal(504,lista2);
	insertarFinal(505,lista2);

	imprimirListaContigua(lista2);

	//Paso 12
	concatenar(lista1, lista2);
	imprimirListaContigua(lista1);

	//Final
	destructor(lista2);
	destructor(lista1);
}
