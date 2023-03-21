#include "ListaContiguaOrdenada.h"

#include <stdbool.h>
#include <stdlib.h>
#include <assert.h>
#include <stdio.h>
#include <string.h>

ListaContiguaOrdenada* constructor(){
    ListaContiguaOrdenada* nuevaLista = (ListaContiguaOrdenada*)malloc(sizeof(ListaContiguaOrdenada));
    nuevaLista->array = NULL;
    nuevaLista->n = 0;
    nuevaLista->capacidad = 0;
    return(nuevaLista);
}

bool isOrdenada(ListaContiguaOrdenada *lista){
    assert(lista != NULL);

    for(int ii = 1; ii < lista->n; ii++){
        if(lista->array[ii - 1] > lista->array[ii]){
            return(false);
        }
    }

    return(true);
}

int busquedaBinaria(ListaContiguaOrdenada *lista, int elem, int posIni, int tam){
    assert(lista != NULL);
    assert(lista->n >= 0);
    assert(lista->capacidad >= 0);
    assert(isOrdenada(lista));

    assert(posIni >= 0);
    assert(tam >= 0);

    if(tam == 0){ //Si el tamaño del subvector es 0, el elemento no está
        assert(posIni <= lista->n); //Vamos a comprobar que la posicion de inicio esté dentro del rango de la lista
    }else{ //Si el subvector tiene longitud
        assert(posIni < lista->n); //Comprobamos entonces que la posicion de inicio está dentro del rango de la lista
        assert(tam <= (lista->n-1) - posIni + 1); //Comprobamos además que el tamaño del subvector sea lógico
    }

    if(tam == 0){ //Si hemos pasado los anteriores asserts y el subvector es 0 de largo
        return(posIni); //Pues devolvemos la posicion inicial
    }

    int posFin = posIni + tam - 1; //Calculamos la posicion final del subvector
	int posMedio = (posIni + posFin) / 2; //Calculamos la posicion media del subvector

    //Si el valor que buscamos es el del medio, pues devolvemos la posicion media
    if(getValor(lista, posMedio) == elem){
        return(posMedio);
    }else if(elem > getValor(lista, posMedio)){
        //Si el valor que buscamos está por encima del valor del medio
        //Calculamos el nuevo fin del nuevo subvector
        int nuevoSubvector = posFin - (posMedio + 1) + 1;

        //Y buscamos desde la posicion del medio hasta el nuevo fin
        return(busquedaBinaria(lista, elem, posMedio + 1, nuevoSubvector));
    }else{
        //Si no es el del medio y tampoco está por encima, por narices será más pequeño que el del medio
        //Calculamos nuevo final del subvector
        int nuevoSubvector = (posMedio - 1) - posIni + 1;

        return(busquedaBinaria(lista, elem, posIni, nuevoSubvector));
    }
}

int buscarOrdenada(ListaContiguaOrdenada *lista, int elem){
    assert(lista != NULL);
    assert(lista->n >= 0);
    assert(lista->capacidad >= 0);
    assert(isOrdenada(lista));

    //Si al buscar el metodo binario de busqueda nos devuelve n, significa que no ha encontrado nada asi que
    //devolvemos -1 como indica el enunciado
    int posiblePos = busquedaBinaria(lista, elem, 0, lista->n);
    if(posiblePos == lista->n){
        return(-1);
    }

    //Si la posicion devuelta por la busqueda binaria es distinta de n, comprobamos si el valor del array en esa
    //posicion es el elemento que buscamos y devolvemos la posicion; o -1 si no existe.
    if(getValor(lista,posiblePos) == elem){
        return(posiblePos);
    }else{
        return(-1);
    }
}

void insertarOrdenada(ListaContiguaOrdenada *lista, int elem){
    assert(lista != NULL);
    assert(lista->n >= 0);
    assert(lista->capacidad >= 0);
    assert(isOrdenada(lista));

    insertar(lista, busquedaBinaria(lista, elem, 0, lista->n), elem);
}

void eliminarOrdenada(ListaContiguaOrdenada *lista, int elem){
    assert(lista != NULL);
    assert(lista->n >= 0);
    assert(lista->capacidad >= 0);
    assert(isOrdenada(lista));
    assert(buscarOrdenada(lista, elem) != -1);

    eliminar(lista, busquedaBinaria(lista, elem, 0, lista->n));
}

int getValor(ListaContiguaOrdenada *lista, int pos){
    assert(lista != NULL);
	assert(lista->n >= 0 && lista->capacidad >= lista->n);
	assert(pos >= 0 && pos <= lista->n-1);

    return(lista->array[pos]);
}

void insertar(ListaContiguaOrdenada *lista, int pos, int elem){
    assert(lista != NULL);
	assert(lista->n >= 0 && lista->capacidad >= lista->n);

    if(listaLlena(lista)){
        ampliarReducir(lista, 2);
    }

    if(pos == 0){
        memmove(lista->array+1,lista->array,sizeof(int) * sizeof(lista->n));
        lista->array[0] = elem;
        lista->n++;
    }else{
        lista->array[lista->n] = elem;
        lista->n++;
    }
}

bool listaLlena(ListaContiguaOrdenada *lista){
    assert(lista != NULL);
	assert(lista->n >= 0 && lista->capacidad >= lista->n);

    if(lista->n == lista->capacidad){
        return true;
    }else{
        return false;
    }
}

void eliminar(ListaContiguaOrdenada *lista, int pos){
    assert(lista != NULL);
	assert(lista->n >= 0 && lista->capacidad >= lista->n);

    memmove(lista->array+pos,lista->array+pos+1,(lista->n-pos-1)*sizeof(int));
    lista->n--;

	if (lista->capacidad - lista->n >= 2 * 5){
        ampliarReducir(lista, -2);
    } 
}

void ampliarReducir(ListaContiguaOrdenada *lista, int nuevoTam){
    assert(lista != NULL);
	assert(lista->n >= 0 && lista->capacidad >= lista->n);

    lista->array = (int*)realloc(lista->array, sizeof(int) * (lista->capacidad + nuevoTam));
	lista->capacidad += 2;
}