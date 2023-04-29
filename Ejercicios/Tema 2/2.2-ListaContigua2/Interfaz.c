#include <stdbool.h>
#include "ListaContigua.h"
#include "stdio.h"
#include "assert.h"
#include <stdlib.h>

void imprimirListaContigua(ListaContigua *lista) {
	assert(lista != NULL);
	assert(lista->n >= 0 && lista->capacidad >= lista->n); 

	printf("n=%d|Max=%d|ListaContigua=", lista->n, lista->capacidad);
	
	if (lista->n ==0) {
        printf("Lista vacia");
    }else {
		for (int i = 0; i < lista->n; i++) {
			printf("%d", get(i, lista));
			if (i < lista->n - 1) {
                printf(",");
            }
        }
	}
	printf("\n");
}
