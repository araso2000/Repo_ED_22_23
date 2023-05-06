#include "stdio.h"
#include "EspacioAereo.h"


void main () {

	// Grafo que guardará el espacio aéreo
	ListaContigua* grafo = crearListaContigua();;
	imprimirGrafo(grafo);
	printf("\n");

	// Insertamos los aeropuertos
	printf("Insertamos aeropuertos:\n");
	insertarAeropuerto(grafo, "Barajas");
	insertarAeropuerto(grafo, "Prat");
	insertarAeropuerto(grafo, "Heathrow");
	insertarAeropuerto(grafo, "JFK");
	insertarAeropuerto(grafo, "Frankfurt");
	imprimirGrafo(grafo);
	printf("\n");

	// Insertamos rutas
	printf("Insertamos rutas:\n");
	insertarRuta(grafo, "Barajas", "Prat", 300, "Vueling");
	insertarRuta(grafo, "Prat", "Barajas", 350, "Iberia");
	insertarRuta(grafo, "Barajas", "Heathrow", 900, "Iberia");
	insertarRuta(grafo, "Barajas", "JFK", 3000, "Iberia");
	insertarRuta(grafo, "JFK", "Heathrow", 2500, "Iberia");
	imprimirGrafo(grafo);
	printf("\n");

	// Borro Frankfurt
	printf("Borro Frankfurt:\n");
	eliminarAeropuerto(grafo, "Frankfurt");
	imprimirGrafo(grafo);
	printf("\n");

	// Borro ruta de Prat a Barajas
	printf("Borro ruta de Prat a Barajas:\n");
	eliminarRuta(grafo, "Prat", "Barajas");
	imprimirGrafo(grafo);
	printf("\n");

	// Borro Barajas
	printf("Borro Barajas:\n");
	eliminarAeropuerto(grafo, "Barajas");
	imprimirGrafo(grafo);
	printf("\n");

	destruirListaContigua(grafo); // OJO: las listas enlazadas con las rutas no se han destruido
}