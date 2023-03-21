#include "Pila.h"

#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

int main(){
    Pila *pila = constructor();

    push(pila,1);
    push(pila,2);
    push(pila,3);
    push(pila,4);
    imprimir(pila);
    pop(pila);
    imprimir(pila);
    printf("Cima: Numero: %d\n", verCima(pila)->elemento);
    imprimir(pila);
    destruirPila(pila);
}