#include "ListaDobleEnlazada.h"
#include <stdio.h>

void imprimirLista(ListaDobleEnlazada *lista){
    
    printf("Tam Lista: %d -> ",lista->tamActual);
    
    if(lista->tamActual == 0){
        
        printf("Lista vacia");
   
    }else{
        for(int ii=0 ; ii < lista->tamActual ; ii++){
            
            printf("(%d,%s)",getValor(lista,ii).matricula,getValor(lista,ii).nombre);
            
            if(ii != lista->tamActual-1){
                printf(", ");
            }
        }
    }
    printf("\n");
}