#include "ListaDobleEnlazada.h"
#include <stdio.h>

void imprimir(ListaDobleEnlazada *lista){
    printf("Tam Lista: %d -> ",lista->tamActual);
    
    if(lista->tamActual == 0){
        printf("Lista vacia");
    }else{
        for(int ii=0 ; ii < lista->tamActual ; ii++){
            Ruta temporal = getValor(lista,ii);
            printf("(%s, %d, %s)",temporal.aeropuerto, temporal.km, temporal.empresa);
            if(ii != lista->tamActual-1){
                printf(", ");
            }
        }
    }
    printf("\n");
}