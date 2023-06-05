#include "EspacioAereo.h"

#include <stdbool.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

bool existeAeropuerto(ListaContigua *grafo, char *nombre){
    assert(grafo != NULL && grafo->n >= 0 && grafo->capacidad >= grafo->n); // la lista que representa al grafo tiene sentido
	assert(nombre != NULL);

    //Creamos un objeto aeropuerto temporal con el que usar las funciones privadas de una lista contigua
    Aeropuerto temporal;
    strcpy(temporal.nombre,nombre);

    //Usamos métodos de la lista contigua
    if(buscarContigua(temporal,grafo) == -1){
        return false;
    }else{
        return true;
    }
}

ListaDobleEnlazada* getDestinos(ListaContigua *grafo, char *origen){
    assert(grafo != NULL && grafo->n >= 0 && grafo->capacidad >= grafo->n); // la lista que representa al grafo tiene sentido
	assert(origen != NULL);
	assert(existeAeropuerto(grafo, origen));

    //Creamos un objeto aeropuerto temporal con el que usar las funciones privadas de una lista contigua
    Aeropuerto temporal;
    strcpy(temporal.nombre,origen);
    //Obtenemos la posicion donde se encuentra ese aeropuerto, obtenemos sus rutas salientes y las returneamos
    return(get(buscarContigua(temporal, grafo),grafo).salientes);
}

ListaDobleEnlazada* getOrigenes(ListaContigua *grafo, char *destino){
    //Identico al anterior pero esta vez obtenemos las rutas entrantes

    assert(grafo != NULL && grafo->n >= 0 && grafo->capacidad >= grafo->n); // la lista que representa al grafo tiene sentido
	assert(destino != NULL);
	assert(existeAeropuerto(grafo, destino));

    //Creamos un objeto aeropuerto temporal con el que usar las funciones privadas de una lista contigua
    Aeropuerto temporal;
    strcpy(temporal.nombre,destino);
    //Obtenemos la posicion donde se encuentra ese aeropuerto, obtenemos sus rutas salientes y las returneamos
    return(get(buscarContigua(temporal, grafo),grafo).entrantes);
}

bool existeRuta(ListaContigua *grafo, char *origen, char *destino){
    assert(grafo != NULL && grafo->n >= 0 && grafo->capacidad >= grafo->n); // la lista que representa al grafo tiene sentido
	assert(origen != NULL);
	assert(destino != NULL);
	assert(existeAeropuerto(origen, grafo));
	assert(existeAeropuerto(destino, grafo));

    //Creamos una ruta temporal con la que usar los metodos privados de la lista contigua
    Ruta temporal;
    strcpy(temporal.aeropuerto,destino);
    //Buscamos entre todos los aeropuertos si existe la ruta como destino
    if(buscar(getDestinos(grafo,origen),temporal) == -1){
        return false;
    }else{
        return true;
    }
}

void imprimirGrafo(ListaContigua *grafo){
    assert(grafo != NULL && grafo->n >= 0 && grafo->capacidad >= grafo->n); // la lista que representa al grafo tiene sentido

    if(grafo->n == 0){
        printf("Grafo vacio\n");
    }else{
        for(int ii=0; ii<grafo->n; ii++){
            Aeropuerto temporal = get(ii, grafo); //Obtenemos el aeropuerto
            printf("Nodo %s:\n",temporal.nombre);
            printf("\tRutas de salida: ");
            //Imprimimos por cada aeropuerto su lista doblemente enlazada de rutas salientes
            imprimirListaEnlazada(get(ii,grafo).salientes);
            printf("\tRutas de entrada: ");
            //Y rutas entrantes
            imprimirListaEnlazada(get(ii,grafo).entrantes);
        }
    }
}

void insertarAeropuerto(ListaContigua *grafo, char *nombre){
    assert(grafo != NULL && grafo->n >= 0 && grafo->capacidad >= grafo->n); // la lista que representa al grafo tiene sentido
	assert(nombre != NULL);
	assert(!existeAeropuerto(grafo, nombre)); // Ese aeropuerto no existe previamente

    //Creamos un objeto aeropuerto temporal con el que usar las funciones privadas de una lista contigua
    Aeropuerto temporal;
    strcpy(temporal.nombre,nombre);

    //Inicializamos el resto de componentes del struct Aeropuerto
    temporal.entrantes = constructor();
    temporal.salientes = constructor();
    insertarFinal(temporal,grafo);
}

void insertarRuta(ListaContigua *grafo, char *origen, char *destino, int distancia, char *empresa){
    assert(grafo != NULL && grafo->n >= 0 && grafo->capacidad >= grafo->n); // la lista que representa al grafo tiene sentido
	assert(origen != NULL);
	assert(destino != NULL);
	assert(empresa != NULL);
	assert(existeAeropuerto(grafo, origen));
	assert(existeAeropuerto(grafo, destino));
	assert(!existeRuta(grafo, origen, destino));
	assert(distancia > 0);

    //Creamos una ruta temporal con la que usar los metodos privados de la lista contigua
    Ruta nuevo;
    strcpy(nuevo.aeropuerto,destino);
    nuevo.km = distancia;
    strcpy(nuevo.empresa,empresa);

    //Insertamos la nueva ruta en la lista de destinos del aeropuerto de origen
    insertarEnlazada(getDestinos(grafo,origen), 0, nuevo);

    //Insertamos la nueva ruta en la lista de origenes del aeropuerto de destino
    insertarEnlazada(getOrigenes(grafo,destino), 0, nuevo);
}

void eliminarRuta(ListaContigua *grafo, char *origen, char *destino){
    assert(grafo != NULL && grafo->n >= 0 && grafo->capacidad >= grafo->n); // la lista que representa al grafo tiene sentido
	assert(origen != NULL);
	assert(destino != NULL);
	assert(existeAeropuerto(grafo, origen));
	assert(existeAeropuerto(grafo, destino));
	assert(existeRuta(grafo, origen, destino));

    //Creamos una ruta temporal con la que usar los metodos privados de la lista contigua
    Ruta temporal;
    strcpy(temporal.aeropuerto,destino);
    //Primero borramos la ruta de todos los aeropuertos que la tengan como destino
    //eliminar(ListaEnlazadaDoble destinos, int posicionABorrar);
    eliminar(getDestinos(grafo , origen) , buscar(getDestinos(grafo,origen),temporal));

    //Segundo borramos la ruta de todos los aeropuertos que la tengan como origen
    strcpy(temporal.aeropuerto,origen);
    eliminar(getOrigenes(grafo , destino) , buscar(getOrigenes(grafo,destino),temporal));
}

void eliminarAeropuerto(ListaContigua *grafo, char *nombre){
    assert(grafo != NULL && grafo->n >= 0 && grafo->capacidad >= grafo->n); // la lista que representa al grafo tiene sentido
	assert(nombre != NULL);
	assert(existeAeropuerto(grafo, nombre));

    //Obtenemos los destinos de dicho aeropuerto, para ir eliminando ruta por ruta
    ListaDobleEnlazada *destinos = getDestinos(grafo, nombre);
    while(destinos->tamActual > 0){
        //Vamos borrando la primera ruta todo el rato hasta quedarnos sin rutas
        eliminarRuta(grafo, nombre, getValor(destinos,0).aeropuerto);
    }

    //Obtenemos los origenes de dicho aeropuerto, para ir eliminando ruta por ruta
    ListaDobleEnlazada *origenes = getOrigenes(grafo, nombre);
    while(origenes->tamActual > 0){
        //Vamos borrando la primera ruta todo el rato hasta quedarnos sin rutas
        eliminarRuta(grafo, getValor(origenes,0).aeropuerto, nombre);
    }

    //Borramos el aeropuerto entero
    Aeropuerto temporal;
    strcpy(temporal.nombre,nombre);
    eliminar(buscarContigua(temporal,grafo), grafo);
}