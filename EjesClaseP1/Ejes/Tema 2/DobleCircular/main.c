#include "ListaDobleEnlazada.h"
#include "impresionListasEnlazadas.h"
#include <stdlib.h>
#include <stdio.h>

int main(void){
    ListaDobleEnlazada *lista1 = constructor();
    imprimir(lista1);

    insertar(lista1,0,45);
    imprimir(lista1);

    insertar(lista1,0,46);
    imprimir(lista1);

    insertar(lista1,2,47);
    imprimir(lista1);

    insertar(lista1,0,48);
    imprimir(lista1);

    eliminar(lista1,1);
    imprimir(lista1);

    eliminar(lista1,2);
    imprimir(lista1);

    eliminar(lista1,0);
    imprimir(lista1);

    ListaDobleEnlazada *lista2 = constructor();

    for(int ii = 0 ; ii < 5 ; ii++){
        insertar(lista2,0,ii*2);
    }
    imprimir(lista2);

    concatenar(lista1,lista2);
    imprimir(lista1);

    buscar(lista1,4);

    destructor(lista1);
}
