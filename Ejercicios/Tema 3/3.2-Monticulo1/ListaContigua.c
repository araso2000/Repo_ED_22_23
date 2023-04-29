#include <stdbool.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

#include "ListaContigua.h"

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

int get(ListaContigua *lista, int pos){
    assert(lista != NULL);
	assert(lista->n >= 0 && lista->capacidad >= lista->n);
	assert(pos >= 0);
    assert(pos <= lista->n - 1);

    return(lista->array[pos]);
}

void modificar(ListaContigua *lista, int pos, int num){
    assert(lista != NULL);
	assert(lista->n >= 0 && lista->capacidad >= lista->n);
	assert(pos >= 0 && pos <= lista->n-1);

    lista->array[pos] = num;
}

void ampliarReducir(ListaContigua *lista, int nuevoTam){
    assert(lista != NULL);
	assert(lista->n >= 0 && lista->capacidad >= lista->n);

    lista->array = (int*)realloc(lista->array, sizeof(int) * (lista->capacidad + nuevoTam));
	lista->capacidad += 2;
}

void insertarFinal(ListaContigua *lista, int num){
    assert(lista != NULL);
	assert(lista->n >= 0 && lista->capacidad >= lista->n);

    insertar(lista, num, lista->n);
}

void eliminarFinal(ListaContigua *lista){
    assert(lista != NULL);
	assert(lista->n > 0);
	assert(lista->capacidad >= lista->n);

    eliminar(lista, lista->n);
}

void insertar(ListaContigua *lista, int num, int pos){
    assert(lista != NULL);
	assert(lista->n >= 0 && lista->capacidad >= lista->n);

    if(listaLlena(lista)){
        ampliarReducir(lista, 2);
    }

    if(pos == 0){
        memmove(lista->array+1,lista->array,sizeof(int) * sizeof(lista->n));
        lista->array[0] = num;
        lista->n++;
    }else{
        lista->array[lista->n] = num;
        lista->n++;
    }
}

void eliminar(ListaContigua *lista, int pos){
    assert(lista != NULL);
	assert(lista->n >= 0 && lista->capacidad >= lista->n);

    memmove(lista->array+pos,lista->array+pos+1,(lista->n-pos-1)*sizeof(int));
    lista->n--;

	if (lista->capacidad - lista->n >= 2 * 5){
        ampliarReducir(lista, -2);
    } 
}

void concatenar(ListaContigua *lista1, ListaContigua *lista2){
    assert(lista1 != NULL);
	assert(lista1->n >= 0 && lista1->capacidad >= lista1->n);
    assert(lista2 != NULL);
	assert(lista2->n >= 0 && lista2->capacidad >= lista2->n);

    for(int ii=0; ii<lista2->n; ii++){
        insertarFinal(lista1, lista2->array[ii]);
    }
}

int buscar(ListaContigua *lista, int elem){
    assert(lista != NULL);
	assert(lista->n >= 0 && lista->capacidad >= lista->n);

    int posicion = -1;

    for(int ii = 0 ; ii < lista->n ; ii++){
        if(lista->array[ii] == elem){
            posicion = ii;
            break;
        }
    }

    return(posicion);
}