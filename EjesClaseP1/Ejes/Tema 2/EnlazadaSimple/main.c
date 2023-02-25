#include "ListaEnlazada.h"
#include "impresionListasEnlazadas.h"
#include <stdlib.h>
#include <stdio.h>

int main(void){
    ListaEnlazada *lista1 = constructor();
    imprimir(lista1);

    insertar(lista1,0,45);
    imprimir(lista1);

    insertar(lista1,1,48);
    imprimir(lista1);

    insertar(lista1,0,51);
    imprimir(lista1);

    eliminar(lista1,1);
    imprimir(lista1);

    destructor(lista1);
}
