#include "ListaEnlazada.h"
#include <stdio.h>

void imprimir(ListaEnlazada *lista){
    printf("Tam Lista: %d -> ",lista->tamActual);
    for(int ii=0;ii<lista->tamActual;ii++){
        printf("%d",getValor(getNodo(lista,ii)));
        if(ii != lista->tamActual-1){
            printf(", ");
        }
    }
    printf("\n");
}