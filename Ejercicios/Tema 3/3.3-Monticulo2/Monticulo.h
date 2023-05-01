#include <stdbool.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

#include "ListaContigua.h"

void imprimirRecursivo(ListaContigua *arbol, int raiz, int numTabulaciones);

void imprimirArbol(ListaContigua *arbol);

bool esMonticulo(ListaContigua *arbol, int raiz);

void insertarMonticulo(ListaContigua *arbol, int clave);

void reestructurar(ListaContigua *arbol);

void borrar(ListaContigua *arbol);

int getRaiz(ListaContigua *arbol);

void ordenarPorMonticulo(ListaContigua *arbol);