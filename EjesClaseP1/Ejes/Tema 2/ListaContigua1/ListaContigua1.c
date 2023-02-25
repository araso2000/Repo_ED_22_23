#include <stdbool.h>
#include <stdlib.h>
#include "ListaContigua1.h"
#include <assert.h>

#define INCREMENTO = 5;

ListaContigua* constructor(){
    ListaContigua* nuevaLista = (ListaContigua*)malloc(sizeof(ListaContigua));
    nuevaLista->array = NULL;
    nuevaLista->n = 0;
    nuevaLista->capacidad = 0;
    return(nuevaLista);
}

void destructor(ListaContigua *lista){
    assert(lista != NULL);
	assert(lista->n >= 0 && lista->capacidad >= lista->n);
	
    free(lista->array);
    free(lista);
}

bool listaLlena(ListaContigua *lista){
    assert(lista != NULL);
	assert(lista->n >= 0 && lista->capacidad >= lista->n);

    if(lista->n == lista->capacidad){
        return true;
    }else{
        return false;
    }
}

int get(int pos, ListaContigua *lista){
    assert(lista != NULL);
	assert(lista->n >= 0 && lista->capacidad >= lista->n);
	assert(pos >= 0 && pos <= lista->n-1);

    return(lista->array[pos]);
}

void modificar(int pos, int num, ListaContigua *lista){
    assert(lista != NULL);
	assert(lista->n >= 0 && lista->capacidad >= lista->n);
	assert(pos >= 0 && pos <= lista->n-1);

    lista->array[pos] = num;
}

void ampliarReducir(int nuevoTam, ListaContigua *lista){
    assert(lista != NULL);
	assert(lista->n >= 0 && lista->capacidad >= lista->n);

    lista->array = (int*)realloc(lista->array, sizeof(int) * (lista->capacidad + nuevoTam));
	lista->capacidad += 5;
}

void insertarFinal(int num, ListaContigua *lista){
    assert(lista != NULL);
	assert(lista->n >= 0 && lista->capacidad >= lista->n);

    if(listaLlena(lista)){
        ampliarReducir(5, lista);
    }

    lista->array[lista->n] = num;
    lista->n++;
}

void eliminarFinal(ListaContigua *lista){
    assert(lista != NULL);
	assert(lista->n > 0);
	assert(lista->capacidad >= lista->n);

    lista->n--;
	if (lista->capacidad - lista->n >= 2 * 5){
        ampliarReducir(-5, lista);
    } 
}
