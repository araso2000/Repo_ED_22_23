#include "ListaEnlazada.h"
#include "impresionListasEnlazadas.h"
#include <stdlib.h>
#include <stdio.h>

int main(void){
    ListaEnlazada *lista1 = constructor();
    imprimir(lista1);

    insertar(lista1,0,1);
    imprimir(lista1);

    insertar(lista1,1,2);
    imprimir(lista1);

    insertar(lista1,2,3);
    imprimir(lista1);

    insertar(lista1,0,4);
    imprimir(lista1);

    eliminar(lista1,1);
    imprimir(lista1);

    eliminar(lista1,2);
    imprimir(lista1);

    eliminar(lista1,0);
    imprimir(lista1);

    destructor(lista1);
}
